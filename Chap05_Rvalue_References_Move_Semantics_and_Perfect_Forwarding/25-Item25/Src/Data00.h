#pragma once

#include <memory>
#include <string>

struct SomeDataStructure {};

class Widget
{
public: 
    Widget() {}
    ~Widget() {}

    // rhs is r-value reference
    Widget( Widget&& rhs ) : name( std::move( rhs.name ) ), p( std::move( rhs.p ) )
    {
    }

    // newName is universal reference
    template<typename T>
    void setName( T&& newName )
    {
        name = std::forward<T>( newName );
    }

    //template<typename T>
    //void setName( T&& newName )
    //{
    //    // universal reference compiles but is bad, bad, bad!
    //    name = std::move( newName );
    //}

    // set from const l-value
    void setNameStr( const std::string& newName )
    {
        name = newName;
    }

    // set from r-value
    void setNameStr( std::string&& newName )
    {
        name = std::move( newName );    
    }


private:
    std::string name;
    std::shared_ptr<SomeDataStructure> p;
};