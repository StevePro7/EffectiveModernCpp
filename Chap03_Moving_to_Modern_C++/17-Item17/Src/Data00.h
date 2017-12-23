#pragma once

class Widget
{
public:
    Widget() {}
    ~Widget() {}                // user declared dtor

    // default copy ctor
    Widget( const Widget& rhs ) = default;

    // default copy assign
    Widget& operator=( const Widget& ) = default;

    // move ctor
    Widget( Widget&& rhs ) {}

    // move assignment operator
    Widget& operator=( Widget&& rhs )
    {
        return *this;
    }

    // construct Widget from anything
    template<typename T>
    Widget( const T& rhs ) {}

    // assign Widget from anything
    template<typename T>
    Widget& operator=( const T& rhs )
    {
        return *this;
    }
};