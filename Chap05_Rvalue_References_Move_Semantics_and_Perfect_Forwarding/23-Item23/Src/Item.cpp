#pragma once

#include <chrono>
#include <string>

class Widget
{
public:
    Widget() {}

    Widget( Widget&& rhs ) : s( std::move( rhs.s ) )
    {
        ++moveCtorCalls;
    }

    // unconventional, undesirable, implementation
    //Widget( Widget&& rhs ) : s( std::forward<std::string>( rhs.s ) )
    //{
    //    ++moveCtorCalls;
    //}

private:
    static std::size_t moveCtorCalls;
    std::string s;
};

// C++11 std::move
//template<typename T>
//typename remove_reference<T>::type&&
//move( T&& param )
//{
//    using ReturnType = typename remove_reference<T>::type&&;
//    return static_cast<ReturnType>(param);
//}

// C++14 std::move
template<typename T>
decltype(auto) move( T&& param )
{
    using ReturnType = std::remove_reference_t<T>&&;
    return static_cast<ReturnType>(param);
}

class Annotation
{
public:
    explicit Annotation( const std::string text ) : value( std::move( text ) )
    {
    }

private:
    std::string value;
};

// std::string is actually a typedef for std::basic_string<char>
//class string
//{
//public:
//    string( const string& rhs );    // copy ctor
//    string( string&& rhs );         // move ctor
//};


void process( const Widget& lvalArg )   // process l-values
{
}
void process( Widget&& rvalArg )        // process r-values
{
}


template<typename T>
void logAndProcess( T&& param )
{
    auto now = std::chrono::system_clock::now();
    //makeLogEntry( "Calling 'process'", now );
    process( std::forward<T>( param ) );
}

int main()
{
    Widget w;
    logAndProcess( w );                 // call with l-value
    logAndProcess( std::move( w ) );    // call with r-value
    return 0;
}
