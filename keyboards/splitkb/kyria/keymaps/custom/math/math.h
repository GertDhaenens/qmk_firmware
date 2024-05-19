//!-----------------------------------------------------------------------
//! @file           : math.h
//! @author         : Gert Dhaenens
//! @date           : 02-06-2023 21:42
//!-----------------------------------------------------------------------

#pragma once

// System Includes
//-----------------------------------------------------------------------
#include <math.h>

//! @brief Linear interpolate between two floats
//! @param i_a The start point of our linear interpolation
//! @param i_b The end point of our linear interpolation
//! @param i_t The amount to interpolate by. Must be between [0,1]
float
math_lerp
(
    float const i_a,
    float const i_b,
    float const i_t
);

//! @brief Get the minimum value between two values
//! @param i_a The first value to get the minimum of
//! @param i_a The second value to get the minimum of
float
math_min
(
    float const i_a,
    float const i_b
);

//! @brief Get the maximum value between two values
//! @param i_a The first value to get the maximum of
//! @param i_a The second value to get the maximum of
float
math_max
(
    float const i_a,
    float const i_b
);

//! @brief Clamp a value between two ranges
//! @param i_a The value to clamp
//! @param i_min The minimum value to clamp by
//! @param i_max The maximum value to clamp by
float
math_clamp
(
    float const i_a,
    float const i_min,
    float const i_max
);

//! @brief Clamp a value between 0 and 1
//! @param i_a The value to clamp
float
math_saturate
(
    float const i_a
);

//! @brief Convert degrees to radians
//! @param i_degrees The value to convert
float
math_degrees_to_radians
(
    float const i_degrees
);
