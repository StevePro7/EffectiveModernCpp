#pragma once

#include "Data00.h"

#include <chrono>
#include <set>

// global data structure
std::multiset<std::string> names;

void logAndAdd( const std::string& name )
{
    // get current time
    auto now = std::chrono::system_clock::now();

    // make log entry
    //log( now, "logAndAdd" );

    // add name to global data structure
    names.emplace( name );
}

template<typename T>
void logAndAdd( T&& name )
{
    auto now = std::chrono::system_clock::now();
    //log( now, "logAndAdd" );
    names.emplace( std::forward<T>( name ) );
}

// return name corresponding to idx
std::string nameFromIdx( int idx )
{
    return "name";
}

// new overload
void logAndAdd( int idx )
{
    auto now = std::chrono::system_clock::now();
    //log( now, "logAndAdd" );
    names.emplace( nameFromIdx( idx ) );
}


int main()
{

    std::string petName( "Darla" );

    // initial function called
    logAndAdd( petName );                       // pass l-value std::string
    logAndAdd( std::string( "Persephone" ) );   // pass r-value std::string
    logAndAdd( "Patty Dog" );                   // pass string literal

    // template overload called
    logAndAdd( petName );                       // as before, copy l-value into multiset
    logAndAdd( std::string( "Persephone" ) );   // move r-value instead of copying it
    logAndAdd( "Patty Dog" );                   // create a std::string in multiset instead of copying qa temporary std::string

    // as before - these call the T&& [template] overload
    logAndAdd( petName );
    logAndAdd( std::string( "Persephone" ) );
    logAndAdd( "Patty Dog" );
    logAndAdd( 22 );                            // calls int overload

    short nameIdx;
    nameIdx = 17;                               // give nameIdx a value

    // note: see reference to function template instantiation 'void logAndAdd<short&>(T)' being compiled
    // logAndAdd( nameIdx );                    // error!


    Person p( "Nancy" );
    //auto cloneOfOP( p );                      // create new Person from p; this won't compile!

    const Person cp( "Nancy" );                 // object is now const
    auto cloneOfP( cp );                        // calls copy constructor

    return 0;
}
