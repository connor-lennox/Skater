//
// Created by connor on 1/4/26.
//

#pragma once
#include <cmath>

#include "MathUtil.h"

namespace Skater {
    struct Vector4 {
        float X;
        float Y;
        float Z;
        float W;

        Vector4() : Vector4(0, 0, 0, 0) {}
        explicit Vector4(const float val) : Vector4(val, val, val, val) {}
        Vector4(const float x, const float y, const float z, const float w) : X(x), Y(y), Z(z), W(w) {}

        [[nodiscard]] bool Equals(const Vector4 other) const { return X == other.X && Y == other.Y && Z == other.Z && W == other.W; }

        Vector4 operator+(const Vector4 rhs) const { return Vector4(X + rhs.X, Y + rhs.Y, Z + rhs.Z, W + rhs.W); }
        Vector4 operator-(const Vector4 rhs) const { return Vector4(X - rhs.X, Y - rhs.Y, Z - rhs.Z, W - rhs.W); }
        Vector4 operator*(const Vector4 rhs) const { return Vector4(X * rhs.X, Y * rhs.Y, Z * rhs.Z, W * rhs.W); }
        Vector4 operator/(const Vector4 rhs) const { return Vector4(X / rhs.X, Y / rhs.Y, Z / rhs.Z, W / rhs.W); }

        bool operator==(const Vector4 rhs) const { return Equals(rhs); }
        bool operator!=(const Vector4 rhs) const { return !Equals(rhs); }

        // Unary minus
        Vector4 operator-() const { return Vector4(-X, -Y, -Z, -W); }

        static Vector4 Floor(const Vector4 vec) { return Vector4(std::floor(vec.X), std::floor(vec.Y), std::floor(vec.Z), std::floor(vec.W)); }
        Vector4 Floor() const { return Floor(*this); }

        static Vector4 Ceil(const Vector4 vec) { return Vector4(std::ceil(vec.X), std::ceil(vec.Y), std::ceil(vec.Z), std::ceil(vec.W)); }
        Vector4 Ceil() const { return Ceil(*this); }

        static float Length(const Vector4 vec) { return std::sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z + vec.W * vec.W); }
        float Length() const { return std::sqrt(X * X + Y * Y + Z * Z + W * W); }

        static float LengthSquared(const Vector4 vec) { return vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z + vec.W * vec.W; }
        float LengthSquared() const { return X * X + Y * Y + Z * Z + W * W; }

        static float DistanceSquared(const Vector4 lhs, const Vector4 rhs) {
            const float v1 = lhs.X - rhs.X, v2 = lhs.Y - rhs.Y, v3 = lhs.Z - rhs.Z, v4 = lhs.W - rhs.W;
            return v1 * v1 + v2 * v2 + v3 * v3 + v4 * v4;
        }
        float DistanceSquared(const Vector4 rhs) const { return DistanceSquared(*this, rhs); }

        static float Distance(const Vector4 lhs, const Vector4 rhs) {
            const float v1 = lhs.X - rhs.X, v2 = lhs.Y - rhs.Y, v3 = lhs.Z - rhs.Z, v4 = lhs.W - rhs.W;
            return std::sqrt(v1 * v1 + v2 * v2 + v3 * v3 + v4 * v4);
        }
        float Distance(const Vector4 rhs) const { return Distance(*this, rhs); }

        static float Dot(const Vector4 lhs, const Vector4 rhs) {
            return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z + lhs.W * rhs.W;
        }
        float Dot(const Vector4 rhs) const { return Dot(*this, rhs); }

        static Vector4 Normalized(const Vector4 vec) {
            const float val = 1.0f / std::sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z + vec.W * vec.W);
            return Vector4(vec.X * val, vec.Y * val, vec.Z * val, vec.W * val);
        }
        Vector4 Normalized() const {
            const float val = 1.0f / std::sqrt(X * X + Y * Y + Z * Z + W * W);
            return Vector4(X * val, Y * val, Z * val, W * val);
        }

        static Vector4 Lerp(const Vector4 lhs, const Vector4 rhs, const float t) {
            return Vector4(
                MathUtil::Lerp(lhs.X, rhs.X, t),
                MathUtil::Lerp(lhs.Y, rhs.Y, t),
                MathUtil::Lerp(lhs.Z, rhs.Z, t),
                MathUtil::Lerp(lhs.W, rhs.W, t)
            );
        }
        Vector4 Lerp(const Vector4 rhs, const float t) const {
            return Vector4(
                MathUtil::Lerp(X, rhs.X, t),
                MathUtil::Lerp(Y, rhs.Y, t),
                MathUtil::Lerp(Z, rhs.Z, t),
                MathUtil::Lerp(W, rhs.W, t)
            );
        }

        static const Vector4 Zero;
        static const Vector4 One;
    };

    inline const Vector4 Vector4::Zero(0);
    inline const Vector4 Vector4::One(1);
}
