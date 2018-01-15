#pragma once

#include <chrono>
#include <set>
#include <string>
#include "Data00.h"

// global data structure
std::multiset<std::string> names;

// make log entry and add name to data structure
//template<typename T>
//void logAndAdd( T&& nane )
//{
//    auto now = std::chrono::system_clock::now();
//    //log( now, "logAndAdd" );
//    names.emplace( std::forward<T>( name ) );
//}


template<typename T>
void logAndAdd( T&& name )
{
    // not quite correct.
    logAndAddImpl( name, std::is_integral<T>() );

    logAndAddImpl( std::forward<T>( name ), std::is_integral<typename std::remove_reference<T>::type>() );
}

// non-integral argument: add it to global data structure
template<typename T>
void logAndAddImpl( T&& name, std::false_type )
{
    auto now = std::chrono::system_clock::now();
    //log( now, "logAndAdd" );
    names.emplace( std::forward<T>( name ) );
}

std::string nameFromIdx( int idx )
{
    return "name";
}
// integral argument: look up name and call logAndAdd with it
void logAndAddImpl( int idx, std::true_type )
{
    //logAndAddImpl( nameFromIdx( idx ) );
}


int main()
{
    return 0;
}
