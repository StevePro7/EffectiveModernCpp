#pragma once

#include <cstddef>
#include <deque>
#include <string>

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

void authenticateUser()
{
}

// works but requires refinement
template<typename Container, typename Index>
auto authAndAccess( Container& c, Index i ) -> decltype(c[i])
{
    authenticateUser();
    return c[i];
}

// C++14 but not quite correct
template<typename Container, typename Index>
auto authAndAccess2( Container& c, Index i )
{
    authenticateUser();
    return c[i];
}

// C++14 works but still requires refinement
template<typename Container, typename Index>
decltype(auto) authAndAccess3( Container& c, Index i )
{
    authenticateUser();
    return c[i];
}

// Factory function
std::deque<std::string> makeStringDeque()
{
    std::deque<std::string> queue;
    return queue;
}

// c is now a universal reference
template<typename Container, typename Index>
decltype(auto) authAndAccess4( Container&& c, Index i )
{
    authenticateUser();
    return std::forward<Container>( c )[i];
}
// C++11 version
template<typename Container, typename Index>
auto authAndAccess5( Container&& c, Index i ) -> decltype(std::forward<Container>( c )[i])
{
    authenticateUser();
    return std::forward<Container>( c )[i];
}

int main()
{
    myVector<int> v;                // decltype(v)      vector<int>
    if( v[0] == 0 )                 // decltype(v[0]    int&
    {
    }

    // authenticateUser             return d[5] then assign 10 to it
    std::deque<int> d;
    //authAndAccess2( d, 5 ) = 10;    // authenticate user    return d[5] then assign 10  won't compile!

    Widget w;                       // Widget
    const Widget& cw = w;           // const Widget &
    auto myWidget1 = cw;            // auto type deduction      Widget
    decltype(auto) myWidget2 = cw;  // decltype type deduction  const Widget &

    std::deque<std::string> queue = makeStringDeque();
    // make copy of 5th element of deque returned from makeStringDeque
    //auto s = authAndAccess3( makeStringDeque(), 5 );                    //    subscript out of range
    //auto s = authAndAccess4( makeStringDeque(), 5 );                    //    subscript out of range
    // could not understand how to call the version 4 without runtime error!

    return 0;
}
