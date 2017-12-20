#pragma once

#include <array>
#include "Data00.h"

// pow constexpr function that never throws
constexpr int pow( int base, int exp ) noexcept
{
    return (exp == 0 ? 1 : base * pow( base, exp - 1 ));
}

//C+14
//constexpr int pow( int base, int exp ) noexcept
//{
//    auto result = 1;
//    for( int i = 0; i < exp; ++i )
//    {
//        result *= base;
//    }
//
//    return result;
//}

constexpr Point midPoint( const Point& p1, const Point& p2 )
{
    // call constexpr member function
    return { (p1.xValue() + p2.xValue()) / 2, (p1.yValue() + p2.yValue()) / 2 };
}

int main()
{
    int sz;                                 // non-constexpr variable
    //constexpr auto arraySize2 = sz;       // error!  sz value not known at compilation
    //std::array<int, sz> data1;            // error!  same problem
    constexpr auto arraySize2 = 10;         // fine 10 is a compile-time constant
    std::array<int, arraySize2> data2;      // fine, arraySize2 is constexpr

    //const auto arraySize = sz;            // books says fine but I am getting error
    //std::array<int, arraySize> data;      // error!  arraySize value not known at compilation

    constexpr auto numConds = 5;
    std::array<int, pow( 3, numConds )> results;    // results has 3 ^ numConds elements

    constexpr Point p1( 9.4, 27.7 );        // fine "runs" constexpr ctor during compilation
    constexpr Point p2( 28.8, 5.3);         // also fine

    // init constexpr object with result of constexpr function
    constexpr auto mid = midPoint( p1, p2 );

    return 0;
}
