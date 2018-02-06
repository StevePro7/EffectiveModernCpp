#pragma once

#include <memory>
#include <string>
#include <vector>

class Widget1
{
public:
    void setPtr( std::unique_ptr<std::string>&& ptr )
    {
        p = std::move( ptr );
    }

    // corresponding pass by value
    //void setPtr( std::unique_ptr<std::string> ptr )
    //{
    //    p = std::move( ptr );
    //}

private:
    std::unique_ptr<std::string> p;
};


class Widget2
{
public:
    void addName( std::string newName )
    {
        if( (newName.length() >= minLen) && (newName.length() <= maxLen) )
        {
            names.push_back( std::move( newName ) );
        }
    }

private:
    std::vector<std::string> names;
    const int minLen = 5;
    const int maxLen = 15;
};