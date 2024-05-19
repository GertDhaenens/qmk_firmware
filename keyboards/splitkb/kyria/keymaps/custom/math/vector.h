//!-----------------------------------------------------------------------
//! @file           : vector.h
//! @author         : Gert Dhaenens
//! @date           : 01-06-2023 20:55
//!-----------------------------------------------------------------------

#pragma once

// Includes
//-----------------------------------------------------------------------
#include "math.h"

//! @brief A 2 dimensional vector of unsigned ints
typedef union tagVec2u
{
    struct
    {
        uint32_t x;
        uint32_t y;
    };
    uint32_t v[2u];

} Vec2u;

//! @brief A 2 dimensional vector of floats
typedef union tagVec2f
{
    struct
    {
        float x;
        float y;
    };
    float v[2u];

} Vec2f;

//! @brief A 3 dimensional vector of floats
typedef union tagVec3f
{
    struct
    {
        float x;
        float y;
        float z;
    };
    float v[3u];

} Vec3f;

//! @brief A 4 dimensional vector of floats
typedef union tagVec4f
{
    struct
    {
        float x;
        float y;
        float z;
        float w;
    };
    float v[4u];

} Vec4f;

//! @{
//! @brief Create a new vector with a given set of components
static inline Vec2f vec2f( float const i_x, float const i_y );
static inline Vec3f vec3f( float const i_x, float const i_y, float const i_z );
static inline Vec4f vec4f( float const i_x, float const i_y, float const i_z, float const i_w );
//! @}

//! @{
//! @brief Get a vector with all components set to zero
static inline Vec2f vec2f_zero( void );
static inline Vec3f vec3f_zero( void );
static inline Vec4f vec4f_zero( void );
//! @}

//! @{
//! @brief Get a vector with all components set to one
static inline Vec2f vec2f_one( void );
static inline Vec3f vec3f_one( void );
static inline Vec4f vec4f_one( void );
//! @}

//! @{
//! @brief Get a vector representing a unit X-axis vector
static inline Vec2f vec2f_unit_x( void );
static inline Vec3f vec3f_unit_x( void );
static inline Vec4f vec4f_unit_x( void );
//! @}

//! @{
//! @brief Get a vector representing a unit Y-axis vector
static inline Vec2f vec2f_unit_y( void );
static inline Vec3f vec3f_unit_y( void );
static inline Vec4f vec4f_unit_y( void );
//! @}

//! @{
//! @brief Get a vector representing a unit Z-axis vector
static inline Vec3f vec3f_unit_z( void );
static inline Vec4f vec4f_unit_z( void );
//! @}

//! @{
//! @brief Get a vector representing a unit W-axis vector
static inline Vec4f vec4f_unit_w( void );
//! @}

//! @{
//! @brief Add two vectors together
//! @param i_a The first operand of the addition
//! @param i_b The second operand of the addition
static inline Vec2f vec2f_add( Vec2f const i_a, Vec2f const i_b );
static inline Vec3f vec3f_add( Vec3f const i_a, Vec3f const i_b );
static inline Vec4f vec4f_add( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Subtract two vectors from eachother
//! @param i_a The first operand of the subtraction
//! @param i_b The second operand of the subtraction
static inline Vec2f vec2f_sub( Vec2f const i_a, Vec2f const i_b );
static inline Vec3f vec3f_sub( Vec3f const i_a, Vec3f const i_b );
static inline Vec4f vec4f_sub( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Multiply two vectors with each other
//! @param i_a The first operand of the multiplication
//! @param i_b The second operand of the multiplication
static inline Vec2f vec2f_mul( Vec2f const i_a, Vec2f const i_b );
static inline Vec3f vec3f_mul( Vec3f const i_a, Vec3f const i_b );
static inline Vec4f vec4f_mul( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Divide two vectors from eachother
//! @param i_a The first operand of the division
//! @param i_b The second operand of the division
static inline Vec2f vec2f_div( Vec2f const i_a, Vec2f const i_b );
static inline Vec3f vec3f_div( Vec3f const i_a, Vec3f const i_b );
static inline Vec4f vec4f_div( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Calculate the length of a vector
//! @param i_a The vector to calculate the value for
static inline float vec2f_length( Vec2f const i_a );
static inline float vec3f_length( Vec3f const i_a );
static inline float vec4f_length( Vec4f const i_a );
//! @}

//! @{
//! @brief Calculate the squared length of a vector
//! @param i_a The vector to calculate the value for
static inline float vec2f_length_squared( Vec2f const i_a );
static inline float vec3f_length_squared( Vec3f const i_a );
static inline float vec4f_length_squared( Vec4f const i_a );
//! @}

//! @{
//! @brief Normalise a vector
//! @param i_a The vector to normalise
static inline Vec2f vec2f_normalise( Vec2f const i_a );
static inline Vec3f vec3f_normalise( Vec3f const i_a );
static inline Vec4f vec4f_normalise( Vec4f const i_a );
//! @}

//! @{
//! @brief Create a vector with all components set to the same value
//! @param i_a The value to set all components to
static inline Vec2f vec2f_splat( float const i_a );
static inline Vec3f vec3f_splat( float const i_a );
static inline Vec4f vec4f_splat( float const i_a );
//! @}

//! @{
//! @brief Calculate the dot product between two vectors
//! @param i_a The first vector
//! @param i_b The second vector
static inline float vec2f_dot( Vec2f const i_a, Vec2f const i_b );
static inline float vec3f_dot( Vec3f const i_a, Vec3f const i_b );
static inline float vec4f_dot( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Calculate the cross product between two vectors
//! @param i_a The first vector
//! @param i_b The second vector
static inline Vec3f vec3f_cross( Vec3f const i_a, Vec3f const i_b );
//! @}

//! @brief Calculate the reflection of a vector around a normal
//! @param i_incident The vector to reflect
//! @param i_normal The vector to reflect against
static inline Vec3f vec3f_reflect( Vec3f const i_incident, Vec3f const i_normal );
//! @}

//! @brief Calculate the refraction of a vector around a normal
//! @param i_incident The vector to reflect
//! @param i_normal The vector to reflect against
//! @param i_iorRatio The index of refraction of the active medium divided by the index of refraction of the entry medium
static inline Vec3f vec3f_refract( Vec3f const i_incident, Vec3f const i_normal, float const i_iorRatio );
//! @}

//! @brief Calculate the reflectance between an incident vector and a normal
//! @param i_incident The incident direction to reflect
//! @param i_normal The vector to reflect against
//! @param i_iorRatio The index of refraction of the active medium divided by the index of refraction of the entry medium
static inline float vec3f_reflectance( Vec3f const i_incident, Vec3f const i_normal, float const i_iorRatio );
//! @}

//! @{
//! @brief Linear interpolate between two vectors
//! @param i_a The start point of our linear interpolation
//! @param i_b The end point of our linear interpolation
//! @param i_t The amount to interpolate by. Must be between [0,1]
static inline Vec2f vec2f_lerp( Vec2f const i_a, Vec2f const i_b, float const i_t );
static inline Vec3f vec3f_lerp( Vec3f const i_a, Vec3f const i_b, float const i_t );
static inline Vec4f vec4f_lerp( Vec4f const i_a, Vec4f const i_b, float const i_t );
//! @}

//! @{
//! @brief Calculate the component-wise minimum of two vectors
//! @param i_a The first vector to consider
//! @param i_b The second vector to consider
static inline Vec2f vec2f_min( Vec2f const i_a, Vec2f const i_b );
static inline Vec3f vec3f_min( Vec3f const i_a, Vec3f const i_b );
static inline Vec4f vec4f_min( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Calculate the component-wise maximum of two vectors
//! @param i_a The first vector to consider
//! @param i_b The second vector to consider
static inline Vec2f vec2f_max( Vec2f const i_a, Vec2f const i_b );
static inline Vec3f vec3f_max( Vec3f const i_a, Vec3f const i_b );
static inline Vec4f vec4f_max( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Calculate the distance between two vectors
//! @param i_a The first vector to consider
//! @param i_b The second vector to consider
static inline float vec2f_distance( Vec2f const i_a, Vec2f const i_b );
static inline float vec3f_distance( Vec3f const i_a, Vec3f const i_b );
static inline float vec4f_distance( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Calculate the distance squared between two vectors
//! @param i_a The first vector to consider
//! @param i_b The second vector to consider
static inline float vec2f_distance_squared( Vec2f const i_a, Vec2f const i_b );
static inline float vec3f_distance_squared( Vec3f const i_a, Vec3f const i_b );
static inline float vec4f_distance_squared( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Are all components zero?
//! @param i_a The vector to check the components of
static inline bool vec2f_all_zero( Vec2f const i_a );
static inline bool vec3f_all_zero( Vec3f const i_a );
static inline bool vec4f_all_zero( Vec4f const i_a );
//! @}

//! @{
//! @brief Are all components non-zero?
//! @param i_a The vector to check the components of
static inline bool vec2f_all_non_zero( Vec2f const i_a );
static inline bool vec3f_all_non_zero( Vec3f const i_a );
static inline bool vec4f_all_non_zero( Vec4f const i_a );
//! @}

//! @{
//! @brief Are all components greater or equal to eachother?
//! @param i_a The first comparison element
//! @param i_b The second comparison element
static inline bool vec2f_all_greater_equal( Vec2f const i_a, Vec2f const i_b );
static inline bool vec3f_all_greater_equal( Vec3f const i_a, Vec3f const i_b );
static inline bool vec4f_all_greater_equal( Vec4f const i_a, Vec4f const i_b );
//! @}

//! @{
//! @brief Are all components lesser or equal to eachother?
//! @param i_a The first comparison element
//! @param i_b The second comparison element
static inline bool vec2f_all_lesser_equal( Vec2f const i_a, Vec2f const i_b );
static inline bool vec3f_all_lesser_equal( Vec3f const i_a, Vec3f const i_b );
static inline bool vec4f_all_lesser_equal( Vec4f const i_a, Vec4f const i_b );
//! @}

#include "vector.inl"
