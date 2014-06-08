#include <boost/test/unit_test.hpp>
#include <cmath>
#include <Vector4.hpp>

using namespace M3D;

BOOST_AUTO_TEST_SUITE(Vector4_Test_Suite)

/**
 * Ensure that the default constructor sets all components to zero.
 */
BOOST_AUTO_TEST_CASE(TestDefaultConstructor)
{
	const Vector4 v;

	BOOST_CHECK_EQUAL(v.x, 0.0f);
	BOOST_CHECK_EQUAL(v.y, 0.0f);
	BOOST_CHECK_EQUAL(v.z, 0.0f);
	BOOST_CHECK_EQUAL(v.w, 0.0f);
}

/**
 * Ensure that the constructor sets all component values to those that were
 * specified.
 */
BOOST_AUTO_TEST_CASE(TestConstructor)
{
	const float x = 1.0f;
	const float y = 2.0f;
	const float z = 3.0f;
	const float w = 4.0f;

	const Vector4 v(x, y, z, w);

	BOOST_CHECK_EQUAL(v.x, x);
	BOOST_CHECK_EQUAL(v.y, y);
	BOOST_CHECK_EQUAL(v.z, z);
	BOOST_CHECK_EQUAL(v.w, w);
}

/**
 * First test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator1)
{
	const Vector4 v1(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 v2(0.0f, 0.0f, 0.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, true);
}

/**
 * Second test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator2)
{
	const Vector4 v1(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 v2(1.0f, 0.0f, 0.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * Third test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator3)
{
	const Vector4 v1(0.0f, 2.0f, 0.0f, 0.0f);
	const Vector4 v2(0.0f, 0.0f, 0.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * Fourth test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator4)
{
	const Vector4 v1(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 v2(0.0f, 0.0f, 3.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * Fifth test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator5)
{
	const Vector4 v1(0.0f, 0.0f, 0.0f, 0.0f);
	const Vector4 v2(0.0f, 0.0f, 0.0f, 4.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * First test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator1)
{
	const Vector4 v1(1.0f, 1.0f, 1.0f, 1.0f);
	const Vector4 v2(1.0f, 1.0f, 1.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, false);
}

/**
 * Second test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator2)
{
	const Vector4 v1(1.0f, 1.0f, 1.0f, 1.0f);
	const Vector4 v2(0.0f, 1.0f, 1.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Third test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator3)
{
	const Vector4 v1(1.0f, 1.0f, 1.0f, 1.0f);
	const Vector4 v2(1.0f, 2.0f, 1.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Fourth test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator4)
{
	const Vector4 v1(1.0f, 1.0f, 1.0f, 1.0f);
	const Vector4 v2(1.0f, 1.0f, -3.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Fifth test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator5)
{
	const Vector4 v1(1.0f, 1.0f, 1.0f, 1.001f);
	const Vector4 v2(1.0f, 1.0f, 1.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Test the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator)
{
	const Vector4 v1(2.0f, 3.0f, 5.0f, 7.0f);
	const Vector4 v2(7.0f, -9.0f, 11.0f, -13.0f);

	BOOST_CHECK_EQUAL(v1 + v2, Vector4(9.0f, -6.0f, 16.0f, -6.0f));
}

/**
 * Test the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator)
{
	const Vector4 v1(2.0f, 3.0f, 5.0f, 7.0f);
	const Vector4 v2(7.0f, -9.0f, 11.0f, -13.0f);

	BOOST_CHECK_EQUAL(v1 - v2, Vector4(-5.0f, 12.0f, -6.0f, 20.0f));
}

/**
 * Test the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator)
{
	const Vector4 v1(0.0f, 1.0f, -2.0f, 3.0f);

	BOOST_CHECK_EQUAL(-v1, Vector4(0.0f, -1.0f, 2.0f, -3.0f));
}

/**
 * First test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator1)
{
	const Vector4 v(1.0f, -2.0f, 0.0f, 5.0f);

	BOOST_CHECK_EQUAL(v * 5, Vector4(5.0f, -10.0f, 0.0f, 25.0f));
}

/**
 * Second test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator2)
{
	const Vector4 v(-2.0f, 4.0f, 6.0f, -8.0f);

	BOOST_CHECK_EQUAL(-3.0f * v, Vector4(6.0f, -12.0f, -18.0f, 24.0f));
}

/**
 * Test the scalar division operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarDivisionOperator)
{
	const Vector4 v(3.0f, 6.0f, -9.0f, 30.0f);

	BOOST_CHECK_EQUAL(v / 3.0f, Vector4(1.0f, 2.0f, -3.0f, 10.0f));
}

/**
 * Test the sqrMagnitude function.
 */
BOOST_AUTO_TEST_CASE(TestSqrMagnitude)
{
	const Vector4 v(2.0f, 3.0f, 5.0f, 7.0f);

	BOOST_CHECK_CLOSE(v.sqrMagnitude(), 87.0f, 1e-3);
}

/**
 * Test the magnitude function.
 */
BOOST_AUTO_TEST_CASE(TestMagnitude)
{
	const Vector4 v(2.0f, 4.0f, 4.0f, 8.0f);

	BOOST_CHECK_CLOSE(v.magnitude(), 10.0f, 1e-3);
}

/**
 * Test the normalized function.
 */
BOOST_AUTO_TEST_CASE(TestNormalized)
{
	const Vector4 v(-4.0f, 0.0f, 3.0f, 12.0f);
	const Vector4 n = v.normalized();

	BOOST_CHECK_EQUAL(n, Vector4(-4.0f / 13.0f, 0.0f, 3.0f / 13.0f, 12.0f / 13.0f));
}

/**
 * Test the normalize function.
 */
BOOST_AUTO_TEST_CASE(TestNormalize)
{
	Vector4 v(4.0f, 0.0f, -3.0f, 12.0f);
	v.normalize();

	BOOST_CHECK_EQUAL(v, Vector4(4.0f / 13.0f, 0.0f, -3.0f / 13.0f, 12.0f / 13.0f));
}

/**
 * Test the scale function.
 */
BOOST_AUTO_TEST_CASE(TestScale)
{
	const Vector4 v1(2.0f, 3.0f, 4.0f, 5.0f);
	const Vector4 v2(-3.0f, 9.0f, 0.5f, 10.0f);

	BOOST_CHECK_EQUAL(scale(v1, v2), Vector4(-6.0f, 27.0f, 2.0f, 50.0f));
}

/**
 * Test the dot-product function.
 */
BOOST_AUTO_TEST_CASE(TestDotProduct)
{
	const Vector4 v1(2.0f, 4.0f, -1.0f, 3.0f);
	const Vector4 v2(1.0f, -3.0f, 5.0f, -4.0f);
	const float d = dot(v1, v2);

	BOOST_CHECK_CLOSE(d, -27.0f, 1e-3);
}

/**
 * First test for the sqrDistance function.
 */
BOOST_AUTO_TEST_CASE(TestSqrDistance1)
{
	Vector4 v(2.0f, -3.0f, 5.0f, -7.0f);

	BOOST_CHECK_CLOSE(sqrDistance(v, v), 0.0f, 1e-3);
}

/**
 * Second test for the sqrDistance function.
 */
BOOST_AUTO_TEST_CASE(TestSqrDistance2)
{
	Vector4 v1(-2.0f, 3.0f, -5.0, 7.0f);
	Vector4 v2(1.0f, 2.0f, 3.0f, 4.0f);

	BOOST_CHECK_CLOSE(sqrDistance(v1, v2), 83.0f, 1e-3);
}

/**
 * First test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance1)
{
	Vector4 v(1.0f, 2.0f, 3.0f, 4.0f);

	BOOST_CHECK_CLOSE(distance(v, v), 0.0f, 1e-3);
}

/**
 * Second test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance2)
{
	Vector4 v1(0.0f, 0.0f, 0.0f, 0.0f);
	Vector4 v2(4.0f, 2.0f, 4.0f, 8.0f);

	BOOST_CHECK_CLOSE(distance(v1, v2), 10.0f, 1e-3);
}

/**
 * Third test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance3)
{
	Vector4 v1(0.0f, 0.0f, 0.0f, -10.0f);
	Vector4 v2(0.0f, 0.0f, 0.0f, 1.0f);

	BOOST_CHECK_CLOSE(distance(v1, v2), 11.0f, 1e-3);
}

BOOST_AUTO_TEST_SUITE_END()
