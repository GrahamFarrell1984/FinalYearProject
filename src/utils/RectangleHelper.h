#pragma once

#include "Types.h"

namespace Utils {
    static bool contains(const Rect& r, const Point& p, const int32_t offset) {
        return p.x > r.x - offset && p.x < r.x + r.w + offset && p.y > r.y - offset && p.y < r.y + r.h + offset;
    }

    static bool isIntersecting(const Rect& a, const Rect& b) noexcept {
        return (a.x + a.w) >= b.x && a.x <= (b.x + b.w) && (a.y + a.h) >= b.y && a.y <= (b.y + b.h);
        /* If the top right corner of rectangle a is greater than or equal to the top left corner of rectangle b
         * and the top left corner of rectangle a is less than or equal to the top right corner of rectangle b
         * and the bottom left corner of rectangle a is greater than or equal to the top left corner of rectangle b
         * and the top left corner of rectangle a is less than or equal to the bottom left corner of rectangle b
         * them a collision has occurred. */
    }

    static Point intersectingDepth(const Rect& a, const Rect& b) noexcept {

        // Calculate centers.
        Point centerA { a.x + a.w  / 2, a.y + a.h / 2 };
        Point centerB { b.x + b.w  / 2, b.y + a.h / 2 };

        // Calculate current and minimum-non-intersecting distances between centers.
        int32_t distanceX = centerA.x - centerB.x;
        int32_t distanceY = centerA.y - centerB.y;
        int32_t minDistanceX = (a.w + b.w)  / 2;
        int32_t minDistanceY = (a.h + b.h)  / 2;

        // If we are not intersecting at all, return (0, 0).
        if (std::abs(distanceX) >= minDistanceX || std::abs(distanceY) >= minDistanceY)
            return Point{ 0, 0 };

        return Point {
                distanceX > 0 ? minDistanceX - distanceX : -minDistanceX - distanceX,
                distanceY > 0 ? minDistanceY - distanceY : -minDistanceY - distanceY
        };
    }
} // NS Utils::Rect