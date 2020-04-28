#pragma once

#include "Types.h"

namespace Utils {
    static bool isIntersecting(const Rect& a, const Rect& b) noexcept
    {
        return (a.x + a.w) >= b.x && a.x <= (b.x + b.w) && (a.y + a.h) >= b.y && a.y <= (b.y + b.h);
    }
} // NS Utils::Rect