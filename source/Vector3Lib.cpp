#include "Vector3Lib.h"

namespace Vector3
{

	//Constructor
	Vector3::Vector3() : x(0), y(0), z(0) {}

	//Copy Constructors
	Vector3::Vector3(const array2d_t<float, 1, 3>& i) : v(i) {}

	Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

	Vector3::Vector3(Vector3 & v) : x(v.GetX()), y(v.GetY()), z(v.GetZ()) {}

	//Deconstructor
	Vector3::~Vector3() {}

	//Operator Overloads
	Vector3 & Vector3::operator+=(const Vector3 & v)
	{
		x += v.x;
		y += v.y;
		x += v.z;
		return *this;
	}

	Vector3 & Vector3::operator-=(const Vector3 & v)
	{
		x -= v.x;
		y -= v.y;
		z -= v.z;
		return *this;
	}

	Vector3 & Vector3::operator*=(float num)
	{
		x *= num;
		y *= num;
		z *= num;
		return *this;
	}

	Vector3 & Vector3::operator/=(float num)
	{
		x /= num;
		y /= num;
		z /= num;
		return *this;
	}

	bool Vector3::operator!=(const Vector3 & v) const
	{
		return x != v.x || y != v.y || z != v.z;
	}

	bool Vector3::operator==(const Vector3 & v) const
	{
		return (*this != v) == false;
	}

	Vector3 Vector3::operator+(const Vector3 & v) const
	{
		return Vector3(x + v.x, y + v.y, z + v.z);
	}

	Vector3 Vector3::operator-(Vector3 & v)
	{
		return Vector3(-x, -y, -z);
	}

	Vector3 Vector3::operator-(const Vector3 & v) const
	{
		return Vector3(x - v.x, y - v.y, z - v.z);
	}

	Vector3 Vector3::operator*(float num) const
	{
		return Vector3(x * num, y * num, z * num);
	}

	Vector3 Vector3::operator/(float num) const
	{
		return Vector3(x / num, y / num, z / num);
	}

	//Calculates the Length
	float Vector3::Length(const Vector3 & v)
	{
		return sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
	}

	//Calculates the length squared
	float Vector3::LengthSquared(const Vector3 & v)
	{
		return v.x * v.x + v.y * v.y + v.z * v.z;
	}

	//Inverts the vector
	Vector3 & Vector3::Invert(Vector3 & v)
	{
		return v *= -1;
	}

	//Normalizes the vector
	Vector3 & Vector3::Normalize(Vector3 & v)
	{
		if (Length(v) == 0) return v;
		v /= Length(v);
		return v;
	}

	//Converts from Spherical Coords to Cartesian
	Vector3 Vector3::Spherical(float x, float y, float z)
	{
		float radius = sqrt(x * x + y * y + z * z);
		float theta = atan2(y, x);
		float phi = acos(z / radius);

		return Vector3(radius, theta, phi);
	}

	//Converts from Cartesian to Spherical Coords
	Vector3 Vector3::Cartesian(float radius, float theta, float phi)
	{
		float XTheta = cos(theta);
		float YTheta = sin(theta);

		float XPhi = cos(phi);
		float YPhi = sin(phi);

		return Vector3((XTheta * XPhi * radius), (YTheta * XPhi * radius), (YPhi * radius));
	}

	//Calculates the crossproduct of 2 vector 2's
	Vector3 Vector3::CrossProduct(const Vector3 & v1, const Vector3 & v2)
	{
		return Vector3(v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x);
	}

	//Calculates the dot product of 2 vector 2's
	float Vector3::DotProduct(const Vector3 & v1, const Vector3 & v2)
	{
		return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
	}

	//MISC//

	//Allows for testing
	std::ostream& operator<<(std::ostream& os, const Vector3& v)
	{
		os << "x: " << v.GetX() << ";  y: " << v.GetY() << ";  z: " << v.GetZ();
		return os;
	}

}
