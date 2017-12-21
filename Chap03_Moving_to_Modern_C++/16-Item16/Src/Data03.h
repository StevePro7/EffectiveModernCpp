#pragma once

#include <mutex>

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
        std::lock_guard<std::mutex> guard( m );     // lock m

        if( cacheValid )
        {
            return cachedValue;
        }
        else
        {
            auto va11 = expensiveComputation1();
            auto va12 = expensiveComputation2();
            cachedValue = va11 + va12;
            cacheValid = true;
            return cachedValue;
        }
    };                                              // unlock

private:
    mutable std::mutex m;
    mutable int cachedValue;            // no longer atomic
    mutable bool cacheValid{ false };   // no longer atomic
};