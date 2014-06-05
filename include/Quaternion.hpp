#ifndef QUATERNION_HPP
#define QUATERNION_HPP

#include <iostream>

#include <Vector3.hpp>

namespace M3D
{
	class Quaternion
	{
	public:
		/**
		 * Default constructor.
		 *
		 * Constructs the identity quaternion, corresponding to no rotation.
		 * This quaternion has real (scalar) part equal to 1 and vector part
		 * equal to the zero vector.
		 */
		Quaternion();

		/**
		 * Constructor.
		 *
		 * Constructs a quaternion from the specified components.
		 *
		 * @param w_ The real (scalar) component.
		 * @param x_ The x-component of the vector part.
		 * @param y_ The y-component of the vector part.
		 * @param z_ The z-component of the vector part.
		 */
		Quaternion(float w_, float x_, float y_, float z_);

		/**
		 * Constructor.
		 *
		 * Constructs a quaternion from the specified scalar and vector parts.
		 *
		 * @param s Scalar (real) part.
		 * @param v Vector part.
		 */
		Quaternion(const float s, const Vector3& v);

		/**
		 * Equality operator.
		 *
		 * @param q1 The first quaternion.
		 * @param q2 The second quaternion.
		 * @return True if the two supplied quaternions are equal. False
		 * otherwise.
		 */
		friend float operator==(const Quaternion& q1, const Quaternion& q2);

		/**
		 * Non-equality operator.
		 *
		 * @param q1 The first quaternion.
		 * @param q2 The second quaternion.
		 * @return True if the two supplied quaternions are not equal. False
		 * otherwise.
		 */
		friend float operator!=(const Quaternion& q1, const Quaternion& q2);

		/**
		 * Hamilton product. Combines the `lhs` and `rhs` rotations.
		 *
		 * Quaternion multiplication is not commutative, so the order of the
		 * operands is important. The result of `lhs` * `rhs` is the rotation
		 * obtained by first rotating by `rhs` and then by `lhs`. You can think
		 * of this as applying the `lhs` rotation to the `rhs` rotation.
		 *
		 * @param lhs The left hand side quaternion.
		 * @param rhs The right hand side quaternion.
		 * @return Returns the product of the two quaternions.
		 */
		friend Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);

		/**
		 * Rotates the vector `v` by applying the quaternion rotation `q`.
		 *
		 * @param q The quaternion rotation to apply to the vector.
		 * @param v The vector to be rotated.
		 * @return The vector `v` rotated by `q`.
		 */
		friend Vector3 operator*(const Quaternion& q, const Vector3& v);

		/**
		 * Stream output operator.
		 *
		 * @param out Output stream.
		 * @param q Quaternion to output.
		 * @return Output stream.
		 */
		friend std::ostream& operator <<(std::ostream& out, const Quaternion& q);

		/**
		 * Returns the squared magnitude of the quaternion.
		 *
		 * @return Squared magnitude of the quaternion.
		 */
		float sqrMagnitude() const;

		/**
		 * Returns the magnitude of the quaternion.
		 *
		 * @return Magnitude of the quaternion.
		 */
		float magnitude() const;

		/**
		 * Returns a copy of this quaternion representing the same rotation but
		 * with magnitude equal to 1.
		 *
		 * @return This quaternion normalized.
		 */
		Quaternion normalized() const;

		/**
		 * Normalizes the quaternion so that it represents the same rotation,
		 * but has magnitude equal to 1.
		 */
		void normalize();

		/**
		 * Rotates this unit quaternion towards the specified `target` unit
		 * quaternion by an angular step of `maxRadiansDelta` (without
		 * overshoot).
		 *
		 * @param target Target unit quaternion rotation.
		 * @param maxRadiansDelta Maximum number of radians to rotate.
		 */
		void rotateTowards(const Quaternion& target, float maxRadiansDelta);

		/**
		 * Returns a unit quaternion corresponding to the rotation around the
		 * specified unit vector `axis` by the specified `angle`.
		 *
		 * @note The axis supplied must be a unit vector.
		 *
		 * @param angle Angle in radians.
		 * @param axis Axis for the rotation.
		 * @return Unit quaternion corresponding to the angle-axis rotation
		 * provided.
		 */
		static Quaternion angleAxis(const float angle, const Vector3& axis);

		/**
		 * Returns a unit quaternion corresponding to the rotation of z radians
		 * about the z-axis, y radians about the y-axis and x radians about the
		 * x-axis (in that order).
		 *
		 * @param eulerAngles The euler angles for the rotation.
		 * @return Unit quaternion corresponding to the rotation specified by
		 * the supplied euler angles.
		 */
		static Quaternion euler(const Vector3& eulerAngles);

		/**
		 * Returns a unit quaternion that represents the sortest rotation from
		 * the `fromDirection` to the `toDirection`.
		 *
		 * @param fromDirection Direction for the quaternion to rotate from.
		 * @param toDirection Direction for the quaternion to rotate to.
		 * @return Unit quaternion corresponding to the rotation from
		 * `fromDirection` to `toDirection`.
		 */
		static Quaternion fromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

		/**
		 * Returns a unit quaternion that rotates to look in the specified
		 * `forward` direction.
		 *
		 * @note The quaternion returned represents the shortest possible
		 * rotation and will probably not preserve the upward direction. This
		 * function is less expensive than the identically named function that
		 * preserves the upward direction. You should use this method when you
		 * don't care about the resulting upwards direction.
		 *
		 * @param forward The direction to look in.
		 * @return Unit quaternion representing the rotation that looks in
		 * the `forward` direction.
		 */
		static Quaternion lookRotation(const Vector3& forward);

		/**
		 * Returns a unit quaternion that rotates to look in the specified
		 * `forward` direction with the specified `upwards` direction.
		 *
		 * @param forward The direction to look in.
		 * @param upwards The vector that defines which direction is up.
		 * @return Unit quaternion representing the rotation that looks in
		 * the `forward` direction.
		 */
		static Quaternion lookRotation(const Vector3& forward, const Vector3& upwards);

		/**
		 * Returns a copy of the conjugate of this quaternion.
		 *
		 * @return Conjugate of the quaternion.
		 */
		Quaternion conjugate() const;

		/**
		 * Returns a copy of the multiplicitive inverse of this quaternion.
		 *
		 * @note The inverse of a unit quaternion is exactly equal to the
		 * conjugate. The conjugate is less expensive to compute and so should
		 * be preferred when working with unit quaternions.
		 *
		 * @return Multiplicitive inverse of this quaternion.
		 */
		Quaternion inverse() const;

	public:
		/**
		 * The real (scalar) component.
		 */
		float w;

		/**
		 * The x-component of the vector part.
		 */
		float x;

		/**
		 * The y-component of the vector part.
		 */
		float y;

		/**
		 * The z-component of the vector part.
		 */
		float z;

	public:
		/**
		 * Quaternion representing the zero rotation.
		 */
		static const Quaternion IDENTITY;
	};

	/**
	 * Returns the dot (scalar) product of two quaternions.
	 *
	 * The dot product is commutative.
	 *
	 * @param lhs The left hand side quaternion.
	 * @param rhs The right hand side quaternion.
	 * @return Dot product of the two quaternions.
	 */
	float dot(const Quaternion& lhs, const Quaternion& rhs);

	/**
	 * Returns the angle (in radians) between the two unit quaternion rotations
	 * supplied.
	 *
	 * @param from The unit quaternion that the angle should be measured from.
	 * @param to The unit quaternion that the angle should be measured to.
	 * @return Angle (radians) between the two rotations.
	 */
	float angle(const Quaternion& from, const Quaternion& to);
}

#endif
