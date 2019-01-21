#pragma once

#include "LibraryTemplate.h"

namespace Vector3
{
	class Vector3
	{
	public:
		//CONSTRUCTORS//

		//Zero'd Vector3
		Vector3();

		Vector3(const array2d_t<float, 1, 3>& v);

		//Preset Vector3 with 2 floats
		Vector3(float x, float y, float z);

		//Preset Vector3 with another Vector3
		Vector3(Vector3& v);


		//Deconstructor
		virtual ~Vector3();

		//Operators
		Vector3& operator+=(const Vector3& v);
		Vector3& operator-=(const Vector3& v);
		Vector3& operator*=(float num);
		Vector3& operator/=(float num);

		bool operator!=(const Vector3& v) const;
		bool operator==(const Vector3& v) const;

		Vector3 operator+(const Vector3& v) const;
		Vector3 operator-(Vector3& v);
		Vector3 operator-(const Vector3& v) const;
		Vector3 operator*(float num) const;
		Vector3 operator/(float num) const;

		//Magnitude/Length
		static float Length(const Vector3& v);
		static float LengthSquared(const Vector3& v);

		//Invert
		static Vector3& Invert(Vector3& v);

		//Normalize
		static Vector3& Normalize(Vector3& v);

		//Speherical & Cartesian
		static Vector3 Spherical(float x, float y, float z);
		static Vector3 Cartesian(float radius, float angle, float z);

		//Dot & Cross Product
		static Vector3 CrossProduct(const Vector3& v1, const Vector3& v2);
		static float DotProduct(const Vector3& v1, const Vector3& v2);

		// Getters
		float GetX() const { return x; }
		float GetY() const { return y; }
		float GetZ() const { return z; }

		// Setters
		void SetX(float _x) { x = _x; }
		void SetY(float _y) { y = _y; }
		void SetZ(float _z) { z = _z; }

	private:
		//Union for variables
		union
		{
			array2d_t<float, 1, 3> v;
			struct {
				float x;
				float y;
				float z;
			};
			struct
			{
				float i[3];
			};
		};
	};

	//Operator overload for testing.
	std::ostream& operator<<(std::ostream& os, const Vector3& v);
}