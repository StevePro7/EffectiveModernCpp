#pragma once

#include <functional>
#include <vector>

using FilterContainer = std::vector<std::function<bool( int )>>;

class Widget
{
public:
    void addFilter() const
    {
        FilterContainer filters;
        auto divisorCopy = divisor;

        // capture the copy and use the copy
        filters.emplace_back( [divisorCopy]( int value ) {return value % divisorCopy == 0; } );

        filters.emplace_back( [=]( int value ) {return value % divisorCopy == 0; } );

        // C++14 copy divisor to closure and use the copy
        filters.emplace_back( [divisor = divisor]( int value ) { return value % divisor == 0; } );
    }

private:
    int divisor;            // used in Widget's filter
};
