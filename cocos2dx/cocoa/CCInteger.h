#ifndef __CCINTEGER_H__
#define __CCINTEGER_H__

#include "CCObject.h"
#include <cstdint>

NS_CC_BEGIN

/**
 * @addtogroup data_structures
 * @{
 * @js NA
 */

class CC_DLL CCInteger : public CCObject
{
public:
    CCInteger(int64_t v)
        : m_nValue(v) {}
    int64_t getValue() const {return m_nValue;}

    static CCInteger* create(int v)
    {
        CCInteger* pRet = new CCInteger(v);
        pRet->autorelease();
        return pRet;
    }

    /* override functions
     * @lua NA
     */
    virtual void acceptVisitor(CCDataVisitor &visitor) { visitor.visit(this); }

private:
    int64_t m_nValue;
};

// end of data_structure group
/// @}

NS_CC_END

#endif /* __CCINTEGER_H__ */
