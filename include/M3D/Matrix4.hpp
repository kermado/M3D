#ifndef MATRIX4_HPP
#define MATRIX4_HPP

#include <M3D/Matrix3.hpp>

#include <ostream>

namespace M3D
{
	class Vector3;
	class Vector4;
	class Quaternion;

	class Matrix4
	{
	public:
		/**
		 * Default constructor.
		 *
		 * Constructs the identity matrix.
		 */
		Matrix4();

		/**
		 * Constructor.
		 *
		 * Constructs the matrix from the passed array.
		 *
		 * @param arr Array of floating point values in row-major order.
		 */
		Matrix4(const float arr[16]);

		/**
		 * Constructor.
		 *
		 * Constructs the matrix from the specified entries.
		 *
		 * @param entry00 Entry at row 0 column 0.
		 * @param entry01 Entry at row 0 column 1.
		 * @param entry02 Entry at row 0 column 2.
		 * @param entry03 Entry at row 0 column 3.
		 * @param entry10 Entry at row 1 column 0.
		 * @param entry11 Entry at row 1 column 1.
		 * @param entry12 Entry at row 1 column 2.
		 * @param entry13 Entry at row 1 column 3.
		 * @param entry20 Entry at row 2 column 0.
		 * @param entry21 Entry at row 2 column 1.
		 * @param entry22 Entry at row 2 column 2.
		 * @param entry23 Entry at row 2 column 3.
		 * @param entry30 Entry at row 3 column 0.
		 * @param entry31 Entry at row 3 column 1.
		 * @param entry32 Entry at row 3 column 2.
		 * @param entry33 Entry at row 3 column 3.
		 */
		Matrix4(float entry00, float entry01, float entry02, float entry03,
			float entry10, float entry11, float entry12, float entry13,
			float entry20, float entry21, float entry22, float entry23,
			float entry30, float entry31, float entry32, float entry33);

		/**
		 * Constructor.
		 *
		 * Constructs the matrix from the passed 3x3 matrix.
		 *
		 * @param A The 3x3 matrix from which to construct this matrix.
		 */
		Matrix4(const Matrix3& A);

		/**
		 * Constructor.
		 *
		 * Constructs the matrix from the passed quaternion.
		 *
		 * @param q The quaternion from which to construct the matrix.
		 */
		Matrix4(const Quaternion& q);

		/**
		 * Copy constructor.
		 *
		 * @param other The other matrix to copy.
		 */
		Matrix4(const Matrix4& other) = default;

		/**
		 * Matrix entry accessor operator.
		 *
		 * @note Entry indicies are in the range 0 <= `index` <= 16.
		 *
		 * @param index Index for the entry to return.
		 * @return Entry at position `index`.
		 */
		float operator[](std::size_t index) const;

		/**
		 * Equality operator.
		 *
		 * @param A The first matrix.
		 * @param B The second matrix.
		 * @return True if the two supplied matrices are equal. False otherwise.
		 */
		friend bool operator==(const Matrix4& A, const Matrix4& B);

		/**
		 * Non-equality operator.
		 *
		 * @param A The first matrix.
		 * @param B The second matrix.
		 * @return True if the two supplied matrices are not equal. False
		 * otherwise.
		 */
		friend bool operator!=(const Matrix4& A, const Matrix4& B);

		/**
		 * Matrix addition operator.
		 *
		 * @note Matrix addition is commutative.
		 *
		 * @param A The first matrix.
		 * @param B The second matrix.
		 * @return The matrix equal to the sum of `A` and `B`.
		 */
		friend Matrix4 operator+(const Matrix4& A, const Matrix4& B);

		/**
		 * Matrix subtraction operator.
		 *
		 * @note Matrix subtraction is not commutative.
		 *
		 * @param lhs The left hand side matrix.
		 * @param rhs The right hand side matrix.
		 * @return The matrix equal to the `rhs` matrix subtracted from the `lhs`
		 * matrix.
		 */
		friend Matrix4 operator-(const Matrix4& lhs, const Matrix4& rhs);

		/**
		 * Matrix negation operator.
		 *
		 * @param A The matrix to negate.
		 * @return The additive inverse of the matrix `A`.
		 */
		friend Matrix4 operator-(const Matrix4 &A);

		/**
		 * Scalar multiplication operator.
		 *
		 * Multiplies each entry of a matrix by a given scalar value.
		 *
		 * @param A The matrix to be multiplied by the given scalar.
		 * @param s The scalar value.
		 * @return The matrix `A` multiplied by the scalar `s`.
		 */
		friend Matrix4 operator*(const Matrix4& A, const float s);

		/**
		 * Scalar multiplication operator.
		 *
		 * Multiplies each entry of a matrix by a given scalar value.
		 *
		 * @param s The scalar value.
		 * @param A The matrix to be multiplied by the given scalar.
		 * @return The matrix `A` multiplied by the scalar `s`.
		 */
		friend Matrix4 operator*(const float s, const Matrix4& A);

		/**
		 * Vector multiplication operator.
		 *
		 * Multiplies the column vector `rhs` on the left by the matrix `lhs`,
		 * returning the resulting vector.
		 *
		 * @param lhs The matrix.
		 * @param rhs The column vector.
		 * @return The vector `rhs` multiplied by the matrix `lhs` on the left.
		 */
		friend Vector4 operator*(const Matrix4& lhs, const Vector4& rhs);

		/**
		 * Vector multiplication operator.
		 *
		 * Multiplies the matrix `rhs` on the left by the row vector `lhs`,
		 * returning the resulting vector.
		 *
		 * @param lhs The matrix.
		 * @param rhs The row vector.
		 * @return The vector `lhs` multiplied by the matrix `rhs` on the right.
		 */
		friend Vector4 operator*(const Vector4& lhs, const Matrix4& rhs);

		/**
		 * Matrix multiplication operator.
		 *
		 * @note Matrix multiplication is not commutative.
		 *
		 * @param lhs The left hand side matrix.
		 * @param rhs The right hand side matrix.
		 * @return The matrix equal to the product `lhs` x `rhs`.
		 */
		friend Matrix4 operator*(const Matrix4& lhs, const Matrix4& rhs);

		/**
		 * Stream output operator.
		 *
		 * @param out Output stream.
		 * @param A Matrix to output.
		 * @return Output stream.
		 */
		friend std::ostream& operator <<(std::ostream& out, const Matrix4& A);

		/**
		 * Returns a copy of this matrix transposed so that the rows now form
		 * columns.
		 *
		 * @return Transposed copy of this matrix.
		 */
		Matrix4 transposed() const;

		/**
		 * Transposes this matrix so that the rows now form columns.
		 */
		void transpose();

		/**
		 * Returns the determinant of the matrix.
		 *
		 * @note A square matrix is invertable if and only if its determinant is
		 * nonzero.
		 *
		 * @return The determinant.
		 */
		float determinant() const;

		/**
		 * Returns a copy of the multiplicitive inverse of this matrix.
		 *
		 * @return The multiplicitive inverse of this matrix.
		 */
		Matrix4 inverse() const;

		/**
		 * Returns a scaling matrix that scales by `scaleFactors.x`,
		 * 'scaleFactors.y' and `scaleFactors.z` in the x, y and z axes
		 * respectively.
		 *
		 * @param scaleFactors Scale factors.
		 * @return Scaling matrix.
		 */
		static Matrix4 scaling(const Vector3& scaleFactors);

		/**
		 * Returns a scaling matrix that scales by `factor` uniformly in the
		 * x, y and z components.
		 *
		 * @param scale Uniform scale factor.
		 * @return Scaling matrix.
		 */
		static Matrix4 scaling(const float factor);

		/**
		 * Returns a translation matrix that translates by the vector
		 * `translation`.
		 *
		 * @param translation Translation vector.
		 * @return Matrix that translates by the translation vector.
		 */
		static Matrix4 translation(const Vector3& translation);

		/**
		 * Returns a rotation matrix corresponding to the rotation around the
		 * specified unit vector `axis` by the specified `angle`.
		 *
		 * @note The axis supplied must be a unit vector.
		 *
		 * @param angle Angle in radians.
		 * @param axis Axis for the rotation.
		 * @return Rotation matrix corresponding to the angle-axis rotation
		 * provided.
		 */
		static Matrix4 angleAxis(const float angle, const Vector3& axis);

		/**
		 * Returns a rotation matrix corresponding to the rotation of z radians
		 * about the z-axis, y radians about the y-axis and x radians about the
		 * x-axis (in that order).
		 *
		 * @param eulerAngles The euler angles for the rotation.
		 * @return Rotation matrix corresponding to the rotation specified by
		 * the supplied euler angles.
		 */
		static Matrix4 euler(const Vector3& eulerAngles);

		/**
		 * Returns a rotation matrix that represents the sortest rotation from
		 * the `fromDirection` to the `toDirection`.
		 *
		 * @param fromDirection Direction for the matrix to rotate from.
		 * @param toDirection Direction for the matrix to rotate to.
		 * @return Rotation matrix corresponding to the rotation from
		 * `fromDirection` to `toDirection`.
		 */
		static Matrix4 fromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

		/**
		 * Returns a rotation matrix that rotates Vector3::FORWARD to look
		 * in the specified `forward` direction with the specified `upwards`
		 * direction.
		 *
		 * @param forward The direction to look in.
		 * @param upwards The vector that defines which direction is up.
		 * @return Rotation matrix representing the rotation that looks in the
		 * `forward` direction.
		 */
		static Matrix4 lookRotation(const Vector3& forward, const Vector3& upwards);

		/**
		 * Returns a rotation matrix that rotates Vector3::FORWARD from the
		 * specified `eye` position of the object to be rotated to look at the
		 * `target` point with the specified `upwards` direction.
		 *
		 * @param target The target point to look at.
		 * @param eye The position of the object to be rotated.
		 * @param upwards The vector that defines which direction is up.
		 * @return Rotation matrix representing the rotation for the `eye`
		 * positioned object to "look at" the `target` point.
		 */
		static Matrix4 lookRotation(const Vector3& target, const Vector3& eye, const Vector3& upwards);

	public:
		/**
		 * The multiplicitive identity matrix.
		 */
		static const Matrix4 IDENTITY;

		/**
		 * The additive identity matrix.
		 */
		static const Matrix4 ZERO;

	private:
		/**
		 * The matrix entries (row major).
		 */
		float m[16];
	};
}

#endif
