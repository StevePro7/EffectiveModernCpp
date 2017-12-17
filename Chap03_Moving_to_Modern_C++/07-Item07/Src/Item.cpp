#pragma once

#include <atomic>
#include <vector>

class Widget
{
public:
    Widget() {}
    //  Widget( int x ) : x( x ) {}
    ~Widget() {}

    Widget( int i, bool b ) {}          // ctors not declaring
    Widget( int i, double d ) {}        // std::initializer_list params

    //Widget( std::initializer_list<long double> il ) {}
    //Widget( std::initializer_list<bool> il2 ) {}

    // std::initializer_list element type is now std::string
    //Widget( std::initializer_list<std::string> il ) {}      // no implicit

    Widget( std::initializer_list<int> il ) {}      // no implicit conversion funs

    operator float() const { return 0.0f; }

private:
    int x{ 0 };         // fine, x's default value is 0
    int y = 0;          // also fine
    //int z( 0 );         // error!
};


// type of object to create types of arguments to use
template<typename T, typename... Ts>
void doSomeWork( Ts&&... params )
{
    // create local T object from params
}


int main()
{
    //int x( 0 );         // initializer is in parentheses
    //int y = 0;          // initializer follows "="
    //int z{ 0 };         // initializer is in braces
    //int w = { 0 };      // initializer uses "=" and braces

    //Widget w1;          // call default constructor
    //Widget w2 = w1;     // not an assignment; calls copy ctor
    //w1 = w2;            // an assignment; calls copy operator=

    std::vector<int> v{ 1, 3, 5 };  // v's initial content is 1, 3, 5

    std::atomic<int> ai1{ 0 };      // fine
    std::atomic<int> ai2( 0 );      // fine
    //std::atomic<int> ai3 = 0;       // error!       NOTE: did not get error in VS2017

    double x = 0, y = 0, z = 0;
    //int sum1{ x + y + z };          // error! sum of doubles may not be expressible as int
    int sum2( x + y + z );          // fine (value of expression truncated to an int)
    int sum3 = x + y + z;           // ditto

    //Widget w1( 10 );                // calls Widget ctor with argument 10
    //Widget w2();                    // most vexing parse! declares function named w2() that returns a Widget!
    //Widget w3{};                    // calls Widget ctor with no args

    //Widget w1( 10, true );              // calls first ctor
    //Widget w2{ 10, true };              // also calls first ctor
    //Widget w3( 10, 5.0 );               // calls second ctor
    //Widget w4{ 10, 5.0 };               // also calls second ctor

    // Add Widget ctor std::initializer_list<long double>
    //Widget w1( 10, true );              // uses parens and calls first ctor
    //Widget w2{ 10, true };              // uses braces but now calls std::initializer_list ctor
    //Widget w3( 10, 5.0 );               // uses parens and calls second ctor
    //Widget w4{ 10, 5.0 };               // uses braces but now calls std::initializer_list ctor

    //Widget w5( w4 );                    // uses parens, calls copy ctor
    //Widget w6{ w4 };                    // uses braces, calls std::initializer_list ctor
    //Widget w7( std::move( w4 ) );       // uses parens, calls move ctor
    //Widget w8{ std::move( w4 ) };       // uses braces, calls std::initializer_list ctor

    // Add Widget ctor std::initializer_list<bool>
    // Widgetw{10, 5.0};                // error! requires narrowing conversions

    // Add Widget ctor std::initializer_list<std::string>
    //Widget w1( 10, true );              // uses parens, still calls first ctor
    //Widget w2{ 10, true };              // uses braces, now calls first ctor
    //Widget w3( 10, 5.0 );               // uses parens, still calls second ctor
    //Widget w4{ 10, 5.0 };               // uses braces, now calls second ctor

    // Add Widget ctor std::initializer_list<int>
    Widget w1;                          // calls default ctor
    Widget w2{};                        // also calls default ctor
    Widget w3();                        // move vexing parse! declares a function!

    // Empty braces means no arguments no an empty std::initializer_list
    Widget w4( {} );                    // calls std::initializer_list ctor with empty list
    Widget w5{ {} };                    // ditto


    // use non-std::initializer_list ctor:
    // create 10-element std::vector, all elements have value of 20
    std::vector<int> v1( 10, 20 );

    // use std::initializer_list ctor:
    // create 2-element std::vector, element values are 10 and 20
    std::vector<int> v2{ 10, 20 };


    std::vector<int> v3;
    doSomeWork<std::vector<int>>( 10, 20 );

    return 0;
}
