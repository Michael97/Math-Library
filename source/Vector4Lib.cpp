#include "Vector4Lib.h"

namespace Vector4
{

	Vector4::Vector4() : x(0), y(0), z(0), w(0) {}

	Vector4::Vector4(const array2d_t<float, 1, 4>& i) : v(i) {}

	Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}

	Vector4::~Vector4() {}

	Vector4 & Vector4::operator+=(const Vector4 & v)
	{
		x += v.x;
		y += v.y;
		x += v.z;
		w += v.w;
		return *this;
	}

	Vector4 & Vector4::operator-=(const Vector4 & v)
	{
		x -= v.x;
		y -= v.y;
		x -= v.z;
		w -= v.w;
		return *this;
	}

	Vector4 & Vector4::operator*=(float num)
	{
		x *= num;
		y *= num;
		x *= num;
		w *= num;
		return *this;
	}

	Vector4 & Vector4::operator/=(float num)
	{
		x /= num;
		y /= num;
		x /= num;
		w /= num;
		return *this;
	}

	bool Vector4::operator!=(const Vector4 & v) const
	{
		return x != v.x || y != v.y || z != v.z || w != v.w;
	}

	bool Vector4::operator==(const Vector4 & v) const
	{
		return (*this != v) == false;
	}

	Vector4 Vector4::operator+(const Vector4 & v) const
	{
		return Vector4(x + v.x, y + v.y, z + v.z, w + v.w);
	}

	Vector4 Vector4::operator-(Vector4 & v)
	{
		return Vector4(-x, -y, -z, -w);
	}

	Vector4 Vector4::operator-(const Vector4 & v) const
	{
		return Vector4(x - v.x, y - v.y, z - v.z, w - v.w);
	}

	Vector4 Vector4::operator*(float num) const
	{
		return Vector4(x * num, y * num, z * num, w * num);
	}

	Vector4 Vector4::operator/(float num) const
	{
		return Vector4(x / num, y / num, z / num, w / num);
	}

	Vector4 Vector4::Set(float newX, float newY, float newZ, float newW)
	{
		return Vector4(newX, newY, newZ, newW);
	}

	float Vector4::Length(const Vector4 & v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	float Vector4::LengthSquared(const Vector4 & v)
	{
		return (v.x * v.x + v.y * v.y + v.z * v.z + v.w * v.w);
	}

	Vector4 & Vector4::Invert(Vector4 & v)
	{
		return v *= -1;
	}

	Vector4 & Vector4::Normalize(Vector4 & v)
	{
		if (Length(v) == 0) return v;
		v /= Length(v);
		return v;
	}
}