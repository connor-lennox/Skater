//
// Created by connor on 1/4/26.
//

#pragma once
#include "Vector2.h"

namespace Skater {
    /// Row-Major 4x4 Matrix
    struct Matrix4 {
        float Elements[16] {};

        Matrix4(
            const float m11, const float m12, const float m13, const float m14,
            const float m21, const float m22, const float m23, const float m24,
            const float m31, const float m32, const float m33, const float m34,
            const float m41, const float m42, const float m43, const float m44
        ) : Elements(m11, m12, m13, m14, m21, m22, m23, m24, m31, m32, m33, m34, m41, m42, m43, m44) {}

        Matrix4 operator+(const Matrix4 rhs) const {
            return Matrix4(
                Elements[0] + rhs.Elements[0], Elements[1] + rhs.Elements[1], Elements[2] + rhs.Elements[2], Elements[3] + rhs.Elements[3],
                Elements[4] + rhs.Elements[4], Elements[5] + rhs.Elements[5], Elements[6] + rhs.Elements[6], Elements[7] + rhs.Elements[7],
                Elements[8] + rhs.Elements[8], Elements[9] + rhs.Elements[9], Elements[10] + rhs.Elements[10], Elements[11] + rhs.Elements[11],
                Elements[12] + rhs.Elements[12], Elements[13] + rhs.Elements[13], Elements[14] + rhs.Elements[14], Elements[15] + rhs.Elements[15]
            );
        }

        Matrix4 operator-(const Matrix4 rhs) const {
            return Matrix4(
                Elements[0] - rhs.Elements[0], Elements[1] - rhs.Elements[1], Elements[2] - rhs.Elements[2], Elements[3] - rhs.Elements[3],
                Elements[4] - rhs.Elements[4], Elements[5] - rhs.Elements[5], Elements[6] - rhs.Elements[6], Elements[7] - rhs.Elements[7],
                Elements[8] - rhs.Elements[8], Elements[9] - rhs.Elements[9], Elements[10] - rhs.Elements[10], Elements[11] - rhs.Elements[11],
                Elements[12] - rhs.Elements[12], Elements[13] - rhs.Elements[13], Elements[14] - rhs.Elements[14], Elements[15] - rhs.Elements[15]
            );
        }

        Matrix4 operator*(const Matrix4 rhs) const {
            const auto m11 = Elements[0] * rhs.Elements[0] + Elements[1] * rhs.Elements[4] + Elements[2] * rhs.Elements[8] + Elements[3] * rhs.Elements[12];
            const auto m12 = Elements[0] * rhs.Elements[1] + Elements[1] * rhs.Elements[5] + Elements[2] * rhs.Elements[9] + Elements[3] * rhs.Elements[13];
            const auto m13 = Elements[0] * rhs.Elements[2] + Elements[1] * rhs.Elements[6] + Elements[2] * rhs.Elements[10] + Elements[3] * rhs.Elements[14];
            const auto m14 = Elements[0] * rhs.Elements[3] + Elements[1] * rhs.Elements[7] + Elements[2] * rhs.Elements[11] + Elements[3] * rhs.Elements[15];
            const auto m21 = Elements[4] * rhs.Elements[0] + Elements[5] * rhs.Elements[4] + Elements[6] * rhs.Elements[8] + Elements[7] * rhs.Elements[12];
            const auto m22 = Elements[4] * rhs.Elements[1] + Elements[5] * rhs.Elements[5] + Elements[6] * rhs.Elements[9] + Elements[7] * rhs.Elements[13];
            const auto m23 = Elements[4] * rhs.Elements[2] + Elements[5] * rhs.Elements[6] + Elements[6] * rhs.Elements[10] + Elements[7] * rhs.Elements[14];
            const auto m24 = Elements[4] * rhs.Elements[3] + Elements[5] * rhs.Elements[7] + Elements[6] * rhs.Elements[11] + Elements[7] * rhs.Elements[15];
            const auto m31 = Elements[8] * rhs.Elements[0] + Elements[9] * rhs.Elements[4] + Elements[10] * rhs.Elements[8] + Elements[11] * rhs.Elements[12];
            const auto m32 = Elements[8] * rhs.Elements[1] + Elements[9] * rhs.Elements[5] + Elements[10] * rhs.Elements[9] + Elements[11] * rhs.Elements[13];
            const auto m33 = Elements[8] * rhs.Elements[2] + Elements[9] * rhs.Elements[6] + Elements[10] * rhs.Elements[10] + Elements[11] * rhs.Elements[14];
            const auto m34 = Elements[8] * rhs.Elements[3] + Elements[9] * rhs.Elements[7] + Elements[10] * rhs.Elements[11] + Elements[11] * rhs.Elements[15];
            const auto m41 = Elements[12] * rhs.Elements[0] + Elements[13] * rhs.Elements[4] + Elements[14] * rhs.Elements[8] + Elements[15] * rhs.Elements[12];
            const auto m42 = Elements[12] * rhs.Elements[1] + Elements[13] * rhs.Elements[5] + Elements[14] * rhs.Elements[9] + Elements[15] * rhs.Elements[13];
            const auto m43 = Elements[12] * rhs.Elements[2] + Elements[13] * rhs.Elements[6] + Elements[14] * rhs.Elements[10] + Elements[15] * rhs.Elements[14];
           	const auto m44 = Elements[12] * rhs.Elements[3] + Elements[13] * rhs.Elements[7] + Elements[14] * rhs.Elements[11] + Elements[15] * rhs.Elements[15];

            return Matrix4(
                m11, m12, m13, m14,
                m21, m22, m23, m24,
                m31, m32, m33, m34,
                m41, m42, m43, m44
            );
        }

        Matrix4 operator*(const float rhs) const {
            return Matrix4(
                Elements[0] * rhs, Elements[1] * rhs, Elements[2] * rhs, Elements[3] * rhs,
                Elements[4] * rhs, Elements[5] * rhs, Elements[6] * rhs, Elements[7] * rhs,
                Elements[8] * rhs, Elements[9] * rhs, Elements[10] * rhs, Elements[11] * rhs,
                Elements[12] * rhs, Elements[13] * rhs, Elements[14] * rhs, Elements[15] * rhs
            );
        }

        static Matrix4 CreateOrthographic(const float width, const float height, const float zNearPlane, const float zFarPlane) {
            return Matrix4(
                2.0f / width, 0, 0, 0,
                0, 2.0f / height, 0, 0,
                0, 0, 1.0f / (zNearPlane - zFarPlane), 0,
                0, 0, zNearPlane / (zNearPlane - zFarPlane), 1
            );
        }

        static Matrix4 CreateTranslation(const Vector2 position) {
            return Matrix4(
                1, 0, 0, 0,
                0, 1, 0, 0,
                0, 0, 1, 0,
                position.X, position.Y, 0, 1
            );
        }

        static Matrix4 CreateScale(const float scale) {
            return CreateScale(scale, scale);
        }

        static Matrix4 CreateScale(const float xScale, const float yScale) {
            return Matrix4(
                xScale, 0, 0, 0,
                0, yScale, 0, 0,
                0, 0, 1, 0,
                0, 0, 0, 1
            );
        }
    };
}
