#pragma once

#include "LibraryTemplate.h"

namespace nVector2
{
	class Vector2
	{
	public:

		//CONSTRUCTORS//

		//Zero'd Vector2
		Vector2();

		Vector2(const array2d_t<float, 1, 2>& v);

		//Preset Vector2 with 2 floats
		Vector2(float x, float y);

		//Preset Vector2 with another Vector2
		Vector2(Vector2& v);


		//Deconstructor
		virtual ~Vector2();


		//DIRECTIONS//
		
		//Pre defined direction up
		static Vector2 Up();

		//Pre defined direction down
		static Vector2 Down();

		//Pre defined direction right
		static Vector2 Right();

		//Pre defined direction left
		static Vector2 Left();


		//OPERATOR OVERLOADS//

		//Vector2 += Vector2
		Vector2& operator+=(const Vector2& v);

		//Vector2 -= Vector2
		Vector2& operator-=(const Vector2& v);

		//Vector2 *= float
		Vector2& operator*=(float num);

		//Vector2 /= float
		Vector2& operator/=(float num);


		//Vector2 != Vector2
		bool operator!=(const Vector2& v) const;

		//Vector2 == Vector2
		bool operator==(const Vector2& v) const;


		//Vector2 + Vector2
		Vector2 operator+(const Vector2& v) const;

		//Vector2 - Vector2
		Vector2 operator-(Vector2& v);

		//Vector2 - Vector2
		Vector2 operator-(const Vector2& v) const;

		//Vector2 * float
		Vector2 operator*(const float num) const;

		//Vector2 * Vector2
		Vector2 operator*(const Vector2& v) const;

		//Vector2 / float
		Vector2 operator/(const float num) const;

		//Vector2 / Vector2
		Vector2 operator/(const Vector2& v) const;


		static float Magnitude(const Vector2& v);
		static float MagnitudeSquared(const Vector2& v);
		float Distance(const Vector2 & v) const;
		float DistanceSquared(const Vector2 & v) const;
		static float Angle(const Vector2& v1, const Vector2& v2);

		static Vector2& Invert(Vector2& v);
		static Vector2& Normalize(Vector2& v);

		static Vector2 Polar(float x, float y);
		static Vector2 Cartesian(float radius, float angle);
		static float DotProduct(const Vector2& v1, const Vector2& v2);

		// Getters
		float GetX() const { return x; }
		float GetY() const { return y; }

		// Setters
		void SetX(float _x) { x = _x; }
		void SetY(float _y) { y = _y; }

	private:
		//Union for variables
		union
		{
			array2d_t<float, 1, 2> v;
			struct {
				float x;
				float y;
			};
			struct
			{
				float i[2];
			};
		};
	};

	//Operator overload for testing.
	std::ostream& operator<<(std::ostream& os, const Vector2& v);

}