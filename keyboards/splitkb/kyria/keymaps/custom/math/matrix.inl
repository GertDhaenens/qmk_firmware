//------------------------------------------
//! @file       matrix.inl
//! @author     Gert
//! @date       2024-05-01
//------------------------------------------

//-----------------------------------------------------------------------
Mat3x3f
mat3x3f_identity
(
    void
)
{
    return (Mat3x3f) {
        .x = { .x = 1.0f, .y = 0.0f, .z = 0.0f },
        .y = { .x = 0.0f, .y = 1.0f, .z = 0.0f },
        .z = { .x = 0.0f, .y = 0.0f, .z = 1.0f },
    };
}

//-----------------------------------------------------------------------
Mat4x4f
mat4x4f_identity
(
    void
)
{
    return (Mat4x4f) {
        .x = { .x = 1.0f, .y = 0.0f, .z = 0.0f, .w = 0.0f },
        .y = { .x = 0.0f, .y = 1.0f, .z = 0.0f, .w = 0.0f },
        .z = { .x = 0.0f, .y = 0.0f, .z = 1.0f, .w = 0.0f },
        .w = { .x = 0.0f, .y = 0.0f, .z = 0.0f, .w = 1.0f },
    };
}

//-----------------------------------------------------------------------
Mat3x3f
mat3x3f_transpose
(
    Mat3x3f const i_mat
)
{

    return (Mat3x3f) {
        .x = { .x = i_mat.x.x, .y = i_mat.y.x, .z = i_mat.z.x },
        .y = { .x = i_mat.x.y, .y = i_mat.y.y, .z = i_mat.z.y },
        .z = { .x = i_mat.x.z, .y = i_mat.y.z, .z = i_mat.z.z },
    };
}

//-----------------------------------------------------------------------
Mat4x4f
mat4x4f_transpose
(
    Mat4x4f const i_mat
)
{

    return (Mat4x4f) {
        .x = { .x = i_mat.x.x, .y = i_mat.y.x, .z = i_mat.z.x, .w = i_mat.w.x },
        .y = { .x = i_mat.x.y, .y = i_mat.y.y, .z = i_mat.z.y, .w = i_mat.w.y },
        .z = { .x = i_mat.x.z, .y = i_mat.y.z, .z = i_mat.z.z, .w = i_mat.w.z },
        .w = { .x = i_mat.x.w, .y = i_mat.y.w, .z = i_mat.z.w, .w = i_mat.w.w },
    };
}

//-----------------------------------------------------------------------
Mat4x4f
mat4x4f_inverse
(
    Mat4x4f const i_mat
)
{

    float const s0 = i_mat.x.x * i_mat.y.y - i_mat.y.x * i_mat.x.y;
    float const s1 = i_mat.x.x * i_mat.y.z - i_mat.y.x * i_mat.x.z;
    float const s2 = i_mat.x.x * i_mat.y.w - i_mat.y.x * i_mat.x.w;
    float const s3 = i_mat.x.y * i_mat.y.z - i_mat.y.y * i_mat.x.z;
    float const s4 = i_mat.x.y * i_mat.y.w - i_mat.y.y * i_mat.x.w;
    float const s5 = i_mat.x.z * i_mat.y.w - i_mat.y.z * i_mat.x.w;

    float const c5 = i_mat.z.z * i_mat.w.w - i_mat.w.z * i_mat.z.w;
    float const c4 = i_mat.z.y * i_mat.w.w - i_mat.w.y * i_mat.z.w;
    float const c3 = i_mat.z.y * i_mat.w.z - i_mat.w.y * i_mat.z.z;
    float const c2 = i_mat.z.x * i_mat.w.w - i_mat.w.x * i_mat.z.w;
    float const c1 = i_mat.z.x * i_mat.w.z - i_mat.w.x * i_mat.z.z;
    float const c0 = i_mat.z.x * i_mat.w.y - i_mat.w.x * i_mat.z.y;

    float const detRcp =  1.0f / ( s0 * c5 - s1 * c4 + s2 * c3 + s3 * c2 - s4 * c1 + s5 * c0 );

    return (Mat4x4f) {
        .x = {
            .x = ( i_mat.y.y * c5 - i_mat.y.z * c4 + i_mat.y.w * c3) * detRcp,
            .y = (-i_mat.x.y * c5 + i_mat.x.z * c4 - i_mat.x.w * c3) * detRcp,
            .z = ( i_mat.w.y * s5 - i_mat.w.z * s4 + i_mat.w.w * s3) * detRcp,
            .w = (-i_mat.z.y * s5 + i_mat.z.z * s4 - i_mat.z.w * s3) * detRcp,
        },
        .y = {
            .x = (-i_mat.y.x * c5 + i_mat.y.z * c2 - i_mat.y.w * c1) * detRcp,
            .y = ( i_mat.x.x * c5 - i_mat.x.z * c2 + i_mat.x.w * c1) * detRcp,
            .z = (-i_mat.w.x * s5 + i_mat.w.z * s2 - i_mat.w.w * s1) * detRcp,
            .w = ( i_mat.z.x * s5 - i_mat.z.z * s2 + i_mat.z.w * s1) * detRcp,
        },
        .z = {
            .x = ( i_mat.y.x * c4 - i_mat.y.y * c2 + i_mat.y.w * c0) * detRcp,
            .y = (-i_mat.x.x * c4 + i_mat.x.y * c2 - i_mat.x.w * c0) * detRcp,
            .z = ( i_mat.w.x * s4 - i_mat.w.y * s2 + i_mat.w.w * s0) * detRcp,
            .w = (-i_mat.z.x * s4 + i_mat.z.y * s2 - i_mat.z.w * s0) * detRcp,
        },
        .w = {
            .x = (-i_mat.y.x * c3 + i_mat.y.y * c1 - i_mat.y.z * c0) * detRcp,
            .y = ( i_mat.x.x * c3 - i_mat.x.y * c1 + i_mat.x.z * c0) * detRcp,
            .z = (-i_mat.w.x * s3 + i_mat.w.y * s1 - i_mat.w.z * s0) * detRcp,
            .w = ( i_mat.z.x * s3 - i_mat.z.y * s1 + i_mat.z.z * s0) * detRcp,
        }
    };
}

//-----------------------------------------------------------------------
Vec3f
mat3x3f_column
(
    Mat3x3f const i_mat,
    uint8_t const i_column
)
{
    return (Vec3f) {
        .x = i_mat.m[ ( 0u * 3u ) + i_column ],
        .y = i_mat.m[ ( 1u * 3u ) + i_column ],
        .z = i_mat.m[ ( 2u * 3u ) + i_column ],
    };
}

//-----------------------------------------------------------------------
Vec4f
mat4x4f_column
(
    Mat4x4f const i_mat,
    uint8_t const i_column
)
{
    return (Vec4f) {
        .x = i_mat.m[ ( 0u * 4u ) + i_column ],
        .y = i_mat.m[ ( 1u * 4u ) + i_column ],
        .z = i_mat.m[ ( 2u * 4u ) + i_column ],
        .w = i_mat.m[ ( 3u * 4u ) + i_column ],
    };
}

//-----------------------------------------------------------------------
Mat3x3f mat3x3f_mul
(
    Mat3x3f const i_a,
    Mat3x3f const i_b
)
{
    return (Mat3x3f) {
        .x = {
            .x = vec3f_dot( i_a.x, mat3x3f_column( i_b, 0u ) ),
            .y = vec3f_dot( i_a.x, mat3x3f_column( i_b, 1u ) ),
            .z = vec3f_dot( i_a.x, mat3x3f_column( i_b, 2u ) ),
        },
        .y = {
            .x = vec3f_dot( i_a.y, mat3x3f_column( i_b, 0u ) ),
            .y = vec3f_dot( i_a.y, mat3x3f_column( i_b, 1u ) ),
            .z = vec3f_dot( i_a.y, mat3x3f_column( i_b, 2u ) ),
        },
        .z = {
            .x = vec3f_dot( i_a.z, mat3x3f_column( i_b, 0u ) ),
            .y = vec3f_dot( i_a.z, mat3x3f_column( i_b, 1u ) ),
            .z = vec3f_dot( i_a.z, mat3x3f_column( i_b, 2u ) ),
        }
    };
}

//-----------------------------------------------------------------------
Mat4x4f mat4x4f_mul
(
    Mat4x4f const i_a,
    Mat4x4f const i_b
)
{
    Vec4f const bx = mat4x4f_column( i_b, 0u );
    Vec4f const by = mat4x4f_column( i_b, 1u );
    Vec4f const bz = mat4x4f_column( i_b, 2u );
    Vec4f const bw = mat4x4f_column( i_b, 3u );

    return (Mat4x4f) {
        .x = {
            .x = vec4f_dot( i_a.x, bx ),
            .y = vec4f_dot( i_a.x, by ),
            .z = vec4f_dot( i_a.x, bz ),
            .w = vec4f_dot( i_a.x, bw ),
        },
        .y = {
            .x = vec4f_dot( i_a.y, bx ),
            .y = vec4f_dot( i_a.y, by ),
            .z = vec4f_dot( i_a.y, bz ),
            .w = vec4f_dot( i_a.y, bw ),
        },
        .z = {
            .x = vec4f_dot( i_a.z, bx ),
            .y = vec4f_dot( i_a.z, by ),
            .z = vec4f_dot( i_a.z, bz ),
            .w = vec4f_dot( i_a.z, bw ),
        },
        .w = {
            .x = vec4f_dot( i_a.w, bx ),
            .y = vec4f_dot( i_a.w, by ),
            .z = vec4f_dot( i_a.w, bz ),
            .w = vec4f_dot( i_a.w, bw ),
        }
    };
}

//-----------------------------------------------------------------------
Vec3f mat3x3f_mul_vec
(
    Vec3f const i_vec,
    Mat3x3f const i_mat
)
{
    return (Vec3f) {
        .x = vec3f_dot( i_vec, mat3x3f_column( i_mat, 0u ) ),
        .y = vec3f_dot( i_vec, mat3x3f_column( i_mat, 1u ) ),
        .z = vec3f_dot( i_vec, mat3x3f_column( i_mat, 2u ) ),
    };
}

//-----------------------------------------------------------------------
Vec4f mat4x4f_mul_vec
(
    Vec4f const i_vec,
    Mat4x4f const i_mat
)
{
    return (Vec4f) {
        .x = vec4f_dot( i_vec, mat4x4f_column( i_mat, 0u ) ),
        .y = vec4f_dot( i_vec, mat4x4f_column( i_mat, 1u ) ),
        .z = vec4f_dot( i_vec, mat4x4f_column( i_mat, 2u ) ),
        .w = vec4f_dot( i_vec, mat4x4f_column( i_mat, 3u ) ),
    };
}

//-----------------------------------------------------------------------
Mat3x3f
mat3x3f_rotate_x
(
    float const i_angleInRadians
)
{
    float const s = sinf( i_angleInRadians );
    float const c = cosf( i_angleInRadians );

    return (Mat3x3f) {
        .x = { .x = 1.0f, .y = 0.0f, .z = 0.0f },
        .y = { .x = 0.0f, .y = +c, .z = -s },
        .z = { .x = 0.0f, .y = +s, .z = +c },
    };
}

//-----------------------------------------------------------------------
Mat4x4f
mat4x4f_lookat_lh
(
    Vec3f const i_position,
    Vec3f const i_direction,
    Vec3f const i_up
)
{
    Vec3f const axisZ = vec3f_normalise( i_direction );
    Vec3f const axisX = vec3f_normalise( vec3f_cross( i_up, axisZ ) );
    Vec3f const axisY = vec3f_normalise( vec3f_cross( axisZ, axisX ) );

    return (Mat4x4f) {
        .x = { .x = axisX.x, .y = axisY.x, .z = axisZ.x, .w = 0.0f },
        .y = { .x = axisX.y, .y = axisY.y, .z = axisZ.y, .w = 0.0f },
        .z = { .x = axisX.z, .y = axisY.z, .z = axisZ.z, .w = 0.0f },
        .w = { .x = -vec3f_dot( axisX, i_position ), .y = -vec3f_dot( axisY, i_position ), .z = -vec3f_dot( axisZ, i_position ), .w = 1.0f },
    };
}

//-----------------------------------------------------------------------
Mat4x4f
mat4x4f_perspective_lh
(
    float const i_aspectRatio,
    float const i_fovYInRadians,
    float const i_nearPlane,
    float const i_farPlane
)
{
    float const tanHalfFovY = tanf( i_fovYInRadians * 0.5f );
    float const m00 = 1.0f / ( tanHalfFovY * i_aspectRatio );
    float const m11 = 1.0f / ( tanHalfFovY );
    float const m22 = i_farPlane / ( i_farPlane - i_nearPlane );
    float const m23 = 1.0f;
    float const m32 = -i_farPlane / ( i_farPlane - i_nearPlane );

    return (Mat4x4f) {
        .x = { .x = m00,.y = 0.0f, .z = 0.0f, .w = 0.0f },
        .y = { .x = 0.0f, .y = m11, .z = 0.0f, .w = 0.0f },
        .z = { .x = 0.0f, .y = 0.0f, .z = m22,.w = m23 },
        .w = { .x = 0.0f, .y = 0.0f, .z = m32,.w = 0.0f },
    };
}

//-----------------------------------------------------------------------
Vec3f
mat4x4f_transform_position
(
    Mat4x4f const i_mat,
    Vec3f const i_vec
)
{
    Vec4f const pos = mat4x4f_mul_vec( (Vec4f) { .x = i_vec.x, .y = i_vec.y, .z = i_vec.z, .w = 1.0f }, i_mat );
    return (Vec3f) {
        .x = pos.x / pos.w,
        .y = pos.y / pos.w,
        .z = pos.z / pos.w
    };
}

//-----------------------------------------------------------------------
Vec3f
mat4x4f_transform_direction
(
    Mat4x4f const i_mat,
    Vec3f const i_vec
)
{
    Vec4f pos = mat4x4f_mul_vec( (Vec4f) { .x = i_vec.x, .y = i_vec.y, .z = i_vec.z, .w = 0.0f }, i_mat );
    return (Vec3f) { .x = pos.x, .y = pos.y, .z = pos.z };
}
