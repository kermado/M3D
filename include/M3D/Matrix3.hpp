#ifndef MATRIX3_HPP
#define MATRIX3_HPP

#include <ostream>
#include <M3D/Vector3.hpp>

namespace M3D
{
	class Matrix3
	{
	public:
		/**
		 * Default constructor.
		 *
		 * Constructs the identity matrix.
		 */
		Matrix3();

		/**
		 * Constructor.
		 *
		 * Constructs the matrix from the passed array.
		 *
		 * @param arr Array of floating point values in row-major order.
		 */
		Matrix3(const float arr[9]);

		/**
		 * Constructor.
		 *
		 * Constructs the matrix from the specified entries.
		 *
		 * @param entry00 Entry at row 0 column 0.
		 * @param entry01 Entry at row 0 column 1.
		 * @param entry02 Entry at row 0 column 2.
		 * @param entry10 Entry at row 1 column 0.
		 * @param entry11 Entry at row 1 column 1.
		 * @param entry12 Entry at row 1 column 2.
		 * @param entry20 Entry at row 2 column 0.
		 * @param entry21 Entry at row 2 column 1.
		 * @param entry22 Entry at row 2 column 2.
		 */
		Matrix3(float entry00, float entry01, float entry02,
			float entry10, float entry11, float entry12,
			float entry20, float entry21, float entry22);

		/**
		 * Copy constructor.
		 *
		 * @param other The other matrix to copy.
		 */
		Matrix3(const Matrix3& other) = default;

		/**
		 * Matrix entry accessor operator.
		 *
		 * @note Entry indicies are in the range 0 <= `index` <= 8.
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
		friend bool operator==(const Matrix3& A, const Matrix3& B);

		/**
		 * Non-equality operator.
		 *
		 * @param A The first matrix.
		 * @param B The second matrix.
		 * @return True if the two supplied matrices are not equal. False
		 * otherwise.
		 */
		friend bool operator!=(const Matrix3& A, const Matrix3& B);

		/**
		 * Matrix addition operator.
		 *
		 * @note Matrix addition is commutative.
		 *
		 * @param A The first matrix.
		 * @param B The second matrix.
		 * @return The matrix equal to the sum of `A` and `B`.
		 */
		friend Matrix3 operator+(const Matrix3& A, const Matrix3& B);

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
		friend Matrix3 operator-(const Matrix3& lhs, const Matrix3& rhs);

		/**
		 * Matrix negation operator.
		 *
		 * @param A The matrix to negate.
		 * @return The additive inverse of the matrix `A`.
		 */
		friend Matrix3 operator-(const Matrix3 &A);

		/**
		 * Scalar multiplication operator.
		 *
		 * Multiplies each entry of a matrix by a given scalar value.
		 *
		 * @param A The matrix to be multiplied by the given scalar.
		 * @param s The scalar value.
		 * @return The matrix `A` multiplied by the scalar `s`.
		 */
		friend Matrix3 operator*(const Matrix3& A, const float s);

		/**
		 * Scalar multiplication operator.
		 *
		 * Multiplies each entry of a matrix by a given scalar value.
		 *
		 * @param s The scalar value.
		 * @param A The matrix to be multiplied by the given scalar.
		 * @return The matrix `A` multiplied by the scalar `s`.
		 */
		friend Matrix3 operator*(const float s, const Matrix3& A);

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
		friend Vector3 operator*(const Matrix3& lhs, const Vector3& rhs);

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
		friend Vector3 operator*(const Vector3& lhs, const Matrix3& rhs);

		/**
		 * Matrix multiplication operator.
		 *
		 * @note Matrix multiplication is not commutative.
		 *
		 * @param lhs The left hand side matrix.
		 * @param rhs The right hand side matrix.
		 * @return The matrix equal to the product `lhs` x `rhs`.
		 */
		friend Matrix3 operator*(const Matrix3& lhs, const Matrix3& rhs);

		/**
		 * Stream output operator.
		 *
		 * @param out Output stream.
		 * @param A Matrix to output.
		 * @return Output stream.
		 */
		friend std::ostream& operator <<(std::ostream& out, const Matrix3& A);

		/**
		 * Returns a copy of this matrix transposed so that the rows now form
		 * columns.
		 *
		 * @return Transposed copy of this matrix.
		 */
		Matrix3 transposed() const;

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
		Matrix3 inverse() const;

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
		static Matrix3 angleAxis(const float angle, const Vector3& axis);

		/**
		 * Returns a rotation matrix corresponding to the rotation of z radians
		 * about the z-axis, y radians about the y-axis and x radians about the
		 * x-axis (in that order).
		 *
		 * @param eulerAngles The euler angles for the rotation.
		 * @return Rotation matrix corresponding to the rotation specified by
		 * the supplied euler angles.
		 */
		static Matrix3 euler(const Vector3& eulerAngles);

		/**
		 * Returns a rotation matrix that represents the sortest rotation from
		 * the `fromDirection` to the `toDirection`.
		 *
		 * @param fromDirection Direction for the matrix to rotate from.
		 * @param toDirection Direction for the matrix to rotate to.
		 * @return Rotation matrix corresponding to the rotation from
		 * `fromDirection` to `toDirection`.
		 */
		static Matrix3 fromToRotation(const Vector3& fromDirection, const Vector3& toDirection);

		/**
		 * Returns a rotation matrix that rotates the Vector3::FORWARD to look
		 * in the specified `forward` direction with the specified `upwards`
		 * direction.
		 *
		 * @param forward The direction to look in.
		 * @param upwards The vector that defines which direction is up.
		 * @return Rotation matrix representing the rotation that looks in the
		 * `forward` direction.
		 */
		static Matrix3 lookRotation(const Vector3& forward, const Vector3& upwards);

	public:
		/**
		 * The multiplicitive identity matrix.
		 */
		static const Matrix3 IDENTITY;

		/**
		 * The additive identity matrix.
		 */
		static const Matrix3 ZERO;

	private:
		/**
		 * The matrix entries (row major).
		 */
		float m[9];
	};
}

#endif
