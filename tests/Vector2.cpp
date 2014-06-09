#include <boost/test/unit_test.hpp>
#include <cmath>
#include <Vector2.hpp>

using namespace M3D;

BOOST_AUTO_TEST_SUITE(Vector2_Test_Suite)

/**
 * Ensure that the default constructor sets all components to zero.
 */
BOOST_AUTO_TEST_CASE(TestDefaultConstructor)
{
	const Vector2 v;

	BOOST_CHECK_EQUAL(v.x, 0.0f);
	BOOST_CHECK_EQUAL(v.y, 0.0f);
}

/**
 * Ensure that the constructor sets all component values to those that were
 * specified.
 */
BOOST_AUTO_TEST_CASE(TestConstructor)
{
	const float x = 1.0f;
	const float y = 2.0f;

	const Vector2 v(x, y);

	BOOST_CHECK_EQUAL(v.x, x);
	BOOST_CHECK_EQUAL(v.y, y);
}

/**
 * First test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator1)
{
	const Vector2 v1(0.0f, 0.0f);
	const Vector2 v2(0.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, true);
}

/**
 * Second test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator2)
{
	const Vector2 v1(0.0f, 0.0f);
	const Vector2 v2(1.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * Third test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator3)
{
	const Vector2 v1(0.0f, 2.0f);
	const Vector2 v2(0.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * First test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator1)
{
	const Vector2 v1(1.0f, 1.0f);
	const Vector2 v2(1.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, false);
}

/**
 * Second test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator2)
{
	const Vector2 v1(1.0f, 1.0f);
	const Vector2 v2(0.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Third test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator3)
{
	const Vector2 v1(1.0f, 1.0f);
	const Vector2 v2(1.0f, 2.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Test the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator)
{
	const Vector2 v1(2.0f, 3.0f);
	const Vector2 v2(7.0f, -9.0f);

	BOOST_CHECK_EQUAL(v1 + v2, Vector2(9.0f, -6.0f));
}

/**
 * Test the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator)
{
	const Vector2 v1(2.0f, 3.0f);
	const Vector2 v2(7.0f, -9.0f);

	BOOST_CHECK_EQUAL(v1 - v2, Vector2(-5.0f, 12.0f));
}

/**
 * Test the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator)
{
	const Vector2 v1(3.0f, -4.0f);

	BOOST_CHECK_EQUAL(-v1, Vector2(-3.0f, 4.0f));
}

/**
 * First test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator1)
{
	const Vector2 v(1.0f, -2.0f);

	BOOST_CHECK_EQUAL(v * 5, Vector2(5.0f, -10.0f));
}

/**
 * Second test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator2)
{
	const Vector2 v(-2.0f, 4.0f);

	BOOST_CHECK_EQUAL(-3.0f * v, Vector2(6.0f, -12.0f));
}

/**
 * Test the scalar division operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarDivisionOperator)
{
	const Vector2 v(3.0f, -6.0f);

	BOOST_CHECK_EQUAL(v / 3.0f, Vector2(1.0f, -2.0f));
}

/**
 * Test the sqrMagnitude function.
 */
BOOST_AUTO_TEST_CASE(TestSqrMagnitude)
{
	const Vector2 v(2.0f, 3.0f);

	BOOST_CHECK_CLOSE(v.sqrMagnitude(), 13.0f, 1e-3);
}

/**
 * Test the magnitude function.
 */
BOOST_AUTO_TEST_CASE(TestMagnitude)
{
	const Vector2 v(3.0f, 4.0f);

	BOOST_CHECK_CLOSE(v.magnitude(), 5.0f, 1e-3);
}

/**
 * Test the normalized function.
 */
BOOST_AUTO_TEST_CASE(TestNormalized)
{
	const Vector2 v(-3.0f, 4.0f);
	const Vector2 n = v.normalized();

	BOOST_CHECK_EQUAL(n, Vector2(-3.0f / 5.0f, 4.0f / 5.0f));
}

/**
 * Test the normalize function.
 */
BOOST_AUTO_TEST_CASE(TestNormalize)
{
	Vector2 v(3.0f, -4.0f);
	v.normalize();

	BOOST_CHECK_EQUAL(v, Vector2(3.0f / 5.0f, -4.0f / 5.0f));
}

/**
 * Test the scale function.
 */
BOOST_AUTO_TEST_CASE(TestScale)
{
	const Vector2 v1(2.0f, 3.0f);
	const Vector2 v2(-3.0f, 9.0f);

	BOOST_CHECK_EQUAL(scale(v1, v2), Vector2(-6.0f, 27.0f));
}

/**
 * Test the dot-product function.
 */
BOOST_AUTO_TEST_CASE(TestDotProduct)
{
	const Vector2 v1(2.0f, 4.0f);
	const Vector2 v2(1.0f, -3.0f);
	const float d = dot(v1, v2);

	BOOST_CHECK_CLOSE(d, -10.0f, 1e-3);
}

/**
 * First test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle1)
{
	Vector2 v1(1.0, 1.0);
	Vector2 v2(-1.0, -1.0);

	BOOST_CHECK_CLOSE(angle(v1, v1), 0.0f, 1e-3);
	BOOST_CHECK_CLOSE(angle(v2, v2), 0.0f, 1e-3);
}

/**
 * Second test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle2)
{
	Vector2 v1(1.0f, 0.0f);
	Vector2 v2(-1.0f, 0.0f);

	BOOST_CHECK_CLOSE(angle(v1, v2), M_PI, 1e-3);
}

/**
 * Third test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle3)
{
	Vector2 v1(1.0f, 0.0f);
	Vector2 v2(0.0f, -1.0f);

	BOOST_CHECK_CLOSE(angle(v1, v2), 0.5f * M_PI, 1e-3);
}

/**
 * Fourth test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle4)
{
	Vector2 v1(1.0f, 0.0f);
	Vector2 v2(1.0f, 1.0f);

	BOOST_CHECK_CLOSE(angle(v1, v2), 0.25f * M_PI, 1e-3);
}

/**
 * First test for the sqrDistance function.
 */
BOOST_AUTO_TEST_CASE(TestSqrDistance1)
{
	Vector2 v(3.0f, -4.0f);

	BOOST_CHECK_CLOSE(sqrDistance(v, v), 0.0f, 1e-3);
}

/**
 * Second test for the sqrDistance function.
 */
BOOST_AUTO_TEST_CASE(TestSqrDistance2)
{
	Vector2 v1(-2.0f, 3.0f);
	Vector2 v2(1.0f, 2.0f);

	BOOST_CHECK_CLOSE(sqrDistance(v1, v2), 10.0f, 1e-3);
}

/**
 * First test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance1)
{
	Vector2 v(3.0f, -4.0f);

	BOOST_CHECK_CLOSE(distance(v, v), 0.0f, 1e-3);
}

/**
 * Second test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance2)
{
	Vector2 v1(0.0f, 0.0f);
	Vector2 v2(3.0f, 4.0f);

	BOOST_CHECK_CLOSE(distance(v1, v2), 5.0f, 1e-3);
}

/**
 * Third test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance3)
{
	Vector2 v1(4.0f, 9.0f);
	Vector2 v2(1.0f, 2.0f);

	BOOST_CHECK_CLOSE(distance(v1, v2), std::sqrt(58.0f), 1e-3);
}

BOOST_AUTO_TEST_SUITE_END()
