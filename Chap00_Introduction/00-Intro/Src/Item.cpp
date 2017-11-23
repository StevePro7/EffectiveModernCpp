#pragma once

// C/C++ Lanugage | C++ Lanugage standard
#include <utility>

class Widget
{
public:
    Widget() {}

    // If not defined will get "attempting to reference a deleted function"
    Widget( Widget& lhs ) {}

    // rhs is an lvalue though it has an rvalue reference type
    Widget( Widget&& rhs ) {}
};

// These are C++ source code ellipses
template<typename... Ts>
void processVals( const Ts&... params )
{
}

// someFunc parameter w is passed by value
void someFunc( Widget w )
{
}

// Declarations
extern int x;                   // object declaration
class xWidget;                  // class declaration
bool xFunc( const xWidget& w ); // function declaration
enum class Color;               // scoped enum declaration

// Definitions
int x;                          // object definition
class yWidget                   // class definition
{
};

bool yFunc( const yWidget& w )  // function definition
{
    return true;
}

enum class Color                // scoped enum definition
{
    Yellow, Red, Blue
};

int main()
{
    // wid is some Widget
    Widget wid;

    // In this call to someFunc, w i s a copy of wid that's created via copy construction
    someFunc( wid );
    
    // In this call to someFunc, w i s a copy of wid that's created via move construction
    someFunc( std::move( wid ) );

    return 0;
}