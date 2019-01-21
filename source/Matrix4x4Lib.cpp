#include "../header/Matrix4x4Lib.h"

namespace Matrix4x4
{
	Matrix4x4::Matrix4x4() {}

	//Copy Constructor
	Matrix4x4::Matrix4x4(float m00, float m01, float m02, float m03,
		float m10, float m11, float m12, float m13,
		float m20, float m21, float m22, float m23,
		float m30, float m31, float m32, float m33)
	{
		(*this).m[0][0] = m00;
		(*this).m[0][1] = m01;
		(*this).m[0][2] = m02;
		(*this).m[0][3] = m03;

		(*this).m[1][0] = m10;
		(*this).m[1][1] = m11;
		(*this).m[1][2] = m12;
		(*this).m[1][3] = m13;

		(*this).m[2][0] = m20;
		(*this).m[2][1] = m21;
		(*this).m[2][2] = m22;
		(*this).m[2][3] = m23;

		(*this).m[3][0] = m30;
		(*this).m[3][1] = m31;
		(*this).m[3][2] = m32;
		(*this).m[3][3] = m33;
	}

	//Copy Contructor
	Matrix4x4::Matrix4x4(const array2d_t<float, 4, 4>& i) : m(i) {}

	//Decontructor
	Matrix4x4::~Matrix4x4() {}

	//Sets an objects matrix that has already been initiated 
	void Matrix4x4::Set(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33, Matrix4x4& matrix4x4)
	{
		matrix4x4.m11 = m00; matrix4x4.m21 = m10; matrix4x4.m31 = m20; matrix4x4.m41 = m30;
		matrix4x4.m12 = m01; matrix4x4.m22 = m11; matrix4x4.m32 = m21; matrix4x4.m42 = m31;
		matrix4x4.m13 = m02; matrix4x4.m23 = m12; matrix4x4.m33 = m22; matrix4x4.m43 = m32;
		matrix4x4.m14 = m03; matrix4x4.m24 = m13; matrix4x4.m34 = m23; matrix4x4.m44 = m33;
	}

	//Creates an Identity Matrix
	void Matrix4x4::IdentityMatrix(Matrix4x4& matrix4x4)
	{
		matrix4x4.m[0][0] = 1.0f; matrix4x4.m[1][0] = 0.0f; matrix4x4.m[2][0] = 0.0f; matrix4x4.m[3][0] = 0.0f;
		matrix4x4.m[0][1] = 0.0f; matrix4x4.m[1][1] = 1.0f; matrix4x4.m[2][1] = 0.0f; matrix4x4.m[3][1] = 0.0f;
		matrix4x4.m[0][2] = 0.0f; matrix4x4.m[1][2] = 0.0f; matrix4x4.m[2][2] = 1.0f; matrix4x4.m[3][2] = 0.0f;
		matrix4x4.m[0][3] = 0.0f; matrix4x4.m[1][3] = 0.0f; matrix4x4.m[2][3] = 0.0f; matrix4x4.m[3][3] = 1.0f;
	}

	//Creates an Empty Matrix
	void Matrix4x4::ZeroMatrix(Matrix4x4& matrix4x4)
	{
		matrix4x4.m[0][0] = 0.0f; matrix4x4.m[1][0] = 0.0f; matrix4x4.m[2][0] = 0.0f; matrix4x4.m[3][0] = 0.0f;
		matrix4x4.m[0][1] = 0.0f; matrix4x4.m[1][1] = 0.0f; matrix4x4.m[2][1] = 0.0f; matrix4x4.m[3][1] = 0.0f;
		matrix4x4.m[0][2] = 0.0f; matrix4x4.m[1][2] = 0.0f; matrix4x4.m[2][2] = 0.0f; matrix4x4.m[3][2] = 0.0f;
		matrix4x4.m[0][3] = 0.0f; matrix4x4.m[1][3] = 0.0f; matrix4x4.m[2][3] = 0.0f; matrix4x4.m[3][3] = 0.0f;
	}

	//Operator Overloads
	Matrix4x4 Matrix4x4::operator=(const Matrix4x4 & matrix)
	{

		m[0][0] = matrix.m[0][0]; m[1][0] = matrix.m[1][0]; m[2][0] = matrix.m[2][0]; m[3][0] = matrix.m[3][0];
		m[0][1] = matrix.m[0][1]; m[1][1] = matrix.m[1][1]; m[2][1] = matrix.m[2][1]; m[3][1] = matrix.m[3][1];
		m[0][2] = matrix.m[0][2]; m[1][2] = matrix.m[1][2]; m[2][2] = matrix.m[2][2]; m[3][2] = matrix.m[3][2];
		m[0][3] = matrix.m[0][3]; m[1][3] = matrix.m[1][3]; m[2][3] = matrix.m[2][3]; m[3][3] = matrix.m[3][3];
		return this->m;
	}

	Matrix4x4 Matrix4x4::operator+=(const Matrix4x4 & matrix) const
	{
		Matrix4x4 copy(this->m);

		copy.m[0][0] += matrix.m[0][0];
		copy.m[0][1] += matrix.m[0][1];
		copy.m[0][2] += matrix.m[0][2];
		copy.m[0][3] += matrix.m[0][3];
		copy.m[1][0] += matrix.m[1][0];
		copy.m[1][1] += matrix.m[1][1];
		copy.m[1][2] += matrix.m[1][2];
		copy.m[1][3] += matrix.m[1][3];
		copy.m[2][0] += matrix.m[2][0];
		copy.m[2][1] += matrix.m[2][1];
		copy.m[2][2] += matrix.m[2][2];
		copy.m[2][3] += matrix.m[2][3];
		copy.m[3][0] += matrix.m[3][0];
		copy.m[3][1] += matrix.m[3][1];
		copy.m[3][2] += matrix.m[3][2];
		copy.m[3][3] += matrix.m[3][3];

		return copy.m;
	}

	Matrix4x4 Matrix4x4::operator-=(const Matrix4x4 & matrix) const
	{
		Matrix4x4 copy(this->m);

		copy.m[0][0] -= matrix.m[0][0];
		copy.m[0][1] -= matrix.m[0][1];
		copy.m[0][2] -= matrix.m[0][2];
		copy.m[0][3] -= matrix.m[0][3];
		copy.m[1][0] -= matrix.m[1][0];
		copy.m[1][1] -= matrix.m[1][1];
		copy.m[1][2] -= matrix.m[1][2];
		copy.m[1][3] -= matrix.m[1][3];
		copy.m[2][0] -= matrix.m[2][0];
		copy.m[2][1] -= matrix.m[2][1];
		copy.m[2][2] -= matrix.m[2][2];
		copy.m[2][3] -= matrix.m[2][3];
		copy.m[3][0] -= matrix.m[3][0];
		copy.m[3][1] -= matrix.m[3][1];
		copy.m[3][2] -= matrix.m[3][2];
		copy.m[3][3] -= matrix.m[3][3];

		return copy.m;
	}

	Matrix4x4 Matrix4x4::operator+(const Matrix4x4 & matrix) const
	{
		Matrix4x4 returnMatrix;

		returnMatrix.m[0][0] = m[0][0] + matrix.m[0][0];
		returnMatrix.m[0][1] = m[0][1] + matrix.m[0][1];
		returnMatrix.m[0][2] = m[0][2] + matrix.m[0][2];
		returnMatrix.m[0][2] = m[0][3] + matrix.m[0][3];
		returnMatrix.m[1][0] = m[1][0] + matrix.m[1][0];
		returnMatrix.m[1][1] = m[1][1] + matrix.m[1][1];
		returnMatrix.m[1][2] = m[1][2] + matrix.m[1][2];
		returnMatrix.m[0][2] = m[1][3] + matrix.m[1][3];
		returnMatrix.m[2][0] = m[2][0] + matrix.m[2][0];
		returnMatrix.m[2][1] = m[2][1] + matrix.m[2][1];
		returnMatrix.m[2][2] = m[2][2] + matrix.m[2][2];
		returnMatrix.m[0][2] = m[2][3] + matrix.m[2][3];
		returnMatrix.m[2][0] = m[3][0] + matrix.m[3][0];
		returnMatrix.m[2][1] = m[3][1] + matrix.m[3][1];
		returnMatrix.m[2][2] = m[3][2] + matrix.m[3][2];
		returnMatrix.m[0][2] = m[3][3] + matrix.m[3][3];

		return returnMatrix.m;
	}

	Matrix4x4 Matrix4x4::operator-(const Matrix4x4 & matrix) const
	{
		Matrix4x4 returnMatrix;


		returnMatrix.m[0][0] = m[0][0] - matrix.m[0][0];
		returnMatrix.m[0][1] = m[0][1] - matrix.m[0][1];
		returnMatrix.m[0][2] = m[0][2] - matrix.m[0][2];
		returnMatrix.m[0][2] = m[0][3] - matrix.m[0][3];
		returnMatrix.m[1][0] = m[1][0] - matrix.m[1][0];
		returnMatrix.m[1][1] = m[1][1] - matrix.m[1][1];
		returnMatrix.m[1][2] = m[1][2] - matrix.m[1][2];
		returnMatrix.m[0][2] = m[1][3] - matrix.m[1][3];
		returnMatrix.m[2][0] = m[2][0] - matrix.m[2][0];
		returnMatrix.m[2][1] = m[2][1] - matrix.m[2][1];
		returnMatrix.m[2][2] = m[2][2] - matrix.m[2][2];
		returnMatrix.m[0][2] = m[2][3] - matrix.m[2][3];
		returnMatrix.m[2][0] = m[3][0] - matrix.m[3][0];
		returnMatrix.m[2][1] = m[3][1] - matrix.m[3][1];
		returnMatrix.m[2][2] = m[3][2] - matrix.m[3][2];
		returnMatrix.m[0][2] = m[3][3] - matrix.m[3][3];

		return returnMatrix.m;
	}

	Matrix4x4 Matrix4x4::operator*(const Matrix4x4& matrix) const
	{
		Matrix4x4 returnMatrix;

		returnMatrix.m[0][0] = m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0] + m[0][2] * matrix.m[2][0] + m[0][3] * matrix.m[3][0];
		returnMatrix.m[0][1] = m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1] + m[0][2] * matrix.m[2][1] + m[0][3] * matrix.m[3][1];
		returnMatrix.m[0][2] = m[0][0] * matrix.m[0][2] + m[0][1] * matrix.m[1][2] + m[0][2] * matrix.m[2][2] + m[0][3] * matrix.m[3][2];
		returnMatrix.m[0][3] = m[0][0] * matrix.m[0][3] + m[0][1] * matrix.m[1][3] + m[0][2] * matrix.m[2][3] + m[0][3] * matrix.m[3][3];
		returnMatrix.m[1][0] = m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0] + m[1][2] * matrix.m[2][0] + m[1][3] * matrix.m[3][0];
		returnMatrix.m[1][1] = m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1] + m[1][2] * matrix.m[2][1] + m[1][3] * matrix.m[3][1];
		returnMatrix.m[1][2] = m[1][0] * matrix.m[0][2] + m[1][1] * matrix.m[1][2] + m[1][2] * matrix.m[2][2] + m[1][3] * matrix.m[3][2];
		returnMatrix.m[1][3] = m[1][0] * matrix.m[0][3] + m[1][1] * matrix.m[1][3] + m[1][2] * matrix.m[2][3] + m[1][3] * matrix.m[3][3];
		returnMatrix.m[2][0] = m[2][0] * matrix.m[0][0] + m[2][1] * matrix.m[1][0] + m[2][2] * matrix.m[2][0] + m[2][3] * matrix.m[3][0];
		returnMatrix.m[2][1] = m[2][0] * matrix.m[0][1] + m[2][1] * matrix.m[1][1] + m[2][2] * matrix.m[2][1] + m[2][3] * matrix.m[3][1];
		returnMatrix.m[2][2] = m[2][0] * matrix.m[0][2] + m[2][1] * matrix.m[1][2] + m[2][2] * matrix.m[2][2] + m[3][3] * matrix.m[3][2];
		returnMatrix.m[2][3] = m[2][0] * matrix.m[0][3] + m[2][1] * matrix.m[1][3] + m[2][2] * matrix.m[2][3] + m[2][3] * matrix.m[3][3];
		returnMatrix.m[3][0] = m[3][0] * matrix.m[0][0] + m[3][1] * matrix.m[1][0] + m[3][2] * matrix.m[3][0] + m[3][3] * matrix.m[3][0];
		returnMatrix.m[3][1] = m[3][0] * matrix.m[0][1] + m[3][1] * matrix.m[1][1] + m[3][2] * matrix.m[3][1] + m[3][3] * matrix.m[3][1];
		returnMatrix.m[3][2] = m[3][0] * matrix.m[0][2] + m[3][1] * matrix.m[1][2] + m[3][2] * matrix.m[3][2] + m[3][3] * matrix.m[3][2];
		returnMatrix.m[3][3] = m[3][0] * matrix.m[0][3] + m[3][1] * matrix.m[1][3] + m[3][2] * matrix.m[3][3] + m[3][3] * matrix.m[3][3];

		return returnMatrix.m;
	}

	Matrix4x4 Matrix4x4::operator*(const float value) const
	{
		Matrix4x4 returnMatrix;

		returnMatrix.m[0][0] * value; returnMatrix.m[1][0] * value; returnMatrix.m[2][0] * value; returnMatrix.m[3][0] * value;
		returnMatrix.m[0][1] * value; returnMatrix.m[1][1] * value; returnMatrix.m[2][1] * value; returnMatrix.m[3][1] * value;
		returnMatrix.m[0][2] * value; returnMatrix.m[1][2] * value; returnMatrix.m[2][2] * value; returnMatrix.m[3][2] * value;
		returnMatrix.m[0][3] * value; returnMatrix.m[1][3] * value; returnMatrix.m[2][3] * value; returnMatrix.m[3][3] * value;

		return returnMatrix.m;
	}

	bool Matrix4x4::operator==(const Matrix4x4 & matrix) const
	{
		return m[0][0] == matrix.m[0][0] && m[1][0] == matrix.m[1][0] && m[2][0] == matrix.m[2][0] && m[3][0] == matrix.m[3][0] &&
			m[0][1] == matrix.m[0][1] && m[1][1] == matrix.m[1][1] && m[2][1] == matrix.m[2][1] && m[3][1] == matrix.m[3][1] &&
			m[0][2] == matrix.m[0][2] && m[1][2] == matrix.m[1][2] && m[2][2] == matrix.m[2][2] && m[3][2] == matrix.m[3][2] &&
			m[0][3] == matrix.m[0][3] && m[1][3] == matrix.m[1][3] && m[2][3] == matrix.m[2][3] && m[3][3] == matrix.m[3][3];
	}


	bool Matrix4x4::operator!=(const Matrix4x4 & matrix) const
	{
		return m[0][0] != matrix.m[0][0] || m[1][0] != matrix.m[1][0] || m[2][0] != matrix.m[2][0] || m[3][0] != matrix.m[3][0] ||
			m[0][1] != matrix.m[0][1] || m[1][1] != matrix.m[1][1] || m[2][1] != matrix.m[2][1] || m[3][1] != matrix.m[3][1] ||
			m[0][2] != matrix.m[0][2] || m[1][2] != matrix.m[1][2] || m[2][2] != matrix.m[2][2] || m[3][2] != matrix.m[3][2] ||
			m[0][3] != matrix.m[0][3] || m[1][3] != matrix.m[1][3] || m[2][3] != matrix.m[2][3] || m[3][3] != matrix.m[3][3];
	}

	/*Matrix4x4& Matrix4x4::ComboMatrix(Vector3 & vector3, float theta)
	{

	Matrix4x4 test(Translate(vector3) * RotateX(theta));

	return test;
	}
	*/

	//Translate a matrix
	Matrix4x4 Matrix4x4::Translate(float x, float y, float z)
	{
		Matrix4x4 matrix4x4;

		matrix4x4.m[0][0] = 1.0f; matrix4x4.m[1][0] = 0.0f; matrix4x4.m[2][0] = 0.0f; matrix4x4.m[3][0] = x;
		matrix4x4.m[0][1] = 0.0f; matrix4x4.m[1][1] = 1.0f; matrix4x4.m[2][1] = 0.0f; matrix4x4.m[3][1] = y;
		matrix4x4.m[0][2] = 0.0f; matrix4x4.m[1][2] = 0.0f; matrix4x4.m[2][2] = 0.0f; matrix4x4.m[3][2] = z;
		matrix4x4.m[0][3] = 0.0f; matrix4x4.m[1][3] = 0.0f; matrix4x4.m[2][3] = 0.0f; matrix4x4.m[3][3] = 1.0f;

		return matrix4x4.m;
	}

	//Sets the position of the sprite
	Matrix4x4 Matrix4x4::SetPosition(float x, float y, float z) const
	{
		Matrix4x4 copy(this->m);
		copy.m[3][0] = x;
		copy.m[3][1] = y;
		copy.m[3][2] = z;
		copy.m[3][3] = 1.0f;
		return copy.m;
	}

	//Changes the scale of a sprite
	Matrix4x4 Matrix4x4::Scale(float x, float y, float z)
	{
		Matrix4x4 matrix4x4;

		matrix4x4.m[0][0] = x; matrix4x4.m[1][0] = 0.0f; matrix4x4.m[2][0] = 0.0f; matrix4x4.m[3][0] = 0.0f;
		matrix4x4.m[0][1] = 0.0f; matrix4x4.m[1][1] = y; matrix4x4.m[2][1] = 0.0f; matrix4x4.m[3][1] = 0.0f;
		matrix4x4.m[0][2] = 0.0f; matrix4x4.m[1][2] = 0.0f; matrix4x4.m[2][2] = z; matrix4x4.m[3][2] = 0.0f;
		matrix4x4.m[0][3] = 0.0f; matrix4x4.m[1][3] = 0.0f; matrix4x4.m[2][3] = 0.0f; matrix4x4.m[3][3] = 1.0f;

		return matrix4x4.m;
	}

	//Rotates a sprite in the X axis
	Matrix4x4 Matrix4x4::RotateX(float theta)
	{
		Matrix4x4 matrix4x4;

		const float co = cos(Degree2Radian(theta));
		const float si = sin(Degree2Radian(theta));

		matrix4x4.m11 = 1.0f; matrix4x4.m21 = 0.0f; matrix4x4.m31 = 0.0f; matrix4x4.m41 = 0.0f;
		matrix4x4.m12 = 0.0f; matrix4x4.m22 = co; matrix4x4.m32 = si; matrix4x4.m42 = 0.0f;
		matrix4x4.m13 = 0.0f; matrix4x4.m23 = -si; matrix4x4.m33 = co; matrix4x4.m43 = 0.0f;
		matrix4x4.m14 = 0.0f; matrix4x4.m24 = 0.0f; matrix4x4.m34 = 0.0f; matrix4x4.m44 = 1.0f;

		return matrix4x4.m;
	}

	//Rotates a sprite in the Y axis
	Matrix4x4 Matrix4x4::RotateY(float theta)
	{
		Matrix4x4 matrix4x4;

		const float co = cos(Degree2Radian(theta));
		const float si = sin(Degree2Radian(theta));

		matrix4x4.m11 = co; matrix4x4.m21 = 0.0f; matrix4x4.m31 = -si; matrix4x4.m41 = 0.0f;
		matrix4x4.m12 = 0.0f; matrix4x4.m22 = 1.0f; matrix4x4.m32 = 0.0f; matrix4x4.m42 = 0.0f;
		matrix4x4.m13 = si; matrix4x4.m23 = 0.0f; matrix4x4.m33 = co; matrix4x4.m43 = 0.0f;
		matrix4x4.m14 = 0.0f; matrix4x4.m24 = 0.0f; matrix4x4.m34 = 0.0f; matrix4x4.m44 = 1.0f;

		return matrix4x4.m;
	}

	//Rotates a sprite in the Z axis
	Matrix4x4 Matrix4x4::RotateZ(float theta)
	{
		Matrix4x4 matrix4x4;

		const float co = cos(Degree2Radian(theta));
		const float si = sin(Degree2Radian(theta));

		matrix4x4.m11 = co; matrix4x4.m21 = si; matrix4x4.m31 = 0.0f; matrix4x4.m41 = 0.0f;
		matrix4x4.m12 = -si; matrix4x4.m22 = co; matrix4x4.m32 = 0.0f; matrix4x4.m42 = 0.0f;
		matrix4x4.m13 = 0.0f; matrix4x4.m23 = 0.0f; matrix4x4.m33 = 1.0f; matrix4x4.m43 = 0.0f;
		matrix4x4.m14 = 0.0f; matrix4x4.m24 = 0.0f; matrix4x4.m34 = 0.0f; matrix4x4.m44 = 1.0f;

		return matrix4x4.m;
	}

	/*float Matrix4x4::Determinant() const
	{
	return (m[0][0] * (m[1][1] * m[2][2] * m[3][3] - m[1][3] * m[2][2] * m[3][1]) +
	m[0][1] * (m[1][2] * m[2][3] * m[3][0] - m[1][0] * m[2][3] * m[3][2]) +
	m[0][2] * (m[1][3] * m[2][0] * m[3][1] - m[1][1] * m[2][0] * m[3][3]) +
	m[0][3] * (m[1][0] * m[2][1] * m[3][2] - m[1][2] * m[2][1] * m[3][0]));
	}*/

	//Gets teh Determinant
	float Matrix4x4::Determinant() const
	{
		return (m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) +
			m[0][1] * (m[1][2] * m[2][0] - m[1][0] * m[2][2]) +
			m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]));
	}

	//Inverts a matrix
	bool Matrix4x4::Inverse()
	{
		float determinant = Determinant();
		if (determinant != 0.0f)
		{
			const float inverseDeterminant = 1 / (determinant);

			Matrix4x4& matrix4x4 = *this;

			m[0][0] = (matrix4x4.m[1][1] * matrix4x4.m[2][2] - matrix4x4.m[1][2] * matrix4x4.m[2][1]) * inverseDeterminant;
			m[0][1] = (matrix4x4.m[0][2] * matrix4x4.m[2][1] - matrix4x4.m[0][1] * matrix4x4.m[2][2]) * inverseDeterminant;
			m[0][2] = (matrix4x4.m[0][1] * matrix4x4.m[1][2] - matrix4x4.m[0][2] * matrix4x4.m[1][1]) * inverseDeterminant;
			m[0][3] = 0.0f;

			m[1][0] = (matrix4x4.m[1][2] * matrix4x4.m[2][0] - matrix4x4.m[1][0] * matrix4x4.m[2][2]) * inverseDeterminant;
			m[1][1] = (matrix4x4.m[0][0] * matrix4x4.m[2][2] - matrix4x4.m[0][2] * matrix4x4.m[2][0]) * inverseDeterminant;
			m[1][2] = (matrix4x4.m[0][2] * matrix4x4.m[1][0] - matrix4x4.m[0][0] * matrix4x4.m[1][2]) * inverseDeterminant;
			m[1][3] = 0.0f;

			m[2][0] = (matrix4x4.m[1][0] * matrix4x4.m[2][1] - matrix4x4.m[1][1] * matrix4x4.m[2][0]) * inverseDeterminant;
			m[2][1] = (matrix4x4.m[0][1] * matrix4x4.m[2][0] - matrix4x4.m[0][0] * matrix4x4.m[2][1]) * inverseDeterminant;
			m[2][2] = (matrix4x4.m[0][0] * matrix4x4.m[1][1] - matrix4x4.m[0][1] * matrix4x4.m[1][0]) * inverseDeterminant;
			m[2][3] = 0.0f;

			m[3][0] = (matrix4x4.m[1][0] * (matrix4x4.m[2][2] * matrix4x4.m[3][1] - matrix4x4.m[2][1] * matrix4x4.m[3][2]) +
				matrix4x4.m[1][1] * (matrix4x4.m[2][0] * matrix4x4.m[3][2] - matrix4x4.m[2][2] * matrix4x4.m[3][0]) +
				matrix4x4.m[1][2] * (matrix4x4.m[2][1] * matrix4x4.m[3][0] - matrix4x4.m[2][0] * matrix4x4.m[3][1])) * inverseDeterminant;
			m[3][1] = (matrix4x4.m[0][0] * (matrix4x4.m[2][1] * matrix4x4.m[3][2] - matrix4x4.m[2][2] * matrix4x4.m[3][1]) +
				matrix4x4.m[0][1] * (matrix4x4.m[2][2] * matrix4x4.m[3][0] - matrix4x4.m[2][0] * matrix4x4.m[3][2]) +
				matrix4x4.m[0][2] * (matrix4x4.m[2][0] * matrix4x4.m[3][1] - matrix4x4.m[2][1] * matrix4x4.m[3][0])) * inverseDeterminant;
			m[3][2] = (matrix4x4.m[0][0] * (matrix4x4.m[2][2] * matrix4x4.m[3][1] - matrix4x4.m[2][1] * matrix4x4.m[3][2]) +
				matrix4x4.m[0][1] * (matrix4x4.m[2][0] * matrix4x4.m[3][2] - matrix4x4.m[2][2] * matrix4x4.m[3][0]) +
				matrix4x4.m[0][2] * (matrix4x4.m[2][1] * matrix4x4.m[3][0] - matrix4x4.m[2][0] * matrix4x4.m[3][1])) * inverseDeterminant;
			m[3][3] = 1.0f;

			return true;
		}
		return false;
	}

	//Allows for testing
	std::ostream& operator<<(std::ostream& os, const Matrix4x4& matrix)
	{
		os << "(1,1): " << matrix.m[0][0] << ";  (2,1): " << matrix.m[1][0] << ";  (3,1): " << matrix.m[2][0] << ";  (4,1): " << matrix.m[3][0]
			<< ";  (1,2): " << matrix.m[0][1] << ";  (2,2): " << matrix.m[1][1] << ";  (3,2): " << matrix.m[2][1] << ";  (4,2): " << matrix.m[3][1]
			<< ";  (1,3): " << matrix.m[0][2] << ";  (2,3): " << matrix.m[1][2] << ";  (3,3): " << matrix.m[2][2] << ";  (4,3): " << matrix.m[3][2]
			<< ";  (1,4): " << matrix.m[0][3] << ";  (2,4): " << matrix.m[1][3] << ";  (3,4): " << matrix.m[2][3] << ";  (4,4): " << matrix.m[3][3];
		return os;
	}

}