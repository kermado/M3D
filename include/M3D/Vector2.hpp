#ifndef VECTOR2_HPP
#define VECTOR2_HPP

#include <ostream>

namespace M3D
{
	class Vector2
	{
	public:
		/**
		 * Default constructor.
		 *
		 * Constructs the zero vector.
		 */
		Vector2();

		/**
		 * Constructor.
		 *
		 * @param x_ The first component.
		 * @param y_ The second component.
		 */
		Vector2(float x_, float y_);

		/**
		 * Vector equality operator.
		 *
		 * @param v1 The first vector.
		 * @param v2 The second vector.
		 * @return True if the two supplied vectors are equal. False otherwise.
		 */
		friend float operator==(const Vector2& v1, const Vector2& v2);

		/**
		 * Vector non-equality operator.
		 *
		 * @param v1 The first vector.
		 * @param v2 The second vector.
		 * @return True if the two supplied vectors are not equal. False
		 * otherwise.
		 */
		friend float operator!=(const Vector2& v1, const Vector2& v2);

		/**
		 * Vector addition operator.
		 *
		 * @param v1 First vector.
		 * @param v2 Second vector.
		 * @return Result of adding the first vector to the second vector.
		 */
		friend Vector2 operator+(const Vector2& v1, const Vector2& v2);

		/**
		 * Vector subtraction operator.
		 *
		 * @param v1 The first vector.
		 * @param v2 The second vector.
		 * @return Result of subtracting the second vector from the first
		 * vector.
		 */
		friend Vector2 operator-(const Vector2& v1, const Vector2& v2);

		/**
		 * Vector negation operator.
		 *
		 * @param v The vector to negate.
		 * @return The additive inverse of the vector `v`.
		 */
		friend Vector2 operator-(const Vector2 &v);

		/**
		 * Scalar multiplication operator.
		 *
		 * @param v The vector.
		 * @param s The scalar value.
		 * @return Vector `v` scaled by `s`.
		 */
		friend Vector2 operator*(const Vector2& v, const float s);

		/**
		 * Scalar multiplication operator.
		 *
		 * @param s The scalar value.
		 * @param v The vector.
		 * @return Vector `v` scaled by `s`.
		 */
		friend Vector2 operator*(const float s, const Vector2& v);

		/**
		 * Scalar division operator.
		 *
		 * @param v The vector.
		 * @param s The scalar value.
		 * @return Vector `v` scaled by the reciprocal of `s`.
		 */
		friend Vector2 operator/(const Vector2& v, const float s);

		/**
		 * Stream output operator.
		 *
		 * @param out Output stream.
		 * @param v Vector to output.
		 * @return Output stream.
		 */
		friend std::ostream& operator <<(std::ostream& out, const Vector2& v);

		/**
		 * Returns the squared length of the vector.
		 *
		 * @return Squared length of the vector.
		 */
		float sqrMagnitude() const;

		/**
		 * Returns the length of the vector.
		 *
		 * @note You can usually use @see sqrMagnitude, which is faster to
		 * compute. Use this function only if you need the actual length.
		 *
		 * @return Length of the vector.
		 */
		float magnitude() const;

		/**
		 * Returns a copy of this vector that points in the same direction, but
		 * with a magnitude of 1.
		 *
		 * @return This vector with a magnitude of 1.
		 */
		Vector2 normalized() const;

		/**
		 * Normalizes the vector so that it points in the same direction but
		 * with a magnitude of 1.
		 */
		void normalize();

	public:
		/**
		 * First component.
		 */
		float x;

		/**
		 * Second component.
		 */
		float y;

	public:
		/**
		 * Vector representing the up direction.
		 * This is shorthand for writing Vector2(0.0f, 1.0f).
		 */
		static const Vector2 UP;

		/**
		 * Vector representing the down direction.
		 * This is shorthand for writing Vector2(0.0f, -1.0f).
		 */
		static const Vector2 DOWN;

		/**
		 * Vector representing the right direction.
		 * This is shorthand for writing Vector2(1.0f, 0.0f).
		 */
		static const Vector2 RIGHT;

		/**
		 * Vector representing the left direction.
		 * This is shorthand for writing Vector2(-1.0f, 0.0f).
		 */
		static const Vector2 LEFT;

		/**
		 * Shorthand for writing Vector3(1.0f, 1.0f).
		 */
		static const Vector2 ONE;

		/**
		 * Shorthand for writing Vector3(0.0f, 0.0f).
		 */
		static const Vector2 ZERO;
	};

	/**
	 * Multiplies two vectors component-wise. This is the same as scaling the
	 * first vector by the second vector.
	 *
	 * @param v1 The left hand side vector.
	 * @param v2 The right hand side vector.
	 * @return Result of scaling the first vector by the second vector.
	 */
	Vector2 scale(const Vector2& v1, const Vector2& v2);

	/**
	 * Returns the dot product of two vectors.
	 *
	 * The dot product is commutative. For normalized vectors, the dot product
	 * returns 1 if they point in exactly the same direction, -1 if they
	 * point in completely opposite directions and 0 if they vectors are
	 * perpendicular.
	 *
	 * @param lhs The left hand side vector.
	 * @param rhs The right hand side vector.
	 * @return Dot product of the two vectors.
	 */
	float dot(const Vector2& lhs, const Vector2& rhs);

	/**
	 * Returns the smallest angle in radians between `from` and `to`.
	 *
	 * @param from The angle extends round from this vector.
	 * @param to The angle extends round to this vector.
	 * @return Angle in radians.
	 */
	float angle(const Vector2& from, const Vector2& to);

	/**
	 * Returns the square distance between vectors `p1` and `p2`.
	 *
	 * Visualizing both input vectors as points in 2D space, this is the
	 * square of the straight-line distance between the two points.
	 *
	 * @param p1 The vector representing the first point.
	 * @param p2 The vector representing the second point.
	 * @return Square of the distance between the two points.
	 */
	float sqrDistance(const Vector2& p1, const Vector2& p2);

	/**
	 * Returns the distance between vectors `p1` and `p2`.
	 *
	 * Visualizing both input vectors as points in 2D space, this is the
	 * straight-line distance between the two points.
	 *
	 * @param p1 The vector representing the first point.
	 * @param p2 The vector representing the second point.
	 * @return Distance between the two points.
	 */
	float distance(const Vector2& p1, const Vector2& p2);
}

#endif
