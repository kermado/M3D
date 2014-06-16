#ifndef VECTOR4_HPP
#define VECTOR4_HPP

#include <ostream>

#include <M3D/Vector3.hpp>

namespace M3D
{
	class Vector4
	{
	public:
		/**
		 * Default constructor.
		 *
		 * Constructs the zero vector.
		 */
		Vector4();

		/**
		 * Constructor.
		 *
		 * @param x_ The first component.
		 * @param y_ The second component.
		 * @param z_ The third component.
		 * @param w_ The fourth component.
		 */
		Vector4(float x_, float y_, float z_, float w_);

		/**
		 * Constructor.
		 *
		 * Constructs a 4D vector from a 3D vector by setting the fourth
		 * component equal to zero.
		 */
		Vector4(const Vector3& v);

		/**
		 * Constructor.
		 *
		 * Constructs a 4D vector from a 3D vector and specified fourth
		 * component value.
		 */
		Vector4(const Vector3& v, float w_);

		/**
		 * Vector equality operator.
		 *
		 * @param v1 The first vector.
		 * @param v2 The second vector.
		 * @return True if the two supplied vectors are equal. False otherwise.
		 */
		friend float operator==(const Vector4& v1, const Vector4& v2);

		/**
		 * Vector non-equality operator.
		 *
		 * @param v1 The first vector.
		 * @param v2 The second vector.
		 * @return True if the two supplied vectors are not equal. False
		 * otherwise.
		 */
		friend float operator!=(const Vector4& v1, const Vector4& v2);

		/**
		 * Vector addition operator.
		 *
		 * @param v1 First vector.
		 * @param v2 Second vector.
		 * @return Result of adding the first vector to the second vector.
		 */
		friend Vector4 operator+(const Vector4& v1, const Vector4& v2);

		/**
		 * Vector subtraction operator.
		 *
		 * @param v1 The first vector.
		 * @param v2 The second vector.
		 * @return Result of subtracting the second vector from the first
		 * vector.
		 */
		friend Vector4 operator-(const Vector4& v1, const Vector4& v2);

		/**
		 * Vector negation operator.
		 *
		 * @param v The vector to negate.
		 * @return The additive inverse of the vector `v`.
		 */
		friend Vector4 operator-(const Vector4 &v);

		/**
		 * Scalar multiplication operator.
		 *
		 * @param v The vector.
		 * @param s The scalar value.
		 * @return Vector `v` scaled by `s`.
		 */
		friend Vector4 operator*(const Vector4& v, const float s);

		/**
		 * Scalar multiplication operator.
		 *
		 * @param s The scalar value.
		 * @param v The vector.
		 * @return Vector `v` scaled by `s`.
		 */
		friend Vector4 operator*(const float s, const Vector4& v);

		/**
		 * Scalar division operator.
		 *
		 * @param v The vector.
		 * @param s The scalar value.
		 * @return Vector `v` scaled by the reciprocal of `s`.
		 */
		friend Vector4 operator/(const Vector4& v, const float s);

		/**
		 * Stream output operator.
		 *
		 * @param out Output stream.
		 * @param v Vector to output.
		 * @return Output stream.
		 */
		friend std::ostream& operator <<(std::ostream& out, const Vector4& v);

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
		Vector4 normalized() const;

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

		/**
		 * Third component.
		 */
		float z;

		/**
		 * Fourth component.
		 */
		float w;

	public:
		/**
		 * Vector representing the forward direction.
		 * This is shorthand for writing Vector4(0.0f, 0.0f, 1.0f, 0.0f).
		 */
		static const Vector4 FORWARD;

		/**
		 * Vector representing the back direction.
		 * This is shorthand for writing Vector4(0.0f, 0.0f, -1.0f, 0.0f).
		 */
		static const Vector4 BACK;

		/**
		 * Vector representing the up direction.
		 * This is shorthand for writing Vector4(0.0f, 1.0f, 0.0f, 0.0f).
		 */
		static const Vector4 UP;

		/**
		 * Vector representing the down direction.
		 * This is shorthand for writing Vector4(0.0f, -1.0f, 0.0f, 0.0f).
		 */
		static const Vector4 DOWN;

		/**
		 * Vector representing the right direction.
		 * This is shorthand for writing Vector4(1.0f, 0.0f, 0.0f, 0.0f).
		 */
		static const Vector4 RIGHT;

		/**
		 * Vector representing the left direction.
		 * This is shorthand for writing Vector4(-1.0f, 0.0f, 0.0f, 0.0f).
		 */
		static const Vector4 LEFT;

		/**
		 * Shorthand for writing Vector4(1.0f, 1.0f, 1.0f, 1.0f).
		 */
		static const Vector4 ONE;

		/**
		 * Shorthand for writing Vector4(0.0f, 0.0f, 0.0f, 0.0f).
		 */
		static const Vector4 ZERO;
	};

	/**
	 * Multiplies two vectors component-wise. This is the same as scaling the
	 * first vector by the second vector.
	 *
	 * @param v1 The left hand side vector.
	 * @param v2 The right hand side vector.
	 * @return Result of scaling the first vector by the second vector.
	 */
	Vector4 scale(const Vector4& v1, const Vector4& v2);

	/**
	 * Returns the dot product of two vectors.
	 *
	 * The dot product is commutative.
	 *
	 * @param lhs The left hand side vector.
	 * @param rhs The right hand side vector.
	 * @return Dot product of the two vectors.
	 */
	float dot(const Vector4& lhs, const Vector4& rhs);

	/**
	 * Returns the square distance between vectors `p1` and `p2`.
	 *
	 * @param p1 The vector representing the first point.
	 * @param p2 The vector representing the second point.
	 * @return Square of the distance between the two points.
	 */
	float sqrDistance(const Vector4& p1, const Vector4& p2);

	/**
	 * Returns the distance between vectors `p1` and `p2`.
	 *
	 * @param p1 The vector representing the first point.
	 * @param p2 The vector representing the second point.
	 * @return Distance between the two points.
	 */
	float distance(const Vector4& p1, const Vector4& p2);
}

#endif
