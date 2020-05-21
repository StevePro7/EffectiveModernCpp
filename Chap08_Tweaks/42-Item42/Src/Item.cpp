#pragma once

#include <list>
#include <memory>
#include <regex>
#include <string>
#include <vector>

class Widget
{
};

void killWidget( Widget* pWidget )
{
}

int main()
{
    // container of std::string
    std::vector<std::string> vs;

    // add literal string
    // this create temporary string and pass it to push back
    vs.push_back( "test" );

    // construct string inside vs directly from "test"
    vs.emplace_back( "test" );

    // insert string consisting of 50 'x' characters
    vs.emplace_back( 50, 'x' );


    std::string queenOfDisco( "Donna Summer" );

    // copy construct string at end of vs
    vs.push_back( queenOfDisco );

    // ditto
    vs.emplace_back( queenOfDisco );


    // add "test" to beginning of vs
    vs.emplace( vs.begin(), "test" );

    // construct new value at end of container;
    // don't pass the type in container;
    // don't use container rejecting duplicates
    vs.emplace_back( "test" );

    // ditto
    vs.emplace_back( 50, 'x' );


    std::list<std::shared_ptr<Widget>> ptrs;

    // This:
    ptrs.push_back( std::shared_ptr<Widget>( new Widget, killWidget ) );

    // is equivalent to this:
    //ptrs.push_back( new Widget, killWidget );

    
    // create Widget and have spw manage it
    std::shared_ptr<Widget> spw( new Widget, killWidget );

    // add spw as r-value
    ptrs.push_back( std::move( spw ) );

    // the emplace back version is similar
    std::shared_ptr<Widget> spw2( new Widget, killWidget );
    ptrs.emplace_back( std::move( spw2 ) );


    std::vector<std::regex> regexes;

    // add nullptr to container of regexes?
    // regexes.emplace_back( nullptr );		// error! NULL reference

    // error! won't compile
    // std::regex r = nullptr;

    // error! won't compile
    // regexes.push_back( nullptr );


    // regex constructor takes const char* pointer is explicit
    // std::regex upperCaseWord( "[A-Z+" );	// error! NULL reference

    // that's why these lines do not compile
    // error! won't compile
    // std::regex r = nullptr;

    // error! won't compile
    // regexes.push_back( nullptr );


    // However, this compiles
    // std::regex r( nullptr );	// error! NULL reference

    // error! won't compile
    // std::regex r1 = nullptr;

    // compiles
    // std::regex r2( nullptr );	// error! NULL reference


    // compiles.
    // Direct init permits use of explicit std::regex constructor taking a pointer
    // regexes.emplace_back( nullptr );	// error! NULL reference

    // error! copy init forbids use of that constructor
    // regexes.push_back( nullptr );

    return 0;
}
