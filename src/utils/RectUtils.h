#pragma once

#include "Types.h"

namespace Utils {
    static bool isIntersecting(const Rect& a, const Rect& b) noexcept
    {
        return (a.x + a.w) >= b.x && a.x <= (b.x + b.w) && (a.y + a.h) >= b.y && a.y <= (b.y + b.h);
        /* If the top right corner of rectangle a is greater than or equal to the top left corner of rectangle b
         * and the top left corner of rectangle a is less than or equal to the top right corner of rectangle b
         * and the bottom left corner of rectangle a is greater than or equal to the top left corner of rectangle b
         * and the top left corner of rectangle a is less than or equal to the bottom left corner of rectangle b
         * them a collision has occurred. */
    }
} // NS Utils::Rect