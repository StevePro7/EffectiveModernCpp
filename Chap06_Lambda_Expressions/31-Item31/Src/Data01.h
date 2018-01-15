#pragma once

#include <functional>
#include <vector>

using FilterContainer = std::vector<std::function<bool( int )>>;

int computerDivisor( int c1, int c2 )
{
    return c1 / c2;
}

void addDivisorFilter()
{
    auto calc1 = 20;    // computerSomeValue1();
    auto calc2 = 10;    // computerSomeValue2();

    auto divisor = computerDivisor( calc1, calc2 );

    // danger! ref to divisor will dangle!
    FilterContainer filters;
    filters.emplace_back( [&]( int value ) { return value % divisor == 0; } );
}