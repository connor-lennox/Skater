//
// Created by connor on 12/30/25.
//

#pragma once
#include <cstdint>

namespace Skater {
    struct Point {
        uint32_t X;
        uint32_t Y;

        Point() : Point(0, 0) {}
        Point(const uint32_t x, const uint32_t y) : X(x), Y(y) {}

        bool Equals(const Point other) const { return X == other.X && Y == other.Y; }

        Point operator+(const Point rhs) const { return Point(X + rhs.X, Y + rhs.Y); }
        Point operator-(const Point rhs) const { return Point(X - rhs.X, Y - rhs.Y); }
        Point operator*(const Point rhs) const { return Point(X * rhs.X, Y * rhs.Y); }
        Point operator/(const Point rhs) const { return Point(X / rhs.X, Y * rhs.Y); }

        bool operator==(const Point rhs) const { return Equals(rhs); }
        bool operator!=(const Point rhs) const { return !Equals(rhs); }

        // Unary minus
        Point operator-() const { return Point(-X, -Y); }
    };
}
