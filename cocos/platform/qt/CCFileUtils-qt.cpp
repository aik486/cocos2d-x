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
#include "CCFileUtils-qt.h"

#include <QStandardPaths>
#include <QDir>
#include <QFileInfo>
#include <QFile>

#define DECLARE_GUARD std::lock_guard<std::recursive_mutex> mutexGuard(_mutex)

NS_CC_BEGIN

FileUtilsQt::FileUtilsQt() 
{
    _writablePath = QStandardPaths::writableLocation(
        QStandardPaths::CacheLocation).toStdString();
}

FileUtilsQt::~FileUtilsQt() = default;

FileUtils* FileUtils::getInstance()
{
    if (s_sharedFileUtils == nullptr)
    {
        s_sharedFileUtils = new (std::nothrow) FileUtilsQt();
        if (!s_sharedFileUtils->init())
        {
          delete s_sharedFileUtils;
          s_sharedFileUtils = nullptr;
          CCLOG("ERROR: Could not init CCFileUtilsQt");
        }
    }
    return s_sharedFileUtils;
}


std::string FileUtilsQt::getWritablePath() const
{
    DECLARE_GUARD;
    return _writablePath;
}

bool FileUtilsQt::isFileExistInternal(const std::string& filePath) const
{
    if (filePath.empty())
    {
        return false;
    }
    
    auto filePathQt = QString::fromStdString(filePath);
    
    if (QDir::isAbsolutePath(filePathQt))
    {
        return QFileInfo(filePathQt).isFile();
    }

    return false;
}

bool FileUtilsQt::isDirectoryExistInternal(const std::string &dirPath) const
{
    if (dirPath.empty())
    {
        return false;
    }
    
    auto dirPathQt = QString::fromStdString(dirPath);
    
    if (QDir::isAbsolutePath(dirPathQt))
    {
        return QFileInfo(dirPathQt).isDir();
    }

    return false;
}


bool FileUtilsQt::removeDirectory(const std::string& path) const
{
    auto dirPathQt = QString::fromStdString(path);
    
    if (QDir::isAbsolutePath(dirPathQt)) 
    {
        return QDir().rmdir(dirPathQt);
    }
    
    return false;
}

std::string FileUtilsQt::getPathForDirectory(const std::string &dir, const std::string &resolutionDiretory, const std::string &searchPath) const
{
    auto dirPath = searchPath + resolutionDiretory + dir;
    auto dirPathQt = QString::fromStdString(dirPath);

    if (QDir::isAbsolutePath(dirPathQt))
    {
        return dirPath;
    }

    dirPathQt = QStandardPaths::locate(
                QStandardPaths::AppDataLocation,
                dirPathQt, QStandardPaths::LocateDirectory);
    
    if (dirPathQt.isEmpty()) {
        return std::string();
    }
    
    return dirPathQt.toStdString();
}


std::string FileUtilsQt::getFullPathForFilenameWithinDirectory(const std::string& directory, const std::string& filename) const
{
   auto filePath = directory + filename;
   auto filePathQt = QString::fromStdString(filePath);
  
   if (QDir::isAbsolutePath(filePathQt)) {
       return filePath;
   }
   
   filePathQt = QStandardPaths::locate(
               QStandardPaths::AppDataLocation,
               filePathQt, QStandardPaths::LocateFile);
   
   if (filePathQt.isEmpty()) {
       return std::string();
   }
   
   return filePathQt.toStdString();
}

bool FileUtilsQt::createDirectory(const std::string& path) const
{
    auto dirPathQt = QString::fromStdString(path);
    if (dirPathQt.isEmpty() || !QDir::isAbsolutePath(dirPathQt)) {
        return false;
    }
    
    if (QFileInfo(dirPathQt).isDir())
        return true;
       
    return QDir().mkpath(dirPathQt);
}

NS_CC_END
