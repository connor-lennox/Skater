//
// Created by connor on 12/30/25.
//

#pragma once
#include <cmath>

#include "MathUtil.h"

namespace Skater {
    struct Vector2 {
        float X;
        float Y;

        Vector2() : Vector2(0, 0) {}
        Vector2(const float x, const float y) : X(x), Y(y) {}

        bool Equals(const Vector2 other) const { return X == other.X && Y == other.Y; }

        Vector2 operator+(const Vector2 rhs) const { return Vector2(X + rhs.X, Y + rhs.Y); }
        Vector2 operator-(const Vector2 rhs) const { return Vector2(X - rhs.X, Y - rhs.Y); }
        Vector2 operator*(const Vector2 rhs) const { return Vector2(X * rhs.X, Y * rhs.Y); }
        Vector2 operator/(const Vector2 rhs) const { return Vector2(X / rhs.X, Y / rhs.Y); }

        bool operator==(const Vector2 rhs) const { return Equals(rhs); }
        bool operator!=(const Vector2 rhs) const { return !Equals(rhs); }

        // Unary minus
        Vector2 operator-() const { return Vector2(-X, -Y); }

        static Vector2 Floor(const Vector2 vec) { return Vector2(std::floor(vec.X), std::floor(vec.Y)); }
        Vector2 Floor() const { return Floor(*this); }

        static Vector2 Ceil(const Vector2 vec) { return Vector2(std::ceil(vec.X), std::ceil(vec.Y)); }
        Vector2 Ceil() const { return Ceil(*this); }

        static float Length(const Vector2 vec) { return std::sqrt(vec.X * vec.X + vec.Y * vec.Y); }
        float Length() const { return std::sqrt(X * X + Y * Y); }

        static float LengthSquared(const Vector2 vec) { return vec.X * vec.X + vec.Y * vec.Y; }
        float LengthSquared() const { return X * X + Y * Y; }

        static float DistanceSquared(const Vector2 lhs, const Vector2 rhs) {
            const float v1 = lhs.X - rhs.X, v2 = lhs.Y - rhs.Y;
            return v1 * v1 + v2 * v2;
        }
        float DistanceSquared(const Vector2 rhs) const { return DistanceSquared(*this, rhs); }

        static float Distance(const Vector2 lhs, const Vector2 rhs) {
            const float v1 = lhs.X - rhs.X, v2 = lhs.Y - rhs.Y;
            return std::sqrt(v1 * v1 + v2 * v2);
        }
        float Distance(const Vector2 rhs) const { return Distance(*this, rhs); }

        static float Dot(const Vector2 lhs, const Vector2 rhs) {
            return (lhs.X * rhs.X) + lhs.Y * rhs.Y;
        }
        float Dot(const Vector2 rhs) const { return Dot(*this, rhs); }

        static Vector2 Normalized(const Vector2 vec) {
            const float val = 1.0f / std::sqrt(vec.X * vec.X + vec.Y * vec.Y);
            return Vector2(vec.X * val, vec.Y * val);
        }
        Vector2 Normalized() const {
            const float val = 1.0f / std::sqrt(X * X + Y * Y);
            return Vector2(X * val, Y * val);
        }

        static Vector2 Lerp(const Vector2 lhs, const Vector2 rhs, const float t) {
            return Vector2(MathUtil::Lerp(lhs.X, rhs.X, t), MathUtil::Lerp(lhs.Y, rhs.Y, t));
        }
        Vector2 Lerp(const Vector2 rhs, const float t) const {
            return Vector2(MathUtil::Lerp(X, rhs.X, t), MathUtil::Lerp(Y, rhs.Y, t));
        }

        static const Vector2 Zero;
        static const Vector2 One;
    };

    inline const Vector2 Vector2::Zero(0, 0);
    inline const Vector2 Vector2::One(1, 1);
}
