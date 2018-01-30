#pragma once

class Widget
{
};

class PolyWidget
{
public:
    template<typename T>
    void operator()( const T& param )
    {
    }
};