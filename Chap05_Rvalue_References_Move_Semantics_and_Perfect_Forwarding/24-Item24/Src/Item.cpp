#pragma once

#include <vector>

class Widget
{
};

// r-value reference
void f( Widget&& param )
{
    // no type deduction
    // param is an r-value reference
}

// r-value reference
template<typename T>
void f2( std::vector<T>&& param )
{
    // param is an r-value reference
}

// not r-value reference
template<typename T>
void f3( T&& param )            // param is a universal reference
{
}

// param is an r-value reference
template<typename T>
void f( const T&& param )
{
}

// from C++ standards
//template<class T, class Allocator = allocator<T>>
//class vector
//{
//public:
//    void push_back( T&& x );
//    template<class... Args>
//    void emplace_back( Args&&... args );
//};

//class vector<Widget, allocator<Widget>>
//{
//public:
//    void push_back( T&& x );  // r-value reference
//};

// param is a universal reference
template<typename MyTemplateType>
void someFunc( MyTemplateType&& param )
{
}

// C++14
//auto timeFuncInvocation = []( auto&& func, auto&&... params )
//{
//    // start timer;
//    std::forward( <decltype(func)>(func)(std::forward<decltype(params)>( params )...);
//    // stop timer;
//}

int main()
{
    // r-value reference
    Widget&& var1 = Widget();   // no type deduction
                                // var1 is an r-value reference

    // not r-value reference
    auto&& var2 = var1;         // var2 is a universal reference


    Widget w;

    // l-value passed to f; param type is Widget& (i.e. an l-value reference)
    //f( w );       // error! can't bind l-value to r-value reference

    // r-value passed to f; param type is Widget&& (i.e. an r-value reference)
    f( std::move( w ) );


    std::vector<int> v;
    //f( v );       // error! can't bind l-value to r-value reference


    std::vector<Widget> vw;

    return 0;
}
