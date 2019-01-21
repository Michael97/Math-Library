#include "../header/Matrix3x3Lib.h"


namespace Matrix3x3
{

	// Constructor
	Matrix3x3::Matrix3x3() {}

	Matrix3x3::Matrix3x3(const float m00, const float m01, const float m02, const float m10, const float m11, const float m12, const float m20, const float m21, const float m22)
	{
		(*this).m[0][0] = m00;
		(*this).m[0][1] = m01;
		(*this).m[0][2] = m02;

		(*this).m[1][0] = m10;
		(*this).m[1][1] = m11;
		(*this).m[1][2] = m12;

		(*this).m[2][0] = m20;
		(*this).m[2][1] = m21;
		(*this).m[2][2] = m22;
	}

	//Copy Constructors
	Matrix3x3::Matrix3x3(const array2d_t<float, 3, 3>& i) : m(i) {}

	Matrix3x3::~Matrix3x3() {}

	//Sets an objects matrix that has already been initiated 
	void Matrix3x3::Set(float m00, float m01, float m02, float m10, float m11, float m12, float m20, float m21, float m22, Matrix3x3& matrix3x3)
	{
		matrix3x3.m[0][0] = m00; matrix3x3.m[1][0] = m10; matrix3x3.m[2][0] = m20;
		matrix3x3.m[0][1] = m01; matrix3x3.m[1][1] = m11; matrix3x3.m[2][1] = m21;
		matrix3x3.m[0][2] = m02; matrix3x3.m[1][2] = m12; matrix3x3.m[2][2] = m22;
	}

	//Creates an Identity Matrix
	void Matrix3x3::IdentityMatrix(Matrix3x3& matrix3x3)
	{
		matrix3x3.m[0][0] = 1.0f; matrix3x3.m[1][0] = 0.0f; matrix3x3.m[2][0] = 0.0f;
		matrix3x3.m[0][1] = 0.0f; matrix3x3.m[1][1] = 1.0f; matrix3x3.m[2][1] = 0.0f;
		matrix3x3.m[0][2] = 0.0f; matrix3x3.m[1][2] = 0.0f; matrix3x3.m[2][2] = 1.0f;
	}

	//Creates an Empty matrix
	void Matrix3x3::ZeroMatrix(Matrix3x3& matrix3x3)
	{
		matrix3x3.m[0][0] = 0.0f; matrix3x3.m[1][0] = 0.0f; matrix3x3.m[2][0] = 0.0f;
		matrix3x3.m[0][1] = 0.0f; matrix3x3.m[1][1] = 0.0f; matrix3x3.m[2][1] = 0.0f;
		matrix3x3.m[0][2] = 0.0f; matrix3x3.m[1][2] = 0.0f; matrix3x3.m[2][2] = 0.0f;
	}

	//Operator Overloads
	Matrix3x3 Matrix3x3::operator=(const Matrix3x3 & matrix)
	{

		m[0][0] = matrix.m[0][0]; m[1][0] = matrix.m[1][0]; m[2][0] = matrix.m[2][0];
		m[0][1] = matrix.m[0][1]; m[1][1] = matrix.m[1][1]; m[2][1] = matrix.m[2][1];
		m[0][2] = matrix.m[0][2]; m[1][2] = matrix.m[1][2]; m[2][2] = matrix.m[2][2];
		return this->m;
	}

	Matrix3x3 Matrix3x3::operator+=(const Matrix3x3 & matrix) const
	{
		Matrix3x3 copy(this->m);

		copy.m[0][0] += matrix.m[0][0];
		copy.m[0][1] += matrix.m[0][1];
		copy.m[0][2] += matrix.m[0][2];
		copy.m[1][0] += matrix.m[1][0];
		copy.m[1][1] += matrix.m[1][1];
		copy.m[1][2] += matrix.m[1][2];
		copy.m[2][0] += matrix.m[2][0];
		copy.m[2][1] += matrix.m[2][1];
		copy.m[2][2] += matrix.m[2][2];

		return copy.m;
	}

	Matrix3x3 Matrix3x3::operator-=(const Matrix3x3 & matrix) const
	{
		Matrix3x3 copy(this->m);

		copy.m[0][0] -= matrix.m[0][0];
		copy.m[0][1] -= matrix.m[0][1];
		copy.m[0][2] -= matrix.m[0][2];
		copy.m[1][0] -= matrix.m[1][0];
		copy.m[1][1] -= matrix.m[1][1];
		copy.m[1][2] -= matrix.m[1][2];
		copy.m[2][0] -= matrix.m[2][0];
		copy.m[2][1] -= matrix.m[2][1];
		copy.m[2][2] -= matrix.m[2][2];

		return copy.m;
	}

	Matrix3x3 Matrix3x3::operator+(const Matrix3x3 & matrix) const
	{
		Matrix3x3 returnMatrix;

		returnMatrix.m[0][0] = m[0][0] + matrix.m[0][0];
		returnMatrix.m[0][1] = m[0][1] + matrix.m[0][1];
		returnMatrix.m[0][2] = m[0][2] + matrix.m[0][2];
		returnMatrix.m[1][0] = m[1][0] + matrix.m[1][0];
		returnMatrix.m[1][1] = m[1][1] + matrix.m[1][1];
		returnMatrix.m[1][2] = m[1][2] + matrix.m[1][2];
		returnMatrix.m[2][0] = m[2][0] + matrix.m[2][0];
		returnMatrix.m[2][1] = m[2][1] + matrix.m[2][1];
		returnMatrix.m[2][2] = m[2][2] + matrix.m[2][2];

		return returnMatrix.m;
	}

	Matrix3x3 Matrix3x3::operator-(const Matrix3x3 & matrix) const
	{
		Matrix3x3 returnMatrix;

		returnMatrix.m[0][0] = m[0][0] - matrix.m[0][0];
		returnMatrix.m[0][1] = m[0][1] - matrix.m[0][1];
		returnMatrix.m[0][2] = m[0][2] - matrix.m[0][2];
		returnMatrix.m[1][0] = m[1][0] - matrix.m[1][0];
		returnMatrix.m[1][1] = m[1][1] - matrix.m[1][1];
		returnMatrix.m[1][2] = m[1][2] - matrix.m[1][2];
		returnMatrix.m[2][0] = m[2][0] - matrix.m[2][0];
		returnMatrix.m[2][1] = m[2][1] - matrix.m[2][1];
		returnMatrix.m[2][2] = m[2][2] - matrix.m[2][2];

		return returnMatrix.m;
	}

	Matrix3x3 Matrix3x3::operator*(const Matrix3x3& matrix) const
	{
		Matrix3x3 returnMatrix;

		returnMatrix.m[0][0] = m[0][0] * matrix.m[0][0] + m[0][1] * matrix.m[1][0] + m[0][2] * matrix.m[2][0];
		returnMatrix.m[0][1] = m[0][0] * matrix.m[0][1] + m[0][1] * matrix.m[1][1] + m[0][2] * matrix.m[2][1];
		returnMatrix.m[0][2] = m[0][0] * matrix.m[0][2] + m[0][1] * matrix.m[1][2] + m[0][2] * matrix.m[2][2];
		returnMatrix.m[1][0] = m[1][0] * matrix.m[0][0] + m[1][1] * matrix.m[1][0] + m[1][2] * matrix.m[2][0];
		returnMatrix.m[1][1] = m[1][0] * matrix.m[0][1] + m[1][1] * matrix.m[1][1] + m[1][2] * matrix.m[2][1];
		returnMatrix.m[1][2] = m[1][0] * matrix.m[0][2] + m[1][1] * matrix.m[1][2] + m[1][2] * matrix.m[2][2];
		returnMatrix.m[2][0] = m[2][0] * matrix.m[0][0] + m[2][1] * matrix.m[1][0] + m[2][2] * matrix.m[2][0];
		returnMatrix.m[2][1] = m[2][0] * matrix.m[0][1] + m[2][1] * matrix.m[1][1] + m[2][2] * matrix.m[2][1];
		returnMatrix.m[2][2] = m[2][0] * matrix.m[0][2] + m[2][1] * matrix.m[1][2] + m[2][2] * matrix.m[2][2];

		return returnMatrix.m;
	}

	Matrix3x3 Matrix3x3::operator*(const float value) const
	{
		Matrix3x3 returnMatrix;

		returnMatrix.m[0][0] * value; returnMatrix.m[1][0] * value; returnMatrix.m[2][0] * value;
		returnMatrix.m[0][1] * value; returnMatrix.m[1][1] * value; returnMatrix.m[2][1] * value;
		returnMatrix.m[0][2] * value; returnMatrix.m[1][2] * value; returnMatrix.m[2][2] * value;

		return returnMatrix.m;
	}

	bool Matrix3x3::operator==(const Matrix3x3 & matrix) const
	{
		return m[0][0] == matrix.m[0][0] && m[1][0] == matrix.m[1][0] && m[2][0] == matrix.m[2][0] &&
			m[0][1] == matrix.m[0][1] && m[1][1] == matrix.m[1][1] && m[2][1] == matrix.m[2][1] &&
			m[0][2] == matrix.m[0][2] && m[1][2] == matrix.m[1][2] && m[2][2] == matrix.m[2][2];
	}


	bool Matrix3x3::operator!=(const Matrix3x3 & matrix) const
	{
		return m[0][0] != matrix.m[0][0] || m[1][0] != matrix.m[1][0] || m[2][0] != matrix.m[2][0] ||
			m[0][1] != matrix.m[0][1] || m[1][1] != matrix.m[1][1] || m[2][1] != matrix.m[2][1] ||
			m[0][2] != matrix.m[0][2] || m[1][2] != matrix.m[1][2] || m[2][2] != matrix.m[2][2];
	}

	//Translates a matrix
	Matrix3x3 Matrix3x3::Translate(float x, float y)
	{
		Matrix3x3 matrix3x3;

		matrix3x3.m[0][0] = 1.0f; matrix3x3.m[1][0] = 0.0f; matrix3x3.m[2][0] = x;
		matrix3x3.m[0][1] = 0.0f; matrix3x3.m[1][1] = 1.0f; matrix3x3.m[2][1] = y;
		matrix3x3.m[0][2] = 0.0f; matrix3x3.m[1][2] = 0.0f; matrix3x3.m[2][2] = 1.0f;

		return matrix3x3.m;
	}



	//Scales a matrix
	Matrix3x3 Matrix3x3::Scale(float x, float y)
	{
		Matrix3x3 matrix3x3;

		matrix3x3.m[0][0] = x; matrix3x3.m[1][0] = 0.0f; matrix3x3.m[2][0] = 0.0f;
		matrix3x3.m[0][1] = 0.0f; matrix3x3.m[1][1] = y; matrix3x3.m[2][1] = 0.0f;
		matrix3x3.m[0][2] = 0.0f; matrix3x3.m[1][2] = 0.0f; matrix3x3.m[2][2] = 1.0f;

		return matrix3x3.m;
	}

	//Rotates a matrix
	Matrix3x3 Matrix3x3::Rotate(float theta)
	{
		Matrix3x3 matrix3x3;

		matrix3x3.m[0][0] = cos(
			(theta)); matrix3x3.m[1][0] = -sin(Degree2Radian(theta)); matrix3x3.m[2][0] = 0.0f;
		matrix3x3.m[0][1] = sin(Degree2Radian(theta)); matrix3x3.m[1][1] = cos(Degree2Radian(theta)); matrix3x3.m[2][1] = 0.0f;
		matrix3x3.m[0][2] = 0.0f; matrix3x3.m[1][2] = 0.0f; matrix3x3.m[2][2] = 1.0f;

		return matrix3x3.m;
	}

	//Finds the determinant
	float Matrix3x3::Determinant() const
	{
		return (m[0][0] * (m[1][1] * m[2][2] - m[1][2] * m[2][1]) +
			m[0][1] * (m[1][2] * m[2][0] - m[1][0] * m[2][2]) +
			m[0][2] * (m[1][0] * m[2][1] - m[1][1] * m[2][0]));
	}

	//Inverts the matrix
	bool Matrix3x3::Inverse()
	{
		float determinant = Determinant();
		if (determinant != 0.0f)
		{
			const float inverseDeterminant = 1 / (determinant);

			Matrix3x3 matrix3x3 = this->m;

			m[0][0] = (matrix3x3.m[1][1] * matrix3x3.m[2][2] - matrix3x3.m[1][2] * matrix3x3.m[2][1]) * inverseDeterminant;
			m[0][1] = (matrix3x3.m[0][2] * matrix3x3.m[2][1] - matrix3x3.m[0][1] * matrix3x3.m[2][2]) * inverseDeterminant;
			m[0][2] = (matrix3x3.m[0][1] * matrix3x3.m[1][2] - matrix3x3.m[0][2] * matrix3x3.m[1][1]) * inverseDeterminant;

			m[1][0] = (matrix3x3.m[1][2] * matrix3x3.m[2][0] - matrix3x3.m[1][0] * matrix3x3.m[2][2]) * inverseDeterminant;
			m[1][1] = (matrix3x3.m[0][0] * matrix3x3.m[2][2] - matrix3x3.m[0][2] * matrix3x3.m[2][0]) * inverseDeterminant;
			m[1][2] = (matrix3x3.m[0][2] * matrix3x3.m[1][0] - matrix3x3.m[0][0] * matrix3x3.m[1][2]) * inverseDeterminant;

			m[2][0] = (matrix3x3.m[1][0] * matrix3x3.m[2][1] - matrix3x3.m[1][1] * matrix3x3.m[2][0]) * inverseDeterminant;
			m[2][1] = (matrix3x3.m[0][1] * matrix3x3.m[2][0] - matrix3x3.m[0][0] * matrix3x3.m[2][1]) * inverseDeterminant;
			m[2][2] = (matrix3x3.m[0][0] * matrix3x3.m[1][1] - matrix3x3.m[0][1] * matrix3x3.m[1][0]) * inverseDeterminant;

			return true;
		}
		return false;
	}

	static float Degree2Radian(float degrees)
	{
		return degrees / 180 * (float)3.14159265359;
	}

	static float Radian2Degree(float radians)
	{
		return radians / (float)3.14159265359 * 180;
	}


	//Allows for testing
	std::ostream& operator<<(std::ostream& os, const Matrix3x3& matrix)
	{
		os << "(1,1): " << matrix.m[0][0] << ";  (2,1): " << matrix.m[1][0] << ";  (3,1): " << matrix.m[2][0]
			<< " (1,2): " << matrix.m[0][1] << ";  (2,2): " << matrix.m[1][1] << ";  (3,2): " << matrix.m[2][1]
			<< " (1,3): " << matrix.m[0][2] << ";  (2,3): " << matrix.m[1][2] << ";  (3,3): " << matrix.m[2][2];
		return os;
	}
}