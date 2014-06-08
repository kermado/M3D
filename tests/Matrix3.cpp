#include <boost/test/unit_test.hpp>
#include <cmath>
#include <Matrix3.hpp>
#include <Vector3.hpp>

using namespace M3D;

BOOST_AUTO_TEST_SUITE(Matrix3_Test_Suite)

/**
 * Test that the default constructor constructs the identity matrix.
 */
BOOST_AUTO_TEST_CASE(TestDefaultConstructor)
{
	const Matrix3 A;
	for (size_t i = 0; i < 9; ++i)
	{
		if (i % 4 == 0)
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
	float arr[9] = {-1.0f, 1.0f, 2.0f, 3.5f, 1.9f, 100.0f, -1.25f, -1e-6f, 33.0f};
	const Matrix3 A(arr);
	for (size_t i = 0; i < 9; ++i)
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
	float arr[9] = {0.1f, 1.2f, 2.3f, 3.4f, 4.5f, -5.6f, 6.7f, 7.8f, -8.9f};
	const Matrix3 A(0.1f, 1.2f, 2.3f, 3.4f, 4.5f, -5.6f, 6.7f, 7.8f, -8.9f);
	for (size_t i = 0; i < 9; ++i)
	{
		BOOST_CHECK_CLOSE(A[i], arr[i], 1e-6);
	}
}

/**
 * First test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator1)
{
	const Matrix3 A;
	const Matrix3 B;

	BOOST_CHECK(A == B);
}

/**
 * Second test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator2)
{
	const Matrix3 A(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);

	BOOST_CHECK(A == A);
}

/**
 * Third test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator3)
{
	const Matrix3 A(1.0f, 2.0f, 3.0f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);
	const Matrix3 B(1.0f, 2.0f, 3.1f, 4.0f, 5.0f, 6.0f, 7.0f, 8.0f, 9.0f);

	BOOST_CHECK_EQUAL(A == B, false);
}

/**
 * First test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator1)
{
	const Matrix3 A;
	const Matrix3 B;

	BOOST_CHECK_EQUAL(A != B, false);
}

/**
 * Second test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator2)
{
	const Matrix3 A(2.0f, 3.0f, 5.0f, 7.0f, 11.0f, 13.0f, 17.0f, 19.0f, 23.0f);

	BOOST_CHECK_EQUAL(A != A, false);
}

/**
 * Third test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator3)
{
	const Matrix3 A(2.0f, 3.0f, 5.0f, 7.0f, 11.0f, 13.0f, 17.0f, 19.0f, 23.0f);
	const Matrix3 B(2.0f, 3.0f, 5.0f, 7.0f, 11.0f, 13.0f, 17.0f, 19.0f, 29.0f);

	BOOST_CHECK(A != B);
}

/**
 * First test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator1)
{
	const Matrix3 A;
	const Matrix3 B;

	BOOST_CHECK_EQUAL(A + B, Matrix3(2.0f, 0.0f, 0.0f, 0.0f, 2.0f, 0.0f, 0.0f, 0.0f, 2.0f));
}

/**
 * Second test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator2)
{
	const Matrix3 A;
	const Matrix3 B(-1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f);

	BOOST_CHECK_EQUAL(A + B, Matrix3::ZERO);
}

/**
 * Third test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator3)
{
	const Matrix3 A(2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f, 18.0f);
	const Matrix3 B(1.0f, 3.0f, 5.0f, 7.0f, 9.0f, 11.0f, 13.0f, 15.0f, 17.0f);

	BOOST_CHECK_EQUAL(A + B, Matrix3(3.0f, 7.0f, 11.0f, 15.0f, 19.0f, 23.0f, 27.0f, 31.0f, 35.0f));
}

/**
 * First test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator1)
{
	const Matrix3 A;
	const Matrix3 B;

	BOOST_CHECK_EQUAL(A - B, Matrix3::ZERO);
}

/**
 * Second test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator2)
{
	const Matrix3 A;
	const Matrix3 B = Matrix3::ZERO;

	BOOST_CHECK_EQUAL(A - B, Matrix3::IDENTITY);
}

/**
 * Third test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator3)
{
	const Matrix3 A(2.0f, 4.0f, 6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f, 18.0f);
	const Matrix3 B(5.0f, 1.0f, 2.0f, 6.0f, 12.0f, 1.0f, 0.0f, 6.0f, -18.0f);

	BOOST_CHECK_EQUAL(A - B, Matrix3(-3.0f, 3.0f, 4.0f, 2.0f, -2.0f, 11.0f, 14.0f, 10.0f, 36.0f));
}

/**
 * First test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator1)
{
	BOOST_CHECK_EQUAL(-Matrix3::ZERO, Matrix3::ZERO);
}

/**
 * Second test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator2)
{
	BOOST_CHECK_EQUAL(-Matrix3::IDENTITY, Matrix3(-1.0f, 0.0f, 0.0f, 0.0f, -1.0f, 0.0f, 0.0f, 0.0f, -1.0f));
}

/**
 * Third test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator3)
{
	const Matrix3 A(2.0f, 4.0f, -6.0f, 8.0f, 10.0f, 12.0f, 14.0f, 16.0f, 18.0f);
	BOOST_CHECK_EQUAL(-A, Matrix3(-2.0f, -4.0f, 6.0f, -8.0f, -10.0f, -12.0f, -14.0f, -16.0f, -18.0f));
}

/**
 * First test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator1)
{
	const Matrix3 A(1.0f, 3.0f, 5.0f, 7.0f, 9.0f, 11.0f, 13.0f, 15.0f, 17.0f);

	BOOST_CHECK_EQUAL(A * 2.0f, Matrix3(2.0f, 6.0f, 10.0f, 14.0f, 18.0f, 22.0f, 26.0f, 30.0f, 34.0f));
}

/**
 * Second test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator2)
{
	const Matrix3 A(1.0f, 3.0f, 5.0f, 7.0f, 9.0f, 11.0f, 13.0f, 15.0f, 17.0f);

	BOOST_CHECK_EQUAL(A * 0.0f, Matrix3::ZERO);
}

/**
 * Third test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator3)
{
	const Matrix3 A(2.0f, -4.0f, 6.0f, -8.0f, 10.0f, -12.0f, 14.0f, -16.0f, 18.0f);

	BOOST_CHECK_EQUAL(A * 3.5f, 3.5f * A);
}

/**
 * First test for the column-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestColumnVectorMultiplicationOperator1)
{
	const Vector3 v(2.0f, 4.0f, -6.0f);
	BOOST_CHECK_EQUAL(Matrix3::IDENTITY * v, v);
}

/**
 * Second test for the column-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestColumnVectorMultiplicationOperator2)
{
	const Vector3 v(1.0f, 2.0f, 3.0f);
	const Matrix3 A(4.0f, 5.0f, 6.0f, 6.0f, 5.0f, 4.0f, 4.0f, 6.0f, 5.0f);
	BOOST_CHECK_EQUAL(A * v, Vector3(32.0f, 28.0f, 31.0f));
}

/**
 * First test for the row-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestRowVectorMultiplicationOperator1)
{
	const Vector3 v(1.0f, -3.0f, 5.0f);
	BOOST_CHECK_EQUAL(v * Matrix3::IDENTITY, v);
}

/**
 * Second test for the row-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestRowVectorMultiplicationOperator2)
{
	const Vector3 v(1.0f, 2.0f, 3.0f);
	const Matrix3 A(4.0f, 5.0f, 6.0f, 6.0f, 5.0f, 4.0f, 4.0f, 6.0f, 5.0f);
	BOOST_CHECK_EQUAL(v * A, Vector3(28.0f, 33.0f, 29.0f));
}

/**
 * First test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator1)
{
	BOOST_CHECK_EQUAL(Matrix3::IDENTITY * Matrix3::IDENTITY, Matrix3::IDENTITY);
}

/**
 * Second test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator2)
{
	BOOST_CHECK_EQUAL(Matrix3::IDENTITY * Matrix3::ZERO, Matrix3::ZERO);
}

/**
 * Third test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator3)
{
	const Matrix3 A(1.0f, 2.0f, 3.0f, 3.0f, 2.0f, 1.0f, 2.0f, 1.0f, 3.0f);
	const Matrix3 B(4.0f, 5.0f, 6.0f, 6.0f, 5.0f, 4.0f, 4.0f, 6.0f, 5.0f);
	BOOST_CHECK_EQUAL(A * B, Matrix3(28.0f, 33.0f, 29.0f, 28.0f, 31.0f, 31.0f, 26.0f, 33.0f, 31.0f));
}

/**
 * Fourth test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator4)
{
	const Matrix3 A(1.0f, 2.0f, 3.0f, 3.0f, 2.0f, 1.0f, 2.0f, 1.0f, 3.0f);
	const Matrix3 B(4.0f, 5.0f, 6.0f, 6.0f, 5.0f, 4.0f, 4.0f, 6.0f, 5.0f);
	BOOST_CHECK_EQUAL(B * A, Matrix3(31.0f, 24.0f, 35.0f, 29.0f, 26.0f, 35.0f, 32.0f, 25.0f, 33.0f));
}

/**
 * First test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed1)
{
	BOOST_CHECK_EQUAL(Matrix3::IDENTITY.transposed(), Matrix3::IDENTITY);
}

/**
 * Second test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed2)
{
	BOOST_CHECK_EQUAL(Matrix3::ZERO.transposed(), Matrix3::ZERO);
}

/**
 * Third test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed3)
{
	const Matrix3 A(4.0f, 5.0f, 6.0f, 6.0f, 5.0f, 4.0f, 4.0f, 6.0f, 5.0f);
	BOOST_CHECK_EQUAL(A.transposed(), Matrix3(4.0f, 6.0f, 4.0f, 5.0f, 5.0f, 6.0f, 6.0f, 4.0f, 5.0f));
}

/**
 * Fourth test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed4)
{
	const Matrix3 A(1.0f, 2.0f, 3.0f, 3.0f, 2.0f, 1.0f, 2.0f, 1.0f, 3.0f);
	BOOST_CHECK_EQUAL(A.transposed().transposed(), A);
}

/**
 * First test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose1)
{
	Matrix3 A = Matrix3::IDENTITY;
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix3::IDENTITY);
}

/**
 * Second test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose2)
{
	Matrix3 A = Matrix3::ZERO;
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix3::ZERO);
}

/**
 * Third test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose3)
{
	Matrix3 A(4.0f, 5.0f, 6.0f, 6.0f, 5.0f, 4.0f, 4.0f, 6.0f, 5.0f);
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix3(4.0f, 6.0f, 4.0f, 5.0f, 5.0f, 6.0f, 6.0f, 4.0f, 5.0f));
}

/**
 * Fourth test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose4)
{
	Matrix3 A(1.0f, 2.0f, 3.0f, 3.0f, 2.0f, 1.0f, 2.0f, 1.0f, 3.0f);
	A.transpose();
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix3(1.0f, 2.0f, 3.0f, 3.0f, 2.0f, 1.0f, 2.0f, 1.0f, 3.0f));
}

/**
 * First test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant1)
{
	BOOST_CHECK_EQUAL(Matrix3::IDENTITY.determinant(), 1.0f);
}

/**
 * Second test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant2)
{
	BOOST_CHECK_EQUAL(Matrix3::ZERO.determinant(), 0.0f);
}

/**
 * Third test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant3)
{
	const Matrix3 A(4.0f, 5.0f, 6.0f, 6.0f, 5.0f, 4.0f, 4.0f, 6.0f, 5.0f);
	BOOST_CHECK_EQUAL(A.determinant(), 30.0f);
}

/**
 * First test for the inverse function.
 */
BOOST_AUTO_TEST_CASE(TestInverse1)
{
	BOOST_CHECK_EQUAL(Matrix3::IDENTITY.inverse(), Matrix3::IDENTITY);
}

/**
 * Second test for the inverse function.
 */
BOOST_AUTO_TEST_CASE(TestInverse2)
{
	const Matrix3 A(1.0f, 2.0f, 3.0f, 3.0f, 2.0f, 1.0f, 2.0f, 1.0f, 3.0f);
	BOOST_CHECK_EQUAL(A.inverse(), (1.0f / 12.0f) * Matrix3(-5.0f, 3.0f, 4.0f, 7.0f, 3.0f, -8.0f, 1.0f, -3.0f, 4.0f));
}

/**
 * First test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory1)
{
	const float angle = 0.0f;
	const Vector3 axis(0.0f, 1.0f, 0.0f);
	const Matrix3 A = Matrix3::angleAxis(angle, axis);

	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::FORWARD);
}

/**
 * Second test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory2)
{
	const float angle = M_PI;
	const Vector3 axis(0.0f, 1.0f, 0.0f);
	const Matrix3 A = Matrix3::angleAxis(angle, axis);

	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::BACK);
}

/**
 * Third test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory3)
{
	const float angle = 0.5f * M_PI;
	const Vector3 axis(0.0f, 0.0f, 1.0f);
	const Matrix3 A = Matrix3::angleAxis(angle, axis);

	BOOST_CHECK_EQUAL(A * Vector3::UP, Vector3::LEFT);
}

/**
 * Fourth test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory4)
{
	const float angle = 2.0f * M_PI;
	const Vector3 axis(1.0f, 1.0f, 1.0f);
	const Matrix3 A = Matrix3::angleAxis(angle, axis.normalized());

	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::FORWARD);
}

/**
 * First test for the euler angles static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory1)
{
	const Vector3 angles(0.0f, 0.0f, 0.0f);
	const Matrix3 A = Matrix3::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::FORWARD);
}

/**
 * Second test for the euler angles static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory2)
{
	const Vector3 angles(0.0f, M_PI, 0.0f);
	const Matrix3 A = Matrix3::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::BACK);
}

/**
 * Third test for the euler angles static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory3)
{
	const Vector3 angles(0.0f, 0.0f, 0.5f * M_PI);
	const Matrix3 A = Matrix3::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector3::UP, Vector3::LEFT);
}

/**
 * Fourth test for the euler angles static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAnglesFactory4)
{
	const Vector3 angles(0.0f, 2.0f * M_PI, 2.0f * M_PI);
	const Matrix3 A = Matrix3::euler(angles);

	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::FORWARD);
}

/**
 * First test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation1)
{
	const Matrix3 A = Matrix3::fromToRotation(Vector3::FORWARD, Vector3::FORWARD);
	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::FORWARD);
}

/**
 * Second test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation2)
{
	const Matrix3 A = Matrix3::fromToRotation(Vector3::UP, Vector3::LEFT);
	BOOST_CHECK_EQUAL(A * Vector3::UP, Vector3::LEFT);
}

/**
 * Third test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation3)
{
	const Matrix3 A = Matrix3::fromToRotation(Vector3::LEFT, Vector3::RIGHT);
	BOOST_CHECK_EQUAL(A * Vector3::LEFT, Vector3::RIGHT);
}

/**
 * First test for the lookRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation1)
{
	const Matrix3 A = Matrix3::lookRotation(Vector3::FORWARD, Vector3::UP);
	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::FORWARD);
	BOOST_CHECK_EQUAL(A * Vector3::UP, Vector3::UP);
}


/**
 * Second test for the lookRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation2)
{
	const Matrix3 A = Matrix3::lookRotation(Vector3::RIGHT, Vector3::UP);
	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::RIGHT);
	BOOST_CHECK_EQUAL(A * Vector3::UP, Vector3::UP);
}

/**
 * Third test for the lookRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation3)
{
	const Matrix3 A = Matrix3::lookRotation(Vector3::BACK, Vector3::UP);
	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::BACK);
	BOOST_CHECK_EQUAL(A * Vector3::UP, Vector3::UP);
}

/**
 * Fourth test for the lookRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation4)
{
	const Matrix3 A = Matrix3::lookRotation(Vector3::UP, Vector3::FORWARD);
	BOOST_CHECK_EQUAL(A * Vector3::FORWARD, Vector3::UP);
	BOOST_CHECK_EQUAL(A * Vector3::UP, Vector3::FORWARD);
}

BOOST_AUTO_TEST_SUITE_END()
