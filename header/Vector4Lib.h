#pragma once

#include "LibraryTemplate.h"

namespace Vector4
{
	class Vector4
	{
	public:
		//CONSTRUCTORS//

		//Zero'd Vector4
		Vector4();

		Vector4(const array2d_t<float, 1, 4>& v);

		//Preset Vector4 with 2 floats
		Vector4(float x, float y, float z, float w);

		//Preset Vector4 with another Vector4
		Vector4(Vector4& v);


		//Deconstructor
		virtual ~Vector4();

		//Operators
		Vector4& operator+=(const Vector4& v);
		Vector4& operator-=(const Vector4& v);
		Vector4& operator*=(float num);
		Vector4& operator/=(float num);

		bool operator!=(const Vector4& v) const;
		bool operator==(const Vector4& v) const;

		Vector4 operator+(const Vector4& v) const;
		Vector4 operator-(Vector4& v);
		Vector4 operator-(const Vector4& v) const;
		Vector4 operator*(float num) const;
		Vector4 operator/(float num) const;

		//Set x,y,z and w components of an existing Vector4
		Vector4 Set(float newX, float newY, float newZ, float newW);

		//Magnitude/Length
		static float Length(const Vector4& v);
		static float LengthSquared(const Vector4& v);

		//Invert
		static Vector4& Invert(Vector4& v);

		//Normalize
		static Vector4& Normalize(Vector4& v);

		// Getters
		float GetX() const { return x; }
		float GetY() const { return y; }
		float GetZ() const { return z; }
		float GetW() const { return w; }

		// Setters
		void SetX(float _x) { x = _x; }
		void SetY(float _y) { y = _y; }
		void SetZ(float _z) { z = _z; }
		void SetW(float _w) { w = _w; }

	private:
		//Union for variables
		union
		{
			array2d_t<float, 1, 4> v;
			struct {
				float x;
				float y;
				float z;
				float w;
			};
			struct
			{
				float i[4];
			};
		};
	};
}