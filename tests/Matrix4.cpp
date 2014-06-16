#include <M3D/Matrix4.hpp>
#include <M3D/Vector3.hpp>
#include <M3D/Vector4.hpp>

#include <boost/test/unit_test.hpp>
#include <cmath>

using namespace M3D;

BOOST_AUTO_TEST_SUITE(Matrix4_Test_Suite)

/**
 * Test that the default constructor constructs the identity matrix.
 */
BOOST_AUTO_TEST_CASE(TestDefaultConstructor)
{
	const Matrix4 A;
	for (size_t i = 0; i < 16; ++i)
	{
		if (i % 5 == 0)
		{
			BOOST_CHECK_CLOSE(A[i], 1.0f, 1e-6);
		}
		else
		{
			BOOST_CHECK_CLOSE(A[i], 0.0f, 1e-6);
		}
	}
}

/**
 * Test that the constructor constructs the matrix defined by the passed
 * row-major array.
 */
BOOST_AUTO_TEST_CASE(TestArrayConstructor)
{
	float arr[16] = {
		-1.0f, 1.0f, 2.0f, 2.5,
		3.5f, 1.9f, 100.0f, -33.125f,
		-1.25f, -1e-6f, 25.0f, 19.3f,
		-75.0f, 125.0f, -30.0f, 20.0f
	};
	const Matrix4 A(arr);
	for (size_t i = 0; i < 16; ++i)
	{
		BOOST_CHECK_CLOSE(A[i], arr[i], 1e-6);
	}
}

/**
 * Test that the constructor constructs the matrix defined by the entry values
 * in row-major order.
 */
BOOST_AUTO_TEST_CASE(TestEntryConstructor)
{
	float arr[16] = {
		0.1f, 1.2f, 2.3f, 3.4f,
		4.5f, -5.6f, 6.7f, 7.8f,
		-8.9f, 9.1f, 10.2f, -11.3f,
		12.4f, -13.5f, -14.6f, 15.7f
	};
	const Matrix4 A(
		0.1f, 1.2f, 2.3f, 3.4f,
		4.5f, -5.6f, 6.7f, 7.8f,
		-8.9f, 9.1f, 10.2f, -11.3f,
		12.4f, -13.5f, -14.6f, 15.7f
	);
	for (size_t i = 0; i < 16; ++i)
	{
		BOOST_CHECK_CLOSE(A[i], arr[i], 1e-6);
	}
}

/**
 * Test that the constructor constructs the matrix defined by the passed 3x3
 * matrix.
 */
BOOST_AUTO_TEST_CASE(Test3x3MatrixConstructor)
{
	const Matrix3 B(0.1f, 1.2f, 2.3f, 3.4f, 4.5f, -5.6f, 6.7f, 7.8f, -8.9f);
	const Matrix4 A(B);

	BOOST_CHECK_CLOSE(A[0], B[0], 1e-6);
	BOOST_CHECK_CLOSE(A[1], B[1], 1e-6);
	BOOST_CHECK_CLOSE(A[2], B[2], 1e-6);
	BOOST_CHECK_CLOSE(A[3], 0.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[4], B[3], 1e-6);
	BOOST_CHECK_CLOSE(A[5], B[4], 1e-6);
	BOOST_CHECK_CLOSE(A[6], B[5], 1e-6);
	BOOST_CHECK_CLOSE(A[7], 0.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[8], B[6], 1e-6);
	BOOST_CHECK_CLOSE(A[9], B[7], 1e-6);
	BOOST_CHECK_CLOSE(A[10], B[8], 1e-6);
	BOOST_CHECK_CLOSE(A[11], 0.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[12], 0.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[13], 0.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[14], 0.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[15], 1.0f, 1e-6);
}

/**
 * First test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator1)
{
	const Matrix4 A;
	const Matrix4 B;

	BOOST_CHECK(A == B);
}

/**
 * Second test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator2)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);

	BOOST_CHECK(A == A);
}

/**
 * Third test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator3)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	const Matrix4 B(
		1.0f, 2.01f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);

	BOOST_CHECK_EQUAL(A == B, false);
}

/**
 * First test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator1)
{
	const Matrix4 A;
	const Matrix4 B;

	BOOST_CHECK_EQUAL(A != B, false);
}

/**
 * Second test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator2)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);

	BOOST_CHECK_EQUAL(A != A, false);
}

/**
 * Third test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator3)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	const Matrix4 B(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 30.0f, 16.0f
	);

	BOOST_CHECK(A != B);
}

/**
 * First test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator1)
{
	const Matrix4 A;
	const Matrix4 B;
	const Matrix4 C(
		2.0f, 0.0f, 0.0f, 0.0f,
		0.0f, 2.0f, 0.0f, 0.0f,
		0.0f, 0.0f, 2.0f, 0.0f,
		0.0f, 0.0f, 0.0f, 2.0f
	);

	BOOST_CHECK_EQUAL(A + B, C);
}

/**
 * Second test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator2)
{
	const Matrix4 A;
	const Matrix4 B(
		-1.0f, 0.0f, 0.0f, 0.0f,
		0.0f, -1.0f, 0.0f, 0.0f,
		0.0f, 0.0f, -1.0f, 0.0f,
		0.0f, 0.0f, 0.0f, -1.0f
	);

	BOOST_CHECK_EQUAL(A + B, Matrix4::ZERO);
}

/**
 * Third test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator3)
{
	const Matrix4 A(
		2.0f, 4.0f, 6.0f, 8.0f,
		10.0f, 12.0f, 14.0f, 16.0f,
		18.0f, 20.0f, 22.0f, 24.0f,
		26.0f, 28.0f, 30.0f, 32.0f
	);
	const Matrix4 B(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	const Matrix4 C(
		3.0f, 6.0f, 9.0f, 12.0f,
		15.0f, 18.0f, 21.0f, 24.0f,
		27.0f, 30.0f, 33.0f, 36.0f,
		39.0f, 42.0f, 45.0f, 48.0f
	);

	BOOST_CHECK_EQUAL(A + B, C);
}

/**
 * First test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator1)
{
	const Matrix4 A;
	const Matrix4 B;

	BOOST_CHECK_EQUAL(A - B, Matrix4::ZERO);
}

/**
 * Second test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator2)
{
	const Matrix4 A;
	const Matrix4 B = Matrix4::ZERO;

	BOOST_CHECK_EQUAL(A - B, Matrix4::IDENTITY);
}

/**
 * Third test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator3)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	const Matrix4 B(
		2.0f, 4.0f, 6.0f, 8.0f,
		10.0f, 12.0f, 14.0f, 16.0f,
		18.0f, 20.0f, 22.0f, 24.0f,
		26.0f, 28.0f, 30.0f, 32.0f
	);
	const Matrix4 C(
		-1.0f, -2.0f, -3.0f, -4.0f,
		-5.0f, -6.0f, -7.0f, -8.0f,
		-9.0f, -10.0f, -11.0f, -12.0f,
		-13.0f, -14.0f, -15.0f, -16.0f
	);

	BOOST_CHECK_EQUAL(A - B, C);
}

/**
 * First test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator1)
{
	BOOST_CHECK_EQUAL(-Matrix4::ZERO, Matrix4::ZERO);
}

/**
 * Second test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator2)
{
	BOOST_CHECK_EQUAL(-Matrix4::IDENTITY, Matrix4::ZERO - Matrix4::IDENTITY);
}

/**
 * Third test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator3)
{
	const Matrix4 A(
		1.0f, -2.0f, 3.0f, -4.0f,
		-5.0f, 6.0f, -7.0f, 8.0f,
		9.0f, -10.0f, 11.0f, -12.0f,
		-13.0f, 14.0f, -15.0f, 16.0f
	);
	const Matrix4 B(
		-1.0f, 2.0f, -3.0f, 4.0f,
		5.0f, -6.0f, 7.0f, -8.0f,
		-9.0f, 10.0f, -11.0f, 12.0f,
		13.0f, -14.0f, 15.0f, -16.0f
	);
	BOOST_CHECK_EQUAL(-A, B);
}

/**
 * First test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator1)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);

	BOOST_CHECK_EQUAL(A * 0.0f, Matrix4::ZERO);
}

/**
 * Second test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator2)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	const Matrix4 B(
		2.0f, 4.0f, 6.0f, 8.0f,
		10.0f, 12.0f, 14.0f, 16.0f,
		18.0f, 20.0f, 22.0f, 24.0f,
		26.0f, 28.0f, 30.0f, 32.0f
	);

	BOOST_CHECK_EQUAL(A * 2.0f, B);
	BOOST_CHECK_EQUAL(2.0f * A, B);
}

/**
 * First test for the column-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestColumnVectorMultiplicationOperator1)
{
	const Vector4 v(2.0f, 4.0f, -6.0f, 8.0f);
	BOOST_CHECK_EQUAL(Matrix4::IDENTITY * v, v);
}

/**
 * Second test for the column-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestColumnVectorMultiplicationOperator2)
{
	const Vector4 v(1.0f, 2.0f, 3.0f, 4.0f);
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	BOOST_CHECK_EQUAL(A * v, Vector4(30.0f, 70.0f, 110.0f, 150.0f));
}

/**
 * First test for the row-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestRowVectorMultiplicationOperator1)
{
	const Vector4 v(1.0f, -3.0f, 5.0f, -7.0f);
	BOOST_CHECK_EQUAL(v * Matrix4::IDENTITY, v);
}

/**
 * Second test for the row-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestRowVectorMultiplicationOperator2)
{
	const Vector4 v(1.0f, 2.0f, 3.0f, 4.0f);
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	BOOST_CHECK_EQUAL(v * A, Vector4(90.0f, 100.0f, 110.0f, 120.0f));
}

/**
 * First test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator1)
{
	BOOST_CHECK_EQUAL(Matrix4::IDENTITY * Matrix4::IDENTITY, Matrix4::IDENTITY);
}

/**
 * Second test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator2)
{
	BOOST_CHECK_EQUAL(Matrix4::IDENTITY * Matrix4::ZERO, Matrix4::ZERO);
}

/**
 * Third test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator3)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	const Matrix4 B(
		2.0f, 4.0f, 6.0f, 8.0f,
		10.0f, 12.0f, 14.0f, 16.0f,
		18.0f, 20.0f, 22.0f, 24.0f,
		26.0f, 28.0f, 30.0f, 32.0f
	);
	const Matrix4 C(
		45.0f, 50.0f, 55.0f, 60.0f,
		101.0f, 114.0f, 127.0f, 140.0f,
		157.0f, 178.0f, 199.0f, 220.0f,
		213.0f, 242.0f, 271.0f, 300.0f
	);
	BOOST_CHECK_EQUAL(A * B, 4.0f * C);
}

/**
 * First test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed1)
{
	BOOST_CHECK_EQUAL(Matrix4::IDENTITY.transposed(), Matrix4::IDENTITY);
}

/**
 * Second test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed2)
{
	BOOST_CHECK_EQUAL(Matrix4::ZERO.transposed(), Matrix4::ZERO);
}

/**
 * Third test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed3)
{
	const Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	const Matrix4 B(
		1.0f, 5.0f, 9.0f, 13.0f,
		2.0f, 6.0f, 10.0f, 14.0f,
		3.0f, 7.0f, 11.0f, 15.0f,
		4.0f, 8.0f, 12.0f, 16.0f
	);
	BOOST_CHECK_EQUAL(A.transposed(), B);
}

/**
 * First test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose1)
{
	Matrix4 A = Matrix4::IDENTITY;
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix4::IDENTITY);
}

/**
 * Second test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose2)
{
	Matrix4 A = Matrix4::ZERO;
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix4::ZERO);
}

/**
 * Third test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose3)
{
	Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	const Matrix4 B(
		1.0f, 5.0f, 9.0f, 13.0f,
		2.0f, 6.0f, 10.0f, 14.0f,
		3.0f, 7.0f, 11.0f, 15.0f,
		4.0f, 8.0f, 12.0f, 16.0f
	);
	A.transpose();
	BOOST_CHECK_EQUAL(A, B);
}

/**
 * First test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant1)
{
	BOOST_CHECK_EQUAL(Matrix4::IDENTITY.determinant(), 1.0f);
}

/**
 * Second test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant2)
{
	BOOST_CHECK_EQUAL(Matrix4::ZERO.determinant(), 0.0f);
}

/**
 * Third test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant3)
{
	const Matrix4 A(
		1.0f, 3.0f, 2.0f, 4.0f,
		4.0f, 2.0f, 3.0f, 1.0f,
		2.0f, 3.0f, 1.0f, 4.0f,
		1.0f, 2.0f, 3.0f, 4.0f
	);
	BOOST_CHECK_EQUAL(A.determinant(), 30.0f);
}

/**
 * Fourth test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant4)
{
	Matrix4 A(
		1.0f, 2.0f, 3.0f, 4.0f,
		5.0f, 6.0f, 7.0f, 8.0f,
		9.0f, 10.0f, 11.0f, 12.0f,
		13.0f, 14.0f, 15.0f, 16.0f
	);
	BOOST_CHECK_EQUAL(A.determinant(), 0.0f);
}

/**
 * First test for the inverse function.
 */
BOOST_AUTO_TEST_CASE(TestInverse1)
{
	BOOST_CHECK_EQUAL(Matrix4::IDENTITY.inverse(), Matrix4::IDENTITY);
}

/**
 * Second test for the inverse function.
 */
BOOST_AUTO_TEST_CASE(TestInverse2)
{
	const Matrix4 A(
		1.0f, 3.0f, 2.0f, 4.0f,
		4.0f, 2.0f, 3.0f, 1.0f,
		2.0f, 3.0f, 1.0f, 4.0f,
		1.0f, 2.0f, 3.0f, 4.0f
	);
	const Matrix4 B(
		-21.0f, 4.0f, 15.0f, 5.0f,
		39.0f, 4.0f, -15.0f, -25.0f,
		9.0f, 4.0f, -15.0f, 5.0f,
		-21.0f, -6.0f, 15.0f, 15.0f
	);
	BOOST_CHECK_EQUAL(A.inverse(), (1.0f / 30.0f) * B);
}

/**
 * First test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory1)
{
	const float angle = 0.0f;
	const Vector3 axis(0.0f, 1.0f, 0.0f);
	const Matrix4 A = Matrix4::angleAxis(angle, axis);

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector3::FORWARD);
}

/**
 * Second test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory2)
{
	const float angle = M_PI;
	const Vector3 axis(0.0f, 1.0f, 0.0f);
	const Matrix4 A = Matrix4::angleAxis(angle, axis);

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::BACK);
}

/**
 * Third test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory3)
{
	const float angle = 0.5f * M_PI;
	const Vector3 axis(0.0f, 0.0f, 1.0f);
	const Matrix4 A = Matrix4::angleAxis(angle, axis);

	BOOST_CHECK_EQUAL(A * Vector4::UP, Vector4::LEFT);
}

/**
 * Fourth test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory4)
{
	const float angle = 2.0f * M_PI;
	const Vector3 axis(1.0f, 1.0f, 1.0f);
	const Matrix4 A = Matrix4::angleAxis(angle, axis.normalized());

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::FORWARD);
}

/**
 * Fifth test for the angle axis static factory function.
 * Tests rotation of a point (homogeneous coordinate equal to 1.0).
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory5)
{
	const float angle = 0.5f * M_PI;
	const Vector3 axis(0.0f, 1.0f, 0.0f);
	const Matrix4 A = Matrix4::angleAxis(angle, axis.normalized());

	BOOST_CHECK_EQUAL(A * Vector4(0.0f, 0.0f, 1.0f, 1.0f), Vector4(1.0f, 0.0f, 0.0f, 1.0f));
}

/**
 * First test for the euler angles static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory1)
{
	const Vector3 angles(0.0f, 0.0f, 0.0f);
	const Matrix4 A = Matrix4::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::FORWARD);
}

/**
 * Second test for the euler angles static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory2)
{
	const Vector3 angles(0.0f, M_PI, 0.0f);
	const Matrix4 A = Matrix4::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::BACK);
}

/**
 * Third test for the euler angles static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory3)
{
	const Vector3 angles(0.0f, 0.0f, 0.5f * M_PI);
	const Matrix4 A = Matrix4::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector4::UP, Vector4::LEFT);
}

/**
 * Fourth test for the euler angles static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory4)
{
	const Vector3 angles(0.0f, 2.0f * M_PI, 2.0f * M_PI);
	const Matrix4 A = Matrix4::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::FORWARD);
}

/**
 * Fifth test for the euler angles static factory function.
 * Tests rotation of a point (homogeneous coordinate equal to 1.0).
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory5)
{
	const Vector3 angles(0.0f, 0.5f * M_PI, 0.0f);
	const Matrix4 A = Matrix4::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector4(0.0f, 0.0f, 1.0f, 1.0f), Vector4(1.0f, 0.0f, 0.0f, 1.0f));
}

/**
 * First test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation1)
{
	const Matrix4 A = Matrix4::fromToRotation(Vector3::FORWARD, Vector3::FORWARD);
	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::FORWARD);
}

/**
 * Second test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation2)
{
	const Matrix4 A = Matrix4::fromToRotation(Vector3::UP, Vector3::LEFT);
	BOOST_CHECK_EQUAL(A * Vector4::UP, Vector4::LEFT);
}

/**
 * Third test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation3)
{
	const Matrix4 A = Matrix4::fromToRotation(Vector3::LEFT, Vector3::RIGHT);
	BOOST_CHECK_EQUAL(A * Vector4::LEFT, Vector4::RIGHT);
}

/**
 * Fourth test for the fromToRotation static factory function.
 * Tests rotation of a point (homogeneous coordinate equal to 1.0).
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation4)
{
	const Matrix4 A = Matrix4::fromToRotation(Vector3::FORWARD, Vector3::DOWN);
	BOOST_CHECK_EQUAL(A * Vector4(0.0f, 0.0f, 1.0f, 1.0f), Vector4(0.0f, -1.0f, 0.0f, 1.0f));
}

/**
 * First test for the lookRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation1)
{
	const Matrix4 A = Matrix4::lookRotation(Vector3::FORWARD, Vector3::ZERO, Vector3::UP);
	const Matrix4 B = Matrix4::lookRotation(Vector3::FORWARD, Vector3::UP);

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::FORWARD);
	BOOST_CHECK_EQUAL(A * Vector4::UP, Vector4::UP);
	BOOST_CHECK_EQUAL(A, B);
}

/**
 * Second test for the lookRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation2)
{
	const Matrix4 A = Matrix4::lookRotation(Vector3::RIGHT, Vector3::ZERO, Vector3::UP);
	const Matrix4 B = Matrix4::lookRotation(Vector3::RIGHT, Vector3::UP);

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::RIGHT);
	BOOST_CHECK_EQUAL(A * Vector4::UP, Vector4::UP);
	BOOST_CHECK_EQUAL(A, B);
}

/**
 * Third test for the lookRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation3)
{
	const Matrix4 A = Matrix4::lookRotation(Vector3::ZERO, Vector3(0.0f, 0.0f, 100.0f), Vector3::UP);
	const Vector4 v1 = A * Vector4::FORWARD;
	const Vector4 v2 = A * Vector4::UP;
	BOOST_CHECK_EQUAL(Vector3(v1.x, v1.y, v1.z), Vector3::BACK);
	BOOST_CHECK_EQUAL(Vector3(v2.x, v2.y, v2.z), Vector3::UP);
}

/**
 * Fourth test for the lookRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation4)
{
	const Matrix4 A = Matrix4::lookRotation(Vector3::UP, Vector3::ZERO, Vector3::FORWARD);
	const Matrix4 B = Matrix4::lookRotation(Vector3::UP, Vector3::FORWARD);

	BOOST_CHECK_EQUAL(A * Vector4::FORWARD, Vector4::UP);
	BOOST_CHECK_EQUAL(A * Vector4::UP, Vector4::FORWARD);
	BOOST_CHECK_EQUAL(A, B);
}

BOOST_AUTO_TEST_SUITE_END()
