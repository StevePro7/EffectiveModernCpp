#pragma once

#include <cstddef>
#include <vector>
#include "Data00.h"

void f( const std::vector<int>& v )
{
}

void f( std::size_t val )
{
}

// accept any arguments
template<typename... Ts>
void fwd( Ts&&... params )
{
    // forward them to f
    f( std::forward<Ts>( params )... );
}

// processing function
void f( int( *pf )(int) )
{
}
void f2( int pf( int ) )
{
}

// accept any argument
template<typename T>
void fwd( T&& param )
{
    // forward it to f
    f( std::forward<T>( param ) );
}

int processVal( int value )
{
    return 0;
}
int processVal( int value, int priority )
{
    return 1;
}

// template for processing values
template<typename T>
T workOnVal( T param )
{
    return 0;
}

using ProcessFuncType = int( *)(int);

// function to call
void f3( std::size_t sz )
{
}

int main()
{
    //f( expression );          // if this does one thing
    //fwd( expression );        // but this does something else
    // fwd failed to perfectly forward expression to f

    f( { 1, 2, 3 } );           // fine "{ 1, 2, 3 } implicitly converted to std::vector<int>
                                //fwd( { 1, 2, 3 } );       // error! doesn't compile

    auto il = { 1, 2, 3 };      // il type deduced to be std::initializer_list<int>
    fwd( il );                  // fine perfect forward il to f


    std::vector<int> widgetData;                    // no definition for MinVals
    widgetData.reserve( Widget::MinVals );          // use of MinVals

    f( Widget::MinVals );                           // fine treated as f(28)
    fwd( Widget::MinVals );                         // error! shouldn't link


    f( processVal );                                // fine
                                                    //fwd( processVal );                            // error! which processVal


                                                    //fwd( workOnVal );                             // error which workOnVal instantiation?

    ProcessFuncType processValPtr = processVal;     // specify needed signature for processVal
    fwd( processValPtr );                           // fine
    fwd( static_cast<ProcessFuncType>(workOnVal) ); // also fine


    IPv4Header h;
    h.totalLength = 16;
    f3( h.totalLength );                            // fine
                                                    //fwd( h.totalLength );                         // error!

                                                    // copy bitfield value
    auto length = static_cast<std::uint16_t>(h.totalLength);
    return 0;
}
