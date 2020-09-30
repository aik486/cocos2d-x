#pragma once

#include "js_bindings/manual/QtScriptRef.hpp"
#include "QtScriptBaseClassPrototype.h"
#include "cocos/cocos2d.h"
#include "cocos/renderer/backend/Device.h"
#include "cocos/renderer/backend/Buffer.h"

void qtscript_register_all_cocos2dx(QScriptEngine *engine);

namespace cocos2d {
class QtScriptVec2 final : public QtScriptBaseClassPrototype<Vec2, false>
{
	Q_OBJECT

protected:
	explicit QtScriptVec2(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptVec2(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void add(const cocos2d::Vec2& v);
	Q_INVOKABLE cocos2d::Vec2 added(const cocos2d::Vec2& v);
	Q_INVOKABLE void clamp(const cocos2d::Vec2& min, const cocos2d::Vec2& max);
	Q_INVOKABLE cocos2d::Vec2 compOp(QScriptValue function);
	Q_INVOKABLE float cross(const cocos2d::Vec2& other);
	Q_INVOKABLE bool differs(const cocos2d::Vec2& v);
	Q_INVOKABLE float distance(const cocos2d::Vec2& v);
	Q_INVOKABLE float distanceSquared(const cocos2d::Vec2& v);
	Q_INVOKABLE cocos2d::Vec2 divided(float s);
	Q_INVOKABLE float dot(const cocos2d::Vec2& v);
	Q_INVOKABLE bool equals(const cocos2d::Vec2& v);
	Q_INVOKABLE bool fuzzyEquals(const cocos2d::Vec2& target, float variance);
	Q_INVOKABLE float getAngle();
	Q_INVOKABLE float getAngle(const cocos2d::Vec2& other);
	Q_INVOKABLE cocos2d::Vec2 getClampPoint(const cocos2d::Vec2& min_inclusive, const cocos2d::Vec2& max_inclusive);
	Q_INVOKABLE float getDistance(const cocos2d::Vec2& other);
	Q_INVOKABLE float getDistanceSq(const cocos2d::Vec2& other);
	Q_INVOKABLE float getLength();
	Q_INVOKABLE float getLengthSq();
	Q_INVOKABLE cocos2d::Vec2 getMidpoint(const cocos2d::Vec2& other);
	Q_INVOKABLE cocos2d::Vec2 getNormalized();
	Q_INVOKABLE cocos2d::Vec2 getPerp();
	Q_INVOKABLE cocos2d::Vec2 getRPerp();
	Q_INVOKABLE bool greaterThan(const cocos2d::Vec2& v);
	Q_INVOKABLE bool isOne();
	Q_INVOKABLE bool isZero();
	Q_INVOKABLE float length();
	Q_INVOKABLE float lengthSquared();
	Q_INVOKABLE cocos2d::Vec2 lerp(const cocos2d::Vec2& other, float alpha);
	Q_INVOKABLE bool lessThan(const cocos2d::Vec2& v);
	Q_INVOKABLE void mul(float s);
	Q_INVOKABLE cocos2d::Vec2 multiplied(float s);
	Q_INVOKABLE void negate();
	Q_INVOKABLE cocos2d::Vec2 negated();
	Q_INVOKABLE void normalize();
	Q_INVOKABLE cocos2d::Vec2 project(const cocos2d::Vec2& other);
	Q_INVOKABLE cocos2d::Vec2 rotate(const cocos2d::Vec2& other);
	Q_INVOKABLE void rotate(const cocos2d::Vec2& point, float angle);
	Q_INVOKABLE cocos2d::Vec2 rotateByAngle(const cocos2d::Vec2& pivot, float angle);
	Q_INVOKABLE void scale(float scalar);
	Q_INVOKABLE void set(const cocos2d::Vec2& v);
	Q_INVOKABLE void set(float xx, float yy);
	Q_INVOKABLE void setPoint(float xx, float yy);
	Q_INVOKABLE void setZero();
	Q_INVOKABLE void smooth(const cocos2d::Vec2& target, float elapsedTime, float responseTime);
	Q_INVOKABLE void sub(const cocos2d::Vec2& v);
	Q_INVOKABLE void subtract(const cocos2d::Vec2& v);
	Q_INVOKABLE cocos2d::Vec2 subtracted(const cocos2d::Vec2& v);
	Q_INVOKABLE cocos2d::Vec2 unrotate(const cocos2d::Vec2& other);
	static QScriptValue angle(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue dot(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue forAngle(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getIntersectPoint(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue isLineIntersect(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue isLineOverlap(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue isLineParallel(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue isSegmentIntersect(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue isSegmentOverlap(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(float x READ _public_field_get_x WRITE _public_field_set_x)
	float _public_field_get_x() const;
	void _public_field_set_x(float value);
	Q_PROPERTY(float y READ _public_field_get_y WRITE _public_field_set_y)
	float _public_field_get_y() const;
	void _public_field_set_y(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Vec2)
Q_DECLARE_METATYPE(cocos2d::Vec2 *)
Q_DECLARE_METATYPE(const cocos2d::Vec2 *)

namespace cocos2d {
class QtScriptVec3 final : public QtScriptBaseClassPrototype<Vec3, false>
{
	Q_OBJECT

protected:
	explicit QtScriptVec3(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptVec3(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void add(const cocos2d::Vec3& v);
	Q_INVOKABLE cocos2d::Vec3 added(const cocos2d::Vec3& v);
	Q_INVOKABLE void clamp(const cocos2d::Vec3& min, const cocos2d::Vec3& max);
	Q_INVOKABLE void cross(const cocos2d::Vec3& v);
	Q_INVOKABLE bool differs(const cocos2d::Vec3& v);
	Q_INVOKABLE float distance(const cocos2d::Vec3& v);
	Q_INVOKABLE float distanceSquared(const cocos2d::Vec3& v);
	Q_INVOKABLE cocos2d::Vec3 divided(float s);
	Q_INVOKABLE float dot(const cocos2d::Vec3& v);
	Q_INVOKABLE bool equals(const cocos2d::Vec3& v);
	Q_INVOKABLE cocos2d::Vec3 getNormalized();
	Q_INVOKABLE bool greaterThan(const cocos2d::Vec3& rhs);
	Q_INVOKABLE bool isOne();
	Q_INVOKABLE bool isZero();
	Q_INVOKABLE float length();
	Q_INVOKABLE float lengthSquared();
	Q_INVOKABLE cocos2d::Vec3 lerp(const cocos2d::Vec3& target, float alpha);
	Q_INVOKABLE bool lessThan(const cocos2d::Vec3& rhs);
	Q_INVOKABLE void mul(float s);
	Q_INVOKABLE cocos2d::Vec3 multiplied(float s);
	Q_INVOKABLE void negate();
	Q_INVOKABLE cocos2d::Vec3 negated();
	Q_INVOKABLE void normalize();
	Q_INVOKABLE void scale(float scalar);
	Q_INVOKABLE void set(const cocos2d::Vec3& v);
	Q_INVOKABLE void set(const cocos2d::Vec3& p1, const cocos2d::Vec3& p2);
	Q_INVOKABLE void set(float xx, float yy, float zz);
	Q_INVOKABLE void setZero();
	Q_INVOKABLE void smooth(const cocos2d::Vec3& target, float elapsedTime, float responseTime);
	Q_INVOKABLE void sub(const cocos2d::Vec3& v);
	Q_INVOKABLE void subtract(const cocos2d::Vec3& v);
	Q_INVOKABLE cocos2d::Vec3 subtracted(const cocos2d::Vec3& v);
	static QScriptValue angle(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue dot(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue fromColor(QScriptContext *context, QScriptEngine* engine);
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

Q_DECLARE_METATYPE(cocos2d::Vec3)
Q_DECLARE_METATYPE(cocos2d::Vec3 *)
Q_DECLARE_METATYPE(const cocos2d::Vec3 *)

namespace cocos2d {
class QtScriptVec4 final : public QtScriptBaseClassPrototype<Vec4, false>
{
	Q_OBJECT

protected:
	explicit QtScriptVec4(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptVec4(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void add(const cocos2d::Vec4& v);
	Q_INVOKABLE cocos2d::Vec4 added(const cocos2d::Vec4& v);
	Q_INVOKABLE void clamp(const cocos2d::Vec4& min, const cocos2d::Vec4& max);
	Q_INVOKABLE bool differs(const cocos2d::Vec4& v);
	Q_INVOKABLE float distance(const cocos2d::Vec4& v);
	Q_INVOKABLE float distanceSquared(const cocos2d::Vec4& v);
	Q_INVOKABLE cocos2d::Vec4 divided(float s);
	Q_INVOKABLE float dot(const cocos2d::Vec4& v);
	Q_INVOKABLE bool equals(const cocos2d::Vec4& v);
	Q_INVOKABLE cocos2d::Vec4 getNormalized();
	Q_INVOKABLE bool isOne();
	Q_INVOKABLE bool isZero();
	Q_INVOKABLE float length();
	Q_INVOKABLE float lengthSquared();
	Q_INVOKABLE bool lessThan(const cocos2d::Vec4& v);
	Q_INVOKABLE void mul(float s);
	Q_INVOKABLE cocos2d::Vec4 multiplied(float s);
	Q_INVOKABLE void negate();
	Q_INVOKABLE cocos2d::Vec4 negated();
	Q_INVOKABLE void normalize();
	Q_INVOKABLE void scale(float scalar);
	Q_INVOKABLE void set(const cocos2d::Vec4& v);
	Q_INVOKABLE void set(const cocos2d::Vec4& p1, const cocos2d::Vec4& p2);
	Q_INVOKABLE void set(float xx, float yy, float zz, float ww);
	Q_INVOKABLE void sub(const cocos2d::Vec4& v);
	Q_INVOKABLE void subtract(const cocos2d::Vec4& v);
	Q_INVOKABLE cocos2d::Vec4 subtracted(const cocos2d::Vec4& v);
	static QScriptValue angle(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue dot(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue fromColor(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(float w READ _public_field_get_w WRITE _public_field_set_w)
	float _public_field_get_w() const;
	void _public_field_set_w(float value);
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

Q_DECLARE_METATYPE(cocos2d::Vec4)
Q_DECLARE_METATYPE(cocos2d::Vec4 *)
Q_DECLARE_METATYPE(const cocos2d::Vec4 *)

namespace cocos2d {
class QtScriptMat4 final : public QtScriptBaseClassPrototype<Mat4, false>
{
	Q_OBJECT

protected:
	explicit QtScriptMat4(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMat4(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void add(float scalar);
	Q_INVOKABLE cocos2d::Mat4 added(const cocos2d::Mat4& mat);
	Q_INVOKABLE float determinant();
	Q_INVOKABLE cocos2d::Mat4 getInversed();
	Q_INVOKABLE cocos2d::Mat4 getNegated();
	Q_INVOKABLE cocos2d::Mat4 getTransposed();
	Q_INVOKABLE bool inverse();
	Q_INVOKABLE bool isIdentity();
	Q_INVOKABLE void mul(const cocos2d::Mat4& mat);
	Q_INVOKABLE cocos2d::Mat4 multiplied(const cocos2d::Mat4& mat);
	Q_INVOKABLE void multiply(float scalar);
	Q_INVOKABLE void negate();
	Q_INVOKABLE cocos2d::Mat4 negated();
	Q_INVOKABLE void rotate(const cocos2d::Quaternion& q);
	Q_INVOKABLE void rotateX(float angle);
	Q_INVOKABLE void rotateY(float angle);
	Q_INVOKABLE void rotateZ(float angle);
	Q_INVOKABLE void scale(float value);
	Q_INVOKABLE void scale(float xScale, float yScale, float zScale);
	Q_INVOKABLE void set(const cocos2d::Mat4& mat);
	Q_INVOKABLE void set(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
	Q_INVOKABLE void setIdentity();
	Q_INVOKABLE void setZero();
	Q_INVOKABLE void sub(const cocos2d::Mat4& mat);
	Q_INVOKABLE void subtract(const cocos2d::Mat4& mat);
	Q_INVOKABLE cocos2d::Mat4 subtracted(const cocos2d::Mat4& mat);
	Q_INVOKABLE void translate(const cocos2d::Vec3& t);
	Q_INVOKABLE void translate(float x, float y, float z);
	Q_INVOKABLE void transpose();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Mat4)
Q_DECLARE_METATYPE(cocos2d::Mat4 *)
Q_DECLARE_METATYPE(const cocos2d::Mat4 *)

namespace cocos2d {
class QtScriptQuaternion final : public QtScriptBaseClassPrototype<Quaternion, false>
{
	Q_OBJECT

protected:
	explicit QtScriptQuaternion(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptQuaternion(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void conjugate();
	Q_INVOKABLE cocos2d::Quaternion getConjugated();
	Q_INVOKABLE cocos2d::Quaternion getInversed();
	Q_INVOKABLE cocos2d::Quaternion getNormalized();
	Q_INVOKABLE bool inverse();
	Q_INVOKABLE bool isIdentity();
	Q_INVOKABLE bool isZero();
	Q_INVOKABLE void mul(const cocos2d::Quaternion& q);
	Q_INVOKABLE cocos2d::Quaternion multiplied(const cocos2d::Quaternion& q);
	Q_INVOKABLE void multiply(const cocos2d::Quaternion& q);
	Q_INVOKABLE void normalize();
	Q_INVOKABLE void set(const cocos2d::Mat4& m);
	Q_INVOKABLE void set(const cocos2d::Vec3& axis, float angle);
	Q_INVOKABLE void set(float xx, float yy, float zz, float ww);
	Q_INVOKABLE void setIdentity();
	Q_INVOKABLE float toAxisAngle(cocos2d::Vec3* e);
	Q_INVOKABLE cocos2d::Vec3 vec3Multiplied(const cocos2d::Vec3& v);
	static QScriptValue identity(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue squad(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue zero(QScriptContext *context, QScriptEngine* engine);
	Q_PROPERTY(float w READ _public_field_get_w WRITE _public_field_set_w)
	float _public_field_get_w() const;
	void _public_field_set_w(float value);
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

Q_DECLARE_METATYPE(cocos2d::Quaternion)
Q_DECLARE_METATYPE(cocos2d::Quaternion *)
Q_DECLARE_METATYPE(const cocos2d::Quaternion *)

namespace cocos2d {
class QtScriptSize final : public QtScriptBaseClassPrototype<Size, false>
{
	Q_OBJECT

protected:
	explicit QtScriptSize(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSize(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Size added(const cocos2d::Size& right);
	Q_INVOKABLE cocos2d::Size divided(float a);
	Q_INVOKABLE bool equals(const cocos2d::Size& target);
	Q_INVOKABLE cocos2d::Size multiplied(float a);
	Q_INVOKABLE void set(const cocos2d::Size& other);
	Q_INVOKABLE void setSize(float width, float height);
	Q_INVOKABLE cocos2d::Size subtracted(const cocos2d::Size& right);
	Q_INVOKABLE cocos2d::Vec2 toVec2();
	Q_PROPERTY(float height READ _public_field_get_height WRITE _public_field_set_height)
	float _public_field_get_height() const;
	void _public_field_set_height(float value);
	Q_PROPERTY(float width READ _public_field_get_width WRITE _public_field_set_width)
	float _public_field_get_width() const;
	void _public_field_set_width(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Size)
Q_DECLARE_METATYPE(cocos2d::Size *)
Q_DECLARE_METATYPE(const cocos2d::Size *)

namespace cocos2d {
class QtScriptRect final : public QtScriptBaseClassPrototype<Rect, false>
{
	Q_OBJECT

protected:
	explicit QtScriptRect(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRect(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool containsPoint(const cocos2d::Vec2& point);
	Q_INVOKABLE bool equals(const cocos2d::Rect& rect);
	Q_INVOKABLE float getMaxX();
	Q_INVOKABLE float getMaxY();
	Q_INVOKABLE float getMidX();
	Q_INVOKABLE float getMidY();
	Q_INVOKABLE float getMinX();
	Q_INVOKABLE float getMinY();
	Q_INVOKABLE bool intersectsCircle(const cocos2d::Vec2& center, float radius);
	Q_INVOKABLE bool intersectsRect(const cocos2d::Rect& rect);
	Q_INVOKABLE void merge(const cocos2d::Rect& rect);
	Q_INVOKABLE void set(const cocos2d::Rect& other);
	Q_INVOKABLE void setRect(float x, float y, float width, float height);
	Q_INVOKABLE cocos2d::Rect unionWithRect(const cocos2d::Rect& rect);
	Q_PROPERTY(cocos2d::Vec2 origin READ _public_field_get_origin WRITE _public_field_set_origin)
	cocos2d::Vec2 _public_field_get_origin() const;
	void _public_field_set_origin(const cocos2d::Vec2& value);
	Q_PROPERTY(cocos2d::Size size READ _public_field_get_size WRITE _public_field_set_size)
	cocos2d::Size _public_field_get_size() const;
	void _public_field_set_size(const cocos2d::Size& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Rect)
Q_DECLARE_METATYPE(cocos2d::Rect *)
Q_DECLARE_METATYPE(const cocos2d::Rect *)

namespace cocos2d {
namespace backend {
class QtScriptSamplerDescriptor final : public QtScriptBaseClassPrototype<SamplerDescriptor, false>
{
	Q_OBJECT

protected:
	explicit QtScriptSamplerDescriptor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSamplerDescriptor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int magFilter READ _public_field_get_magFilter WRITE _public_field_set_magFilter)
	int _public_field_get_magFilter() const;
	void _public_field_set_magFilter(int value);
	Q_PROPERTY(int minFilter READ _public_field_get_minFilter WRITE _public_field_set_minFilter)
	int _public_field_get_minFilter() const;
	void _public_field_set_minFilter(int value);
	Q_PROPERTY(int sAddressMode READ _public_field_get_sAddressMode WRITE _public_field_set_sAddressMode)
	int _public_field_get_sAddressMode() const;
	void _public_field_set_sAddressMode(int value);
	Q_PROPERTY(int tAddressMode READ _public_field_get_tAddressMode WRITE _public_field_set_tAddressMode)
	int _public_field_get_tAddressMode() const;
	void _public_field_set_tAddressMode(int value);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::SamplerDescriptor)
Q_DECLARE_METATYPE(cocos2d::backend::SamplerDescriptor *)
Q_DECLARE_METATYPE(const cocos2d::backend::SamplerDescriptor *)

namespace cocos2d {
namespace backend {
class QtScriptUniformInfo final : public QtScriptBaseClassPrototype<UniformInfo, false>
{
	Q_OBJECT

protected:
	explicit QtScriptUniformInfo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptUniformInfo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int bufferOffset READ _public_field_get_bufferOffset WRITE _public_field_set_bufferOffset)
	unsigned int _public_field_get_bufferOffset() const;
	void _public_field_set_bufferOffset(unsigned int value);
	Q_PROPERTY(int count READ _public_field_get_count WRITE _public_field_set_count)
	int _public_field_get_count() const;
	void _public_field_set_count(int value);
	Q_PROPERTY(bool isArray READ _public_field_get_isArray WRITE _public_field_set_isArray)
	bool _public_field_get_isArray() const;
	void _public_field_set_isArray(const bool& value);
	Q_PROPERTY(bool isMatrix READ _public_field_get_isMatrix WRITE _public_field_set_isMatrix)
	bool _public_field_get_isMatrix() const;
	void _public_field_set_isMatrix(const bool& value);
	Q_PROPERTY(int location READ _public_field_get_location WRITE _public_field_set_location)
	int _public_field_get_location() const;
	void _public_field_set_location(int value);
	Q_PROPERTY(bool needConvert READ _public_field_get_needConvert WRITE _public_field_set_needConvert)
	bool _public_field_get_needConvert() const;
	void _public_field_set_needConvert(const bool& value);
	Q_PROPERTY(unsigned int size READ _public_field_get_size WRITE _public_field_set_size)
	unsigned int _public_field_get_size() const;
	void _public_field_set_size(unsigned int value);
	Q_PROPERTY(unsigned int type READ _public_field_get_type WRITE _public_field_set_type)
	unsigned int _public_field_get_type() const;
	void _public_field_set_type(unsigned int value);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::UniformInfo)
Q_DECLARE_METATYPE(cocos2d::backend::UniformInfo *)
Q_DECLARE_METATYPE(const cocos2d::backend::UniformInfo *)

namespace cocos2d {
namespace backend {
class QtScriptUniformLocation final : public QtScriptBaseClassPrototype<UniformLocation, false>
{
	Q_OBJECT

protected:
	explicit QtScriptUniformLocation(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptUniformLocation(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool equals(const cocos2d::backend::UniformLocation& other);
	Q_INVOKABLE size_t id(const cocos2d::backend::UniformLocation& uniform);
	Q_INVOKABLE void reset();
	Q_INVOKABLE bool toBool();
	Q_PROPERTY(int shaderStage READ _public_field_get_shaderStage WRITE _public_field_set_shaderStage)
	int _public_field_get_shaderStage() const;
	void _public_field_set_shaderStage(int value);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::UniformLocation)
Q_DECLARE_METATYPE(cocos2d::backend::UniformLocation *)
Q_DECLARE_METATYPE(const cocos2d::backend::UniformLocation *)

namespace cocos2d {
namespace backend {
class QtScriptAttributeBindInfo final : public QtScriptBaseClassPrototype<AttributeBindInfo, false>
{
	Q_OBJECT

protected:
	explicit QtScriptAttributeBindInfo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAttributeBindInfo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray attributeName READ _public_field_get_attributeName WRITE _public_field_set_attributeName)
	QByteArray _public_field_get_attributeName() const;
	void _public_field_set_attributeName(const QByteArray& value);
	Q_PROPERTY(int location READ _public_field_get_location WRITE _public_field_set_location)
	int _public_field_get_location() const;
	void _public_field_set_location(int value);
	Q_PROPERTY(int size READ _public_field_get_size WRITE _public_field_set_size)
	int _public_field_get_size() const;
	void _public_field_set_size(int value);
	Q_PROPERTY(int type READ _public_field_get_type WRITE _public_field_set_type)
	int _public_field_get_type() const;
	void _public_field_set_type(int value);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::AttributeBindInfo)
Q_DECLARE_METATYPE(cocos2d::backend::AttributeBindInfo *)
Q_DECLARE_METATYPE(const cocos2d::backend::AttributeBindInfo *)

namespace cocos2d {
namespace backend {
class QtScriptBlendDescriptor final : public QtScriptBaseClassPrototype<BlendDescriptor, false>
{
	Q_OBJECT

protected:
	explicit QtScriptBlendDescriptor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBlendDescriptor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int alphaBlendOperation READ _public_field_get_alphaBlendOperation WRITE _public_field_set_alphaBlendOperation)
	int _public_field_get_alphaBlendOperation() const;
	void _public_field_set_alphaBlendOperation(int value);
	Q_PROPERTY(bool blendEnabled READ _public_field_get_blendEnabled WRITE _public_field_set_blendEnabled)
	bool _public_field_get_blendEnabled() const;
	void _public_field_set_blendEnabled(const bool& value);
	Q_PROPERTY(int destinationAlphaBlendFactor READ _public_field_get_destinationAlphaBlendFactor WRITE _public_field_set_destinationAlphaBlendFactor)
	int _public_field_get_destinationAlphaBlendFactor() const;
	void _public_field_set_destinationAlphaBlendFactor(int value);
	Q_PROPERTY(int destinationRGBBlendFactor READ _public_field_get_destinationRGBBlendFactor WRITE _public_field_set_destinationRGBBlendFactor)
	int _public_field_get_destinationRGBBlendFactor() const;
	void _public_field_set_destinationRGBBlendFactor(int value);
	Q_PROPERTY(int rgbBlendOperation READ _public_field_get_rgbBlendOperation WRITE _public_field_set_rgbBlendOperation)
	int _public_field_get_rgbBlendOperation() const;
	void _public_field_set_rgbBlendOperation(int value);
	Q_PROPERTY(int sourceAlphaBlendFactor READ _public_field_get_sourceAlphaBlendFactor WRITE _public_field_set_sourceAlphaBlendFactor)
	int _public_field_get_sourceAlphaBlendFactor() const;
	void _public_field_set_sourceAlphaBlendFactor(int value);
	Q_PROPERTY(int sourceRGBBlendFactor READ _public_field_get_sourceRGBBlendFactor WRITE _public_field_set_sourceRGBBlendFactor)
	int _public_field_get_sourceRGBBlendFactor() const;
	void _public_field_set_sourceRGBBlendFactor(int value);
	Q_PROPERTY(int writeMask READ _public_field_get_writeMask WRITE _public_field_set_writeMask)
	int _public_field_get_writeMask() const;
	void _public_field_set_writeMask(int value);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::BlendDescriptor)
Q_DECLARE_METATYPE(cocos2d::backend::BlendDescriptor *)
Q_DECLARE_METATYPE(const cocos2d::backend::BlendDescriptor *)

namespace cocos2d {
class QtScriptColor3B final : public QtScriptBaseClassPrototype<Color3B, false>
{
	Q_OBJECT

protected:
	explicit QtScriptColor3B(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptColor3B(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool differs(const cocos2d::Color3B& right);
	Q_INVOKABLE bool equals(const cocos2d::Color3B& right);
	Q_PROPERTY(uint8_t b READ _public_field_get_b WRITE _public_field_set_b)
	uint8_t _public_field_get_b() const;
	void _public_field_set_b(uint8_t value);
	Q_PROPERTY(uint8_t g READ _public_field_get_g WRITE _public_field_set_g)
	uint8_t _public_field_get_g() const;
	void _public_field_set_g(uint8_t value);
	Q_PROPERTY(uint8_t r READ _public_field_get_r WRITE _public_field_set_r)
	uint8_t _public_field_get_r() const;
	void _public_field_set_r(uint8_t value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Color3B)
Q_DECLARE_METATYPE(cocos2d::Color3B *)
Q_DECLARE_METATYPE(const cocos2d::Color3B *)

namespace cocos2d {
class QtScriptColor4B final : public QtScriptBaseClassPrototype<Color4B, false>
{
	Q_OBJECT

protected:
	explicit QtScriptColor4B(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptColor4B(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool differs(const cocos2d::Color4B& right);
	Q_INVOKABLE bool equals(const cocos2d::Color4B& right);
	Q_INVOKABLE void set(uint8_t _r, uint8_t _g, uint8_t _b, uint8_t _a);
	Q_PROPERTY(uint8_t a READ _public_field_get_a WRITE _public_field_set_a)
	uint8_t _public_field_get_a() const;
	void _public_field_set_a(uint8_t value);
	Q_PROPERTY(uint8_t b READ _public_field_get_b WRITE _public_field_set_b)
	uint8_t _public_field_get_b() const;
	void _public_field_set_b(uint8_t value);
	Q_PROPERTY(uint8_t g READ _public_field_get_g WRITE _public_field_set_g)
	uint8_t _public_field_get_g() const;
	void _public_field_set_g(uint8_t value);
	Q_PROPERTY(uint8_t r READ _public_field_get_r WRITE _public_field_set_r)
	uint8_t _public_field_get_r() const;
	void _public_field_set_r(uint8_t value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Color4B)
Q_DECLARE_METATYPE(cocos2d::Color4B *)
Q_DECLARE_METATYPE(const cocos2d::Color4B *)

namespace cocos2d {
class QtScriptColor4F final : public QtScriptBaseClassPrototype<Color4F, false>
{
	Q_OBJECT

protected:
	explicit QtScriptColor4F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptColor4F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool differs(const cocos2d::Color4F& right);
	Q_INVOKABLE bool equals(const cocos2d::Color4F& right);
	Q_PROPERTY(float a READ _public_field_get_a WRITE _public_field_set_a)
	float _public_field_get_a() const;
	void _public_field_set_a(float value);
	Q_PROPERTY(float b READ _public_field_get_b WRITE _public_field_set_b)
	float _public_field_get_b() const;
	void _public_field_set_b(float value);
	Q_PROPERTY(float g READ _public_field_get_g WRITE _public_field_set_g)
	float _public_field_get_g() const;
	void _public_field_set_g(float value);
	Q_PROPERTY(float r READ _public_field_get_r WRITE _public_field_set_r)
	float _public_field_get_r() const;
	void _public_field_set_r(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Color4F)
Q_DECLARE_METATYPE(cocos2d::Color4F *)
Q_DECLARE_METATYPE(const cocos2d::Color4F *)

namespace cocos2d {
class QtScriptTex2F final : public QtScriptBaseClassPrototype<Tex2F, false>
{
	Q_OBJECT

protected:
	explicit QtScriptTex2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTex2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float u READ _public_field_get_u WRITE _public_field_set_u)
	float _public_field_get_u() const;
	void _public_field_set_u(float value);
	Q_PROPERTY(float v READ _public_field_get_v WRITE _public_field_set_v)
	float _public_field_get_v() const;
	void _public_field_set_v(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Tex2F)
Q_DECLARE_METATYPE(cocos2d::Tex2F *)
Q_DECLARE_METATYPE(const cocos2d::Tex2F *)

namespace cocos2d {
class QtScriptPointSprite final : public QtScriptBaseClassPrototype<PointSprite, false>
{
	Q_OBJECT

protected:
	explicit QtScriptPointSprite(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptPointSprite(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Color4B color READ _public_field_get_color WRITE _public_field_set_color)
	cocos2d::Color4B _public_field_get_color() const;
	void _public_field_set_color(const cocos2d::Color4B& value);
	Q_PROPERTY(cocos2d::Vec2 pos READ _public_field_get_pos WRITE _public_field_set_pos)
	cocos2d::Vec2 _public_field_get_pos() const;
	void _public_field_set_pos(const cocos2d::Vec2& value);
	Q_PROPERTY(float size READ _public_field_get_size WRITE _public_field_set_size)
	float _public_field_get_size() const;
	void _public_field_set_size(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::PointSprite)
Q_DECLARE_METATYPE(cocos2d::PointSprite *)
Q_DECLARE_METATYPE(const cocos2d::PointSprite *)

namespace cocos2d {
class QtScriptQuad2 final : public QtScriptBaseClassPrototype<Quad2, false>
{
	Q_OBJECT

protected:
	explicit QtScriptQuad2(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptQuad2(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Vec2 bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::Vec2 _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::Vec2& value);
	Q_PROPERTY(cocos2d::Vec2 br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::Vec2 _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::Vec2& value);
	Q_PROPERTY(cocos2d::Vec2 tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::Vec2 _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::Vec2& value);
	Q_PROPERTY(cocos2d::Vec2 tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::Vec2 _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::Vec2& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Quad2)
Q_DECLARE_METATYPE(cocos2d::Quad2 *)
Q_DECLARE_METATYPE(const cocos2d::Quad2 *)

namespace cocos2d {
class QtScriptQuad3 final : public QtScriptBaseClassPrototype<Quad3, false>
{
	Q_OBJECT

protected:
	explicit QtScriptQuad3(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptQuad3(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Vec3 bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::Vec3 _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::Vec3 _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::Vec3 _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::Vec3 _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::Vec3& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Quad3)
Q_DECLARE_METATYPE(cocos2d::Quad3 *)
Q_DECLARE_METATYPE(const cocos2d::Quad3 *)

namespace cocos2d {
class QtScriptV2F_C4B_T2F final : public QtScriptBaseClassPrototype<V2F_C4B_T2F, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV2F_C4B_T2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV2F_C4B_T2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Color4B colors READ _public_field_get_colors WRITE _public_field_set_colors)
	cocos2d::Color4B _public_field_get_colors() const;
	void _public_field_set_colors(const cocos2d::Color4B& value);
	Q_PROPERTY(cocos2d::Tex2F texCoords READ _public_field_get_texCoords WRITE _public_field_set_texCoords)
	cocos2d::Tex2F _public_field_get_texCoords() const;
	void _public_field_set_texCoords(const cocos2d::Tex2F& value);
	Q_PROPERTY(cocos2d::Vec2 vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::Vec2 _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::Vec2& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V2F_C4B_T2F)
Q_DECLARE_METATYPE(cocos2d::V2F_C4B_T2F *)
Q_DECLARE_METATYPE(const cocos2d::V2F_C4B_T2F *)

namespace cocos2d {
class QtScriptV2F_C4B_PF final : public QtScriptBaseClassPrototype<V2F_C4B_PF, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV2F_C4B_PF(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV2F_C4B_PF(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Color4B colors READ _public_field_get_colors WRITE _public_field_set_colors)
	cocos2d::Color4B _public_field_get_colors() const;
	void _public_field_set_colors(const cocos2d::Color4B& value);
	Q_PROPERTY(float pointSize READ _public_field_get_pointSize WRITE _public_field_set_pointSize)
	float _public_field_get_pointSize() const;
	void _public_field_set_pointSize(float value);
	Q_PROPERTY(cocos2d::Vec2 vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::Vec2 _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::Vec2& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V2F_C4B_PF)
Q_DECLARE_METATYPE(cocos2d::V2F_C4B_PF *)
Q_DECLARE_METATYPE(const cocos2d::V2F_C4B_PF *)

namespace cocos2d {
class QtScriptV2F_C4F_T2F final : public QtScriptBaseClassPrototype<V2F_C4F_T2F, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV2F_C4F_T2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV2F_C4F_T2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Color4F colors READ _public_field_get_colors WRITE _public_field_set_colors)
	cocos2d::Color4F _public_field_get_colors() const;
	void _public_field_set_colors(const cocos2d::Color4F& value);
	Q_PROPERTY(cocos2d::Tex2F texCoords READ _public_field_get_texCoords WRITE _public_field_set_texCoords)
	cocos2d::Tex2F _public_field_get_texCoords() const;
	void _public_field_set_texCoords(const cocos2d::Tex2F& value);
	Q_PROPERTY(cocos2d::Vec2 vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::Vec2 _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::Vec2& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V2F_C4F_T2F)
Q_DECLARE_METATYPE(cocos2d::V2F_C4F_T2F *)
Q_DECLARE_METATYPE(const cocos2d::V2F_C4F_T2F *)

namespace cocos2d {
class QtScriptV3F_C4B_T2F final : public QtScriptBaseClassPrototype<V3F_C4B_T2F, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV3F_C4B_T2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV3F_C4B_T2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Color4B colors READ _public_field_get_colors WRITE _public_field_set_colors)
	cocos2d::Color4B _public_field_get_colors() const;
	void _public_field_set_colors(const cocos2d::Color4B& value);
	Q_PROPERTY(cocos2d::Tex2F texCoords READ _public_field_get_texCoords WRITE _public_field_set_texCoords)
	cocos2d::Tex2F _public_field_get_texCoords() const;
	void _public_field_set_texCoords(const cocos2d::Tex2F& value);
	Q_PROPERTY(cocos2d::Vec3 vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::Vec3 _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::Vec3& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V3F_C4B_T2F)
Q_DECLARE_METATYPE(cocos2d::V3F_C4B_T2F *)
Q_DECLARE_METATYPE(const cocos2d::V3F_C4B_T2F *)

namespace cocos2d {
class QtScriptV3F_T2F final : public QtScriptBaseClassPrototype<V3F_T2F, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV3F_T2F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV3F_T2F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Tex2F texCoords READ _public_field_get_texCoords WRITE _public_field_set_texCoords)
	cocos2d::Tex2F _public_field_get_texCoords() const;
	void _public_field_set_texCoords(const cocos2d::Tex2F& value);
	Q_PROPERTY(cocos2d::Vec3 vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::Vec3 _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::Vec3& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V3F_T2F)
Q_DECLARE_METATYPE(cocos2d::V3F_T2F *)
Q_DECLARE_METATYPE(const cocos2d::V3F_T2F *)

namespace cocos2d {
class QtScriptV3F_C4F final : public QtScriptBaseClassPrototype<V3F_C4F, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV3F_C4F(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV3F_C4F(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Color4F colors READ _public_field_get_colors WRITE _public_field_set_colors)
	cocos2d::Color4F _public_field_get_colors() const;
	void _public_field_set_colors(const cocos2d::Color4F& value);
	Q_PROPERTY(cocos2d::Vec3 vertices READ _public_field_get_vertices WRITE _public_field_set_vertices)
	cocos2d::Vec3 _public_field_get_vertices() const;
	void _public_field_set_vertices(const cocos2d::Vec3& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V3F_C4F)
Q_DECLARE_METATYPE(cocos2d::V3F_C4F *)
Q_DECLARE_METATYPE(const cocos2d::V3F_C4F *)

namespace cocos2d {
class QtScriptV2F_C4B_T2F_Triangle final : public QtScriptBaseClassPrototype<V2F_C4B_T2F_Triangle, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV2F_C4B_T2F_Triangle(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV2F_C4B_T2F_Triangle(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::V2F_C4B_T2F a READ _public_field_get_a WRITE _public_field_set_a)
	cocos2d::V2F_C4B_T2F _public_field_get_a() const;
	void _public_field_set_a(const cocos2d::V2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::V2F_C4B_T2F b READ _public_field_get_b WRITE _public_field_set_b)
	cocos2d::V2F_C4B_T2F _public_field_get_b() const;
	void _public_field_set_b(const cocos2d::V2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::V2F_C4B_T2F c READ _public_field_get_c WRITE _public_field_set_c)
	cocos2d::V2F_C4B_T2F _public_field_get_c() const;
	void _public_field_set_c(const cocos2d::V2F_C4B_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V2F_C4B_T2F_Triangle)
Q_DECLARE_METATYPE(cocos2d::V2F_C4B_T2F_Triangle *)
Q_DECLARE_METATYPE(const cocos2d::V2F_C4B_T2F_Triangle *)

namespace cocos2d {
class QtScriptV2F_C4B_T2F_Quad final : public QtScriptBaseClassPrototype<V2F_C4B_T2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV2F_C4B_T2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV2F_C4B_T2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::V2F_C4B_T2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::V2F_C4B_T2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::V2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::V2F_C4B_T2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::V2F_C4B_T2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::V2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::V2F_C4B_T2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::V2F_C4B_T2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::V2F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::V2F_C4B_T2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::V2F_C4B_T2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::V2F_C4B_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V2F_C4B_T2F_Quad)
Q_DECLARE_METATYPE(cocos2d::V2F_C4B_T2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::V2F_C4B_T2F_Quad *)

namespace cocos2d {
class QtScriptV3F_C4B_T2F_Quad final : public QtScriptBaseClassPrototype<V3F_C4B_T2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV3F_C4B_T2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV3F_C4B_T2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::V3F_C4B_T2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::V3F_C4B_T2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::V3F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::V3F_C4B_T2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::V3F_C4B_T2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::V3F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::V3F_C4B_T2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::V3F_C4B_T2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::V3F_C4B_T2F& value);
	Q_PROPERTY(cocos2d::V3F_C4B_T2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::V3F_C4B_T2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::V3F_C4B_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V3F_C4B_T2F_Quad)
Q_DECLARE_METATYPE(cocos2d::V3F_C4B_T2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::V3F_C4B_T2F_Quad *)

namespace cocos2d {
class QtScriptV2F_C4F_T2F_Quad final : public QtScriptBaseClassPrototype<V2F_C4F_T2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV2F_C4F_T2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV2F_C4F_T2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::V2F_C4F_T2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::V2F_C4F_T2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::V2F_C4F_T2F& value);
	Q_PROPERTY(cocos2d::V2F_C4F_T2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::V2F_C4F_T2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::V2F_C4F_T2F& value);
	Q_PROPERTY(cocos2d::V2F_C4F_T2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::V2F_C4F_T2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::V2F_C4F_T2F& value);
	Q_PROPERTY(cocos2d::V2F_C4F_T2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::V2F_C4F_T2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::V2F_C4F_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V2F_C4F_T2F_Quad)
Q_DECLARE_METATYPE(cocos2d::V2F_C4F_T2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::V2F_C4F_T2F_Quad *)

namespace cocos2d {
class QtScriptV3F_T2F_Quad final : public QtScriptBaseClassPrototype<V3F_T2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScriptV3F_T2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptV3F_T2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::V3F_T2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::V3F_T2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::V3F_T2F& value);
	Q_PROPERTY(cocos2d::V3F_T2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::V3F_T2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::V3F_T2F& value);
	Q_PROPERTY(cocos2d::V3F_T2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::V3F_T2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::V3F_T2F& value);
	Q_PROPERTY(cocos2d::V3F_T2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::V3F_T2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::V3F_T2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::V3F_T2F_Quad)
Q_DECLARE_METATYPE(cocos2d::V3F_T2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::V3F_T2F_Quad *)

namespace cocos2d {
class QtScriptBlendFunc final : public QtScriptBaseClassPrototype<BlendFunc, false>
{
	Q_OBJECT

protected:
	explicit QtScriptBlendFunc(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBlendFunc(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool differs(const cocos2d::BlendFunc& a);
	Q_INVOKABLE bool equals(const cocos2d::BlendFunc& a);
	Q_INVOKABLE bool lessThan(const cocos2d::BlendFunc& a);
	Q_PROPERTY(int dst READ _public_field_get_dst WRITE _public_field_set_dst)
	int _public_field_get_dst() const;
	void _public_field_set_dst(int value);
	Q_PROPERTY(int src READ _public_field_get_src WRITE _public_field_set_src)
	int _public_field_get_src() const;
	void _public_field_set_src(int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::BlendFunc)
Q_DECLARE_METATYPE(cocos2d::BlendFunc *)
Q_DECLARE_METATYPE(const cocos2d::BlendFunc *)

namespace cocos2d {
class QtScriptT2F_Quad final : public QtScriptBaseClassPrototype<T2F_Quad, false>
{
	Q_OBJECT

protected:
	explicit QtScriptT2F_Quad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptT2F_Quad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Tex2F bl READ _public_field_get_bl WRITE _public_field_set_bl)
	cocos2d::Tex2F _public_field_get_bl() const;
	void _public_field_set_bl(const cocos2d::Tex2F& value);
	Q_PROPERTY(cocos2d::Tex2F br READ _public_field_get_br WRITE _public_field_set_br)
	cocos2d::Tex2F _public_field_get_br() const;
	void _public_field_set_br(const cocos2d::Tex2F& value);
	Q_PROPERTY(cocos2d::Tex2F tl READ _public_field_get_tl WRITE _public_field_set_tl)
	cocos2d::Tex2F _public_field_get_tl() const;
	void _public_field_set_tl(const cocos2d::Tex2F& value);
	Q_PROPERTY(cocos2d::Tex2F tr READ _public_field_get_tr WRITE _public_field_set_tr)
	cocos2d::Tex2F _public_field_get_tr() const;
	void _public_field_set_tr(const cocos2d::Tex2F& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::T2F_Quad)
Q_DECLARE_METATYPE(cocos2d::T2F_Quad *)
Q_DECLARE_METATYPE(const cocos2d::T2F_Quad *)

namespace cocos2d {
class QtScriptFontShadow final : public QtScriptBaseClassPrototype<FontShadow, false>
{
	Q_OBJECT

protected:
	explicit QtScriptFontShadow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFontShadow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float shadowBlur READ _public_field_get_shadowBlur WRITE _public_field_set_shadowBlur)
	float _public_field_get_shadowBlur() const;
	void _public_field_set_shadowBlur(float value);
	Q_PROPERTY(bool shadowEnabled READ _public_field_get_shadowEnabled WRITE _public_field_set_shadowEnabled)
	bool _public_field_get_shadowEnabled() const;
	void _public_field_set_shadowEnabled(const bool& value);
	Q_PROPERTY(cocos2d::Size shadowOffset READ _public_field_get_shadowOffset WRITE _public_field_set_shadowOffset)
	cocos2d::Size _public_field_get_shadowOffset() const;
	void _public_field_set_shadowOffset(const cocos2d::Size& value);
	Q_PROPERTY(float shadowOpacity READ _public_field_get_shadowOpacity WRITE _public_field_set_shadowOpacity)
	float _public_field_get_shadowOpacity() const;
	void _public_field_set_shadowOpacity(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FontShadow)
Q_DECLARE_METATYPE(cocos2d::FontShadow *)
Q_DECLARE_METATYPE(const cocos2d::FontShadow *)

namespace cocos2d {
class QtScriptFontStroke final : public QtScriptBaseClassPrototype<FontStroke, false>
{
	Q_OBJECT

protected:
	explicit QtScriptFontStroke(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFontStroke(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(uint8_t strokeAlpha READ _public_field_get_strokeAlpha WRITE _public_field_set_strokeAlpha)
	uint8_t _public_field_get_strokeAlpha() const;
	void _public_field_set_strokeAlpha(uint8_t value);
	Q_PROPERTY(cocos2d::Color3B strokeColor READ _public_field_get_strokeColor WRITE _public_field_set_strokeColor)
	cocos2d::Color3B _public_field_get_strokeColor() const;
	void _public_field_set_strokeColor(const cocos2d::Color3B& value);
	Q_PROPERTY(bool strokeEnabled READ _public_field_get_strokeEnabled WRITE _public_field_set_strokeEnabled)
	bool _public_field_get_strokeEnabled() const;
	void _public_field_set_strokeEnabled(const bool& value);
	Q_PROPERTY(float strokeSize READ _public_field_get_strokeSize WRITE _public_field_set_strokeSize)
	float _public_field_get_strokeSize() const;
	void _public_field_set_strokeSize(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FontStroke)
Q_DECLARE_METATYPE(cocos2d::FontStroke *)
Q_DECLARE_METATYPE(const cocos2d::FontStroke *)

namespace cocos2d {
class QtScriptFontDefinition final : public QtScriptBaseClassPrototype<FontDefinition, false>
{
	Q_OBJECT

protected:
	explicit QtScriptFontDefinition(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFontDefinition(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int alignment READ _public_field_get_alignment WRITE _public_field_set_alignment)
	int _public_field_get_alignment() const;
	void _public_field_set_alignment(int value);
	Q_PROPERTY(cocos2d::Size dimensions READ _public_field_get_dimensions WRITE _public_field_set_dimensions)
	cocos2d::Size _public_field_get_dimensions() const;
	void _public_field_set_dimensions(const cocos2d::Size& value);
	Q_PROPERTY(bool enableWrap READ _public_field_get_enableWrap WRITE _public_field_set_enableWrap)
	bool _public_field_get_enableWrap() const;
	void _public_field_set_enableWrap(const bool& value);
	Q_PROPERTY(uint8_t fontAlpha READ _public_field_get_fontAlpha WRITE _public_field_set_fontAlpha)
	uint8_t _public_field_get_fontAlpha() const;
	void _public_field_set_fontAlpha(uint8_t value);
	Q_PROPERTY(cocos2d::Color3B fontFillColor READ _public_field_get_fontFillColor WRITE _public_field_set_fontFillColor)
	cocos2d::Color3B _public_field_get_fontFillColor() const;
	void _public_field_set_fontFillColor(const cocos2d::Color3B& value);
	Q_PROPERTY(QByteArray fontName READ _public_field_get_fontName WRITE _public_field_set_fontName)
	QByteArray _public_field_get_fontName() const;
	void _public_field_set_fontName(const QByteArray& value);
	Q_PROPERTY(int fontSize READ _public_field_get_fontSize WRITE _public_field_set_fontSize)
	int _public_field_get_fontSize() const;
	void _public_field_set_fontSize(int value);
	Q_PROPERTY(int overflow READ _public_field_get_overflow WRITE _public_field_set_overflow)
	int _public_field_get_overflow() const;
	void _public_field_set_overflow(int value);
	Q_PROPERTY(cocos2d::FontShadow shadow READ _public_field_get_shadow WRITE _public_field_set_shadow)
	cocos2d::FontShadow _public_field_get_shadow() const;
	void _public_field_set_shadow(const cocos2d::FontShadow& value);
	Q_PROPERTY(cocos2d::FontStroke stroke READ _public_field_get_stroke WRITE _public_field_set_stroke)
	cocos2d::FontStroke _public_field_get_stroke() const;
	void _public_field_set_stroke(const cocos2d::FontStroke& value);
	Q_PROPERTY(int vertAlignment READ _public_field_get_vertAlignment WRITE _public_field_set_vertAlignment)
	int _public_field_get_vertAlignment() const;
	void _public_field_set_vertAlignment(int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FontDefinition)
Q_DECLARE_METATYPE(cocos2d::FontDefinition *)
Q_DECLARE_METATYPE(const cocos2d::FontDefinition *)

namespace cocos2d {
class QtScriptViewport final : public QtScriptBaseClassPrototype<Viewport, false>
{
	Q_OBJECT

protected:
	explicit QtScriptViewport(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptViewport(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int h READ _public_field_get_h WRITE _public_field_set_h)
	unsigned int _public_field_get_h() const;
	void _public_field_set_h(unsigned int value);
	Q_PROPERTY(unsigned int w READ _public_field_get_w WRITE _public_field_set_w)
	unsigned int _public_field_get_w() const;
	void _public_field_set_w(unsigned int value);
	Q_PROPERTY(int x READ _public_field_get_x WRITE _public_field_set_x)
	int _public_field_get_x() const;
	void _public_field_set_x(int value);
	Q_PROPERTY(int y READ _public_field_get_y WRITE _public_field_set_y)
	int _public_field_get_y() const;
	void _public_field_set_y(int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Viewport)
Q_DECLARE_METATYPE(cocos2d::Viewport *)
Q_DECLARE_METATYPE(const cocos2d::Viewport *)

namespace cocos2d {
class QtScriptScissorRect final : public QtScriptBaseClassPrototype<ScissorRect, false>
{
	Q_OBJECT

protected:
	explicit QtScriptScissorRect(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptScissorRect(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float height READ _public_field_get_height WRITE _public_field_set_height)
	float _public_field_get_height() const;
	void _public_field_set_height(float value);
	Q_PROPERTY(float width READ _public_field_get_width WRITE _public_field_set_width)
	float _public_field_get_width() const;
	void _public_field_set_width(float value);
	Q_PROPERTY(float x READ _public_field_get_x WRITE _public_field_set_x)
	float _public_field_get_x() const;
	void _public_field_set_x(float value);
	Q_PROPERTY(float y READ _public_field_get_y WRITE _public_field_set_y)
	float _public_field_get_y() const;
	void _public_field_set_y(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ScissorRect)
Q_DECLARE_METATYPE(cocos2d::ScissorRect *)
Q_DECLARE_METATYPE(const cocos2d::ScissorRect *)

namespace cocos2d {
namespace backend {
class QtScriptStencilDescriptor final : public QtScriptBaseClassPrototype<StencilDescriptor, false>
{
	Q_OBJECT

protected:
	explicit QtScriptStencilDescriptor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptStencilDescriptor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool equals(const cocos2d::backend::StencilDescriptor& rhs);
	Q_PROPERTY(int depthFailureOperation READ _public_field_get_depthFailureOperation WRITE _public_field_set_depthFailureOperation)
	int _public_field_get_depthFailureOperation() const;
	void _public_field_set_depthFailureOperation(int value);
	Q_PROPERTY(int depthStencilPassOperation READ _public_field_get_depthStencilPassOperation WRITE _public_field_set_depthStencilPassOperation)
	int _public_field_get_depthStencilPassOperation() const;
	void _public_field_set_depthStencilPassOperation(int value);
	Q_PROPERTY(unsigned int readMask READ _public_field_get_readMask WRITE _public_field_set_readMask)
	unsigned int _public_field_get_readMask() const;
	void _public_field_set_readMask(unsigned int value);
	Q_PROPERTY(int stencilCompareFunction READ _public_field_get_stencilCompareFunction WRITE _public_field_set_stencilCompareFunction)
	int _public_field_get_stencilCompareFunction() const;
	void _public_field_set_stencilCompareFunction(int value);
	Q_PROPERTY(int stencilFailureOperation READ _public_field_get_stencilFailureOperation WRITE _public_field_set_stencilFailureOperation)
	int _public_field_get_stencilFailureOperation() const;
	void _public_field_set_stencilFailureOperation(int value);
	Q_PROPERTY(unsigned int writeMask READ _public_field_get_writeMask WRITE _public_field_set_writeMask)
	unsigned int _public_field_get_writeMask() const;
	void _public_field_set_writeMask(unsigned int value);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::StencilDescriptor)
Q_DECLARE_METATYPE(cocos2d::backend::StencilDescriptor *)
Q_DECLARE_METATYPE(const cocos2d::backend::StencilDescriptor *)

namespace cocos2d {
namespace backend {
class QtScriptDepthStencilDescriptor final : public QtScriptBaseClassPrototype<DepthStencilDescriptor, false>
{
	Q_OBJECT

protected:
	explicit QtScriptDepthStencilDescriptor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDepthStencilDescriptor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::backend::StencilDescriptor backFaceStencil READ _public_field_get_backFaceStencil WRITE _public_field_set_backFaceStencil)
	cocos2d::backend::StencilDescriptor _public_field_get_backFaceStencil() const;
	void _public_field_set_backFaceStencil(const cocos2d::backend::StencilDescriptor& value);
	Q_PROPERTY(int depthCompareFunction READ _public_field_get_depthCompareFunction WRITE _public_field_set_depthCompareFunction)
	int _public_field_get_depthCompareFunction() const;
	void _public_field_set_depthCompareFunction(int value);
	Q_PROPERTY(bool depthTestEnabled READ _public_field_get_depthTestEnabled WRITE _public_field_set_depthTestEnabled)
	bool _public_field_get_depthTestEnabled() const;
	void _public_field_set_depthTestEnabled(const bool& value);
	Q_PROPERTY(bool depthWriteEnabled READ _public_field_get_depthWriteEnabled WRITE _public_field_set_depthWriteEnabled)
	bool _public_field_get_depthWriteEnabled() const;
	void _public_field_set_depthWriteEnabled(const bool& value);
	Q_PROPERTY(cocos2d::backend::StencilDescriptor frontFaceStencil READ _public_field_get_frontFaceStencil WRITE _public_field_set_frontFaceStencil)
	cocos2d::backend::StencilDescriptor _public_field_get_frontFaceStencil() const;
	void _public_field_set_frontFaceStencil(const cocos2d::backend::StencilDescriptor& value);
	Q_PROPERTY(bool stencilTestEnabled READ _public_field_get_stencilTestEnabled WRITE _public_field_set_stencilTestEnabled)
	bool _public_field_get_stencilTestEnabled() const;
	void _public_field_set_stencilTestEnabled(const bool& value);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::DepthStencilDescriptor)
Q_DECLARE_METATYPE(cocos2d::backend::DepthStencilDescriptor *)
Q_DECLARE_METATYPE(const cocos2d::backend::DepthStencilDescriptor *)

namespace cocos2d {
namespace backend {
class QtScriptDepthStencilState : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptDepthStencilState(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDepthStencilState(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::DepthStencilState *)
Q_DECLARE_METATYPE(const cocos2d::backend::DepthStencilState *)

namespace cocos2d {
namespace backend {
class QtScriptTextureDescriptor final : public QtScriptBaseClassPrototype<TextureDescriptor, false>
{
	Q_OBJECT

protected:
	explicit QtScriptTextureDescriptor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTextureDescriptor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(uint32_t depth READ _public_field_get_depth WRITE _public_field_set_depth)
	uint32_t _public_field_get_depth() const;
	void _public_field_set_depth(uint32_t value);
	Q_PROPERTY(uint32_t height READ _public_field_get_height WRITE _public_field_set_height)
	uint32_t _public_field_get_height() const;
	void _public_field_set_height(uint32_t value);
	Q_PROPERTY(cocos2d::backend::SamplerDescriptor samplerDescriptor READ _public_field_get_samplerDescriptor WRITE _public_field_set_samplerDescriptor)
	cocos2d::backend::SamplerDescriptor _public_field_get_samplerDescriptor() const;
	void _public_field_set_samplerDescriptor(const cocos2d::backend::SamplerDescriptor& value);
	Q_PROPERTY(int textureFormat READ _public_field_get_textureFormat WRITE _public_field_set_textureFormat)
	int _public_field_get_textureFormat() const;
	void _public_field_set_textureFormat(int value);
	Q_PROPERTY(int textureType READ _public_field_get_textureType WRITE _public_field_set_textureType)
	int _public_field_get_textureType() const;
	void _public_field_set_textureType(int value);
	Q_PROPERTY(int textureUsage READ _public_field_get_textureUsage WRITE _public_field_set_textureUsage)
	int _public_field_get_textureUsage() const;
	void _public_field_set_textureUsage(int value);
	Q_PROPERTY(uint32_t width READ _public_field_get_width WRITE _public_field_set_width)
	uint32_t _public_field_get_width() const;
	void _public_field_set_width(uint32_t value);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::TextureDescriptor)
Q_DECLARE_METATYPE(cocos2d::backend::TextureDescriptor *)
Q_DECLARE_METATYPE(const cocos2d::backend::TextureDescriptor *)

namespace cocos2d {
namespace backend {
class QtScriptTextureBackend : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptTextureBackend(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTextureBackend(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void getBytes(size_t arg0, size_t arg1, size_t arg2, size_t arg3, bool arg4, const QScriptValue& arg5);
	Q_INVOKABLE int getTextureFormat();
	Q_INVOKABLE int getTextureType();
	Q_INVOKABLE int getTextureUsage();
	Q_INVOKABLE bool hasMipmaps();
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::TextureBackend *)
Q_DECLARE_METATYPE(const cocos2d::backend::TextureBackend *)

namespace cocos2d {
namespace backend {
class QtScriptTexture2DBackend : public QtScriptTextureBackend
{
	Q_OBJECT

protected:
	explicit QtScriptTexture2DBackend(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTexture2DBackend(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE size_t getHeight();
	Q_INVOKABLE size_t getWidth();
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::Texture2DBackend *)
Q_DECLARE_METATYPE(const cocos2d::backend::Texture2DBackend *)

namespace cocos2d {
namespace backend {
class QtScriptTextureCubemapBackend : public QtScriptTextureBackend
{
	Q_OBJECT

protected:
	explicit QtScriptTextureCubemapBackend(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTextureCubemapBackend(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::TextureCubemapBackend *)
Q_DECLARE_METATYPE(const cocos2d::backend::TextureCubemapBackend *)

namespace cocos2d {
namespace backend {
class QtScriptShaderModule : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptShaderModule(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptShaderModule(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE size_t getHashValue();
	Q_INVOKABLE int getShaderStage();
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::ShaderModule *)
Q_DECLARE_METATYPE(const cocos2d::backend::ShaderModule *)

namespace cocos2d {
namespace backend {
class QtScriptShaderCache : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptShaderCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptShaderCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void removeAllShaders();
	Q_INVOKABLE void removeUnusedShader();
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue newFragmentShaderModule(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue newVertexShaderModule(QScriptContext *context, QScriptEngine* engine);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::ShaderCache *)
Q_DECLARE_METATYPE(const cocos2d::backend::ShaderCache *)

namespace cocos2d {
namespace backend {
class QtScriptProgram : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptProgram(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptProgram(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::backend::UniformInfo getActiveUniformInfo(int stage, int location);
	Q_INVOKABLE int getAttributeLocation(const QByteArray& name);
	Q_INVOKABLE QByteArray getFragmentShader();
	Q_INVOKABLE int getMaxFragmentLocation();
	Q_INVOKABLE int getMaxVertexLocation();
	Q_INVOKABLE int getProgramType();
	Q_INVOKABLE size_t getUniformBufferSize(int stage);
	Q_INVOKABLE cocos2d::backend::UniformLocation getUniformLocation(const QByteArray& uniform);
	Q_INVOKABLE QByteArray getVertexShader();
	static QScriptValue getBuiltinProgram(QScriptContext *context, QScriptEngine* engine);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::Program *)
Q_DECLARE_METATYPE(const cocos2d::backend::Program *)

namespace cocos2d {
namespace backend {
class QtScriptProgramState : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptProgramState(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptProgramState(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::backend::ProgramState* clone();
	Q_INVOKABLE int getAttributeLocation(const QByteArray& name);
	Q_INVOKABLE cocos2d::backend::Program* getProgram();
	Q_INVOKABLE cocos2d::backend::UniformLocation getUniformLocation(const QByteArray& uniform);
	Q_INVOKABLE void setCallbackUniform(const cocos2d::backend::UniformLocation& arg0, QScriptValue arg1);
	Q_INVOKABLE void setParameterAutoBinding(const QByteArray& uniformName, const QByteArray& autoBinding);
	Q_INVOKABLE void setTexture(const cocos2d::backend::UniformLocation& uniformLocation, uint32_t slot, cocos2d::backend::TextureBackend* texture);
	Q_INVOKABLE void setUniform(const cocos2d::backend::UniformLocation& arg0, const QByteArray& arg1);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::ProgramState *)
Q_DECLARE_METATYPE(const cocos2d::backend::ProgramState *)

namespace cocos2d {
class QtScriptPipelineDescriptor final : public QtScriptBaseClassPrototype<PipelineDescriptor, false>
{
	Q_OBJECT

protected:
	explicit QtScriptPipelineDescriptor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptPipelineDescriptor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::backend::BlendDescriptor blendDescriptor READ _public_field_get_blendDescriptor WRITE _public_field_set_blendDescriptor)
	cocos2d::backend::BlendDescriptor _public_field_get_blendDescriptor() const;
	void _public_field_set_blendDescriptor(const cocos2d::backend::BlendDescriptor& value);
	Q_PROPERTY(cocos2d::backend::ProgramState* programState READ _public_field_get_programState WRITE _public_field_set_programState)
	cocos2d::backend::ProgramState* _public_field_get_programState() const;
	void _public_field_set_programState(cocos2d::backend::ProgramState* value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::PipelineDescriptor)
Q_DECLARE_METATYPE(cocos2d::PipelineDescriptor *)
Q_DECLARE_METATYPE(const cocos2d::PipelineDescriptor *)

namespace cocos2d {
class QtScriptRenderCommand : public QtScriptBaseClassPrototype<RenderCommand *, true>
{
	Q_OBJECT

protected:
	explicit QtScriptRenderCommand(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRenderCommand(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool _3D READ is3D WRITE set3D)
	Q_PROPERTY(bool skipBatching READ isSkipBatching WRITE setSkipBatching)
	Q_PROPERTY(bool transparent READ isTransparent WRITE setTransparent)
	Q_INVOKABLE float getDepth();
	Q_INVOKABLE float getGlobalOrder();
	Q_INVOKABLE cocos2d::Mat4 getMV();
	Q_INVOKABLE cocos2d::PipelineDescriptor getPipelineDescriptor();
	Q_INVOKABLE int getType();
	Q_INVOKABLE void init(float globalZOrder, const cocos2d::Mat4& modelViewTransform, unsigned int flags);
	bool is3D();
	bool isSkipBatching();
	bool isTransparent();
	void set3D(bool value);
	void setSkipBatching(bool value);
	void setTransparent(bool isTransparent);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::RenderCommand *)
Q_DECLARE_METATYPE(const cocos2d::RenderCommand *)

namespace cocos2d {
class QtScriptCustomCommand : public QtScriptRenderCommand
{
	Q_OBJECT

protected:
	explicit QtScriptCustomCommand(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCustomCommand(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int drawType READ getDrawType WRITE setDrawType)
	Q_PROPERTY(float lineWidth READ getLineWidth WRITE setLineWidth)
	Q_PROPERTY(int primitiveType READ getPrimitiveType WRITE setPrimitiveType)
	Q_PROPERTY(cocos2d::backend::Buffer* vertexBuffer READ getVertexBuffer WRITE setVertexBuffer)
	Q_INVOKABLE void createIndexBuffer(int format, size_t capacity, int usage);
	Q_INVOKABLE void createVertexBuffer(size_t vertexSize, size_t capacity, int usage);
	int getDrawType();
	Q_INVOKABLE cocos2d::backend::Buffer* getIndexBuffer();
	Q_INVOKABLE size_t getIndexCapacity();
	Q_INVOKABLE size_t getIndexDrawCount();
	Q_INVOKABLE size_t getIndexDrawOffset();
	Q_INVOKABLE int getIndexFormat();
	float getLineWidth();
	int getPrimitiveType();
	cocos2d::backend::Buffer* getVertexBuffer();
	Q_INVOKABLE size_t getVertexCapacity();
	Q_INVOKABLE size_t getVertexDrawCount();
	Q_INVOKABLE size_t getVertexDrawStart();
	Q_INVOKABLE void init(float globalZOrder);
	Q_INVOKABLE void init(float globalZOrder, const cocos2d::BlendFunc& blendFunc);
	Q_INVOKABLE void init(float globalZOrder, const cocos2d::Mat4& modelViewTransform, unsigned int flags);
	Q_INVOKABLE void setAfterCallback(QScriptValue after);
	Q_INVOKABLE void setBeforeCallback(QScriptValue before);
	void setDrawType(int drawType);
	Q_INVOKABLE void setIndexBuffer(cocos2d::backend::Buffer* indexBuffer, int indexFormat);
	Q_INVOKABLE void setIndexDrawInfo(size_t start, size_t count);
	void setLineWidth(float lineWidth);
	void setPrimitiveType(int primitiveType);
	void setVertexBuffer(cocos2d::backend::Buffer* vertexBuffer);
	Q_INVOKABLE void setVertexDrawInfo(size_t start, size_t count);
	Q_INVOKABLE void updateIndexBuffer(const QByteArray& arg0);
	Q_INVOKABLE void updateIndexBuffer(const QByteArray& arg0, size_t arg1);
	Q_INVOKABLE void updateVertexBuffer(const QByteArray& arg0);
	Q_INVOKABLE void updateVertexBuffer(const QByteArray& arg0, size_t arg1);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CustomCommand *)
Q_DECLARE_METATYPE(const cocos2d::CustomCommand *)

namespace cocos2d {
class QtScriptTexture2D : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptTexture2D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTexture2D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Texture2D* alphaTexture READ getAlphaTexture WRITE setAlphaTexture)
	Q_PROPERTY(float maxS READ getMaxS WRITE setMaxS)
	Q_PROPERTY(float maxT READ getMaxT WRITE setMaxT)
	Q_PROPERTY(bool renderTarget READ isRenderTarget WRITE setRenderTarget)
	Q_INVOKABLE void generateMipmap();
	cocos2d::Texture2D* getAlphaTexture();
	Q_INVOKABLE bool getAlphaTextureName();
	Q_INVOKABLE cocos2d::backend::TextureBackend* getBackendTexture();
	Q_INVOKABLE unsigned int getBitsPerPixelForFormat();
	Q_INVOKABLE unsigned int getBitsPerPixelForFormat(int format);
	Q_INVOKABLE cocos2d::Size getContentSize();
	Q_INVOKABLE cocos2d::Size getContentSizeInPixels();
	float getMaxS();
	float getMaxT();
	Q_INVOKABLE QByteArray getPath();
	Q_INVOKABLE int getPixelFormat();
	Q_INVOKABLE int getPixelsHigh();
	Q_INVOKABLE int getPixelsWide();
	Q_INVOKABLE QByteArray getStringForFormat();
	Q_INVOKABLE bool hasMipmaps();
	Q_INVOKABLE bool hasPremultipliedAlpha();
	Q_INVOKABLE bool initWithBackendTexture(cocos2d::backend::TextureBackend* texture);
	Q_INVOKABLE bool initWithBackendTexture(cocos2d::backend::TextureBackend* texture, bool preMultipliedAlpha);
	Q_INVOKABLE bool initWithData(const QByteArray& arg0, int arg1, int arg2, int arg3, const cocos2d::Size& arg4, bool arg5);
	Q_INVOKABLE bool initWithData(const QByteArray& arg0, int arg1, int arg2, int arg3, int arg4, const cocos2d::Size& arg5, bool arg6);
	Q_INVOKABLE bool initWithImage(cocos2d::Image* image);
	Q_INVOKABLE bool initWithImage(cocos2d::Image* image, int format);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const cocos2d::FontDefinition& textDefinition);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize, const cocos2d::Size& dimensions);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize, const cocos2d::Size& dimensions, int hAlignment);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize, const cocos2d::Size& dimensions, int hAlignment, int vAlignment);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize, const cocos2d::Size& dimensions, int hAlignment, int vAlignment, bool enableWrap);
	Q_INVOKABLE bool initWithString(const QByteArray& text, const QByteArray& fontName, float fontSize, const cocos2d::Size& dimensions, int hAlignment, int vAlignment, bool enableWrap, int overflow);
	bool isRenderTarget();
	Q_INVOKABLE void setAliasTexParameters();
	void setAlphaTexture(cocos2d::Texture2D* alphaTexture);
	Q_INVOKABLE void setAntiAliasTexParameters();
	void setMaxS(float maxS);
	void setMaxT(float maxT);
	void setRenderTarget(bool renderTarget);
	Q_INVOKABLE void setTexParameters(const cocos2d::backend::SamplerDescriptor& params);
	Q_INVOKABLE bool updateWithData(const QByteArray& arg0, int arg1, int arg2, int arg3, int arg4);
	static QScriptValue getDefaultAlphaPixelFormat(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setDefaultAlphaPixelFormat(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Texture2D *)
Q_DECLARE_METATYPE(const cocos2d::Texture2D *)

namespace cocos2d {
class QtScriptTouch : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptTouch(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTouch(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE float getCurrentForce();
	Q_INVOKABLE cocos2d::Vec2 getDelta();
	Q_INVOKABLE int getID();
	Q_INVOKABLE cocos2d::Vec2 getLocation();
	Q_INVOKABLE cocos2d::Vec2 getLocationInView();
	Q_INVOKABLE float getMaxForce();
	Q_INVOKABLE cocos2d::Vec2 getPreviousLocation();
	Q_INVOKABLE cocos2d::Vec2 getPreviousLocationInView();
	Q_INVOKABLE cocos2d::Vec2 getStartLocation();
	Q_INVOKABLE cocos2d::Vec2 getStartLocationInView();
	Q_INVOKABLE void setTouchInfo(int id, float x, float y);
	Q_INVOKABLE void setTouchInfo(int id, float x, float y, float force, float maxForce);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Touch *)
Q_DECLARE_METATYPE(const cocos2d::Touch *)

namespace cocos2d {
class QtScriptAffineTransform final : public QtScriptBaseClassPrototype<AffineTransform, false>
{
	Q_OBJECT

protected:
	explicit QtScriptAffineTransform(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAffineTransform(QScriptEngine *engine);
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

Q_DECLARE_METATYPE(cocos2d::AffineTransform)
Q_DECLARE_METATYPE(cocos2d::AffineTransform *)
Q_DECLARE_METATYPE(const cocos2d::AffineTransform *)

namespace cocos2d {
class QtScriptComponent : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptComponent(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptComponent(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
	Q_PROPERTY(QByteArray name READ getName WRITE setName)
	QByteArray getName();
	Q_INVOKABLE cocos2d::Node* getOwner();
	Q_INVOKABLE bool init();
	bool isEnabled();
	void setEnabled(bool enabled);
	void setName(const QByteArray& name);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Component *)
Q_DECLARE_METATYPE(const cocos2d::Component *)

namespace cocos2d {
class QtScriptNode : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(const cocos2d::Mat4* additionalTransform READ getAdditionalTransform WRITE setAdditionalTransform)
	Q_PROPERTY(cocos2d::Vec2 anchorPoint READ getAnchorPoint WRITE setAnchorPoint)
	Q_PROPERTY(unsigned short cameraMask READ getCameraMask WRITE setCameraMask)
	Q_PROPERTY(bool cascadeColorEnabled READ isCascadeColorEnabled WRITE setCascadeColorEnabled)
	Q_PROPERTY(bool cascadeOpacityEnabled READ isCascadeOpacityEnabled WRITE setCascadeOpacityEnabled)
	Q_PROPERTY(cocos2d::Color3B color READ getColor WRITE setColor)
	Q_PROPERTY(cocos2d::Size contentSize READ getContentSize WRITE setContentSize)
	Q_PROPERTY(float globalZOrder READ getGlobalZOrder WRITE setGlobalZOrder)
	Q_PROPERTY(bool ignoreAnchorPointForPosition READ isIgnoreAnchorPointForPosition WRITE setIgnoreAnchorPointForPosition)
	Q_PROPERTY(int32_t localZOrder READ getLocalZOrder WRITE setLocalZOrder)
	Q_PROPERTY(QByteArray name READ getName WRITE setName)
	Q_PROPERTY(cocos2d::Mat4 nodeToParentTransform READ getNodeToParentTransform WRITE setNodeToParentTransform)
	Q_PROPERTY(cocos2d::Vec2 normalizedPosition READ getNormalizedPosition WRITE setNormalizedPosition)
	Q_PROPERTY(uint8_t opacity READ getOpacity WRITE setOpacity)
	Q_PROPERTY(bool opacityModifyRGB READ isOpacityModifyRGB WRITE setOpacityModifyRGB)
	Q_PROPERTY(cocos2d::Node* parent READ getParent WRITE setParent)
	Q_PROPERTY(cocos2d::Vec2 position READ getPosition WRITE setPosition)
	Q_PROPERTY(cocos2d::Vec3 position3D READ getPosition3D WRITE setPosition3D)
	Q_PROPERTY(cocos2d::Vec2 positionNormalized READ getPositionNormalized WRITE setPositionNormalized)
	Q_PROPERTY(float positionX READ getPositionX WRITE setPositionX)
	Q_PROPERTY(float positionY READ getPositionY WRITE setPositionY)
	Q_PROPERTY(float positionZ READ getPositionZ WRITE setPositionZ)
	Q_PROPERTY(cocos2d::backend::ProgramState* programState READ getProgramState WRITE setProgramState)
	Q_PROPERTY(float rotation READ getRotation WRITE setRotation)
	Q_PROPERTY(cocos2d::Vec3 rotation3D READ getRotation3D WRITE setRotation3D)
	Q_PROPERTY(cocos2d::Quaternion rotationQuat READ getRotationQuat WRITE setRotationQuat)
	Q_PROPERTY(float rotationSkewX READ getRotationSkewX WRITE setRotationSkewX)
	Q_PROPERTY(float rotationSkewY READ getRotationSkewY WRITE setRotationSkewY)
	Q_PROPERTY(float scale READ getScale WRITE setScale)
	Q_PROPERTY(float scaleX READ getScaleX WRITE setScaleX)
	Q_PROPERTY(float scaleY READ getScaleY WRITE setScaleY)
	Q_PROPERTY(float scaleZ READ getScaleZ WRITE setScaleZ)
	Q_PROPERTY(cocos2d::backend::Program* shaderProgram READ getShaderProgram WRITE setShaderProgram)
	Q_PROPERTY(float skewX READ getSkewX WRITE setSkewX)
	Q_PROPERTY(float skewY READ getSkewY WRITE setSkewY)
	Q_PROPERTY(int tag READ getTag WRITE setTag)
	Q_PROPERTY(bool useInvertedAdditionalTransformOrder READ isUseInvertedAdditionalTransformOrder WRITE setUseInvertedAdditionalTransformOrder)
	Q_PROPERTY(cocos2d::Ref* userObject READ getUserObject WRITE setUserObject)
	Q_PROPERTY(bool visible READ isVisible WRITE setVisible)
	Q_INVOKABLE void addChild(cocos2d::Node* child);
	Q_INVOKABLE void addChild(cocos2d::Node* child, int localZOrder);
	Q_INVOKABLE void addChild(cocos2d::Node* child, int localZOrder, int tag);
	Q_INVOKABLE bool addComponent(cocos2d::Component* component);
	Q_INVOKABLE void cleanup();
	Q_INVOKABLE cocos2d::Node* clone();
	Q_INVOKABLE cocos2d::Vec2 convertToNodeSpace(const cocos2d::Vec2& worldPoint);
	Q_INVOKABLE cocos2d::Vec2 convertToNodeSpaceAR(const cocos2d::Vec2& worldPoint);
	Q_INVOKABLE cocos2d::Vec2 convertToWorldSpace(const cocos2d::Vec2& nodePoint);
	Q_INVOKABLE cocos2d::Vec2 convertToWorldSpaceAR(const cocos2d::Vec2& nodePoint);
	Q_INVOKABLE cocos2d::Vec2 convertTouchToNodeSpace(cocos2d::Touch* touch);
	Q_INVOKABLE cocos2d::Vec2 convertTouchToNodeSpaceAR(cocos2d::Touch* touch);
	Q_INVOKABLE void copyNodeChildrenFrom(const cocos2d::Node* from);
	Q_INVOKABLE void copyNodeChildrenFrom(const cocos2d::Node* from, bool skipHidden);
	Q_INVOKABLE void copyPropertiesFrom(const cocos2d::Node* from);
	Q_INVOKABLE void enumerateChildren(const QByteArray& name, QScriptValue callback);
	Q_INVOKABLE cocos2d::Action* getActionByTag(int tag);
	const cocos2d::Mat4* getAdditionalTransform();
	cocos2d::Vec2 getAnchorPoint();
	Q_INVOKABLE cocos2d::Vec2 getAnchorPointInPoints();
	Q_INVOKABLE cocos2d::Rect getBoundingBox();
	unsigned short getCameraMask();
	Q_INVOKABLE cocos2d::Node* getChildByName(const QByteArray& name);
	Q_INVOKABLE cocos2d::Node* getChildByTag(int tag);
	Q_INVOKABLE cocos2d::Vector<cocos2d::Node *> getChildren();
	Q_INVOKABLE ssize_t getChildrenCount();
	cocos2d::Color3B getColor();
	Q_INVOKABLE cocos2d::Component* getComponent(const QByteArray& name);
	cocos2d::Size getContentSize();
	Q_INVOKABLE QByteArray getDescription();
	Q_INVOKABLE cocos2d::Color3B getDisplayedColor();
	Q_INVOKABLE uint8_t getDisplayedOpacity();
	float getGlobalZOrder();
	int32_t getLocalZOrder();
	QByteArray getName();
	Q_INVOKABLE cocos2d::AffineTransform getNodeToParentAffineTransform();
	Q_INVOKABLE cocos2d::AffineTransform getNodeToParentAffineTransform(cocos2d::Node* ancestor);
	cocos2d::Mat4 getNodeToParentTransform();
	Q_INVOKABLE cocos2d::Mat4 getNodeToParentTransform(cocos2d::Node* ancestor);
	Q_INVOKABLE cocos2d::AffineTransform getNodeToWorldAffineTransform();
	Q_INVOKABLE cocos2d::Mat4 getNodeToWorldTransform();
	cocos2d::Vec2 getNormalizedPosition();
	Q_INVOKABLE ssize_t getNumberOfRunningActions();
	Q_INVOKABLE ssize_t getNumberOfRunningActionsByTag(int tag);
	uint8_t getOpacity();
	cocos2d::Node* getParent();
	Q_INVOKABLE cocos2d::AffineTransform getParentToNodeAffineTransform();
	Q_INVOKABLE cocos2d::Mat4 getParentToNodeTransform();
	cocos2d::Vec2 getPosition();
	cocos2d::Vec3 getPosition3D();
	cocos2d::Vec2 getPositionNormalized();
	float getPositionX();
	float getPositionY();
	float getPositionZ();
	cocos2d::backend::ProgramState* getProgramState();
	float getRotation();
	cocos2d::Vec3 getRotation3D();
	cocos2d::Quaternion getRotationQuat();
	float getRotationSkewX();
	float getRotationSkewY();
	float getScale();
	float getScaleX();
	float getScaleY();
	float getScaleZ();
	Q_INVOKABLE cocos2d::Scene* getScene();
	cocos2d::backend::Program* getShaderProgram();
	float getSkewX();
	float getSkewY();
	int getTag();
	Q_INVOKABLE cocos2d::Node* getTransformParent();
	cocos2d::Ref* getUserObject();
	Q_INVOKABLE cocos2d::AffineTransform getWorldToNodeAffineTransform();
	Q_INVOKABLE cocos2d::Mat4 getWorldToNodeTransform();
	Q_INVOKABLE bool init();
	bool isCascadeColorEnabled();
	bool isCascadeOpacityEnabled();
	bool isIgnoreAnchorPointForPosition();
	bool isOpacityModifyRGB();
	Q_INVOKABLE bool isRunning();
	Q_INVOKABLE bool isScheduled(const QByteArray& key);
	bool isUseInvertedAdditionalTransformOrder();
	bool isVisible();
	Q_INVOKABLE void removeAllChildren();
	Q_INVOKABLE void removeAllChildrenWithCleanup(bool cleanup);
	Q_INVOKABLE void removeAllComponents();
	Q_INVOKABLE void removeChild(cocos2d::Node* child);
	Q_INVOKABLE void removeChild(cocos2d::Node* child, bool cleanup);
	Q_INVOKABLE void removeChildByName(const QByteArray& name);
	Q_INVOKABLE void removeChildByName(const QByteArray& name, bool cleanup);
	Q_INVOKABLE void removeChildByTag(int tag);
	Q_INVOKABLE void removeChildByTag(int tag, bool cleanup);
	Q_INVOKABLE bool removeComponent(const QByteArray& name);
	Q_INVOKABLE void removeFromParent();
	Q_INVOKABLE void removeFromParentAndCleanup(bool cleanup);
	Q_INVOKABLE cocos2d::Action* runAction(cocos2d::Action* action);
	Q_INVOKABLE void schedule(QScriptValue callback, const QByteArray& key);
	Q_INVOKABLE void schedule(QScriptValue callback, float interval, const QByteArray& key);
	Q_INVOKABLE void schedule(QScriptValue callback, float interval, unsigned int repeat, float delay, const QByteArray& key);
	Q_INVOKABLE void scheduleOnce(QScriptValue callback, float delay, const QByteArray& key);
	Q_INVOKABLE void scheduleUpdate();
	Q_INVOKABLE void scheduleUpdateWithPriority(int priority);
	void setAdditionalTransform(const cocos2d::Mat4* additionalTransform);
	Q_INVOKABLE void setAffineTransform(const cocos2d::AffineTransform& additionalTransform);
	void setAnchorPoint(const cocos2d::Vec2& anchorPoint);
	void setCameraMask(unsigned short mask);
	void setCameraMask(unsigned short mask, bool applyChildren);
	void setCascadeColorEnabled(bool cascadeColorEnabled);
	void setCascadeOpacityEnabled(bool cascadeOpacityEnabled);
	void setColor(const cocos2d::Color3B& color);
	void setContentSize(const cocos2d::Size& contentSize);
	void setGlobalZOrder(float globalZOrder);
	void setIgnoreAnchorPointForPosition(bool ignore);
	void setLocalZOrder(int32_t localZOrder);
	void setName(const QByteArray& name);
	void setNodeToParentTransform(const cocos2d::Mat4& transform);
	void setNormalizedPosition(const cocos2d::Vec2& position);
	Q_INVOKABLE void setOnEnterCallback(QScriptValue callback);
	Q_INVOKABLE void setOnEnterTransitionDidFinishCallback(QScriptValue callback);
	Q_INVOKABLE void setOnExitCallback(QScriptValue callback);
	Q_INVOKABLE void setOnExitTransitionDidStartCallback(QScriptValue callback);
	Q_INVOKABLE void setOnUpdateCallback(QScriptValue callback);
	void setOpacity(uint8_t opacity);
	void setOpacityModifyRGB(bool value);
	void setParent(cocos2d::Node* parent);
	void setPosition(const cocos2d::Vec2& position);
	Q_INVOKABLE void setPosition(float x, float y);
	void setPosition3D(const cocos2d::Vec3& position);
	void setPositionNormalized(const cocos2d::Vec2& position);
	void setPositionX(float x);
	void setPositionY(float y);
	void setPositionZ(float positionZ);
	void setProgramState(cocos2d::backend::ProgramState* programState);
	void setRotation(float rotation);
	void setRotation3D(const cocos2d::Vec3& rotation);
	void setRotationQuat(const cocos2d::Quaternion& quat);
	void setRotationSkewX(float rotationX);
	void setRotationSkewY(float rotationY);
	void setScale(float scale);
	Q_INVOKABLE void setScale(float scaleX, float scaleY);
	void setScaleX(float scaleX);
	void setScaleY(float scaleY);
	void setScaleZ(float scaleZ);
	void setShaderProgram(cocos2d::backend::Program* program);
	void setSkewX(float skewX);
	void setSkewY(float skewY);
	void setTag(int tag);
	void setUseInvertedAdditionalTransformOrder(bool value);
	void setUserObject(cocos2d::Ref* userObject);
	void setVisible(bool visible);
	Q_INVOKABLE void sortAllChildren();
	Q_INVOKABLE void stopAction(cocos2d::Action* action);
	Q_INVOKABLE void stopActionByTag(int tag);
	Q_INVOKABLE void stopActionsByFlags(unsigned int flags);
	Q_INVOKABLE void stopAllActions();
	Q_INVOKABLE void stopAllActionsByTag(int tag);
	Q_INVOKABLE void unschedule(const QByteArray& key);
	Q_INVOKABLE void unscheduleAllCallbacks();
	Q_INVOKABLE void unscheduleUpdate();
	Q_INVOKABLE void updateTransform();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getAttachedNodeCount(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Node *)
Q_DECLARE_METATYPE(const cocos2d::Node *)

namespace cocos2d {
class QtScriptScene : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptScene(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptScene(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::NavMesh* navMesh READ getNavMesh WRITE setNavMesh)
	Q_INVOKABLE cocos2d::Camera* getDefaultCamera();
	cocos2d::NavMesh* getNavMesh();
	Q_INVOKABLE bool initWithSize(const cocos2d::Size& size);
	Q_INVOKABLE void setCameraOrderDirty();
	void setNavMesh(cocos2d::NavMesh* navMesh);
	Q_INVOKABLE void setNavMeshDebugCamera(cocos2d::Camera* camera);
	Q_INVOKABLE void stepPhysicsAndNavigation(float deltaTime);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithSize(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Scene *)
Q_DECLARE_METATYPE(const cocos2d::Scene *)

namespace cocos2d {
class QtScriptGLContextAttrs final : public QtScriptBaseClassPrototype<GLContextAttrs, false>
{
	Q_OBJECT

protected:
	explicit QtScriptGLContextAttrs(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptGLContextAttrs(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int alphaBits READ _public_field_get_alphaBits WRITE _public_field_set_alphaBits)
	int _public_field_get_alphaBits() const;
	void _public_field_set_alphaBits(int value);
	Q_PROPERTY(int blueBits READ _public_field_get_blueBits WRITE _public_field_set_blueBits)
	int _public_field_get_blueBits() const;
	void _public_field_set_blueBits(int value);
	Q_PROPERTY(int depthBits READ _public_field_get_depthBits WRITE _public_field_set_depthBits)
	int _public_field_get_depthBits() const;
	void _public_field_set_depthBits(int value);
	Q_PROPERTY(int greenBits READ _public_field_get_greenBits WRITE _public_field_set_greenBits)
	int _public_field_get_greenBits() const;
	void _public_field_set_greenBits(int value);
	Q_PROPERTY(int multisamplingCount READ _public_field_get_multisamplingCount WRITE _public_field_set_multisamplingCount)
	int _public_field_get_multisamplingCount() const;
	void _public_field_set_multisamplingCount(int value);
	Q_PROPERTY(int redBits READ _public_field_get_redBits WRITE _public_field_set_redBits)
	int _public_field_get_redBits() const;
	void _public_field_set_redBits(int value);
	Q_PROPERTY(int stencilBits READ _public_field_get_stencilBits WRITE _public_field_set_stencilBits)
	int _public_field_get_stencilBits() const;
	void _public_field_set_stencilBits(int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::GLContextAttrs)
Q_DECLARE_METATYPE(cocos2d::GLContextAttrs *)
Q_DECLARE_METATYPE(const cocos2d::GLContextAttrs *)

namespace cocos2d {
class QtScriptGLView : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptGLView(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptGLView(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Size getDesignResolutionSize();
	Q_INVOKABLE cocos2d::Size getFrameSize();
	Q_INVOKABLE cocos2d::Rect getSafeAreaRect();
	Q_INVOKABLE float getScaleX();
	Q_INVOKABLE float getScaleY();
	Q_INVOKABLE cocos2d::Rect getScissorRect();
	Q_INVOKABLE QByteArray getViewName();
	Q_INVOKABLE cocos2d::Rect getViewPortRect();
	Q_INVOKABLE cocos2d::Vec2 getVisibleOrigin();
	Q_INVOKABLE cocos2d::Rect getVisibleRect();
	Q_INVOKABLE cocos2d::Size getVisibleSize();
	Q_INVOKABLE bool isScissorEnabled();
	Q_INVOKABLE void pollEvents();
	static QScriptValue getGLContextAttrs(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::GLView *)
Q_DECLARE_METATYPE(const cocos2d::GLView *)

namespace cocos2d {
class QtScriptDirector : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptDirector(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDirector(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Vec2 convertToGL(const cocos2d::Vec2& point);
	Q_INVOKABLE cocos2d::Vec2 convertToUI(const cocos2d::Vec2& point);
	Q_INVOKABLE cocos2d::ActionManager* getActionManager();
	Q_INVOKABLE float getAnimationInterval();
	Q_INVOKABLE float getContentScaleFactor();
	Q_INVOKABLE float getDeltaTime();
	Q_INVOKABLE float getFrameRate();
	Q_INVOKABLE int64_t getFrameStartTimeMicros();
	Q_INVOKABLE cocos2d::Mat4 getMatrix(int type);
	Q_INVOKABLE cocos2d::Node* getNotificationNode();
	Q_INVOKABLE cocos2d::GLView* getOpenGLView();
	Q_INVOKABLE int getProjection();
	Q_INVOKABLE cocos2d::Renderer* getRenderer();
	Q_INVOKABLE cocos2d::Scene* getRunningScene();
	Q_INVOKABLE cocos2d::Rect getSafeAreaRect();
	Q_INVOKABLE cocos2d::Scheduler* getScheduler();
	Q_INVOKABLE float getSecondsPerFrame();
	Q_INVOKABLE cocos2d::TextureCache* getTextureCache();
	Q_INVOKABLE unsigned int getTotalFrames();
	Q_INVOKABLE cocos2d::Vec2 getVisibleOrigin();
	Q_INVOKABLE cocos2d::Size getVisibleSize();
	Q_INVOKABLE cocos2d::Size getWinSize();
	Q_INVOKABLE cocos2d::Size getWinSizeInPixels();
	Q_INVOKABLE float getZEye();
	Q_INVOKABLE bool isDisplayStats();
	Q_INVOKABLE bool isNextDeltaTimeZero();
	Q_INVOKABLE bool isPaused();
	Q_INVOKABLE bool isSendCleanupToScene();
	Q_INVOKABLE bool isValid();
	Q_INVOKABLE void purgeCachedData();
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Director *)
Q_DECLARE_METATYPE(const cocos2d::Director *)

namespace cocos2d {
class QtScriptScheduler : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptScheduler(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptScheduler(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float timeScale READ getTimeScale WRITE setTimeScale)
	Q_INVOKABLE void cancelPerformAll();
	float getTimeScale();
	Q_INVOKABLE void perform(QScriptValue function);
	void setTimeScale(float timeScale);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Scheduler *)
Q_DECLARE_METATYPE(const cocos2d::Scheduler *)

namespace cocos2d {
class QtScriptAABB final : public QtScriptBaseClassPrototype<AABB, false>
{
	Q_OBJECT

protected:
	explicit QtScriptAABB(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAABB(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool containPoint(const cocos2d::Vec3& point);
	Q_INVOKABLE cocos2d::Vec3 getCenter();
	Q_INVOKABLE void getCorners(cocos2d::Vec3* dst);
	Q_INVOKABLE bool intersects(const cocos2d::AABB& aabb);
	Q_INVOKABLE bool isEmpty();
	Q_INVOKABLE void merge(const cocos2d::AABB& box);
	Q_INVOKABLE void reset();
	Q_INVOKABLE void set(const cocos2d::Vec3& min, const cocos2d::Vec3& max);
	Q_INVOKABLE void transform(const cocos2d::Mat4& mat);
	Q_PROPERTY(cocos2d::Vec3 max READ _public_field_get_max WRITE _public_field_set_max)
	cocos2d::Vec3 _public_field_get_max() const;
	void _public_field_set_max(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 min READ _public_field_get_min WRITE _public_field_set_min)
	cocos2d::Vec3 _public_field_get_min() const;
	void _public_field_set_min(const cocos2d::Vec3& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::AABB)
Q_DECLARE_METATYPE(cocos2d::AABB *)
Q_DECLARE_METATYPE(const cocos2d::AABB *)

namespace cocos2d {
class QtScriptMeshVertexAttrib final : public QtScriptBaseClassPrototype<MeshVertexAttrib, false>
{
	Q_OBJECT

protected:
	explicit QtScriptMeshVertexAttrib(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMeshVertexAttrib(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int getAttribSizeBytes();
	Q_PROPERTY(int type READ _public_field_get_type WRITE _public_field_set_type)
	int _public_field_get_type() const;
	void _public_field_set_type(int value);
	Q_PROPERTY(int vertexAttrib READ _public_field_get_vertexAttrib WRITE _public_field_set_vertexAttrib)
	int _public_field_get_vertexAttrib() const;
	void _public_field_set_vertexAttrib(int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MeshVertexAttrib)
Q_DECLARE_METATYPE(cocos2d::MeshVertexAttrib *)
Q_DECLARE_METATYPE(const cocos2d::MeshVertexAttrib *)

namespace cocos2d {
class QtScriptAnimation3D : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptAnimation3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAnimation3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE float getDuration();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Animation3D *)
Q_DECLARE_METATYPE(const cocos2d::Animation3D *)

namespace cocos2d {
class QtScriptAnimation3DCache : public QtScriptBaseClassPrototype<Animation3DCache *, true>
{
	Q_OBJECT

protected:
	explicit QtScriptAnimation3DCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAnimation3DCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addAnimation(const QByteArray& key, cocos2d::Animation3D* animation);
	Q_INVOKABLE cocos2d::Animation3D* getAnimation(const QByteArray& key);
	Q_INVOKABLE void removeAllAnimations();
	Q_INVOKABLE void removeUnusedAnimation();
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Animation3DCache *)
Q_DECLARE_METATYPE(const cocos2d::Animation3DCache *)

namespace cocos2d {
class QtScriptAction : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int flags READ getFlags WRITE setFlags)
	Q_PROPERTY(int tag READ getTag WRITE setTag)
	Q_INVOKABLE cocos2d::Action* clone();
	Q_INVOKABLE QByteArray description();
	unsigned int getFlags();
	Q_INVOKABLE cocos2d::Node* getOriginalTarget();
	int getTag();
	Q_INVOKABLE cocos2d::Node* getTarget();
	Q_INVOKABLE bool isDone();
	Q_INVOKABLE cocos2d::Action* reverse();
	void setFlags(unsigned int flags);
	void setTag(int tag);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Action *)
Q_DECLARE_METATYPE(const cocos2d::Action *)

namespace cocos2d {
class QtScriptFiniteTimeAction : public QtScriptAction
{
	Q_OBJECT

protected:
	explicit QtScriptFiniteTimeAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFiniteTimeAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float duration READ getDuration WRITE setDuration)
	Q_INVOKABLE cocos2d::FiniteTimeAction* clone();
	float getDuration();
	Q_INVOKABLE cocos2d::FiniteTimeAction* reverse();
	void setDuration(float duration);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FiniteTimeAction *)
Q_DECLARE_METATYPE(const cocos2d::FiniteTimeAction *)

namespace cocos2d {
class QtScriptSpeed : public QtScriptAction
{
	Q_OBJECT

protected:
	explicit QtScriptSpeed(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSpeed(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::ActionInterval* innerAction READ getInnerAction WRITE setInnerAction)
	Q_PROPERTY(float speed READ getSpeed WRITE setSpeed)
	Q_INVOKABLE cocos2d::Speed* clone();
	cocos2d::ActionInterval* getInnerAction();
	float getSpeed();
	Q_INVOKABLE bool initWithAction(cocos2d::ActionInterval* action, float speed);
	Q_INVOKABLE cocos2d::Speed* reverse();
	void setInnerAction(cocos2d::ActionInterval* action);
	void setSpeed(float speed);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Speed *)
Q_DECLARE_METATYPE(const cocos2d::Speed *)

namespace cocos2d {
class QtScriptFollow : public QtScriptAction
{
	Q_OBJECT

protected:
	explicit QtScriptFollow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFollow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool boundarySet READ isBoundarySet WRITE setBoundarySet)
	Q_INVOKABLE cocos2d::Follow* clone();
	Q_INVOKABLE bool initWithTarget(cocos2d::Node* followedNode);
	Q_INVOKABLE bool initWithTarget(cocos2d::Node* followedNode, const cocos2d::Rect& rect);
	Q_INVOKABLE bool initWithTargetAndOffset(cocos2d::Node* followedNode, float xOffset, float yOffset);
	Q_INVOKABLE bool initWithTargetAndOffset(cocos2d::Node* followedNode, float xOffset, float yOffset, const cocos2d::Rect& rect);
	bool isBoundarySet();
	Q_INVOKABLE cocos2d::Follow* reverse();
	void setBoundarySet(bool value);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithOffset(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Follow *)
Q_DECLARE_METATYPE(const cocos2d::Follow *)

namespace cocos2d {
class QtScriptImage : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptImage(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptImage(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int getBitPerPixel();
	Q_INVOKABLE QByteArray getData();
	Q_INVOKABLE ssize_t getDataLen();
	Q_INVOKABLE QByteArray getFilePath();
	Q_INVOKABLE int getFileType();
	Q_INVOKABLE int getHeight();
	Q_INVOKABLE int getNumberOfMipmaps();
	Q_INVOKABLE int getPixelFormat();
	Q_INVOKABLE int getWidth();
	Q_INVOKABLE bool hasAlpha();
	Q_INVOKABLE bool hasPremultipliedAlpha();
	Q_INVOKABLE bool initWithImageData(const QByteArray& arg0);
	Q_INVOKABLE bool initWithImageFile(const QByteArray& path);
	Q_INVOKABLE bool initWithRawData(const QByteArray& arg0, int arg1, int arg2, int arg3, bool arg4);
	Q_INVOKABLE bool isCompressed();
	Q_INVOKABLE void premultiplyAlpha();
	Q_INVOKABLE void reversePremultipliedAlpha();
	Q_INVOKABLE bool saveToFile(const QByteArray& filename);
	Q_INVOKABLE bool saveToFile(const QByteArray& filename, bool isToRGB);
	static QScriptValue setPNGPremultipliedAlphaEnabled(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setPVRImagesHavePremultipliedAlpha(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Image *)
Q_DECLARE_METATYPE(const cocos2d::Image *)

namespace cocos2d {
class QtScriptSpriteFrame : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptSpriteFrame(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSpriteFrame(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Vec2 anchorPoint READ getAnchorPoint WRITE setAnchorPoint)
	Q_PROPERTY(cocos2d::Vec2 offset READ getOffset WRITE setOffset)
	Q_PROPERTY(cocos2d::Vec2 offsetInPixels READ getOffsetInPixels WRITE setOffsetInPixels)
	Q_PROPERTY(cocos2d::Size originalSize READ getOriginalSize WRITE setOriginalSize)
	Q_PROPERTY(cocos2d::Size originalSizeInPixels READ getOriginalSizeInPixels WRITE setOriginalSizeInPixels)
	Q_PROPERTY(cocos2d::Rect rect READ getRect WRITE setRect)
	Q_PROPERTY(cocos2d::Rect rectInPixels READ getRectInPixels WRITE setRectInPixels)
	Q_PROPERTY(bool rotated READ isRotated WRITE setRotated)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	Q_INVOKABLE cocos2d::SpriteFrame* clone();
	cocos2d::Vec2 getAnchorPoint();
	Q_INVOKABLE cocos2d::Rect getCenterRect();
	cocos2d::Vec2 getOffset();
	cocos2d::Vec2 getOffsetInPixels();
	cocos2d::Size getOriginalSize();
	cocos2d::Size getOriginalSizeInPixels();
	cocos2d::Rect getRect();
	cocos2d::Rect getRectInPixels();
	cocos2d::Texture2D* getTexture();
	Q_INVOKABLE bool hasAnchorPoint();
	Q_INVOKABLE bool hasCenterRect();
	Q_INVOKABLE bool hasPolygonInfo();
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* pobTexture, const cocos2d::Rect& rect);
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* pobTexture, const cocos2d::Rect& rect, bool rotated, const cocos2d::Vec2& offset, const cocos2d::Size& originalSize);
	Q_INVOKABLE bool initWithTextureFilename(const QByteArray& filename, const cocos2d::Rect& rect);
	Q_INVOKABLE bool initWithTextureFilename(const QByteArray& filename, const cocos2d::Rect& rect, bool rotated, const cocos2d::Vec2& offset, const cocos2d::Size& originalSize);
	bool isRotated();
	void setAnchorPoint(const cocos2d::Vec2& anchorPoint);
	Q_INVOKABLE void setCenterRectInPixels(const cocos2d::Rect& centerRect);
	void setOffset(const cocos2d::Vec2& offsets);
	void setOffsetInPixels(const cocos2d::Vec2& offsetInPixels);
	void setOriginalSize(const cocos2d::Size& sizeInPixels);
	void setOriginalSizeInPixels(const cocos2d::Size& sizeInPixels);
	void setRect(const cocos2d::Rect& rect);
	void setRectInPixels(const cocos2d::Rect& rectInPixels);
	void setRotated(bool rotated);
	void setTexture(cocos2d::Texture2D* pobTexture);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SpriteFrame *)
Q_DECLARE_METATYPE(const cocos2d::SpriteFrame *)

namespace cocos2d {
class QtScriptAnimationFrame : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptAnimationFrame(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAnimationFrame(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float delayUnits READ getDelayUnits WRITE setDelayUnits)
	Q_PROPERTY(cocos2d::SpriteFrame* spriteFrame READ getSpriteFrame WRITE setSpriteFrame)
	Q_INVOKABLE cocos2d::AnimationFrame* clone();
	float getDelayUnits();
	cocos2d::SpriteFrame* getSpriteFrame();
	Q_INVOKABLE bool initWithSpriteFrame(cocos2d::SpriteFrame* arg0, float arg1);
	void setDelayUnits(float delayUnits);
	void setSpriteFrame(cocos2d::SpriteFrame* frame);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::AnimationFrame *)
Q_DECLARE_METATYPE(const cocos2d::AnimationFrame *)

namespace cocos2d {
class QtScriptAnimation : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptAnimation(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAnimation(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float delayPerUnit READ getDelayPerUnit WRITE setDelayPerUnit)
	Q_PROPERTY(cocos2d::Vector<cocos2d::AnimationFrame *> frames READ getFrames WRITE setFrames)
	Q_PROPERTY(unsigned int loops READ getLoops WRITE setLoops)
	Q_PROPERTY(bool restoreOriginalFrame READ getRestoreOriginalFrame WRITE setRestoreOriginalFrame)
	Q_INVOKABLE void addSpriteFrame(cocos2d::SpriteFrame* frame);
	Q_INVOKABLE void addSpriteFrameWithFile(const QByteArray& filename);
	Q_INVOKABLE void addSpriteFrameWithTexture(cocos2d::Texture2D* pobTexture, const cocos2d::Rect& rect);
	Q_INVOKABLE cocos2d::Animation* clone();
	float getDelayPerUnit();
	Q_INVOKABLE float getDuration();
	cocos2d::Vector<cocos2d::AnimationFrame *> getFrames();
	unsigned int getLoops();
	bool getRestoreOriginalFrame();
	Q_INVOKABLE float getTotalDelayUnits();
	Q_INVOKABLE bool init();
	Q_INVOKABLE bool initWithAnimationFrames(const cocos2d::Vector<cocos2d::AnimationFrame *>& arrayOfAnimationFrameNames, float delayPerUnit, unsigned int loops);
	Q_INVOKABLE bool initWithSpriteFrames(const cocos2d::Vector<cocos2d::SpriteFrame *>& arrayOfSpriteFrameNames);
	Q_INVOKABLE bool initWithSpriteFrames(const cocos2d::Vector<cocos2d::SpriteFrame *>& arrayOfSpriteFrameNames, float delay);
	Q_INVOKABLE bool initWithSpriteFrames(const cocos2d::Vector<cocos2d::SpriteFrame *>& arrayOfSpriteFrameNames, float delay, unsigned int loops);
	void setDelayPerUnit(float delayPerUnit);
	void setFrames(const cocos2d::Vector<cocos2d::AnimationFrame *>& frames);
	void setLoops(unsigned int loops);
	void setRestoreOriginalFrame(bool restoreOriginalFrame);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithSpriteFrames(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Animation *)
Q_DECLARE_METATYPE(const cocos2d::Animation *)

namespace cocos2d {
class QtScriptActionInterval : public QtScriptFiniteTimeAction
{
	Q_OBJECT

protected:
	explicit QtScriptActionInterval(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptActionInterval(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_INVOKABLE cocos2d::ActionInterval* clone();
	float getAmplitudeRate();
	Q_INVOKABLE float getElapsed();
	Q_INVOKABLE bool initWithDuration(float d);
	Q_INVOKABLE cocos2d::ActionInterval* reverse();
	void setAmplitudeRate(float amp);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ActionInterval *)
Q_DECLARE_METATYPE(const cocos2d::ActionInterval *)

namespace cocos2d {
class QtScriptSequence : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptSequence(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSequence(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Sequence* clone();
	Q_INVOKABLE bool init(const cocos2d::Vector<cocos2d::FiniteTimeAction *>& arrayOfActions);
	Q_INVOKABLE bool initWithTwoActions(cocos2d::FiniteTimeAction* pActionOne, cocos2d::FiniteTimeAction* pActionTwo);
	Q_INVOKABLE cocos2d::Sequence* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTwoActions(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Sequence *)
Q_DECLARE_METATYPE(const cocos2d::Sequence *)

namespace cocos2d {
class QtScriptRepeat : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptRepeat(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRepeat(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::FiniteTimeAction* innerAction READ getInnerAction WRITE setInnerAction)
	Q_INVOKABLE cocos2d::Repeat* clone();
	cocos2d::FiniteTimeAction* getInnerAction();
	Q_INVOKABLE bool initWithAction(cocos2d::FiniteTimeAction* pAction, unsigned int times);
	Q_INVOKABLE cocos2d::Repeat* reverse();
	void setInnerAction(cocos2d::FiniteTimeAction* action);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Repeat *)
Q_DECLARE_METATYPE(const cocos2d::Repeat *)

namespace cocos2d {
class QtScriptRepeatForever : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptRepeatForever(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRepeatForever(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::ActionInterval* innerAction READ getInnerAction WRITE setInnerAction)
	Q_INVOKABLE cocos2d::RepeatForever* clone();
	cocos2d::ActionInterval* getInnerAction();
	Q_INVOKABLE bool initWithAction(cocos2d::ActionInterval* action);
	Q_INVOKABLE cocos2d::RepeatForever* reverse();
	void setInnerAction(cocos2d::ActionInterval* action);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::RepeatForever *)
Q_DECLARE_METATYPE(const cocos2d::RepeatForever *)

namespace cocos2d {
class QtScriptSpawn : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptSpawn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSpawn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Spawn* clone();
	Q_INVOKABLE bool init(const cocos2d::Vector<cocos2d::FiniteTimeAction *>& arrayOfActions);
	Q_INVOKABLE bool initWithTwoActions(cocos2d::FiniteTimeAction* action1, cocos2d::FiniteTimeAction* action2);
	Q_INVOKABLE cocos2d::Spawn* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTwoActions(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Spawn *)
Q_DECLARE_METATYPE(const cocos2d::Spawn *)

namespace cocos2d {
class QtScriptRotateTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptRotateTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRotateTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void calculateAngles(float& startAngle, float& diffAngle, float dstAngle);
	Q_INVOKABLE cocos2d::RotateTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Vec3& dstAngle3D);
	Q_INVOKABLE bool initWithDuration(float duration, float dstAngleX, float dstAngleY);
	Q_INVOKABLE cocos2d::RotateTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::RotateTo *)
Q_DECLARE_METATYPE(const cocos2d::RotateTo *)

namespace cocos2d {
class QtScriptRotateBy : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptRotateBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRotateBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::RotateBy* clone();
	Q_INVOKABLE bool initWithDuration(float duration, float deltaAngle);
	Q_INVOKABLE bool initWithDuration(float duration, float deltaAngleZ_X, float deltaAngleZ_Y);
	Q_INVOKABLE cocos2d::RotateBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::RotateBy *)
Q_DECLARE_METATYPE(const cocos2d::RotateBy *)

namespace cocos2d {
class QtScriptMoveBy : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptMoveBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMoveBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::MoveBy* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Vec2& deltaPosition);
	Q_INVOKABLE cocos2d::MoveBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MoveBy *)
Q_DECLARE_METATYPE(const cocos2d::MoveBy *)

namespace cocos2d {
class QtScriptMoveTo : public QtScriptMoveBy
{
	Q_OBJECT

protected:
	explicit QtScriptMoveTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMoveTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::MoveTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Vec2& position);
	Q_INVOKABLE cocos2d::MoveTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MoveTo *)
Q_DECLARE_METATYPE(const cocos2d::MoveTo *)

namespace cocos2d {
class QtScriptSkewTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptSkewTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSkewTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::SkewTo* clone();
	Q_INVOKABLE bool initWithDuration(float t, float sx, float sy);
	Q_INVOKABLE cocos2d::SkewTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SkewTo *)
Q_DECLARE_METATYPE(const cocos2d::SkewTo *)

namespace cocos2d {
class QtScriptSkewBy : public QtScriptSkewTo
{
	Q_OBJECT

protected:
	explicit QtScriptSkewBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSkewBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::SkewBy* clone();
	Q_INVOKABLE bool initWithDuration(float t, float sx, float sy);
	Q_INVOKABLE cocos2d::SkewBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SkewBy *)
Q_DECLARE_METATYPE(const cocos2d::SkewBy *)

namespace cocos2d {
class QtScriptResizeTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptResizeTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptResizeTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ResizeTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& final_size);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ResizeTo *)
Q_DECLARE_METATYPE(const cocos2d::ResizeTo *)

namespace cocos2d {
class QtScriptResizeBy : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptResizeBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptResizeBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ResizeBy* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& deltaSize);
	Q_INVOKABLE cocos2d::ResizeBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ResizeBy *)
Q_DECLARE_METATYPE(const cocos2d::ResizeBy *)

namespace cocos2d {
class QtScriptJumpBy : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptJumpBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptJumpBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::JumpBy* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Vec2& position, float height, int jumps);
	Q_INVOKABLE cocos2d::JumpBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::JumpBy *)
Q_DECLARE_METATYPE(const cocos2d::JumpBy *)

namespace cocos2d {
class QtScriptJumpTo : public QtScriptJumpBy
{
	Q_OBJECT

protected:
	explicit QtScriptJumpTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptJumpTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::JumpTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Vec2& position, float height, int jumps);
	Q_INVOKABLE cocos2d::JumpTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::JumpTo *)
Q_DECLARE_METATYPE(const cocos2d::JumpTo *)

namespace cocos2d {
class QtScriptBezierConfig final : public QtScriptBaseClassPrototype<_ccBezierConfig, false>
{
	Q_OBJECT

protected:
	explicit QtScriptBezierConfig(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBezierConfig(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Vec2 controlPoint_1 READ _public_field_get_controlPoint_1 WRITE _public_field_set_controlPoint_1)
	cocos2d::Vec2 _public_field_get_controlPoint_1() const;
	void _public_field_set_controlPoint_1(const cocos2d::Vec2& value);
	Q_PROPERTY(cocos2d::Vec2 controlPoint_2 READ _public_field_get_controlPoint_2 WRITE _public_field_set_controlPoint_2)
	cocos2d::Vec2 _public_field_get_controlPoint_2() const;
	void _public_field_set_controlPoint_2(const cocos2d::Vec2& value);
	Q_PROPERTY(cocos2d::Vec2 endPosition READ _public_field_get_endPosition WRITE _public_field_set_endPosition)
	cocos2d::Vec2 _public_field_get_endPosition() const;
	void _public_field_set_endPosition(const cocos2d::Vec2& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ccBezierConfig)
Q_DECLARE_METATYPE(cocos2d::_ccBezierConfig *)
Q_DECLARE_METATYPE(const cocos2d::_ccBezierConfig *)

namespace cocos2d {
class QtScriptBezierBy : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptBezierBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBezierBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::BezierBy* clone();
	Q_INVOKABLE bool initWithDuration(float t, const cocos2d::_ccBezierConfig& c);
	Q_INVOKABLE cocos2d::BezierBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::BezierBy *)
Q_DECLARE_METATYPE(const cocos2d::BezierBy *)

namespace cocos2d {
class QtScriptBezierTo : public QtScriptBezierBy
{
	Q_OBJECT

protected:
	explicit QtScriptBezierTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBezierTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::BezierTo* clone();
	Q_INVOKABLE bool initWithDuration(float t, const cocos2d::_ccBezierConfig& c);
	Q_INVOKABLE cocos2d::BezierTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::BezierTo *)
Q_DECLARE_METATYPE(const cocos2d::BezierTo *)

namespace cocos2d {
class QtScriptScaleTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptScaleTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptScaleTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ScaleTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, float s);
	Q_INVOKABLE bool initWithDuration(float duration, float sx, float sy);
	Q_INVOKABLE bool initWithDuration(float duration, float sx, float sy, float sz);
	Q_INVOKABLE cocos2d::ScaleTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ScaleTo *)
Q_DECLARE_METATYPE(const cocos2d::ScaleTo *)

namespace cocos2d {
class QtScriptScaleBy : public QtScriptScaleTo
{
	Q_OBJECT

protected:
	explicit QtScriptScaleBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptScaleBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ScaleBy* clone();
	Q_INVOKABLE cocos2d::ScaleBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ScaleBy *)
Q_DECLARE_METATYPE(const cocos2d::ScaleBy *)

namespace cocos2d {
class QtScriptBlink : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptBlink(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBlink(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Blink* clone();
	Q_INVOKABLE bool initWithDuration(float duration, int blinks);
	Q_INVOKABLE cocos2d::Blink* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Blink *)
Q_DECLARE_METATYPE(const cocos2d::Blink *)

namespace cocos2d {
class QtScriptFadeTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptFadeTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFadeTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FadeTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, uint8_t opacity);
	Q_INVOKABLE cocos2d::FadeTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FadeTo *)
Q_DECLARE_METATYPE(const cocos2d::FadeTo *)

namespace cocos2d {
class QtScriptFadeIn : public QtScriptFadeTo
{
	Q_OBJECT

protected:
	explicit QtScriptFadeIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFadeIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FadeIn* clone();
	Q_INVOKABLE void setReverseAction(cocos2d::FadeTo* ac);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FadeIn *)
Q_DECLARE_METATYPE(const cocos2d::FadeIn *)

namespace cocos2d {
class QtScriptFadeOut : public QtScriptFadeTo
{
	Q_OBJECT

protected:
	explicit QtScriptFadeOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFadeOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FadeOut* clone();
	Q_INVOKABLE void setReverseAction(cocos2d::FadeTo* ac);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FadeOut *)
Q_DECLARE_METATYPE(const cocos2d::FadeOut *)

namespace cocos2d {
class QtScriptTintTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptTintTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTintTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::TintTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, uint8_t red, uint8_t green, uint8_t blue);
	Q_INVOKABLE cocos2d::TintTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TintTo *)
Q_DECLARE_METATYPE(const cocos2d::TintTo *)

namespace cocos2d {
class QtScriptTintBy : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptTintBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTintBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::TintBy* clone();
	Q_INVOKABLE bool initWithDuration(float duration, int16_t deltaRed, int16_t deltaGreen, int16_t deltaBlue);
	Q_INVOKABLE cocos2d::TintBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TintBy *)
Q_DECLARE_METATYPE(const cocos2d::TintBy *)

namespace cocos2d {
class QtScriptDelayTime : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptDelayTime(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDelayTime(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::DelayTime* clone();
	Q_INVOKABLE cocos2d::DelayTime* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::DelayTime *)
Q_DECLARE_METATYPE(const cocos2d::DelayTime *)

namespace cocos2d {
class QtScriptReverseTime : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptReverseTime(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptReverseTime(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ReverseTime* clone();
	Q_INVOKABLE bool initWithAction(cocos2d::FiniteTimeAction* action);
	Q_INVOKABLE cocos2d::ReverseTime* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ReverseTime *)
Q_DECLARE_METATYPE(const cocos2d::ReverseTime *)

namespace cocos2d {
class QtScriptAnimate : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptAnimate(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAnimate(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Animation* animation READ getAnimation WRITE setAnimation)
	Q_INVOKABLE cocos2d::Animate* clone();
	cocos2d::Animation* getAnimation();
	Q_INVOKABLE int getCurrentFrameIndex();
	Q_INVOKABLE bool initWithAnimation(cocos2d::Animation* animation);
	Q_INVOKABLE cocos2d::Animate* reverse();
	void setAnimation(cocos2d::Animation* animation);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Animate *)
Q_DECLARE_METATYPE(const cocos2d::Animate *)

namespace cocos2d {
class QtScriptTargetedAction : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptTargetedAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTargetedAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Node* forcedTarget READ getForcedTarget WRITE setForcedTarget)
	Q_INVOKABLE cocos2d::TargetedAction* clone();
	cocos2d::Node* getForcedTarget();
	Q_INVOKABLE bool initWithTarget(cocos2d::Node* target, cocos2d::FiniteTimeAction* action);
	Q_INVOKABLE cocos2d::TargetedAction* reverse();
	void setForcedTarget(cocos2d::Node* forcedTarget);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TargetedAction *)
Q_DECLARE_METATYPE(const cocos2d::TargetedAction *)

namespace cocos2d {
class QtScriptActionFloat : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptActionFloat(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptActionFloat(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ActionFloat* clone();
	Q_INVOKABLE bool initWithDuration(float duration, float from, float to, QScriptValue callback);
	Q_INVOKABLE cocos2d::ActionFloat* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ActionFloat *)
Q_DECLARE_METATYPE(const cocos2d::ActionFloat *)

namespace cocos2d {
class QtScriptAnimate3D : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptAnimate3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAnimate3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float originInterval READ getOriginInterval WRITE setOriginInterval)
	Q_PROPERTY(int quality READ getQuality WRITE setQuality)
	Q_PROPERTY(float speed READ getSpeed WRITE setSpeed)
	Q_PROPERTY(float weight READ getWeight WRITE setWeight)
	Q_INVOKABLE cocos2d::Animate3D* clone();
	float getOriginInterval();
	int getQuality();
	float getSpeed();
	float getWeight();
	Q_INVOKABLE bool init(cocos2d::Animation3D* animation);
	Q_INVOKABLE bool init(cocos2d::Animation3D* animation, float fromTime, float duration);
	Q_INVOKABLE bool initWithFrames(cocos2d::Animation3D* animation, int startFrame, int endFrame, float frameRate);
	Q_INVOKABLE void removeFromMap();
	Q_INVOKABLE cocos2d::Animate3D* reverse();
	void setOriginInterval(float interval);
	void setQuality(int quality);
	void setSpeed(float speed);
	void setWeight(float weight);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithFrames(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getTransitionTime(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setTransitionTime(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Animate3D *)
Q_DECLARE_METATYPE(const cocos2d::Animate3D *)

namespace cocos2d {
class QtScriptConfiguration : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptConfiguration(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptConfiguration(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool checkForGLExtension(const QByteArray& searchName);
	Q_INVOKABLE void gatherGPUInfo();
	Q_INVOKABLE int getAnimate3DQuality();
	Q_INVOKABLE QByteArray getInfo();
	Q_INVOKABLE int getMaxAttributes();
	Q_INVOKABLE int getMaxModelviewStackDepth();
	Q_INVOKABLE int getMaxSupportDirLightInShader();
	Q_INVOKABLE int getMaxSupportPointLightInShader();
	Q_INVOKABLE int getMaxSupportSpotLightInShader();
	Q_INVOKABLE int getMaxTextureSize();
	Q_INVOKABLE int getMaxTextureUnits();
	Q_INVOKABLE cocos2d::Value getValue(const QByteArray& key);
	Q_INVOKABLE cocos2d::Value getValue(const QByteArray& key, const cocos2d::Value& defaultValue);
	Q_INVOKABLE bool init();
	Q_INVOKABLE void loadConfigFile(const QByteArray& filename);
	Q_INVOKABLE void setValue(const QByteArray& key, const cocos2d::Value& value);
	Q_INVOKABLE bool supportsATITC();
	Q_INVOKABLE bool supportsBGRA8888();
	Q_INVOKABLE bool supportsDiscardFramebuffer();
	Q_INVOKABLE bool supportsETC();
	Q_INVOKABLE bool supportsMapBuffer();
	Q_INVOKABLE bool supportsNPOT();
	Q_INVOKABLE bool supportsOESDepth24();
	Q_INVOKABLE bool supportsOESPackedDepthStencil();
	Q_INVOKABLE bool supportsPVRTC();
	Q_INVOKABLE bool supportsS3TC();
	Q_INVOKABLE bool supportsShareableVAO();
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Configuration *)
Q_DECLARE_METATYPE(const cocos2d::Configuration *)

namespace cocos2d {
class QtScriptData final : public QtScriptBaseClassPrototype<Data, false>
{
	Q_OBJECT

protected:
	explicit QtScriptData(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptData(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void clear();
	Q_INVOKABLE ssize_t copy(const QByteArray& arg0);
	Q_INVOKABLE QByteArray getBytes();
	Q_INVOKABLE ssize_t getSize();
	Q_INVOKABLE bool isNull();
	Q_INVOKABLE void set(const cocos2d::Data& other);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Data)
Q_DECLARE_METATYPE(cocos2d::Data *)
Q_DECLARE_METATYPE(const cocos2d::Data *)

namespace cocos2d {
class QtScriptResizableBuffer : public QtScriptBaseClassPrototype<ResizableBuffer *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptResizableBuffer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptResizableBuffer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void* buffer();
	Q_INVOKABLE void resize(size_t size);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptResizableBuffer::StorageType)
Q_DECLARE_METATYPE(cocos2d::ResizableBuffer *)
Q_DECLARE_METATYPE(const cocos2d::ResizableBuffer *)

namespace cocos2d {
class QtScriptFileUtils : public QtScriptBaseClassPrototype<FileUtils *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptFileUtils(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFileUtils(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray defaultResourceRootPath READ getDefaultResourceRootPath WRITE setDefaultResourceRootPath)
	Q_PROPERTY(bool popupNotify READ isPopupNotify WRITE setPopupNotify)
	Q_PROPERTY(std::vector<std::string> searchPaths READ getSearchPaths WRITE setSearchPaths)
	Q_PROPERTY(std::vector<std::string> searchResolutionsOrder READ getSearchResolutionsOrder WRITE setSearchResolutionsOrder)
	Q_PROPERTY(QByteArray writablePath READ getWritablePath WRITE setWritablePath)
	Q_INVOKABLE void addSearchPath(const QByteArray& path);
	Q_INVOKABLE void addSearchPath(const QByteArray& path, const bool front);
	Q_INVOKABLE void addSearchResolutionsOrder(const QByteArray& order);
	Q_INVOKABLE void addSearchResolutionsOrder(const QByteArray& order, const bool front);
	Q_INVOKABLE bool createDirectory(const QByteArray& dirPath);
	Q_INVOKABLE void createDirectory(const QByteArray& dirPath, QScriptValue callback);
	Q_INVOKABLE QByteArray fullPathForFilename(const QByteArray& filename);
	Q_INVOKABLE QByteArray fullPathFromRelativeFile(const QByteArray& filename, const QByteArray& relativeFile);
	Q_INVOKABLE cocos2d::Data getDataFromFile(const QByteArray& filename);
	Q_INVOKABLE void getDataFromFile(const QByteArray& filename, QScriptValue callback);
	QByteArray getDefaultResourceRootPath();
	Q_INVOKABLE QByteArray getFileDataFromZip(const QByteArray& zipFilePath, const QByteArray& filename, long* size);
	Q_INVOKABLE QByteArray getFileExtension(const QByteArray& filePath);
	Q_INVOKABLE long getFileSize(const QByteArray& filepath);
	Q_INVOKABLE void getFileSize(const QByteArray& filepath, QScriptValue callback);
	Q_INVOKABLE std::vector<std::string> getOriginalSearchPaths();
	std::vector<std::string> getSearchPaths();
	std::vector<std::string> getSearchResolutionsOrder();
	Q_INVOKABLE QByteArray getStringFromFile(const QByteArray& filename);
	Q_INVOKABLE void getStringFromFile(const QByteArray& path, QScriptValue callback);
	QByteArray getWritablePath();
	Q_INVOKABLE bool isAbsolutePath(const QByteArray& path);
	Q_INVOKABLE bool isDirectoryExist(const QByteArray& dirPath);
	Q_INVOKABLE void isDirectoryExist(const QByteArray& fullPath, QScriptValue callback);
	Q_INVOKABLE bool isFileExist(const QByteArray& filename);
	Q_INVOKABLE void isFileExist(const QByteArray& filename, QScriptValue callback);
	bool isPopupNotify();
	Q_INVOKABLE std::vector<std::string> listFiles(const QByteArray& dirPath);
	Q_INVOKABLE void listFilesAsync(const QByteArray& dirPath, QScriptValue callback);
	Q_INVOKABLE void listFilesRecursively(const QByteArray& dirPath, std::vector<std::string>* files);
	Q_INVOKABLE void listFilesRecursivelyAsync(const QByteArray& dirPath, QScriptValue callback);
	Q_INVOKABLE void loadFilenameLookupDictionaryFromFile(const QByteArray& filename);
	Q_INVOKABLE void purgeCachedEntries();
	Q_INVOKABLE bool removeDirectory(const QByteArray& dirPath);
	Q_INVOKABLE void removeDirectory(const QByteArray& dirPath, QScriptValue callback);
	Q_INVOKABLE bool removeFile(const QByteArray& filepath);
	Q_INVOKABLE void removeFile(const QByteArray& filepath, QScriptValue callback);
	Q_INVOKABLE bool renameFile(const QByteArray& oldfullpath, const QByteArray& newfullpath);
	Q_INVOKABLE bool renameFile(const QByteArray& path, const QByteArray& oldname, const QByteArray& name);
	Q_INVOKABLE void renameFile(const QByteArray& path, const QByteArray& oldname, const QByteArray& name, QScriptValue callback);
	void setDefaultResourceRootPath(const QByteArray& path);
	void setPopupNotify(bool notify);
	void setSearchPaths(const std::vector<std::string>& searchPaths);
	void setSearchResolutionsOrder(const std::vector<std::string>& searchResolutionsOrder);
	void setWritablePath(const QByteArray& writablePath);
	Q_INVOKABLE bool writeDataToFile(const cocos2d::Data& data, const QByteArray& fullPath);
	Q_INVOKABLE void writeDataToFile(cocos2d::Data data, const QByteArray& fullPath, QScriptValue callback);
	Q_INVOKABLE bool writeStringToFile(const QByteArray& dataStr, const QByteArray& fullPath);
	Q_INVOKABLE void writeStringToFile(QByteArray dataStr, const QByteArray& fullPath, QScriptValue callback);
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptFileUtils::StorageType)
Q_DECLARE_METATYPE(cocos2d::FileUtils *)
Q_DECLARE_METATYPE(const cocos2d::FileUtils *)

namespace cocos2d {
class QtScriptZipFile : public QtScriptBaseClassPrototype<ZipFile *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptZipFile(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptZipFile(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool fileExists(const QByteArray& fileName);
	Q_INVOKABLE QByteArray getFileData(const QByteArray& fileName, long* size);
	Q_INVOKABLE QByteArray getFirstFilename();
	Q_INVOKABLE QByteArray getNextFilename();
	Q_INVOKABLE std::vector<std::string> listFiles(const QByteArray& pathname);
	Q_INVOKABLE bool setFilter(const QByteArray& filter);
	static QScriptValue createWithBuffer(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptZipFile::StorageType)
Q_DECLARE_METATYPE(cocos2d::ZipFile *)
Q_DECLARE_METATYPE(const cocos2d::ZipFile *)

namespace cocos2d {
class QtScriptMathUtil final : public QtScriptBaseClassPrototype<MathUtil, false>
{
	Q_OBJECT

protected:
	explicit QtScriptMathUtil(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMathUtil(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue lerp(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MathUtil)
Q_DECLARE_METATYPE(cocos2d::MathUtil *)
Q_DECLARE_METATYPE(const cocos2d::MathUtil *)

namespace cocos2d {
class QtScriptActionCamera : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptActionCamera(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptActionCamera(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Vec3 center READ getCenter WRITE setCenter)
	Q_PROPERTY(cocos2d::Vec3 eye READ getEye WRITE setEye)
	Q_PROPERTY(cocos2d::Vec3 up READ getUp WRITE setUp)
	Q_INVOKABLE cocos2d::ActionCamera* clone();
	cocos2d::Vec3 getCenter();
	cocos2d::Vec3 getEye();
	cocos2d::Vec3 getUp();
	Q_INVOKABLE cocos2d::ActionCamera* reverse();
	void setCenter(const cocos2d::Vec3& center);
	void setEye(const cocos2d::Vec3& eye);
	Q_INVOKABLE void setEye(float x, float y, float z);
	void setUp(const cocos2d::Vec3& up);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ActionCamera *)
Q_DECLARE_METATYPE(const cocos2d::ActionCamera *)

namespace cocos2d {
class QtScriptSphericalRadius final : public QtScriptBaseClassPrototype<SphericalRadius, false>
{
	Q_OBJECT

protected:
	explicit QtScriptSphericalRadius(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSphericalRadius(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float azimuth READ _public_field_get_azimuth WRITE _public_field_set_azimuth)
	float _public_field_get_azimuth() const;
	void _public_field_set_azimuth(float value);
	Q_PROPERTY(float radius READ _public_field_get_radius WRITE _public_field_set_radius)
	float _public_field_get_radius() const;
	void _public_field_set_radius(float value);
	Q_PROPERTY(float zenith READ _public_field_get_zenith WRITE _public_field_set_zenith)
	float _public_field_get_zenith() const;
	void _public_field_set_zenith(float value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SphericalRadius)
Q_DECLARE_METATYPE(cocos2d::SphericalRadius *)
Q_DECLARE_METATYPE(const cocos2d::SphericalRadius *)

namespace cocos2d {
class QtScriptOrbitCamera : public QtScriptActionCamera
{
	Q_OBJECT

protected:
	explicit QtScriptOrbitCamera(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptOrbitCamera(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::OrbitCamera* clone();
	Q_INVOKABLE cocos2d::SphericalRadius getSphericalRadius();
	Q_INVOKABLE bool initWithDuration(float t, float radius, float deltaRadius, float angleZ, float deltaAngleZ, float angleX, float deltaAngleX);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::OrbitCamera *)
Q_DECLARE_METATYPE(const cocos2d::OrbitCamera *)

namespace cocos2d {
class QtScriptPointArray : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptPointArray(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptPointArray(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void append(const cocos2d::Vec2& controlPoint);
	Q_INVOKABLE cocos2d::Vec2 at(ssize_t index);
	Q_INVOKABLE cocos2d::PointArray* clone();
	Q_INVOKABLE ssize_t count();
	Q_INVOKABLE bool initWithCapacity(ssize_t capacity);
	Q_INVOKABLE void insert(const cocos2d::Vec2& controlPoint, ssize_t index);
	Q_INVOKABLE void remove(ssize_t index);
	Q_INVOKABLE void replace(const cocos2d::Vec2& controlPoint, ssize_t index);
	Q_INVOKABLE cocos2d::PointArray* reverse();
	Q_INVOKABLE void reverseInline();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::PointArray *)
Q_DECLARE_METATYPE(const cocos2d::PointArray *)

namespace cocos2d {
class QtScriptCardinalSplineTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptCardinalSplineTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCardinalSplineTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::PointArray* points READ getPoints WRITE setPoints)
	Q_INVOKABLE cocos2d::CardinalSplineTo* clone();
	cocos2d::PointArray* getPoints();
	Q_INVOKABLE bool initWithDuration(float duration, cocos2d::PointArray* points, float tension);
	Q_INVOKABLE cocos2d::CardinalSplineTo* reverse();
	void setPoints(cocos2d::PointArray* points);
	Q_INVOKABLE void updatePosition(const cocos2d::Vec2& newPos);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CardinalSplineTo *)
Q_DECLARE_METATYPE(const cocos2d::CardinalSplineTo *)

namespace cocos2d {
class QtScriptCardinalSplineBy : public QtScriptCardinalSplineTo
{
	Q_OBJECT

protected:
	explicit QtScriptCardinalSplineBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCardinalSplineBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CardinalSplineBy* clone();
	Q_INVOKABLE cocos2d::CardinalSplineBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CardinalSplineBy *)
Q_DECLARE_METATYPE(const cocos2d::CardinalSplineBy *)

namespace cocos2d {
class QtScriptCatmullRomTo : public QtScriptCardinalSplineTo
{
	Q_OBJECT

protected:
	explicit QtScriptCatmullRomTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCatmullRomTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CatmullRomTo* clone();
	Q_INVOKABLE bool initWithDuration(float dt, cocos2d::PointArray* points);
	Q_INVOKABLE cocos2d::CatmullRomTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CatmullRomTo *)
Q_DECLARE_METATYPE(const cocos2d::CatmullRomTo *)

namespace cocos2d {
class QtScriptCatmullRomBy : public QtScriptCardinalSplineBy
{
	Q_OBJECT

protected:
	explicit QtScriptCatmullRomBy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCatmullRomBy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CatmullRomBy* clone();
	Q_INVOKABLE bool initWithDuration(float dt, cocos2d::PointArray* points);
	Q_INVOKABLE cocos2d::CatmullRomBy* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CatmullRomBy *)
Q_DECLARE_METATYPE(const cocos2d::CatmullRomBy *)

namespace cocos2d {
class QtScriptActionEase : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptActionEase(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptActionEase(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ActionInterval* getInnerAction();
	Q_INVOKABLE bool initWithAction(cocos2d::ActionInterval* action);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ActionEase *)
Q_DECLARE_METATYPE(const cocos2d::ActionEase *)

namespace cocos2d {
class QtScriptEaseRateAction : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseRateAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseRateAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rate READ getRate WRITE setRate)
	float getRate();
	Q_INVOKABLE bool initWithAction(cocos2d::ActionInterval* pAction, float fRate);
	void setRate(float rate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseRateAction *)
Q_DECLARE_METATYPE(const cocos2d::EaseRateAction *)

namespace cocos2d {
class QtScriptEaseExponentialIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseExponentialIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseExponentialIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseExponentialIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseExponentialIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseExponentialIn *)

namespace cocos2d {
class QtScriptEaseExponentialOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseExponentialOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseExponentialOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseExponentialOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseExponentialOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseExponentialOut *)

namespace cocos2d {
class QtScriptEaseExponentialInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseExponentialInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseExponentialInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseExponentialInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseExponentialInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseExponentialInOut *)

namespace cocos2d {
class QtScriptEaseSineIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseSineIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseSineIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseSineIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseSineIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseSineIn *)

namespace cocos2d {
class QtScriptEaseSineOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseSineOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseSineOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseSineOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseSineOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseSineOut *)

namespace cocos2d {
class QtScriptEaseSineInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseSineInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseSineInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseSineInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseSineInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseSineInOut *)

namespace cocos2d {
class QtScriptEaseBounce : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseBounce(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseBounce(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseBounce *)
Q_DECLARE_METATYPE(const cocos2d::EaseBounce *)

namespace cocos2d {
class QtScriptEaseBounceIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseBounceIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseBounceIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseBounceIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseBounceIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseBounceIn *)

namespace cocos2d {
class QtScriptEaseBounceOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseBounceOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseBounceOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseBounceOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseBounceOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseBounceOut *)

namespace cocos2d {
class QtScriptEaseBounceInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseBounceInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseBounceInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseBounceInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseBounceInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseBounceInOut *)

namespace cocos2d {
class QtScriptEaseBackIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseBackIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseBackIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseBackIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseBackIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseBackIn *)

namespace cocos2d {
class QtScriptEaseBackOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseBackOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseBackOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseBackOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseBackOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseBackOut *)

namespace cocos2d {
class QtScriptEaseBackInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseBackInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseBackInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseBackInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseBackInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseBackInOut *)

namespace cocos2d {
class QtScriptEaseQuadraticActionIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuadraticActionIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuadraticActionIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuadraticActionIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuadraticActionIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuadraticActionIn *)

namespace cocos2d {
class QtScriptEaseQuadraticActionOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuadraticActionOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuadraticActionOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuadraticActionOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuadraticActionOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuadraticActionOut *)

namespace cocos2d {
class QtScriptEaseQuadraticActionInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuadraticActionInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuadraticActionInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuadraticActionInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuadraticActionInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuadraticActionInOut *)

namespace cocos2d {
class QtScriptEaseQuarticActionIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuarticActionIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuarticActionIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuarticActionIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuarticActionIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuarticActionIn *)

namespace cocos2d {
class QtScriptEaseQuarticActionOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuarticActionOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuarticActionOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuarticActionOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuarticActionOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuarticActionOut *)

namespace cocos2d {
class QtScriptEaseQuarticActionInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuarticActionInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuarticActionInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuarticActionInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuarticActionInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuarticActionInOut *)

namespace cocos2d {
class QtScriptEaseQuinticActionIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuinticActionIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuinticActionIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuinticActionIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuinticActionIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuinticActionIn *)

namespace cocos2d {
class QtScriptEaseQuinticActionOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuinticActionOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuinticActionOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuinticActionOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuinticActionOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuinticActionOut *)

namespace cocos2d {
class QtScriptEaseQuinticActionInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseQuinticActionInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseQuinticActionInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseQuinticActionInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseQuinticActionInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseQuinticActionInOut *)

namespace cocos2d {
class QtScriptEaseCircleActionIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseCircleActionIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseCircleActionIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseCircleActionIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseCircleActionIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseCircleActionIn *)

namespace cocos2d {
class QtScriptEaseCircleActionOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseCircleActionOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseCircleActionOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseCircleActionOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseCircleActionOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseCircleActionOut *)

namespace cocos2d {
class QtScriptEaseCircleActionInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseCircleActionInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseCircleActionInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseCircleActionInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseCircleActionInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseCircleActionInOut *)

namespace cocos2d {
class QtScriptEaseCubicActionIn : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseCubicActionIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseCubicActionIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseCubicActionIn* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseCubicActionIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseCubicActionIn *)

namespace cocos2d {
class QtScriptEaseCubicActionOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseCubicActionOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseCubicActionOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseCubicActionOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseCubicActionOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseCubicActionOut *)

namespace cocos2d {
class QtScriptEaseCubicActionInOut : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseCubicActionInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseCubicActionInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseCubicActionInOut* clone();
	Q_INVOKABLE cocos2d::ActionEase* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseCubicActionInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseCubicActionInOut *)

namespace cocos2d {
class QtScriptEaseIn : public QtScriptEaseRateAction
{
	Q_OBJECT

protected:
	explicit QtScriptEaseIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseIn* clone();
	Q_INVOKABLE cocos2d::EaseRateAction* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseIn *)

namespace cocos2d {
class QtScriptEaseOut : public QtScriptEaseRateAction
{
	Q_OBJECT

protected:
	explicit QtScriptEaseOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseOut* clone();
	Q_INVOKABLE cocos2d::EaseRateAction* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseOut *)

namespace cocos2d {
class QtScriptEaseInOut : public QtScriptEaseRateAction
{
	Q_OBJECT

protected:
	explicit QtScriptEaseInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseInOut* clone();
	Q_INVOKABLE cocos2d::EaseRateAction* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseInOut *)

namespace cocos2d {
class QtScriptEaseElastic : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseElastic(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseElastic(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float period READ getPeriod WRITE setPeriod)
	float getPeriod();
	Q_INVOKABLE bool initWithAction(cocos2d::ActionInterval* action);
	Q_INVOKABLE bool initWithAction(cocos2d::ActionInterval* action, float period);
	void setPeriod(float fPeriod);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseElastic *)
Q_DECLARE_METATYPE(const cocos2d::EaseElastic *)

namespace cocos2d {
class QtScriptEaseElasticIn : public QtScriptEaseElastic
{
	Q_OBJECT

protected:
	explicit QtScriptEaseElasticIn(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseElasticIn(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseElasticIn* clone();
	Q_INVOKABLE cocos2d::EaseElastic* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseElasticIn *)
Q_DECLARE_METATYPE(const cocos2d::EaseElasticIn *)

namespace cocos2d {
class QtScriptEaseElasticOut : public QtScriptEaseElastic
{
	Q_OBJECT

protected:
	explicit QtScriptEaseElasticOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseElasticOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseElasticOut* clone();
	Q_INVOKABLE cocos2d::EaseElastic* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseElasticOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseElasticOut *)

namespace cocos2d {
class QtScriptEaseElasticInOut : public QtScriptEaseElastic
{
	Q_OBJECT

protected:
	explicit QtScriptEaseElasticInOut(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseElasticInOut(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseElasticInOut* clone();
	Q_INVOKABLE cocos2d::EaseElastic* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseElasticInOut *)
Q_DECLARE_METATYPE(const cocos2d::EaseElasticInOut *)

namespace cocos2d {
class QtScriptEaseBezierAction : public QtScriptActionEase
{
	Q_OBJECT

protected:
	explicit QtScriptEaseBezierAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptEaseBezierAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::EaseBezierAction* clone();
	Q_INVOKABLE cocos2d::EaseBezierAction* reverse();
	Q_INVOKABLE void setBezierParamer(float p0, float p1, float p2, float p3);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::EaseBezierAction *)
Q_DECLARE_METATYPE(const cocos2d::EaseBezierAction *)

namespace cocos2d {
class QtScriptActionInstant : public QtScriptFiniteTimeAction
{
	Q_OBJECT

protected:
	explicit QtScriptActionInstant(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptActionInstant(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ActionInstant* clone();
	Q_INVOKABLE cocos2d::ActionInstant* reverse();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ActionInstant *)
Q_DECLARE_METATYPE(const cocos2d::ActionInstant *)

namespace cocos2d {
class QtScriptShow : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptShow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptShow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Show* clone();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Show *)
Q_DECLARE_METATYPE(const cocos2d::Show *)

namespace cocos2d {
class QtScriptHide : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptHide(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptHide(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Hide* clone();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Hide *)
Q_DECLARE_METATYPE(const cocos2d::Hide *)

namespace cocos2d {
class QtScriptToggleVisibility : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptToggleVisibility(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptToggleVisibility(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ToggleVisibility* clone();
	Q_INVOKABLE cocos2d::ToggleVisibility* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ToggleVisibility *)
Q_DECLARE_METATYPE(const cocos2d::ToggleVisibility *)

namespace cocos2d {
class QtScriptRemoveSelf : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptRemoveSelf(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRemoveSelf(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::RemoveSelf* clone();
	Q_INVOKABLE bool init(bool isNeedCleanUp);
	Q_INVOKABLE cocos2d::RemoveSelf* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::RemoveSelf *)
Q_DECLARE_METATYPE(const cocos2d::RemoveSelf *)

namespace cocos2d {
class QtScriptFlipX : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptFlipX(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFlipX(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FlipX* clone();
	Q_INVOKABLE bool initWithFlipX(bool x);
	Q_INVOKABLE cocos2d::FlipX* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FlipX *)
Q_DECLARE_METATYPE(const cocos2d::FlipX *)

namespace cocos2d {
class QtScriptFlipY : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptFlipY(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFlipY(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FlipY* clone();
	Q_INVOKABLE bool initWithFlipY(bool y);
	Q_INVOKABLE cocos2d::FlipY* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FlipY *)
Q_DECLARE_METATYPE(const cocos2d::FlipY *)

namespace cocos2d {
class QtScriptPlace : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptPlace(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptPlace(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Place* clone();
	Q_INVOKABLE bool initWithPosition(const cocos2d::Vec2& pos);
	Q_INVOKABLE cocos2d::Place* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Place *)
Q_DECLARE_METATYPE(const cocos2d::Place *)

namespace cocos2d {
class QtScriptCallFunc : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCallFunc(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCallFunc(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CallFunc* clone();
	Q_INVOKABLE void execute();
	Q_INVOKABLE bool initWithFunction(QScriptValue func);
	Q_INVOKABLE cocos2d::CallFunc* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CallFunc *)
Q_DECLARE_METATYPE(const cocos2d::CallFunc *)

namespace cocos2d {
class QtScriptCallFuncN : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptCallFuncN(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCallFuncN(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::CallFuncN* clone();
	Q_INVOKABLE void execute();
	Q_INVOKABLE bool initWithFunction(QScriptValue func);
	Q_INVOKABLE cocos2d::CallFuncN* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CallFuncN *)
Q_DECLARE_METATYPE(const cocos2d::CallFuncN *)

namespace cocos2d {
class QtScriptGridAction : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptGridAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptGridAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::GridAction* clone();
	Q_INVOKABLE cocos2d::GridBase* getGrid();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize);
	Q_INVOKABLE cocos2d::GridAction* reverse();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::GridAction *)
Q_DECLARE_METATYPE(const cocos2d::GridAction *)

namespace cocos2d {
class QtScriptGrid3DAction : public QtScriptGridAction
{
	Q_OBJECT

protected:
	explicit QtScriptGrid3DAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptGrid3DAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Grid3DAction* clone();
	Q_INVOKABLE cocos2d::Rect getGridRect();
	Q_INVOKABLE cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2& position);
	Q_INVOKABLE cocos2d::Vec3 getVertex(const cocos2d::Vec2& position);
	Q_INVOKABLE void setVertex(const cocos2d::Vec2& position, const cocos2d::Vec3& vertex);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Grid3DAction *)
Q_DECLARE_METATYPE(const cocos2d::Grid3DAction *)

namespace cocos2d {
class QtScriptTiledGrid3DAction : public QtScriptGridAction
{
	Q_OBJECT

protected:
	explicit QtScriptTiledGrid3DAction(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTiledGrid3DAction(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::TiledGrid3DAction* clone();
	Q_INVOKABLE cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2& position);
	Q_INVOKABLE cocos2d::Quad3 getTile(const cocos2d::Vec2& position);
	Q_INVOKABLE void setTile(const cocos2d::Vec2& position, const cocos2d::Quad3& coords);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TiledGrid3DAction *)
Q_DECLARE_METATYPE(const cocos2d::TiledGrid3DAction *)

namespace cocos2d {
class QtScriptAccelDeccelAmplitude : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptAccelDeccelAmplitude(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAccelDeccelAmplitude(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rate READ getRate WRITE setRate)
	Q_INVOKABLE cocos2d::AccelDeccelAmplitude* clone();
	float getRate();
	Q_INVOKABLE bool initWithAction(cocos2d::Action* action, float duration);
	Q_INVOKABLE cocos2d::AccelDeccelAmplitude* reverse();
	void setRate(float rate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::AccelDeccelAmplitude *)
Q_DECLARE_METATYPE(const cocos2d::AccelDeccelAmplitude *)

namespace cocos2d {
class QtScriptAccelAmplitude : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptAccelAmplitude(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAccelAmplitude(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rate READ getRate WRITE setRate)
	Q_INVOKABLE cocos2d::AccelAmplitude* clone();
	float getRate();
	Q_INVOKABLE bool initWithAction(cocos2d::Action* action, float duration);
	Q_INVOKABLE cocos2d::AccelAmplitude* reverse();
	void setRate(float rate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::AccelAmplitude *)
Q_DECLARE_METATYPE(const cocos2d::AccelAmplitude *)

namespace cocos2d {
class QtScriptDeccelAmplitude : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptDeccelAmplitude(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDeccelAmplitude(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float rate READ getRate WRITE setRate)
	Q_INVOKABLE cocos2d::DeccelAmplitude* clone();
	float getRate();
	Q_INVOKABLE bool initWithAction(cocos2d::Action* action, float duration);
	Q_INVOKABLE cocos2d::DeccelAmplitude* reverse();
	void setRate(float rate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::DeccelAmplitude *)
Q_DECLARE_METATYPE(const cocos2d::DeccelAmplitude *)

namespace cocos2d {
class QtScriptStopGrid : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptStopGrid(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptStopGrid(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::StopGrid* clone();
	Q_INVOKABLE cocos2d::StopGrid* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::StopGrid *)
Q_DECLARE_METATYPE(const cocos2d::StopGrid *)

namespace cocos2d {
class QtScriptReuseGrid : public QtScriptActionInstant
{
	Q_OBJECT

protected:
	explicit QtScriptReuseGrid(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptReuseGrid(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ReuseGrid* clone();
	Q_INVOKABLE bool initWithTimes(int times);
	Q_INVOKABLE cocos2d::ReuseGrid* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ReuseGrid *)
Q_DECLARE_METATYPE(const cocos2d::ReuseGrid *)

namespace cocos2d {
class QtScriptWaves3D : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptWaves3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptWaves3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_INVOKABLE cocos2d::Waves3D* clone();
	float getAmplitude();
	float getAmplitudeRate();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, unsigned int waves, float amplitude);
	void setAmplitude(float amplitude);
	void setAmplitudeRate(float amplitudeRate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Waves3D *)
Q_DECLARE_METATYPE(const cocos2d::Waves3D *)

namespace cocos2d {
class QtScriptFlipX3D : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptFlipX3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFlipX3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FlipX3D* clone();
	Q_INVOKABLE bool initWithDuration(float duration);
	Q_INVOKABLE bool initWithSize(const cocos2d::Size& gridSize, float duration);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FlipX3D *)
Q_DECLARE_METATYPE(const cocos2d::FlipX3D *)

namespace cocos2d {
class QtScriptFlipY3D : public QtScriptFlipX3D
{
	Q_OBJECT

protected:
	explicit QtScriptFlipY3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFlipY3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FlipY3D* clone();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FlipY3D *)
Q_DECLARE_METATYPE(const cocos2d::FlipY3D *)

namespace cocos2d {
class QtScriptLens3D : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptLens3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLens3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float lensEffect READ getLensEffect WRITE setLensEffect)
	Q_PROPERTY(cocos2d::Vec2 position READ getPosition WRITE setPosition)
	Q_INVOKABLE cocos2d::Lens3D* clone();
	float getLensEffect();
	cocos2d::Vec2 getPosition();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, const cocos2d::Vec2& position, float radius);
	Q_INVOKABLE void setConcave(bool concave);
	void setLensEffect(float lensEffect);
	void setPosition(const cocos2d::Vec2& position);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Lens3D *)
Q_DECLARE_METATYPE(const cocos2d::Lens3D *)

namespace cocos2d {
class QtScriptRipple3D : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptRipple3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRipple3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_PROPERTY(cocos2d::Vec2 position READ getPosition WRITE setPosition)
	Q_INVOKABLE cocos2d::Ripple3D* clone();
	float getAmplitude();
	float getAmplitudeRate();
	cocos2d::Vec2 getPosition();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, const cocos2d::Vec2& position, float radius, unsigned int waves, float amplitude);
	void setAmplitude(float fAmplitude);
	void setAmplitudeRate(float fAmplitudeRate);
	void setPosition(const cocos2d::Vec2& position);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Ripple3D *)
Q_DECLARE_METATYPE(const cocos2d::Ripple3D *)

namespace cocos2d {
class QtScriptShaky3D : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptShaky3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptShaky3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Shaky3D* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, int range, bool shakeZ);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Shaky3D *)
Q_DECLARE_METATYPE(const cocos2d::Shaky3D *)

namespace cocos2d {
class QtScriptLiquid : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptLiquid(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLiquid(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_INVOKABLE cocos2d::Liquid* clone();
	float getAmplitude();
	float getAmplitudeRate();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, unsigned int waves, float amplitude);
	void setAmplitude(float amplitude);
	void setAmplitudeRate(float amplitudeRate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Liquid *)
Q_DECLARE_METATYPE(const cocos2d::Liquid *)

namespace cocos2d {
class QtScriptWaves : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptWaves(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptWaves(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_INVOKABLE cocos2d::Waves* clone();
	float getAmplitude();
	float getAmplitudeRate();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, unsigned int waves, float amplitude, bool horizontal, bool vertical);
	void setAmplitude(float amplitude);
	void setAmplitudeRate(float amplitudeRate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Waves *)
Q_DECLARE_METATYPE(const cocos2d::Waves *)

namespace cocos2d {
class QtScriptTwirl : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptTwirl(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTwirl(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_PROPERTY(cocos2d::Vec2 position READ getPosition WRITE setPosition)
	Q_INVOKABLE cocos2d::Twirl* clone();
	float getAmplitude();
	float getAmplitudeRate();
	cocos2d::Vec2 getPosition();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, const cocos2d::Vec2& position, unsigned int twirls, float amplitude);
	void setAmplitude(float amplitude);
	void setAmplitudeRate(float amplitudeRate);
	void setPosition(const cocos2d::Vec2& position);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Twirl *)
Q_DECLARE_METATYPE(const cocos2d::Twirl *)

namespace cocos2d {
class QtScriptActionManager : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptActionManager(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptActionManager(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addAction(cocos2d::Action* action, cocos2d::Node* target, bool paused);
	Q_INVOKABLE cocos2d::Action* getActionByTag(int tag, const cocos2d::Node* target);
	Q_INVOKABLE ssize_t getNumberOfRunningActions();
	Q_INVOKABLE ssize_t getNumberOfRunningActionsInTarget(const cocos2d::Node* target);
	Q_INVOKABLE size_t getNumberOfRunningActionsInTargetByTag(const cocos2d::Node* target, int tag);
	Q_INVOKABLE cocos2d::Vector<cocos2d::Node *> pauseAllRunningActions();
	Q_INVOKABLE void pauseTarget(cocos2d::Node* target);
	Q_INVOKABLE void removeAction(cocos2d::Action* action);
	Q_INVOKABLE void removeActionByTag(int tag, cocos2d::Node* target);
	Q_INVOKABLE void removeActionsByFlags(unsigned int flags, cocos2d::Node* target);
	Q_INVOKABLE void removeAllActions();
	Q_INVOKABLE void removeAllActionsByTag(int tag, cocos2d::Node* target);
	Q_INVOKABLE void removeAllActionsFromTarget(cocos2d::Node* target);
	Q_INVOKABLE void resumeTarget(cocos2d::Node* target);
	Q_INVOKABLE void resumeTargets(const cocos2d::Vector<cocos2d::Node *>& targetsToResume);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ActionManager *)
Q_DECLARE_METATYPE(const cocos2d::ActionManager *)

namespace cocos2d {
class QtScriptPageTurn3D : public QtScriptGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptPageTurn3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptPageTurn3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::PageTurn3D* clone();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::PageTurn3D *)
Q_DECLARE_METATYPE(const cocos2d::PageTurn3D *)

namespace cocos2d {
class QtScriptProgressTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptProgressTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptProgressTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ProgressTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, float percent);
	Q_INVOKABLE cocos2d::ProgressTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ProgressTo *)
Q_DECLARE_METATYPE(const cocos2d::ProgressTo *)

namespace cocos2d {
class QtScriptProgressFromTo : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptProgressFromTo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptProgressFromTo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ProgressFromTo* clone();
	Q_INVOKABLE bool initWithDuration(float duration, float fromPercentage, float toPercentage);
	Q_INVOKABLE cocos2d::ProgressFromTo* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ProgressFromTo *)
Q_DECLARE_METATYPE(const cocos2d::ProgressFromTo *)

namespace cocos2d {
class QtScriptShakyTiles3D : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptShakyTiles3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptShakyTiles3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ShakyTiles3D* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, int range, bool shakeZ);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ShakyTiles3D *)
Q_DECLARE_METATYPE(const cocos2d::ShakyTiles3D *)

namespace cocos2d {
class QtScriptShatteredTiles3D : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptShatteredTiles3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptShatteredTiles3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ShatteredTiles3D* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, int range, bool shatterZ);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ShatteredTiles3D *)
Q_DECLARE_METATYPE(const cocos2d::ShatteredTiles3D *)

namespace cocos2d {
class QtScriptShuffleTiles : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptShuffleTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptShuffleTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ShuffleTiles* clone();
	Q_INVOKABLE cocos2d::Size getDelta(const cocos2d::Size& pos);
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, unsigned int seed);
	Q_INVOKABLE void placeTile(const cocos2d::Vec2& pos, cocos2d::Tile* t);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ShuffleTiles *)
Q_DECLARE_METATYPE(const cocos2d::ShuffleTiles *)

namespace cocos2d {
class QtScriptFadeOutTRTiles : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptFadeOutTRTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFadeOutTRTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FadeOutTRTiles* clone();
	Q_INVOKABLE float testFunc(const cocos2d::Size& pos, float time);
	Q_INVOKABLE void transformTile(const cocos2d::Vec2& pos, float distance);
	Q_INVOKABLE void turnOffTile(const cocos2d::Vec2& pos);
	Q_INVOKABLE void turnOnTile(const cocos2d::Vec2& pos);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FadeOutTRTiles *)
Q_DECLARE_METATYPE(const cocos2d::FadeOutTRTiles *)

namespace cocos2d {
class QtScriptFadeOutBLTiles : public QtScriptFadeOutTRTiles
{
	Q_OBJECT

protected:
	explicit QtScriptFadeOutBLTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFadeOutBLTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FadeOutBLTiles* clone();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FadeOutBLTiles *)
Q_DECLARE_METATYPE(const cocos2d::FadeOutBLTiles *)

namespace cocos2d {
class QtScriptFadeOutUpTiles : public QtScriptFadeOutTRTiles
{
	Q_OBJECT

protected:
	explicit QtScriptFadeOutUpTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFadeOutUpTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FadeOutUpTiles* clone();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FadeOutUpTiles *)
Q_DECLARE_METATYPE(const cocos2d::FadeOutUpTiles *)

namespace cocos2d {
class QtScriptFadeOutDownTiles : public QtScriptFadeOutUpTiles
{
	Q_OBJECT

protected:
	explicit QtScriptFadeOutDownTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFadeOutDownTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FadeOutDownTiles* clone();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FadeOutDownTiles *)
Q_DECLARE_METATYPE(const cocos2d::FadeOutDownTiles *)

namespace cocos2d {
class QtScriptTurnOffTiles : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptTurnOffTiles(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTurnOffTiles(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::TurnOffTiles* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, unsigned int seed);
	Q_INVOKABLE void turnOffTile(const cocos2d::Vec2& pos);
	Q_INVOKABLE void turnOnTile(const cocos2d::Vec2& pos);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TurnOffTiles *)
Q_DECLARE_METATYPE(const cocos2d::TurnOffTiles *)

namespace cocos2d {
class QtScriptWavesTiles3D : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptWavesTiles3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptWavesTiles3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_INVOKABLE cocos2d::WavesTiles3D* clone();
	float getAmplitude();
	float getAmplitudeRate();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, unsigned int waves, float amplitude);
	void setAmplitude(float amplitude);
	void setAmplitudeRate(float amplitudeRate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::WavesTiles3D *)
Q_DECLARE_METATYPE(const cocos2d::WavesTiles3D *)

namespace cocos2d {
class QtScriptJumpTiles3D : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptJumpTiles3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptJumpTiles3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float amplitude READ getAmplitude WRITE setAmplitude)
	Q_PROPERTY(float amplitudeRate READ getAmplitudeRate WRITE setAmplitudeRate)
	Q_INVOKABLE cocos2d::JumpTiles3D* clone();
	float getAmplitude();
	float getAmplitudeRate();
	Q_INVOKABLE bool initWithDuration(float duration, const cocos2d::Size& gridSize, unsigned int numberOfJumps, float amplitude);
	void setAmplitude(float amplitude);
	void setAmplitudeRate(float amplitudeRate);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::JumpTiles3D *)
Q_DECLARE_METATYPE(const cocos2d::JumpTiles3D *)

namespace cocos2d {
class QtScriptSplitRows : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptSplitRows(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSplitRows(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::SplitRows* clone();
	Q_INVOKABLE bool initWithDuration(float duration, unsigned int rows);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SplitRows *)
Q_DECLARE_METATYPE(const cocos2d::SplitRows *)

namespace cocos2d {
class QtScriptSplitCols : public QtScriptTiledGrid3DAction
{
	Q_OBJECT

protected:
	explicit QtScriptSplitCols(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSplitCols(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::SplitCols* clone();
	Q_INVOKABLE bool initWithDuration(float duration, unsigned int cols);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SplitCols *)
Q_DECLARE_METATYPE(const cocos2d::SplitCols *)

namespace cocos2d {
class QtScriptActionTween : public QtScriptActionInterval
{
	Q_OBJECT

protected:
	explicit QtScriptActionTween(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptActionTween(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::ActionTween* clone();
	Q_INVOKABLE bool initWithDuration(float duration, const QByteArray& key, float from, float to);
	Q_INVOKABLE cocos2d::ActionTween* reverse();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ActionTween *)
Q_DECLARE_METATYPE(const cocos2d::ActionTween *)

namespace cocos2d {
class QtScriptAtlasNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptAtlasNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAtlasNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::TextureAtlas* textureAtlas READ getTextureAtlas WRITE setTextureAtlas)
	cocos2d::BlendFunc getBlendFunc();
	Q_INVOKABLE size_t getQuadsToDraw();
	cocos2d::Texture2D* getTexture();
	cocos2d::TextureAtlas* getTextureAtlas();
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* texture, int tileWidth, int tileHeight, int itemsToRender);
	Q_INVOKABLE bool initWithTileFile(const QByteArray& tile, int tileWidth, int tileHeight, int itemsToRender);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	Q_INVOKABLE void setQuadsToDraw(ssize_t quadsToDraw);
	void setTexture(cocos2d::Texture2D* texture);
	void setTextureAtlas(cocos2d::TextureAtlas* textureAtlas);
	Q_INVOKABLE void updateAtlasValues();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::AtlasNode *)
Q_DECLARE_METATYPE(const cocos2d::AtlasNode *)

namespace cocos2d {
class QtScriptGroupCommand : public QtScriptRenderCommand
{
	Q_OBJECT

protected:
	explicit QtScriptGroupCommand(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptGroupCommand(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int getRenderQueueID();
	Q_INVOKABLE void init(float globalOrder);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::GroupCommand *)
Q_DECLARE_METATYPE(const cocos2d::GroupCommand *)

namespace cocos2d {
class QtScriptCallbackCommand : public QtScriptRenderCommand
{
	Q_OBJECT

protected:
	explicit QtScriptCallbackCommand(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCallbackCommand(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void execute();
	Q_INVOKABLE void init(float globalZOrder);
	Q_INVOKABLE void init(float globalZorder, const cocos2d::Mat4& transform, unsigned int arg0);
	void setFunc(QScriptValue value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CallbackCommand *)
Q_DECLARE_METATYPE(const cocos2d::CallbackCommand *)

namespace cocos2d {
class QtScriptCaptureScreenCallbackCommand : public QtScriptRenderCommand
{
	Q_OBJECT

protected:
	explicit QtScriptCaptureScreenCallbackCommand(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCaptureScreenCallbackCommand(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void init(float globalZOrder);
	Q_INVOKABLE void setCallback(const QScriptValue& arg0);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CaptureScreenCallbackCommand *)
Q_DECLARE_METATYPE(const cocos2d::CaptureScreenCallbackCommand *)

namespace cocos2d {
class QtScriptClippingNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptClippingNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptClippingNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float alphaThreshold READ getAlphaThreshold WRITE setAlphaThreshold)
	Q_PROPERTY(bool inverted READ isInverted WRITE setInverted)
	Q_PROPERTY(cocos2d::Node* stencil READ getStencil WRITE setStencil)
	float getAlphaThreshold();
	cocos2d::Node* getStencil();
	Q_INVOKABLE bool hasContent();
	Q_INVOKABLE bool init(cocos2d::Node* stencil);
	bool isInverted();
	void setAlphaThreshold(float alphaThreshold);
	void setInverted(bool inverted);
	void setStencil(cocos2d::Node* stencil);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ClippingNode *)
Q_DECLARE_METATYPE(const cocos2d::ClippingNode *)

namespace cocos2d {
class QtScriptClippingRectangleNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptClippingRectangleNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptClippingRectangleNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool clippingEnabled READ isClippingEnabled WRITE setClippingEnabled)
	Q_PROPERTY(cocos2d::Rect clippingRegion READ getClippingRegion WRITE setClippingRegion)
	cocos2d::Rect getClippingRegion();
	bool isClippingEnabled();
	void setClippingEnabled(bool enabled);
	void setClippingRegion(const cocos2d::Rect& clippingRegion);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ClippingRectangleNode *)
Q_DECLARE_METATYPE(const cocos2d::ClippingRectangleNode *)

namespace cocos2d {
class QtScriptDrawNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptDrawNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDrawNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(bool isolated READ isIsolated WRITE setIsolated)
	Q_PROPERTY(float lineWidth READ getLineWidth WRITE setLineWidth)
	Q_INVOKABLE void clear();
	cocos2d::BlendFunc getBlendFunc();
	Q_INVOKABLE int getCapacity(int bufferType);
	float getLineWidth();
	Q_INVOKABLE int getSize(int bufferType);
	Q_INVOKABLE bool isEmpty(int bufferType);
	bool isIsolated();
	Q_INVOKABLE void reserve(int capacity, int bufferType);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	void setIsolated(bool isolated);
	void setLineWidth(float lineWidth);
	Q_INVOKABLE void shrink(int bufferType);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::DrawNode *)
Q_DECLARE_METATYPE(const cocos2d::DrawNode *)

namespace cocos2d {
class QtScriptFont : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptFont(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFont(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::FontAtlas* createFontAtlas();
	Q_INVOKABLE int getFontMaxHeight();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Font *)
Q_DECLARE_METATYPE(const cocos2d::Font *)

namespace cocos2d {
class QtScriptBMFontConfiguration : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptBMFontConfiguration(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBMFontConfiguration(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray atlasName READ getAtlasName WRITE setAtlasName)
	Q_INVOKABLE QByteArray description();
	QByteArray getAtlasName();
	Q_INVOKABLE bool initWithFNTfile(const QByteArray& FNTfile);
	void setAtlasName(const QByteArray& atlasName);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::BMFontConfiguration *)
Q_DECLARE_METATYPE(const cocos2d::BMFontConfiguration *)

namespace cocos2d {
class QtScriptFontFNT : public QtScriptFont
{
	Q_OBJECT

protected:
	explicit QtScriptFontFNT(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFontFNT(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float fontSize READ getFontSize WRITE setFontSize)
	float getFontSize();
	Q_INVOKABLE int getOriginalFontSize();
	void setFontSize(float fontSize);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue purgeCachedData(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue reloadBMFontResource(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FontFNT *)
Q_DECLARE_METATYPE(const cocos2d::FontFNT *)

namespace cocos2d {
class QtScriptFontLetterDefinition final : public QtScriptBaseClassPrototype<FontLetterDefinition, false>
{
	Q_OBJECT

protected:
	explicit QtScriptFontLetterDefinition(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFontLetterDefinition(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float U READ _public_field_get_U WRITE _public_field_set_U)
	float _public_field_get_U() const;
	void _public_field_set_U(float value);
	Q_PROPERTY(float V READ _public_field_get_V WRITE _public_field_set_V)
	float _public_field_get_V() const;
	void _public_field_set_V(float value);
	Q_PROPERTY(float height READ _public_field_get_height WRITE _public_field_set_height)
	float _public_field_get_height() const;
	void _public_field_set_height(float value);
	Q_PROPERTY(float offsetX READ _public_field_get_offsetX WRITE _public_field_set_offsetX)
	float _public_field_get_offsetX() const;
	void _public_field_set_offsetX(float value);
	Q_PROPERTY(float offsetY READ _public_field_get_offsetY WRITE _public_field_set_offsetY)
	float _public_field_get_offsetY() const;
	void _public_field_set_offsetY(float value);
	Q_PROPERTY(bool rotated READ _public_field_get_rotated WRITE _public_field_set_rotated)
	bool _public_field_get_rotated() const;
	void _public_field_set_rotated(const bool& value);
	Q_PROPERTY(int textureID READ _public_field_get_textureID WRITE _public_field_set_textureID)
	int _public_field_get_textureID() const;
	void _public_field_set_textureID(int value);
	Q_PROPERTY(bool validDefinition READ _public_field_get_validDefinition WRITE _public_field_set_validDefinition)
	bool _public_field_get_validDefinition() const;
	void _public_field_set_validDefinition(const bool& value);
	Q_PROPERTY(float width READ _public_field_get_width WRITE _public_field_set_width)
	float _public_field_get_width() const;
	void _public_field_set_width(float value);
	Q_PROPERTY(int xAdvance READ _public_field_get_xAdvance WRITE _public_field_set_xAdvance)
	int _public_field_get_xAdvance() const;
	void _public_field_set_xAdvance(int value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FontLetterDefinition)
Q_DECLARE_METATYPE(cocos2d::FontLetterDefinition *)
Q_DECLARE_METATYPE(const cocos2d::FontLetterDefinition *)

namespace cocos2d {
class QtScriptFontAtlas : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptFontAtlas(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFontAtlas(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float lineHeight READ getLineHeight WRITE setLineHeight)
	Q_INVOKABLE void addLetterDefinition(char32_t utf32Char, const cocos2d::FontLetterDefinition& letterDefinition);
	Q_INVOKABLE void addTexture(cocos2d::Texture2D* texture, int slot);
	Q_INVOKABLE const cocos2d::Font* getFont();
	Q_INVOKABLE QByteArray getFontName();
	Q_INVOKABLE bool getLetterDefinitionForChar(char32_t utf32Char, cocos2d::FontLetterDefinition& letterDefinition);
	float getLineHeight();
	Q_INVOKABLE cocos2d::Texture2D* getTexture(int slot);
	Q_INVOKABLE bool prepareLetterDefinitions(const QString& utf16String);
	Q_INVOKABLE void purgeTexturesAtlas();
	Q_INVOKABLE void setAliasTexParameters();
	Q_INVOKABLE void setAntiAliasTexParameters();
	void setLineHeight(float newHeight);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::FontAtlas *)
Q_DECLARE_METATYPE(const cocos2d::FontAtlas *)

namespace cocos2d {
class QtScriptTTFConfig final : public QtScriptBaseClassPrototype<_ttfConfig, false>
{
	Q_OBJECT

protected:
	explicit QtScriptTTFConfig(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTTFConfig(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool bold READ _public_field_get_bold WRITE _public_field_set_bold)
	bool _public_field_get_bold() const;
	void _public_field_set_bold(const bool& value);
	Q_PROPERTY(QByteArray customGlyphs READ _public_field_get_customGlyphs WRITE _public_field_set_customGlyphs)
	QByteArray _public_field_get_customGlyphs() const;
	void _public_field_set_customGlyphs(const QByteArray& value);
	Q_PROPERTY(bool distanceFieldEnabled READ _public_field_get_distanceFieldEnabled WRITE _public_field_set_distanceFieldEnabled)
	bool _public_field_get_distanceFieldEnabled() const;
	void _public_field_set_distanceFieldEnabled(const bool& value);
	Q_PROPERTY(QByteArray fontFilePath READ _public_field_get_fontFilePath WRITE _public_field_set_fontFilePath)
	QByteArray _public_field_get_fontFilePath() const;
	void _public_field_set_fontFilePath(const QByteArray& value);
	Q_PROPERTY(float fontSize READ _public_field_get_fontSize WRITE _public_field_set_fontSize)
	float _public_field_get_fontSize() const;
	void _public_field_set_fontSize(float value);
	Q_PROPERTY(int glyphs READ _public_field_get_glyphs WRITE _public_field_set_glyphs)
	int _public_field_get_glyphs() const;
	void _public_field_set_glyphs(int value);
	Q_PROPERTY(bool italics READ _public_field_get_italics WRITE _public_field_set_italics)
	bool _public_field_get_italics() const;
	void _public_field_set_italics(const bool& value);
	Q_PROPERTY(int outlineSize READ _public_field_get_outlineSize WRITE _public_field_set_outlineSize)
	int _public_field_get_outlineSize() const;
	void _public_field_set_outlineSize(int value);
	Q_PROPERTY(bool strikethrough READ _public_field_get_strikethrough WRITE _public_field_set_strikethrough)
	bool _public_field_get_strikethrough() const;
	void _public_field_set_strikethrough(const bool& value);
	Q_PROPERTY(bool underline READ _public_field_get_underline WRITE _public_field_set_underline)
	bool _public_field_get_underline() const;
	void _public_field_set_underline(const bool& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::_ttfConfig)
Q_DECLARE_METATYPE(cocos2d::_ttfConfig *)
Q_DECLARE_METATYPE(const cocos2d::_ttfConfig *)

namespace cocos2d {
class QtScriptLabel : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptLabel(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLabel(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float additionalKerning READ getAdditionalKerning WRITE setAdditionalKerning)
	Q_PROPERTY(float bMFontSize READ getBMFontSize WRITE setBMFontSize)
	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(bool clipMarginEnabled READ isClipMarginEnabled WRITE setClipMarginEnabled)
	Q_PROPERTY(float height READ getHeight WRITE setHeight)
	Q_PROPERTY(int horizontalAlignment READ getHorizontalAlignment WRITE setHorizontalAlignment)
	Q_PROPERTY(float lineHeight READ getLineHeight WRITE setLineHeight)
	Q_PROPERTY(float lineSpacing READ getLineSpacing WRITE setLineSpacing)
	Q_PROPERTY(float maxLineWidth READ getMaxLineWidth WRITE setMaxLineWidth)
	Q_PROPERTY(int overflow READ getOverflow WRITE setOverflow)
	Q_PROPERTY(QByteArray string READ getString WRITE setString)
	Q_PROPERTY(QByteArray systemFontName READ getSystemFontName WRITE setSystemFontName)
	Q_PROPERTY(float systemFontSize READ getSystemFontSize WRITE setSystemFontSize)
	Q_PROPERTY(cocos2d::Color4B textColor READ getTextColor WRITE setTextColor)
	Q_PROPERTY(int verticalAlignment READ getVerticalAlignment WRITE setVerticalAlignment)
	Q_PROPERTY(float width READ getWidth WRITE setWidth)
	Q_INVOKABLE void disableEffect();
	Q_INVOKABLE void disableEffect(int effect);
	Q_INVOKABLE void enableBold();
	Q_INVOKABLE void enableGlow(const cocos2d::Color4B& glowColor);
	Q_INVOKABLE void enableItalics();
	Q_INVOKABLE void enableOutline(const cocos2d::Color4B& outlineColor);
	Q_INVOKABLE void enableOutline(const cocos2d::Color4B& outlineColor, int outlineSize);
	Q_INVOKABLE void enableShadow();
	Q_INVOKABLE void enableShadow(const cocos2d::Color4B& shadowColor);
	Q_INVOKABLE void enableShadow(const cocos2d::Color4B& shadowColor, const cocos2d::Size& offset);
	Q_INVOKABLE void enableShadow(const cocos2d::Color4B& shadowColor, const cocos2d::Size& offset, int blurRadius);
	Q_INVOKABLE void enableStrikethrough();
	Q_INVOKABLE void enableUnderline();
	Q_INVOKABLE void enableWrap(bool enable);
	float getAdditionalKerning();
	Q_INVOKABLE QByteArray getBMFontFilePath();
	float getBMFontSize();
	cocos2d::BlendFunc getBlendFunc();
	Q_INVOKABLE cocos2d::Size getDimensions();
	Q_INVOKABLE cocos2d::Color4F getEffectColor();
	Q_INVOKABLE cocos2d::FontAtlas* getFontAtlas();
	float getHeight();
	int getHorizontalAlignment();
	Q_INVOKABLE int getLabelEffectType();
	Q_INVOKABLE int getLabelType();
	Q_INVOKABLE cocos2d::Sprite* getLetter(int lettetIndex);
	float getLineHeight();
	float getLineSpacing();
	float getMaxLineWidth();
	Q_INVOKABLE float getOutlineSize();
	int getOverflow();
	Q_INVOKABLE float getRenderingFontSize();
	Q_INVOKABLE float getShadowBlurRadius();
	Q_INVOKABLE cocos2d::Color4F getShadowColor();
	Q_INVOKABLE cocos2d::Size getShadowOffset();
	QByteArray getString();
	Q_INVOKABLE int getStringLength();
	Q_INVOKABLE int getStringNumLines();
	QByteArray getSystemFontName();
	float getSystemFontSize();
	Q_INVOKABLE cocos2d::_ttfConfig getTTFConfig();
	Q_INVOKABLE int getTextAlignment();
	cocos2d::Color4B getTextColor();
	int getVerticalAlignment();
	float getWidth();
	Q_INVOKABLE bool initWithTTF(const cocos2d::_ttfConfig& ttfConfig, const QByteArray& text);
	Q_INVOKABLE bool initWithTTF(const QByteArray& text, const QByteArray& fontFilePath, float fontSize);
	Q_INVOKABLE bool initWithTTF(const QByteArray& text, const QByteArray& fontFilePath, float fontSize, const cocos2d::Size& dimensions);
	Q_INVOKABLE bool initWithTTF(const QByteArray& text, const QByteArray& fontFilePath, float fontSize, const cocos2d::Size& dimensions, int hAlignment);
	Q_INVOKABLE bool initWithTTF(const QByteArray& text, const QByteArray& fontFilePath, float fontSize, const cocos2d::Size& dimensions, int hAlignment, int vAlignment);
	bool isClipMarginEnabled();
	Q_INVOKABLE bool isShadowEnabled();
	Q_INVOKABLE bool isWrapEnabled();
	Q_INVOKABLE void requestSystemFontRefresh();
	void setAdditionalKerning(float space);
	Q_INVOKABLE void setAlignment(int hAlignment);
	Q_INVOKABLE void setAlignment(int hAlignment, int vAlignment);
	Q_INVOKABLE bool setBMFontFilePath(const QByteArray& bmfontFilePath);
	Q_INVOKABLE bool setBMFontFilePath(const QByteArray& bmfontFilePath, float fontSize);
	Q_INVOKABLE bool setBMFontFilePath(const QByteArray& bmfontFilePath, const cocos2d::Rect& imageRect, bool imageRotated);
	Q_INVOKABLE bool setBMFontFilePath(const QByteArray& bmfontFilePath, const cocos2d::Rect& imageRect, bool imageRotated, float fontSize);
	void setBMFontSize(float fontSize);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	Q_INVOKABLE bool setCharMap(const QByteArray& plistFile);
	Q_INVOKABLE bool setCharMap(const QByteArray& charMapFile, int itemWidth, int itemHeight, int startCharMap);
	void setClipMarginEnabled(bool clipEnabled);
	Q_INVOKABLE void setDimensions(float width, float height);
	void setHeight(float height);
	void setHorizontalAlignment(int hAlignment);
	Q_INVOKABLE void setLineBreakWithoutSpace(bool breakWithoutSpace);
	void setLineHeight(float height);
	void setLineSpacing(float height);
	void setMaxLineWidth(float maxLineWidth);
	void setOverflow(int overflow);
	void setString(const QByteArray& text);
	void setSystemFontName(const QByteArray& font);
	void setSystemFontSize(float fontSize);
	Q_INVOKABLE bool setTTFConfig(const cocos2d::_ttfConfig& ttfConfig);
	void setTextColor(const cocos2d::Color4B& color);
	void setVerticalAlignment(int vAlignment);
	void setWidth(float width);
	Q_INVOKABLE void updateContent();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithBMFont(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithCharMap(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithSystemFont(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTTF(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Label *)
Q_DECLARE_METATYPE(const cocos2d::Label *)

namespace cocos2d {
class QtScriptLabelAtlas : public QtScriptAtlasNode
{
	Q_OBJECT

protected:
	explicit QtScriptLabelAtlas(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLabelAtlas(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray string READ getString WRITE setString)
	QByteArray getString();
	Q_INVOKABLE bool initWithString(const QByteArray& string, const QByteArray& fntFile);
	Q_INVOKABLE bool initWithString(const QByteArray& string, const QByteArray& charMapFile, int itemWidth, int itemHeight, int startCharMap);
	void setString(const QByteArray& label);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::LabelAtlas *)
Q_DECLARE_METATYPE(const cocos2d::LabelAtlas *)

namespace cocos2d {
class QtScriptLayer : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptLayer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLayer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Layer *)
Q_DECLARE_METATYPE(const cocos2d::Layer *)

namespace cocos2d {
class QtScriptLayerColor : public QtScriptLayer
{
	Q_OBJECT

protected:
	explicit QtScriptLayerColor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLayerColor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_INVOKABLE void changeHeight(float h);
	Q_INVOKABLE void changeWidth(float w);
	Q_INVOKABLE void changeWidthAndHeight(float w, float h);
	cocos2d::BlendFunc getBlendFunc();
	Q_INVOKABLE bool initWithColor(const cocos2d::Color4B& color);
	Q_INVOKABLE bool initWithColor(const cocos2d::Color4B& color, float width, float height);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::LayerColor *)
Q_DECLARE_METATYPE(const cocos2d::LayerColor *)

namespace cocos2d {
class QtScriptLayerGradient : public QtScriptLayerColor
{
	Q_OBJECT

protected:
	explicit QtScriptLayerGradient(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLayerGradient(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool compressedInterpolation READ isCompressedInterpolation WRITE setCompressedInterpolation)
	Q_PROPERTY(cocos2d::Color3B endColor READ getEndColor WRITE setEndColor)
	Q_PROPERTY(uint8_t endOpacity READ getEndOpacity WRITE setEndOpacity)
	Q_PROPERTY(cocos2d::Color3B startColor READ getStartColor WRITE setStartColor)
	Q_PROPERTY(uint8_t startOpacity READ getStartOpacity WRITE setStartOpacity)
	Q_PROPERTY(cocos2d::Vec2 vector READ getVector WRITE setVector)
	cocos2d::Color3B getEndColor();
	uint8_t getEndOpacity();
	cocos2d::Color3B getStartColor();
	uint8_t getStartOpacity();
	cocos2d::Vec2 getVector();
	Q_INVOKABLE bool initWithColor(const cocos2d::Color4B& start, const cocos2d::Color4B& end);
	Q_INVOKABLE bool initWithColor(const cocos2d::Color4B& start, const cocos2d::Color4B& end, const cocos2d::Vec2& v);
	bool isCompressedInterpolation();
	void setCompressedInterpolation(bool compressedInterpolation);
	void setEndColor(const cocos2d::Color3B& endColor);
	void setEndOpacity(uint8_t endOpacity);
	void setStartColor(const cocos2d::Color3B& startColor);
	void setStartOpacity(uint8_t startOpacity);
	void setVector(const cocos2d::Vec2& alongVector);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::LayerGradient *)
Q_DECLARE_METATYPE(const cocos2d::LayerGradient *)

namespace cocos2d {
class QtScriptLayerRadialGradient : public QtScriptLayer
{
	Q_OBJECT

protected:
	explicit QtScriptLayerRadialGradient(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLayerRadialGradient(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(cocos2d::Vec2 center READ getCenter WRITE setCenter)
	Q_PROPERTY(cocos2d::Color4B endColor READ getEndColor WRITE setEndColor)
	Q_PROPERTY(cocos2d::Color3B endColor3B READ getEndColor3B WRITE setEndColor3B)
	Q_PROPERTY(uint8_t endOpacity READ getEndOpacity WRITE setEndOpacity)
	Q_PROPERTY(float expand READ getExpand WRITE setExpand)
	Q_PROPERTY(float radius READ getRadius WRITE setRadius)
	Q_PROPERTY(cocos2d::Color4B startColor READ getStartColor WRITE setStartColor)
	Q_PROPERTY(cocos2d::Color3B startColor3B READ getStartColor3B WRITE setStartColor3B)
	Q_PROPERTY(uint8_t startOpacity READ getStartOpacity WRITE setStartOpacity)
	cocos2d::BlendFunc getBlendFunc();
	cocos2d::Vec2 getCenter();
	cocos2d::Color4B getEndColor();
	cocos2d::Color3B getEndColor3B();
	uint8_t getEndOpacity();
	float getExpand();
	float getRadius();
	cocos2d::Color4B getStartColor();
	cocos2d::Color3B getStartColor3B();
	uint8_t getStartOpacity();
	Q_INVOKABLE bool initWithColor(const cocos2d::Color4B& startColor, const cocos2d::Color4B& endColor, float radius, const cocos2d::Vec2& center, float expand);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	void setCenter(const cocos2d::Vec2& center);
	void setEndColor(const cocos2d::Color4B& color);
	void setEndColor3B(const cocos2d::Color3B& color);
	void setEndOpacity(uint8_t opacity);
	void setExpand(float expand);
	void setRadius(float radius);
	void setStartColor(const cocos2d::Color4B& color);
	void setStartColor3B(const cocos2d::Color3B& color);
	void setStartOpacity(uint8_t opacity);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::LayerRadialGradient *)
Q_DECLARE_METATYPE(const cocos2d::LayerRadialGradient *)

namespace cocos2d {
class QtScriptLayerMultiplex : public QtScriptLayer
{
	Q_OBJECT

protected:
	explicit QtScriptLayerMultiplex(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptLayerMultiplex(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addLayer(cocos2d::Layer* layer);
	Q_INVOKABLE bool initWithArray(const cocos2d::Vector<cocos2d::Layer *>& arrayOfLayers);
	Q_INVOKABLE void switchTo(int n);
	Q_INVOKABLE void switchTo(int n, bool cleanup);
	Q_INVOKABLE void switchToAndReleaseMe(int n);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithArray(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithLayer(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::LayerMultiplex *)
Q_DECLARE_METATYPE(const cocos2d::LayerMultiplex *)

namespace cocos2d {
class QtScriptMenuItem : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptMenuItem(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMenuItem(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
	Q_INVOKABLE bool initWithCallback(QScriptValue callback);
	bool isEnabled();
	Q_INVOKABLE bool isSelected();
	Q_INVOKABLE cocos2d::Rect rect();
	Q_INVOKABLE void setCallback(QScriptValue callback);
	void setEnabled(bool value);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MenuItem *)
Q_DECLARE_METATYPE(const cocos2d::MenuItem *)

namespace cocos2d {
class QtScriptMenuItemLabel : public QtScriptMenuItem
{
	Q_OBJECT

protected:
	explicit QtScriptMenuItemLabel(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMenuItemLabel(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Color3B disabledColor READ getDisabledColor WRITE setDisabledColor)
	Q_PROPERTY(cocos2d::Node* label READ getLabel WRITE setLabel)
	Q_PROPERTY(QByteArray string READ getString WRITE setString)
	cocos2d::Color3B getDisabledColor();
	cocos2d::Node* getLabel();
	QByteArray getString();
	Q_INVOKABLE bool initWithLabel(cocos2d::Node* label, QScriptValue callback);
	void setDisabledColor(const cocos2d::Color3B& color);
	void setLabel(cocos2d::Node* node);
	void setString(const QByteArray& label);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MenuItemLabel *)
Q_DECLARE_METATYPE(const cocos2d::MenuItemLabel *)

namespace cocos2d {
class QtScriptMenuItemAtlasFont : public QtScriptMenuItemLabel
{
	Q_OBJECT

protected:
	explicit QtScriptMenuItemAtlasFont(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMenuItemAtlasFont(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithString(const QByteArray& value, const QByteArray& charMapFile, int itemWidth, int itemHeight, char startCharMap, QScriptValue callback);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MenuItemAtlasFont *)
Q_DECLARE_METATYPE(const cocos2d::MenuItemAtlasFont *)

namespace cocos2d {
class QtScriptMenuItemFont : public QtScriptMenuItemLabel
{
	Q_OBJECT

protected:
	explicit QtScriptMenuItemFont(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMenuItemFont(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray fontName READ getFontName WRITE setFontName)
	Q_PROPERTY(int fontSize READ getFontSize WRITE setFontSize)
	QByteArray getFontName();
	int getFontSize();
	Q_INVOKABLE bool initWithString(const QByteArray& value, QScriptValue callback);
	void setFontName(const QByteArray& name);
	void setFontSize(int size);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getFontName(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getFontSize(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setFontName(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setFontSize(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MenuItemFont *)
Q_DECLARE_METATYPE(const cocos2d::MenuItemFont *)

namespace cocos2d {
class QtScriptMenuItemSprite : public QtScriptMenuItem
{
	Q_OBJECT

protected:
	explicit QtScriptMenuItemSprite(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMenuItemSprite(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Node* disabledImage READ getDisabledImage WRITE setDisabledImage)
	Q_PROPERTY(cocos2d::Node* normalImage READ getNormalImage WRITE setNormalImage)
	Q_PROPERTY(cocos2d::Node* selectedImage READ getSelectedImage WRITE setSelectedImage)
	cocos2d::Node* getDisabledImage();
	cocos2d::Node* getNormalImage();
	cocos2d::Node* getSelectedImage();
	Q_INVOKABLE bool initWithNormalSprite(cocos2d::Node* normalSprite, cocos2d::Node* selectedSprite, cocos2d::Node* disabledSprite, QScriptValue callback);
	void setDisabledImage(cocos2d::Node* image);
	void setNormalImage(cocos2d::Node* image);
	void setSelectedImage(cocos2d::Node* image);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MenuItemSprite *)
Q_DECLARE_METATYPE(const cocos2d::MenuItemSprite *)

namespace cocos2d {
class QtScriptMenuItemImage : public QtScriptMenuItemSprite
{
	Q_OBJECT

protected:
	explicit QtScriptMenuItemImage(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMenuItemImage(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool initWithNormalImage(const QByteArray& normalImage, const QByteArray& selectedImage, const QByteArray& disabledImage, QScriptValue callback);
	Q_INVOKABLE void setDisabledSpriteFrame(cocos2d::SpriteFrame* frame);
	Q_INVOKABLE void setNormalSpriteFrame(cocos2d::SpriteFrame* frame);
	Q_INVOKABLE void setSelectedSpriteFrame(cocos2d::SpriteFrame* frame);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MenuItemImage *)
Q_DECLARE_METATYPE(const cocos2d::MenuItemImage *)

namespace cocos2d {
class QtScriptMenuItemToggle : public QtScriptMenuItem
{
	Q_OBJECT

protected:
	explicit QtScriptMenuItemToggle(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMenuItemToggle(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int selectedIndex READ getSelectedIndex WRITE setSelectedIndex)
	Q_PROPERTY(cocos2d::Vector<cocos2d::MenuItem *> subItems READ getSubItems WRITE setSubItems)
	Q_INVOKABLE void addSubItem(cocos2d::MenuItem* item);
	unsigned int getSelectedIndex();
	Q_INVOKABLE cocos2d::MenuItem* getSelectedItem();
	cocos2d::Vector<cocos2d::MenuItem *> getSubItems();
	Q_INVOKABLE bool initWithItem(cocos2d::MenuItem* item);
	void setSelectedIndex(unsigned int index);
	void setSubItems(const cocos2d::Vector<cocos2d::MenuItem *>& items);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithCallback(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MenuItemToggle *)
Q_DECLARE_METATYPE(const cocos2d::MenuItemToggle *)

namespace cocos2d {
class QtScriptMenu : public QtScriptLayer
{
	Q_OBJECT

protected:
	explicit QtScriptMenu(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMenu(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
	Q_INVOKABLE void alignItemsHorizontally();
	Q_INVOKABLE void alignItemsHorizontallyWithPadding(float padding);
	Q_INVOKABLE void alignItemsVertically();
	Q_INVOKABLE void alignItemsVerticallyWithPadding(float padding);
	Q_INVOKABLE bool initWithArray(const cocos2d::Vector<cocos2d::MenuItem *>& arrayOfItems);
	bool isEnabled();
	void setEnabled(bool value);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithArray(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithItem(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Menu *)
Q_DECLARE_METATYPE(const cocos2d::Menu *)

namespace cocos2d {
class QtScriptMotionStreak : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptMotionStreak(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMotionStreak(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(bool fastMode READ isFastMode WRITE setFastMode)
	Q_PROPERTY(bool startingPositionInitialized READ isStartingPositionInitialized WRITE setStartingPositionInitialized)
	Q_PROPERTY(float stroke READ getStroke WRITE setStroke)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	cocos2d::BlendFunc getBlendFunc();
	float getStroke();
	cocos2d::Texture2D* getTexture();
	Q_INVOKABLE bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::Color3B& color, const QByteArray& path);
	bool isFastMode();
	bool isStartingPositionInitialized();
	Q_INVOKABLE void reset();
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	void setFastMode(bool bFastMode);
	void setStartingPositionInitialized(bool bStartingPositionInitialized);
	void setStroke(float stroke);
	void setTexture(cocos2d::Texture2D* texture);
	Q_INVOKABLE void tintWithColor(const cocos2d::Color3B& colors);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MotionStreak *)
Q_DECLARE_METATYPE(const cocos2d::MotionStreak *)

namespace cocos2d {
class QtScriptNodeGrid : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptNodeGrid(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptNodeGrid(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::GridBase* grid READ getGrid WRITE setGrid)
	Q_PROPERTY(cocos2d::Rect gridRect READ getGridRect WRITE setGridRect)
	cocos2d::GridBase* getGrid();
	cocos2d::Rect getGridRect();
	void setGrid(cocos2d::GridBase* grid);
	void setGridRect(const cocos2d::Rect& gridRect);
	Q_INVOKABLE void setTarget(cocos2d::Node* target);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::NodeGrid *)
Q_DECLARE_METATYPE(const cocos2d::NodeGrid *)

namespace cocos2d {
class QtScriptParticleBatchNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptParticleBatchNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleBatchNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::TextureAtlas* textureAtlas READ getTextureAtlas WRITE setTextureAtlas)
	Q_INVOKABLE void disableParticle(int particleIndex);
	cocos2d::BlendFunc getBlendFunc();
	cocos2d::Texture2D* getTexture();
	cocos2d::TextureAtlas* getTextureAtlas();
	Q_INVOKABLE bool initWithFile(const QByteArray& fileImage, int capacity);
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* tex, int capacity);
	Q_INVOKABLE void insertChild(cocos2d::ParticleSystem* system, int index);
	Q_INVOKABLE void removeChildAtIndex(int index, bool doCleanup);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	void setTexture(cocos2d::Texture2D* texture);
	void setTextureAtlas(cocos2d::TextureAtlas* atlas);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleBatchNode *)
Q_DECLARE_METATYPE(const cocos2d::ParticleBatchNode *)

namespace cocos2d {
class QtScriptParticleSystem : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptParticleSystem(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleSystem(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float angle READ getAngle WRITE setAngle)
	Q_PROPERTY(float angleVar READ getAngleVar WRITE setAngleVar)
	Q_PROPERTY(int atlasIndex READ getAtlasIndex WRITE setAtlasIndex)
	Q_PROPERTY(bool autoRemoveOnFinish READ isAutoRemoveOnFinish WRITE setAutoRemoveOnFinish)
	Q_PROPERTY(cocos2d::ParticleBatchNode* batchNode READ getBatchNode WRITE setBatchNode)
	Q_PROPERTY(bool blendAdditive READ isBlendAdditive WRITE setBlendAdditive)
	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(float duration READ getDuration WRITE setDuration)
	Q_PROPERTY(float emissionRate READ getEmissionRate WRITE setEmissionRate)
	Q_PROPERTY(int emitterMode READ getEmitterMode WRITE setEmitterMode)
	Q_PROPERTY(cocos2d::Color4F endColor READ getEndColor WRITE setEndColor)
	Q_PROPERTY(cocos2d::Color4F endColorVar READ getEndColorVar WRITE setEndColorVar)
	Q_PROPERTY(float endRadius READ getEndRadius WRITE setEndRadius)
	Q_PROPERTY(float endRadiusVar READ getEndRadiusVar WRITE setEndRadiusVar)
	Q_PROPERTY(float endSize READ getEndSize WRITE setEndSize)
	Q_PROPERTY(float endSizeVar READ getEndSizeVar WRITE setEndSizeVar)
	Q_PROPERTY(float endSpin READ getEndSpin WRITE setEndSpin)
	Q_PROPERTY(float endSpinVar READ getEndSpinVar WRITE setEndSpinVar)
	Q_PROPERTY(cocos2d::Vec2 gravity READ getGravity WRITE setGravity)
	Q_PROPERTY(float life READ getLife WRITE setLife)
	Q_PROPERTY(float lifeVar READ getLifeVar WRITE setLifeVar)
	Q_PROPERTY(cocos2d::Vec2 posVar READ getPosVar WRITE setPosVar)
	Q_PROPERTY(int positionType READ getPositionType WRITE setPositionType)
	Q_PROPERTY(float radialAccel READ getRadialAccel WRITE setRadialAccel)
	Q_PROPERTY(float radialAccelVar READ getRadialAccelVar WRITE setRadialAccelVar)
	Q_PROPERTY(float rotatePerSecond READ getRotatePerSecond WRITE setRotatePerSecond)
	Q_PROPERTY(float rotatePerSecondVar READ getRotatePerSecondVar WRITE setRotatePerSecondVar)
	Q_PROPERTY(bool rotationIsDir READ getRotationIsDir WRITE setRotationIsDir)
	Q_PROPERTY(cocos2d::Vec2 sourcePosition READ getSourcePosition WRITE setSourcePosition)
	Q_PROPERTY(bool sourcePositionCompatible READ isSourcePositionCompatible WRITE setSourcePositionCompatible)
	Q_PROPERTY(float speed READ getSpeed WRITE setSpeed)
	Q_PROPERTY(float speedVar READ getSpeedVar WRITE setSpeedVar)
	Q_PROPERTY(cocos2d::Color4F startColor READ getStartColor WRITE setStartColor)
	Q_PROPERTY(cocos2d::Color4F startColorVar READ getStartColorVar WRITE setStartColorVar)
	Q_PROPERTY(float startRadius READ getStartRadius WRITE setStartRadius)
	Q_PROPERTY(float startRadiusVar READ getStartRadiusVar WRITE setStartRadiusVar)
	Q_PROPERTY(float startSize READ getStartSize WRITE setStartSize)
	Q_PROPERTY(float startSizeVar READ getStartSizeVar WRITE setStartSizeVar)
	Q_PROPERTY(float startSpin READ getStartSpin WRITE setStartSpin)
	Q_PROPERTY(float startSpinVar READ getStartSpinVar WRITE setStartSpinVar)
	Q_PROPERTY(float tangentialAccel READ getTangentialAccel WRITE setTangentialAccel)
	Q_PROPERTY(float tangentialAccelVar READ getTangentialAccelVar WRITE setTangentialAccelVar)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(int totalParticles READ getTotalParticles WRITE setTotalParticles)
	Q_INVOKABLE void addParticles(int count);
	float getAngle();
	float getAngleVar();
	int getAtlasIndex();
	cocos2d::ParticleBatchNode* getBatchNode();
	cocos2d::BlendFunc getBlendFunc();
	float getDuration();
	float getEmissionRate();
	int getEmitterMode();
	cocos2d::Color4F getEndColor();
	cocos2d::Color4F getEndColorVar();
	float getEndRadius();
	float getEndRadiusVar();
	float getEndSize();
	float getEndSizeVar();
	float getEndSpin();
	float getEndSpinVar();
	cocos2d::Vec2 getGravity();
	float getLife();
	float getLifeVar();
	Q_INVOKABLE unsigned int getParticleCount();
	cocos2d::Vec2 getPosVar();
	int getPositionType();
	float getRadialAccel();
	float getRadialAccelVar();
	Q_INVOKABLE QByteArray getResourceFile();
	float getRotatePerSecond();
	float getRotatePerSecondVar();
	bool getRotationIsDir();
	cocos2d::Vec2 getSourcePosition();
	float getSpeed();
	float getSpeedVar();
	cocos2d::Color4F getStartColor();
	cocos2d::Color4F getStartColorVar();
	float getStartRadius();
	float getStartRadiusVar();
	float getStartSize();
	float getStartSizeVar();
	float getStartSpin();
	float getStartSpinVar();
	float getTangentialAccel();
	float getTangentialAccelVar();
	cocos2d::Texture2D* getTexture();
	int getTotalParticles();
	Q_INVOKABLE bool initWithData(const QByteArray& arg0);
	Q_INVOKABLE bool initWithFile(const QByteArray& plistFile);
	Q_INVOKABLE bool initWithTotalParticles(int numberOfParticles);
	Q_INVOKABLE bool isActive();
	bool isAutoRemoveOnFinish();
	bool isBlendAdditive();
	Q_INVOKABLE bool isFull();
	Q_INVOKABLE bool isPaused();
	bool isSourcePositionCompatible();
	Q_INVOKABLE void pauseEmissions();
	Q_INVOKABLE void postStep();
	Q_INVOKABLE void resetSystem();
	Q_INVOKABLE void resumeEmissions();
	void setAngle(float angle);
	void setAngleVar(float angleVar);
	void setAtlasIndex(int index);
	void setAutoRemoveOnFinish(bool var);
	void setBatchNode(cocos2d::ParticleBatchNode* batchNode);
	void setBlendAdditive(bool value);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	void setDuration(float duration);
	void setEmissionRate(float rate);
	void setEmitterMode(int mode);
	void setEndColor(const cocos2d::Color4F& color);
	void setEndColorVar(const cocos2d::Color4F& color);
	void setEndRadius(float endRadius);
	void setEndRadiusVar(float endRadiusVar);
	void setEndSize(float endSize);
	void setEndSizeVar(float sizeVar);
	void setEndSpin(float endSpin);
	void setEndSpinVar(float endSpinVar);
	void setGravity(const cocos2d::Vec2& g);
	void setLife(float life);
	void setLifeVar(float lifeVar);
	void setPosVar(const cocos2d::Vec2& pos);
	void setPositionType(int type);
	void setRadialAccel(float t);
	void setRadialAccelVar(float t);
	void setRotatePerSecond(float degrees);
	void setRotatePerSecondVar(float degrees);
	void setRotationIsDir(bool t);
	void setSourcePosition(const cocos2d::Vec2& pos);
	void setSourcePositionCompatible(bool sourcePositionCompatible);
	void setSpeed(float speed);
	void setSpeedVar(float speed);
	void setStartColor(const cocos2d::Color4F& color);
	void setStartColorVar(const cocos2d::Color4F& color);
	void setStartRadius(float startRadius);
	void setStartRadiusVar(float startRadiusVar);
	void setStartSize(float startSize);
	void setStartSizeVar(float sizeVar);
	void setStartSpin(float spin);
	void setStartSpinVar(float pinVar);
	void setTangentialAccel(float t);
	void setTangentialAccelVar(float t);
	void setTexture(cocos2d::Texture2D* texture);
	void setTotalParticles(int totalParticles);
	Q_INVOKABLE void start();
	Q_INVOKABLE void stop();
	Q_INVOKABLE void stopSystem();
	Q_INVOKABLE void updateWithNoTime();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getAllParticleSystems(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleSystem *)
Q_DECLARE_METATYPE(const cocos2d::ParticleSystem *)

namespace cocos2d {
class QtScriptParticleSystemQuad : public QtScriptParticleSystem
{
	Q_OBJECT

protected:
	explicit QtScriptParticleSystemQuad(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleSystemQuad(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setDisplayFrame(cocos2d::SpriteFrame* spriteFrame);
	Q_INVOKABLE void setTextureWithRect(cocos2d::Texture2D* texture, const cocos2d::Rect& rect);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleSystemQuad *)
Q_DECLARE_METATYPE(const cocos2d::ParticleSystemQuad *)

namespace cocos2d {
class QtScriptParticleFire : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleFire(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleFire(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleFire *)
Q_DECLARE_METATYPE(const cocos2d::ParticleFire *)

namespace cocos2d {
class QtScriptParticleFireworks : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleFireworks(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleFireworks(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleFireworks *)
Q_DECLARE_METATYPE(const cocos2d::ParticleFireworks *)

namespace cocos2d {
class QtScriptParticleSun : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleSun(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleSun(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleSun *)
Q_DECLARE_METATYPE(const cocos2d::ParticleSun *)

namespace cocos2d {
class QtScriptParticleGalaxy : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleGalaxy(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleGalaxy(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleGalaxy *)
Q_DECLARE_METATYPE(const cocos2d::ParticleGalaxy *)

namespace cocos2d {
class QtScriptParticleFlower : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleFlower(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleFlower(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleFlower *)
Q_DECLARE_METATYPE(const cocos2d::ParticleFlower *)

namespace cocos2d {
class QtScriptParticleMeteor : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleMeteor(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleMeteor(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleMeteor *)
Q_DECLARE_METATYPE(const cocos2d::ParticleMeteor *)

namespace cocos2d {
class QtScriptParticleSpiral : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleSpiral(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleSpiral(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleSpiral *)
Q_DECLARE_METATYPE(const cocos2d::ParticleSpiral *)

namespace cocos2d {
class QtScriptParticleExplosion : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleExplosion(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleExplosion(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleExplosion *)
Q_DECLARE_METATYPE(const cocos2d::ParticleExplosion *)

namespace cocos2d {
class QtScriptParticleSmoke : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleSmoke(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleSmoke(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleSmoke *)
Q_DECLARE_METATYPE(const cocos2d::ParticleSmoke *)

namespace cocos2d {
class QtScriptParticleSnow : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleSnow(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleSnow(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleSnow *)
Q_DECLARE_METATYPE(const cocos2d::ParticleSnow *)

namespace cocos2d {
class QtScriptParticleRain : public QtScriptParticleSystemQuad
{
	Q_OBJECT

protected:
	explicit QtScriptParticleRain(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParticleRain(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTotalParticles(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParticleRain *)
Q_DECLARE_METATYPE(const cocos2d::ParticleRain *)

namespace cocos2d {
class QtScriptProgressTimer : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptProgressTimer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptProgressTimer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Vec2 barChangeRate READ getBarChangeRate WRITE setBarChangeRate)
	Q_PROPERTY(cocos2d::Vec2 midpoint READ getMidpoint WRITE setMidpoint)
	Q_PROPERTY(float percentage READ getPercentage WRITE setPercentage)
	Q_PROPERTY(bool reverseDirection READ isReverseDirection WRITE setReverseDirection)
	Q_PROPERTY(cocos2d::Sprite* sprite READ getSprite WRITE setSprite)
	Q_PROPERTY(int type READ getType WRITE setType)
	cocos2d::Vec2 getBarChangeRate();
	cocos2d::Vec2 getMidpoint();
	float getPercentage();
	cocos2d::Sprite* getSprite();
	int getType();
	Q_INVOKABLE bool initWithSprite(cocos2d::Sprite* sp);
	bool isReverseDirection();
	void setBarChangeRate(const cocos2d::Vec2& barChangeRate);
	void setMidpoint(const cocos2d::Vec2& point);
	void setPercentage(float percentage);
	void setReverseDirection(bool value);
	void setSprite(cocos2d::Sprite* sprite);
	void setType(int type);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ProgressTimer *)
Q_DECLARE_METATYPE(const cocos2d::ProgressTimer *)

namespace cocos2d {
class QtScriptProtectedNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptProtectedNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptProtectedNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addProtectedChild(cocos2d::Node* child);
	Q_INVOKABLE void addProtectedChild(cocos2d::Node* child, int localZOrder);
	Q_INVOKABLE void addProtectedChild(cocos2d::Node* child, int localZOrder, int tag);
	Q_INVOKABLE void disableCascadeColor();
	Q_INVOKABLE void disableCascadeOpacity();
	Q_INVOKABLE cocos2d::Node* getProtectedChildByTag(int tag);
	Q_INVOKABLE void removeAllProtectedChildren();
	Q_INVOKABLE void removeAllProtectedChildrenWithCleanup(bool cleanup);
	Q_INVOKABLE void removeProtectedChild(cocos2d::Node* child);
	Q_INVOKABLE void removeProtectedChild(cocos2d::Node* child, bool cleanup);
	Q_INVOKABLE void removeProtectedChildByTag(int tag);
	Q_INVOKABLE void removeProtectedChildByTag(int tag, bool cleanup);
	Q_INVOKABLE void reorderProtectedChild(cocos2d::Node* child, int localZOrder);
	Q_INVOKABLE void sortAllProtectedChildren();
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ProtectedNode *)
Q_DECLARE_METATYPE(const cocos2d::ProtectedNode *)

namespace cocos2d {
class QtScriptTextureAtlas : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptTextureAtlas(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTextureAtlas(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool dirty READ isDirty WRITE setDirty)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	Q_INVOKABLE void fillWithEmptyQuadsFromIndex(ssize_t index, ssize_t amount);
	Q_INVOKABLE size_t getCapacity();
	Q_INVOKABLE QByteArray getDescription();
	cocos2d::Texture2D* getTexture();
	Q_INVOKABLE size_t getTotalQuads();
	Q_INVOKABLE void increaseTotalQuadsWith(ssize_t amount);
	Q_INVOKABLE bool initWithFile(const QByteArray& file, ssize_t capacity);
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* texture, ssize_t capacity);
	Q_INVOKABLE void insertQuad(const cocos2d::V3F_C4B_T2F_Quad& quad, ssize_t index);
	Q_INVOKABLE void insertQuadFromIndex(ssize_t fromIndex, ssize_t newIndex);
	bool isDirty();
	Q_INVOKABLE void moveQuadsFromIndex(ssize_t index, ssize_t newIndex);
	Q_INVOKABLE void moveQuadsFromIndex(ssize_t oldIndex, ssize_t amount, ssize_t newIndex);
	Q_INVOKABLE void removeAllQuads();
	Q_INVOKABLE void removeQuadAtIndex(ssize_t index);
	Q_INVOKABLE void removeQuadsAtIndex(ssize_t index, ssize_t amount);
	Q_INVOKABLE bool resizeCapacity(ssize_t capacity);
	void setDirty(bool bDirty);
	void setTexture(cocos2d::Texture2D* texture);
	Q_INVOKABLE void updateQuad(const cocos2d::V3F_C4B_T2F_Quad& quad, ssize_t index);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TextureAtlas *)
Q_DECLARE_METATYPE(const cocos2d::TextureAtlas *)

namespace cocos2d {
class QtScriptSprite : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptSprite(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSprite(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(unsigned int atlasIndex READ getAtlasIndex WRITE setAtlasIndex)
	Q_PROPERTY(cocos2d::SpriteBatchNode* batchNode READ getBatchNode WRITE setBatchNode)
	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(cocos2d::Rect centerRect READ getCenterRect WRITE setCenterRect)
	Q_PROPERTY(cocos2d::Rect centerRectNormalized READ getCenterRectNormalized WRITE setCenterRectNormalized)
	Q_PROPERTY(bool dirty READ isDirty WRITE setDirty)
	Q_PROPERTY(bool flippedX READ isFlippedX WRITE setFlippedX)
	Q_PROPERTY(bool flippedY READ isFlippedY WRITE setFlippedY)
	Q_PROPERTY(cocos2d::SpriteFrame* spriteFrame READ getSpriteFrame WRITE setSpriteFrame)
	Q_PROPERTY(bool stretchEnabled READ isStretchEnabled WRITE setStretchEnabled)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::TextureAtlas* textureAtlas READ getTextureAtlas WRITE setTextureAtlas)
	Q_PROPERTY(cocos2d::Rect textureRect READ getTextureRect WRITE setTextureRect)
	Q_INVOKABLE cocos2d::Sprite* clone();
	Q_INVOKABLE void copyPropertiesFrom(const cocos2d::Sprite* from);
	unsigned int getAtlasIndex();
	cocos2d::SpriteBatchNode* getBatchNode();
	cocos2d::BlendFunc getBlendFunc();
	cocos2d::Rect getCenterRect();
	cocos2d::Rect getCenterRectNormalized();
	Q_INVOKABLE cocos2d::Vec2 getOffsetPosition();
	Q_INVOKABLE cocos2d::V3F_C4B_T2F_Quad getQuad();
	Q_INVOKABLE QByteArray getResourceName();
	Q_INVOKABLE int getResourceType();
	cocos2d::SpriteFrame* getSpriteFrame();
	cocos2d::Texture2D* getTexture();
	cocos2d::TextureAtlas* getTextureAtlas();
	cocos2d::Rect getTextureRect();
	Q_INVOKABLE bool initWithFile(const QByteArray& filename);
	Q_INVOKABLE bool initWithFile(const QByteArray& filename, const cocos2d::Rect& rect);
	Q_INVOKABLE bool initWithPolygon(const cocos2d::PolygonInfo& info);
	Q_INVOKABLE bool initWithSpriteFrame(cocos2d::SpriteFrame* spriteFrame);
	Q_INVOKABLE bool initWithSpriteFrameName(const QByteArray& spriteFrameName);
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* texture);
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* texture, const cocos2d::Rect& rect);
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* texture, const cocos2d::Rect& rect, bool rotated);
	bool isDirty();
	bool isFlippedX();
	bool isFlippedY();
	Q_INVOKABLE bool isFrameDisplayed(cocos2d::SpriteFrame* frame);
	bool isStretchEnabled();
	Q_INVOKABLE bool isTextureRectRotated();
	void setAtlasIndex(unsigned int atlasIndex);
	void setBatchNode(cocos2d::SpriteBatchNode* spriteBatchNode);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	void setCenterRect(const cocos2d::Rect& rect);
	void setCenterRectNormalized(const cocos2d::Rect& rect);
	void setDirty(bool dirty);
	Q_INVOKABLE void setDisplayFrameWithAnimationName(const QByteArray& animationName, unsigned int frameIndex);
	void setFlippedX(bool flippedX);
	void setFlippedY(bool flippedY);
	void setSpriteFrame(cocos2d::SpriteFrame* newFrame);
	void setStretchEnabled(bool enabled);
	void setTexture(cocos2d::Texture2D* texture);
	void setTextureAtlas(cocos2d::TextureAtlas* textureAtlas);
	void setTextureRect(const cocos2d::Rect& rect);
	Q_INVOKABLE void setTextureRect(const cocos2d::Rect& rect, bool rotated, const cocos2d::Size& untrimmedSize);
	Q_INVOKABLE void setVertexLayout();
	Q_INVOKABLE void setVertexRect(const cocos2d::Rect& rect);
	Q_INVOKABLE void updateShaders(const QByteArray& vert, const QByteArray& frag);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithSpriteFrame(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithSpriteFrameName(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Sprite *)
Q_DECLARE_METATYPE(const cocos2d::Sprite *)

namespace cocos2d {
class QtScriptRenderTexture : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptRenderTexture(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRenderTexture(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool autoDraw READ isAutoDraw WRITE setAutoDraw)
	Q_PROPERTY(cocos2d::Color4F clearColor READ getClearColor WRITE setClearColor)
	Q_PROPERTY(float clearDepth READ getClearDepth WRITE setClearDepth)
	Q_PROPERTY(int clearFlags READ getClearFlags WRITE setClearFlags)
	Q_PROPERTY(int clearStencil READ getClearStencil WRITE setClearStencil)
	Q_PROPERTY(cocos2d::Sprite* sprite READ getSprite WRITE setSprite)
	Q_INVOKABLE void begin();
	Q_INVOKABLE void beginWithClear(float r, float g, float b, float a);
	Q_INVOKABLE void beginWithClear(float r, float g, float b, float a, float depthValue);
	Q_INVOKABLE void beginWithClear(float r, float g, float b, float a, float depthValue, int stencilValue);
	Q_INVOKABLE void clear(float r, float g, float b, float a);
	Q_INVOKABLE void clearDepth(float depthValue);
	Q_INVOKABLE void clearStencil(int stencilValue);
	Q_INVOKABLE void end();
	cocos2d::Color4F getClearColor();
	float getClearDepth();
	int getClearFlags();
	int getClearStencil();
	cocos2d::Sprite* getSprite();
	Q_INVOKABLE bool initWithWidthAndHeight(int w, int h, int format);
	Q_INVOKABLE bool initWithWidthAndHeight(int w, int h, int format, int depthStencilFormat);
	bool isAutoDraw();
	Q_INVOKABLE void newImage(QScriptValue imageCallback);
	Q_INVOKABLE void newImage(QScriptValue imageCallback, bool flipImage);
	Q_INVOKABLE bool saveToFile(const QByteArray& filename);
	Q_INVOKABLE bool saveToFile(const QByteArray& filename, bool isRGBA);
	Q_INVOKABLE bool saveToFile(const QByteArray& filename, bool isRGBA, QScriptValue callback);
	Q_INVOKABLE bool saveToFileAsNonPMA(const QByteArray& filename);
	Q_INVOKABLE bool saveToFileAsNonPMA(const QByteArray& filename, bool isRGBA);
	Q_INVOKABLE bool saveToFileAsNonPMA(const QByteArray& filename, bool isRGBA, QScriptValue callback);
	void setAutoDraw(bool isAutoDraw);
	void setClearColor(const cocos2d::Color4F& clearColor);
	void setClearDepth(float clearDepth);
	void setClearFlags(int clearFlags);
	void setClearStencil(int clearStencil);
	Q_INVOKABLE void setKeepMatrix(bool keepMatrix);
	void setSprite(cocos2d::Sprite* sprite);
	Q_INVOKABLE void setVirtualViewport(const cocos2d::Vec2& rtBegin, const cocos2d::Rect& fullRect, const cocos2d::Rect& fullViewport);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::RenderTexture *)
Q_DECLARE_METATYPE(const cocos2d::RenderTexture *)

namespace cocos2d {
class QtScriptOBB final : public QtScriptBaseClassPrototype<OBB, false>
{
	Q_OBJECT

protected:
	explicit QtScriptOBB(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptOBB(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool containPoint(const cocos2d::Vec3& point);
	Q_INVOKABLE bool intersects(const cocos2d::OBB& box);
	Q_INVOKABLE void reset();
	Q_INVOKABLE void set(const cocos2d::Vec3& center, const cocos2d::Vec3& _xAxis, const cocos2d::Vec3& _yAxis, const cocos2d::Vec3& _zAxis, const cocos2d::Vec3& _extents);
	Q_INVOKABLE void setAABB(const cocos2d::AABB& aabb);
	Q_INVOKABLE void transform(const cocos2d::Mat4& mat);
	Q_PROPERTY(cocos2d::Vec3 center READ _public_field_get_center WRITE _public_field_set_center)
	cocos2d::Vec3 _public_field_get_center() const;
	void _public_field_set_center(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 extentX READ _public_field_get_extentX WRITE _public_field_set_extentX)
	cocos2d::Vec3 _public_field_get_extentX() const;
	void _public_field_set_extentX(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 extentY READ _public_field_get_extentY WRITE _public_field_set_extentY)
	cocos2d::Vec3 _public_field_get_extentY() const;
	void _public_field_set_extentY(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 extentZ READ _public_field_get_extentZ WRITE _public_field_set_extentZ)
	cocos2d::Vec3 _public_field_get_extentZ() const;
	void _public_field_set_extentZ(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 extents READ _public_field_get_extents WRITE _public_field_set_extents)
	cocos2d::Vec3 _public_field_get_extents() const;
	void _public_field_set_extents(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 xAxis READ _public_field_get_xAxis WRITE _public_field_set_xAxis)
	cocos2d::Vec3 _public_field_get_xAxis() const;
	void _public_field_set_xAxis(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 yAxis READ _public_field_get_yAxis WRITE _public_field_set_yAxis)
	cocos2d::Vec3 _public_field_get_yAxis() const;
	void _public_field_set_yAxis(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 zAxis READ _public_field_get_zAxis WRITE _public_field_set_zAxis)
	cocos2d::Vec3 _public_field_get_zAxis() const;
	void _public_field_set_zAxis(const cocos2d::Vec3& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::OBB)
Q_DECLARE_METATYPE(cocos2d::OBB *)
Q_DECLARE_METATYPE(const cocos2d::OBB *)

namespace cocos2d {
class QtScriptPlane final : public QtScriptBaseClassPrototype<Plane, false>
{
	Q_OBJECT

protected:
	explicit QtScriptPlane(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptPlane(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE float dist2Plane(const cocos2d::Vec3& p);
	Q_INVOKABLE float getDist();
	Q_INVOKABLE cocos2d::Vec3 getNormal();
	Q_INVOKABLE int getSide(const cocos2d::Vec3& point);
	Q_INVOKABLE void initPlane(const cocos2d::Vec3& normal, float dist);
	Q_INVOKABLE void initPlane(const cocos2d::Vec3& p1, const cocos2d::Vec3& p2, const cocos2d::Vec3& p3);
	Q_INVOKABLE void initWithNormalAndPoint(const cocos2d::Vec3& normal, const cocos2d::Vec3& point);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Plane)
Q_DECLARE_METATYPE(cocos2d::Plane *)
Q_DECLARE_METATYPE(const cocos2d::Plane *)

namespace cocos2d {
class QtScriptFrustum final : public QtScriptBaseClassPrototype<Frustum, false>
{
	Q_OBJECT

protected:
	explicit QtScriptFrustum(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptFrustum(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool clipZ READ isClipZ WRITE setClipZ)
	Q_INVOKABLE bool initFrustum(const cocos2d::Camera* camera);
	bool isClipZ();
	Q_INVOKABLE bool isOutOfFrustum(const cocos2d::AABB& aabb);
	void setClipZ(bool clipZ);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Frustum)
Q_DECLARE_METATYPE(cocos2d::Frustum *)
Q_DECLARE_METATYPE(const cocos2d::Frustum *)

namespace cocos2d {
class QtScriptCamera : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptCamera(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCamera(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::CameraBackgroundBrush* backgroundBrush READ getBackgroundBrush WRITE setBackgroundBrush)
	Q_PROPERTY(int cameraFlag READ getCameraFlag WRITE setCameraFlag)
	Q_PROPERTY(int8_t depth READ getDepth WRITE setDepth)
	Q_INVOKABLE void apply();
	Q_INVOKABLE void applyViewport();
	Q_INVOKABLE void clearBackground();
	cocos2d::CameraBackgroundBrush* getBackgroundBrush();
	int getCameraFlag();
	int8_t getDepth();
	Q_INVOKABLE float getDepthInView(const cocos2d::Mat4& transform);
	Q_INVOKABLE float getFarPlane();
	Q_INVOKABLE float getNearPlane();
	Q_INVOKABLE cocos2d::Mat4 getProjectionMatrix();
	Q_INVOKABLE int getRenderOrder();
	Q_INVOKABLE int getType();
	Q_INVOKABLE cocos2d::Mat4 getViewMatrix();
	Q_INVOKABLE cocos2d::Mat4 getViewProjectionMatrix();
	Q_INVOKABLE bool initDefault();
	Q_INVOKABLE bool initOrthographic(float zoomX, float zoomY, float nearPlane, float farPlane);
	Q_INVOKABLE bool initPerspective(float fieldOfView, float aspectRatio, float nearPlane, float farPlane);
	Q_INVOKABLE bool isBrushValid();
	Q_INVOKABLE bool isViewProjectionUpdated();
	Q_INVOKABLE bool isVisibleInFrustum(const cocos2d::AABB* aabb);
	Q_INVOKABLE void lookAt(const cocos2d::Vec3& target);
	Q_INVOKABLE void lookAt(const cocos2d::Vec3& target, const cocos2d::Vec3& up);
	Q_INVOKABLE cocos2d::Vec2 project(const cocos2d::Vec3& src);
	Q_INVOKABLE cocos2d::Vec2 projectGL(const cocos2d::Vec3& src);
	Q_INVOKABLE void setAdditionalProjection(const cocos2d::Mat4& mat);
	void setBackgroundBrush(cocos2d::CameraBackgroundBrush* clearBrush);
	void setCameraFlag(int flag);
	void setDepth(int8_t depth);
	Q_INVOKABLE void setScene(cocos2d::Scene* scene);
	Q_INVOKABLE cocos2d::Vec3 unproject(const cocos2d::Vec3& src);
	Q_INVOKABLE void unproject(const cocos2d::Size& size, const cocos2d::Vec3* src, cocos2d::Vec3* dst);
	Q_INVOKABLE cocos2d::Vec3 unprojectGL(const cocos2d::Vec3& src);
	Q_INVOKABLE void unprojectGL(const cocos2d::Size& size, const cocos2d::Vec3* src, cocos2d::Vec3* dst);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createOrthographic(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createPerspective(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getDefaultCamera(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getDefaultViewport(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getVisitingCamera(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setDefaultViewport(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Camera *)
Q_DECLARE_METATYPE(const cocos2d::Camera *)

namespace cocos2d {
class QtScriptCameraBackgroundBrush : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptCameraBackgroundBrush(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCameraBackgroundBrush(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int getBrushType();
	Q_INVOKABLE bool init();
	Q_INVOKABLE bool isValid();
	static QScriptValue createColorBrush(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createDepthBrush(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createNoneBrush(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createSkyboxBrush(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CameraBackgroundBrush *)
Q_DECLARE_METATYPE(const cocos2d::CameraBackgroundBrush *)

namespace cocos2d {
class QtScriptCameraBackgroundDepthBrush : public QtScriptCameraBackgroundBrush
{
	Q_OBJECT

protected:
	explicit QtScriptCameraBackgroundDepthBrush(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCameraBackgroundDepthBrush(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setDepth(float depth);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CameraBackgroundDepthBrush *)
Q_DECLARE_METATYPE(const cocos2d::CameraBackgroundDepthBrush *)

namespace cocos2d {
class QtScriptCameraBackgroundColorBrush : public QtScriptCameraBackgroundDepthBrush
{
	Q_OBJECT

protected:
	explicit QtScriptCameraBackgroundColorBrush(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCameraBackgroundColorBrush(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void setColor(const cocos2d::Color4F& color);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CameraBackgroundColorBrush *)
Q_DECLARE_METATYPE(const cocos2d::CameraBackgroundColorBrush *)

namespace cocos2d {
class QtScriptCameraBackgroundSkyBoxBrush : public QtScriptCameraBackgroundBrush
{
	Q_OBJECT

protected:
	explicit QtScriptCameraBackgroundSkyBoxBrush(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptCameraBackgroundSkyBoxBrush(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool actived READ isActived WRITE setActived)
	bool isActived();
	void setActived(bool actived);
	Q_INVOKABLE void setTexture(cocos2d::TextureCube* texture);
	Q_INVOKABLE void setTextureValid(bool valid);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::CameraBackgroundSkyBoxBrush *)
Q_DECLARE_METATYPE(const cocos2d::CameraBackgroundSkyBoxBrush *)

namespace cocos2d {
class QtScriptGridBase : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptGridBase(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptGridBase(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool active READ isActive WRITE setActive)
	Q_PROPERTY(cocos2d::Rect gridRect READ getGridRect WRITE setGridRect)
	Q_PROPERTY(cocos2d::Size gridSize READ getGridSize WRITE setGridSize)
	Q_PROPERTY(int reuseGrid READ getReuseGrid WRITE setReuseGrid)
	Q_PROPERTY(cocos2d::Vec2 step READ getStep WRITE setStep)
	Q_PROPERTY(bool textureFlipped READ isTextureFlipped WRITE setTextureFlipped)
	cocos2d::Rect getGridRect();
	cocos2d::Size getGridSize();
	int getReuseGrid();
	cocos2d::Vec2 getStep();
	Q_INVOKABLE bool initWithSize(const cocos2d::Size& gridSize);
	Q_INVOKABLE bool initWithSize(const cocos2d::Size& gridSize, const cocos2d::Rect& rect);
	Q_INVOKABLE bool initWithSize(const cocos2d::Size& gridSize, cocos2d::Texture2D* texture, bool flipped);
	Q_INVOKABLE bool initWithSize(const cocos2d::Size& gridSize, cocos2d::Texture2D* texture, bool flipped, const cocos2d::Rect& rect);
	bool isActive();
	bool isTextureFlipped();
	void setActive(bool active);
	void setGridRect(const cocos2d::Rect& rect);
	void setGridSize(const cocos2d::Size& gridSize);
	void setReuseGrid(int reuseGrid);
	void setStep(const cocos2d::Vec2& step);
	void setTextureFlipped(bool flipped);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::GridBase *)
Q_DECLARE_METATYPE(const cocos2d::GridBase *)

namespace cocos2d {
class QtScriptGrid3D : public QtScriptGridBase
{
	Q_OBJECT

protected:
	explicit QtScriptGrid3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptGrid3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool needDepthTestForBlit READ getNeedDepthTestForBlit WRITE setNeedDepthTestForBlit)
	bool getNeedDepthTestForBlit();
	Q_INVOKABLE cocos2d::Vec3 getOriginalVertex(const cocos2d::Vec2& pos);
	Q_INVOKABLE cocos2d::Vec3 getVertex(const cocos2d::Vec2& pos);
	void setNeedDepthTestForBlit(bool neededDepthTest);
	Q_INVOKABLE void setVertex(const cocos2d::Vec2& pos, const cocos2d::Vec3& vertex);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Grid3D *)
Q_DECLARE_METATYPE(const cocos2d::Grid3D *)

namespace cocos2d {
class QtScriptTiledGrid3D : public QtScriptGridBase
{
	Q_OBJECT

protected:
	explicit QtScriptTiledGrid3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTiledGrid3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Quad3 getOriginalTile(const cocos2d::Vec2& pos);
	Q_INVOKABLE cocos2d::Quad3 getTile(const cocos2d::Vec2& pos);
	Q_INVOKABLE void setTile(const cocos2d::Vec2& pos, const cocos2d::Quad3& coords);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TiledGrid3D *)
Q_DECLARE_METATYPE(const cocos2d::TiledGrid3D *)

namespace cocos2d {
class QtScriptBaseLight : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptBaseLight(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBaseLight(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(bool enabled READ isEnabled WRITE setEnabled)
	Q_PROPERTY(float intensity READ getIntensity WRITE setIntensity)
	Q_PROPERTY(int lightFlag READ getLightFlag WRITE setLightFlag)
	float getIntensity();
	int getLightFlag();
	Q_INVOKABLE int getLightType();
	bool isEnabled();
	void setEnabled(bool enabled);
	void setIntensity(float intensity);
	void setLightFlag(int flag);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::BaseLight *)
Q_DECLARE_METATYPE(const cocos2d::BaseLight *)

namespace cocos2d {
class QtScriptDirectionLight : public QtScriptBaseLight
{
	Q_OBJECT

protected:
	explicit QtScriptDirectionLight(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDirectionLight(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Vec3 direction READ getDirection WRITE setDirection)
	cocos2d::Vec3 getDirection();
	Q_INVOKABLE cocos2d::Vec3 getDirectionInWorld();
	void setDirection(const cocos2d::Vec3& dir);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::DirectionLight *)
Q_DECLARE_METATYPE(const cocos2d::DirectionLight *)

namespace cocos2d {
class QtScriptPointLight : public QtScriptBaseLight
{
	Q_OBJECT

protected:
	explicit QtScriptPointLight(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptPointLight(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(float range READ getRange WRITE setRange)
	float getRange();
	void setRange(float range);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::PointLight *)
Q_DECLARE_METATYPE(const cocos2d::PointLight *)

namespace cocos2d {
class QtScriptSpotLight : public QtScriptBaseLight
{
	Q_OBJECT

protected:
	explicit QtScriptSpotLight(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSpotLight(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Vec3 direction READ getDirection WRITE setDirection)
	Q_PROPERTY(float innerAngle READ getInnerAngle WRITE setInnerAngle)
	Q_PROPERTY(float outerAngle READ getOuterAngle WRITE setOuterAngle)
	Q_PROPERTY(float range READ getRange WRITE setRange)
	Q_INVOKABLE float getCosInnerAngle();
	Q_INVOKABLE float getCosOuterAngle();
	cocos2d::Vec3 getDirection();
	Q_INVOKABLE cocos2d::Vec3 getDirectionInWorld();
	float getInnerAngle();
	float getOuterAngle();
	float getRange();
	void setDirection(const cocos2d::Vec3& dir);
	void setInnerAngle(float angle);
	void setOuterAngle(float outerAngle);
	void setRange(float range);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SpotLight *)
Q_DECLARE_METATYPE(const cocos2d::SpotLight *)

namespace cocos2d {
class QtScriptAmbientLight : public QtScriptBaseLight
{
	Q_OBJECT

protected:
	explicit QtScriptAmbientLight(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAmbientLight(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::AmbientLight *)
Q_DECLARE_METATYPE(const cocos2d::AmbientLight *)

namespace cocos2d {
class QtScriptRenderStateBlock final : public QtScriptBaseClassPrototype<RenderState::StateBlock, false>
{
	Q_OBJECT

protected:
	explicit QtScriptRenderStateBlock(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRenderStateBlock(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void bind(cocos2d::PipelineDescriptor* programState);
	Q_INVOKABLE uint32_t getHash();
	Q_INVOKABLE bool isDirty();
	Q_INVOKABLE void setBlend(bool enabled);
	Q_INVOKABLE void setBlendDst(int blend);
	Q_INVOKABLE void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	Q_INVOKABLE void setBlendSrc(int blend);
	Q_INVOKABLE void setCullFace(bool enabled);
	Q_INVOKABLE void setCullFaceSide(int side);
	Q_INVOKABLE void setDepthFunction(int func);
	Q_INVOKABLE void setDepthTest(bool enabled);
	Q_INVOKABLE void setDepthWrite(bool enabled);
	Q_INVOKABLE void setFrontFace(int winding);
	Q_INVOKABLE void setState(const QByteArray& name, const QByteArray& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::RenderState::StateBlock)
Q_DECLARE_METATYPE(cocos2d::RenderState::StateBlock *)
Q_DECLARE_METATYPE(const cocos2d::RenderState::StateBlock *)

namespace cocos2d {
class QtScriptRenderState : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptRenderState(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRenderState(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE QByteArray getName();
	Q_INVOKABLE cocos2d::RenderState::StateBlock getStateBlock();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::RenderState *)
Q_DECLARE_METATYPE(const cocos2d::RenderState *)

namespace cocos2d {
class QtScriptTechnique : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptTechnique(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTechnique(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addPass(cocos2d::Pass* pass);
	Q_INVOKABLE cocos2d::Technique* clone();
	Q_INVOKABLE QByteArray getName();
	Q_INVOKABLE cocos2d::Pass* getPassByIndex(ssize_t index);
	Q_INVOKABLE ssize_t getPassCount();
	Q_INVOKABLE cocos2d::Vector<cocos2d::Pass *> getPasses();
	Q_INVOKABLE cocos2d::RenderState::StateBlock getStateBlock();
	Q_INVOKABLE void setMaterial(cocos2d::Material* material);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithProgramState(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Technique *)
Q_DECLARE_METATYPE(const cocos2d::Technique *)

namespace cocos2d {
class QtScriptMaterial : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptMaterial(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMaterial(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray name READ getName WRITE setName)
	Q_PROPERTY(cocos2d::RenderState::StateBlock stateBlock READ getStateBlock WRITE setStateBlock)
	Q_INVOKABLE void addTechnique(cocos2d::Technique* technique);
	Q_INVOKABLE cocos2d::Material* clone();
	QByteArray getName();
	Q_INVOKABLE cocos2d::RenderState* getRenderState();
	cocos2d::RenderState::StateBlock getStateBlock();
	Q_INVOKABLE cocos2d::Technique* getTechnique();
	Q_INVOKABLE cocos2d::Technique* getTechniqueByIndex(ssize_t index);
	Q_INVOKABLE cocos2d::Technique* getTechniqueByName(const QByteArray& name);
	Q_INVOKABLE ssize_t getTechniqueCount();
	void setName(const QByteArray& name);
	void setStateBlock(const cocos2d::RenderState::StateBlock& state);
	Q_INVOKABLE void setTechnique(const QByteArray& techniqueName);
	static QScriptValue createWithFilename(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithProgramState(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Material *)
Q_DECLARE_METATYPE(const cocos2d::Material *)

namespace cocos2d {
class QtScriptPass : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptPass(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptPass(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(QByteArray name READ getName WRITE setName)
	Q_INVOKABLE cocos2d::Pass* clone();
	QByteArray getName();
	Q_INVOKABLE cocos2d::backend::ProgramState* getProgramState();
	Q_INVOKABLE cocos2d::RenderState::StateBlock getStateBlock();
	Q_INVOKABLE cocos2d::VertexAttribBinding* getVertexAttributeBinding();
	void setName(const QByteArray& name);
	Q_INVOKABLE void setTechnique(cocos2d::Technique* technique);
	Q_INVOKABLE void setVertexAttribBinding(cocos2d::VertexAttribBinding* binding);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithProgramState(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Pass *)
Q_DECLARE_METATYPE(const cocos2d::Pass *)

namespace cocos2d {
class QtScriptRenderer final : public QtScriptBaseClassPrototype<Renderer, false>
{
	Q_OBJECT

protected:
	explicit QtScriptRenderer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRenderer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int cullMode READ getCullMode WRITE setCullMode)
	Q_PROPERTY(int depthCompareFunction READ getDepthCompareFunction WRITE setDepthCompareFunction)
	Q_PROPERTY(bool depthTest READ getDepthTest WRITE setDepthTest)
	Q_PROPERTY(bool depthWrite READ getDepthWrite WRITE setDepthWrite)
	Q_PROPERTY(bool scissorTest READ getScissorTest WRITE setScissorTest)
	Q_PROPERTY(bool stencilTest READ getStencilTest WRITE setStencilTest)
	Q_PROPERTY(unsigned int stencilWriteMask READ getStencilWriteMask WRITE setStencilWriteMask)
	Q_PROPERTY(int winding READ getWinding WRITE setWinding)
	Q_INVOKABLE void addCommand(cocos2d::RenderCommand* command);
	Q_INVOKABLE void addCommand(cocos2d::RenderCommand* command, int renderQueueID);
	Q_INVOKABLE void addDrawnBatches(ssize_t number);
	Q_INVOKABLE void addDrawnVertices(ssize_t number);
	Q_INVOKABLE bool checkVisibility(const cocos2d::Mat4& transform, const cocos2d::Size& size);
	Q_INVOKABLE void clean();
	Q_INVOKABLE void clear(int flags, const cocos2d::Color4F& color, float depth, unsigned int stencil, float globalOrder);
	Q_INVOKABLE void clearDrawStats();
	Q_INVOKABLE int createRenderQueue();
	Q_INVOKABLE cocos2d::Color4F getClearColor();
	Q_INVOKABLE float getClearDepth();
	Q_INVOKABLE int getClearFlag();
	Q_INVOKABLE unsigned int getClearStencil();
	Q_INVOKABLE cocos2d::Texture2D* getColorAttachment();
	int getCullMode();
	Q_INVOKABLE cocos2d::Texture2D* getDepthAttachment();
	int getDepthCompareFunction();
	bool getDepthTest();
	bool getDepthWrite();
	Q_INVOKABLE ssize_t getDrawnBatches();
	Q_INVOKABLE ssize_t getDrawnVertices();
	Q_INVOKABLE int getRenderTargetFlag();
	Q_INVOKABLE cocos2d::ScissorRect getScissorRect();
	bool getScissorTest();
	Q_INVOKABLE cocos2d::Texture2D* getStencilAttachment();
	Q_INVOKABLE int getStencilCompareFunction();
	Q_INVOKABLE int getStencilDepthPassOperation();
	Q_INVOKABLE int getStencilFailureOperation();
	Q_INVOKABLE int getStencilPassDepthFailureOperation();
	Q_INVOKABLE unsigned int getStencilReadMask();
	Q_INVOKABLE unsigned int getStencilReferenceValue();
	bool getStencilTest();
	unsigned int getStencilWriteMask();
	Q_INVOKABLE cocos2d::Viewport getViewport();
	int getWinding();
	Q_INVOKABLE void init();
	Q_INVOKABLE void popGroup();
	Q_INVOKABLE void pushGroup(int renderQueueID);
	void setCullMode(int mode);
	void setDepthCompareFunction(int func);
	void setDepthTest(bool value);
	void setDepthWrite(bool value);
	Q_INVOKABLE void setRenderTarget(int flags, cocos2d::Texture2D* colorAttachment, cocos2d::Texture2D* depthAttachment, cocos2d::Texture2D* stencilAttachment);
	Q_INVOKABLE void setScissorRect(float x, float y, float width, float height);
	void setScissorTest(bool enabled);
	Q_INVOKABLE void setStencilCompareFunction(int func, unsigned int ref, unsigned int readMask);
	Q_INVOKABLE void setStencilOperation(int stencilFailureOp, int depthFailureOp, int stencilDepthPassOp);
	void setStencilTest(bool value);
	void setStencilWriteMask(unsigned int mask);
	Q_INVOKABLE void setViewPort(int x, int y, unsigned int w, unsigned int h);
	void setWinding(int winding);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Renderer)
Q_DECLARE_METATYPE(cocos2d::Renderer *)
Q_DECLARE_METATYPE(const cocos2d::Renderer *)

namespace cocos2d {
class QtScriptTextureCube : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptTextureCube(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTextureCube(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::backend::TextureBackend* getBackendTexture();
	Q_INVOKABLE bool reloadTexture();
	Q_INVOKABLE void setTexParameters(const cocos2d::backend::SamplerDescriptor& arg0);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TextureCube *)
Q_DECLARE_METATYPE(const cocos2d::TextureCube *)

namespace cocos2d {
class QtScriptTextureCache : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptTextureCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTextureCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::Texture2D* addImage(const QByteArray& filepath);
	Q_INVOKABLE cocos2d::Texture2D* addImage(cocos2d::Image* image, const QByteArray& key);
	Q_INVOKABLE void addImageAsync(const QByteArray& filepath, QScriptValue callback);
	Q_INVOKABLE void addImageAsync(const QByteArray& path, QScriptValue callback, const QByteArray& callbackKey);
	Q_INVOKABLE QByteArray getCachedTextureInfo();
	Q_INVOKABLE QByteArray getDescription();
	Q_INVOKABLE QByteArray getTextureFilePath(cocos2d::Texture2D* texture);
	Q_INVOKABLE cocos2d::Texture2D* getTextureForKey(const QByteArray& key);
	Q_INVOKABLE bool reloadTexture(const QByteArray& fileName);
	Q_INVOKABLE void removeAllTextures();
	Q_INVOKABLE void removeTexture(cocos2d::Texture2D* texture);
	Q_INVOKABLE void removeTextureForKey(const QByteArray& key);
	Q_INVOKABLE void removeUnusedTextures();
	Q_INVOKABLE void renameTextureWithKey(const QByteArray& srcName, const QByteArray& dstName);
	Q_INVOKABLE void unbindAllImageAsync();
	Q_INVOKABLE void unbindImageAsync(const QByteArray& filename);
	static QScriptValue getETC1AlphaFileSuffix(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setETC1AlphaFileSuffix(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TextureCache *)
Q_DECLARE_METATYPE(const cocos2d::TextureCache *)

namespace cocos2d {
class QtScriptDeviceUtils : public QtScriptBaseClassPrototype<Device *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptDeviceUtils(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDeviceUtils(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue getDPI(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getTextureDataForText(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setAccelerometerEnabled(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setAccelerometerInterval(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue setKeepScreenOn(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue vibrate(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptDeviceUtils::StorageType)
Q_DECLARE_METATYPE(cocos2d::Device *)
Q_DECLARE_METATYPE(const cocos2d::Device *)

namespace cocos2d {
class QtScriptApplicationProtocol : public QtScriptBaseClassPrototype<ApplicationProtocol *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptApplicationProtocol(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptApplicationProtocol(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int getCurrentLanguage();
	Q_INVOKABLE QByteArray getCurrentLanguageCode();
	Q_INVOKABLE int getTargetPlatform();
	Q_INVOKABLE QByteArray getVersion();
	Q_INVOKABLE bool openURL(const QByteArray& url);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::QtScriptApplicationProtocol::StorageType)
Q_DECLARE_METATYPE(cocos2d::ApplicationProtocol *)
Q_DECLARE_METATYPE(const cocos2d::ApplicationProtocol *)

namespace cocos2d {
class QtScriptApplication : public QtScriptApplicationProtocol
{
	Q_OBJECT

protected:
	explicit QtScriptApplication(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptApplication(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Application *)
Q_DECLARE_METATYPE(const cocos2d::Application *)

namespace cocos2d {
class QtScriptAnimationCache : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptAnimationCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAnimationCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addAnimation(cocos2d::Animation* animation, const QByteArray& name);
	Q_INVOKABLE void addAnimationsWithData(const QByteArray& arg0);
	Q_INVOKABLE void addAnimationsWithFile(const QByteArray& plist);
	Q_INVOKABLE cocos2d::Animation* getAnimation(const QByteArray& name);
	Q_INVOKABLE bool init();
	Q_INVOKABLE void removeAnimation(const QByteArray& name);
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::AnimationCache *)
Q_DECLARE_METATYPE(const cocos2d::AnimationCache *)

namespace cocos2d {
class QtScriptSpriteBatchNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptSpriteBatchNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSpriteBatchNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(cocos2d::TextureAtlas* textureAtlas READ getTextureAtlas WRITE setTextureAtlas)
	Q_INVOKABLE cocos2d::SpriteBatchNode* addSpriteWithoutQuad(cocos2d::Sprite* child, int z, int aTag);
	Q_INVOKABLE void appendChild(cocos2d::Sprite* sprite);
	Q_INVOKABLE ssize_t atlasIndexForChild(cocos2d::Sprite* sprite, int z);
	cocos2d::BlendFunc getBlendFunc();
	Q_INVOKABLE std::vector<cocos2d::Sprite *> getDescendants();
	cocos2d::Texture2D* getTexture();
	cocos2d::TextureAtlas* getTextureAtlas();
	Q_INVOKABLE ssize_t highestAtlasIndexInChild(cocos2d::Sprite* sprite);
	Q_INVOKABLE void increaseAtlasCapacity();
	Q_INVOKABLE bool initWithFile(const QByteArray& fileImage);
	Q_INVOKABLE bool initWithFile(const QByteArray& fileImage, ssize_t capacity);
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* tex);
	Q_INVOKABLE bool initWithTexture(cocos2d::Texture2D* tex, ssize_t capacity);
	Q_INVOKABLE void insertQuadFromSprite(cocos2d::Sprite* sprite, ssize_t index);
	Q_INVOKABLE ssize_t lowestAtlasIndexInChild(cocos2d::Sprite* sprite);
	Q_INVOKABLE ssize_t rebuildIndexInOrder(cocos2d::Sprite* parent, ssize_t index);
	Q_INVOKABLE void removeChildAtIndex(ssize_t index, bool doCleanup);
	Q_INVOKABLE void removeSpriteFromAtlas(cocos2d::Sprite* sprite);
	Q_INVOKABLE void reorderBatch(bool reorder);
	Q_INVOKABLE void reserveCapacity(ssize_t newCapacity);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	void setTexture(cocos2d::Texture2D* texture);
	void setTextureAtlas(cocos2d::TextureAtlas* textureAtlas);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SpriteBatchNode *)
Q_DECLARE_METATYPE(const cocos2d::SpriteBatchNode *)

namespace cocos2d {
class QtScriptSpriteFrameCache : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptSpriteFrameCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSpriteFrameCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addSpriteFrame(cocos2d::SpriteFrame* frame, const QByteArray& frameName);
	Q_INVOKABLE void addSpriteFramesWithFile(const QByteArray& plist);
	Q_INVOKABLE void addSpriteFramesWithFile(const QByteArray& plist, const QByteArray& textureFileName);
	Q_INVOKABLE void addSpriteFramesWithFileContent(const QByteArray& plist_content, cocos2d::Texture2D* texture);
	Q_INVOKABLE cocos2d::SpriteFrame* getSpriteFrameByName(const QByteArray& name);
	Q_INVOKABLE bool init();
	Q_INVOKABLE bool isSpriteFramesWithFileLoaded(const QByteArray& plist);
	Q_INVOKABLE bool reloadTexture(const QByteArray& plist);
	Q_INVOKABLE void removeSpriteFrameByName(const QByteArray& name);
	Q_INVOKABLE void removeSpriteFrames();
	Q_INVOKABLE void removeSpriteFramesFromFile(const QByteArray& plist);
	Q_INVOKABLE void removeSpriteFramesFromFileContent(const QByteArray& plist_content);
	Q_INVOKABLE void removeSpriteFramesFromTexture(cocos2d::Texture2D* texture);
	Q_INVOKABLE void removeUnusedSpriteFrames();
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::SpriteFrameCache *)
Q_DECLARE_METATYPE(const cocos2d::SpriteFrameCache *)

namespace cocos2d {
class QtScriptParallaxNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptParallaxNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptParallaxNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::_ccArray* parallaxArray READ getParallaxArray WRITE setParallaxArray)
	Q_INVOKABLE void addChild(cocos2d::Node* child, int z, const cocos2d::Vec2& parallaxRatio, const cocos2d::Vec2& positionOffset);
	cocos2d::_ccArray* getParallaxArray();
	void setParallaxArray(cocos2d::_ccArray* parallaxArray);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::ParallaxNode *)
Q_DECLARE_METATYPE(const cocos2d::ParallaxNode *)

namespace cocos2d {
class QtScriptTileMapAtlas : public QtScriptAtlasNode
{
	Q_OBJECT

protected:
	explicit QtScriptTileMapAtlas(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptTileMapAtlas(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::sImageTGA* tGAInfo READ getTGAInfo WRITE setTGAInfo)
	cocos2d::sImageTGA* getTGAInfo();
	Q_INVOKABLE cocos2d::Color3B getTileAt(const cocos2d::Vec2& position);
	Q_INVOKABLE bool initWithTileFile(const QByteArray& tile, const QByteArray& mapFile, int tileWidth, int tileHeight);
	Q_INVOKABLE void releaseMap();
	void setTGAInfo(cocos2d::sImageTGA* TGAInfo);
	Q_INVOKABLE void setTile(const cocos2d::Color3B& tile, const cocos2d::Vec2& position);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::TileMapAtlas *)
Q_DECLARE_METATYPE(const cocos2d::TileMapAtlas *)

namespace cocos2d {
class QtScriptAttachNode : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptAttachNode(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptAttachNode(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::AttachNode *)
Q_DECLARE_METATYPE(const cocos2d::AttachNode *)

namespace cocos2d {
class QtScriptBillBoard : public QtScriptSprite
{
	Q_OBJECT

protected:
	explicit QtScriptBillBoard(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBillBoard(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(int mode READ getMode WRITE setMode)
	int getMode();
	void setMode(int mode);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithTexture(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::BillBoard *)
Q_DECLARE_METATYPE(const cocos2d::BillBoard *)

namespace cocos2d {
class QtScriptMesh : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptMesh(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMesh(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(cocos2d::Material* material READ getMaterial WRITE setMaterial)
	Q_PROPERTY(cocos2d::MeshIndexData* meshIndexData READ getMeshIndexData WRITE setMeshIndexData)
	Q_PROPERTY(QByteArray name READ getName WRITE setName)
	Q_PROPERTY(cocos2d::backend::ProgramState* programState READ getProgramState WRITE setProgramState)
	Q_PROPERTY(cocos2d::MeshSkin* skin READ getSkin WRITE setSkin)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	Q_PROPERTY(bool visible READ isVisible WRITE setVisible)
	Q_INVOKABLE void calculateAABB();
	Q_INVOKABLE cocos2d::AABB getAABB();
	cocos2d::BlendFunc getBlendFunc();
	Q_INVOKABLE cocos2d::backend::Buffer* getIndexBuffer();
	Q_INVOKABLE ssize_t getIndexCount();
	Q_INVOKABLE int getIndexFormat();
	cocos2d::Material* getMaterial();
	cocos2d::MeshIndexData* getMeshIndexData();
	Q_INVOKABLE ssize_t getMeshVertexAttribCount();
	Q_INVOKABLE cocos2d::MeshVertexAttrib getMeshVertexAttribute(int idx);
	QByteArray getName();
	Q_INVOKABLE int getPrimitiveType();
	cocos2d::backend::ProgramState* getProgramState();
	cocos2d::MeshSkin* getSkin();
	cocos2d::Texture2D* getTexture();
	Q_INVOKABLE cocos2d::Texture2D* getTexture(int usage);
	Q_INVOKABLE QByteArray getTextureFileName();
	Q_INVOKABLE cocos2d::backend::Buffer* getVertexBuffer();
	Q_INVOKABLE int getVertexSizeInBytes();
	Q_INVOKABLE bool hasVertexAttrib(int attrib);
	bool isVisible();
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	Q_INVOKABLE void setForce2DQueue(bool force2D);
	void setMaterial(cocos2d::Material* material);
	void setMeshIndexData(cocos2d::MeshIndexData* indexdata);
	void setName(const QByteArray& name);
	void setProgramState(cocos2d::backend::ProgramState* programState);
	void setSkin(cocos2d::MeshSkin* skin);
	void setTexture(cocos2d::Texture2D* tex);
	Q_INVOKABLE void setTexture(cocos2d::Texture2D* tex, int usage);
	Q_INVOKABLE void setTexture(cocos2d::Texture2D* tex, int usage, bool cacheFileName);
	void setVisible(bool visible);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Mesh *)
Q_DECLARE_METATYPE(const cocos2d::Mesh *)

namespace cocos2d {
class QtScriptMeshSkin : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptMeshSkin(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMeshSkin(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addSkinBone(cocos2d::Bone3D* bone);
	Q_INVOKABLE cocos2d::Bone3D* getBoneByIndex(unsigned int index);
	Q_INVOKABLE cocos2d::Bone3D* getBoneByName(const QByteArray& id);
	Q_INVOKABLE ssize_t getBoneCount();
	Q_INVOKABLE int getBoneIndex(cocos2d::Bone3D* bone);
	Q_INVOKABLE cocos2d::Mat4 getInvBindPose(const cocos2d::Bone3D* bone);
	Q_INVOKABLE cocos2d::Bone3D* getRootBone();
	Q_INVOKABLE void removeAllBones();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MeshSkin *)
Q_DECLARE_METATYPE(const cocos2d::MeshSkin *)

namespace cocos2d {
class QtScriptMotionStreak3D : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptMotionStreak3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMotionStreak3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(bool startingPositionInitialized READ isStartingPositionInitialized WRITE setStartingPositionInitialized)
	Q_PROPERTY(float stroke READ getStroke WRITE setStroke)
	Q_PROPERTY(cocos2d::Vec3 sweepAxis READ getSweepAxis WRITE setSweepAxis)
	Q_PROPERTY(cocos2d::Texture2D* texture READ getTexture WRITE setTexture)
	cocos2d::BlendFunc getBlendFunc();
	float getStroke();
	cocos2d::Vec3 getSweepAxis();
	cocos2d::Texture2D* getTexture();
	Q_INVOKABLE bool initWithFade(float fade, float minSeg, float stroke, const cocos2d::Color3B& color, const QByteArray& path);
	bool isStartingPositionInitialized();
	Q_INVOKABLE void reset();
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	void setStartingPositionInitialized(bool bStartingPositionInitialized);
	void setStroke(float stroke);
	void setSweepAxis(const cocos2d::Vec3& sweepAxis);
	void setTexture(cocos2d::Texture2D* texture);
	Q_INVOKABLE void tintWithColor(const cocos2d::Color3B& colors);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MotionStreak3D *)
Q_DECLARE_METATYPE(const cocos2d::MotionStreak3D *)

namespace cocos2d {
class QtScriptMeshIndexData : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptMeshIndexData(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMeshIndexData(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::AABB aABB READ getAABB WRITE setAABB)
	Q_PROPERTY(QByteArray id READ getId WRITE setId)
	Q_PROPERTY(int primitiveType READ getPrimitiveType WRITE setPrimitiveType)
	cocos2d::AABB getAABB();
	QByteArray getId();
	Q_INVOKABLE cocos2d::backend::Buffer* getIndexBuffer();
	Q_INVOKABLE const cocos2d::MeshVertexData* getMeshVertexData();
	int getPrimitiveType();
	Q_INVOKABLE cocos2d::backend::Buffer* getVertexBuffer();
	void setAABB(const cocos2d::AABB& aabb);
	void setId(const QByteArray& id);
	void setPrimitiveType(int primitive);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MeshIndexData *)
Q_DECLARE_METATYPE(const cocos2d::MeshIndexData *)

namespace cocos2d {
class QtScriptMeshVertexData : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptMeshVertexData(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptMeshVertexData(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::MeshIndexData* getMeshIndexDataById(const QByteArray& id);
	Q_INVOKABLE cocos2d::MeshIndexData* getMeshIndexDataByIndex(int index);
	Q_INVOKABLE ssize_t getMeshIndexDataCount();
	Q_INVOKABLE cocos2d::MeshVertexAttrib getMeshVertexAttrib(ssize_t index);
	Q_INVOKABLE ssize_t getMeshVertexAttribCount();
	Q_INVOKABLE ssize_t getSizePerVertex();
	Q_INVOKABLE cocos2d::backend::Buffer* getVertexBuffer();
	Q_INVOKABLE bool hasVertexAttrib(int attrib);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::MeshVertexData *)
Q_DECLARE_METATYPE(const cocos2d::MeshVertexData *)

namespace cocos2d {
class QtScriptRay final : public QtScriptBaseClassPrototype<Ray, false>
{
	Q_OBJECT

protected:
	explicit QtScriptRay(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptRay(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE float dist(const cocos2d::Plane& plane);
	Q_INVOKABLE bool intersectsAABB(const cocos2d::AABB& arg0);
	Q_INVOKABLE bool intersectsOBB(const cocos2d::OBB& arg0);
	Q_INVOKABLE cocos2d::Vec3 intersectsPlane(const cocos2d::Plane& plane);
	Q_INVOKABLE void set(const cocos2d::Vec3& origin, const cocos2d::Vec3& direction);
	Q_INVOKABLE void transform(const cocos2d::Mat4& matrix);
	Q_PROPERTY(cocos2d::Vec3 direction READ _public_field_get_direction WRITE _public_field_set_direction)
	cocos2d::Vec3 _public_field_get_direction() const;
	void _public_field_set_direction(const cocos2d::Vec3& value);
	Q_PROPERTY(cocos2d::Vec3 origin READ _public_field_get_origin WRITE _public_field_set_origin)
	cocos2d::Vec3 _public_field_get_origin() const;
	void _public_field_set_origin(const cocos2d::Vec3& value);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Ray)
Q_DECLARE_METATYPE(cocos2d::Ray *)
Q_DECLARE_METATYPE(const cocos2d::Ray *)

namespace cocos2d {
class QtScriptBone3D : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptBone3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBone3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::Mat4 inverseBindPose READ getInverseBindPose WRITE setInverseBindPose)
	Q_INVOKABLE void addChildBone(cocos2d::Bone3D* bone);
	Q_INVOKABLE void clearBoneBlendState();
	Q_INVOKABLE cocos2d::Bone3D* getChildBoneByIndex(int index);
	Q_INVOKABLE ssize_t getChildBoneCount();
	cocos2d::Mat4 getInverseBindPose();
	Q_INVOKABLE QByteArray getName();
	Q_INVOKABLE cocos2d::Bone3D* getParentBone();
	Q_INVOKABLE cocos2d::Mat4 getWorldMat();
	Q_INVOKABLE void removeAllChildBone();
	Q_INVOKABLE void removeChildBone(cocos2d::Bone3D* bone);
	Q_INVOKABLE void removeChildBoneByIndex(int index);
	Q_INVOKABLE void resetPose();
	void setInverseBindPose(const cocos2d::Mat4& m);
	Q_INVOKABLE void setOriPose(const cocos2d::Mat4& m);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Bone3D *)
Q_DECLARE_METATYPE(const cocos2d::Bone3D *)

namespace cocos2d {
class QtScriptSkeleton3D : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptSkeleton3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSkeleton3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addBone(cocos2d::Bone3D* bone);
	Q_INVOKABLE cocos2d::Bone3D* getBoneByIndex(unsigned int index);
	Q_INVOKABLE cocos2d::Bone3D* getBoneByName(const QByteArray& id);
	Q_INVOKABLE ssize_t getBoneCount();
	Q_INVOKABLE int getBoneIndex(cocos2d::Bone3D* bone);
	Q_INVOKABLE cocos2d::Bone3D* getRootBone(int index);
	Q_INVOKABLE ssize_t getRootCount();
	Q_INVOKABLE void removeAllBones();
	Q_INVOKABLE void updateBoneMatrix();
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Skeleton3D *)
Q_DECLARE_METATYPE(const cocos2d::Skeleton3D *)

namespace cocos2d {
class QtScriptSkybox : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptSkybox(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSkybox(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool init(const QByteArray& positive_x, const QByteArray& negative_x, const QByteArray& positive_y, const QByteArray& negative_y, const QByteArray& positive_z, const QByteArray& negative_z);
	Q_INVOKABLE void reload();
	Q_INVOKABLE void setTexture(cocos2d::TextureCube* arg0);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Skybox *)
Q_DECLARE_METATYPE(const cocos2d::Skybox *)

namespace cocos2d {
class QtScriptSprite3D : public QtScriptNode
{
	Q_OBJECT

protected:
	explicit QtScriptSprite3D(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSprite3D(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_PROPERTY(cocos2d::BlendFunc blendFunc READ getBlendFunc WRITE setBlendFunc)
	Q_PROPERTY(bool forceDepthWrite READ isForceDepthWrite WRITE setForceDepthWrite)
	Q_PROPERTY(unsigned int lightMask READ getLightMask WRITE setLightMask)
	Q_INVOKABLE void genMaterial();
	Q_INVOKABLE void genMaterial(bool useLight);
	Q_INVOKABLE cocos2d::AABB getAABB();
	Q_INVOKABLE cocos2d::AABB getAABBRecursively();
	Q_INVOKABLE cocos2d::AttachNode* getAttachNode(const QByteArray& boneName);
	cocos2d::BlendFunc getBlendFunc();
	unsigned int getLightMask();
	Q_INVOKABLE cocos2d::Material* getMaterial(int meshIndex);
	Q_INVOKABLE cocos2d::Mesh* getMesh();
	Q_INVOKABLE cocos2d::Mesh* getMeshByIndex(int index);
	Q_INVOKABLE cocos2d::Mesh* getMeshByName(const QByteArray& name);
	Q_INVOKABLE ssize_t getMeshCount();
	Q_INVOKABLE cocos2d::MeshIndexData* getMeshIndexData(const QByteArray& indexId);
	Q_INVOKABLE cocos2d::Skeleton3D* getSkeleton();
	Q_INVOKABLE bool initWithFile(const QByteArray& path);
	bool isForceDepthWrite();
	Q_INVOKABLE bool loadFromCache(const QByteArray& path);
	Q_INVOKABLE void removeAllAttachNode();
	Q_INVOKABLE void removeAttachNode(const QByteArray& boneName);
	void setBlendFunc(const cocos2d::BlendFunc& blendFunc);
	Q_INVOKABLE void setCullFace(int side);
	Q_INVOKABLE void setCullFaceEnabled(bool enable);
	Q_INVOKABLE void setForce2DQueue(bool force2D);
	void setForceDepthWrite(bool value);
	void setLightMask(unsigned int mask);
	Q_INVOKABLE void setMaterial(cocos2d::Material* material);
	Q_INVOKABLE void setMaterial(cocos2d::Material* material, int meshIndex);
	Q_INVOKABLE void setTexture(cocos2d::Texture2D* texture);
	static QScriptValue create(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createAsync(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getAABBRecursivelyImp(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Sprite3D *)
Q_DECLARE_METATYPE(const cocos2d::Sprite3D *)

namespace cocos2d {
class QtScriptSprite3DCache final : public QtScriptBaseClassPrototype<Sprite3DCache, false>
{
	Q_OBJECT

protected:
	explicit QtScriptSprite3DCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSprite3DCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void removeAllSprite3DData();
	Q_INVOKABLE void removeSprite3DData(const QByteArray& key);
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Sprite3DCache)
Q_DECLARE_METATYPE(cocos2d::Sprite3DCache *)
Q_DECLARE_METATYPE(const cocos2d::Sprite3DCache *)

namespace cocos2d {
class QtScriptSprite3DMaterial : public QtScriptMaterial
{
	Q_OBJECT

protected:
	explicit QtScriptSprite3DMaterial(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSprite3DMaterial(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE int getMaterialType();
	Q_INVOKABLE void setTexture(cocos2d::Texture2D* tex, int usage);
	static QScriptValue createBuiltInMaterial(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithFilename(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue createWithProgramState(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue releaseBuiltInMaterial(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue releaseCachedMaterial(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Sprite3DMaterial *)
Q_DECLARE_METATYPE(const cocos2d::Sprite3DMaterial *)

namespace cocos2d {
class QtScriptSprite3DMaterialCache final : public QtScriptBaseClassPrototype<Sprite3DMaterialCache, false>
{
	Q_OBJECT

protected:
	explicit QtScriptSprite3DMaterialCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptSprite3DMaterialCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool addSprite3DMaterial(const QByteArray& key, cocos2d::Texture2D* tex);
	Q_INVOKABLE cocos2d::Texture2D* getSprite3DMaterial(const QByteArray& key);
	Q_INVOKABLE void removeAllSprite3DMaterial();
	Q_INVOKABLE void removeUnusedSprite3DMaterial();
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::Sprite3DMaterialCache)
Q_DECLARE_METATYPE(cocos2d::Sprite3DMaterialCache *)
Q_DECLARE_METATYPE(const cocos2d::Sprite3DMaterialCache *)

namespace cocos2d {
class QtScriptVertexAttribBinding : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptVertexAttribBinding(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptVertexAttribBinding(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE uint32_t getVertexAttribsFlags();
	Q_INVOKABLE bool hasAttribute(const int& key);
};

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::VertexAttribBinding *)
Q_DECLARE_METATYPE(const cocos2d::VertexAttribBinding *)

namespace cocos2d {
namespace backend {
class QtScriptProgramCache : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptProgramCache(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptProgramCache(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE void addCustomProgram(const QByteArray& key, cocos2d::backend::Program* program);
	Q_INVOKABLE cocos2d::backend::Program* getBuiltinProgram(int type);
	Q_INVOKABLE cocos2d::backend::Program* getCustomProgram(const QByteArray& key);
	Q_INVOKABLE void removeAllPrograms();
	Q_INVOKABLE void removeProgram(cocos2d::backend::Program* program);
	Q_INVOKABLE void removeUnusedProgram();
	static QScriptValue destroyInstance(QScriptContext *context, QScriptEngine* engine);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::ProgramCache *)
Q_DECLARE_METATYPE(const cocos2d::backend::ProgramCache *)

namespace cocos2d {
namespace backend {
class QtScriptDeviceInfo : public QtScriptBaseClassPrototype<DeviceInfo *, false>
{
	Q_OBJECT

protected:
	explicit QtScriptDeviceInfo(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDeviceInfo(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE bool checkForFeatureSupported(int feature);
	Q_INVOKABLE QByteArray getExtension();
	Q_INVOKABLE int getMaxAttributes();
	Q_INVOKABLE int getMaxSamplesAllowed();
	Q_INVOKABLE int getMaxTextureSize();
	Q_INVOKABLE int getMaxTextureUnits();
	Q_INVOKABLE QByteArray getRenderer();
	Q_INVOKABLE QByteArray getVendor();
	Q_INVOKABLE QByteArray getVersion();
	Q_INVOKABLE bool init();
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::QtScriptDeviceInfo::StorageType)
Q_DECLARE_METATYPE(cocos2d::backend::DeviceInfo *)
Q_DECLARE_METATYPE(const cocos2d::backend::DeviceInfo *)

namespace cocos2d {
namespace backend {
class QtScriptDevice : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptDevice(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptDevice(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE cocos2d::backend::DepthStencilState* createDepthStencilState(const cocos2d::backend::DepthStencilDescriptor& descriptor);
	Q_INVOKABLE cocos2d::backend::DeviceInfo* getDeviceInfo();
	Q_INVOKABLE cocos2d::backend::Buffer* newBuffer(size_t size, int type, int usage);
	Q_INVOKABLE cocos2d::backend::Program* newProgram(const QByteArray& vertexShader, const QByteArray& fragmentShader);
	Q_INVOKABLE cocos2d::backend::TextureBackend* newTexture(const cocos2d::backend::TextureDescriptor& descriptor);
	static QScriptValue getInstance(QScriptContext *context, QScriptEngine* engine);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::Device *)
Q_DECLARE_METATYPE(const cocos2d::backend::Device *)

namespace cocos2d {
namespace backend {
class QtScriptBuffer : public QtScriptRef
{
	Q_OBJECT

protected:
	explicit QtScriptBuffer(QScriptEngine *engine, const QByteArray &className);

	virtual int constructorArgumentCountMin() const override;
	virtual int constructorArgumentCountMax() const override;
	virtual bool constructObject(QScriptContext *, NativeObjectType &out) override;

public:
	explicit QtScriptBuffer(QScriptEngine *engine);
	static void Register(const QScriptValue &targetNamespace);

	Q_INVOKABLE size_t getSize();
	Q_INVOKABLE void updateData(const QByteArray& arg0);
	Q_INVOKABLE void updateSubData(const QByteArray& arg0, size_t arg1);
	Q_INVOKABLE void usingDefaultStoredData(bool needDefaultStoredData);
};

} // end of backend

} // end of cocos2d

Q_DECLARE_METATYPE(cocos2d::backend::Buffer *)
Q_DECLARE_METATYPE(const cocos2d::backend::Buffer *)

