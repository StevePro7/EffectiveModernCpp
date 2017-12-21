#pragma once

#include <atomic>
#include <cmath>

class Point
{
public:
    double distanceFromOrigin() const noexcept
    {
        ++callCount;        // atomic increment
        return std::sqrt( (x * x) + (y * y) );;
    }

private:
    mutable std::atomic<unsigned> callCount{ 0 };
    double x, y;
};