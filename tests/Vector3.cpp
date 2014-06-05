#include <boost/test/unit_test.hpp>
#include <cmath>
#include <Vector3.hpp>

using namespace M3D;


BOOST_AUTO_TEST_SUITE(Vector3_Test_Suite)

/**
 * Ensure that the default constructor sets all components to zero.
 */
BOOST_AUTO_TEST_CASE(TestDefaultConstructor)
{
	const Vector3 v;

	BOOST_CHECK_EQUAL(v.x, 0.0f);
	BOOST_CHECK_EQUAL(v.y, 0.0f);
	BOOST_CHECK_EQUAL(v.z, 0.0f);
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

	const Vector3 v(x, y, z);

	BOOST_CHECK_EQUAL(v.x, x);
	BOOST_CHECK_EQUAL(v.y, y);
	BOOST_CHECK_EQUAL(v.z, z);
}

/**
 * First test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator1)
{
	const Vector3 v1(0.0f, 0.0f, 0.0f);
	const Vector3 v2(0.0f, 0.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, true);
}

/**
 * Second test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator2)
{
	const Vector3 v1(0.0f, 0.0f, 0.0f);
	const Vector3 v2(1.0f, 0.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * Third test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator3)
{
	const Vector3 v1(0.0f, 2.0f, 0.0f);
	const Vector3 v2(0.0f, 0.0f, 0.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * Fourth test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator4)
{
	const Vector3 v1(0.0f, 0.0f, 0.0f);
	const Vector3 v2(0.0f, 0.0f, 4.0f);

	BOOST_CHECK_EQUAL(v1 == v2, false);
}

/**
 * First test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator1)
{
	const Vector3 v1(1.0f, 1.0f, 1.0f);
	const Vector3 v2(1.0f, 1.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, false);
}

/**
 * Second test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator2)
{
	const Vector3 v1(1.0f, 1.0f, 1.0f);
	const Vector3 v2(0.0f, 1.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Third test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator3)
{
	const Vector3 v1(1.0f, 1.0f, 1.0f);
	const Vector3 v2(1.0f, 2.0f, 1.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Fourth test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator4)
{
	const Vector3 v1(1.0f, 1.0f, 1.0f);
	const Vector3 v2(1.0f, 1.0f, -3.0f);

	BOOST_CHECK_EQUAL(v1 != v2, true);
}

/**
 * Test the addition operator.
 */
BOOST_AUTO_TEST_CASE(TestAdditionOperator)
{
	const Vector3 v1(2.0f, 3.0f, 5.0f);
	const Vector3 v2(7.0f, -9.0f, 11.0f);

	BOOST_CHECK_EQUAL(v1 + v2, Vector3(9.0f, -6.0f, 16.0f));
}

/**
 * Test the subtraction operator.
 */
BOOST_AUTO_TEST_CASE(TestSubtractionOperator)
{
	const Vector3 v1(2.0f, 3.0f, 5.0f);
	const Vector3 v2(7.0f, -9.0f, 11.0f);

	BOOST_CHECK_EQUAL(v1 - v2, Vector3(-5.0f, 12.0f, -6.0f));
}

/**
 * Test the unary negation operator.
 */
BOOST_AUTO_TEST_CASE(TestNegationOperator)
{
	const Vector3 v1(0.0f, 1.0f, -2.0f);

	BOOST_CHECK_EQUAL(-v1, Vector3(0.0f, -1.0f, 2.0f));
}

/**
 * First test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator1)
{
	const Vector3 v(1.0f, -2.0f, 0.0f);

	BOOST_CHECK_EQUAL(v * 5, Vector3(5.0f, -10.0f, 0.0f));
}

/**
 * Second test for the scalar multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarMultiplicationOperator2)
{
	const Vector3 v(-2.0f, 4.0f, 6.0f);

	BOOST_CHECK_EQUAL(-3.0f * v, Vector3(6.0f, -12.0f, -18.0f));
}

/**
 * Test the scalar division operator.
 */
BOOST_AUTO_TEST_CASE(TestScalarDivisionOperator)
{
	const Vector3 v(3.0f, 6.0f, -9.0f);

	BOOST_CHECK_EQUAL(v / 3.0f, Vector3(1.0f, 2.0f, -3.0f));
}

/**
 * Test the sqrMagnitude function.
 */
BOOST_AUTO_TEST_CASE(TestSqrMagnitude)
{
	const Vector3 v(2.0f, 3.0f, 5.0f);

	BOOST_CHECK_CLOSE(v.sqrMagnitude(), 38.0f, 1e-3);
}

/**
 * Test the magnitude function.
 */
BOOST_AUTO_TEST_CASE(TestMagnitude)
{
	const Vector3 v(2.0f, 4.0f, 4.0f);

	BOOST_CHECK_CLOSE(v.magnitude(), 6.0f, 1e-3);
}

/**
 * Test the normalized function.
 */
BOOST_AUTO_TEST_CASE(TestNormalized)
{
	const Vector3 v(-4.0f, 0.0f, 3.0f);
	const Vector3 n = v.normalized();

	BOOST_CHECK_EQUAL(n, Vector3(-0.8f, 0.0f, 0.6f));
}

/**
 * Test the normalize function.
 */
BOOST_AUTO_TEST_CASE(TestNormalize)
{
	Vector3 v(4.0f, 0.0f, -3.0f);
	v.normalize();

	BOOST_CHECK_EQUAL(v, Vector3(0.8f, 0.0f, -0.6f));
}

/**
 * Test the scale function.
 */
BOOST_AUTO_TEST_CASE(TestScale)
{
	const Vector3 v1(2.0f, 3.0f, 4.0f);
	const Vector3 v2(-3.0f, 9.0f, 0.5f);

	BOOST_CHECK_EQUAL(scale(v1, v2), Vector3(-6.0f, 27.0f, 2.0f));
}

/**
 * Test the dot-product function.
 */
BOOST_AUTO_TEST_CASE(TestDotProduct)
{
	const Vector3 v1(2.0f, 4.0f, -1.0f);
	const Vector3 v2(1.0f, -3.0f, 5.0f);
	const float d = dot(v1, v2);

	BOOST_CHECK_CLOSE(d, -15.0f, 1e-3);
}

/**
 * First test for the the cross-product function.
 */
BOOST_AUTO_TEST_CASE(TestCrossProduct1)
{
	const Vector3 v1(1.0f, 1.0f, 1.0f);
	const Vector3 v2(1.0f, 1.0f, 1.0f);
	const Vector3 c = cross(v1, v2);

	BOOST_CHECK_EQUAL(c, Vector3(0.0f, 0.0f, 0.0f));
}

/**
 * Second test for the the cross-product function.
 */
BOOST_AUTO_TEST_CASE(TestCrossProduct2)
{
	const Vector3 v1(1.0f, 1.0f, 1.0f);
	const Vector3 v2(2.0f, 2.0f, 2.0f);
	const Vector3 c = cross(v1, v2);

	BOOST_CHECK_EQUAL(c, Vector3(0.0f, 0.0f, 0.0f));
}

/**
 * Third test for the the cross-product function.
 */
BOOST_AUTO_TEST_CASE(TestCrossProduct3)
{
	const Vector3 v1(2.0f, 3.0f, 4.0f);
	const Vector3 v2(-2.0f, -3.0f, -4.0f);
	const Vector3 c = cross(v1, v2);

	BOOST_CHECK_EQUAL(c, Vector3(0.0f, 0.0f, 0.0f));
}

/**
 * Fourth test for the the cross-product function.
 */
BOOST_AUTO_TEST_CASE(TestCrossProduct4)
{
	const Vector3 v1(1.0f, 0.0f, 0.0f);
	const Vector3 v2(0.0f, 1.0f, 0.0f);
	const Vector3 c = cross(v1, v2);

	BOOST_CHECK_EQUAL(c, Vector3(0.0f, 0.0f, 1.0f));
}

/**
 * First test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle1)
{
	Vector3 v1(1.0, 1.0, 1.0);
	Vector3 v2(-1.0, -1.0, -1.0);

	BOOST_CHECK_CLOSE(angle(v1, v1), 0.0f, 1e-3);
	BOOST_CHECK_CLOSE(angle(v2, v2), 0.0f, 1e-3);
}

/**
 * Second test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle2)
{
	Vector3 v1(1.0f, 0.0f, 0.0f);
	Vector3 v2(-1.0f, 0.0f, 0.0f);

	BOOST_CHECK_CLOSE(angle(v1, v2), M_PI, 1e-3);
}

/**
 * Third test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle3)
{
	Vector3 v1(1.0f, 0.0f, 0.0f);
	Vector3 v2(0.0f, -1.0f, 0.0f);

	BOOST_CHECK_CLOSE(angle(v1, v2), 0.5f * M_PI, 1e-3);
}

/**
 * Fourth test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle4)
{
	Vector3 v1(1.0f, 0.0f, 0.0f);
	Vector3 v2(1.0f, 1.0f, 0.0f);

	BOOST_CHECK_CLOSE(angle(v1, v2), 0.25f * M_PI, 1e-3);
}

/**
 * First test for the sqrDistance function.
 */
BOOST_AUTO_TEST_CASE(TestSqrDistance1)
{
	Vector3 v(2.0f, -3.0f, 5.0f);

	BOOST_CHECK_CLOSE(sqrDistance(v, v), 0.0f, 1e-3);
}

/**
 * Second test for the sqrDistance function.
 */
BOOST_AUTO_TEST_CASE(TestSqrDistance2)
{
	Vector3 v1(-2.0f, 3.0f, -5.0);
	Vector3 v2(1.0f, 2.0f, 3.0f);

	BOOST_CHECK_CLOSE(sqrDistance(v1, v2), 74.0f, 1e-3);
}

/**
 * First test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance1)
{
	Vector3 v(1.0f, 2.0f, 3.0f);

	BOOST_CHECK_CLOSE(distance(v, v), 0.0f, 1e-3);
}

/**
 * Second test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance2)
{
	Vector3 v1(0.0f, 0.0f, 0.0f);
	Vector3 v2(4.0f, 2.0f, 4.0f);

	BOOST_CHECK_CLOSE(distance(v1, v2), 6.0f, 1e-3);
}

/**
 * Third test for the distance function.
 */
BOOST_AUTO_TEST_CASE(TestDistance3)
{
	Vector3 v1(0.0f, 0.0f, -10.0f);
	Vector3 v2(0.0f, 0.0f, 1.0f);

	BOOST_CHECK_CLOSE(distance(v1, v2), 11.0f, 1e-3);
}

BOOST_AUTO_TEST_SUITE_END()
