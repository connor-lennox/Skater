//
// Created by connor on 1/4/26.
//

#pragma once
#include <cmath>

#include "MathUtil.h"


namespace Skater {
    struct Vector3 {
        float X;
        float Y;
        float Z;

        Vector3() : Vector3(0, 0, 0) {}
        explicit Vector3(const float val) : Vector3(val, val, val) {}
        Vector3(const float x, const float y, const float z) : X(x), Y(y), Z(z) {}

        [[nodiscard]] bool Equals(const Vector3 other) const { return X == other.X && Y == other.Y && Z == other.Z; }

        Vector3 operator+(const Vector3 rhs) const { return Vector3(X + rhs.X, Y + rhs.Y, Z + rhs.Z); }
        Vector3 operator-(const Vector3 rhs) const { return Vector3(X - rhs.X, Y - rhs.Y, Z - rhs.Z); }
        Vector3 operator*(const Vector3 rhs) const { return Vector3(X * rhs.X, Y * rhs.Y, Z * rhs.Z); }
        Vector3 operator/(const Vector3 rhs) const { return Vector3(X / rhs.X, Y / rhs.Y, Z / rhs.Z); }

        bool operator==(const Vector3 rhs) const { return Equals(rhs); }
        bool operator!=(const Vector3 rhs) const { return !Equals(rhs); }

        // Unary minus
        Vector3 operator-() const { return Vector3(-X, -Y, -Z); }

        static Vector3 Floor(const Vector3 vec) { return Vector3(std::floor(vec.X), std::floor(vec.Y), std::floor(vec.Z)); }
        Vector3 Floor() const { return Floor(*this); }

        static Vector3 Ceil(const Vector3 vec) { return Vector3(std::ceil(vec.X), std::ceil(vec.Y), std::ceil(vec.Z)); }
        Vector3 Ceil() const { return Ceil(*this); }

        static float Length(const Vector3 vec) { return std::sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z); }
        float Length() const { return std::sqrt(X * X + Y * Y + Z * Z); }

        static float LengthSquared(const Vector3 vec) { return vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z; }
        float LengthSquared() const { return X * X + Y * Y + Z * Z; }

        static float DistanceSquared(const Vector3 lhs, const Vector3 rhs) {
            const float v1 = lhs.X - rhs.X, v2 = lhs.Y - rhs.Y, v3 = lhs.Z - rhs.Z;
            return v1 * v1 + v2 * v2 + v3 * v3;
        }
        float DistanceSquared(const Vector3 rhs) const { return DistanceSquared(*this, rhs); }

        static float Distance(const Vector3 lhs, const Vector3 rhs) {
            const float v1 = lhs.X - rhs.X, v2 = lhs.Y - rhs.Y, v3 = lhs.Z - rhs.Z;
            return std::sqrt(v1 * v1 + v2 * v2 + v3 * v3);
        }
        float Distance(const Vector3 rhs) const { return Distance(*this, rhs); }

        static float Dot(const Vector3 lhs, const Vector3 rhs) {
            return lhs.X * rhs.X + lhs.Y * rhs.Y + lhs.Z * rhs.Z;
        }
        float Dot(const Vector3 rhs) const { return Dot(*this, rhs); }

        static Vector3 Normalized(const Vector3 vec) {
            const float val = 1.0f / std::sqrt(vec.X * vec.X + vec.Y * vec.Y + vec.Z * vec.Z);
            return Vector3(vec.X * val, vec.Y * val, vec.Z * val);
        }
        Vector3 Normalized() const {
            const float val = 1.0f / std::sqrt(X * X + Y * Y + Z * Z);
            return Vector3(X * val, Y * val, Z * val);
        }

        static Vector3 Lerp(const Vector3 lhs, const Vector3 rhs, const float t) {
            return Vector3(
                MathUtil::Lerp(lhs.X, rhs.X, t),
                MathUtil::Lerp(lhs.Y, rhs.Y, t),
                MathUtil::Lerp(lhs.Z, rhs.Z, t)
            );
        }
        Vector3 Lerp(const Vector3 rhs, const float t) const {
            return Vector3(
                MathUtil::Lerp(X, rhs.X, t),
                MathUtil::Lerp(Y, rhs.Y, t),
                MathUtil::Lerp(Z, rhs.Z, t)
            );
        }

        static const Vector3 Zero;
        static const Vector3 One;
    };

    inline const Vector3 Vector3::Zero(0);
    inline const Vector3 Vector3::One(1);
}
