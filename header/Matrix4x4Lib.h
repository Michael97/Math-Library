#pragma once

#include "LibraryTemplate.h"
#include "Vector4Lib.h"

namespace Matrix4x4
{
	class Matrix4x4
	{
	public:
		//Union for variables
		union
		{
			array2d_t<float, 4, 4> m;
			struct {
				float m11, m12, m13, m14;
				float m21, m22, m23, m24;
				float m31, m32, m33, m34;
				float m41, m42, m43, m44;
			};
			struct
			{
				float i[16];
			};
			struct
			{
				Vector4::Vector4 xAxis;
				Vector4::Vector4 yAxis;
				Vector4::Vector4 zAxis;
				Vector4::Vector4 wAxis;
			};

		};

		//Constructor
		Matrix4x4();

		//Copy Constructor
		Matrix4x4(const array2d_t<float, 4, 4>& m);

		Matrix4x4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21,
			float m22, float m23, float m30, float m31, float m32, float m33);

		//Deconstructor
		~Matrix4x4();

		void Set(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21,
			float m22, float m23, float m30, float m31, float m32, float m33, Matrix4x4& matrix4x4);

		static void IdentityMatrix(Matrix4x4& matrix4x4);
		static void ZeroMatrix(Matrix4x4& matrix4x4);

		//Operators
		Matrix4x4 operator=(const Matrix4x4& matrix);

		//friend Matrix4x4 operator=(Matrix4x4& matrix, Matrix4x4& matrix2);

		Matrix4x4 operator+=(const Matrix4x4& matrix) const;
		Matrix4x4 operator-=(const Matrix4x4& matrix) const;

		Matrix4x4 operator+(const Matrix4x4& matrix) const;
		Matrix4x4 operator-(const Matrix4x4& matrix) const;
		Matrix4x4 operator*(const Matrix4x4& matrix) const;
		Matrix4x4 operator*(const float value) const;

		bool operator==(const Matrix4x4& matrix) const;
		bool operator!=(const Matrix4x4& matrix) const;

		//Matrix3x3 * Matrix3x3
		//static Matrix4x4 ComboMatrix(Vector3 & vector3, float theta);

		//Translation
		static Matrix4x4 Translate(float x, float y, float z);

		Matrix4x4 SetPosition(float x, float y, float z) const;

		//Scaling
		static Matrix4x4 Scale(float x, float y, float z);

		//Rotations
		static Matrix4x4 RotateX(float theta);
		static Matrix4x4 RotateY(float theta);
		static Matrix4x4 RotateZ(float theta);

		//Determinant
		float Determinant() const;

		//Inverse
		bool Inverse();
	};

	//Converts from degrees to radians
	float Degree2Radian(float degrees)
	{
		return degrees / 180 * (float)3.14159265359;
	}

	//Converts from radians to degrees
	float Radian2Degree(float radians)
	{
		return radians / (float)3.14159265359 * 180;
	}
}