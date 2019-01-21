// MathFuncsLib.cpp
// compile with: cl /c /EHsc MathFuncsLib.cpp
// post-build command: lib MathFuncsLib.obj

//#include "stdafx.h"

#include "Vector2Lib.h"

namespace Vector2
{

	///////////////
	//Vector2
	///////////////
	
	//Constructors//

	//Initiate a zero'd vector2
	Vector2::Vector2() : x(0), y(0) {}
	
	Vector2::Vector2(const array2d_t<float, 1, 2>& i) : v(i) {}

	//Initiate a pre set vector2 with 2 floats
	Vector2::Vector2(float x, float y) : x(x), y(y) {}

	//Initiate a pre set vector2 with another vector2
	Vector2::Vector2(Vector2 & v) : x(v.GetX()), y(v.GetY()) {}

	//Decontructor
	Vector2::~Vector2() {}


	//Directions//

	//Pre defined direction up
	Vector2 Vector2::Up()
	{
		return Vector2(0, 1);
	}

	//Pre defined direction down
	Vector2 Vector2::Down()
	{
		return Vector2(0, -1);
	}

	//Pre defined direction right
	Vector2 Vector2::Right()
	{
		return Vector2(1, 0);
	}

	//Pre defined direction left
	Vector2 Vector2::Left()
	{
		return Vector2(-1, 0);
	}

	
	//MATHEMATIC FUNCTIONS//

	//Magnitude of a vector
	float Vector2::Magnitude(const Vector2& v)
	{
		
		return sqrt(v.x * v.x + v.y * v.y);
	}

	//Magnitude of a vector without square rooting it
	float Vector2::MagnitudeSquared(const Vector2& v)
	{
		return v.x * v.x + v.y * v.y;
	}

	//Finds the euclidean distance between 2 Vector2s returns a float
	float Vector2::Distance(const Vector2& v) const
	{
		return sqrt(((x - v.x) * (x - v.x)) + ((y - v.y) * (y - v.y)));
	}

	//Finds the euclidean distance between 2 Vector2s returns a float squared
	float Vector2::DistanceSquared(const Vector2& v) const
	{
		return ((x - v.x) * (x - v.x)) + ((y - v.y) * (y - v.y));
	}

	//Returns an angle between 2 vectors as a radian
	float Vector2::Angle(const Vector2 & v1, const Vector2 & v2)
	{
		//calc dot product
		float dotProduct = DotProduct(v1, v2);

		//calc length/magnitude
		float magnitude1 = Magnitude(v1);
		float magnitude2 = Magnitude(v2);

		//calculate the  angle between vectors
		return dotProduct / (magnitude1 * magnitude2);
	}

	//Inverts the current vector
	Vector2& Vector2::Invert(Vector2& v)
	{
		return v *= -1;
	}

	//Normalizes the inputed vector
	Vector2& Vector2::Normalize(Vector2& v)
	{
		if (Magnitude(v) == 0) return v;
		v /= Magnitude(v);
		return v;
	}

	//Convert from polar to cartesian 
	Vector2 Vector2::Cartesian(float radius, float angle)
	{
		return Vector2(radius * cos(angle), radius * sin(angle));
	}


	//Convert from cartesian to polar coords
	Vector2 Vector2::Polar(float x, float y)
	{
		return Vector2(atan2(y, x), sqrt(x * x + y * y));
	}

	//Tell us the direction the 2 vectors are pointing to relative to each other
	float Vector2::DotProduct(const Vector2& v1, const Vector2& v2)
	{
		return v1.x * v2.x + v1.y * v2.y;
	}


	//OPERATOR OVERLOADS//


	//Vector2 += Vector2
	Vector2& Vector2::operator+=(const Vector2& v) { x += v.x; y += v.y; return *this; }

	//Vector2 -= Vector2
	Vector2& Vector2::operator-=(const Vector2& v) { x -= v.x; y -= v.y; return *this; }

	//Vector2 *= float
	Vector2& Vector2::operator*=(float num) { x *= num; y *= num; return *this; }

	//Vector2 /= float
	Vector2& Vector2::operator/=(float num) { x /= num; y /= num; return *this; }


	//Vector2 != Vector2
	bool Vector2::operator!=(const Vector2& v) const { return x != v.x || y != v.y; }

	//Vector2 == Vector2
	bool Vector2::operator==(const Vector2& v) const { return (*this != v) == false; }


	//Vector2 + Vector2
	Vector2 Vector2::operator+(const Vector2& v) const { return Vector2(x + v.x, y + v.y); }

	//Vector2 - Vector2
	Vector2 Vector2::operator-(Vector2& v) { return v * -1; }

	//Vector2 - Vector2
	Vector2 Vector2::operator-(const Vector2& v) const { return Vector2(x - v.x, y - v.y); }

	//Vector2 * float
	Vector2 Vector2::operator*(const float num) const { return Vector2(x * num, y * num); }

	//Vector2 * Vector2
	Vector2 Vector2::operator*(const Vector2& v) const { return Vector2(x * v.x, y * v.y); }

	//Vector2 / float
	Vector2 Vector2::operator/(const float num) const { return Vector2(x / num, y / num); }

	//Vector2 / Vector2
	Vector2 Vector2::operator/(const Vector2& v) const { return Vector2(x / v.x, y / v.y); }
	

	//Misc//

	//Allows for vectors to be posted in the command text
	std::ostream& operator<<(std::ostream& os, const Vector2& v)
	{
		os << "x: " << v.GetX() << ";  y: " << v.GetY();
		return os;
	}

}
