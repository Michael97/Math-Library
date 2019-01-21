#pragma once

#include "LibraryTemplate.h"
#include "Vector3Lib.h"

namespace Matrix3x3
{
	class Matrix3x3
	{
	public:
		//Union for variables
		union
		{
			array2d_t<float, 3, 3> m;
			struct {
				float m11, m12, m13;
				float m21, m22, m23;
				float m31, m32, m33;
			};
			struct
			{
				float i[9];
			};
			struct
			{
				Vector3::Vector3 xAxis;
				Vector3::Vector3 yAxis;
				Vector3::Vector3 zAxis;
			};

		};
		//Constructor
		Matrix3x3();

		Matrix3x3(const float m00, const float m01, const float m02,
			const float m10, const float m11, const float m12,
			const float m20, const float m21, const float m22);


		//Copy Constructor
		Matrix3x3(const array2d_t<float, 3, 3>& m);

		//Deconstructor
		~Matrix3x3();

		void Set(const float m00, const float m01, const float m02,
			const float m10, const float m11, const float m12,
			const float m20, const float m21, const float m22, Matrix3x3& matrix3x3);

		static void IdentityMatrix(Matrix3x3& matrix3x3);
		static void ZeroMatrix(Matrix3x3& matrix3x3);

		//Operators
		Matrix3x3 operator=(const Matrix3x3& matrix);

		Matrix3x3 operator+=(const Matrix3x3& matrix) const;
		Matrix3x3 operator-=(const Matrix3x3& matrix) const;

		Matrix3x3 operator+(const Matrix3x3& matrix) const;
		Matrix3x3 operator-(const Matrix3x3& matrix) const;
		Matrix3x3 operator*(const Matrix3x3& matrix) const;
		Matrix3x3 operator*(const float value) const;

		bool operator==(const Matrix3x3& matrix) const;
		bool operator!=(const Matrix3x3& matrix) const;

		//Translation
		static Matrix3x3 Translate(float x, float y);

		//Scaling
		static Matrix3x3 Scale(float x, float y);

		//Rotations
		static Matrix3x3 Rotate(float theta);

		//Determinant
		float Determinant() const;

		//Inverse
		bool Inverse();

	};

	//Converts from degrees to radians
	static float Degree2Radian(float degrees);

	//Converts from radians to degrees
	static float Radian2Degree(float radians);
}