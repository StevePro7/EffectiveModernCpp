#pragma once

#include <initializer_list>
#include <vector>

// conceptual template for deducing x type
template<typename T>
void func_for_x( T param )                  // int
{
}

// conceptual template for deducing cx type
template<typename T>
void func_for_cx( const T param )           // const int
{
}

// conceptual template for deducing rx type
template<typename T>
void func_for_rx( const T& param )          // const int &
{
}

// someFunc is a function
// type void(int, double)
void someFunc( int, double )
{
}

// template with parameter declaration equivalent to x declaration
template<typename T>
void f1( T param )
{
}

template<typename T>
void f2( std::initializer_list<T> initList )
{
}

// error: can't deduce type for { 1, 2, 3 }
//auto createList()
//{
//    return { 1, 2, 3 };
//}

int main()
{
    auto x = 27;            // case 3   x neither ptr nor ref       int
    const auto cx = x;      // case 3   cx isn't either             const int
    const auto& rx = x;     // case 1   rx is non-universal ref     const int&

    func_for_x( 27 );       // conceptual call      param deduced type is x type    int
    func_for_cx( x );       // conceptual call      param deduced type is cx type   const int
    func_for_rx( x );       // conceptual call      param deduced type is rx type   const int&

    // Case 2   Type is universal reference         works as expected
    auto&& uref1 = x;       // x int        lvalue  uref1 type  int&
    auto&& uref2 = cx;      // cx const int lvalue  uref2 type  const int&
    auto&& uref3 = 27;      // 27           rvalue  uref3 type  int&&

    const char name[] = "R. N. Briggs";     // name type    const char[13]
    auto arr1 = name;                       // arr1 type    const char*
    auto& arr2 = name;                      // arr2 type    const char[13](&)

    auto func1 = someFunc;                  // func1 type   void(*)(int, double)
    auto& func2 = someFunc;                 // func2 type   void(&)(int, double)

    // all four syntaxes but one result: an int with value 27
    int x1 = 27;        // C++98
    int x2( x1 );       // C++98
    int x3 = { 27 };    // C++11
    int x4{ 27 };       // C++11

    // all compile but don't have the same meaning as above
    auto y1 = 27;       // C++98            int                             value = 27
    auto y2( y1 );      // C++98            int                             value = 27
    auto y3 = { 27 };   // C++11            std::initializer_list<int>      value = { 27 }
    auto y4{ y3 };      // C++11            std::initializer_list<int>      value = { 27 }

    // error! can't deduce T for std::initializer_list<T>
    //auto x5 = { 1, 2, 3.0 };

    auto x6 = { 11, 23, 9 };                // type    std::initializer_list<int>
    //f1( { 11, 13, 9 } );                  // error! can't deduce type for T
    f2( { 11, 13, 9 } );                    // T deduced as int
                                            // initList type    std::initializer_list<int>

    std::vector<int> v;
    auto resetV = [&v]( const auto& newValue ) { v = newValue; };           // C++14
    //resetV( { 1, 2, 3 } );                // error!   cannot deduce type for { 1, 2, 3 }

    return 0;
}