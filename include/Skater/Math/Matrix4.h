//
// Created by connor on 1/4/26.
//

#pragma once

namespace Skater {
    struct Matrix4 {
        float M11, M12, M13, M14,
              M21, M22, M23, M24,
              M31, M32, M33, M34,
              M41, M42, M43, M44;

        Matrix4(
            const float m11, const float m12, const float m13, const float m14,
            const float m21, const float m22, const float m23, const float m24,
            const float m31, const float m32, const float m33, const float m34,
            const float m41, const float m42, const float m43, const float m44
        ) :
            M11(m11), M12(m12), M13(m13), M14(m14), M21(m21), M22(m22), M23(m23), M24(m24), M31(m31),
                M32(m32), M33(m33), M34(m34), M41(m41), M42(m42), M43(m43), M44(m44) {}

        Matrix4 operator+(const Matrix4 rhs) const {
            return Matrix4(
                M11 + rhs.M11, M12 + rhs.M12, M13 + rhs.M13, M14 + rhs.M14,
                M21 + rhs.M21, M22 + rhs.M22, M23 + rhs.M23, M24 + rhs.M24,
                M31 + rhs.M31, M32 + rhs.M32, M33 + rhs.M33, M34 + rhs.M34,
                M41 + rhs.M41, M42 + rhs.M42, M43 + rhs.M43, M44 + rhs.M44
            );
        }

        Matrix4 operator-(const Matrix4 rhs) const {
            return Matrix4(
                M11 - rhs.M11, M12 - rhs.M12, M13 - rhs.M13, M14 - rhs.M14,
                M21 - rhs.M21, M22 - rhs.M22, M23 - rhs.M23, M24 - rhs.M24,
                M31 - rhs.M31, M32 - rhs.M32, M33 - rhs.M33, M34 - rhs.M34,
                M41 - rhs.M41, M42 - rhs.M42, M43 - rhs.M43, M44 - rhs.M44
            );
        }

        Matrix4 operator*(const Matrix4 rhs) const {
            const auto m11 = M11 * rhs.M11 + M12 * rhs.M21 + M13 * rhs.M31 + M14 * rhs.M41;
            const auto m12 = M11 * rhs.M12 + M12 * rhs.M22 + M13 * rhs.M32 + M14 * rhs.M42;
            const auto m13 = M11 * rhs.M13 + M12 * rhs.M23 + M13 * rhs.M33 + M14 * rhs.M43;
            const auto m14 = M11 * rhs.M14 + M12 * rhs.M24 + M13 * rhs.M34 + M14 * rhs.M44;
            const auto m21 = M21 * rhs.M11 + M22 * rhs.M21 + M23 * rhs.M31 + M24 * rhs.M41;
            const auto m22 = M21 * rhs.M12 + M22 * rhs.M22 + M23 * rhs.M32 + M24 * rhs.M42;
            const auto m23 = M21 * rhs.M13 + M22 * rhs.M23 + M23 * rhs.M33 + M24 * rhs.M43;
            const auto m24 = M21 * rhs.M14 + M22 * rhs.M24 + M23 * rhs.M34 + M24 * rhs.M44;
            const auto m31 = M31 * rhs.M11 + M32 * rhs.M21 + M33 * rhs.M31 + M34 * rhs.M41;
            const auto m32 = M31 * rhs.M12 + M32 * rhs.M22 + M33 * rhs.M32 + M34 * rhs.M42;
            const auto m33 = M31 * rhs.M13 + M32 * rhs.M23 + M33 * rhs.M33 + M34 * rhs.M43;
            const auto m34 = M31 * rhs.M14 + M32 * rhs.M24 + M33 * rhs.M34 + M34 * rhs.M44;
            const auto m41 = M41 * rhs.M11 + M42 * rhs.M21 + M43 * rhs.M31 + M44 * rhs.M41;
            const auto m42 = M41 * rhs.M12 + M42 * rhs.M22 + M43 * rhs.M32 + M44 * rhs.M42;
            const auto m43 = M41 * rhs.M13 + M42 * rhs.M23 + M43 * rhs.M33 + M44 * rhs.M43;
           	const auto m44 = M41 * rhs.M14 + M42 * rhs.M24 + M43 * rhs.M34 + M44 * rhs.M44;

            return Matrix4(
                m11, m12, m13, m14,
                m21, m22, m23, m24,
                m31, m32, m33, m34,
                m41, m42, m43, m44
            );
        }

        Matrix4 operator*(const float rhs) const {
            return Matrix4(
                M11 * rhs, M12 * rhs, M13 * rhs, M14 * rhs,
                M21 * rhs, M22 * rhs, M23 * rhs, M24 * rhs,
                M31 * rhs, M32 * rhs, M33 * rhs, M34 * rhs,
                M41 * rhs, M42 * rhs, M43 * rhs, M44 * rhs
            );
        }
    };
}
