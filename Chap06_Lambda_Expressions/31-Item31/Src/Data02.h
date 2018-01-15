#pragma once

#include <functional>
#include <vector>

using FilterContainer = std::vector<std::function<bool( int )>>;

int computerDivisor( int c1, int c2 )
{
    return c1 / c2;
}

template<typename C>
void workWithContainer( const C& container )
{
    auto calc1 = 20;    // computerSomeValue1();
    auto calc2 = 10;    // computerSomeValue2();

    auto divisor = computerDivisor( calc1, calc2 );

    // type of elements in container
    using ContElemT = typename C::value_type;

    using std::begin;
    using std::end;

    // if all values in container are multiples of divisor
    if( std::all_of( begin( container ), end( container ), [&]( const ContElemT& value ) { return value % divisor == 0; } ) )
    {
    }
    else
    {
        // at least one isn't
    }


    // now divisor can't dangle
    FilterContainer filters;
    filters.emplace_back( [=]( int value ) {return value % divisor == 0; } );

}
