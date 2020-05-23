#pragma once

//#include "Data01.h"
//#include "Data03.h"
#include "Data04.h"
#include "Data05.h"
#include <memory>

using FilterContainer = std::vector<std::function<bool( int )>>;

void doSomeWork()
{
    auto pw = std::make_unique<Widget>();

    // add filter that uses Widget::divisor
    pw->addFilter();

    // destroy Widget; filters now holds dangling pointer!
}

int main()
{
    FilterContainer filters;
    filters.emplace_back( []( int value ) {return value % 5 == 0; } );

    return 0;
}
