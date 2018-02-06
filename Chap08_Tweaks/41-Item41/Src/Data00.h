#pragma once

#include <string>
#include <vector>

class Widget0
{
public:
    // Approach #1: overload for l-values and r-values
    // take l-value; copy it
    void addName1(const std::string& newName)
    {
        names.push_back( newName );
    }
    // take r-value; move it
    void addName1( const std::string&& newName )
    {
        // move it; see Item 25 for use of std::move
        names.push_back( std::move( newName ) );
    }

    // Approach #2: use universal reference
    // take l-values and r-values;
    // copy l-values and move r-values;
    template<typename T>
    void addName2( T&& newName )
    {
        // see Item 25 for use of std::forward
        names.push_back( std::forward<T>( newName ) );
    }

    // Approach #3: pass by value
    // take l-value or r-value; move it
    void addName3( std::string newName )
    {
        names.push_back( std::move( newName ) );
    }

private:
    std::vector<std::string> names;
};