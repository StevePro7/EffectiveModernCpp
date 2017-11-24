#pragma once

#include <cstddef>

class Widget {};

// decltype(i)      const int
const int i = 0;

// decltype(w)      const Widget&
// decltype(f)      bool(const Widget&)
bool f( const Widget& w )
{
    return true;
}

// decltype(Point::x)   int
// decltype(Point::y)   int
struct Point
{
    int x, y;
};

template<typename T>
class myVector
{
public:
    T& operator[]( std::size_t index )
    {
        int x = 7;
        return x;
    }
};

int main()
{
    myVector<int> v;        // decltype(v)      vector<int>
    if( v[0] == 0 )         // decltype(v[0]    int&
    {
    }
    return 0;
}