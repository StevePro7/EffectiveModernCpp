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
        filters.emplace_back( [=]( int value ) {return value % divisor == 0; } );

        // error! divisor not available
        //filters.emplace_back( []( int value ) {return value % divisor == 0; } );

        // error! no local divisor to capture
        //filters.emplace_back( [divisor]( int value ) { return value % divisor == 0; } );
    }

    void addFilter2() const
    {
        auto currentObjectPtr = this;
        FilterContainer filters;
        filters.emplace_back( [currentObjectPtr]( int value ) { return value % currentObjectPtr->divisor == 0; } );
    }

private:
    int divisor;            // used in Widget's filter
};
