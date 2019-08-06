#pragma once

#include "js_bindings/manual/QtScriptCCObject.hpp"
#include "QtScriptBaseClassPrototype.h"
#include "include/cocos2d.h"

void qtscript_register_all_cocos2dx(QScriptEngine *engine);

namespace cocos2d {
class QtScriptCCDataVisitor : public QtScriptBaseClassPrototype<CCDataVisitor *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCDataVisitor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDataVisitor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void visitDict(const cocos2d::CCDictionary* p);
	Q_INVOKABLE void visitString(const cocos2d::CCString* p);
	Q_INVOKABLE void visitDouble(const cocos2d::CCDouble* p);
	Q_INVOKABLE void visitArray(const cocos2d::CCArray* p);
	Q_INVOKABLE void visitSet(const cocos2d::CCSet* p);
	Q_INVOKABLE void visitBool(const cocos2d::CCBool* p);
	Q_INVOKABLE void visitFloat(const cocos2d::CCFloat* p);
	Q_INVOKABLE void visitInt(const cocos2d::CCInteger* p);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCDataVisitor::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCDataVisitor *)
Q_DECLARE_METATYPE(const cocos2d::CCDataVisitor *)

namespace cocos2d {
class QtScriptCCPrettyPrinter : public QtScriptCCDataVisitor
{
	Q_OBJECT

protected:
	explicit QtScriptCCPrettyPrinter(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCPrettyPrinter(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void clear();
	Q_INVOKABLE void visitObject(const cocos2d::CCObject* p);
	Q_INVOKABLE QByteArray getResult();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCPrettyPrinter *)
Q_DECLARE_METATYPE(const cocos2d::CCPrettyPrinter *)

namespace cocos2d {
class QtScriptCCPoint final : public QtScriptBaseClassPrototype<CCPoint, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCPoint(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCPoint(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void set(const cocos2d::CCPoint& other);
	Q_INVOKABLE float getDistanceSq(const cocos2d::CCPoint& other);
	Q_INVOKABLE cocos2d::CCPoint normalize();
	Q_INVOKABLE float getLengthSq();
	Q_INVOKABLE cocos2d::CCPoint sub(const cocos2d::CCPoint& right);
	Q_INVOKABLE cocos2d::CCPoint neg();
	Q_INVOKABLE float cross(const cocos2d::CCPoint& other);
	Q_INVOKABLE cocos2d::CCPoint rotateByAngle(const cocos2d::CCPoint& pivot, float angle);
	Q_INVOKABLE cocos2d::CCPoint add(const cocos2d::CCPoint& right);
	Q_INVOKABLE bool fuzzyEquals(const cocos2d::CCPoint& target, float variance);
	Q_INVOKABLE float getDistance(const cocos2d::CCPoint& other);
	Q_INVOKABLE cocos2d::CCPoint unrotate(const cocos2d::CCPoint& other);
	Q_INVOKABLE cocos2d::CCPoint mul(float a);
	Q_INVOKABLE cocos2d::CCPoint lerp(const cocos2d::CCPoint& other, float alpha);
	Q_INVOKABLE bool equals(const cocos2d::CCPoint& target);
	Q_INVOKABLE cocos2d::CCPoint getPerp();
	Q_INVOKABLE cocos2d::CCPoint rotate(const cocos2d::CCPoint& other);
	Q_INVOKABLE float getAngle();
	Q_INVOKABLE float getAngle(const cocos2d::CCPoint& other);
	Q_INVOKABLE void setPoint(float x, float y);
	Q_INVOKABLE cocos2d::CCPoint project(const cocos2d::CCPoint& other);
	Q_INVOKABLE cocos2d::CCPoint getRPerp();
	Q_INVOKABLE float getLength();
	Q_INVOKABLE cocos2d::CCPoint div(float a);
	Q_INVOKABLE float dot(const cocos2d::CCPoint& other);
	static QScriptValue forAngle(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(float x READ _public_field_get_x WRITE _public_field_set_x)
	float _public_field_get_x() const;
	void _public_field_set_x(float value);
	Q_PROPERTY(float y READ _public_field_get_y WRITE _public_field_set_y)
	float _public_field_get_y() const;
	void _public_field_set_y(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCPoint)
Q_DECLARE_METATYPE(cocos2d::CCPoint *)
Q_DECLARE_METATYPE(const cocos2d::CCPoint *)

namespace cocos2d {
class QtScriptCCSize final : public QtScriptBaseClassPrototype<CCSize, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCSize(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSize(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void set(const cocos2d::CCSize& other);
	Q_INVOKABLE cocos2d::CCSize sub(const cocos2d::CCSize& right);
	Q_INVOKABLE bool equals(const cocos2d::CCSize& target);
	Q_INVOKABLE cocos2d::CCSize add(const cocos2d::CCSize& right);
	Q_INVOKABLE cocos2d::CCSize mul(float a);
	Q_INVOKABLE cocos2d::CCSize div(float a);
	Q_INVOKABLE void setSize(float width, float height);
	Q_PROPERTY(float width READ _public_field_get_width WRITE _public_field_set_width)
	float _public_field_get_width() const;
	void _public_field_set_width(float value);
	Q_PROPERTY(float height READ _public_field_get_height WRITE _public_field_set_height)
	float _public_field_get_height() const;
	void _public_field_set_height(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSize)
Q_DECLARE_METATYPE(cocos2d::CCSize *)
Q_DECLARE_METATYPE(const cocos2d::CCSize *)

namespace cocos2d {
class QtScriptCCRect final : public QtScriptBaseClassPrototype<CCRect, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCRect(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCRect(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void set(const cocos2d::CCRect& other);
	Q_INVOKABLE float getMaxY();
	Q_INVOKABLE float getMaxX();
	Q_INVOKABLE bool equals(const cocos2d::CCRect& rect);
	Q_INVOKABLE float getMinY();
	Q_INVOKABLE float getMinX();
	Q_INVOKABLE float getMidY();
	Q_INVOKABLE float getMidX();
	Q_INVOKABLE bool intersectsRect(const cocos2d::CCRect& rect);
	Q_INVOKABLE bool containsPoint(const cocos2d::CCPoint& point);
	Q_INVOKABLE void setRect(float x, float y, float width, float height);
	Q_PROPERTY(cocos2d::CCPoint origin READ _public_field_get_origin WRITE _public_field_set_origin)
	cocos2d::CCPoint _public_field_get_origin() const;
	void _public_field_set_origin(const cocos2d::CCPoint& value);
	Q_PROPERTY(cocos2d::CCSize size READ _public_field_get_size WRITE _public_field_set_size)
	cocos2d::CCSize _public_field_get_size() const;
	void _public_field_set_size(const cocos2d::CCSize& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCRect)
Q_DECLARE_METATYPE(cocos2d::CCRect *)
Q_DECLARE_METATYPE(const cocos2d::CCRect *)

namespace cocos2d {
class QtScriptCCAction : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCNode* originalTarget READ getOriginalTarget WRITE setOriginalTarget)
	Q_PROPERTY(cocos2d::CCNode* target READ getTarget WRITE setTarget)
	Q_PROPERTY(int tag READ getTag WRITE setTag)
	Q_INVOKABLE void startWithTarget(cocos2d::CCNode* pTarget);
	Q_INVOKABLE QByteArray description();
	void setOriginalTarget(cocos2d::CCNode* pOriginalTarget);
	void setTarget(cocos2d::CCNode* pTarget);
	cocos2d::CCNode* getOriginalTarget();
	Q_INVOKABLE void stop();
	cocos2d::CCNode* getTarget();
	Q_INVOKABLE void step(float dt);
	void setTag(int nTag);
	int getTag();
	Q_INVOKABLE bool isDone();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAction *)
Q_DECLARE_METATYPE(const cocos2d::CCAction *)

namespace cocos2d {
class QtScriptCCFiniteTimeAction : public QtScriptCCAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCFiniteTimeAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFiniteTimeAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float duration READ getDuration WRITE setDuration)
	void setDuration(float duration);
	Q_INVOKABLE cocos2d::CCFiniteTimeAction* reverse();
	float getDuration();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFiniteTimeAction *)
Q_DECLARE_METATYPE(const cocos2d::CCFiniteTimeAction *)

namespace cocos2d {
class QtScriptCCSpeed : public QtScriptCCAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCSpeed(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSpeed(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCActionInterval* innerAction READ getInnerAction WRITE setInnerAction)
	Q_PROPERTY(float speed READ getSpeed WRITE setSpeed)
	void setInnerAction(cocos2d::CCActionInterval* pAction);
	float getSpeed();
	void setSpeed(float fSpeed);
	Q_INVOKABLE bool initWithAction(cocos2d::CCActionInterval* pAction, float fSpeed);
	cocos2d::CCActionInterval* getInnerAction();
	Q_INVOKABLE cocos2d::CCActionInterval* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSpeed *)
Q_DECLARE_METATYPE(const cocos2d::CCSpeed *)

namespace cocos2d {
class QtScriptCCFollow : public QtScriptCCAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCFollow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFollow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool boundarySet READ isBoundarySet WRITE setBoundarySet)
	Q_INVOKABLE bool initWithTarget(cocos2d::CCNode* pFollowedNode);
	Q_INVOKABLE bool initWithTarget(cocos2d::CCNode* pFollowedNode, const cocos2d::CCRect& rect);
	void setBoundarySet(bool bValue);
	bool isBoundarySet();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFollow *)
Q_DECLARE_METATYPE(const cocos2d::CCFollow *)

namespace cocos2d {
class QtScriptCCAffineTransform final : public QtScriptBaseClassPrototype<CCAffineTransform, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCAffineTransform(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAffineTransform(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float a READ _public_field_get_a WRITE _public_field_set_a)
	float _public_field_get_a() const;
	void _public_field_set_a(float value);
	Q_PROPERTY(float b READ _public_field_get_b WRITE _public_field_set_b)
	float _public_field_get_b() const;
	void _public_field_set_b(float value);
	Q_PROPERTY(float c READ _public_field_get_c WRITE _public_field_set_c)
	float _public_field_get_c() const;
	void _public_field_set_c(float value);
	Q_PROPERTY(float d READ _public_field_get_d WRITE _public_field_set_d)
	float _public_field_get_d() const;
	void _public_field_set_d(float value);
	Q_PROPERTY(float tx READ _public_field_get_tx WRITE _public_field_set_tx)
	float _public_field_get_tx() const;
	void _public_field_set_tx(float value);
	Q_PROPERTY(float ty READ _public_field_get_ty WRITE _public_field_set_ty)
	float _public_field_get_ty() const;
	void _public_field_set_ty(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAffineTransform)
Q_DECLARE_METATYPE(cocos2d::CCAffineTransform *)
Q_DECLARE_METATYPE(const cocos2d::CCAffineTransform *)

namespace cocos2d {
class QtScriptCCArray : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCArray(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCArray(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithArray(cocos2d::CCArray* otherArray);
	Q_INVOKABLE void reverseObjects();
	Q_INVOKABLE void insertObject(cocos2d::CCObject* object, unsigned int index);
	Q_INVOKABLE void removeAllObjects();
	Q_INVOKABLE void exchangeObjectAtIndex(unsigned int index1, unsigned int index2);
	Q_INVOKABLE bool containsObject(cocos2d::CCObject* object);
	Q_INVOKABLE unsigned int capacity();
	Q_INVOKABLE bool initWithCapacity(unsigned int capacity);
	Q_INVOKABLE bool init();
	Q_INVOKABLE void removeObjectsInArray(cocos2d::CCArray* otherArray);
	Q_INVOKABLE void fastRemoveObjectAtIndex(unsigned int index);
	Q_INVOKABLE void addObject(cocos2d::CCObject* object);
	Q_INVOKABLE unsigned int indexOfObject(cocos2d::CCObject* object);
	Q_INVOKABLE void addObjectsFromArray(cocos2d::CCArray* otherArray);
	Q_INVOKABLE cocos2d::CCObject* lastObject();
	Q_INVOKABLE void exchangeObject(cocos2d::CCObject* object1, cocos2d::CCObject* object2);
	Q_INVOKABLE void fastRemoveObject(cocos2d::CCObject* object);
	Q_INVOKABLE void replaceObjectAtIndex(unsigned int uIndex, cocos2d::CCObject* pObject);
	Q_INVOKABLE void replaceObjectAtIndex(unsigned int uIndex, cocos2d::CCObject* pObject, bool bReleaseObject);
	Q_INVOKABLE cocos2d::CCObject* randomObject();
	Q_INVOKABLE void reduceMemoryFootprint();
	Q_INVOKABLE bool isEqualToArray(cocos2d::CCArray* pOtherArray);
	Q_INVOKABLE unsigned int count();
	Q_INVOKABLE bool initWithObject(cocos2d::CCObject* pObject);
	Q_INVOKABLE void removeObjectAtIndex(unsigned int index);
	Q_INVOKABLE void removeObjectAtIndex(unsigned int index, bool bReleaseObj);
	Q_INVOKABLE void removeLastObject();
	Q_INVOKABLE void removeLastObject(bool bReleaseObj);
	Q_INVOKABLE void removeObject(cocos2d::CCObject* object);
	Q_INVOKABLE void removeObject(cocos2d::CCObject* object, bool bReleaseObj);
	Q_INVOKABLE cocos2d::CCObject* objectAtIndex(unsigned int index);
	static QScriptValue createWithContentsOfFile(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithArray(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithCapacity(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithObject(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithContentsOfFileThreadSafe(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCArray *)
Q_DECLARE_METATYPE(const cocos2d::CCArray *)

namespace cocos2d {
class QtScriptCCGLProgram : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCGLProgram(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCGLProgram(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void reset();
	Q_INVOKABLE void use();
	Q_INVOKABLE void setUniformLocationWith1i(int location, int i1);
	Q_INVOKABLE void setUniformLocationWith2f(int location, float f1, float f2);
	Q_INVOKABLE QByteArray vertexShaderLog();
	Q_INVOKABLE void setUniformLocationWith1f(int location, float f1);
	Q_INVOKABLE unsigned int getProgram();
	Q_INVOKABLE bool initWithVertexShaderFilename(const QByteArray& vShaderFilename, const QByteArray& fShaderFilename);
	Q_INVOKABLE void updateUniforms();
	Q_INVOKABLE QByteArray fragmentShaderLog();
	Q_INVOKABLE void addAttribute(const QByteArray& attributeName, unsigned int index);
	Q_INVOKABLE QByteArray programLog();
	Q_INVOKABLE bool initWithVertexShaderByteArray(const QByteArray& vShaderByteArray, const QByteArray& fShaderByteArray);
	Q_INVOKABLE void setUniformLocationWith3f(int location, float f1, float f2, float f3);
	Q_INVOKABLE bool link();
	Q_INVOKABLE void setUniformLocationWith2i(int location, int i1, int i2);
	Q_INVOKABLE void setUniformsForBuiltins();
	Q_INVOKABLE void setUniformLocationWith4f(int location, float f1, float f2, float f3, float f4);
	Q_INVOKABLE void setUniformLocationWith4i(int location, int i1, int i2, int i3, int i4);
	Q_INVOKABLE void setUniformLocationWith3i(int location, int i1, int i2, int i3);
	Q_INVOKABLE int getUniformLocationForName(const QByteArray& name);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCGLProgram *)
Q_DECLARE_METATYPE(const cocos2d::CCGLProgram *)

namespace cocos2d {
class QtScriptCCAcceleration final : public QtScriptBaseClassPrototype<CCAcceleration, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCAcceleration(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAcceleration(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(double x READ _public_field_get_x WRITE _public_field_set_x)
	double _public_field_get_x() const;
	void _public_field_set_x(double value);
	Q_PROPERTY(double y READ _public_field_get_y WRITE _public_field_set_y)
	double _public_field_get_y() const;
	void _public_field_set_y(double value);
	Q_PROPERTY(double z READ _public_field_get_z WRITE _public_field_set_z)
	double _public_field_get_z() const;
	void _public_field_set_z(double value);
	Q_PROPERTY(double timestamp READ _public_field_get_timestamp WRITE _public_field_set_timestamp)
	double _public_field_get_timestamp() const;
	void _public_field_set_timestamp(double value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAcceleration)
Q_DECLARE_METATYPE(cocos2d::CCAcceleration *)
Q_DECLARE_METATYPE(const cocos2d::CCAcceleration *)

namespace cocos2d {
class QtScriptCCTouch : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCTouch(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTouch(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCPoint getPreviousLocationInView();
	Q_INVOKABLE cocos2d::CCPoint getLocation();
	Q_INVOKABLE cocos2d::CCPoint getDelta();
	Q_INVOKABLE cocos2d::CCPoint getStartLocationInView();
	Q_INVOKABLE cocos2d::CCPoint getStartLocation();
	Q_INVOKABLE int getID();
	Q_INVOKABLE void setTouchInfo(int id, float x, float y);
	Q_INVOKABLE cocos2d::CCPoint getLocationInView();
	Q_INVOKABLE cocos2d::CCPoint getPreviousLocation();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTouch *)
Q_DECLARE_METATYPE(const cocos2d::CCTouch *)

namespace cocos2d {
class QtScriptCCEvent : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCEvent(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEvent(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEvent *)
Q_DECLARE_METATYPE(const cocos2d::CCEvent *)

namespace cocos2d {
class QtScriptCCSet : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCSet(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSet(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int count();
	Q_INVOKABLE void addObject(cocos2d::CCObject* pObject);
	Q_INVOKABLE cocos2d::CCObject* anyObject();
	Q_INVOKABLE void removeAllObjects();
	Q_INVOKABLE void removeObject(cocos2d::CCObject* pObject);
	Q_INVOKABLE bool containsObject(cocos2d::CCObject* pObject);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSet *)
Q_DECLARE_METATYPE(const cocos2d::CCSet *)

namespace cocos2d {
class QtScriptCCScriptHandlerEntry : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCScriptHandlerEntry(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCScriptHandlerEntry(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int64_t getHandler();
	Q_INVOKABLE unsigned int getEntryId();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCScriptHandlerEntry *)
Q_DECLARE_METATYPE(const cocos2d::CCScriptHandlerEntry *)

namespace cocos2d {
class QtScriptCCSchedulerScriptHandlerEntry : public QtScriptCCScriptHandlerEntry
{
	Q_OBJECT

protected:
	explicit QtScriptCCSchedulerScriptHandlerEntry(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSchedulerScriptHandlerEntry(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool isMarkedForDeletion();
	Q_INVOKABLE void markedForDeletion();
	Q_INVOKABLE bool isPaused();
	Q_INVOKABLE cocos2d::CCTimer* getTimer();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSchedulerScriptHandlerEntry *)
Q_DECLARE_METATYPE(const cocos2d::CCSchedulerScriptHandlerEntry *)

namespace cocos2d {
class QtScriptCCTouchScriptHandlerEntry : public QtScriptCCScriptHandlerEntry
{
	Q_OBJECT

protected:
	explicit QtScriptCCTouchScriptHandlerEntry(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTouchScriptHandlerEntry(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool isMultiTouches();
	Q_INVOKABLE bool getSwallowsTouches();
	Q_INVOKABLE int getPriority();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTouchScriptHandlerEntry *)
Q_DECLARE_METATYPE(const cocos2d::CCTouchScriptHandlerEntry *)

namespace cocos2d {
class QtScript_ccColor3B final : public QtScriptBaseClassPrototype<_ccColor3B, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccColor3B(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccColor3B(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned char r READ _public_field_get_r WRITE _public_field_set_r)
	unsigned char _public_field_get_r() const;
	void _public_field_set_r(unsigned char value);
	Q_PROPERTY(unsigned char g READ _public_field_get_g WRITE _public_field_set_g)
	unsigned char _public_field_get_g() const;
	void _public_field_set_g(unsigned char value);
	Q_PROPERTY(unsigned char b READ _public_field_get_b WRITE _public_field_set_b)
	unsigned char _public_field_get_b() const;
	void _public_field_set_b(unsigned char value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccColor3B)
Q_DECLARE_METATYPE(cocos2d::_ccColor3B *)
Q_DECLARE_METATYPE(const cocos2d::_ccColor3B *)

namespace cocos2d {
class QtScript_ccColor4B final : public QtScriptBaseClassPrototype<_ccColor4B, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccColor4B(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccColor4B(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned char r READ _public_field_get_r WRITE _public_field_set_r)
	unsigned char _public_field_get_r() const;
	void _public_field_set_r(unsigned char value);
	Q_PROPERTY(unsigned char g READ _public_field_get_g WRITE _public_field_set_g)
	unsigned char _public_field_get_g() const;
	void _public_field_set_g(unsigned char value);
	Q_PROPERTY(unsigned char b READ _public_field_get_b WRITE _public_field_set_b)
	unsigned char _public_field_get_b() const;
	void _public_field_set_b(unsigned char value);
	Q_PROPERTY(unsigned char a READ _public_field_get_a WRITE _public_field_set_a)
	unsigned char _public_field_get_a() const;
	void _public_field_set_a(unsigned char value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccColor4B)
Q_DECLARE_METATYPE(cocos2d::_ccColor4B *)
Q_DECLARE_METATYPE(const cocos2d::_ccColor4B *)

namespace cocos2d {
class QtScript_ccColor4F final : public QtScriptBaseClassPrototype<_ccColor4F, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccColor4F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccColor4F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float r READ _public_field_get_r WRITE _public_field_set_r)
	float _public_field_get_r() const;
	void _public_field_set_r(float value);
	Q_PROPERTY(float g READ _public_field_get_g WRITE _public_field_set_g)
	float _public_field_get_g() const;
	void _public_field_set_g(float value);
	Q_PROPERTY(float b READ _public_field_get_b WRITE _public_field_set_b)
	float _public_field_get_b() const;
	void _public_field_set_b(float value);
	Q_PROPERTY(float a READ _public_field_get_a WRITE _public_field_set_a)
	float _public_field_get_a() const;
	void _public_field_set_a(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccColor4F)
Q_DECLARE_METATYPE(cocos2d::_ccColor4F *)
Q_DECLARE_METATYPE(const cocos2d::_ccColor4F *)

namespace cocos2d {
class QtScript_ccVertex2F final : public QtScriptBaseClassPrototype<_ccVertex2F, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccVertex2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccVertex2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float x READ _public_field_get_x WRITE _public_field_set_x)
	float _public_field_get_x() const;
	void _public_field_set_x(float value);
	Q_PROPERTY(float y READ _public_field_get_y WRITE _public_field_set_y)
	float _public_field_get_y() const;
	void _public_field_set_y(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccVertex2F)
Q_DECLARE_METATYPE(cocos2d::_ccVertex2F *)
Q_DECLARE_METATYPE(const cocos2d::_ccVertex2F *)

namespace cocos2d {
class QtScript_ccVertex3F final : public QtScriptBaseClassPrototype<_ccVertex3F, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccVertex3F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccVertex3F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float x READ _public_field_get_x WRITE _public_field_set_x)
	float _public_field_get_x() const;
	void _public_field_set_x(float value);
	Q_PROPERTY(float y READ _public_field_get_y WRITE _public_field_set_y)
	float _public_field_get_y() const;
	void _public_field_set_y(float value);
	Q_PROPERTY(float z READ _public_field_get_z WRITE _public_field_set_z)
	float _public_field_get_z() const;
	void _public_field_set_z(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccVertex3F)
Q_DECLARE_METATYPE(cocos2d::_ccVertex3F *)
Q_DECLARE_METATYPE(const cocos2d::_ccVertex3F *)

namespace cocos2d {
class QtScript_ccTex2F final : public QtScriptBaseClassPrototype<_ccTex2F, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccTex2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccTex2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float u READ _public_field_get_u WRITE _public_field_set_u)
	float _public_field_get_u() const;
	void _public_field_set_u(float value);
	Q_PROPERTY(float v READ _public_field_get_v WRITE _public_field_set_v)
	float _public_field_get_v() const;
	void _public_field_set_v(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccTex2F)
Q_DECLARE_METATYPE(cocos2d::_ccTex2F *)
Q_DECLARE_METATYPE(const cocos2d::_ccTex2F *)

namespace cocos2d {
class QtScript_ccPointSprite final : public QtScriptBaseClassPrototype<_ccPointSprite, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccPointSprite(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccPointSprite(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccVertex2F pos READ _public_field_get_pos WRITE _public_field_set_pos)
	cocos2d::_ccVertex2F _public_field_get_pos() const;
	void _public_field_set_pos(const cocos2d::_ccVertex2F& value);
	Q_PROPERTY(cocos2d::_ccColor4B color READ _public_field_get_color WRITE _public_field_set_color)
	cocos2d::_ccColor4B _public_field_get_color() const;
	void _public_field_set_color(const cocos2d::_ccColor4B& value);
	Q_PROPERTY(float size READ _public_field_get_size WRITE _public_field_set_size)
	float _public_field_get_size() const;
	void _public_field_set_size(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccPointSprite)
Q_DECLARE_METATYPE(cocos2d::_ccPointSprite *)
Q_DECLARE_METATYPE(const cocos2d::_ccPointSprite *)

namespace cocos2d {
class QtScript_ccQuad2 final : public QtScriptBaseClassPrototype<_ccQuad2, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccQuad2(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccQuad2(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccVertex2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::_ccVertex2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::_ccVertex2F& value);
	Q_PROPERTY(cocos2d::_ccVertex2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::_ccVertex2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::_ccVertex2F& value);
	Q_PROPERTY(cocos2d::_ccVertex2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::_ccVertex2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::_ccVertex2F& value);
	Q_PROPERTY(cocos2d::_ccVertex2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::_ccVertex2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::_ccVertex2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccQuad2)
Q_DECLARE_METATYPE(cocos2d::_ccQuad2 *)
Q_DECLARE_METATYPE(const cocos2d::_ccQuad2 *)

namespace cocos2d {
class QtScript_ccQuad3 final : public QtScriptBaseClassPrototype<_ccQuad3, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccQuad3(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccQuad3(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccVertex3F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::_ccVertex3F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::_ccVertex3F& value);
	Q_PROPERTY(cocos2d::_ccVertex3F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::_ccVertex3F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::_ccVertex3F& value);
	Q_PROPERTY(cocos2d::_ccVertex3F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::_ccVertex3F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::_ccVertex3F& value);
	Q_PROPERTY(cocos2d::_ccVertex3F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::_ccVertex3F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::_ccVertex3F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccQuad3)
Q_DECLARE_METATYPE(cocos2d::_ccQuad3 *)
Q_DECLARE_METATYPE(const cocos2d::_ccQuad3 *)

namespace cocos2d {
class QtScript_ccV2F_C4B_T2F final : public QtScriptBaseClassPrototype<_ccV2F_C4B_T2F, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccV2F_C4B_T2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccV2F_C4B_T2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccVertex2F vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::_ccVertex2F _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::_ccVertex2F& value);
	Q_PROPERTY(cocos2d::_ccColor4B colors READ _public_field_get_colors WRITE _public_field_set_colors)
	cocos2d::_ccColor4B _public_field_get_colors() const;
	void _public_field_set_colors(const cocos2d::_ccColor4B& value);
	Q_PROPERTY(cocos2d::_ccTex2F texCoords READ _public_field_get_texCoords WRITE _public_field_set_texCoords)
	cocos2d::_ccTex2F _public_field_get_texCoords() const;
	void _public_field_set_texCoords(const cocos2d::_ccTex2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4B_T2F)
Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4B_T2F *)
Q_DECLARE_METATYPE(const cocos2d::_ccV2F_C4B_T2F *)

namespace cocos2d {
class QtScript_ccV2F_C4F_T2F final : public QtScriptBaseClassPrototype<_ccV2F_C4F_T2F, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccV2F_C4F_T2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccV2F_C4F_T2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccVertex2F vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::_ccVertex2F _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::_ccVertex2F& value);
	Q_PROPERTY(cocos2d::_ccColor4F colors READ _public_field_get_colors WRITE _public_field_set_colors)
	cocos2d::_ccColor4F _public_field_get_colors() const;
	void _public_field_set_colors(const cocos2d::_ccColor4F& value);
	Q_PROPERTY(cocos2d::_ccTex2F texCoords READ _public_field_get_texCoords WRITE _public_field_set_texCoords)
	cocos2d::_ccTex2F _public_field_get_texCoords() const;
	void _public_field_set_texCoords(const cocos2d::_ccTex2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4F_T2F)
Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4F_T2F *)
Q_DECLARE_METATYPE(const cocos2d::_ccV2F_C4F_T2F *)

namespace cocos2d {
class QtScript_ccV3F_C4B_T2F final : public QtScriptBaseClassPrototype<_ccV3F_C4B_T2F, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccV3F_C4B_T2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccV3F_C4B_T2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccVertex3F vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::_ccVertex3F _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::_ccVertex3F& value);
	Q_PROPERTY(cocos2d::_ccColor4B colors READ _public_field_get_colors WRITE _public_field_set_colors)
	cocos2d::_ccColor4B _public_field_get_colors() const;
	void _public_field_set_colors(const cocos2d::_ccColor4B& value);
	Q_PROPERTY(cocos2d::_ccTex2F texCoords READ _public_field_get_texCoords WRITE _public_field_set_texCoords)
	cocos2d::_ccTex2F _public_field_get_texCoords() const;
	void _public_field_set_texCoords(const cocos2d::_ccTex2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccV3F_C4B_T2F)
Q_DECLARE_METATYPE(cocos2d::_ccV3F_C4B_T2F *)
Q_DECLARE_METATYPE(const cocos2d::_ccV3F_C4B_T2F *)

namespace cocos2d {
class QtScript_ccV2F_C4B_T2F_Triangle final : public QtScriptBaseClassPrototype<_ccV2F_C4B_T2F_Triangle, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccV2F_C4B_T2F_Triangle(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccV2F_C4B_T2F_Triangle(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccV2F_C4B_T2F a READ _public_field_get_a WRITE _public_field_set_a)
	cocos2d::_ccV2F_C4B_T2F _public_field_get_a() const;
	void _public_field_set_a(const cocos2d::_ccV2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::_ccV2F_C4B_T2F b READ _public_field_get_b WRITE _public_field_set_b)
	cocos2d::_ccV2F_C4B_T2F _public_field_get_b() const;
	void _public_field_set_b(const cocos2d::_ccV2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::_ccV2F_C4B_T2F c READ _public_field_get_c WRITE _public_field_set_c)
	cocos2d::_ccV2F_C4B_T2F _public_field_get_c() const;
	void _public_field_set_c(const cocos2d::_ccV2F_C4B_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4B_T2F_Triangle)
Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4B_T2F_Triangle *)
Q_DECLARE_METATYPE(const cocos2d::_ccV2F_C4B_T2F_Triangle *)

namespace cocos2d {
class QtScript_ccV2F_C4B_T2F_Quad final : public QtScriptBaseClassPrototype<_ccV2F_C4B_T2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccV2F_C4B_T2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccV2F_C4B_T2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccV2F_C4B_T2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::_ccV2F_C4B_T2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::_ccV2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::_ccV2F_C4B_T2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::_ccV2F_C4B_T2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::_ccV2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::_ccV2F_C4B_T2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::_ccV2F_C4B_T2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::_ccV2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::_ccV2F_C4B_T2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::_ccV2F_C4B_T2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::_ccV2F_C4B_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4B_T2F_Quad)
Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4B_T2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::_ccV2F_C4B_T2F_Quad *)

namespace cocos2d {
class QtScript_ccV3F_C4B_T2F_Quad final : public QtScriptBaseClassPrototype<_ccV3F_C4B_T2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccV3F_C4B_T2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccV3F_C4B_T2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccV3F_C4B_T2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::_ccV3F_C4B_T2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::_ccV3F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::_ccV3F_C4B_T2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::_ccV3F_C4B_T2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::_ccV3F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::_ccV3F_C4B_T2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::_ccV3F_C4B_T2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::_ccV3F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::_ccV3F_C4B_T2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::_ccV3F_C4B_T2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::_ccV3F_C4B_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccV3F_C4B_T2F_Quad)
Q_DECLARE_METATYPE(cocos2d::_ccV3F_C4B_T2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::_ccV3F_C4B_T2F_Quad *)

namespace cocos2d {
class QtScript_ccV2F_C4F_T2F_Quad final : public QtScriptBaseClassPrototype<_ccV2F_C4F_T2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccV2F_C4F_T2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccV2F_C4F_T2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccV2F_C4F_T2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::_ccV2F_C4F_T2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::_ccV2F_C4F_T2F& value);
	Q_PROPERTY(cocos2d::_ccV2F_C4F_T2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::_ccV2F_C4F_T2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::_ccV2F_C4F_T2F& value);
	Q_PROPERTY(cocos2d::_ccV2F_C4F_T2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::_ccV2F_C4F_T2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::_ccV2F_C4F_T2F& value);
	Q_PROPERTY(cocos2d::_ccV2F_C4F_T2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::_ccV2F_C4F_T2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::_ccV2F_C4F_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4F_T2F_Quad)
Q_DECLARE_METATYPE(cocos2d::_ccV2F_C4F_T2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::_ccV2F_C4F_T2F_Quad *)

namespace cocos2d {
class QtScript_ccBlendFunc final : public QtScriptBaseClassPrototype<_ccBlendFunc, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccBlendFunc(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccBlendFunc(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int src READ _public_field_get_src WRITE _public_field_set_src)
	unsigned int _public_field_get_src() const;
	void _public_field_set_src(unsigned int value);
	Q_PROPERTY(unsigned int dst READ _public_field_get_dst WRITE _public_field_set_dst)
	unsigned int _public_field_get_dst() const;
	void _public_field_set_dst(unsigned int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccBlendFunc)
Q_DECLARE_METATYPE(cocos2d::_ccBlendFunc *)
Q_DECLARE_METATYPE(const cocos2d::_ccBlendFunc *)

namespace cocos2d {
class QtScript_ccT2F_Quad final : public QtScriptBaseClassPrototype<_ccT2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccT2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccT2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccTex2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::_ccTex2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::_ccTex2F& value);
	Q_PROPERTY(cocos2d::_ccTex2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::_ccTex2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::_ccTex2F& value);
	Q_PROPERTY(cocos2d::_ccTex2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::_ccTex2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::_ccTex2F& value);
	Q_PROPERTY(cocos2d::_ccTex2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::_ccTex2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::_ccTex2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccT2F_Quad)
Q_DECLARE_METATYPE(cocos2d::_ccT2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::_ccT2F_Quad *)

namespace cocos2d {
class QtScriptccAnimationFrameData final : public QtScriptBaseClassPrototype<ccAnimationFrameData, false>
{
	Q_OBJECT

protected:
	explicit QtScriptccAnimationFrameData(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptccAnimationFrameData(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccT2F_Quad texCoords READ _public_field_get_texCoords WRITE _public_field_set_texCoords)
	cocos2d::_ccT2F_Quad _public_field_get_texCoords() const;
	void _public_field_set_texCoords(const cocos2d::_ccT2F_Quad& value);
	Q_PROPERTY(float delay READ _public_field_get_delay WRITE _public_field_set_delay)
	float _public_field_get_delay() const;
	void _public_field_set_delay(float value);
	Q_PROPERTY(cocos2d::CCSize size READ _public_field_get_size WRITE _public_field_set_size)
	cocos2d::CCSize _public_field_get_size() const;
	void _public_field_set_size(const cocos2d::CCSize& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ccAnimationFrameData)
Q_DECLARE_METATYPE(cocos2d::ccAnimationFrameData *)
Q_DECLARE_METATYPE(const cocos2d::ccAnimationFrameData *)

namespace cocos2d {
class QtScript_ccFontShadow final : public QtScriptBaseClassPrototype<_ccFontShadow, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccFontShadow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccFontShadow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool shadowEnabled READ _public_field_get_shadowEnabled WRITE _public_field_set_shadowEnabled)
	bool _public_field_get_shadowEnabled() const;
	void _public_field_set_shadowEnabled(const bool& value);
	Q_PROPERTY(cocos2d::CCSize shadowOffset READ _public_field_get_shadowOffset WRITE _public_field_set_shadowOffset)
	cocos2d::CCSize _public_field_get_shadowOffset() const;
	void _public_field_set_shadowOffset(const cocos2d::CCSize& value);
	Q_PROPERTY(float shadowBlur READ _public_field_get_shadowBlur WRITE _public_field_set_shadowBlur)
	float _public_field_get_shadowBlur() const;
	void _public_field_set_shadowBlur(float value);
	Q_PROPERTY(float shadowOpacity READ _public_field_get_shadowOpacity WRITE _public_field_set_shadowOpacity)
	float _public_field_get_shadowOpacity() const;
	void _public_field_set_shadowOpacity(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccFontShadow)
Q_DECLARE_METATYPE(cocos2d::_ccFontShadow *)
Q_DECLARE_METATYPE(const cocos2d::_ccFontShadow *)

namespace cocos2d {
class QtScript_ccFontStroke final : public QtScriptBaseClassPrototype<_ccFontStroke, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccFontStroke(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccFontStroke(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool strokeEnabled READ _public_field_get_strokeEnabled WRITE _public_field_set_strokeEnabled)
	bool _public_field_get_strokeEnabled() const;
	void _public_field_set_strokeEnabled(const bool& value);
	Q_PROPERTY(cocos2d::_ccColor3B strokeColor READ _public_field_get_strokeColor WRITE _public_field_set_strokeColor)
	cocos2d::_ccColor3B _public_field_get_strokeColor() const;
	void _public_field_set_strokeColor(const cocos2d::_ccColor3B& value);
	Q_PROPERTY(float strokeSize READ _public_field_get_strokeSize WRITE _public_field_set_strokeSize)
	float _public_field_get_strokeSize() const;
	void _public_field_set_strokeSize(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccFontStroke)
Q_DECLARE_METATYPE(cocos2d::_ccFontStroke *)
Q_DECLARE_METATYPE(const cocos2d::_ccFontStroke *)

namespace cocos2d {
class QtScript_ccFontDefinition final : public QtScriptBaseClassPrototype<_ccFontDefinition, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccFontDefinition(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccFontDefinition(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray fontName READ _public_field_get_fontName WRITE _public_field_set_fontName)
	QByteArray _public_field_get_fontName() const;
	void _public_field_set_fontName(const QByteArray& value);
	Q_PROPERTY(int fontSize READ _public_field_get_fontSize WRITE _public_field_set_fontSize)
	int _public_field_get_fontSize() const;
	void _public_field_set_fontSize(int value);
	Q_PROPERTY(int alignment READ _public_field_get_alignment WRITE _public_field_set_alignment)
	int _public_field_get_alignment() const;
	void _public_field_set_alignment(int value);
	Q_PROPERTY(int vertAlignment READ _public_field_get_vertAlignment WRITE _public_field_set_vertAlignment)
	int _public_field_get_vertAlignment() const;
	void _public_field_set_vertAlignment(int value);
	Q_PROPERTY(cocos2d::CCSize dimensions READ _public_field_get_dimensions WRITE _public_field_set_dimensions)
	cocos2d::CCSize _public_field_get_dimensions() const;
	void _public_field_set_dimensions(const cocos2d::CCSize& value);
	Q_PROPERTY(cocos2d::_ccColor3B fontFillColor READ _public_field_get_fontFillColor WRITE _public_field_set_fontFillColor)
	cocos2d::_ccColor3B _public_field_get_fontFillColor() const;
	void _public_field_set_fontFillColor(const cocos2d::_ccColor3B& value);
	Q_PROPERTY(cocos2d::_ccFontShadow shadow READ _public_field_get_shadow WRITE _public_field_set_shadow)
	cocos2d::_ccFontShadow _public_field_get_shadow() const;
	void _public_field_set_shadow(const cocos2d::_ccFontShadow& value);
	Q_PROPERTY(cocos2d::_ccFontStroke stroke READ _public_field_get_stroke WRITE _public_field_set_stroke)
	cocos2d::_ccFontStroke _public_field_get_stroke() const;
	void _public_field_set_stroke(const cocos2d::_ccFontStroke& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccFontDefinition)
Q_DECLARE_METATYPE(cocos2d::_ccFontDefinition *)
Q_DECLARE_METATYPE(const cocos2d::_ccFontDefinition *)

namespace cocos2d {
class QtScript_ccPVRTexturePixelFormatInfo final : public QtScriptBaseClassPrototype<_ccPVRTexturePixelFormatInfo, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccPVRTexturePixelFormatInfo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccPVRTexturePixelFormatInfo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int internalFormat READ _public_field_get_internalFormat WRITE _public_field_set_internalFormat)
	unsigned int _public_field_get_internalFormat() const;
	void _public_field_set_internalFormat(unsigned int value);
	Q_PROPERTY(unsigned int format READ _public_field_get_format WRITE _public_field_set_format)
	unsigned int _public_field_get_format() const;
	void _public_field_set_format(unsigned int value);
	Q_PROPERTY(unsigned int type READ _public_field_get_type WRITE _public_field_set_type)
	unsigned int _public_field_get_type() const;
	void _public_field_set_type(unsigned int value);
	Q_PROPERTY(uint32_t bpp READ _public_field_get_bpp WRITE _public_field_set_bpp)
	uint32_t _public_field_get_bpp() const;
	void _public_field_set_bpp(uint32_t value);
	Q_PROPERTY(bool compressed READ _public_field_get_compressed WRITE _public_field_set_compressed)
	bool _public_field_get_compressed() const;
	void _public_field_set_compressed(const bool& value);
	Q_PROPERTY(bool alpha READ _public_field_get_alpha WRITE _public_field_set_alpha)
	bool _public_field_get_alpha() const;
	void _public_field_set_alpha(const bool& value);
	Q_PROPERTY(int ccPixelFormat READ _public_field_get_ccPixelFormat WRITE _public_field_set_ccPixelFormat)
	int _public_field_get_ccPixelFormat() const;
	void _public_field_set_ccPixelFormat(int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccPVRTexturePixelFormatInfo)
Q_DECLARE_METATYPE(cocos2d::_ccPVRTexturePixelFormatInfo *)
Q_DECLARE_METATYPE(const cocos2d::_ccPVRTexturePixelFormatInfo *)

namespace cocos2d {
class QtScriptCCTexturePVR : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCTexturePVR(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTexturePVR(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool retainName READ isRetainName WRITE setRetainName)
	Q_INVOKABLE bool initWithData(const QByteArray& data, size_t len, int compression);
	Q_INVOKABLE bool initWithContentsOfFile(const QByteArray& path);
	Q_INVOKABLE bool isForcePremultipliedAlpha();
	Q_INVOKABLE unsigned int getHeight();
	Q_INVOKABLE unsigned int getName();
	void setRetainName(bool retainName);
	Q_INVOKABLE bool hasAlpha();
	Q_INVOKABLE unsigned int getWidth();
	Q_INVOKABLE unsigned int getNumberOfMipmaps();
	Q_INVOKABLE bool hasPremultipliedAlpha();
	Q_INVOKABLE int getFormat();
	bool isRetainName();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTexturePVR *)
Q_DECLARE_METATYPE(const cocos2d::CCTexturePVR *)

namespace cocos2d {
class QtScript_ccTexParams final : public QtScriptBaseClassPrototype<_ccTexParams, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccTexParams(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccTexParams(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int minFilter READ _public_field_get_minFilter WRITE _public_field_set_minFilter)
	unsigned int _public_field_get_minFilter() const;
	void _public_field_set_minFilter(unsigned int value);
	Q_PROPERTY(unsigned int magFilter READ _public_field_get_magFilter WRITE _public_field_set_magFilter)
	unsigned int _public_field_get_magFilter() const;
	void _public_field_set_magFilter(unsigned int value);
	Q_PROPERTY(unsigned int wrapS READ _public_field_get_wrapS WRITE _public_field_set_wrapS)
	unsigned int _public_field_get_wrapS() const;
	void _public_field_set_wrapS(unsigned int value);
	Q_PROPERTY(unsigned int wrapT READ _public_field_get_wrapT WRITE _public_field_set_wrapT)
	unsigned int _public_field_get_wrapT() const;
	void _public_field_set_wrapT(unsigned int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccTexParams)
Q_DECLARE_METATYPE(cocos2d::_ccTexParams *)
Q_DECLARE_METATYPE(const cocos2d::_ccTexParams *)

namespace cocos2d {
class QtScriptCCTexture2D : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCTexture2D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTexture2D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCGLProgram* shaderProgram READ getShaderProgram WRITE setShaderProgram)
	Q_PROPERTY(float maxT READ getMaxT WRITE setMaxT)
	Q_PROPERTY(float maxS READ getMaxS WRITE setMaxS)
	cocos2d::CCGLProgram* getShaderProgram();
	Q_INVOKABLE bool initWithETCFile(const QByteArray& file);
	Q_INVOKABLE QByteArray stringForFormat();
	Q_INVOKABLE bool initWithImage(cocos2d::CCImage* uiImage);
	void setShaderProgram(cocos2d::CCGLProgram* var);
	float getMaxS();
	Q_INVOKABLE bool hasPremultipliedAlpha();
	Q_INVOKABLE unsigned int getPixelsHigh();
	Q_INVOKABLE void setTexParameters(cocos2d::_ccTexParams* texParams);
	Q_INVOKABLE unsigned int bitsPerPixelForFormat();
	Q_INVOKABLE unsigned int bitsPerPixelForFormat(int format);
	Q_INVOKABLE unsigned int getName();
	Q_INVOKABLE bool initWithString(const QByteArray& text, cocos2d::_ccFontDefinition* textDefinition);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize, const cocos2d::CCSize& dimensions, int hAlignment, int vAlignment);
	void setMaxT(float var);
	Q_INVOKABLE void drawInRect(const cocos2d::CCRect& rect);
	Q_INVOKABLE cocos2d::CCSize getContentSize();
	float getMaxT();
	Q_INVOKABLE void setAliasTexParameters();
	Q_INVOKABLE void setAntiAliasTexParameters();
	Q_INVOKABLE void generateMipmap();
	Q_INVOKABLE QByteArray description();
	Q_INVOKABLE int getPixelFormat();
	Q_INVOKABLE void initWithPVR(cocos2d::CCTexturePVR* pvr);
	Q_INVOKABLE bool initWithPVR(const QByteArray& data, size_t len, int compression);
	Q_INVOKABLE bool initWithPVRFile(const QByteArray& file);
	Q_INVOKABLE cocos2d::CCSize getContentSizeInPixels();
	Q_INVOKABLE unsigned int getPixelsWide();
	Q_INVOKABLE void drawAtPoint(const cocos2d::CCPoint& point);
	Q_INVOKABLE bool hasMipmaps();
	void setMaxS(float var);
	static QScriptValue setDefaultAlphaPixelFormat(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue defaultAlphaPixelFormat(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue PVRImagesHavePremultipliedAlpha(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(bool bHasPremultipliedAlpha READ _public_field_get_bHasPremultipliedAlpha WRITE _public_field_set_bHasPremultipliedAlpha)
	bool _public_field_get_bHasPremultipliedAlpha() const;
	void _public_field_set_bHasPremultipliedAlpha(const bool& value);
	Q_PROPERTY(bool bHasMipmaps READ _public_field_get_bHasMipmaps WRITE _public_field_set_bHasMipmaps)
	bool _public_field_get_bHasMipmaps() const;
	void _public_field_set_bHasMipmaps(const bool& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTexture2D *)
Q_DECLARE_METATYPE(const cocos2d::CCTexture2D *)

namespace cocos2d {
class QtScriptCCNode : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rotation READ getRotation WRITE setRotation)
	Q_PROPERTY(int zOrder READ getZOrder WRITE setZOrder)
	Q_PROPERTY(float scaleY READ getScaleY WRITE setScaleY)
	Q_PROPERTY(float scaleX READ getScaleX WRITE setScaleX)
	Q_PROPERTY(float skewX READ getSkewX WRITE setSkewX)
	Q_PROPERTY(float skewY READ getSkewY WRITE setSkewY)
	Q_PROPERTY(cocos2d::CCPoint position READ getPosition WRITE setPosition)
	Q_PROPERTY(int gLServerState READ getGLServerState WRITE setGLServerState)
	Q_PROPERTY(float positionY READ getPositionY WRITE setPositionY)
	Q_PROPERTY(float positionX READ getPositionX WRITE setPositionX)
	Q_PROPERTY(cocos2d::CCPoint anchorPoint READ getAnchorPoint WRITE setAnchorPoint)
	Q_PROPERTY(cocos2d::CCGLProgram* shaderProgram READ getShaderProgram WRITE setShaderProgram)
	Q_PROPERTY(float vertexZ READ getVertexZ WRITE setVertexZ)
	Q_PROPERTY(cocos2d::CCScheduler* scheduler READ getScheduler WRITE setScheduler)
	Q_PROPERTY(float rotationX READ getRotationX WRITE setRotationX)
	Q_PROPERTY(float rotationY READ getRotationY WRITE setRotationY)
	Q_PROPERTY(cocos2d::CCSize contentSize READ getContentSize WRITE setContentSize)
	Q_PROPERTY(cocos2d::CCActionManager* actionManager READ getActionManager WRITE setActionManager)
	Q_PROPERTY(bool visible READ isVisible WRITE setVisible)
	Q_PROPERTY(float scale READ getScale WRITE setScale)
	Q_PROPERTY(unsigned int orderOfArrival READ getOrderOfArrival WRITE setOrderOfArrival)
	Q_PROPERTY(cocos2d::CCGridBase* grid READ getGrid WRITE setGrid)
	Q_PROPERTY(cocos2d::CCObject* userObject READ getUserObject WRITE setUserObject)
	Q_PROPERTY(int tag READ getTag WRITE setTag)
	Q_INVOKABLE void addChild(cocos2d::CCNode* child);
	Q_INVOKABLE void addChild(cocos2d::CCNode* child, int zOrder);
	Q_INVOKABLE void addChild(cocos2d::CCNode* child, int zOrder, int tag);
	Q_INVOKABLE bool removeComponent(const QByteArray& pName);
	Q_INVOKABLE cocos2d::CCAffineTransform nodeToWorldTransform();
	cocos2d::CCGLProgram* getShaderProgram();
	cocos2d::CCObject* getUserObject();
	Q_INVOKABLE cocos2d::CCArray* getChildren();
	Q_INVOKABLE cocos2d::CCPoint convertToWorldSpaceAR(const cocos2d::CCPoint& nodePoint);
	Q_INVOKABLE bool isIgnoreAnchorPointForPosition();
	Q_INVOKABLE bool init();
	void setRotation(float fRotation);
	void setZOrder(int zOrder);
	void setScaleY(float fScaleY);
	void setScaleX(float fScaleX);
	Q_INVOKABLE void scheduleUpdateWithPriority(int priority);
	Q_INVOKABLE void scheduleUpdateWithPriority(const QScriptValue& arg0, int arg1);
	Q_INVOKABLE void removeAllComponents();
	int getTag();
	Q_INVOKABLE void onExit();
	Q_INVOKABLE void removeChild(cocos2d::CCNode* child);
	Q_INVOKABLE void removeChild(cocos2d::CCNode* child, bool cleanup);
	Q_INVOKABLE cocos2d::CCPoint convertToWorldSpace(const cocos2d::CCPoint& nodePoint);
	void setSkewX(float fSkewX);
	void setSkewY(float fSkewY);
	Q_INVOKABLE void onEnterTransitionDidFinish();
	Q_INVOKABLE cocos2d::CCPoint convertTouchToNodeSpace(cocos2d::CCTouch* touch);
	Q_INVOKABLE void removeAllChildren();
	float getRotationX();
	float getRotationY();
	Q_INVOKABLE QByteArray description();
	Q_INVOKABLE void unscheduleUpdate();
	Q_INVOKABLE cocos2d::CCAffineTransform nodeToParentTransform();
	Q_INVOKABLE void unscheduleAllSelectors();
	Q_INVOKABLE void removeAllChildrenWithCleanup(bool cleanup);
	cocos2d::CCGridBase* getGrid();
	Q_INVOKABLE unsigned int numberOfRunningActions();
	Q_INVOKABLE void removeFromParentAndCleanup(bool cleanup);
	void setPosition(const cocos2d::CCPoint& position);
	Q_INVOKABLE void setPosition(float x, float y);
	Q_INVOKABLE void stopActionByTag(int tag);
	Q_INVOKABLE void reorderChild(cocos2d::CCNode* child, int zOrder);
	void setGLServerState(int glServerState);
	void setPositionY(float y);
	void setPositionX(float x);
	cocos2d::CCPoint getAnchorPoint();
	Q_INVOKABLE void updateTransform();
	Q_INVOKABLE void registerEventHandler(const QScriptValue& arg0);
	bool isVisible();
	Q_INVOKABLE unsigned int getChildrenCount();
	void setAnchorPoint(const cocos2d::CCPoint& anchorPoint);
	Q_INVOKABLE void onEnter();
	Q_INVOKABLE cocos2d::CCPoint convertToNodeSpaceAR(const cocos2d::CCPoint& worldPoint);
	Q_INVOKABLE bool addComponent(cocos2d::CCComponent* pComponent);
	Q_INVOKABLE void unregisterEventHandler();
	Q_INVOKABLE cocos2d::CCAction* runAction(cocos2d::CCAction* action);
	void setShaderProgram(cocos2d::CCGLProgram* pShaderProgram);
	float getRotation();
	Q_INVOKABLE void resumeSchedulerAndActions();
	int getZOrder();
	Q_INVOKABLE cocos2d::CCPoint getAnchorPointInPoints();
	Q_INVOKABLE void visit();
	Q_INVOKABLE void transform();
	void setVertexZ(float vertexZ);
	void setScheduler(cocos2d::CCScheduler* scheduler);
	Q_INVOKABLE void stopAllActions();
	float getSkewX();
	float getSkewY();
	Q_INVOKABLE void ignoreAnchorPointForPosition(bool ignore);
	Q_INVOKABLE cocos2d::CCAction* getActionByTag(int tag);
	void setRotationX(float fRotaionX);
	void setRotationY(float fRotationY);
	Q_INVOKABLE void setAdditionalTransform(const cocos2d::CCAffineTransform& additionalTransform);
	cocos2d::CCScheduler* getScheduler();
	unsigned int getOrderOfArrival();
	Q_INVOKABLE cocos2d::CCRect boundingBox();
	void setContentSize(const cocos2d::CCSize& contentSize);
	void setActionManager(cocos2d::CCActionManager* actionManager);
	cocos2d::CCPoint getPosition();
	Q_INVOKABLE bool isRunning();
	Q_INVOKABLE cocos2d::CCNode* getParent();
	float getPositionY();
	float getPositionX();
	Q_INVOKABLE void removeChildByTag(int tag);
	Q_INVOKABLE void removeChildByTag(int tag, bool cleanup);
	void setVisible(bool visible);
	Q_INVOKABLE void pauseSchedulerAndActions();
	float getVertexZ();
	Q_INVOKABLE void _setZOrder(int z);
	void setScale(float scale);
	Q_INVOKABLE void setScale(float fScaleX, float fScaleY);
	Q_INVOKABLE cocos2d::CCNode* getChildByTag(int tag);
	void setOrderOfArrival(unsigned int uOrderOfArrival);
	float getScaleY();
	float getScaleX();
	Q_INVOKABLE void cleanup();
	Q_INVOKABLE cocos2d::CCComponent* getComponent(const QByteArray& pName);
	cocos2d::CCSize getContentSize();
	void setGrid(cocos2d::CCGridBase* pGrid);
	Q_INVOKABLE void draw();
	Q_INVOKABLE void transformAncestors();
	void setUserObject(cocos2d::CCObject* pUserObject);
	Q_INVOKABLE void removeFromParent();
	Q_INVOKABLE cocos2d::CCPoint convertTouchToNodeSpaceAR(cocos2d::CCTouch* touch);
	Q_INVOKABLE void sortAllChildren();
	Q_INVOKABLE cocos2d::CCPoint convertToNodeSpace(const cocos2d::CCPoint& worldPoint);
	Q_INVOKABLE void onExitTransitionDidStart();
	float getScale();
	Q_INVOKABLE cocos2d::CCAffineTransform worldToNodeTransform();
	Q_INVOKABLE cocos2d::CCAffineTransform parentToNodeTransform();
	Q_INVOKABLE cocos2d::CCCamera* getCamera();
	void setTag(int nTag);
	Q_INVOKABLE void scheduleUpdate();
	int getGLServerState();
	Q_INVOKABLE void stopAction(cocos2d::CCAction* action);
	cocos2d::CCActionManager* getActionManager();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCNode *)
Q_DECLARE_METATYPE(const cocos2d::CCNode *)

namespace cocos2d {
class QtScriptCCNodeRGBA : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCNodeRGBA(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCNodeRGBA(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccColor3B color READ getColor WRITE setColor)
	Q_PROPERTY(bool cascadeColorEnabled READ isCascadeColorEnabled WRITE setCascadeColorEnabled)
	Q_PROPERTY(unsigned char opacity READ getOpacity WRITE setOpacity)
	Q_PROPERTY(bool opacityModifyRGB READ isOpacityModifyRGB WRITE setOpacityModifyRGB)
	Q_PROPERTY(bool cascadeOpacityEnabled READ isCascadeOpacityEnabled WRITE setCascadeOpacityEnabled)
	bool isOpacityModifyRGB();
	void setColor(const cocos2d::_ccColor3B& color);
	bool isCascadeOpacityEnabled();
	cocos2d::_ccColor3B getColor();
	Q_INVOKABLE unsigned char getDisplayedOpacity();
	void setCascadeColorEnabled(bool cascadeColorEnabled);
	void setOpacity(unsigned char opacity);
	void setOpacityModifyRGB(bool bValue);
	void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);
	Q_INVOKABLE void updateDisplayedOpacity(unsigned char parentOpacity);
	bool isCascadeColorEnabled();
	Q_INVOKABLE void updateDisplayedColor(const cocos2d::_ccColor3B& parentColor);
	unsigned char getOpacity();
	Q_INVOKABLE cocos2d::_ccColor3B getDisplayedColor();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCNodeRGBA *)
Q_DECLARE_METATYPE(const cocos2d::CCNodeRGBA *)

namespace cocos2d {
class QtScriptCCSpriteFrame : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCSpriteFrame(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSpriteFrame(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool rotated READ isRotated WRITE setRotated)
	Q_PROPERTY(cocos2d::CCTexture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::CCRect rectInPixels READ getRectInPixels WRITE setRectInPixels)
	Q_PROPERTY(cocos2d::CCPoint offsetInPixels READ getOffsetInPixels WRITE setOffsetInPixels)
	Q_PROPERTY(cocos2d::CCSize originalSize READ getOriginalSize WRITE setOriginalSize)
	Q_PROPERTY(cocos2d::CCSize originalSizeInPixels READ getOriginalSizeInPixels WRITE setOriginalSizeInPixels)
	Q_PROPERTY(cocos2d::CCPoint offset READ getOffset WRITE setOffset)
	Q_PROPERTY(cocos2d::CCRect rect READ getRect WRITE setRect)
	void setRotated(bool bRotated);
	void setTexture(cocos2d::CCTexture2D* pobTexture);
	cocos2d::CCPoint getOffset();
	void setRectInPixels(const cocos2d::CCRect& rectInPixels);
	cocos2d::CCTexture2D* getTexture();
	cocos2d::CCRect getRect();
	void setOffsetInPixels(const cocos2d::CCPoint& offsetInPixels);
	cocos2d::CCRect getRectInPixels();
	void setOriginalSize(const cocos2d::CCSize& sizeInPixels);
	cocos2d::CCSize getOriginalSizeInPixels();
	void setOriginalSizeInPixels(const cocos2d::CCSize& sizeInPixels);
	void setOffset(const cocos2d::CCPoint& offsets);
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* pobTexture, const cocos2d::CCRect& rect);
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* pobTexture, const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCPoint& offset, const cocos2d::CCSize& originalSize);
	bool isRotated();
	Q_INVOKABLE bool initWithTextureFilename(const QByteArray& filename, const cocos2d::CCRect& rect);
	Q_INVOKABLE bool initWithTextureFilename(const QByteArray& filename, const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCPoint& offset, const cocos2d::CCSize& originalSize);
	void setRect(const cocos2d::CCRect& rect);
	cocos2d::CCPoint getOffsetInPixels();
	cocos2d::CCSize getOriginalSize();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSpriteFrame *)
Q_DECLARE_METATYPE(const cocos2d::CCSpriteFrame *)

namespace cocos2d {
class QtScriptCCString : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCString(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCString(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE unsigned int uintValue();
	Q_INVOKABLE int compare(const QByteArray& arg0);
	Q_INVOKABLE QByteArray getCString();
	Q_INVOKABLE float floatValue();
	Q_INVOKABLE int intValue();
	Q_INVOKABLE double doubleValue();
	Q_INVOKABLE bool boolValue();
	Q_INVOKABLE unsigned int length();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithContentsOfFile(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithData(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(QByteArray sString READ _public_field_get_sString WRITE _public_field_set_sString)
	QByteArray _public_field_get_sString() const;
	void _public_field_set_sString(const QByteArray& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCString *)
Q_DECLARE_METATYPE(const cocos2d::CCString *)

namespace cocos2d {
class QtScriptCCDictionary : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCDictionary(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDictionary(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE unsigned int count();
	Q_INVOKABLE void setObject(cocos2d::CCObject* pObject, const QByteArray& key);
	Q_INVOKABLE void setObjectWithId(cocos2d::CCObject* pObject, intptr_t key);
	Q_INVOKABLE cocos2d::CCObject* objectWithId(intptr_t key);
	Q_INVOKABLE const cocos2d::CCString* valueWithId(intptr_t key);
	Q_INVOKABLE void removeObjectWithId(intptr_t key);
	Q_INVOKABLE cocos2d::CCObject* objectForKey(const QByteArray& key);
	Q_INVOKABLE cocos2d::CCObject* randomObject();
	Q_INVOKABLE void removeAllObjects();
	Q_INVOKABLE void removeObjectsForKeys(cocos2d::CCArray* pKeyArray);
	Q_INVOKABLE void removeObjectForKey(const QByteArray& key);
	Q_INVOKABLE const cocos2d::CCString* valueForKey(const QByteArray& key);
	Q_INVOKABLE bool writeToFile(const QByteArray& fullPath);
	Q_INVOKABLE void removeObjectForElememt(cocos2d::CCDictElement* pElement);
	Q_INVOKABLE cocos2d::CCArray* allKeys();
	Q_INVOKABLE cocos2d::CCArray* allKeysForObject(cocos2d::CCObject* object);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithContentsOfFile(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithDictionary(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(cocos2d::CCDictElement* pElements READ _public_field_get_pElements WRITE _public_field_set_pElements)
	cocos2d::CCDictElement* _public_field_get_pElements() const;
	void _public_field_set_pElements(cocos2d::CCDictElement* value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCDictionary *)
Q_DECLARE_METATYPE(const cocos2d::CCDictionary *)

namespace cocos2d {
class QtScriptCCAnimationFrame : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCAnimationFrame(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAnimationFrame(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCSpriteFrame* spriteFrame READ getSpriteFrame WRITE setSpriteFrame)
	Q_PROPERTY(float delayUnits READ getDelayUnits WRITE setDelayUnits)
	Q_PROPERTY(cocos2d::CCDictionary* userInfo READ getUserInfo WRITE setUserInfo)
	void setSpriteFrame(cocos2d::CCSpriteFrame* var);
	cocos2d::CCDictionary* getUserInfo();
	void setDelayUnits(float var);
	cocos2d::CCSpriteFrame* getSpriteFrame();
	float getDelayUnits();
	void setUserInfo(cocos2d::CCDictionary* var);
	Q_INVOKABLE bool initWithSpriteFrame(cocos2d::CCSpriteFrame* spriteFrame, float delayUnits, cocos2d::CCDictionary* userInfo);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAnimationFrame *)
Q_DECLARE_METATYPE(const cocos2d::CCAnimationFrame *)

namespace cocos2d {
class QtScriptCCAnimation : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCAnimation(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAnimation(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCArray* frames READ getFrames WRITE setFrames)
	Q_PROPERTY(unsigned int loops READ getLoops WRITE setLoops)
	Q_PROPERTY(float delayPerUnit READ getDelayPerUnit WRITE setDelayPerUnit)
	Q_PROPERTY(bool restoreOriginalFrame READ getRestoreOriginalFrame WRITE setRestoreOriginalFrame)
	Q_INVOKABLE void addSpriteFrameWithFileName(const QByteArray& pszFileName);
	void setFrames(cocos2d::CCArray* var);
	unsigned int getLoops();
	cocos2d::CCArray* getFrames();
	Q_INVOKABLE void addSpriteFrame(cocos2d::CCSpriteFrame* pFrame);
	Q_INVOKABLE float getDuration();
	Q_INVOKABLE bool initWithAnimationFrames(cocos2d::CCArray* arrayOfAnimationFrames, float delayPerUnit, unsigned int loops);
	Q_INVOKABLE bool init();
	Q_INVOKABLE bool initWithSpriteFrames(cocos2d::CCArray* pFrames);
	Q_INVOKABLE bool initWithSpriteFrames(cocos2d::CCArray* pFrames, float delay);
	void setLoops(unsigned int var);
	void setDelayPerUnit(float var);
	void setRestoreOriginalFrame(bool var);
	Q_INVOKABLE float getTotalDelayUnits();
	float getDelayPerUnit();
	bool getRestoreOriginalFrame();
	Q_INVOKABLE void addSpriteFrameWithTexture(cocos2d::CCTexture2D* pobTexture, const cocos2d::CCRect& rect);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithSpriteFrames(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAnimation *)
Q_DECLARE_METATYPE(const cocos2d::CCAnimation *)

namespace cocos2d {
class QtScriptCCActionInterval : public QtScriptCCFiniteTimeAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCActionInterval(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCActionInterval(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	void setAmplitudeRate(float amp);
	float getAmplitudeRate();
	Q_INVOKABLE bool initWithDuration(float d);
	Q_INVOKABLE float getElapsed();
	Q_INVOKABLE cocos2d::CCActionInterval* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCActionInterval *)
Q_DECLARE_METATYPE(const cocos2d::CCActionInterval *)

namespace cocos2d {
class QtScriptCCSequence : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCSequence(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSequence(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithTwoActions(cocos2d::CCFiniteTimeAction* pActionOne, cocos2d::CCFiniteTimeAction* pActionTwo);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTwoActions(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSequence *)
Q_DECLARE_METATYPE(const cocos2d::CCSequence *)

namespace cocos2d {
class QtScriptCCRepeat : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCRepeat(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCRepeat(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCFiniteTimeAction* innerAction READ getInnerAction WRITE setInnerAction)
	void setInnerAction(cocos2d::CCFiniteTimeAction* pAction);
	Q_INVOKABLE bool initWithAction(cocos2d::CCFiniteTimeAction* pAction, unsigned int times);
	cocos2d::CCFiniteTimeAction* getInnerAction();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCRepeat *)
Q_DECLARE_METATYPE(const cocos2d::CCRepeat *)

namespace cocos2d {
class QtScriptCCRepeatForever : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCRepeatForever(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCRepeatForever(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCActionInterval* innerAction READ getInnerAction WRITE setInnerAction)
	void setInnerAction(cocos2d::CCActionInterval* pAction);
	Q_INVOKABLE bool initWithAction(cocos2d::CCActionInterval* pAction);
	cocos2d::CCActionInterval* getInnerAction();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCRepeatForever *)
Q_DECLARE_METATYPE(const cocos2d::CCRepeatForever *)

namespace cocos2d {
class QtScriptCCSpawn : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCSpawn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSpawn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithTwoActions(cocos2d::CCFiniteTimeAction* pAction1, cocos2d::CCFiniteTimeAction* pAction2);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTwoActions(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSpawn *)
Q_DECLARE_METATYPE(const cocos2d::CCSpawn *)

namespace cocos2d {
class QtScriptCCRotateTo : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCRotateTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCRotateTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float fDuration, float fDeltaAngle);
	Q_INVOKABLE bool initWithDuration(float fDuration, float fDeltaAngleX, float fDeltaAngleY);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCRotateTo *)
Q_DECLARE_METATYPE(const cocos2d::CCRotateTo *)

namespace cocos2d {
class QtScriptCCRotateBy : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCRotateBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCRotateBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float fDuration, float fDeltaAngle);
	Q_INVOKABLE bool initWithDuration(float fDuration, float fDeltaAngleX, float fDeltaAngleY);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCRotateBy *)
Q_DECLARE_METATYPE(const cocos2d::CCRotateBy *)

namespace cocos2d {
class QtScriptCCMoveBy : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCMoveBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMoveBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCPoint& deltaPosition);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMoveBy *)
Q_DECLARE_METATYPE(const cocos2d::CCMoveBy *)

namespace cocos2d {
class QtScriptCCMoveTo : public QtScriptCCMoveBy
{
	Q_OBJECT

protected:
	explicit QtScriptCCMoveTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMoveTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCPoint& position);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMoveTo *)
Q_DECLARE_METATYPE(const cocos2d::CCMoveTo *)

namespace cocos2d {
class QtScriptCCSkewTo : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCSkewTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSkewTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float t, float sx, float sy);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSkewTo *)
Q_DECLARE_METATYPE(const cocos2d::CCSkewTo *)

namespace cocos2d {
class QtScriptCCSkewBy : public QtScriptCCSkewTo
{
	Q_OBJECT

protected:
	explicit QtScriptCCSkewBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSkewBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSkewBy *)
Q_DECLARE_METATYPE(const cocos2d::CCSkewBy *)

namespace cocos2d {
class QtScriptCCJumpBy : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCJumpBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCJumpBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCPoint& position, float height, unsigned int jumps);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCJumpBy *)
Q_DECLARE_METATYPE(const cocos2d::CCJumpBy *)

namespace cocos2d {
class QtScriptCCJumpTo : public QtScriptCCJumpBy
{
	Q_OBJECT

protected:
	explicit QtScriptCCJumpTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCJumpTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCJumpTo *)
Q_DECLARE_METATYPE(const cocos2d::CCJumpTo *)

namespace cocos2d {
class QtScript_ccBezierConfig final : public QtScriptBaseClassPrototype<_ccBezierConfig, false>
{
	Q_OBJECT

protected:
	explicit QtScript_ccBezierConfig(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScript_ccBezierConfig(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCPoint endPosition READ _public_field_get_endPosition WRITE _public_field_set_endPosition)
	cocos2d::CCPoint _public_field_get_endPosition() const;
	void _public_field_set_endPosition(const cocos2d::CCPoint& value);
	Q_PROPERTY(cocos2d::CCPoint controlPoint_1 READ _public_field_get_controlPoint_1 WRITE _public_field_set_controlPoint_1)
	cocos2d::CCPoint _public_field_get_controlPoint_1() const;
	void _public_field_set_controlPoint_1(const cocos2d::CCPoint& value);
	Q_PROPERTY(cocos2d::CCPoint controlPoint_2 READ _public_field_get_controlPoint_2 WRITE _public_field_set_controlPoint_2)
	cocos2d::CCPoint _public_field_get_controlPoint_2() const;
	void _public_field_set_controlPoint_2(const cocos2d::CCPoint& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccBezierConfig)
Q_DECLARE_METATYPE(cocos2d::_ccBezierConfig *)
Q_DECLARE_METATYPE(const cocos2d::_ccBezierConfig *)

namespace cocos2d {
class QtScriptCCBezierBy : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCBezierBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCBezierBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float t, const cocos2d::_ccBezierConfig& c);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCBezierBy *)
Q_DECLARE_METATYPE(const cocos2d::CCBezierBy *)

namespace cocos2d {
class QtScriptCCBezierTo : public QtScriptCCBezierBy
{
	Q_OBJECT

protected:
	explicit QtScriptCCBezierTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCBezierTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float t, const cocos2d::_ccBezierConfig& c);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCBezierTo *)
Q_DECLARE_METATYPE(const cocos2d::CCBezierTo *)

namespace cocos2d {
class QtScriptCCScaleTo : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCScaleTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCScaleTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, float s);
	Q_INVOKABLE bool initWithDuration(float duration, float sx, float sy);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCScaleTo *)
Q_DECLARE_METATYPE(const cocos2d::CCScaleTo *)

namespace cocos2d {
class QtScriptCCScaleBy : public QtScriptCCScaleTo
{
	Q_OBJECT

protected:
	explicit QtScriptCCScaleBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCScaleBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCScaleBy *)
Q_DECLARE_METATYPE(const cocos2d::CCScaleBy *)

namespace cocos2d {
class QtScriptCCBlink : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCBlink(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCBlink(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, unsigned int uBlinks);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCBlink *)
Q_DECLARE_METATYPE(const cocos2d::CCBlink *)

namespace cocos2d {
class QtScriptCCFadeIn : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCFadeIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFadeIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFadeIn *)
Q_DECLARE_METATYPE(const cocos2d::CCFadeIn *)

namespace cocos2d {
class QtScriptCCFadeOut : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCFadeOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFadeOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFadeOut *)
Q_DECLARE_METATYPE(const cocos2d::CCFadeOut *)

namespace cocos2d {
class QtScriptCCFadeTo : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCFadeTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFadeTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, unsigned char opacity);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFadeTo *)
Q_DECLARE_METATYPE(const cocos2d::CCFadeTo *)

namespace cocos2d {
class QtScriptCCTintTo : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCTintTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTintTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, unsigned char red, unsigned char green, unsigned char blue);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTintTo *)
Q_DECLARE_METATYPE(const cocos2d::CCTintTo *)

namespace cocos2d {
class QtScriptCCTintBy : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCTintBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTintBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, short deltaRed, short deltaGreen, short deltaBlue);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTintBy *)
Q_DECLARE_METATYPE(const cocos2d::CCTintBy *)

namespace cocos2d {
class QtScriptCCDelayTime : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCDelayTime(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDelayTime(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCDelayTime *)
Q_DECLARE_METATYPE(const cocos2d::CCDelayTime *)

namespace cocos2d {
class QtScriptCCReverseTime : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCReverseTime(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCReverseTime(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithAction(cocos2d::CCFiniteTimeAction* pAction);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCReverseTime *)
Q_DECLARE_METATYPE(const cocos2d::CCReverseTime *)

namespace cocos2d {
class QtScriptCCAnimate : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCAnimate(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAnimate(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCAnimation* animation READ getAnimation WRITE setAnimation)
	cocos2d::CCAnimation* getAnimation();
	Q_INVOKABLE bool initWithAnimation(cocos2d::CCAnimation* pAnimation);
	void setAnimation(cocos2d::CCAnimation* var);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAnimate *)
Q_DECLARE_METATYPE(const cocos2d::CCAnimate *)

namespace cocos2d {
class QtScriptCCTargetedAction : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCTargetedAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTargetedAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCNode* forcedTarget READ getForcedTarget WRITE setForcedTarget)
	cocos2d::CCNode* getForcedTarget();
	Q_INVOKABLE bool initWithTarget(cocos2d::CCNode* pTarget, cocos2d::CCFiniteTimeAction* pAction);
	void setForcedTarget(cocos2d::CCNode* var);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTargetedAction *)
Q_DECLARE_METATYPE(const cocos2d::CCTargetedAction *)

namespace cocos2d {
class QtScriptCCActionCamera : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCActionCamera(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCActionCamera(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCActionCamera *)
Q_DECLARE_METATYPE(const cocos2d::CCActionCamera *)

namespace cocos2d {
class QtScriptCCOrbitCamera : public QtScriptCCActionCamera
{
	Q_OBJECT

protected:
	explicit QtScriptCCOrbitCamera(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCOrbitCamera(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCOrbitCamera *)
Q_DECLARE_METATYPE(const cocos2d::CCOrbitCamera *)

namespace cocos2d {
class QtScriptCCActionManager : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCActionManager(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCActionManager(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCAction* getActionByTag(unsigned int tag, cocos2d::CCObject* pTarget);
	Q_INVOKABLE void addAction(cocos2d::CCAction* pAction, cocos2d::CCNode* pTarget, bool paused);
	Q_INVOKABLE void removeAllActions();
	Q_INVOKABLE void removeActionByTag(unsigned int tag, cocos2d::CCObject* pTarget);
	Q_INVOKABLE void resumeTarget(cocos2d::CCObject* pTarget);
	Q_INVOKABLE void pauseTarget(cocos2d::CCObject* pTarget);
	Q_INVOKABLE void removeAllActionsFromTarget(cocos2d::CCObject* pTarget);
	Q_INVOKABLE void resumeTargets(cocos2d::CCSet* targetsToResume);
	Q_INVOKABLE void removeAction(cocos2d::CCAction* pAction);
	Q_INVOKABLE unsigned int numberOfRunningActionsInTarget(cocos2d::CCObject* pTarget);
	Q_INVOKABLE cocos2d::CCSet* pauseAllRunningActions();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCActionManager *)
Q_DECLARE_METATYPE(const cocos2d::CCActionManager *)

namespace cocos2d {
class QtScriptCCActionEase : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCActionEase(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCActionEase(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithAction(cocos2d::CCActionInterval* pAction);
	Q_INVOKABLE cocos2d::CCActionInterval* getInnerAction();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCActionEase *)
Q_DECLARE_METATYPE(const cocos2d::CCActionEase *)

namespace cocos2d {
class QtScriptCCEaseRateAction : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseRateAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseRateAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rate READ getRate WRITE setRate)
	void setRate(float rate);
	Q_INVOKABLE bool initWithAction(cocos2d::CCActionInterval* pAction, float fRate);
	float getRate();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseRateAction *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseRateAction *)

namespace cocos2d {
class QtScriptCCEaseIn : public QtScriptCCEaseRateAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseIn *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseIn *)

namespace cocos2d {
class QtScriptCCEaseOut : public QtScriptCCEaseRateAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseOut *)

namespace cocos2d {
class QtScriptCCEaseInOut : public QtScriptCCEaseRateAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseInOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseInOut *)

namespace cocos2d {
class QtScriptCCEaseExponentialIn : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseExponentialIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseExponentialIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseExponentialIn *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseExponentialIn *)

namespace cocos2d {
class QtScriptCCEaseExponentialOut : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseExponentialOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseExponentialOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseExponentialOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseExponentialOut *)

namespace cocos2d {
class QtScriptCCEaseExponentialInOut : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseExponentialInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseExponentialInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseExponentialInOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseExponentialInOut *)

namespace cocos2d {
class QtScriptCCEaseSineIn : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseSineIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseSineIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseSineIn *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseSineIn *)

namespace cocos2d {
class QtScriptCCEaseSineOut : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseSineOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseSineOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseSineOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseSineOut *)

namespace cocos2d {
class QtScriptCCEaseSineInOut : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseSineInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseSineInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseSineInOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseSineInOut *)

namespace cocos2d {
class QtScriptCCEaseElastic : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseElastic(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseElastic(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float period READ getPeriod WRITE setPeriod)
	void setPeriod(float fPeriod);
	Q_INVOKABLE bool initWithAction(cocos2d::CCActionInterval* pAction);
	Q_INVOKABLE bool initWithAction(cocos2d::CCActionInterval* pAction, float fPeriod);
	float getPeriod();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseElastic *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseElastic *)

namespace cocos2d {
class QtScriptCCEaseElasticIn : public QtScriptCCEaseElastic
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseElasticIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseElasticIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseElasticIn *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseElasticIn *)

namespace cocos2d {
class QtScriptCCEaseElasticOut : public QtScriptCCEaseElastic
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseElasticOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseElasticOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseElasticOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseElasticOut *)

namespace cocos2d {
class QtScriptCCEaseElasticInOut : public QtScriptCCEaseElastic
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseElasticInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseElasticInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseElasticInOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseElasticInOut *)

namespace cocos2d {
class QtScriptCCEaseBounce : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseBounce(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseBounce(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE float bounceTime(float time);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseBounce *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseBounce *)

namespace cocos2d {
class QtScriptCCEaseBounceIn : public QtScriptCCEaseBounce
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseBounceIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseBounceIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseBounceIn *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseBounceIn *)

namespace cocos2d {
class QtScriptCCEaseBounceOut : public QtScriptCCEaseBounce
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseBounceOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseBounceOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseBounceOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseBounceOut *)

namespace cocos2d {
class QtScriptCCEaseBounceInOut : public QtScriptCCEaseBounce
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseBounceInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseBounceInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseBounceInOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseBounceInOut *)

namespace cocos2d {
class QtScriptCCEaseBackIn : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseBackIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseBackIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseBackIn *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseBackIn *)

namespace cocos2d {
class QtScriptCCEaseBackOut : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseBackOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseBackOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseBackOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseBackOut *)

namespace cocos2d {
class QtScriptCCEaseBackInOut : public QtScriptCCActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptCCEaseBackInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEaseBackInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEaseBackInOut *)
Q_DECLARE_METATYPE(const cocos2d::CCEaseBackInOut *)

namespace cocos2d {
class QtScriptTypeInfo : public QtScriptBaseClassPrototype<TypeInfo *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptTypeInfo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTypeInfo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptTypeInfo::StorageType)
Q_DECLARE_METATYPE(cocos2d::TypeInfo *)
Q_DECLARE_METATYPE(const cocos2d::TypeInfo *)

namespace cocos2d {
class QtScriptCCActionInstant : public QtScriptCCFiniteTimeAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCActionInstant(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCActionInstant(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCActionInstant *)
Q_DECLARE_METATYPE(const cocos2d::CCActionInstant *)

namespace cocos2d {
class QtScriptCCShow : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCShow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCShow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCShow *)
Q_DECLARE_METATYPE(const cocos2d::CCShow *)

namespace cocos2d {
class QtScriptCCHide : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCHide(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCHide(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCHide *)
Q_DECLARE_METATYPE(const cocos2d::CCHide *)

namespace cocos2d {
class QtScriptCCToggleVisibility : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCToggleVisibility(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCToggleVisibility(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCToggleVisibility *)
Q_DECLARE_METATYPE(const cocos2d::CCToggleVisibility *)

namespace cocos2d {
class QtScriptCCRemoveSelf : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCRemoveSelf(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCRemoveSelf(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool init(bool isNeedCleanUp);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCRemoveSelf *)
Q_DECLARE_METATYPE(const cocos2d::CCRemoveSelf *)

namespace cocos2d {
class QtScriptCCFlipX : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCFlipX(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFlipX(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithFlipX(bool x);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFlipX *)
Q_DECLARE_METATYPE(const cocos2d::CCFlipX *)

namespace cocos2d {
class QtScriptCCFlipY : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCFlipY(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFlipY(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithFlipY(bool y);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFlipY *)
Q_DECLARE_METATYPE(const cocos2d::CCFlipY *)

namespace cocos2d {
class QtScriptCCPlace : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCPlace(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCPlace(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithPosition(const cocos2d::CCPoint& pos);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCPlace *)
Q_DECLARE_METATYPE(const cocos2d::CCPlace *)

namespace cocos2d {
class QtScriptCCCallFunc : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCCallFunc(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCallFunc(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCObject* targetCallback READ getTargetCallback WRITE setTargetCallback)
	Q_INVOKABLE void execute();
	Q_INVOKABLE bool initWithTarget(cocos2d::CCObject* pSelectorTarget);
	cocos2d::CCObject* getTargetCallback();
	Q_INVOKABLE void setHandler(const QScriptValue& arg0);
	void setTargetCallback(cocos2d::CCObject* pSel);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCallFunc *)
Q_DECLARE_METATYPE(const cocos2d::CCCallFunc *)

namespace cocos2d {
class QtScriptCCCallFuncN : public QtScriptCCCallFunc
{
	Q_OBJECT

protected:
	explicit QtScriptCCCallFuncN(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCallFuncN(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE long getClassTypeInfo();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCallFuncN *)
Q_DECLARE_METATYPE(const cocos2d::CCCallFuncN *)

namespace cocos2d {
class QtScriptCCCallFuncND : public QtScriptCCCallFuncN
{
	Q_OBJECT

protected:
	explicit QtScriptCCCallFuncND(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCallFuncND(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCallFuncND *)
Q_DECLARE_METATYPE(const cocos2d::CCCallFuncND *)

namespace cocos2d {
class QtScriptCCCallFuncO : public QtScriptCCCallFunc
{
	Q_OBJECT

protected:
	explicit QtScriptCCCallFuncO(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCallFuncO(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCObject* object READ getObject WRITE setObject)
	Q_INVOKABLE long getClassTypeInfo();
	cocos2d::CCObject* getObject();
	void setObject(cocos2d::CCObject* pObj);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCallFuncO *)
Q_DECLARE_METATYPE(const cocos2d::CCCallFuncO *)

namespace cocos2d {
class QtScriptCCGridAction : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCGridAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCGridAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCGridBase* getGrid();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCGridAction *)
Q_DECLARE_METATYPE(const cocos2d::CCGridAction *)

namespace cocos2d {
class QtScriptCCGrid3DAction : public QtScriptCCGridAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCGrid3DAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCGrid3DAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setVertex(const cocos2d::CCPoint& position, const cocos2d::_ccVertex3F& vertex);
	Q_INVOKABLE cocos2d::_ccVertex3F vertex(const cocos2d::CCPoint& position);
	Q_INVOKABLE cocos2d::_ccVertex3F originalVertex(const cocos2d::CCPoint& position);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCGrid3DAction *)
Q_DECLARE_METATYPE(const cocos2d::CCGrid3DAction *)

namespace cocos2d {
class QtScriptCCTiledGrid3DAction : public QtScriptCCGridAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCTiledGrid3DAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTiledGrid3DAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::_ccQuad3 tile(const cocos2d::CCPoint& position);
	Q_INVOKABLE void setTile(const cocos2d::CCPoint& position, const cocos2d::_ccQuad3& coords);
	Q_INVOKABLE cocos2d::_ccQuad3 originalTile(const cocos2d::CCPoint& position);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTiledGrid3DAction *)
Q_DECLARE_METATYPE(const cocos2d::CCTiledGrid3DAction *)

namespace cocos2d {
class QtScriptCCAccelDeccelAmplitude : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCAccelDeccelAmplitude(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAccelDeccelAmplitude(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rate READ getRate WRITE setRate)
	void setRate(float fRate);
	Q_INVOKABLE bool initWithAction(cocos2d::CCAction* pAction, float duration);
	float getRate();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAccelDeccelAmplitude *)
Q_DECLARE_METATYPE(const cocos2d::CCAccelDeccelAmplitude *)

namespace cocos2d {
class QtScriptCCAccelAmplitude : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCAccelAmplitude(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAccelAmplitude(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rate READ getRate WRITE setRate)
	void setRate(float fRate);
	Q_INVOKABLE bool initWithAction(cocos2d::CCAction* pAction, float duration);
	float getRate();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAccelAmplitude *)
Q_DECLARE_METATYPE(const cocos2d::CCAccelAmplitude *)

namespace cocos2d {
class QtScriptCCDeccelAmplitude : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCDeccelAmplitude(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDeccelAmplitude(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rate READ getRate WRITE setRate)
	void setRate(float fRate);
	Q_INVOKABLE bool initWithAction(cocos2d::CCAction* pAction, float duration);
	float getRate();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCDeccelAmplitude *)
Q_DECLARE_METATYPE(const cocos2d::CCDeccelAmplitude *)

namespace cocos2d {
class QtScriptCCStopGrid : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCStopGrid(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCStopGrid(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCStopGrid *)
Q_DECLARE_METATYPE(const cocos2d::CCStopGrid *)

namespace cocos2d {
class QtScriptCCReuseGrid : public QtScriptCCActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCCReuseGrid(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCReuseGrid(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithTimes(int times);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCReuseGrid *)
Q_DECLARE_METATYPE(const cocos2d::CCReuseGrid *)

namespace cocos2d {
class QtScriptCCWaves3D : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCWaves3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCWaves3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	float getAmplitudeRate();
	void setAmplitude(float fAmplitude);
	void setAmplitudeRate(float fAmplitudeRate);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int waves, float amplitude);
	float getAmplitude();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCWaves3D *)
Q_DECLARE_METATYPE(const cocos2d::CCWaves3D *)

namespace cocos2d {
class QtScriptCCFlipX3D : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCFlipX3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFlipX3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithSize(const cocos2d::CCSize& gridSize, float duration);
	Q_INVOKABLE bool initWithDuration(float duration);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFlipX3D *)
Q_DECLARE_METATYPE(const cocos2d::CCFlipX3D *)

namespace cocos2d {
class QtScriptCCFlipY3D : public QtScriptCCFlipX3D
{
	Q_OBJECT

protected:
	explicit QtScriptCCFlipY3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFlipY3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFlipY3D *)
Q_DECLARE_METATYPE(const cocos2d::CCFlipY3D *)

namespace cocos2d {
class QtScriptCCLens3D : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCLens3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLens3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float lensEffect READ getLensEffect WRITE setLensEffect)
	Q_PROPERTY(cocos2d::CCPoint position READ getPosition WRITE setPosition)
	Q_INVOKABLE void setConcave(bool bConcave);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, const cocos2d::CCPoint& position, float radius);
	void setLensEffect(float fLensEffect);
	float getLensEffect();
	void setPosition(const cocos2d::CCPoint& position);
	cocos2d::CCPoint getPosition();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLens3D *)
Q_DECLARE_METATYPE(const cocos2d::CCLens3D *)

namespace cocos2d {
class QtScriptCCRipple3D : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCRipple3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCRipple3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(cocos2d::CCPoint position READ getPosition WRITE setPosition)
	void setAmplitudeRate(float fAmplitudeRate);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, const cocos2d::CCPoint& position, float radius, unsigned int waves, float amplitude);
	float getAmplitudeRate();
	void setAmplitude(float fAmplitude);
	float getAmplitude();
	void setPosition(const cocos2d::CCPoint& position);
	cocos2d::CCPoint getPosition();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCRipple3D *)
Q_DECLARE_METATYPE(const cocos2d::CCRipple3D *)

namespace cocos2d {
class QtScriptCCShaky3D : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCShaky3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCShaky3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, int range, bool shakeZ);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCShaky3D *)
Q_DECLARE_METATYPE(const cocos2d::CCShaky3D *)

namespace cocos2d {
class QtScriptCCLiquid : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCLiquid(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLiquid(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	float getAmplitudeRate();
	void setAmplitude(float fAmplitude);
	void setAmplitudeRate(float fAmplitudeRate);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int waves, float amplitude);
	float getAmplitude();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLiquid *)
Q_DECLARE_METATYPE(const cocos2d::CCLiquid *)

namespace cocos2d {
class QtScriptCCWaves : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCWaves(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCWaves(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	float getAmplitudeRate();
	void setAmplitude(float fAmplitude);
	void setAmplitudeRate(float fAmplitudeRate);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical);
	float getAmplitude();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCWaves *)
Q_DECLARE_METATYPE(const cocos2d::CCWaves *)

namespace cocos2d {
class QtScriptCCTwirl : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCTwirl(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTwirl(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(cocos2d::CCPoint position READ getPosition WRITE setPosition)
	void setAmplitudeRate(float fAmplitudeRate);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, cocos2d::CCPoint position, unsigned int twirls, float amplitude);
	float getAmplitudeRate();
	void setAmplitude(float fAmplitude);
	float getAmplitude();
	void setPosition(const cocos2d::CCPoint& position);
	cocos2d::CCPoint getPosition();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTwirl *)
Q_DECLARE_METATYPE(const cocos2d::CCTwirl *)

namespace cocos2d {
class QtScriptCCPageTurn3D : public QtScriptCCGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCPageTurn3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCPageTurn3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCPageTurn3D *)
Q_DECLARE_METATYPE(const cocos2d::CCPageTurn3D *)

namespace cocos2d {
class QtScriptCCProgressTo : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCProgressTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCProgressTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, float fPercent);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCProgressTo *)
Q_DECLARE_METATYPE(const cocos2d::CCProgressTo *)

namespace cocos2d {
class QtScriptCCProgressFromTo : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCProgressFromTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCProgressFromTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, float fFromPercentage, float fToPercentage);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCProgressFromTo *)
Q_DECLARE_METATYPE(const cocos2d::CCProgressFromTo *)

namespace cocos2d {
class QtScriptCCShakyTiles3D : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCShakyTiles3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCShakyTiles3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, int nRange, bool bShakeZ);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCShakyTiles3D *)
Q_DECLARE_METATYPE(const cocos2d::CCShakyTiles3D *)

namespace cocos2d {
class QtScriptCCShatteredTiles3D : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCShatteredTiles3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCShatteredTiles3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, int nRange, bool bShatterZ);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCShatteredTiles3D *)
Q_DECLARE_METATYPE(const cocos2d::CCShatteredTiles3D *)

namespace cocos2d {
class QtScriptCCShuffleTiles : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCShuffleTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCShuffleTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void placeTile(const cocos2d::CCPoint& pos, const cocos2d::Tile& t);
	Q_INVOKABLE cocos2d::CCSize getDelta(const cocos2d::CCSize& pos);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int seed);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCShuffleTiles *)
Q_DECLARE_METATYPE(const cocos2d::CCShuffleTiles *)

namespace cocos2d {
class QtScriptCCFadeOutTRTiles : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCFadeOutTRTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFadeOutTRTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void turnOnTile(const cocos2d::CCPoint& pos);
	Q_INVOKABLE void turnOffTile(const cocos2d::CCPoint& pos);
	Q_INVOKABLE void transformTile(const cocos2d::CCPoint& pos, float distance);
	Q_INVOKABLE float testFunc(const cocos2d::CCSize& pos, float time);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFadeOutTRTiles *)
Q_DECLARE_METATYPE(const cocos2d::CCFadeOutTRTiles *)

namespace cocos2d {
class QtScriptCCFadeOutBLTiles : public QtScriptCCFadeOutTRTiles
{
	Q_OBJECT

protected:
	explicit QtScriptCCFadeOutBLTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFadeOutBLTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFadeOutBLTiles *)
Q_DECLARE_METATYPE(const cocos2d::CCFadeOutBLTiles *)

namespace cocos2d {
class QtScriptCCFadeOutUpTiles : public QtScriptCCFadeOutTRTiles
{
	Q_OBJECT

protected:
	explicit QtScriptCCFadeOutUpTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFadeOutUpTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFadeOutUpTiles *)
Q_DECLARE_METATYPE(const cocos2d::CCFadeOutUpTiles *)

namespace cocos2d {
class QtScriptCCFadeOutDownTiles : public QtScriptCCFadeOutUpTiles
{
	Q_OBJECT

protected:
	explicit QtScriptCCFadeOutDownTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFadeOutDownTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFadeOutDownTiles *)
Q_DECLARE_METATYPE(const cocos2d::CCFadeOutDownTiles *)

namespace cocos2d {
class QtScriptCCTurnOffTiles : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCTurnOffTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTurnOffTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void turnOnTile(const cocos2d::CCPoint& pos);
	Q_INVOKABLE void turnOffTile(const cocos2d::CCPoint& pos);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int seed);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTurnOffTiles *)
Q_DECLARE_METATYPE(const cocos2d::CCTurnOffTiles *)

namespace cocos2d {
class QtScriptCCWavesTiles3D : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCWavesTiles3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCWavesTiles3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	float getAmplitudeRate();
	void setAmplitude(float fAmplitude);
	void setAmplitudeRate(float fAmplitudeRate);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int waves, float amplitude);
	float getAmplitude();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCWavesTiles3D *)
Q_DECLARE_METATYPE(const cocos2d::CCWavesTiles3D *)

namespace cocos2d {
class QtScriptCCJumpTiles3D : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCJumpTiles3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCJumpTiles3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	float getAmplitudeRate();
	void setAmplitude(float fAmplitude);
	void setAmplitudeRate(float fAmplitudeRate);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::CCSize& gridSize, unsigned int numberOfJumps, float amplitude);
	float getAmplitude();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCJumpTiles3D *)
Q_DECLARE_METATYPE(const cocos2d::CCJumpTiles3D *)

namespace cocos2d {
class QtScriptCCSplitRows : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCSplitRows(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSplitRows(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, unsigned int nRows);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSplitRows *)
Q_DECLARE_METATYPE(const cocos2d::CCSplitRows *)

namespace cocos2d {
class QtScriptCCSplitCols : public QtScriptCCTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptCCSplitCols(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSplitCols(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float duration, unsigned int nCols);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSplitCols *)
Q_DECLARE_METATYPE(const cocos2d::CCSplitCols *)

namespace cocos2d {
class QtScriptCCActionTweenDelegate : public QtScriptBaseClassPrototype<CCActionTweenDelegate *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCActionTweenDelegate(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCActionTweenDelegate(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCActionTweenDelegate::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCActionTweenDelegate *)
Q_DECLARE_METATYPE(const cocos2d::CCActionTweenDelegate *)

namespace cocos2d {
class QtScriptCCActionTween : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCActionTween(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCActionTween(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float aDuration, const QByteArray& key, float from, float to);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(QByteArray strKey READ _public_field_get_strKey WRITE _public_field_set_strKey)
	QByteArray _public_field_get_strKey() const;
	void _public_field_set_strKey(const QByteArray& value);
	Q_PROPERTY(float fFrom READ _public_field_get_fFrom WRITE _public_field_set_fFrom)
	float _public_field_get_fFrom() const;
	void _public_field_set_fFrom(float value);
	Q_PROPERTY(float fTo READ _public_field_get_fTo WRITE _public_field_set_fTo)
	float _public_field_get_fTo() const;
	void _public_field_set_fTo(float value);
	Q_PROPERTY(float fDelta READ _public_field_get_fDelta WRITE _public_field_set_fDelta)
	float _public_field_get_fDelta() const;
	void _public_field_set_fDelta(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCActionTween *)
Q_DECLARE_METATYPE(const cocos2d::CCActionTween *)

namespace cocos2d {
class QtScriptCCPointArray : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCPointArray(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCPointArray(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE unsigned int count();
	Q_INVOKABLE void insert(const cocos2d::CCPoint& controlPoint, unsigned int index);
	Q_INVOKABLE cocos2d::CCPointArray* reverse();
	Q_INVOKABLE bool initWithCapacity(unsigned int cap);
	Q_INVOKABLE void remove(unsigned int index);
	Q_INVOKABLE void replace(const cocos2d::CCPoint& controlPoint, unsigned int index);
	Q_INVOKABLE cocos2d::CCPoint at(unsigned int index);
	Q_INVOKABLE void reverseInline();
	Q_INVOKABLE void append(const cocos2d::CCPoint& controlPoint);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCPointArray *)
Q_DECLARE_METATYPE(const cocos2d::CCPointArray *)

namespace cocos2d {
class QtScriptCCCardinalSplineTo : public QtScriptCCActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCCCardinalSplineTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCardinalSplineTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCPointArray* points READ getPoints WRITE setPoints)
	cocos2d::CCPointArray* getPoints();
	void setPoints(cocos2d::CCPointArray* points);
	Q_INVOKABLE void updatePosition(cocos2d::CCPoint& newPos);
	Q_INVOKABLE bool initWithDuration(float duration, cocos2d::CCPointArray* points, float tension);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCardinalSplineTo *)
Q_DECLARE_METATYPE(const cocos2d::CCCardinalSplineTo *)

namespace cocos2d {
class QtScriptCCCardinalSplineBy : public QtScriptCCCardinalSplineTo
{
	Q_OBJECT

protected:
	explicit QtScriptCCCardinalSplineBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCardinalSplineBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCardinalSplineBy *)
Q_DECLARE_METATYPE(const cocos2d::CCCardinalSplineBy *)

namespace cocos2d {
class QtScriptCCCatmullRomTo : public QtScriptCCCardinalSplineTo
{
	Q_OBJECT

protected:
	explicit QtScriptCCCatmullRomTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCatmullRomTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float dt, cocos2d::CCPointArray* points);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCatmullRomTo *)
Q_DECLARE_METATYPE(const cocos2d::CCCatmullRomTo *)

namespace cocos2d {
class QtScriptCCCatmullRomBy : public QtScriptCCCardinalSplineBy
{
	Q_OBJECT

protected:
	explicit QtScriptCCCatmullRomBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCatmullRomBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float dt, cocos2d::CCPointArray* points);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCatmullRomBy *)
Q_DECLARE_METATYPE(const cocos2d::CCCatmullRomBy *)

namespace cocos2d {
class QtScriptCCAtlasNode : public QtScriptCCNodeRGBA
{
	Q_OBJECT

protected:
	explicit QtScriptCCAtlasNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAtlasNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCTexture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::_ccBlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(cocos2d::CCTextureAtlas* textureAtlas READ getTextureAtlas WRITE setTextureAtlas)
	Q_PROPERTY(unsigned int quadsToDraw READ getQuadsToDraw WRITE setQuadsToDraw)
	void setTexture(cocos2d::CCTexture2D* texture);
	cocos2d::_ccBlendFunc getBlendFunc();
	Q_INVOKABLE bool initWithTileFile(const QByteArray& tile, unsigned int tileWidth, unsigned int tileHeight, unsigned int itemsToRender);
	void setBlendFunc(cocos2d::_ccBlendFunc var);
	void setTextureAtlas(cocos2d::CCTextureAtlas* var);
	cocos2d::CCTexture2D* getTexture();
	cocos2d::CCTextureAtlas* getTextureAtlas();
	unsigned int getQuadsToDraw();
	Q_INVOKABLE void updateAtlasValues();
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* texture, unsigned int tileWidth, unsigned int tileHeight, unsigned int itemsToRender);
	void setQuadsToDraw(unsigned int var);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(bool bIsOpacityModifyRGB READ _public_field_get_bIsOpacityModifyRGB WRITE _public_field_set_bIsOpacityModifyRGB)
	bool _public_field_get_bIsOpacityModifyRGB() const;
	void _public_field_set_bIsOpacityModifyRGB(const bool& value);
	Q_PROPERTY(int nUniformColor READ _public_field_get_nUniformColor WRITE _public_field_set_nUniformColor)
	int _public_field_get_nUniformColor() const;
	void _public_field_set_nUniformColor(int value);
	Q_PROPERTY(bool bIgnoreContentScaleFactor READ _public_field_get_bIgnoreContentScaleFactor WRITE _public_field_set_bIgnoreContentScaleFactor)
	bool _public_field_get_bIgnoreContentScaleFactor() const;
	void _public_field_set_bIgnoreContentScaleFactor(const bool& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAtlasNode *)
Q_DECLARE_METATYPE(const cocos2d::CCAtlasNode *)

namespace cocos2d {
class QtScriptCCAutoreleasePool : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCAutoreleasePool(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAutoreleasePool(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addObject(cocos2d::CCObject* pObject);
	Q_INVOKABLE void clear();
	Q_INVOKABLE void removeObject(cocos2d::CCObject* pObject);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAutoreleasePool *)
Q_DECLARE_METATYPE(const cocos2d::CCAutoreleasePool *)

namespace cocos2d {
class QtScriptCCPoolManager final : public QtScriptBaseClassPrototype<CCPoolManager, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCPoolManager(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCPoolManager(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void push();
	Q_INVOKABLE void removeObject(cocos2d::CCObject* pObject);
	Q_INVOKABLE void pop();
	Q_INVOKABLE void finalize();
	Q_INVOKABLE void addObject(cocos2d::CCObject* pObject);
	static QScriptValue purgePoolManager(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue sharedPoolManager(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCPoolManager)
Q_DECLARE_METATYPE(cocos2d::CCPoolManager *)
Q_DECLARE_METATYPE(const cocos2d::CCPoolManager *)

namespace cocos2d {
class QtScriptCCInteger : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCInteger(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCInteger(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int64_t getValue();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCInteger *)
Q_DECLARE_METATYPE(const cocos2d::CCInteger *)

namespace cocos2d {
class QtScriptCCFloat : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCFloat(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFloat(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE float getValue();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFloat *)
Q_DECLARE_METATYPE(const cocos2d::CCFloat *)

namespace cocos2d {
class QtScriptCCDouble : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCDouble(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDouble(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE double getValue();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCDouble *)
Q_DECLARE_METATYPE(const cocos2d::CCDouble *)

namespace cocos2d {
class QtScriptCCBool : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCBool(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCBool(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool getValue();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCBool *)
Q_DECLARE_METATYPE(const cocos2d::CCBool *)

namespace cocos2d {
class QtScriptCCZone final : public QtScriptBaseClassPrototype<CCZone, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCZone(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCZone(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCObject* pCopyObject READ _public_field_get_pCopyObject WRITE _public_field_set_pCopyObject)
	cocos2d::CCObject* _public_field_get_pCopyObject() const;
	void _public_field_set_pCopyObject(cocos2d::CCObject* value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCZone)
Q_DECLARE_METATYPE(cocos2d::CCZone *)
Q_DECLARE_METATYPE(const cocos2d::CCZone *)

namespace cocos2d {
class QtScriptCCDrawNode : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCDrawNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDrawNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccBlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	cocos2d::_ccBlendFunc getBlendFunc();
	void setBlendFunc(const cocos2d::_ccBlendFunc& blendFunc);
	Q_INVOKABLE void clear();
	Q_INVOKABLE void drawPolygon(const QScriptValue& arg0, const cocos2d::_ccColor4F& arg1, float arg2, const cocos2d::_ccColor4F& arg3);
	Q_INVOKABLE void drawPolygon(const QScriptValue& arg0, float arg1, float arg2, const cocos2d::_ccColor4F& arg3, const cocos2d::_ccColor4F& arg4);
	Q_INVOKABLE void drawDot(const cocos2d::CCPoint& pos, float radius, const cocos2d::_ccColor4F& color);
	Q_INVOKABLE void drawSegment(const cocos2d::CCPoint& from, const cocos2d::CCPoint& to, float radius, const cocos2d::_ccColor4F& color);
	Q_INVOKABLE void drawSegment(const cocos2d::CCPoint& from, const cocos2d::CCPoint& to, float width, float height, const cocos2d::_ccColor4F& color);
	Q_INVOKABLE void listenBackToForeground(cocos2d::CCObject* obj);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCDrawNode *)
Q_DECLARE_METATYPE(const cocos2d::CCDrawNode *)

namespace cocos2d {
class QtScriptCCConfiguration : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCConfiguration(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCConfiguration(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool checkForGLExtension(const QByteArray& searchName);
	Q_INVOKABLE cocos2d::CCObject* getObject(const QByteArray& key);
	Q_INVOKABLE void setObject(const QByteArray& key, cocos2d::CCObject* value);
	Q_INVOKABLE double getNumber(const QByteArray& key);
	Q_INVOKABLE double getNumber(const QByteArray& key, double default_value);
	Q_INVOKABLE bool supportsPVRTC();
	Q_INVOKABLE bool supportsShareableVAO();
	Q_INVOKABLE QByteArray getCString(const QByteArray& key);
	Q_INVOKABLE QByteArray getCString(const QByteArray& key, const QByteArray& default_value);
	Q_INVOKABLE bool getBool(const QByteArray& key);
	Q_INVOKABLE bool getBool(const QByteArray& key, bool default_value);
	Q_INVOKABLE int getMaxTextureUnits();
	Q_INVOKABLE bool supportsNPOT();
	Q_INVOKABLE int getMaxModelviewStackDepth();
	Q_INVOKABLE bool supportsDiscardFramebuffer();
	Q_INVOKABLE bool init();
	Q_INVOKABLE void gatherGPUInfo();
	Q_INVOKABLE void dumpInfo();
	Q_INVOKABLE void loadConfigFile(const QByteArray& filename);
	Q_INVOKABLE int getMaxTextureSize();
	Q_INVOKABLE bool supportsBGRA8888();
	static QScriptValue sharedConfiguration(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue purgeConfiguration(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCConfiguration *)
Q_DECLARE_METATYPE(const cocos2d::CCConfiguration *)

namespace cocos2d {
class QtScriptCCGrabber : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCGrabber(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCGrabber(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void beforeRender(cocos2d::CCTexture2D* pTexture);
	Q_INVOKABLE void grab(cocos2d::CCTexture2D* pTexture);
	Q_INVOKABLE void afterRender(cocos2d::CCTexture2D* pTexture);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCGrabber *)
Q_DECLARE_METATYPE(const cocos2d::CCGrabber *)

namespace cocos2d {
class QtScriptCCCamera : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCCamera(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCCamera(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool dirty READ isDirty WRITE setDirty)
	Q_INVOKABLE void locate();
	Q_INVOKABLE void restore();
	Q_INVOKABLE void setUpXYZ(float fUpX, float fUpY, float fUpZ);
	Q_INVOKABLE QByteArray description();
	Q_INVOKABLE void setCenterXYZ(float fCenterX, float fCenterY, float fCenterZ);
	Q_INVOKABLE void setEyeXYZ(float fEyeX, float fEyeY, float fEyeZ);
	Q_INVOKABLE void getCenterXYZ(cocos2d::_ccVertex3F* arg0);
	Q_INVOKABLE void getEyeXYZ(cocos2d::_ccVertex3F* arg0);
	bool isDirty();
	Q_INVOKABLE void init();
	Q_INVOKABLE void getUpXYZ(cocos2d::_ccVertex3F* arg0);
	void setDirty(bool bValue);
	static QScriptValue getZEye(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCCamera *)
Q_DECLARE_METATYPE(const cocos2d::CCCamera *)

namespace cocos2d {
class QtScriptCCLabelAtlas : public QtScriptCCAtlasNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCLabelAtlas(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLabelAtlas(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray string READ getString WRITE setString)
	void setString(const QByteArray& label);
	Q_INVOKABLE bool initWithString(const QByteArray& string, const QByteArray& fntFile);
	Q_INVOKABLE bool initWithString(const QByteArray& string, const QByteArray& charMapFile, unsigned int itemWidth, unsigned int itemHeight, unsigned int startCharMap);
	QByteArray getString();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLabelAtlas *)
Q_DECLARE_METATYPE(const cocos2d::CCLabelAtlas *)

namespace cocos2d {
class QtScriptCCDirector : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCDirector(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDirector(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCNode* notificationNode READ getNotificationNode WRITE setNotificationNode)
	Q_PROPERTY(bool displayStats READ isDisplayStats WRITE setDisplayStats)
	Q_INVOKABLE float getContentScaleFactor();
	Q_INVOKABLE cocos2d::CCSize getWinSizeInPixels();
	Q_INVOKABLE float getDeltaTime();
	cocos2d::CCNode* getNotificationNode();
	Q_INVOKABLE cocos2d::CCSize getWinSize();
	Q_INVOKABLE double frameStartTimeSeconds();
	Q_INVOKABLE bool isSendCleanupToScene();
	Q_INVOKABLE cocos2d::CCPoint getVisibleOrigin();
	Q_INVOKABLE float getSecondsPerFrame();
	Q_INVOKABLE cocos2d::CCPoint convertToUI(const cocos2d::CCPoint& obPoint);
	Q_INVOKABLE cocos2d::CCEGLView* getOpenGLView();
	Q_INVOKABLE cocos2d::CCScene* getRunningScene();
	Q_INVOKABLE int getProjection();
	Q_INVOKABLE bool isNextDeltaTimeZero();
	Q_INVOKABLE cocos2d::CCScheduler* getScheduler();
	Q_INVOKABLE cocos2d::CCPoint convertToGL(const cocos2d::CCPoint& obPoint);
	Q_INVOKABLE unsigned int getTotalFrames();
	void setNotificationNode(cocos2d::CCNode* node);
	bool isDisplayStats();
	Q_INVOKABLE float getZEye();
	Q_INVOKABLE cocos2d::CCSize getVisibleSize();
	Q_INVOKABLE long getClassTypeInfo();
	Q_INVOKABLE double getAnimationInterval();
	Q_INVOKABLE bool isPaused();
	void setDisplayStats(bool bDisplayStats);
	Q_INVOKABLE cocos2d::CCActionManager* getActionManager();
	static QScriptValue sharedDirector(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCDirector *)
Q_DECLARE_METATYPE(const cocos2d::CCDirector *)

namespace cocos2d {
class QtScriptCCDisplayLinkDirector : public QtScriptCCDirector
{
	Q_OBJECT

protected:
	explicit QtScriptCCDisplayLinkDirector(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDisplayLinkDirector(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void startAnimation();
	Q_INVOKABLE void mainLoop();
	Q_INVOKABLE void setAnimationInterval(double dValue);
	Q_INVOKABLE void stopAnimation();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCDisplayLinkDirector *)
Q_DECLARE_METATYPE(const cocos2d::CCDisplayLinkDirector *)

namespace cocos2d {
class QtScriptCCGridBase : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCGridBase(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCGridBase(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCSize gridSize READ getGridSize WRITE setGridSize)
	Q_PROPERTY(cocos2d::CCPoint step READ getStep WRITE setStep)
	Q_PROPERTY(bool textureFlipped READ isTextureFlipped WRITE setTextureFlipped)
	Q_PROPERTY(bool active READ isActive WRITE setActive)
	Q_PROPERTY(int reuseGrid READ getReuseGrid WRITE setReuseGrid)
	void setGridSize(const cocos2d::CCSize& gridSize);
	Q_INVOKABLE void calculateVertexPoints();
	Q_INVOKABLE void afterDraw(cocos2d::CCNode* pTarget);
	Q_INVOKABLE void beforeDraw();
	bool isTextureFlipped();
	cocos2d::CCSize getGridSize();
	cocos2d::CCPoint getStep();
	Q_INVOKABLE void set2DProjection();
	void setStep(const cocos2d::CCPoint& step);
	void setTextureFlipped(bool bFlipped);
	Q_INVOKABLE void blit();
	void setActive(bool bActive);
	int getReuseGrid();
	Q_INVOKABLE bool initWithSize(const cocos2d::CCSize& gridSize);
	Q_INVOKABLE bool initWithSize(const cocos2d::CCSize& gridSize, cocos2d::CCTexture2D* pTexture, bool bFlipped);
	void setReuseGrid(int nReuseGrid);
	bool isActive();
	Q_INVOKABLE void reuse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCGridBase *)
Q_DECLARE_METATYPE(const cocos2d::CCGridBase *)

namespace cocos2d {
class QtScriptCCGrid3D : public QtScriptCCGridBase
{
	Q_OBJECT

protected:
	explicit QtScriptCCGrid3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCGrid3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setVertex(const cocos2d::CCPoint& pos, const cocos2d::_ccVertex3F& vertex);
	Q_INVOKABLE cocos2d::_ccVertex3F vertex(const cocos2d::CCPoint& pos);
	Q_INVOKABLE cocos2d::_ccVertex3F originalVertex(const cocos2d::CCPoint& pos);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCGrid3D *)
Q_DECLARE_METATYPE(const cocos2d::CCGrid3D *)

namespace cocos2d {
class QtScriptCCTiledGrid3D : public QtScriptCCGridBase
{
	Q_OBJECT

protected:
	explicit QtScriptCCTiledGrid3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTiledGrid3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::_ccQuad3 tile(const cocos2d::CCPoint& pos);
	Q_INVOKABLE void setTile(const cocos2d::CCPoint& pos, const cocos2d::_ccQuad3& coords);
	Q_INVOKABLE cocos2d::_ccQuad3 originalTile(const cocos2d::CCPoint& pos);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTiledGrid3D *)
Q_DECLARE_METATYPE(const cocos2d::CCTiledGrid3D *)

namespace cocos2d {
class QtScriptCCTextureAtlas : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCTextureAtlas(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTextureAtlas(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCTexture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::_ccV3F_C4B_T2F_Quad* quads READ getQuads WRITE setQuads)
	Q_PROPERTY(bool dirty READ isDirty WRITE setDirty)
	void setTexture(cocos2d::CCTexture2D* var);
	Q_INVOKABLE void updateQuad(cocos2d::_ccV3F_C4B_T2F_Quad* quad, unsigned int index);
	cocos2d::CCTexture2D* getTexture();
	void setQuads(cocos2d::_ccV3F_C4B_T2F_Quad* var);
	Q_INVOKABLE void moveQuadsFromIndex(unsigned int index, unsigned int newIndex);
	Q_INVOKABLE void moveQuadsFromIndex(unsigned int oldIndex, unsigned int amount, unsigned int newIndex);
	Q_INVOKABLE unsigned int getTotalQuads();
	Q_INVOKABLE void drawQuads();
	Q_INVOKABLE void fillWithEmptyQuadsFromIndex(unsigned int index, unsigned int amount);
	Q_INVOKABLE unsigned int getCapacity();
	Q_INVOKABLE void listenBackToForeground(cocos2d::CCObject* obj);
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* texture, unsigned int capacity);
	Q_INVOKABLE QByteArray description();
	Q_INVOKABLE void removeQuadsAtIndex(unsigned int index, unsigned int amount);
	Q_INVOKABLE void insertQuad(cocos2d::_ccV3F_C4B_T2F_Quad* quad, unsigned int index);
	Q_INVOKABLE void drawNumberOfQuads(unsigned int n);
	Q_INVOKABLE void drawNumberOfQuads(unsigned int n, unsigned int start);
	void setDirty(bool bDirty);
	bool isDirty();
	Q_INVOKABLE void removeAllQuads();
	Q_INVOKABLE bool initWithFile(const QByteArray& file, unsigned int capacity);
	cocos2d::_ccV3F_C4B_T2F_Quad* getQuads();
	Q_INVOKABLE bool resizeCapacity(unsigned int n);
	Q_INVOKABLE void increaseTotalQuadsWith(unsigned int amount);
	Q_INVOKABLE void insertQuads(cocos2d::_ccV3F_C4B_T2F_Quad* quads, unsigned int index, unsigned int amount);
	Q_INVOKABLE void insertQuadFromIndex(unsigned int fromIndex, unsigned int newIndex);
	Q_INVOKABLE void removeQuadAtIndex(unsigned int index);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTextureAtlas *)
Q_DECLARE_METATYPE(const cocos2d::CCTextureAtlas *)

namespace cocos2d {
class QtScriptCCSprite : public QtScriptCCNodeRGBA
{
	Q_OBJECT

protected:
	explicit QtScriptCCSprite(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSprite(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCTexture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::CCRect textureRect READ getTextureRect WRITE setTextureRect)
	Q_PROPERTY(cocos2d::CCSpriteFrame* displayFrame READ displayFrame WRITE setDisplayFrame)
	Q_PROPERTY(cocos2d::CCSpriteBatchNode* batchNode READ getBatchNode WRITE setBatchNode)
	Q_PROPERTY(cocos2d::CCTextureAtlas* textureAtlas READ getTextureAtlas WRITE setTextureAtlas)
	Q_PROPERTY(bool flipY READ isFlipY WRITE setFlipY)
	Q_PROPERTY(bool flipX READ isFlipX WRITE setFlipX)
	Q_PROPERTY(unsigned int atlasIndex READ getAtlasIndex WRITE setAtlasIndex)
	Q_PROPERTY(bool dirty READ isDirty WRITE setDirty)
	Q_PROPERTY(cocos2d::_ccBlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	void setTexture(cocos2d::CCTexture2D* texture);
	cocos2d::CCTexture2D* getTexture();
	cocos2d::CCSpriteFrame* displayFrame();
	cocos2d::CCSpriteBatchNode* getBatchNode();
	Q_INVOKABLE cocos2d::CCPoint getOffsetPosition();
	bool isFlipX();
	bool isFlipY();
	void setTextureRect(const cocos2d::CCRect& rect);
	Q_INVOKABLE void setTextureRect(const cocos2d::CCRect& rect, bool rotated, const cocos2d::CCSize& untrimmedSize);
	Q_INVOKABLE bool initWithSpriteFrameName(const QByteArray& pszSpriteFrameName);
	Q_INVOKABLE bool isFrameDisplayed(cocos2d::CCSpriteFrame* pFrame);
	unsigned int getAtlasIndex();
	void setDisplayFrame(cocos2d::CCSpriteFrame* pNewFrame);
	void setBatchNode(cocos2d::CCSpriteBatchNode* pobSpriteBatchNode);
	cocos2d::_ccBlendFunc getBlendFunc();
	Q_INVOKABLE void setDisplayFrameWithAnimationName(const QByteArray& animationName, int frameIndex);
	void setTextureAtlas(cocos2d::CCTextureAtlas* pobTextureAtlas);
	void setFlipY(bool bFlipY);
	void setFlipX(bool bFlipX);
	bool isDirty();
	void setAtlasIndex(unsigned int uAtlasIndex);
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* pTexture);
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* pTexture, const cocos2d::CCRect& rect);
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* pTexture, const cocos2d::CCRect& rect, bool rotated);
	void setDirty(bool bDirty);
	Q_INVOKABLE bool isTextureRectRotated();
	cocos2d::CCRect getTextureRect();
	Q_INVOKABLE bool initWithFile(const QByteArray& pszFilename);
	Q_INVOKABLE bool initWithFile(const QByteArray& pszFilename, const cocos2d::CCRect& rect);
	void setBlendFunc(cocos2d::_ccBlendFunc blendFunc);
	cocos2d::CCTextureAtlas* getTextureAtlas();
	Q_INVOKABLE bool initWithSpriteFrame(cocos2d::CCSpriteFrame* pSpriteFrame);
	Q_INVOKABLE cocos2d::_ccV3F_C4B_T2F_Quad getQuad();
	Q_INVOKABLE void setVertexRect(const cocos2d::CCRect& rect);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithSpriteFrameName(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithSpriteFrame(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSprite *)
Q_DECLARE_METATYPE(const cocos2d::CCSprite *)

namespace cocos2d {
class QtScriptCCLabelTTF : public QtScriptCCSprite
{
	Q_OBJECT

protected:
	explicit QtScriptCCLabelTTF(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLabelTTF(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCSize dimensions READ getDimensions WRITE setDimensions)
	Q_PROPERTY(cocos2d::_ccFontDefinition* textDefinition READ getTextDefinition WRITE setTextDefinition)
	Q_PROPERTY(QByteArray fontName READ getFontName WRITE setFontName)
	Q_PROPERTY(QByteArray string READ getString WRITE setString)
	Q_PROPERTY(int verticalAlignment READ getVerticalAlignment WRITE setVerticalAlignment)
	Q_PROPERTY(float fontSize READ getFontSize WRITE setFontSize)
	Q_PROPERTY(int horizontalAlignment READ getHorizontalAlignment WRITE setHorizontalAlignment)
	Q_INVOKABLE void enableShadow(const cocos2d::CCSize& shadowOffset, float shadowOpacity, float shadowBlur);
	Q_INVOKABLE void enableShadow(const cocos2d::CCSize& shadowOffset, float shadowOpacity, float shadowBlur, bool mustUpdateTexture);
	void setDimensions(const cocos2d::CCSize& dim);
	float getFontSize();
	QByteArray getString();
	void setTextDefinition(cocos2d::_ccFontDefinition* theDefinition);
	void setFontName(const QByteArray& fontName);
	int getHorizontalAlignment();
	Q_INVOKABLE bool initWithStringAndTextDefinition(const QByteArray& string, cocos2d::_ccFontDefinition& textDefinition);
	void setString(const QByteArray& label);
	Q_INVOKABLE bool initWithString(const QByteArray& string, const QByteArray& fontName, float fontSize);
	Q_INVOKABLE bool initWithString(const QByteArray& string, const QByteArray& fontName, float fontSize, const cocos2d::CCSize& dimensions, int hAlignment);
	Q_INVOKABLE bool initWithString(const QByteArray& string, const QByteArray& fontName, float fontSize, const cocos2d::CCSize& dimensions, int hAlignment, int vAlignment);
	Q_INVOKABLE void setFontFillColor(const cocos2d::_ccColor3B& tintColor);
	Q_INVOKABLE void setFontFillColor(const cocos2d::_ccColor3B& tintColor, bool mustUpdateTexture);
	Q_INVOKABLE QByteArray description();
	Q_INVOKABLE void enableStroke(const cocos2d::_ccColor3B& strokeColor, float strokeSize);
	Q_INVOKABLE void enableStroke(const cocos2d::_ccColor3B& strokeColor, float strokeSize, bool mustUpdateTexture);
	cocos2d::CCSize getDimensions();
	void setVerticalAlignment(int verticalAlignment);
	void setFontSize(float fontSize);
	int getVerticalAlignment();
	cocos2d::_ccFontDefinition* getTextDefinition();
	QByteArray getFontName();
	void setHorizontalAlignment(int alignment);
	Q_INVOKABLE void disableShadow();
	Q_INVOKABLE void disableShadow(bool mustUpdateTexture);
	Q_INVOKABLE void disableStroke();
	Q_INVOKABLE void disableStroke(bool mustUpdateTexture);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithFontDefinition(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLabelTTF *)
Q_DECLARE_METATYPE(const cocos2d::CCLabelTTF *)

namespace cocos2d {
class QtScriptCCSpriteBatchNode : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCSpriteBatchNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSpriteBatchNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCTextureAtlas* textureAtlas READ getTextureAtlas WRITE setTextureAtlas)
	Q_PROPERTY(cocos2d::CCTexture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::_ccBlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_INVOKABLE void appendChild(cocos2d::CCSprite* sprite);
	Q_INVOKABLE void reorderBatch(bool reorder);
	Q_INVOKABLE bool initWithFile(const QByteArray& fileImage, unsigned int capacity);
	cocos2d::_ccBlendFunc getBlendFunc();
	Q_INVOKABLE unsigned int lowestAtlasIndexInChild(cocos2d::CCSprite* sprite);
	Q_INVOKABLE unsigned int atlasIndexForChild(cocos2d::CCSprite* sprite, int z);
	void setTextureAtlas(cocos2d::CCTextureAtlas* textureAtlas);
	Q_INVOKABLE unsigned int rebuildIndexInOrder(cocos2d::CCSprite* parent, unsigned int index);
	Q_INVOKABLE void increaseAtlasCapacity();
	cocos2d::CCTextureAtlas* getTextureAtlas();
	Q_INVOKABLE cocos2d::CCArray* getDescendants();
	void setTexture(cocos2d::CCTexture2D* texture);
	Q_INVOKABLE void insertChild(cocos2d::CCSprite* child, unsigned int index);
	cocos2d::CCTexture2D* getTexture();
	Q_INVOKABLE void removeChildAtIndex(unsigned int index, bool doCleanup);
	Q_INVOKABLE unsigned int highestAtlasIndexInChild(cocos2d::CCSprite* sprite);
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* tex, unsigned int capacity);
	Q_INVOKABLE void removeSpriteFromAtlas(cocos2d::CCSprite* sprite);
	void setBlendFunc(cocos2d::_ccBlendFunc blendFunc);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSpriteBatchNode *)
Q_DECLARE_METATYPE(const cocos2d::CCSpriteBatchNode *)

namespace cocos2d {
class QtScriptCCBMFontConfiguration : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCBMFontConfiguration(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCBMFontConfiguration(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray atlasName READ getAtlasName WRITE setAtlasName)
	void setAtlasName(const QByteArray& atlasName);
	Q_INVOKABLE bool initWithFNTfile(const QByteArray& FNTfile);
	QByteArray getAtlasName();
	Q_INVOKABLE QByteArray description();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCBMFontConfiguration *)
Q_DECLARE_METATYPE(const cocos2d::CCBMFontConfiguration *)

namespace cocos2d {
class QtScriptCCLabelBMFont : public QtScriptCCSpriteBatchNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCLabelBMFont(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLabelBMFont(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned char opacity READ getOpacity WRITE setOpacity)
	Q_PROPERTY(bool cascadeOpacityEnabled READ isCascadeOpacityEnabled WRITE setCascadeOpacityEnabled)
	Q_PROPERTY(QByteArray string READ getString WRITE setString)
	Q_PROPERTY(bool cascadeColorEnabled READ isCascadeColorEnabled WRITE setCascadeColorEnabled)
	Q_PROPERTY(bool opacityModifyRGB READ isOpacityModifyRGB WRITE setOpacityModifyRGB)
	Q_PROPERTY(QByteArray fntFile READ getFntFile WRITE setFntFile)
	Q_PROPERTY(cocos2d::_ccColor3B color READ getColor WRITE setColor)
	Q_INVOKABLE void createFontChars();
	QByteArray getString();
	void setOpacity(unsigned char opacity);
	void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);
	QByteArray getFntFile();
	Q_INVOKABLE void updateLabel();
	Q_INVOKABLE void setWidth(float width);
	bool isOpacityModifyRGB();
	bool isCascadeOpacityEnabled();
	void setString(const QByteArray& newString);
	Q_INVOKABLE void setString(const QByteArray& newString, bool needUpdateLabel);
	Q_INVOKABLE bool initWithString(const QByteArray& str, const QByteArray& fntFile);
	Q_INVOKABLE bool initWithString(const QByteArray& str, const QByteArray& fntFile, float width);
	Q_INVOKABLE bool initWithString(const QByteArray& str, const QByteArray& fntFile, float width, int alignment);
	Q_INVOKABLE bool initWithString(const QByteArray& str, const QByteArray& fntFile, float width, int alignment, cocos2d::CCPoint imageOffset);
	void setCascadeColorEnabled(bool cascadeColorEnabled);
	void setOpacityModifyRGB(bool isOpacityModifyRGB);
	Q_INVOKABLE void updateDisplayedOpacity(unsigned char parentOpacity);
	void setFntFile(const QByteArray& fntFile);
	unsigned char getOpacity();
	Q_INVOKABLE void setLineBreakWithoutSpace(bool breakWithoutSpace);
	Q_INVOKABLE cocos2d::CCBMFontConfiguration* getConfiguration();
	cocos2d::_ccColor3B getColor();
	Q_INVOKABLE unsigned char getDisplayedOpacity();
	void setColor(const cocos2d::_ccColor3B& color);
	Q_INVOKABLE void setCString(const QByteArray& label);
	Q_INVOKABLE cocos2d::_ccColor3B getDisplayedColor();
	bool isCascadeColorEnabled();
	Q_INVOKABLE void updateDisplayedColor(const cocos2d::_ccColor3B& parentColor);
	Q_INVOKABLE void setAlignment(int alignment);
	static QScriptValue purgeCachedData(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLabelBMFont *)
Q_DECLARE_METATYPE(const cocos2d::CCLabelBMFont *)

namespace cocos2d {
class QtScriptCCLayer : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCLayer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLayer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool accelerometerEnabled READ isAccelerometerEnabled WRITE setAccelerometerEnabled)
	Q_PROPERTY(bool touchEnabled READ isTouchEnabled WRITE setTouchEnabled)
	Q_PROPERTY(int touchPriority READ getTouchPriority WRITE setTouchPriority)
	Q_PROPERTY(bool keypadEnabled READ isKeypadEnabled WRITE setKeypadEnabled)
	Q_INVOKABLE void keyBackClicked();
	Q_INVOKABLE bool ccTouchBegan(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	bool isKeypadEnabled();
	Q_INVOKABLE void ccTouchesCancelled(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	Q_INVOKABLE void didAccelerate(cocos2d::CCAcceleration* pAccelerationValue);
	Q_INVOKABLE void ccTouchesMoved(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	Q_INVOKABLE void unregisterTouchHandler();
	Q_INVOKABLE void registerKeypadHandler(const QScriptValue& arg0);
	Q_INVOKABLE int getTouchMode();
	void setAccelerometerEnabled(bool value);
	bool isTouchEnabled();
	Q_INVOKABLE void registerTouchHandler(const QScriptValue& arg0, int arg1, bool arg2, int arg3);
	Q_INVOKABLE void ccTouchMoved(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	void setTouchEnabled(bool value);
	Q_INVOKABLE void setAccelerometerInterval(double interval);
	Q_INVOKABLE void ccTouchesEnded(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	Q_INVOKABLE void unregisterKeypadHandler();
	Q_INVOKABLE void setTouchMode(int mode);
	bool isAccelerometerEnabled();
	Q_INVOKABLE void ccTouchEnded(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	Q_INVOKABLE void ccTouchCancelled(cocos2d::CCTouch* pTouch, cocos2d::CCEvent* pEvent);
	Q_INVOKABLE void ccTouchesBegan(cocos2d::CCSet* pTouches, cocos2d::CCEvent* pEvent);
	void setTouchPriority(int priority);
	int getTouchPriority();
	void setKeypadEnabled(bool value);
	Q_INVOKABLE void registerWithTouchDispatcher();
	Q_INVOKABLE void keyMenuClicked();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLayer *)
Q_DECLARE_METATYPE(const cocos2d::CCLayer *)

namespace cocos2d {
class QtScriptCCLayerRGBA : public QtScriptCCLayer
{
	Q_OBJECT

protected:
	explicit QtScriptCCLayerRGBA(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLayerRGBA(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccColor3B color READ getColor WRITE setColor)
	Q_PROPERTY(bool cascadeColorEnabled READ isCascadeColorEnabled WRITE setCascadeColorEnabled)
	Q_PROPERTY(unsigned char opacity READ getOpacity WRITE setOpacity)
	Q_PROPERTY(bool opacityModifyRGB READ isOpacityModifyRGB WRITE setOpacityModifyRGB)
	Q_PROPERTY(bool cascadeOpacityEnabled READ isCascadeOpacityEnabled WRITE setCascadeOpacityEnabled)
	bool isOpacityModifyRGB();
	void setColor(const cocos2d::_ccColor3B& color);
	bool isCascadeOpacityEnabled();
	cocos2d::_ccColor3B getColor();
	Q_INVOKABLE unsigned char getDisplayedOpacity();
	void setCascadeColorEnabled(bool cascadeColorEnabled);
	void setOpacity(unsigned char opacity);
	void setOpacityModifyRGB(bool bValue);
	void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);
	Q_INVOKABLE void updateDisplayedOpacity(unsigned char parentOpacity);
	bool isCascadeColorEnabled();
	Q_INVOKABLE void updateDisplayedColor(const cocos2d::_ccColor3B& parentColor);
	unsigned char getOpacity();
	Q_INVOKABLE cocos2d::_ccColor3B getDisplayedColor();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLayerRGBA *)
Q_DECLARE_METATYPE(const cocos2d::CCLayerRGBA *)

namespace cocos2d {
class QtScriptCCLayerColor : public QtScriptCCLayerRGBA
{
	Q_OBJECT

protected:
	explicit QtScriptCCLayerColor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLayerColor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccBlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_INVOKABLE void changeWidthAndHeight(float w, float h);
	cocos2d::_ccBlendFunc getBlendFunc();
	void setBlendFunc(cocos2d::_ccBlendFunc var);
	Q_INVOKABLE bool initWithColor(const cocos2d::_ccColor4B& color);
	Q_INVOKABLE bool initWithColor(const cocos2d::_ccColor4B& color, float width, float height);
	Q_INVOKABLE void changeWidth(float w);
	Q_INVOKABLE void changeHeight(float h);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLayerColor *)
Q_DECLARE_METATYPE(const cocos2d::CCLayerColor *)

namespace cocos2d {
class QtScriptCCLayerGradient : public QtScriptCCLayerColor
{
	Q_OBJECT

protected:
	explicit QtScriptCCLayerGradient(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLayerGradient(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCPoint vector READ getVector WRITE setVector)
	Q_PROPERTY(unsigned char startOpacity READ getStartOpacity WRITE setStartOpacity)
	Q_PROPERTY(bool compressedInterpolation READ isCompressedInterpolation WRITE setCompressedInterpolation)
	Q_PROPERTY(unsigned char endOpacity READ getEndOpacity WRITE setEndOpacity)
	Q_PROPERTY(cocos2d::_ccColor3B endColor READ getEndColor WRITE setEndColor)
	Q_PROPERTY(cocos2d::_ccColor3B startColor READ getStartColor WRITE setStartColor)
	cocos2d::_ccColor3B getStartColor();
	bool isCompressedInterpolation();
	unsigned char getStartOpacity();
	void setVector(const cocos2d::CCPoint& var);
	void setStartOpacity(unsigned char var);
	void setCompressedInterpolation(bool bCompressedInterpolation);
	void setEndOpacity(unsigned char var);
	cocos2d::CCPoint getVector();
	void setEndColor(const cocos2d::_ccColor3B& var);
	Q_INVOKABLE bool initWithColor(const cocos2d::_ccColor4B& start, const cocos2d::_ccColor4B& end);
	Q_INVOKABLE bool initWithColor(const cocos2d::_ccColor4B& start, const cocos2d::_ccColor4B& end, const cocos2d::CCPoint& v);
	cocos2d::_ccColor3B getEndColor();
	unsigned char getEndOpacity();
	void setStartColor(const cocos2d::_ccColor3B& var);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLayerGradient *)
Q_DECLARE_METATYPE(const cocos2d::CCLayerGradient *)

namespace cocos2d {
class QtScriptCCLayerMultiplex : public QtScriptCCLayer
{
	Q_OBJECT

protected:
	explicit QtScriptCCLayerMultiplex(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCLayerMultiplex(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithArray(cocos2d::CCArray* arrayOfLayers);
	Q_INVOKABLE void switchToAndReleaseMe(unsigned int n);
	Q_INVOKABLE void addLayer(cocos2d::CCLayer* layer);
	Q_INVOKABLE bool initWithLayers(cocos2d::CCLayer* layer, QByteArray* params);
	Q_INVOKABLE void switchTo(unsigned int n);
	static QScriptValue createWithLayer(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithArray(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCLayerMultiplex *)
Q_DECLARE_METATYPE(const cocos2d::CCLayerMultiplex *)

namespace cocos2d {
class QtScriptCCScene : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCScene(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCScene(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCScene *)
Q_DECLARE_METATYPE(const cocos2d::CCScene *)

namespace cocos2d {
class QtScriptCCTransitionEaseScene : public QtScriptBaseClassPrototype<CCTransitionEaseScene *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionEaseScene(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionEaseScene(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCTransitionEaseScene::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCTransitionEaseScene *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionEaseScene *)

namespace cocos2d {
class QtScriptCCTransitionScene : public QtScriptCCScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionScene(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionScene(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void finish();
	Q_INVOKABLE bool initWithDuration(float t, cocos2d::CCScene* scene);
	Q_INVOKABLE void hideOutShowIn();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionScene *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionScene *)

namespace cocos2d {
class QtScriptCCTransitionSceneOriented : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionSceneOriented(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionSceneOriented(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float t, cocos2d::CCScene* scene, int orientation);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionSceneOriented *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionSceneOriented *)

namespace cocos2d {
class QtScriptCCTransitionRotoZoom : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionRotoZoom(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionRotoZoom(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionRotoZoom *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionRotoZoom *)

namespace cocos2d {
class QtScriptCCTransitionJumpZoom : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionJumpZoom(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionJumpZoom(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionJumpZoom *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionJumpZoom *)

namespace cocos2d {
class QtScriptCCTransitionMoveInL : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionMoveInL(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionMoveInL(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCActionInterval* action();
	Q_INVOKABLE cocos2d::CCActionInterval* easeActionWithAction(cocos2d::CCActionInterval* action);
	Q_INVOKABLE void initScenes();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionMoveInL *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionMoveInL *)

namespace cocos2d {
class QtScriptCCTransitionMoveInR : public QtScriptCCTransitionMoveInL
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionMoveInR(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionMoveInR(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionMoveInR *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionMoveInR *)

namespace cocos2d {
class QtScriptCCTransitionMoveInT : public QtScriptCCTransitionMoveInL
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionMoveInT(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionMoveInT(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionMoveInT *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionMoveInT *)

namespace cocos2d {
class QtScriptCCTransitionMoveInB : public QtScriptCCTransitionMoveInL
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionMoveInB(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionMoveInB(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionMoveInB *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionMoveInB *)

namespace cocos2d {
class QtScriptCCTransitionSlideInL : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionSlideInL(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionSlideInL(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCActionInterval* action();
	Q_INVOKABLE cocos2d::CCActionInterval* easeActionWithAction(cocos2d::CCActionInterval* action);
	Q_INVOKABLE void initScenes();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionSlideInL *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionSlideInL *)

namespace cocos2d {
class QtScriptCCTransitionSlideInR : public QtScriptCCTransitionSlideInL
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionSlideInR(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionSlideInR(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionSlideInR *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionSlideInR *)

namespace cocos2d {
class QtScriptCCTransitionSlideInB : public QtScriptCCTransitionSlideInL
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionSlideInB(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionSlideInB(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionSlideInB *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionSlideInB *)

namespace cocos2d {
class QtScriptCCTransitionSlideInT : public QtScriptCCTransitionSlideInL
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionSlideInT(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionSlideInT(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionSlideInT *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionSlideInT *)

namespace cocos2d {
class QtScriptCCTransitionShrinkGrow : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionShrinkGrow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionShrinkGrow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCActionInterval* easeActionWithAction(cocos2d::CCActionInterval* action);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionShrinkGrow *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionShrinkGrow *)

namespace cocos2d {
class QtScriptCCTransitionFlipX : public QtScriptCCTransitionSceneOriented
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionFlipX(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionFlipX(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionFlipX *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionFlipX *)

namespace cocos2d {
class QtScriptCCTransitionFlipY : public QtScriptCCTransitionSceneOriented
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionFlipY(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionFlipY(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionFlipY *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionFlipY *)

namespace cocos2d {
class QtScriptCCTransitionFlipAngular : public QtScriptCCTransitionSceneOriented
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionFlipAngular(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionFlipAngular(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionFlipAngular *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionFlipAngular *)

namespace cocos2d {
class QtScriptCCTransitionZoomFlipX : public QtScriptCCTransitionSceneOriented
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionZoomFlipX(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionZoomFlipX(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionZoomFlipX *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionZoomFlipX *)

namespace cocos2d {
class QtScriptCCTransitionZoomFlipY : public QtScriptCCTransitionSceneOriented
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionZoomFlipY(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionZoomFlipY(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionZoomFlipY *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionZoomFlipY *)

namespace cocos2d {
class QtScriptCCTransitionZoomFlipAngular : public QtScriptCCTransitionSceneOriented
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionZoomFlipAngular(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionZoomFlipAngular(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionZoomFlipAngular *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionZoomFlipAngular *)

namespace cocos2d {
class QtScriptCCTransitionFade : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionFade(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionFade(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithDuration(float t, cocos2d::CCScene* scene, const cocos2d::_ccColor3B& color);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionFade *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionFade *)

namespace cocos2d {
class QtScriptCCTransitionCrossFade : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionCrossFade(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionCrossFade(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionCrossFade *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionCrossFade *)

namespace cocos2d {
class QtScriptCCTransitionTurnOffTiles : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionTurnOffTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionTurnOffTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCActionInterval* easeActionWithAction(cocos2d::CCActionInterval* action);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionTurnOffTiles *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionTurnOffTiles *)

namespace cocos2d {
class QtScriptCCTransitionSplitCols : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionSplitCols(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionSplitCols(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCActionInterval* action();
	Q_INVOKABLE cocos2d::CCActionInterval* easeActionWithAction(cocos2d::CCActionInterval* action);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionSplitCols *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionSplitCols *)

namespace cocos2d {
class QtScriptCCTransitionSplitRows : public QtScriptCCTransitionSplitCols
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionSplitRows(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionSplitRows(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionSplitRows *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionSplitRows *)

namespace cocos2d {
class QtScriptCCTransitionFadeTR : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionFadeTR(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionFadeTR(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCActionInterval* easeActionWithAction(cocos2d::CCActionInterval* action);
	Q_INVOKABLE cocos2d::CCActionInterval* actionWithSize(const cocos2d::CCSize& size);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionFadeTR *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionFadeTR *)

namespace cocos2d {
class QtScriptCCTransitionFadeBL : public QtScriptCCTransitionFadeTR
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionFadeBL(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionFadeBL(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionFadeBL *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionFadeBL *)

namespace cocos2d {
class QtScriptCCTransitionFadeUp : public QtScriptCCTransitionFadeTR
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionFadeUp(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionFadeUp(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionFadeUp *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionFadeUp *)

namespace cocos2d {
class QtScriptCCTransitionFadeDown : public QtScriptCCTransitionFadeTR
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionFadeDown(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionFadeDown(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionFadeDown *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionFadeDown *)

namespace cocos2d {
class QtScriptCCTransitionPageTurn : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionPageTurn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionPageTurn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCActionInterval* actionWithSize(const cocos2d::CCSize& vector);
	Q_INVOKABLE bool initWithDuration(float t, cocos2d::CCScene* scene, bool backwards);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionPageTurn *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionPageTurn *)

namespace cocos2d {
class QtScriptCCTransitionProgress : public QtScriptCCTransitionScene
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionProgress(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionProgress(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionProgress *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionProgress *)

namespace cocos2d {
class QtScriptCCTransitionProgressRadialCCW : public QtScriptCCTransitionProgress
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionProgressRadialCCW(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionProgressRadialCCW(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionProgressRadialCCW *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionProgressRadialCCW *)

namespace cocos2d {
class QtScriptCCTransitionProgressRadialCW : public QtScriptCCTransitionProgress
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionProgressRadialCW(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionProgressRadialCW(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionProgressRadialCW *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionProgressRadialCW *)

namespace cocos2d {
class QtScriptCCTransitionProgressHorizontal : public QtScriptCCTransitionProgress
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionProgressHorizontal(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionProgressHorizontal(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionProgressHorizontal *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionProgressHorizontal *)

namespace cocos2d {
class QtScriptCCTransitionProgressVertical : public QtScriptCCTransitionProgress
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionProgressVertical(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionProgressVertical(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionProgressVertical *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionProgressVertical *)

namespace cocos2d {
class QtScriptCCTransitionProgressInOut : public QtScriptCCTransitionProgress
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionProgressInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionProgressInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionProgressInOut *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionProgressInOut *)

namespace cocos2d {
class QtScriptCCTransitionProgressOutIn : public QtScriptCCTransitionProgress
{
	Q_OBJECT

protected:
	explicit QtScriptCCTransitionProgressOutIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTransitionProgressOutIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTransitionProgressOutIn *)
Q_DECLARE_METATYPE(const cocos2d::CCTransitionProgressOutIn *)

namespace cocos2d {
class QtScriptCCMenuItem : public QtScriptCCNodeRGBA
{
	Q_OBJECT

protected:
	explicit QtScriptCCMenuItem(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMenuItem(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
	void setEnabled(bool value);
	Q_INVOKABLE void activate();
	bool isEnabled();
	Q_INVOKABLE void selected();
	Q_INVOKABLE void registerTapHandler(const QScriptValue& arg0);
	Q_INVOKABLE bool isSelected();
	Q_INVOKABLE void unregisterTapHandler();
	Q_INVOKABLE void unselected();
	Q_INVOKABLE cocos2d::CCRect rect();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMenuItem *)
Q_DECLARE_METATYPE(const cocos2d::CCMenuItem *)

namespace cocos2d {
class QtScriptCCMenuItemLabel : public QtScriptCCMenuItem
{
	Q_OBJECT

protected:
	explicit QtScriptCCMenuItemLabel(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMenuItemLabel(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCNode* label READ getLabel WRITE setLabel)
	Q_PROPERTY(cocos2d::_ccColor3B disabledColor READ getDisabledColor WRITE setDisabledColor)
	cocos2d::_ccColor3B getDisabledColor();
	void setLabel(cocos2d::CCNode* var);
	void setDisabledColor(const cocos2d::_ccColor3B& var);
	cocos2d::CCNode* getLabel();
	Q_INVOKABLE void setString(const QByteArray& label);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMenuItemLabel *)
Q_DECLARE_METATYPE(const cocos2d::CCMenuItemLabel *)

namespace cocos2d {
class QtScriptCCMenuItemAtlasFont : public QtScriptCCMenuItemLabel
{
	Q_OBJECT

protected:
	explicit QtScriptCCMenuItemAtlasFont(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMenuItemAtlasFont(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMenuItemAtlasFont *)
Q_DECLARE_METATYPE(const cocos2d::CCMenuItemAtlasFont *)

namespace cocos2d {
class QtScriptCCMenuItemFont : public QtScriptCCMenuItemLabel
{
	Q_OBJECT

protected:
	explicit QtScriptCCMenuItemFont(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMenuItemFont(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int fontSizeObj READ fontSizeObj WRITE setFontSizeObj)
	Q_PROPERTY(QByteArray fontNameObj READ fontNameObj WRITE setFontNameObj)
	unsigned int fontSizeObj();
	QByteArray fontNameObj();
	void setFontSizeObj(unsigned int s);
	void setFontNameObj(const QByteArray& name);
	static QScriptValue setFontName(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue fontName(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue fontSize(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setFontSize(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMenuItemFont *)
Q_DECLARE_METATYPE(const cocos2d::CCMenuItemFont *)

namespace cocos2d {
class QtScriptCCMenuItemSprite : public QtScriptCCMenuItem
{
	Q_OBJECT

protected:
	explicit QtScriptCCMenuItemSprite(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMenuItemSprite(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCNode* normalImage READ getNormalImage WRITE setNormalImage)
	Q_PROPERTY(cocos2d::CCNode* disabledImage READ getDisabledImage WRITE setDisabledImage)
	Q_PROPERTY(cocos2d::CCNode* selectedImage READ getSelectedImage WRITE setSelectedImage)
	void setNormalImage(cocos2d::CCNode* var);
	void setDisabledImage(cocos2d::CCNode* var);
	void setSelectedImage(cocos2d::CCNode* var);
	cocos2d::CCNode* getDisabledImage();
	cocos2d::CCNode* getSelectedImage();
	cocos2d::CCNode* getNormalImage();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMenuItemSprite *)
Q_DECLARE_METATYPE(const cocos2d::CCMenuItemSprite *)

namespace cocos2d {
class QtScriptCCMenuItemImage : public QtScriptCCMenuItemSprite
{
	Q_OBJECT

protected:
	explicit QtScriptCCMenuItemImage(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMenuItemImage(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setDisabledSpriteFrame(cocos2d::CCSpriteFrame* frame);
	Q_INVOKABLE void setSelectedSpriteFrame(cocos2d::CCSpriteFrame* frame);
	Q_INVOKABLE void setNormalSpriteFrame(cocos2d::CCSpriteFrame* frame);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMenuItemImage *)
Q_DECLARE_METATYPE(const cocos2d::CCMenuItemImage *)

namespace cocos2d {
class QtScriptCCMenuItemToggle : public QtScriptCCMenuItem
{
	Q_OBJECT

protected:
	explicit QtScriptCCMenuItemToggle(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMenuItemToggle(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCArray* subItems READ getSubItems WRITE setSubItems)
	Q_PROPERTY(unsigned int selectedIndex READ getSelectedIndex WRITE setSelectedIndex)
	void setSubItems(cocos2d::CCArray* var);
	Q_INVOKABLE bool initWithItem(cocos2d::CCMenuItem* item);
	void setSelectedIndex(unsigned int var);
	unsigned int getSelectedIndex();
	Q_INVOKABLE void addSubItem(cocos2d::CCMenuItem* item);
	Q_INVOKABLE cocos2d::CCMenuItem* selectedItem();
	cocos2d::CCArray* getSubItems();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMenuItemToggle *)
Q_DECLARE_METATYPE(const cocos2d::CCMenuItemToggle *)

namespace cocos2d {
class QtScriptCCMenu : public QtScriptCCLayerRGBA
{
	Q_OBJECT

protected:
	explicit QtScriptCCMenu(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMenu(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
	Q_INVOKABLE bool initWithArray(cocos2d::CCArray* pArrayOfItems);
	void setEnabled(bool value);
	Q_INVOKABLE void alignItemsVertically();
	bool isEnabled();
	Q_INVOKABLE void alignItemsInRowsWithArray(cocos2d::CCArray* columns);
	Q_INVOKABLE void setHandlerPriority(int newPriority);
	Q_INVOKABLE void alignItemsHorizontally();
	Q_INVOKABLE void alignItemsHorizontallyWithPadding(float padding);
	Q_INVOKABLE void alignItemsInColumnsWithArray(cocos2d::CCArray* rows);
	Q_INVOKABLE void alignItemsVerticallyWithPadding(float padding);
	Q_INVOKABLE void alignItemsInRows(unsigned int rows, QByteArray* args);
	Q_INVOKABLE void alignItemsInColumns(unsigned int columns, QByteArray* args);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithArray(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithItem(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMenu *)
Q_DECLARE_METATYPE(const cocos2d::CCMenu *)

namespace cocos2d {
class QtScriptCCClippingNode : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCClippingNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCClippingNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool inverted READ isInverted WRITE setInverted)
	Q_PROPERTY(cocos2d::CCNode* stencil READ getStencil WRITE setStencil)
	Q_PROPERTY(float alphaThreshold READ getAlphaThreshold WRITE setAlphaThreshold)
	bool isInverted();
	void setInverted(bool bInverted);
	void setStencil(cocos2d::CCNode* pStencil);
	float getAlphaThreshold();
	Q_INVOKABLE bool init(cocos2d::CCNode* pStencil);
	cocos2d::CCNode* getStencil();
	void setAlphaThreshold(float fAlphaThreshold);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCClippingNode *)
Q_DECLARE_METATYPE(const cocos2d::CCClippingNode *)

namespace cocos2d {
class QtScriptCCMotionStreak : public QtScriptCCNodeRGBA
{
	Q_OBJECT

protected:
	explicit QtScriptCCMotionStreak(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCMotionStreak(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCTexture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::_ccBlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(bool startingPositionInitialized READ isStartingPositionInitialized WRITE setStartingPositionInitialized)
	Q_PROPERTY(bool fastMode READ isFastMode WRITE setFastMode)
	Q_INVOKABLE void reset();
	void setTexture(cocos2d::CCTexture2D* texture);
	void setBlendFunc(cocos2d::_ccBlendFunc blendFunc);
	Q_INVOKABLE void tintWithColor(cocos2d::_ccColor3B colors);
	cocos2d::CCTexture2D* getTexture();
	void setStartingPositionInitialized(bool bStartingPositionInitialized);
	cocos2d::_ccBlendFunc getBlendFunc();
	Q_INVOKABLE bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::_ccColor3B& color, const QByteArray& path);
	bool isFastMode();
	bool isStartingPositionInitialized();
	void setFastMode(bool bFastMode);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCMotionStreak *)
Q_DECLARE_METATYPE(const cocos2d::CCMotionStreak *)

namespace cocos2d {
class QtScriptCCProgressTimer : public QtScriptCCNodeRGBA
{
	Q_OBJECT

protected:
	explicit QtScriptCCProgressTimer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCProgressTimer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCPoint barChangeRate READ getBarChangeRate WRITE setBarChangeRate)
	Q_PROPERTY(cocos2d::CCSprite* sprite READ getSprite WRITE setSprite)
	Q_PROPERTY(cocos2d::CCPoint midpoint READ getMidpoint WRITE setMidpoint)
	Q_PROPERTY(bool reverseDirection READ isReverseDirection WRITE setReverseDirection)
	Q_PROPERTY(float percentage READ getPercentage WRITE setPercentage)
	Q_PROPERTY(int type READ getType WRITE setType)
	Q_INVOKABLE void setReverseProgress(bool reverse);
	bool isReverseDirection();
	void setBarChangeRate(cocos2d::CCPoint var);
	Q_INVOKABLE void setAnchorPoint(cocos2d::CCPoint anchorPoint);
	cocos2d::CCPoint getBarChangeRate();
	float getPercentage();
	void setSprite(cocos2d::CCSprite* pSprite);
	int getType();
	cocos2d::CCSprite* getSprite();
	void setMidpoint(cocos2d::CCPoint var);
	cocos2d::CCPoint getMidpoint();
	Q_INVOKABLE cocos2d::_ccColor3B getColor();
	Q_INVOKABLE unsigned char getOpacity();
	void setReverseDirection(bool value);
	Q_INVOKABLE bool initWithSprite(cocos2d::CCSprite* sp);
	void setPercentage(float fPercentage);
	void setType(int type);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(bool bReverseDirection READ _public_field_get_bReverseDirection WRITE _public_field_set_bReverseDirection)
	bool _public_field_get_bReverseDirection() const;
	void _public_field_set_bReverseDirection(const bool& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCProgressTimer *)
Q_DECLARE_METATYPE(const cocos2d::CCProgressTimer *)

namespace cocos2d {
class QtScriptCCRenderTexture : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCRenderTexture(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCRenderTexture(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCSprite* sprite READ getSprite WRITE setSprite)
	Q_PROPERTY(unsigned int clearFlags READ getClearFlags WRITE setClearFlags)
	Q_PROPERTY(bool autoDraw READ isAutoDraw WRITE setAutoDraw)
	Q_PROPERTY(cocos2d::_ccColor4F clearColor READ getClearColor WRITE setClearColor)
	Q_PROPERTY(float clearDepth READ getClearDepth WRITE setClearDepth)
	Q_INVOKABLE void clearStencil(int stencilValue);
	Q_INVOKABLE void listenToForeground(cocos2d::CCObject* obj);
	float getClearDepth();
	Q_INVOKABLE int getClearStencil();
	Q_INVOKABLE void end();
	Q_INVOKABLE void setClearStencil(float fClearStencil);
	void setSprite(cocos2d::CCSprite* var);
	cocos2d::CCSprite* getSprite();
	bool isAutoDraw();
	void setClearFlags(unsigned int uClearFlags);
	Q_INVOKABLE void begin();
	Q_INVOKABLE bool saveToFile(const QByteArray& szFilePath);
	Q_INVOKABLE bool saveToFile(const QByteArray& name, int format);
	void setAutoDraw(bool bAutoDraw);
	void setClearColor(const cocos2d::_ccColor4F& clearColor);
	Q_INVOKABLE void endToLua();
	Q_INVOKABLE void beginWithClear(float r, float g, float b, float a);
	Q_INVOKABLE void beginWithClear(float r, float g, float b, float a, float depthValue);
	Q_INVOKABLE void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue);
	Q_INVOKABLE void clearDepth(float depthValue);
	cocos2d::_ccColor4F getClearColor();
	Q_INVOKABLE void listenToBackground(cocos2d::CCObject* obj);
	Q_INVOKABLE void clear(float r, float g, float b, float a);
	unsigned int getClearFlags();
	Q_INVOKABLE cocos2d::CCImage* newCCImage();
	Q_INVOKABLE cocos2d::CCImage* newCCImage(bool flipImage);
	void setClearDepth(float fClearDepth);
	Q_INVOKABLE bool initWithWidthAndHeight(int w, int h, int eFormat);
	Q_INVOKABLE bool initWithWidthAndHeight(int w, int h, int eFormat, unsigned int uDepthStencilFormat);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCRenderTexture *)
Q_DECLARE_METATYPE(const cocos2d::CCRenderTexture *)

namespace cocos2d {
class QtScriptCCParticleBatchNode : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleBatchNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleBatchNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCTexture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::CCTextureAtlas* textureAtlas READ getTextureAtlas WRITE setTextureAtlas)
	Q_PROPERTY(cocos2d::_ccBlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	void setTexture(cocos2d::CCTexture2D* texture);
	Q_INVOKABLE bool initWithFile(const QByteArray& fileImage, unsigned int capacity);
	Q_INVOKABLE void disableParticle(unsigned int particleIndex);
	cocos2d::CCTexture2D* getTexture();
	void setTextureAtlas(cocos2d::CCTextureAtlas* var);
	void setBlendFunc(cocos2d::_ccBlendFunc blendFunc);
	cocos2d::CCTextureAtlas* getTextureAtlas();
	cocos2d::_ccBlendFunc getBlendFunc();
	Q_INVOKABLE void insertChild(cocos2d::CCParticleSystem* pSystem, unsigned int index);
	Q_INVOKABLE void removeChildAtIndex(unsigned int index, bool doCleanup);
	Q_INVOKABLE bool initWithTexture(cocos2d::CCTexture2D* tex, unsigned int capacity);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleBatchNode *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleBatchNode *)

namespace cocos2d {
class QtScriptsCCParticle_ModeA final : public QtScriptBaseClassPrototype<sCCParticle::ModeA, false>
{
	Q_OBJECT

protected:
	explicit QtScriptsCCParticle_ModeA(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptsCCParticle_ModeA(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCPoint dir READ _public_field_get_dir WRITE _public_field_set_dir)
	cocos2d::CCPoint _public_field_get_dir() const;
	void _public_field_set_dir(const cocos2d::CCPoint& value);
	Q_PROPERTY(float radialAccel READ _public_field_get_radialAccel WRITE _public_field_set_radialAccel)
	float _public_field_get_radialAccel() const;
	void _public_field_set_radialAccel(float value);
	Q_PROPERTY(float tangentialAccel READ _public_field_get_tangentialAccel WRITE _public_field_set_tangentialAccel)
	float _public_field_get_tangentialAccel() const;
	void _public_field_set_tangentialAccel(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::sCCParticle::ModeA)
Q_DECLARE_METATYPE(cocos2d::sCCParticle::ModeA *)
Q_DECLARE_METATYPE(const cocos2d::sCCParticle::ModeA *)

namespace cocos2d {
class QtScriptsCCParticle_ModeB final : public QtScriptBaseClassPrototype<sCCParticle::ModeB, false>
{
	Q_OBJECT

protected:
	explicit QtScriptsCCParticle_ModeB(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptsCCParticle_ModeB(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float angle READ _public_field_get_angle WRITE _public_field_set_angle)
	float _public_field_get_angle() const;
	void _public_field_set_angle(float value);
	Q_PROPERTY(float degreesPerSecond READ _public_field_get_degreesPerSecond WRITE _public_field_set_degreesPerSecond)
	float _public_field_get_degreesPerSecond() const;
	void _public_field_set_degreesPerSecond(float value);
	Q_PROPERTY(float radius READ _public_field_get_radius WRITE _public_field_set_radius)
	float _public_field_get_radius() const;
	void _public_field_set_radius(float value);
	Q_PROPERTY(float deltaRadius READ _public_field_get_deltaRadius WRITE _public_field_set_deltaRadius)
	float _public_field_get_deltaRadius() const;
	void _public_field_set_deltaRadius(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::sCCParticle::ModeB)
Q_DECLARE_METATYPE(cocos2d::sCCParticle::ModeB *)
Q_DECLARE_METATYPE(const cocos2d::sCCParticle::ModeB *)

namespace cocos2d {
class QtScriptsCCParticle final : public QtScriptBaseClassPrototype<sCCParticle, false>
{
	Q_OBJECT

protected:
	explicit QtScriptsCCParticle(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptsCCParticle(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCPoint pos READ _public_field_get_pos WRITE _public_field_set_pos)
	cocos2d::CCPoint _public_field_get_pos() const;
	void _public_field_set_pos(const cocos2d::CCPoint& value);
	Q_PROPERTY(cocos2d::CCPoint startPos READ _public_field_get_startPos WRITE _public_field_set_startPos)
	cocos2d::CCPoint _public_field_get_startPos() const;
	void _public_field_set_startPos(const cocos2d::CCPoint& value);
	Q_PROPERTY(cocos2d::_ccColor4F color READ _public_field_get_color WRITE _public_field_set_color)
	cocos2d::_ccColor4F _public_field_get_color() const;
	void _public_field_set_color(const cocos2d::_ccColor4F& value);
	Q_PROPERTY(cocos2d::_ccColor4F deltaColor READ _public_field_get_deltaColor WRITE _public_field_set_deltaColor)
	cocos2d::_ccColor4F _public_field_get_deltaColor() const;
	void _public_field_set_deltaColor(const cocos2d::_ccColor4F& value);
	Q_PROPERTY(float size READ _public_field_get_size WRITE _public_field_set_size)
	float _public_field_get_size() const;
	void _public_field_set_size(float value);
	Q_PROPERTY(float deltaSize READ _public_field_get_deltaSize WRITE _public_field_set_deltaSize)
	float _public_field_get_deltaSize() const;
	void _public_field_set_deltaSize(float value);
	Q_PROPERTY(float rotation READ _public_field_get_rotation WRITE _public_field_set_rotation)
	float _public_field_get_rotation() const;
	void _public_field_set_rotation(float value);
	Q_PROPERTY(float deltaRotation READ _public_field_get_deltaRotation WRITE _public_field_set_deltaRotation)
	float _public_field_get_deltaRotation() const;
	void _public_field_set_deltaRotation(float value);
	Q_PROPERTY(float timeToLive READ _public_field_get_timeToLive WRITE _public_field_set_timeToLive)
	float _public_field_get_timeToLive() const;
	void _public_field_set_timeToLive(float value);
	Q_PROPERTY(unsigned int atlasIndex READ _public_field_get_atlasIndex WRITE _public_field_set_atlasIndex)
	unsigned int _public_field_get_atlasIndex() const;
	void _public_field_set_atlasIndex(unsigned int value);
	Q_PROPERTY(cocos2d::sCCParticle::ModeA modeA READ _public_field_get_modeA WRITE _public_field_set_modeA)
	cocos2d::sCCParticle::ModeA _public_field_get_modeA() const;
	void _public_field_set_modeA(const cocos2d::sCCParticle::ModeA& value);
	Q_PROPERTY(cocos2d::sCCParticle::ModeB modeB READ _public_field_get_modeB WRITE _public_field_set_modeB)
	cocos2d::sCCParticle::ModeB _public_field_get_modeB() const;
	void _public_field_set_modeB(const cocos2d::sCCParticle::ModeB& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::sCCParticle)
Q_DECLARE_METATYPE(cocos2d::sCCParticle *)
Q_DECLARE_METATYPE(const cocos2d::sCCParticle *)

namespace cocos2d {
class QtScriptCCParticleSystem : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleSystem(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleSystem(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CCPoint posVar READ getPosVar WRITE setPosVar)
	Q_PROPERTY(float rotatePerSecondVar READ getRotatePerSecondVar WRITE setRotatePerSecondVar)
	Q_PROPERTY(float tangentialAccel READ getTangentialAccel WRITE setTangentialAccel)
	Q_PROPERTY(float startRadius READ getStartRadius WRITE setStartRadius)
	Q_PROPERTY(float rotatePerSecond READ getRotatePerSecond WRITE setRotatePerSecond)
	Q_PROPERTY(float endSize READ getEndSize WRITE setEndSize)
	Q_PROPERTY(float endRadius READ getEndRadius WRITE setEndRadius)
	Q_PROPERTY(cocos2d::_ccColor4F endColor READ getEndColor WRITE setEndColor)
	Q_PROPERTY(float startSpin READ getStartSpin WRITE setStartSpin)
	Q_PROPERTY(float duration READ getDuration WRITE setDuration)
	Q_PROPERTY(cocos2d::CCTexture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(int positionType READ getPositionType WRITE setPositionType)
	Q_PROPERTY(float lifeVar READ getLifeVar WRITE setLifeVar)
	Q_PROPERTY(unsigned int totalParticles READ getTotalParticles WRITE setTotalParticles)
	Q_PROPERTY(cocos2d::_ccColor4F endColorVar READ getEndColorVar WRITE setEndColorVar)
	Q_PROPERTY(float startSpinVar READ getStartSpinVar WRITE setStartSpinVar)
	Q_PROPERTY(unsigned int atlasIndex READ getAtlasIndex WRITE setAtlasIndex)
	Q_PROPERTY(float tangentialAccelVar READ getTangentialAccelVar WRITE setTangentialAccelVar)
	Q_PROPERTY(float endRadiusVar READ getEndRadiusVar WRITE setEndRadiusVar)
	Q_PROPERTY(float radialAccelVar READ getRadialAccelVar WRITE setRadialAccelVar)
	Q_PROPERTY(float startSize READ getStartSize WRITE setStartSize)
	Q_PROPERTY(float speed READ getSpeed WRITE setSpeed)
	Q_PROPERTY(int emitterMode READ getEmitterMode WRITE setEmitterMode)
	Q_PROPERTY(cocos2d::CCPoint sourcePosition READ getSourcePosition WRITE setSourcePosition)
	Q_PROPERTY(bool blendAdditive READ isBlendAdditive WRITE setBlendAdditive)
	Q_PROPERTY(float life READ getLife WRITE setLife)
	Q_PROPERTY(float angleVar READ getAngleVar WRITE setAngleVar)
	Q_PROPERTY(bool rotationIsDir READ getRotationIsDir WRITE setRotationIsDir)
	Q_PROPERTY(float endSizeVar READ getEndSizeVar WRITE setEndSizeVar)
	Q_PROPERTY(float angle READ getAngle WRITE setAngle)
	Q_PROPERTY(cocos2d::CCParticleBatchNode* batchNode READ getBatchNode WRITE setBatchNode)
	Q_PROPERTY(float endSpinVar READ getEndSpinVar WRITE setEndSpinVar)
	Q_PROPERTY(cocos2d::_ccColor4F startColor READ getStartColor WRITE setStartColor)
	Q_PROPERTY(float speedVar READ getSpeedVar WRITE setSpeedVar)
	Q_PROPERTY(bool autoRemoveOnFinish READ isAutoRemoveOnFinish WRITE setAutoRemoveOnFinish)
	Q_PROPERTY(cocos2d::CCPoint gravity READ getGravity WRITE setGravity)
	Q_PROPERTY(float emissionRate READ getEmissionRate WRITE setEmissionRate)
	Q_PROPERTY(float startSizeVar READ getStartSizeVar WRITE setStartSizeVar)
	Q_PROPERTY(bool opacityModifyRGB READ getOpacityModifyRGB WRITE setOpacityModifyRGB)
	Q_PROPERTY(cocos2d::_ccColor4F startColorVar READ getStartColorVar WRITE setStartColorVar)
	Q_PROPERTY(float endSpin READ getEndSpin WRITE setEndSpin)
	Q_PROPERTY(float radialAccel READ getRadialAccel WRITE setRadialAccel)
	Q_PROPERTY(float startRadiusVar READ getStartRadiusVar WRITE setStartRadiusVar)
	Q_PROPERTY(cocos2d::_ccBlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	float getStartSizeVar();
	cocos2d::CCTexture2D* getTexture();
	Q_INVOKABLE bool isFull();
	cocos2d::CCParticleBatchNode* getBatchNode();
	cocos2d::_ccColor4F getStartColor();
	int getPositionType();
	void setPosVar(const cocos2d::CCPoint& var);
	float getEndSpin();
	void setRotatePerSecondVar(float degrees);
	float getStartSpinVar();
	float getRadialAccelVar();
	Q_INVOKABLE void stopSystem();
	float getEndSizeVar();
	void setTangentialAccel(float t);
	float getRadialAccel();
	void setStartRadius(float startRadius);
	void setRotatePerSecond(float degrees);
	void setEndSize(float var);
	cocos2d::CCPoint getGravity();
	float getTangentialAccel();
	void setEndRadius(float endRadius);
	float getAngle();
	float getSpeed();
	void setEndColor(const cocos2d::_ccColor4F& var);
	void setStartSpin(float var);
	void setDuration(float var);
	Q_INVOKABLE bool initWithTotalParticles(unsigned int numberOfParticles);
	void setTexture(cocos2d::CCTexture2D* var);
	cocos2d::CCPoint getPosVar();
	Q_INVOKABLE void updateWithNoTime();
	bool isBlendAdditive();
	float getAngleVar();
	void setPositionType(int var);
	float getEndRadius();
	cocos2d::CCPoint getSourcePosition();
	void setLifeVar(float var);
	void setTotalParticles(unsigned int var);
	void setEndColorVar(const cocos2d::_ccColor4F& var);
	Q_INVOKABLE void updateQuadWithParticle(cocos2d::sCCParticle* particle, const cocos2d::CCPoint& newPosition);
	unsigned int getAtlasIndex();
	float getStartSize();
	void setStartSpinVar(float var);
	Q_INVOKABLE void resetSystem();
	void setAtlasIndex(unsigned int var);
	void setTangentialAccelVar(float t);
	void setEndRadiusVar(float endRadiusVar);
	Q_INVOKABLE bool isActive();
	void setRadialAccelVar(float t);
	void setStartSize(float var);
	void setSpeed(float speed);
	float getStartSpin();
	float getRotatePerSecond();
	Q_INVOKABLE void initParticle(cocos2d::sCCParticle* particle);
	void setEmitterMode(int var);
	float getDuration();
	void setSourcePosition(const cocos2d::CCPoint& var);
	float getEndSpinVar();
	void setBlendAdditive(bool value);
	void setLife(float var);
	void setAngleVar(float var);
	void setRotationIsDir(bool t);
	void setEndSizeVar(float var);
	void setAngle(float var);
	void setBatchNode(cocos2d::CCParticleBatchNode* var);
	float getTangentialAccelVar();
	int getEmitterMode();
	void setEndSpinVar(float var);
	Q_INVOKABLE bool initWithFile(const QByteArray& plistFile);
	float getSpeedVar();
	void setStartColor(const cocos2d::_ccColor4F& var);
	float getRotatePerSecondVar();
	float getEndSize();
	float getLife();
	void setSpeedVar(float speed);
	void setAutoRemoveOnFinish(bool var);
	void setGravity(const cocos2d::CCPoint& g);
	Q_INVOKABLE void postStep();
	void setEmissionRate(float var);
	cocos2d::_ccColor4F getEndColorVar();
	bool getRotationIsDir();
	float getEmissionRate();
	cocos2d::_ccColor4F getEndColor();
	float getLifeVar();
	void setStartSizeVar(float var);
	void setOpacityModifyRGB(bool var);
	Q_INVOKABLE bool addParticle();
	bool getOpacityModifyRGB();
	float getStartRadius();
	Q_INVOKABLE unsigned int getParticleCount();
	float getStartRadiusVar();
	cocos2d::_ccBlendFunc getBlendFunc();
	void setStartColorVar(const cocos2d::_ccColor4F& var);
	void setEndSpin(float var);
	void setRadialAccel(float t);
	Q_INVOKABLE bool initWithDictionary(cocos2d::CCDictionary* dictionary);
	Q_INVOKABLE bool initWithDictionary(cocos2d::CCDictionary* dictionary, const QByteArray& dirname);
	bool isAutoRemoveOnFinish();
	unsigned int getTotalParticles();
	void setStartRadiusVar(float startRadiusVar);
	void setBlendFunc(cocos2d::_ccBlendFunc var);
	float getEndRadiusVar();
	cocos2d::_ccColor4F getStartColorVar();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(bool bTransformSystemDirty READ _public_field_get_bTransformSystemDirty WRITE _public_field_set_bTransformSystemDirty)
	bool _public_field_get_bTransformSystemDirty() const;
	void _public_field_set_bTransformSystemDirty(const bool& value);
	Q_PROPERTY(unsigned int uAllocatedParticles READ _public_field_get_uAllocatedParticles WRITE _public_field_set_uAllocatedParticles)
	unsigned int _public_field_get_uAllocatedParticles() const;
	void _public_field_set_uAllocatedParticles(unsigned int value);
	Q_PROPERTY(bool bIsActive READ _public_field_get_bIsActive WRITE _public_field_set_bIsActive)
	bool _public_field_get_bIsActive() const;
	void _public_field_set_bIsActive(const bool& value);
	Q_PROPERTY(bool bIsBlendAdditive READ _public_field_get_bIsBlendAdditive WRITE _public_field_set_bIsBlendAdditive)
	bool _public_field_get_bIsBlendAdditive() const;
	void _public_field_set_bIsBlendAdditive(const bool& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleSystem *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleSystem *)

namespace cocos2d {
class QtScriptCCParticleSystemQuad : public QtScriptCCParticleSystem
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleSystemQuad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleSystemQuad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setDisplayFrame(cocos2d::CCSpriteFrame* spriteFrame);
	Q_INVOKABLE void initTexCoordsWithRect(const cocos2d::CCRect& rect);
	Q_INVOKABLE void setTextureWithRect(cocos2d::CCTexture2D* texture, const cocos2d::CCRect& rect);
	Q_INVOKABLE void initIndices();
	Q_INVOKABLE void listenBackToForeground(cocos2d::CCObject* obj);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleSystemQuad *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleSystemQuad *)

namespace cocos2d {
class QtScriptCCParticleFire : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleFire(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleFire(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleFire *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleFire *)

namespace cocos2d {
class QtScriptCCParticleFireworks : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleFireworks(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleFireworks(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleFireworks *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleFireworks *)

namespace cocos2d {
class QtScriptCCParticleSun : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleSun(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleSun(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleSun *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleSun *)

namespace cocos2d {
class QtScriptCCParticleGalaxy : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleGalaxy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleGalaxy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleGalaxy *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleGalaxy *)

namespace cocos2d {
class QtScriptCCParticleFlower : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleFlower(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleFlower(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleFlower *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleFlower *)

namespace cocos2d {
class QtScriptCCParticleMeteor : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleMeteor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleMeteor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleMeteor *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleMeteor *)

namespace cocos2d {
class QtScriptCCParticleSpiral : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleSpiral(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleSpiral(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleSpiral *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleSpiral *)

namespace cocos2d {
class QtScriptCCParticleExplosion : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleExplosion(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleExplosion(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleExplosion *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleExplosion *)

namespace cocos2d {
class QtScriptCCParticleSmoke : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleSmoke(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleSmoke(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleSmoke *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleSmoke *)

namespace cocos2d {
class QtScriptCCParticleSnow : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleSnow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleSnow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleSnow *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleSnow *)

namespace cocos2d {
class QtScriptCCParticleRain : public QtScriptCCParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptCCParticleRain(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParticleRain(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParticleRain *)
Q_DECLARE_METATYPE(const cocos2d::CCParticleRain *)

namespace cocos2d {
class QtScriptCCDevice : public QtScriptBaseClassPrototype<CCDevice *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCDevice(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCDevice(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue getDPI(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCDevice::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCDevice *)
Q_DECLARE_METATYPE(const cocos2d::CCDevice *)

namespace cocos2d {
class QtScriptCCFileUtils : public QtScriptTypeInfo
{
	Q_OBJECT

protected:
	explicit QtScriptCCFileUtils(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCFileUtils(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(std::vector<std::string> searchPaths READ getSearchPaths WRITE setSearchPaths)
	Q_PROPERTY(std::vector<std::string> searchResolutionsOrder READ getSearchResolutionsOrder WRITE setSearchResolutionsOrder)
	Q_PROPERTY(bool popupNotify READ isPopupNotify WRITE setPopupNotify)
	bool isPopupNotify();
	Q_INVOKABLE void removeSearchPath(const QByteArray& path);
	Q_INVOKABLE QByteArray fullPathForFilename(const QByteArray& pszFileName);
	Q_INVOKABLE QByteArray fullPathFromRelativeFile(const QByteArray& pszFilename, const QByteArray& pszRelativeFile);
	Q_INVOKABLE QByteArray getFileData(const QByteArray& pszFileName, const QByteArray& pszMode, unsigned long* pSize);
	void setSearchPaths(const std::vector<std::string>& searchPaths);
	Q_INVOKABLE void setFilenameLookupDictionary(cocos2d::CCDictionary* pFilenameLookupDict);
	Q_INVOKABLE void addSearchResolutionsOrder(const QByteArray& order);
	Q_INVOKABLE QByteArray getFileDataFromZip(const QByteArray& pszZipFilePath, const QByteArray& pszFileName, unsigned long* pSize);
	Q_INVOKABLE long getClassTypeInfo();
	Q_INVOKABLE void removeAllPaths();
	void setSearchResolutionsOrder(const std::vector<std::string>& searchResolutionsOrder);
	Q_INVOKABLE void purgeCachedEntries();
	Q_INVOKABLE bool isAbsolutePath(const QByteArray& strPath);
	Q_INVOKABLE void addSearchPath(const QByteArray& path);
	Q_INVOKABLE void loadFilenameLookupDictionaryFromFile(const QByteArray& filename);
	std::vector<std::string> getSearchPaths();
	std::vector<std::string> getSearchResolutionsOrder();
	void setPopupNotify(bool bNotify);
	static QScriptValue purgeFileUtils(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue sharedFileUtils(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCFileUtils *)
Q_DECLARE_METATYPE(const cocos2d::CCFileUtils *)

namespace cocos2d {
class QtScriptCCImage : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCImage(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCImage(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int getDataLen();
	Q_INVOKABLE bool saveToFile(const QByteArray& pszFilePath);
	Q_INVOKABLE bool saveToFile(const QByteArray& pszFilePath, bool bIsToRGB);
	Q_INVOKABLE bool isPremultipliedAlpha();
	Q_INVOKABLE unsigned short getHeight();
	Q_INVOKABLE bool initWithString(const QByteArray& pText);
	Q_INVOKABLE bool initWithString(const QByteArray& pText, int nWidth);
	Q_INVOKABLE bool initWithString(const QByteArray& pText, int nWidth, int nHeight);
	Q_INVOKABLE bool initWithString(const QByteArray& pText, int nWidth, int nHeight, int eAlignMask);
	Q_INVOKABLE bool initWithString(const QByteArray& pText, int nWidth, int nHeight, int eAlignMask, const QByteArray& pFontName);
	Q_INVOKABLE bool initWithString(const QByteArray& pText, int nWidth, int nHeight, int eAlignMask, const QByteArray& pFontName, int nSize);
	Q_INVOKABLE bool hasAlpha();
	Q_INVOKABLE bool initWithImageFile(const QByteArray& strPath);
	Q_INVOKABLE bool initWithImageFile(const QByteArray& strPath, int imageType);
	Q_INVOKABLE unsigned short getWidth();
	Q_INVOKABLE int getBitsPerComponent();
	Q_INVOKABLE QByteArray getData();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCImage *)
Q_DECLARE_METATYPE(const cocos2d::CCImage *)

namespace cocos2d {
class QtScriptCCThread final : public QtScriptBaseClassPrototype<CCThread, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCThread(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCThread(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void createAutoreleasePool();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCThread)
Q_DECLARE_METATYPE(cocos2d::CCThread *)
Q_DECLARE_METATYPE(const cocos2d::CCThread *)

namespace cocos2d {
class QtScriptcc_timeval final : public QtScriptBaseClassPrototype<cc_timeval, false>
{
	Q_OBJECT

protected:
	explicit QtScriptcc_timeval(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptcc_timeval(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cc_time_t tv_sec READ _public_field_get_tv_sec WRITE _public_field_set_tv_sec)
	cc_time_t _public_field_get_tv_sec() const;
	void _public_field_set_tv_sec(cc_time_t value);
	Q_PROPERTY(int32_t tv_usec READ _public_field_get_tv_usec WRITE _public_field_set_tv_usec)
	int32_t _public_field_get_tv_usec() const;
	void _public_field_set_tv_usec(int32_t value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::cc_timeval)
Q_DECLARE_METATYPE(cocos2d::cc_timeval *)
Q_DECLARE_METATYPE(const cocos2d::cc_timeval *)

namespace cocos2d {
class QtScriptCCTime final : public QtScriptBaseClassPrototype<CCTime, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCTime(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTime(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue currentTimeSeconds(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue gettimeofday(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue deltaTime(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTime)
Q_DECLARE_METATYPE(cocos2d::CCTime *)
Q_DECLARE_METATYPE(const cocos2d::CCTime *)

namespace cocos2d {
class QtScriptCCApplicationProtocol : public QtScriptBaseClassPrototype<CCApplicationProtocol *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCApplicationProtocol(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCApplicationProtocol(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCApplicationProtocol::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCApplicationProtocol *)
Q_DECLARE_METATYPE(const cocos2d::CCApplicationProtocol *)

namespace cocos2d {
class QtScriptCCApplication : public QtScriptCCApplicationProtocol
{
	Q_OBJECT

protected:
	explicit QtScriptCCApplication(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCApplication(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray startupScriptFilename READ getStartupScriptFilename WRITE setStartupScriptFilename)
	void setStartupScriptFilename(const QByteArray& startupScriptFile);
	Q_INVOKABLE int getTargetPlatform();
	QByteArray getStartupScriptFilename();
	Q_INVOKABLE void setAnimationInterval(double interval);
	Q_INVOKABLE int getCurrentLanguage();
	static QScriptValue sharedApplication(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCApplication *)
Q_DECLARE_METATYPE(const cocos2d::CCApplication *)

namespace cocos2d {
class QtScriptCCEGLViewProtocol : public QtScriptBaseClassPrototype<CCEGLViewProtocol *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCEGLViewProtocol(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEGLViewProtocol(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray viewName READ getViewName WRITE setViewName)
	Q_INVOKABLE cocos2d::CCRect getViewPortRect();
	Q_INVOKABLE cocos2d::CCSize getFrameSize();
	void setViewName(const QByteArray& pszViewName);
	Q_INVOKABLE float getScaleY();
	Q_INVOKABLE float getScaleX();
	Q_INVOKABLE cocos2d::CCPoint getVisibleOrigin();
	Q_INVOKABLE cocos2d::CCSize getVisibleSize();
	Q_INVOKABLE cocos2d::CCSize getDesignResolutionSize();
	QByteArray getViewName();
	Q_INVOKABLE cocos2d::CCRect getScissorRect();
	Q_INVOKABLE bool isScissorEnabled();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCEGLViewProtocol::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCEGLViewProtocol *)
Q_DECLARE_METATYPE(const cocos2d::CCEGLViewProtocol *)

namespace cocos2d {
class QtScriptCCEGLView : public QtScriptCCEGLViewProtocol
{
	Q_OBJECT

protected:
	explicit QtScriptCCEGLView(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCEGLView(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setIMEKeyboardState(bool bOpen);
	Q_INVOKABLE bool isOpenGLReady();
	static QScriptValue sharedOpenGLView(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCEGLView *)
Q_DECLARE_METATYPE(const cocos2d::CCEGLView *)

namespace cocos2d {
class QtScriptCCShaderCache : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCShaderCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCShaderCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void reloadDefaultShaders();
	Q_INVOKABLE cocos2d::CCGLProgram* programForKey(const QByteArray& key);
	Q_INVOKABLE void loadDefaultShaders();
	Q_INVOKABLE void addProgram(cocos2d::CCGLProgram* program, const QByteArray& key);
	static QScriptValue purgeSharedShaderCache(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue sharedShaderCache(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCShaderCache *)
Q_DECLARE_METATYPE(const cocos2d::CCShaderCache *)

namespace cocos2d {
class QtScriptCCAnimationCache : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCAnimationCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCAnimationCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addAnimation(cocos2d::CCAnimation* animation, const QByteArray& name);
	Q_INVOKABLE void addAnimationsWithFile(const QByteArray& plist);
	Q_INVOKABLE void removeAnimationByName(const QByteArray& name);
	Q_INVOKABLE bool init();
	Q_INVOKABLE cocos2d::CCAnimation* animationByName(const QByteArray& name);
	Q_INVOKABLE void addAnimationsWithDictionary(cocos2d::CCDictionary* dictionary);
	Q_INVOKABLE void addAnimationsWithDictionary(cocos2d::CCDictionary* dictionary, const QByteArray& plist);
	static QScriptValue sharedAnimationCache(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue purgeSharedAnimationCache(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCAnimationCache *)
Q_DECLARE_METATYPE(const cocos2d::CCAnimationCache *)

namespace cocos2d {
class QtScriptCCSpriteFrameCache : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCSpriteFrameCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCSpriteFrameCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addSpriteFramesWithFile(const QByteArray& pszPlist);
	Q_INVOKABLE void addSpriteFramesWithFile(const QByteArray& plist, const QByteArray& textureFileName);
	Q_INVOKABLE void addSpriteFrame(cocos2d::CCSpriteFrame* pobFrame, const QByteArray& pszFrameName);
	Q_INVOKABLE cocos2d::CCSpriteFrame* spriteFrameByName(const QByteArray& pszName);
	Q_INVOKABLE void removeUnusedSpriteFrames();
	Q_INVOKABLE void removeSpriteFramesFromFile(const QByteArray& plist);
	Q_INVOKABLE bool init();
	Q_INVOKABLE void removeSpriteFrames();
	Q_INVOKABLE void removeSpriteFramesFromTexture(cocos2d::CCTexture2D* texture);
	Q_INVOKABLE void removeSpriteFrameByName(const QByteArray& pszName);
	static QScriptValue purgeSharedSpriteFrameCache(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue sharedSpriteFrameCache(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCSpriteFrameCache *)
Q_DECLARE_METATYPE(const cocos2d::CCSpriteFrameCache *)

namespace cocos2d {
class QtScriptCCNotificationCenter : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCNotificationCenter(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCNotificationCenter(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void postNotification(const QByteArray& name);
	Q_INVOKABLE void postNotification(const QByteArray& name, cocos2d::CCObject* object);
	Q_INVOKABLE void removeObserver(cocos2d::CCObject* target, const QByteArray& name);
	Q_INVOKABLE void registerObserver(cocos2d::CCObject* arg0, const QScriptValue& arg1, const QByteArray& arg2);
	Q_INVOKABLE int getObserverHandlerByName(const QByteArray& name);
	Q_INVOKABLE void unregisterScriptObserver(cocos2d::CCObject* target, const QByteArray& name);
	Q_INVOKABLE int removeAllObservers(cocos2d::CCObject* target);
	static QScriptValue sharedNotificationCenter(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue purgeNotificationCenter(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCNotificationCenter *)
Q_DECLARE_METATYPE(const cocos2d::CCNotificationCenter *)

namespace cocos2d {
class QtScriptCCNotificationObserver : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCNotificationObserver(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCNotificationObserver(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int64_t handler READ getHandler WRITE setHandler)
	Q_INVOKABLE void performSelector(cocos2d::CCObject* obj);
	Q_INVOKABLE QByteArray getName();
	Q_INVOKABLE cocos2d::CCObject* getTarget();
	Q_INVOKABLE cocos2d::CCObject* getObject();
	int64_t getHandler();
	void setHandler(int64_t var);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCNotificationObserver *)
Q_DECLARE_METATYPE(const cocos2d::CCNotificationObserver *)

namespace cocos2d {
class QtScriptCCProfiler : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCProfiler(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCProfiler(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void displayTimers();
	Q_INVOKABLE bool init();
	Q_INVOKABLE void releaseTimer(const QByteArray& timerName);
	Q_INVOKABLE void releaseAllTimers();
	Q_INVOKABLE cocos2d::CCProfilingTimer* createAndAddTimerWithName(const QByteArray& timerName);
	static QScriptValue sharedProfiler(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(cocos2d::CCDictionary* pActiveTimers READ _public_field_get_pActiveTimers WRITE _public_field_set_pActiveTimers)
	cocos2d::CCDictionary* _public_field_get_pActiveTimers() const;
	void _public_field_set_pActiveTimers(cocos2d::CCDictionary* value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCProfiler *)
Q_DECLARE_METATYPE(const cocos2d::CCProfiler *)

namespace cocos2d {
class QtScriptCCProfilingTimer : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCProfilingTimer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCProfilingTimer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void reset();
	Q_INVOKABLE bool initWithName(const QByteArray& timerName);
	Q_INVOKABLE QByteArray description();
	Q_INVOKABLE cocos2d::cc_timeval* getStartTime();
	Q_PROPERTY(QByteArray nameStr READ _public_field_get_nameStr WRITE _public_field_set_nameStr)
	QByteArray _public_field_get_nameStr() const;
	void _public_field_set_nameStr(const QByteArray& value);
	Q_PROPERTY(int numberOfCalls READ _public_field_get_numberOfCalls WRITE _public_field_set_numberOfCalls)
	int _public_field_get_numberOfCalls() const;
	void _public_field_set_numberOfCalls(int value);
	Q_PROPERTY(int dAverageTime1 READ _public_field_get_dAverageTime1 WRITE _public_field_set_dAverageTime1)
	int _public_field_get_dAverageTime1() const;
	void _public_field_set_dAverageTime1(int value);
	Q_PROPERTY(int dAverageTime2 READ _public_field_get_dAverageTime2 WRITE _public_field_set_dAverageTime2)
	int _public_field_get_dAverageTime2() const;
	void _public_field_set_dAverageTime2(int value);
	Q_PROPERTY(long long totalTime READ _public_field_get_totalTime WRITE _public_field_set_totalTime)
	long long _public_field_get_totalTime() const;
	void _public_field_set_totalTime(long long value);
	Q_PROPERTY(int minTime READ _public_field_get_minTime WRITE _public_field_set_minTime)
	int _public_field_get_minTime() const;
	void _public_field_set_minTime(int value);
	Q_PROPERTY(int maxTime READ _public_field_get_maxTime WRITE _public_field_set_maxTime)
	int _public_field_get_maxTime() const;
	void _public_field_set_maxTime(int value);
	Q_PROPERTY(cocos2d::cc_timeval sStartTime READ _public_field_get_sStartTime WRITE _public_field_set_sStartTime)
	cocos2d::cc_timeval _public_field_get_sStartTime() const;
	void _public_field_set_sStartTime(const cocos2d::cc_timeval& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCProfilingTimer *)
Q_DECLARE_METATYPE(const cocos2d::CCProfilingTimer *)

namespace cocos2d {
class QtScriptCCUserDefault : public QtScriptBaseClassPrototype<CCUserDefault *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCUserDefault(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCUserDefault(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setIntegerForKey(const QByteArray& pKey, int value);
	Q_INVOKABLE float getFloatForKey(const QByteArray& pKey);
	Q_INVOKABLE float getFloatForKey(const QByteArray& pKey, float defaultValue);
	Q_INVOKABLE bool getBoolForKey(const QByteArray& pKey);
	Q_INVOKABLE bool getBoolForKey(const QByteArray& pKey, bool defaultValue);
	Q_INVOKABLE void setDoubleForKey(const QByteArray& pKey, double value);
	Q_INVOKABLE void setFloatForKey(const QByteArray& pKey, float value);
	Q_INVOKABLE QByteArray getStringForKey(const QByteArray& pKey);
	Q_INVOKABLE QByteArray getStringForKey(const QByteArray& pKey, const QByteArray& defaultValue);
	Q_INVOKABLE void setStringForKey(const QByteArray& pKey, const QByteArray& value);
	Q_INVOKABLE void flush();
	Q_INVOKABLE int getIntegerForKey(const QByteArray& pKey);
	Q_INVOKABLE int getIntegerForKey(const QByteArray& pKey, int defaultValue);
	Q_INVOKABLE double getDoubleForKey(const QByteArray& pKey);
	Q_INVOKABLE double getDoubleForKey(const QByteArray& pKey, double defaultValue);
	Q_INVOKABLE void setBoolForKey(const QByteArray& pKey, bool value);
	static QScriptValue purgeSharedUserDefault(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue isXMLFileExist(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getXMLFilePath(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue sharedUserDefault(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCUserDefault::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCUserDefault *)
Q_DECLARE_METATYPE(const cocos2d::CCUserDefault *)

namespace cocos2d {
class QtScriptCCIMEDelegate : public QtScriptBaseClassPrototype<CCIMEDelegate *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCIMEDelegate(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCIMEDelegate(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool detachWithIME();
	Q_INVOKABLE bool attachWithIME();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCIMEDelegate::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCIMEDelegate *)
Q_DECLARE_METATYPE(const cocos2d::CCIMEDelegate *)

namespace cocos2d {
class QtScriptCCIMEDispatcher : public QtScriptBaseClassPrototype<CCIMEDispatcher *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCIMEDispatcher(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCIMEDispatcher(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE QByteArray getContentText();
	Q_INVOKABLE void dispatchDeleteBackward();
	Q_INVOKABLE void dispatchInsertText(const QByteArray& pText, int nLen);
	Q_INVOKABLE void dispatchKeyboardWillShow(cocos2d::CCIMEKeyboardNotificationInfo& info);
	Q_INVOKABLE void dispatchKeyboardDidShow(cocos2d::CCIMEKeyboardNotificationInfo& info);
	Q_INVOKABLE void dispatchKeyboardWillHide(cocos2d::CCIMEKeyboardNotificationInfo& info);
	Q_INVOKABLE void dispatchKeyboardDidHide(cocos2d::CCIMEKeyboardNotificationInfo& info);
	static QScriptValue sharedDispatcher(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCIMEDispatcher::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCIMEDispatcher *)
Q_DECLARE_METATYPE(const cocos2d::CCIMEDispatcher *)

namespace cocos2d {
class QtScriptCCTextFieldDelegate : public QtScriptBaseClassPrototype<CCTextFieldDelegate *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCTextFieldDelegate(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTextFieldDelegate(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool onTextFieldAttachWithIME(cocos2d::CCTextFieldTTF* sender);
	Q_INVOKABLE bool onTextFieldDeleteBackward(cocos2d::CCTextFieldTTF* sender, const QByteArray& delText, int nLen);
	Q_INVOKABLE bool onDraw(cocos2d::CCTextFieldTTF* sender);
	Q_INVOKABLE bool onTextFieldInsertText(cocos2d::CCTextFieldTTF* sender, const QByteArray& text, int nLen);
	Q_INVOKABLE bool onTextFieldDetachWithIME(cocos2d::CCTextFieldTTF* sender);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCTextFieldDelegate::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCTextFieldDelegate *)
Q_DECLARE_METATYPE(const cocos2d::CCTextFieldDelegate *)

namespace cocos2d {
class QtScriptCCTextFieldTTF : public QtScriptCCLabelTTF
{
	Q_OBJECT

protected:
	explicit QtScriptCCTextFieldTTF(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTextFieldTTF(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool secureTextEntry READ isSecureTextEntry WRITE setSecureTextEntry)
	Q_PROPERTY(cocos2d::_ccColor3B colorSpaceHolder READ getColorSpaceHolder WRITE setColorSpaceHolder)
	Q_PROPERTY(cocos2d::CCTextFieldDelegate* delegate READ getDelegate WRITE setDelegate)
	Q_PROPERTY(QByteArray placeHolder READ getPlaceHolder WRITE setPlaceHolder)
	Q_INVOKABLE int getCharCount();
	cocos2d::CCTextFieldDelegate* getDelegate();
	void setSecureTextEntry(bool value);
	cocos2d::_ccColor3B getColorSpaceHolder();
	Q_INVOKABLE bool initWithPlaceHolder(const QByteArray& placeholder, const QByteArray& fontName, float fontSize);
	Q_INVOKABLE bool initWithPlaceHolder(const QByteArray& placeholder, const cocos2d::CCSize& dimensions, int alignment, const QByteArray& fontName, float fontSize);
	void setColorSpaceHolder(const cocos2d::_ccColor3B& color);
	Q_INVOKABLE bool detachWithIME();
	void setDelegate(cocos2d::CCTextFieldDelegate* var);
	void setPlaceHolder(const QByteArray& text);
	bool isSecureTextEntry();
	QByteArray getPlaceHolder();
	Q_INVOKABLE bool attachWithIME();
	static QScriptValue textFieldWithPlaceHolder(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTextFieldTTF *)
Q_DECLARE_METATYPE(const cocos2d::CCTextFieldTTF *)

namespace cocos2d {
class QtScriptCCTextureCache : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCTextureCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTextureCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void dumpCachedTextureInfo();
	Q_INVOKABLE bool reloadTexture(const QByteArray& fileName);
	Q_INVOKABLE cocos2d::CCTexture2D* addETCImage(const QByteArray& filename);
	Q_INVOKABLE QByteArray description();
	Q_INVOKABLE cocos2d::CCTexture2D* addUIImage(cocos2d::CCImage* image, const QByteArray& key);
	Q_INVOKABLE void removeTextureForKey(const QByteArray& textureKeyName);
	Q_INVOKABLE cocos2d::CCTexture2D* textureForKey(const QByteArray& key);
	Q_INVOKABLE cocos2d::CCDictionary* snapshotTextures();
	Q_INVOKABLE cocos2d::CCTexture2D* addPVRImage(const QByteArray& filename);
	Q_INVOKABLE cocos2d::CCTexture2D* addImage(const QByteArray& fileimage);
	Q_INVOKABLE void removeAllTextures();
	Q_INVOKABLE void removeUnusedTextures();
	Q_INVOKABLE void removeTexture(cocos2d::CCTexture2D* texture);
	static QScriptValue sharedTextureCache(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue purgeSharedTextureCache(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue reloadAllTextures(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTextureCache *)
Q_DECLARE_METATYPE(const cocos2d::CCTextureCache *)

namespace cocos2d {
class QtScriptCCParallaxNode : public QtScriptCCNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCParallaxNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCParallaxNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addChild(cocos2d::CCNode* child, unsigned int zOrder, int tag);
	Q_INVOKABLE void addChild(cocos2d::CCNode* child, unsigned int z, const cocos2d::CCPoint& parallaxRatio, const cocos2d::CCPoint& positionOffset);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCParallaxNode *)
Q_DECLARE_METATYPE(const cocos2d::CCParallaxNode *)

namespace cocos2d {
class QtScriptCCTileMapAtlas : public QtScriptCCAtlasNode
{
	Q_OBJECT

protected:
	explicit QtScriptCCTileMapAtlas(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTileMapAtlas(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::sImageTGA* tGAInfo READ getTGAInfo WRITE setTGAInfo)
	Q_INVOKABLE bool initWithTileFile(const QByteArray& tile, const QByteArray& mapFile, int tileWidth, int tileHeight);
	Q_INVOKABLE void releaseMap();
	Q_INVOKABLE cocos2d::_ccColor3B tileAt(const cocos2d::CCPoint& position);
	cocos2d::sImageTGA* getTGAInfo();
	Q_INVOKABLE void setTile(const cocos2d::_ccColor3B& tile, const cocos2d::CCPoint& position);
	void setTGAInfo(cocos2d::sImageTGA* var);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTileMapAtlas *)
Q_DECLARE_METATYPE(const cocos2d::CCTileMapAtlas *)

namespace cocos2d {
class QtScriptccTouchHandlerHelperData final : public QtScriptBaseClassPrototype<ccTouchHandlerHelperData, false>
{
	Q_OBJECT

protected:
	explicit QtScriptccTouchHandlerHelperData(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptccTouchHandlerHelperData(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int type READ _public_field_get_type WRITE _public_field_set_type)
	int _public_field_get_type() const;
	void _public_field_set_type(int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ccTouchHandlerHelperData)
Q_DECLARE_METATYPE(cocos2d::ccTouchHandlerHelperData *)
Q_DECLARE_METATYPE(const cocos2d::ccTouchHandlerHelperData *)

namespace cocos2d {
class QtScriptCCTouchHandler : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCTouchHandler(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTouchHandler(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int priority READ getPriority WRITE setPriority)
	Q_PROPERTY(cocos2d::CCTouchDelegate* delegate READ getDelegate WRITE setDelegate)
	cocos2d::CCTouchDelegate* getDelegate();
	Q_INVOKABLE bool initWithDelegate(cocos2d::CCTouchDelegate* pDelegate, int nPriority);
	int getPriority();
	void setPriority(int nPriority);
	Q_INVOKABLE int getEnabledSelectors();
	void setDelegate(cocos2d::CCTouchDelegate* pDelegate);
	Q_INVOKABLE void setEnalbedSelectors(int nValue);
	static QScriptValue handlerWithDelegate(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTouchHandler *)
Q_DECLARE_METATYPE(const cocos2d::CCTouchHandler *)

namespace cocos2d {
class QtScriptCCStandardTouchHandler : public QtScriptCCTouchHandler
{
	Q_OBJECT

protected:
	explicit QtScriptCCStandardTouchHandler(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCStandardTouchHandler(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue handlerWithDelegate(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCStandardTouchHandler *)
Q_DECLARE_METATYPE(const cocos2d::CCStandardTouchHandler *)

namespace cocos2d {
class QtScriptCCTargetedTouchHandler : public QtScriptCCTouchHandler
{
	Q_OBJECT

protected:
	explicit QtScriptCCTargetedTouchHandler(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTargetedTouchHandler(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool swallowsTouches READ isSwallowsTouches WRITE setSwallowsTouches)
	bool isSwallowsTouches();
	Q_INVOKABLE cocos2d::CCSet* getClaimedTouches();
	void setSwallowsTouches(bool bSwallowsTouches);
	Q_INVOKABLE bool initWithDelegate(cocos2d::CCTouchDelegate* pDelegate, int nPriority, bool bSwallow);
	static QScriptValue handlerWithDelegate(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTargetedTouchHandler *)
Q_DECLARE_METATYPE(const cocos2d::CCTargetedTouchHandler *)

namespace cocos2d {
class QtScriptCCTimer : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCTimer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCTimer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float interval READ getInterval WRITE setInterval)
	void setInterval(float fInterval);
	float getInterval();
	Q_INVOKABLE bool initWithHandler(const QScriptValue& arg0, float arg1);
	static QScriptValue timerWithHandler(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCTimer *)
Q_DECLARE_METATYPE(const cocos2d::CCTimer *)

namespace cocos2d {
class QtScriptCCScheduler : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCScheduler(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCScheduler(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float timeScale READ getTimeScale WRITE setTimeScale)
	Q_INVOKABLE cocos2d::CCSet* pauseAllTargets();
	void setTimeScale(float fTimeScale);
	Q_INVOKABLE void unscheduleUpdateForTarget(const cocos2d::CCObject* pTarget);
	Q_INVOKABLE void scheduleUpdateForTarget(cocos2d::CCObject* pTarget, int nPriority, bool bPaused);
	Q_INVOKABLE unsigned schedule(const QScriptValue& arg0, float arg1, bool arg2);
	Q_INVOKABLE void unscheduleAllWithMinPriority(int nMinPriority);
	Q_INVOKABLE bool isTargetPaused(cocos2d::CCObject* pTarget);
	Q_INVOKABLE void resumeTarget(cocos2d::CCObject* pTarget);
	Q_INVOKABLE void unscheduleScriptEntry(unsigned int uScheduleScriptEntryID);
	Q_INVOKABLE void unscheduleAll();
	Q_INVOKABLE void resumeTargets(cocos2d::CCSet* targetsToResume);
	Q_INVOKABLE void unscheduleAllForTarget(cocos2d::CCObject* pTarget);
	Q_INVOKABLE void pauseTarget(cocos2d::CCObject* pTarget);
	Q_INVOKABLE cocos2d::CCSet* pauseAllTargetsWithMinPriority(int nMinPriority);
	float getTimeScale();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCScheduler *)
Q_DECLARE_METATYPE(const cocos2d::CCScheduler *)

namespace cocos2d {
class QtScriptCCComponent : public QtScriptCCObject
{
	Q_OBJECT

protected:
	explicit QtScriptCCComponent(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCComponent(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
	Q_PROPERTY(QByteArray name READ getName WRITE setName)
	Q_PROPERTY(cocos2d::CCNode* owner READ getOwner WRITE setOwner)
	void setEnabled(bool b);
	Q_INVOKABLE void onEnter();
	Q_INVOKABLE void onExit();
	void setName(const QByteArray& pName);
	bool isEnabled();
	cocos2d::CCNode* getOwner();
	Q_INVOKABLE bool init();
	void setOwner(cocos2d::CCNode* pOwner);
	QByteArray getName();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CCComponent *)
Q_DECLARE_METATYPE(const cocos2d::CCComponent *)

namespace cocos2d {
class QtScriptCCComponentContainer : public QtScriptBaseClassPrototype<CCComponentContainer *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptCCComponentContainer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCCComponentContainer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CCComponent* get(const QByteArray& pName);
	Q_INVOKABLE void visit(float fDelta);
	Q_INVOKABLE bool remove(const QByteArray& pName);
	Q_INVOKABLE void removeAll();
	Q_INVOKABLE bool add(cocos2d::CCComponent* pCom);
	Q_INVOKABLE bool isEmpty();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptCCComponentContainer::StorageType)
Q_DECLARE_METATYPE(cocos2d::CCComponentContainer *)
Q_DECLARE_METATYPE(const cocos2d::CCComponentContainer *)

