#include "catch.hpp"

#include "Types.h"
#include "utils/RectangleHelper.h"

TEST_CASE("Test intersecting", "[utils]")
{
    Rect r1 { 0, 0, 100, 100};
    Rect r2 { 50, 50, 50, 50};

    REQUIRE(Utils::isIntersecting(r1, r2));
}

TEST_CASE("Test non intersecting", "[utils]")
{
    Rect r1 { 0, 0, 100, 100};
    Rect r2 { 200, 200, 100, 100};

    REQUIRE(!Utils::isIntersecting(r1, r2));
}

TEST_CASE("Test Contain", "[utils]")
{
    Rect  r { 0, 0, 100, 100};
    Point p { 50, 50 };

    REQUIRE(Utils::contains(r, p, 10));
}

TEST_CASE("Test doesn't contain", "[utils]")
{
    Rect  r { 0, 0, 100, 100};
    Point p { 200, 50 };

    REQUIRE(!Utils::contains(r, p, 10));
}

TEST_CASE("Test IntersectionDepth", "[utils]")
{
    Rect r1 { 25, 0, 50, 50};
    Rect r2 { 50, 0, 50, 50};

    const Point p = Utils::intersectingDepth(r1, r2);
    REQUIRE(p.x == -25);
    REQUIRE(p.y == -50);
}

TEST_CASE("Test Non IntersectionDepth", "[utils]")
{
    Rect r1 { 100, 100, 50, 50};
    Rect r2 { 0, 0, 50, 50};

    const Point p = Utils::intersectingDepth(r1, r2);
    REQUIRE(p.x == 0);
    REQUIRE(p.y == 0);
}