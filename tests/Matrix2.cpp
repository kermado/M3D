#include <M3D/Matrix2.hpp>
#include <M3D/Vector2.hpp>

#include <boost/test/unit_test.hpp>
#include <cmath>

using namespace M3D;

BOOST_AUTO_TEST_SUITE(Matrix2_Test_Suite)

/**
 * Test that the default constructor constructs the identity matrix.
 */
BOOST_AUTO_TEST_CASE(TestDefaultConstructor)
{
	const Matrix2 A;
	BOOST_CHECK_CLOSE(A[0], 1.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[1], 0.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[2], 0.0f, 1e-6);
	BOOST_CHECK_CLOSE(A[3], 1.0f, 1e-6);
}

/**
 * Test that the constructor constructs the matrix defined by the passed
 * row-major array.
 */
BOOST_AUTO_TEST_CASE(TestArrayConstructor)
{
	float arr[4] = {-10.0f, 4.7f, -2.4f, 3.5f};
	const Matrix2 A(arr);
	for (size_t i = 0; i < 4; ++i)
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
	const Matrix2 A(0.1f, 1.2f, 2.3f, 3.4f);
	BOOST_CHECK_CLOSE(A[0], 0.1f, 1e-6);
	BOOST_CHECK_CLOSE(A[1], 1.2f, 1e-6);
	BOOST_CHECK_CLOSE(A[2], 2.3f, 1e-6);
	BOOST_CHECK_CLOSE(A[3], 3.4f, 1e-6);
}

/**
 * First test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator1)
{
	const Matrix2 A;
	const Matrix2 B;

	BOOST_CHECK(A == B);
}

/**
 * Second test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator2)
{
	const Matrix2 A(1.0f, 2.0f, 3.0f, 4.0f);

	BOOST_CHECK(A == A);
}

/**
 * Third test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator3)
{
	const Matrix2 A(1.0f, 2.0f, 3.0f, 4.0f);
	const Matrix2 B(1.0f, 2.0f, 3.1f, 4.0f);

	BOOST_CHECK_EQUAL(A == B, false);
}

/**
 * First test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator1)
{
	const Matrix2 A;
	const Matrix2 B;

	BOOST_CHECK_EQUAL(A != B, false);
}

/**
 * Second test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator2)
{
	const Matrix2 A(2.0f, 3.0f, 5.0f, 7.0f);

	BOOST_CHECK_EQUAL(A != A, false);
}

/**
 * Third test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator3)
{
	const Matrix2 A(2.0f, 3.0f, 5.0f, 7.0f);
	const Matrix2 B(2.0f, 1.0f, 5.0f, 7.0f);

	BOOST_CHECK(A != B);
}

/**
 * First test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator1)
{
	const Matrix2 A;
	const Matrix2 B;

	BOOST_CHECK_EQUAL(A + B, Matrix2(2.0f, 0.0f, 0.0f, 2.0f));
}

/**
 * Second test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator2)
{
	const Matrix2 A;
	const Matrix2 B(-1.0f, 0.0f, 0.0f, -1.0f);

	BOOST_CHECK_EQUAL(A + B, Matrix2::ZERO);
}

/**
 * Third test for the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator3)
{
	const Matrix2 A(2.0f, 4.0f, 6.0f, 8.0f);
	const Matrix2 B(1.0f, 3.0f, 5.0f, 7.0f);

	BOOST_CHECK_EQUAL(A + B, Matrix2(3.0f, 7.0f, 11.0f, 15.0f));
}

/**
 * First test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator1)
{
	const Matrix2 A;
	const Matrix2 B;

	BOOST_CHECK_EQUAL(A - B, Matrix2::ZERO);
}

/**
 * Second test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator2)
{
	const Matrix2 A;
	const Matrix2 B = Matrix2::ZERO;

	BOOST_CHECK_EQUAL(A - B, Matrix2::IDENTITY);
}

/**
 * Third test for the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator3)
{
	const Matrix2 A(2.0f, 4.0f, 6.0f, 8.0f);
	const Matrix2 B(5.0f, 1.0f, 2.0f, 6.0f);

	BOOST_CHECK_EQUAL(A - B, Matrix2(-3.0f, 3.0f, 4.0f, 2.0f));
}

/**
 * First test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator1)
{
	BOOST_CHECK_EQUAL(-Matrix2::ZERO, Matrix2::ZERO);
}

/**
 * Second test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator2)
{
	BOOST_CHECK_EQUAL(-Matrix2::IDENTITY, Matrix2(-1.0f, 0.0f, 0.0f, -1.0f));
}

/**
 * Third test for the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator3)
{
	const Matrix2 A(2.0f, 4.0f, -6.0f, 8.0f);
	BOOST_CHECK_EQUAL(-A, Matrix2(-2.0f, -4.0f, 6.0f, -8.0f));
}

/**
 * First test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator1)
{
	const Matrix2 A(1.0f, 3.0f, 5.0f, -7.0f);

	BOOST_CHECK_EQUAL(A * 2.0f, Matrix2(2.0f, 6.0f, 10.0f, -14.0f));
}

/**
 * Second test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator2)
{
	const Matrix2 A(1.0f, 3.0f, -5.0f, 7.0f);

	BOOST_CHECK_EQUAL(A * 0.0f, Matrix2::ZERO);
}

/**
 * Third test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator3)
{
	const Matrix2 A(2.0f, -4.0f, 6.0f, -8.0f);

	BOOST_CHECK_EQUAL(A * 3.5f, 3.5f * A);
}

/**
 * First test for the column-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestColumnVectorMultiplicationOperator1)
{
	const Vector2 v(2.0f, 4.0f);
	BOOST_CHECK_EQUAL(Matrix2::IDENTITY * v, v);
}

/**
 * Second test for the column-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestColumnVectorMultiplicationOperator2)
{
	const Vector2 v(1.0f, 2.0f);
	const Matrix2 A(4.0f, 5.0f, 6.0f, 7.0f);
	BOOST_CHECK_EQUAL(A * v, Vector2(14.0f, 20.0f));
}

/**
 * First test for the row-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestRowVectorMultiplicationOperator1)
{
	const Vector2 v(1.0f, -3.0f);
	BOOST_CHECK_EQUAL(v * Matrix2::IDENTITY, v);
}

/**
 * Second test for the row-vector multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestRowVectorMultiplicationOperator2)
{
	const Vector2 v(1.0f, 2.0f);
	const Matrix2 A(4.0f, 5.0f, 6.0f, 7.0f);
	BOOST_CHECK_EQUAL(v * A, Vector2(16.0f, 19.0f));
}

/**
 * First test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator1)
{
	BOOST_CHECK_EQUAL(Matrix2::IDENTITY * Matrix2::IDENTITY, Matrix2::IDENTITY);
}

/**
 * Second test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator2)
{
	BOOST_CHECK_EQUAL(Matrix2::IDENTITY * Matrix2::ZERO, Matrix2::ZERO);
}

/**
 * Third test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator3)
{
	const Matrix2 A(1.0f, 2.0f, 3.0f, 4.0f);
	const Matrix2 B(5.0f, 6.0f, 7.0f, 8.0f);
	BOOST_CHECK_EQUAL(A * B, Matrix2(19.0f, 22.0f, 43.0f, 50.0f));
}

/**
 * Fourth test for the matrix multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMatrixMultiplicationOperator4)
{
	const Matrix2 A(1.0f, 2.0f, 3.0f, 4.0f);
	const Matrix2 B(5.0f, 6.0f, 7.0f, 8.0f);
	BOOST_CHECK_EQUAL(B * A, Matrix2(23.0f, 34.0f, 31.0f, 46.0f));
}

/**
 * First test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed1)
{
	BOOST_CHECK_EQUAL(Matrix2::IDENTITY.transposed(), Matrix2::IDENTITY);
}

/**
 * Second test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed2)
{
	BOOST_CHECK_EQUAL(Matrix2::ZERO.transposed(), Matrix2::ZERO);
}

/**
 * Third test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed3)
{
	const Matrix2 A(1.0f, 2.0f, 3.0f, 4.0f);
	BOOST_CHECK_EQUAL(A.transposed(), Matrix2(1.0f, 3.0f, 2.0f, 4.0f));
}

/**
 * Fourth test for the transposed function.
 */
BOOST_AUTO_TEST_CASE(TestTransposed4)
{
	const Matrix2 A(1.0f, 2.0f, 3.0f, 4.0f);
	BOOST_CHECK_EQUAL(A.transposed().transposed(), A);
}

/**
 * First test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose1)
{
	Matrix2 A = Matrix2::IDENTITY;
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix2::IDENTITY);
}

/**
 * Second test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose2)
{
	Matrix2 A = Matrix2::ZERO;
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix2::ZERO);
}

/**
 * Third test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose3)
{
	Matrix2 A(4.0f, 5.0f, 6.0f, 7.0f);
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix2(4.0f, 6.0f, 5.0f, 7.0f));
}

/**
 * Fourth test for the transpose function.
 */
BOOST_AUTO_TEST_CASE(TestTranspose4)
{
	Matrix2 A(4.0f, 5.0f, 6.0f, 7.0f);
	A.transpose();
	A.transpose();
	BOOST_CHECK_EQUAL(A, Matrix2(4.0f, 5.0f, 6.0f, 7.0f));
}

/**
 * First test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant1)
{
	BOOST_CHECK_EQUAL(Matrix2::IDENTITY.determinant(), 1.0f);
}

/**
 * Second test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant2)
{
	BOOST_CHECK_EQUAL(Matrix2::ZERO.determinant(), 0.0f);
}

/**
 * Third test for the determinant function.
 */
BOOST_AUTO_TEST_CASE(TestDeterminant3)
{
	const Matrix2 A(1.0f, 2.0f, 3.0f, 4.0f);
	BOOST_CHECK_EQUAL(A.determinant(), -2.0f);
}

/**
 * First test for the inverse function.
 */
BOOST_AUTO_TEST_CASE(TestInverse1)
{
	BOOST_CHECK_EQUAL(Matrix2::IDENTITY.inverse(), Matrix2::IDENTITY);
}

/**
 * Second test for the inverse function.
 */
BOOST_AUTO_TEST_CASE(TestInverse2)
{
	const Matrix2 A(1.0f, 2.0f, 3.0f, 4.0f);
	BOOST_CHECK_EQUAL(A.inverse(), Matrix2(-2.0f, 1.0f, 1.5f, -0.5f));
}

/**
 * First test for the scaling static factory function.
 */
BOOST_AUTO_TEST_CASE(TestScaling1)
{
	const Matrix2 A = Matrix2::scaling(Vector2(0.0f, 0.0f));
	BOOST_CHECK_EQUAL(A, Matrix2::ZERO);
}

/**
 * Second test for the scaling static factory function.
 */
BOOST_AUTO_TEST_CASE(TestScaling2)
{
	const Matrix2 A = Matrix2::scaling(Vector2(1.0f, 1.0f));
	BOOST_CHECK_EQUAL(A, Matrix2::IDENTITY);
}

/**
 * Third test for the scaling static factory function.
 */
BOOST_AUTO_TEST_CASE(TestScaling3)
{
	const Matrix2 A = Matrix2::scaling(Vector2(2.0f, 4.0f));
	const Vector2 v(1.0f, 2.0f);
	BOOST_CHECK_EQUAL(A * v, Vector2(2.0f, 8.0f));
}

/**
 * Fourth test for the scaling static factory function.
 */
BOOST_AUTO_TEST_CASE(TestScaling4)
{
	const Matrix2 A = Matrix2::scaling(10.0f);
	const Vector2 v(3.0f, -4.0f);
	BOOST_CHECK_EQUAL(A * v, Vector2(30.0f, -40.0f));
}

/**
 * First test for the angleRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleRotation1)
{
	const Matrix2 A = Matrix2::angleRotation(0.0f);
	BOOST_CHECK_EQUAL(A * Vector2::RIGHT, Vector2::RIGHT);
}

/**
 * Second test for the angleRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleRotation2)
{
	const Matrix2 A = Matrix2::angleRotation(0.5f * M_PI);
	BOOST_CHECK_EQUAL(A * Vector2::RIGHT, Vector2::UP);
}

/**
 * Third test for the angleRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleRotation3)
{
	const Matrix2 A = Matrix2::angleRotation(M_PI);
	BOOST_CHECK_EQUAL(A * Vector2::RIGHT, Vector2::LEFT);
}

/**
 * Fourth test for the angleRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleRotation4)
{
	const Matrix2 A = Matrix2::angleRotation(1.5f * M_PI);
	BOOST_CHECK_EQUAL(A * Vector2::DOWN, Vector2::LEFT);
}

/**
 * First test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation1)
{
	const Matrix2 A = Matrix2::fromToRotation(Vector2::RIGHT, Vector2::RIGHT);
	BOOST_CHECK_EQUAL(A * Vector2::RIGHT, Vector2::RIGHT);
}

/**
 * Second test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation2)
{
	const Matrix2 A = Matrix2::fromToRotation(Vector2::RIGHT, Vector2::UP);
	BOOST_CHECK_EQUAL(A * Vector2::RIGHT, Vector2::UP);
}

/**
 * Third test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation3)
{
	const Matrix2 A = Matrix2::fromToRotation(Vector2::LEFT, Vector2::RIGHT);
	BOOST_CHECK_EQUAL(A * Vector2::LEFT, Vector2::RIGHT);
}

/**
 * Fourth test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation4)
{
	const Matrix2 A = Matrix2::fromToRotation(Vector2::RIGHT, Vector2::ONE);
	BOOST_CHECK_EQUAL(A * Vector2::RIGHT, Vector2::ONE.normalized());
}

BOOST_AUTO_TEST_SUITE_END()
