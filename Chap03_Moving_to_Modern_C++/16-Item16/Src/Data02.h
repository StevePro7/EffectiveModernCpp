#pragma once

#include <atomic>

int expensiveComputation1()
{
    return 1;
}
int expensiveComputation2()
{
    return 0;
}

class Widget
{
public:
    int magicValue() const
    {
        if( cacheValid )
        {
            return cachedValue;
        }
        else
        {
            auto va11 = expensiveComputation1();
            auto va12 = expensiveComputation2();
            cachedValue = va11 + va12;              // uh oh, part1
            cacheValid = true;                      // uh oh, part2
            return cachedValue;
        }
    };

private:
    mutable std::atomic<bool> cacheValid{ false };
    mutable std::atomic<int> cachedValue;
};