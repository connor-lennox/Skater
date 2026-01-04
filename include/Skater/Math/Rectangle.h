//
// Created by connor on 12/30/25.
//

#pragma once
#include <cstdint>

#include "Point.h"

namespace Skater {
    struct Rectangle {
        uint32_t X;
        uint32_t Y;
        uint32_t Width;
        uint32_t Height;

        [[nodiscard]] uint32_t Left() const { return X; }
        [[nodiscard]] uint32_t Right() const { return X + Width; }
        [[nodiscard]] uint32_t Top() const { return Y; }
        [[nodiscard]] uint32_t Bottom() const { return Y + Height; }

        [[nodiscard]] Point Location() const { return Point(X, Y); }
        [[nodiscard]] Point Size() const { return Point(Width, Height); }
        [[nodiscard]] Point Center() const { return Point(X + Width / 2, Y + Height / 2); }

        [[nodiscard]] bool Equals(const Rectangle other) const { return X == other.X && Y == other.Y && Width == other.Width && Height == other.Height; }

        bool operator==(const Rectangle rhs) const { return Equals(rhs); }
        bool operator!=(const Rectangle rhs) const { return !Equals(rhs); }

        [[nodiscard]] bool Contains(const uint32_t x, const uint32_t y) const {
            return this->X <= x && x < (this->X + this->Width) && this->Y <= y && y < (this->Y + this->Height);
        }

        [[nodiscard]] bool Contains(const Point point) const { return Contains(point.X, point.Y); }

        [[nodiscard]] bool IsEmpty() const { return X == 0 && Y == 0 && Width == 0 && Height == 0; }

        [[nodiscard]] Rectangle Offset(const Point offset) const { return Rectangle(X + offset.X, Y + offset.Y, Width, Height); }

        static Rectangle CenterRectangle(const Rectangle outer, const Rectangle inner) {
            auto delta = outer.Center() - inner.Center();
            return inner.Offset(delta);
        }

        static const Rectangle Empty;
    };

    inline const Rectangle Rectangle::Empty(0, 0, 0, 0);
}
