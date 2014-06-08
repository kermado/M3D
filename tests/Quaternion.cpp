#include <boost/test/unit_test.hpp>
#include <cmath>
#include <Quaternion.hpp>

using namespace M3D;

BOOST_AUTO_TEST_SUITE(Quaternion_Test_Suite)

/**
 * Test that the default constructor constructs the identity quaternion.
 */
BOOST_AUTO_TEST_CASE(TestDefaultConstructor)
{
	const Quaternion q;

	BOOST_CHECK_EQUAL(q.w, 1.0f);
	BOOST_CHECK_EQUAL(q.x, 0.0f);
	BOOST_CHECK_EQUAL(q.y, 0.0f);
	BOOST_CHECK_EQUAL(q.z, 0.0f);
}

/**
 * Test that the component constructor sets all component values to those that
 * were specified.
 */
BOOST_AUTO_TEST_CASE(TestComponentConstructor)
{
	const Quaternion q(2.0f, 5.0f, -2.5f, 0.0f);

	BOOST_CHECK_EQUAL(q.w, 2.0f);
	BOOST_CHECK_EQUAL(q.x, 5.0f);
	BOOST_CHECK_EQUAL(q.y, -2.5f);
	BOOST_CHECK_EQUAL(q.z, 0.0f);
}

/**
 * Test that the scalar-vector constructor sets all component values according
 * to the scalar and vector parts provided.
 */
BOOST_AUTO_TEST_CASE(TestScalarVectorConstructor)
{
	const Quaternion q(0.5f, Vector3(0.1f, 0.2f, -0.3f));

	BOOST_CHECK_EQUAL(q.w, 0.5f);
	BOOST_CHECK_EQUAL(q.x, 0.1f);
	BOOST_CHECK_EQUAL(q.y, 0.2f);
	BOOST_CHECK_EQUAL(q.z, -0.3f);
}

/**
 * First test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator1)
{
	const Quaternion q(0.0f, 0.0f, 0.0f, 0.0f);

	BOOST_CHECK_EQUAL(q == q, true);
}

/**
 * Second test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator2)
{
	const Quaternion q1(1.0f, 2.0f, 3.0f, -4.0f);
	const Quaternion q2(1.0f, 2.0f, 3.0f, -4.0f);

	BOOST_CHECK_EQUAL(q1 == q2, true);
}

/**
 * Third test for the equality operator.
 */
BOOST_AUTO_TEST_CASE(TestEqualityOperator3)
{
	const Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
	const Quaternion q2(2.0f, 2.0f, 3.0f, 4.0f);

	BOOST_CHECK_EQUAL(q1 == q2, false);
}

/**
 * First test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator1)
{
	const Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
	const Quaternion q2(1.0f, 2.0f, 3.0f, -4.0f);

	BOOST_CHECK_EQUAL(q1 != q2, true);
}

/**
 * Second test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator2)
{
	const Quaternion q1(0.0f, 0.0f, 0.0f, 0.0f);
	const Quaternion q2(1.0f, 0.0f, 0.0f, 0.0f);

	BOOST_CHECK_EQUAL(q1 != q2, true);
}

/**
 * Third test for the non-equality operator.
 */
BOOST_AUTO_TEST_CASE(TestNonEqualityOperator3)
{
	const Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
	const Quaternion q2(1.0f, 2.0f, 3.0f, 4.0f);

	BOOST_CHECK_EQUAL(q1 != q2, false);
}

/**
 * First test for the the multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMultiplicationOperator1)
{
	const Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
	const Quaternion q2; // Identity

	BOOST_CHECK_EQUAL(q2 * q1, q1);
}

/**
 * Second test for the the multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMultiplicationOperator2)
{
	const Quaternion q1(1.0f, 1.0f, 1.0f, 1.0f);
	const Quaternion q2(1.0f, 1.0f, 1.0f, 1.0f);

	BOOST_CHECK_EQUAL(q1 * q2, Quaternion(-2.0f, 2.0f, 2.0f, 2.0f));
}

/**
 * Third test for the the multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMultiplicationOperator3)
{
	const Quaternion q1(1.0f, 0.0f, 1.0f, 0.0f);
	const Quaternion q2(1.0f, 0.5f, 0.5f, 0.75f);

	BOOST_CHECK_EQUAL(q1 * q2, Quaternion(0.5f, 1.25f, 1.5f, 0.25f));
}

/**
 * Fourth test for the the multiplication operator.
 */
BOOST_AUTO_TEST_CASE(TestMultiplicationOperator4)
{
	const Quaternion q1(2.0f, 3.0f, 2.0f, 3.0f);
	const Quaternion q2(3.0f, 2.0f, 3.0f, 2.0f);

	BOOST_CHECK_EQUAL(q1 * q2, Quaternion(-12.0f, 8.0f, 12.0f, 18.0f));
}

/**
 * Test for the sqrMagnitude function.
 */
BOOST_AUTO_TEST_CASE(TestSqrMagnitude)
{
	const Quaternion q(1.0f, -2.0f, 3.0f, 4.0f);

	BOOST_CHECK_CLOSE(q.sqrMagnitude(), 30.0f, 1e-3);
}

/**
 * Test for the magnitude function.
 */
BOOST_AUTO_TEST_CASE(TestMagnitude)
{
	const Quaternion q(3.0f, -3.0f, 3.0f, -3.0f);

	BOOST_CHECK_CLOSE(q.magnitude(), 6.0f, 1e-3);
}

/**
 * Test for the normalized function.
 */
BOOST_AUTO_TEST_CASE(TestNormalized)
{
	const Quaternion q(3.0f, 3.0f, 3.0f, -3.0f);

	BOOST_CHECK_EQUAL(q.normalized(), Quaternion(0.5f, 0.5f, 0.5f, -0.5f));
}

/**
 * Test for the normalize function.
 */
BOOST_AUTO_TEST_CASE(TestNormalize)
{
	Quaternion q(25.0f, 0.0f, 0.0f, 0.0f);
	q.normalize();

	BOOST_CHECK_EQUAL(q, Quaternion(1.0f, 0.0f, 0.0f, 0.0f));
}

/**
 * Test for the angle axis static factory function.
 */
BOOST_AUTO_TEST_CASE(TestAngleAxisFactory)
{
	const float angle = 0.5f * M_PI;
	const Vector3 axis(1.0f, 0.0f, 0.0f);
	const Quaternion q = Quaternion::angleAxis(angle, axis);

	BOOST_CHECK_EQUAL(q, Quaternion(0.707107f, 0.707107f, 0.0f, 0.0f));
}

/**
 * Test for the euler angle static factory function.
 */
BOOST_AUTO_TEST_CASE(TestEulerAngleFactory)
{
	const Vector3 eulerAngles(0.5f * M_PI, 0.25f * M_PI, 0.25f * M_PI);
	const Quaternion q = Quaternion::euler(eulerAngles);

	BOOST_CHECK_EQUAL(q, Quaternion(0.5f, 0.707107f, 0.0f, 0.5f));
}

/**
 * Test for the conjugate function.
 */
BOOST_AUTO_TEST_CASE(TestConjugate)
{
	const Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);

	BOOST_CHECK_EQUAL(q.conjugate(), Quaternion(1.0f, -2.0f, -3.0f, -4.0f));
}

/**
 * First test for the dot-product function.
 */
BOOST_AUTO_TEST_CASE(TestDotProduct1)
{
	const Quaternion q(1.0f, 2.0f, 3.0f, 4.0f);

	BOOST_CHECK_EQUAL(q.conjugate(), Quaternion(1.0f, -2.0f, -3.0f, -4.0f));
}

/**
 * Second test for the dot-product function.
 */
BOOST_AUTO_TEST_CASE(TestDotProduct2)
{
	const Quaternion q(0.5f, 0.0f, -0.25f, 0.5f);

	BOOST_CHECK_EQUAL(q.conjugate(), Quaternion(0.5f, 0.0f, 0.25f, -0.5f));
}

/**
 * Ensure that the hamilton product of a quaternion with its conjugate is equal
 * to the dot product of that quaternion with itself.
 */
BOOST_AUTO_TEST_CASE(TestDotProduct3)
{
	const Quaternion q(1.0f, 0.5f, 0.25f, 0.125f);
	const Quaternion qMult = q * q.conjugate();
	const float qDot = dot(q, q);

	BOOST_CHECK_EQUAL(qMult, Quaternion(qDot, 0.0f, 0.0f, 0.0f));
}

/**
 * Test for the inverse function.
 * Ensure that the hamilton product of a quaternion with its inverse is equal
 * to the identity.
 */
BOOST_AUTO_TEST_CASE(TestInverse)
{
	const Quaternion q1(1.0f, 2.0f, 3.0f, 4.0f);
	const Quaternion q2 = q1.inverse();

	BOOST_CHECK_EQUAL(q1 * q2, Quaternion::IDENTITY);
	BOOST_CHECK_EQUAL(q2 * q1, Quaternion::IDENTITY);
}

/**
 * First test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle1)
{
	const Quaternion q = Quaternion::IDENTITY;
	BOOST_CHECK_CLOSE(angle(q, q), 0.0f, 1e-3);
}

/**
 * Second test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle2)
{
	Quaternion q(0.5f, 0.25f, 0.25f, 0.5f);
	q.normalize();
	BOOST_CHECK_CLOSE(angle(q, q), 0.0f, 1e-3);
}

/**
 * Third test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle3)
{
	const float rad = 0.5f * M_PI;
	const Quaternion q = Quaternion::angleAxis(rad, Vector3::FORWARD);
	BOOST_CHECK_CLOSE(angle(Quaternion::IDENTITY, q), rad, 1e-3);
}

/**
 * Fourth test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle4)
{
	const float rad = M_PI;
	const Quaternion q = Quaternion::angleAxis(rad, Vector3::UP);
	BOOST_CHECK_CLOSE(angle(Quaternion::IDENTITY, q), rad, 1e-3);
}

/**
 * Fifth test for the angle function.
 */
BOOST_AUTO_TEST_CASE(TestAngle5)
{
	const float rad = M_PI;
	const Quaternion q = Quaternion::euler(Vector3(rad, 0.0f, rad));
	BOOST_CHECK_CLOSE(angle(Quaternion::IDENTITY, q), rad, 1e-3);
}

/**
 * First test for the the vector-quaternion multiplication operator.
 *
 * Applying the identity quaternion rotation to a vector should product the
 * original vector.
 */
BOOST_AUTO_TEST_CASE(TestVectorQuaternionMultiplicationOperator1)
{
	BOOST_CHECK_EQUAL(Quaternion::IDENTITY * Vector3::ONE, Vector3::ONE);
}


/**
 * Second test for the the vector-quaternion multiplication operator.
 *
 * Rotating the RIGHT vector PI/2 radians about the y-axis should produce the
 * BACK vector.
 */
BOOST_AUTO_TEST_CASE(TestVectorQuaternionMultiplicationOperator2)
{
	const Quaternion q = Quaternion::angleAxis(0.5f * M_PI, Vector3::UP);

	BOOST_CHECK_EQUAL(q * Vector3::RIGHT, Vector3::BACK);
}

/**
 * Third test for the the vector-quaternion multiplication operator.
 *
 * Rotating the FORWARD vector 3PI/2 radians about the x-axis should produce the
 * UP vector.
 *
 */
BOOST_AUTO_TEST_CASE(TestVectorQuaternionMultiplicationOperator3)
{
	const Quaternion q = Quaternion::angleAxis(3.0f * M_PI / 2.0f, Vector3::RIGHT);

	BOOST_CHECK_EQUAL(q * Vector3::FORWARD, Vector3::UP);
}

/**
 * First test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation1)
{
	const Quaternion q = Quaternion::fromToRotation(Vector3::FORWARD, Vector3::FORWARD);
	BOOST_CHECK_EQUAL(q * Vector3::FORWARD, Vector3::FORWARD);
}

/**
 * Second test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation2)
{
	const Quaternion q = Quaternion::fromToRotation(Vector3::UP, Vector3::LEFT);
	BOOST_CHECK_EQUAL(q * Vector3::UP, Vector3::LEFT);
}

/**
 * Third test for the fromToRotation static factory function.
 */
BOOST_AUTO_TEST_CASE(TestFromToRotation3)
{
	const Quaternion q = Quaternion::fromToRotation(Vector3::LEFT, Vector3::RIGHT);
	BOOST_CHECK_EQUAL(q * Vector3::LEFT, Vector3::RIGHT);
}

/**
 * First test for the lookRotation static factory function.
 *
 * The quaternion returned should rotate Vector3::FORWARD to point in the
 * specified direction without nececessarily preserving the upwards direction.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation1)
{
	const Quaternion q = Quaternion::lookRotation(Vector3::RIGHT);
	BOOST_CHECK_EQUAL(q * Vector3::FORWARD, Vector3::RIGHT);
}

/**
 * Second test for the lookRotation static factory function.
 *
 * The quaternion returned should rotate Vector3::FORWARD to point in the
 * specified direction without nececessarily preserving the upwards direction.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation2)
{
	const Quaternion q = Quaternion::lookRotation(Vector3::BACK);
	BOOST_CHECK_EQUAL(q * Vector3::FORWARD, Vector3::BACK);
}

/**
 * Third test for the lookRotation static factory function.
 *
 * The quaternion returned should rotate Vector3::FORWARD to point in the
 * specified direction without nececessarily preserving the upwards direction.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation3)
{
	const Quaternion q = Quaternion::lookRotation(Vector3::FORWARD);
	BOOST_CHECK_EQUAL(q * Vector3::FORWARD, Vector3::FORWARD);
}

/**
 * Fourth test for the lookRotation static factory function.
 *
 * The quaternion returned should rotate Vector3::FORWARD to point in the
 * specified direction whilst preserving the upwards direction when the upwards
 * vector is supplied.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation4)
{
	// We don't expect the UP direction to be preserved when not specifying
	// an upward direction.
	const Quaternion q1 = Quaternion::lookRotation(Vector3::ONE);
	BOOST_CHECK(q1 * Vector3::UP != Vector3::UP);

	// We do expect the UP direction to be preserved When supplying an upwards
	// direction to the lookRotation static factory function.
	const Quaternion q2 = Quaternion::lookRotation(Vector3::ONE, Vector3::UP);
	BOOST_CHECK(q2 * Vector3::UP == Vector3::UP);
}

/**
 * Fifth test for the lookRotation static factory function.
 *
 * This test checks that we don't suffer from gimbal lock. We should be able to
 * construct a quaternion that looks in the up or down directions.
 */
BOOST_AUTO_TEST_CASE(TestLookRotation5)
{
	// Quaternion that rotates the forward vector to look in the down direction.
	const Quaternion q1 = Quaternion::lookRotation(Vector3::DOWN, Vector3::UP);

	// Rotating the forward vector should produce the down vector.
	BOOST_CHECK(q1 * Vector3::FORWARD == Vector3::DOWN);

	// Rotating the up vector should produce the forward vector.
	BOOST_CHECK(q1 * Vector3::UP == Vector3::FORWARD);

	// Quaternion that rotates the forward vector to look in the up direction.
	const Quaternion q2 = Quaternion::lookRotation(Vector3::UP, Vector3::UP);

	// Rotating the forward vector should produce the up vector.
	BOOST_CHECK(q2 * Vector3::FORWARD == Vector3::UP);

	// Rotating the up vector should produce the back vector.
	BOOST_CHECK(q2 * Vector3::UP == Vector3::BACK);
}

/**
 * First test for the rotateTowards function.
 */
BOOST_AUTO_TEST_CASE(TestRotateTowards1)
{
	Quaternion from = Quaternion::IDENTITY;
	const Quaternion to = Quaternion::angleAxis(M_PI, Vector3::RIGHT);
	from.rotateTowards(to, 0.5f * M_PI);
	BOOST_CHECK_EQUAL(from, Quaternion::angleAxis(0.5f * M_PI, Vector3::RIGHT));
}

/**
 * Second test for the rotateTowards function.
 */
BOOST_AUTO_TEST_CASE(TestRotateTowards2)
{
	Quaternion from = Quaternion::lookRotation(Vector3::RIGHT, Vector3::UP);
	const Quaternion to = Quaternion::lookRotation(Vector3::LEFT, Vector3::UP);
	from.rotateTowards(to, 0.5f * M_PI);
	BOOST_CHECK_EQUAL(from, Quaternion::lookRotation(Vector3::FORWARD, Vector3::UP));
}

/**
 * Third test for the rotateTowards function.
 */
BOOST_AUTO_TEST_CASE(TestRotateTowards3)
{
	Quaternion from = Quaternion::IDENTITY;
	const Quaternion to = Quaternion::lookRotation(Vector3::BACK, Vector3::UP);
	from.rotateTowards(to, 2.0f * M_PI);
	BOOST_CHECK_EQUAL(from, Quaternion::lookRotation(Vector3::BACK, Vector3::UP));
}

BOOST_AUTO_TEST_SUITE_END()
