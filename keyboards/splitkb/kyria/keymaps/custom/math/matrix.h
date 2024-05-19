//!-----------------------------------------------------------------------
//! @file           : matrix.h
//! @author         : Gert Dhaenens
//! @date           : 06-06-2023 21:30
//!-----------------------------------------------------------------------

#pragma once

// Includes
//-----------------------------------------------------------------------
#include "vector.h"

//! @brief A 3x3 matrix of floating precision values
typedef union tagMat3x3f
{
    //! @brief The matrix in flat array format
    float m[9];

    //! @brief The matrix in row/column format
    struct
    {
        Vec3f x;
        Vec3f y;
        Vec3f z;
    };

} Mat3x3f;

//! @brief A 4x4 matrix of floating precision values
typedef union tagMat4x4f
{
    //! @brief The matrix in flat array format
    float m[16];

    //! @brief The matrix in row/column format
    struct
    {
        Vec4f x;
        Vec4f y;
        Vec4f z;
        Vec4f w;
    };

} Mat4x4f;

//! @{
//! @brief Create an identity matrix
static inline Mat3x3f mat3x3f_identity( void );
static inline Mat4x4f mat4x4f_identity( void );
//! @}

//! @{
//! @brief Transpose a matrix
//! @param i_mat The matrix to transpose
static inline Mat3x3f mat3x3f_transpose( Mat3x3f const i_mat );
static inline Mat4x4f mat4x4f_transpose( Mat4x4f const i_mat );
//! @}

//! @{
//! @brief Calculate the inverse of our matrix
//! @param i_mat The matrix to inverse
static inline Mat4x4f mat4x4f_inverse( Mat4x4f const i_mat );
//! @}

//! @{
//! @brief Extract a column of a matrix as a vector
//! @param i_mat The matrix to fetch the column of
//! @param i_column The index of the column to extract
static inline Vec3f mat3x3f_column( Mat3x3f const i_mat, uint8_t const i_column );
static inline Vec4f mat4x4f_column( Mat4x4f const i_mat, uint8_t const i_column );
//! @}

//! @{
//! @brief Multiply a matrix with a matrix
//! @param i_a The first matrix to multiply
//! @param i_b The second matrix to multiply
static inline Mat3x3f mat3x3f_mul( Mat3x3f const i_a, Mat3x3f const i_b );
static inline Mat4x4f mat4x4f_mul( Mat4x4f const i_a, Mat4x4f const i_b );
//! @}

//! @{
//! @brief Multiply a matrix with a vector
//! @param i_vec The vector to multiply
//! @param i_mat The matrix to multiply against
static inline Vec3f mat3x3f_mul_vec( Vec3f const i_vec, Mat3x3f const i_mat );
static inline Vec4f mat4x4f_mul_vec( Vec4f const i_vec, Mat4x4f const i_mat );
//! @}

//! @brief Calculate a matrix for a rotation around the X axis
//! @param i_angleInRadians The angle to rotate in radians
static inline
Mat3x3f
mat3x3f_rotate_x
(
    float const i_angleInRadians
);

//! @brief Calculate a view matrix for a left-handed coordinate system
//! @param i_position The position we are looking from
//! @param i_direction The direction we are looking into
//! @param i_up The world up vector
static inline
Mat4x4f
mat4x4f_lookat_lh
(
    Vec3f const i_position,
    Vec3f const i_direction,
    Vec3f const i_up
);

//! @brief Calculate a perspective projections matrix for a left handed coordinate system
//! @param i_aspectRatio The aspect ratio that we're viewing
//! @param i_fovYInRadians The horizontal FOV in radians
//! @param i_nearPlane The closest depth value in scene units
//! @param i_farPlane The furthest depth value in scene units
static inline
Mat4x4f
mat4x4f_perspective_lh
(
    float const i_aspectRatio,
    float const i_fovYInRadians,
    float const i_nearPlane,
    float const i_farPlane
);

//! @brief Transform a position from one space to another
//! @param i_mat The matrix to go from one space to the other
//! @param i_pos The position to transform
static inline
Vec3f
mat4x4f_transform_position
(
    Mat4x4f const i_mat,
    Vec3f const i_pos
);

//! @brief Transform a direction from one space to another
//! @param i_mat The matrix to go from one space to the other
//! @param i_dir The direction to transform
static inline
Vec3f
mat4x4f_transform_direction
(
    Mat4x4f const i_mat,
    Vec3f const i_dir
);

#include "matrix.inl"
