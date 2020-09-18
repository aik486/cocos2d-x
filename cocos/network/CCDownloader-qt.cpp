/****************************************************************************
Copyright (c) 2020 Alexandra Cherdantseva

http://www.cocos2d-x.org

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in
all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
THE SOFTWARE.
****************************************************************************/
#include "CCDownloader-qt.h"

#include <set>

#include "base/CCDirector.h"
#include "network/CCDownloader.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QSaveFile>

namespace cocos2d { namespace network {

struct NetworkReplyStatus {
    int errorCode = 0;
    int errorCodeInternal = 0;
    std::string errorStr;
};

static NetworkReplyStatus qtNetworkReplyStatus(
        const QNetworkReply *reply,
        QNetworkReply::NetworkError error)
{
    NetworkReplyStatus result;
    if (error != QNetworkReply::NoError) {
        result.errorCode = DownloadTask::ERROR_IMPL_INTERNAL;
        result.errorCodeInternal = int(error);
        result.errorStr = reply->errorString().toStdString();
    }
            
    return result;
}

class DownloadTaskQt : public IDownloadTask
{
public:
    DownloadTaskQt(
        DownloaderQt* owner, const std::shared_ptr<const DownloadTask>& task);
    virtual ~DownloadTaskQt() override;
    
protected:
    void taskFinished(QNetworkReply::NetworkError status);
    
private:
    DownloaderQt *_owner;
    QNetworkReply *_reply;
    std::weak_ptr<const DownloadTask> _weakTask;
    const DownloadTask *_taskPtr;
    qint64 _bytesReceived;
};


DownloaderQt::DownloaderQt(const DownloaderHints &)
    : _manager(new QNetworkAccessManager)
{
}

DownloaderQt::~DownloaderQt()
{
    delete _manager;        
}

IDownloadTask *DownloaderQt::createCoTask(std::shared_ptr<const DownloadTask>& task)
{
    return new (std::nothrow) DownloadTaskQt(this, task);
}

DownloadTaskQt::DownloadTaskQt(
    DownloaderQt *owner, const std::shared_ptr<const DownloadTask> &task)
    : _owner(owner)
    , _weakTask(task)
    , _taskPtr(task.get())
    , _bytesReceived(0)
{
    QNetworkRequest request(QString::fromStdString(task->requestURL));
    _reply = owner->_manager->get(request);
    Q_ASSERT(_reply);
    QObject::connect(_reply, &QNetworkReply::finished,
                     [this](){
        if (!_reply) {
            return;
        }
        
        taskFinished(_reply->error());
    });
    
    QObject::connect(_reply, static_cast<void (QNetworkReply::*)(
                         QNetworkReply::NetworkError)>(&QNetworkReply::error),
                     [this](QNetworkReply::NetworkError error){
        if (!_reply) {
            return;
        }
        
        taskFinished(error);
    });
    
    QObject::connect(_reply, &QNetworkReply::downloadProgress,
                     [this](qint64 bytesReceived, qint64 bytesTotal) {
        if (!_reply) {
            return;
        }
        
        if (_weakTask.expired()) {
            return;
        }
        
        qint64 bytesRec = bytesReceived - _bytesReceived;
        _bytesReceived = bytesReceived;
        
        static std::function<int64_t(void *buffer, int64_t len)> dummy;
        
        _owner->onTaskProgress(
            *_taskPtr, bytesRec, _bytesReceived, bytesTotal, dummy);
    });
}

DownloadTaskQt::~DownloadTaskQt()
{
    if (_reply) {
        _reply->deleteLater();
    }
}

void DownloadTaskQt::taskFinished(QNetworkReply::NetworkError error)
{
    auto reply = _reply;
    if (!reply) {
        return;
    }
    _reply = nullptr;
    reply->deleteLater();
    
    auto task = _weakTask.lock();
    if (!task) {
        return;
    }
    
    if (error == QNetworkReply::OperationCanceledError) {
        return;
    }
    
    enum {
        BLOCK_SIZE = 16384
    };
    
    NetworkReplyStatus status;
    std::vector<unsigned char> data;
    if (reply->isReadable()) {
        auto storagePath = QString::fromStdString(task->storagePath);
        
        if (storagePath.isEmpty())
        {
            while (true) {            
                auto pos = data.size();
                data.resize(pos + BLOCK_SIZE);
                auto dataPtr = reinterpret_cast<char *>(&data.data()[pos]);
                auto actualRead = reply->read(dataPtr, BLOCK_SIZE);
                if (actualRead < BLOCK_SIZE) {
                    data.resize(pos + actualRead);
                    break;
                }
            }
        } else
        {
            data.resize(BLOCK_SIZE);
            auto dataPtr = reinterpret_cast<char *>(data.data());
            bool ok = false;
            QSaveFile saveFile(storagePath);
            if (saveFile.open(QSaveFile::WriteOnly)) {
                ok = true;
                while (true) {            
                    auto actualRead = reply->read(dataPtr, BLOCK_SIZE);
                    
                    if (actualRead > 0) {
                        if (saveFile.write(dataPtr, actualRead) != actualRead) {
                            ok = false;
                            break;
                        }
                    }
                    
                    if (actualRead < BLOCK_SIZE) {
                        break;
                    }
                }
                
                ok = ok && saveFile.commit();
                
                if (!ok) {
                    status.errorCode = DownloadTask::ERROR_FILE_OP_FAILED;
                    status.errorStr = saveFile.errorString().toStdString();
                }
            }
            
            data.clear();
        }
    }
    
    if (status.errorCode == 0) {
        status = qtNetworkReplyStatus(reply, error);
    }
    _owner->onTaskFinish(
        *_taskPtr, 
        status.errorCode, 
        status.errorCodeInternal, 
        status.errorStr, 
        data);
}

}}  //  namespace cocos2d::network

