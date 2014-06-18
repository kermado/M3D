#ifndef MATRIX2_HPP
#define MATRIX2_HPP

#include <ostream>
#include <M3D/Vector2.hpp>

namespace M3D
{
	class Matrix2
	{
	public:
		/**
		 * Default constructor.
		 *
		 * Constructs the identity matrix.
		 */
		Matrix2();

		/**
		 * Constructor.
		 *
		 * Constructs the matrix from the passed array.
		 *
		 * @param arr Array of floating point values in row-major order.
		 */
		Matrix2(const float arr[4]);

		/**
		 * Constructor.
		 *
		 * Constructs the matrix from the specified entries.
		 *
		 * @param entry00 Entry at row 0 column 0.
		 * @param entry01 Entry at row 0 column 1.
		 * @param entry10 Entry at row 1 column 0.
		 * @param entry11 Entry at row 1 column 1.
		 * @param entry20 Entry at row 2 column 0.
		 */
		Matrix2(float entry00, float entry01, float entry10, float entry11);

		/**
		 * Copy constructor.
		 *
		 * @param other The other matrix to copy.
		 */
		Matrix2(const Matrix2& other) = default;

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
		friend bool operator==(const Matrix2& A, const Matrix2& B);

		/**
		 * Non-equality operator.
		 *
		 * @param A The first matrix.
		 * @param B The second matrix.
		 * @return True if the two supplied matrices are not equal. False
		 * otherwise.
		 */
		friend bool operator!=(const Matrix2& A, const Matrix2& B);

		/**
		 * Matrix addition operator.
		 *
		 * @note Matrix addition is commutative.
		 *
		 * @param A The first matrix.
		 * @param B The second matrix.
		 * @return The matrix equal to the sum of `A` and `B`.
		 */
		friend Matrix2 operator+(const Matrix2& A, const Matrix2& B);

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
		friend Matrix2 operator-(const Matrix2& lhs, const Matrix2& rhs);

		/**
		 * Matrix negation operator.
		 *
		 * @param A The matrix to negate.
		 * @return The additive inverse of the matrix `A`.
		 */
		friend Matrix2 operator-(const Matrix2 &A);

		/**
		 * Scalar multiplication operator.
		 *
		 * Multiplies each entry of a matrix by a given scalar value.
		 *
		 * @param A The matrix to be multiplied by the given scalar.
		 * @param s The scalar value.
		 * @return The matrix `A` multiplied by the scalar `s`.
		 */
		friend Matrix2 operator*(const Matrix2& A, const float s);

		/**
		 * Scalar multiplication operator.
		 *
		 * Multiplies each entry of a matrix by a given scalar value.
		 *
		 * @param s The scalar value.
		 * @param A The matrix to be multiplied by the given scalar.
		 * @return The matrix `A` multiplied by the scalar `s`.
		 */
		friend Matrix2 operator*(const float s, const Matrix2& A);

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
		friend Vector2 operator*(const Matrix2& lhs, const Vector2& rhs);

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
		friend Vector2 operator*(const Vector2& lhs, const Matrix2& rhs);

		/**
		 * Matrix multiplication operator.
		 *
		 * @note Matrix multiplication is not commutative.
		 *
		 * @param lhs The left hand side matrix.
		 * @param rhs The right hand side matrix.
		 * @return The matrix equal to the product `lhs` x `rhs`.
		 */
		friend Matrix2 operator*(const Matrix2& lhs, const Matrix2& rhs);

		/**
		 * Stream output operator.
		 *
		 * @param out Output stream.
		 * @param A Matrix to output.
		 * @return Output stream.
		 */
		friend std::ostream& operator <<(std::ostream& out, const Matrix2& A);

		/**
		 * Returns a copy of this matrix transposed so that the rows now form
		 * columns.
		 *
		 * @return Transposed copy of this matrix.
		 */
		Matrix2 transposed() const;

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
		Matrix2 inverse() const;

		/**
		 * Returns a scaling matrix that scales by `scaleFactors.x` and
		 * 'scaleFactors.y' in the x and y axes respectively.
		 *
		 * @param scaleFactors Scale factors.
		 * @return Scaling matrix.
		 */
		static Matrix2 scaling(const Vector2& scaleFactors);

		/**
		 * Returns a scaling matrix that scales by `factor` uniformly.
		 *
		 * @param scale Uniform scale factor.
		 * @return Scaling matrix.
		 */
		static Matrix2 scaling(const float factor);

		/**
		 * Returns a rotation matrix that rotates by `angle` radians.
		 *
		 * @param angle Angle (in radians) for the rotation.
		 * @return Rotation matrix that rotates `angle` radians
		 * counter-clockwise.
		 */
		static Matrix2 angleRotation(const float angle);

		/**
		 * Returns a rotation matrix that represents the sortest rotation from
		 * the `fromDirection` to the `toDirection`.
		 *
		 * @param fromDirection Direction for the matrix to rotate from.
		 * @param toDirection Direction for the matrix to rotate to.
		 * @return Rotation matrix corresponding to the rotation from
		 * `fromDirection` to `toDirection`.
		 */
		static Matrix2 fromToRotation(const Vector2& fromDirection, const Vector2& toDirection);

	public:
		/**
		 * The multiplicitive identity matrix.
		 */
		static const Matrix2 IDENTITY;

		/**
		 * The additive identity matrix.
		 */
		static const Matrix2 ZERO;

	private:
		/**
		 * The matrix entries (row major).
		 */
		float m[4];
	};
}

#endif
