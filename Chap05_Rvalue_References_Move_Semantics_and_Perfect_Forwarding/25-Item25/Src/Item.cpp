#pragma once

#include <string>
#include "Data00.h"
#include "Data01.h"


// factory function
std::string getWidgetName()
{
    return "name";
}

// "Copying" version of makeWidget()
Widget makeWidget1()
{
    // local variable
    Widget w;

    // "copy" w into return value
    return w;
}

// "Moving" version of makeWidget()
Widget makeWidget2()
{
    Widget w;

    // move w into return value (don't do this!)
    return std::move( w );

}

// by-value parameter of same type as function's return
Widget makeWidget3( Widget w )
{
    return w;
}

// Compilers must treat it as if it had been written this way:
Widget makeWidget( Widget w )
{
    // treat w as r-value
    return std::move( w );
}

int main()
{
    std::string name = getWidgetName();
    Widget w;

    // n is local variable
    auto n = getWidgetName();

    // moves n into w!
    // n value is now unknown
    w.setName( n );

    return 0;
}
