//!-----------------------------------------------------------------------
//! @file           : math.inl
//! @author         : Gert Dhaenens
//! @date           : 02-06-2023 22:12
//!-----------------------------------------------------------------------

// Includes
//-----------------------------------------------------------------------
#include "math.h"

//-----------------------------------------------------------------------
float
math_lerp
(
    float const i_a,
    float const i_b,
    float const i_t
)
{
    return ( i_a * ( 1.0f - i_t ) ) + ( i_b * i_t );
}

//-----------------------------------------------------------------------
float
math_min
(
    float const i_a,
    float const i_b
)
{
    return ( i_a < i_b ) ? i_a : i_b;
}

//-----------------------------------------------------------------------
float
math_max
(
    float const i_a,
    float const i_b
)
{
    return ( i_a > i_b ) ? i_a : i_b;
}

//-----------------------------------------------------------------------
float
math_clamp
(
    float const i_a,
    float const i_min,
    float const i_max
)
{
    return math_max( i_min, math_min( i_max, i_a ) );
}

//-----------------------------------------------------------------------
float
math_saturate
(
    float const i_a
)
{
    return math_clamp( i_a, 0.0f, 1.0f );
}

//-----------------------------------------------------------------------
float
math_ceil
(
    float const i_a
)
{
    return ceil( i_a );
}

//-----------------------------------------------------------------------
float
math_floor
(
    float const i_a
)
{
    return floor( i_a );
}

//-----------------------------------------------------------------------
float
math_degrees_to_radians
(
    float const i_degrees
)
{
    // i_degrees * ( PI / 180 )
    return i_degrees * 0.0174533f;
}
