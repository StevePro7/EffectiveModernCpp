#pragma once

#include <iostream>
#include <vector>

// declaration only for TD  "Type Displayer"
template<typename T>
class TD;


template<typename T>
void f( const T& param )
{
                                                                        // Microsoft                // gcc
    std::cout << "T     = " << typeid(T).name() << std::endl;           // class Widget const *     // PK6Widget
    std::cout << "param = " << typeid(param).name() << std::endl;       // class Widget const *     // PK6Widget

    // https://stackoverflow.com/questions/25952769/left-of-must-have-class-struct-union-c-error
    int a = param->getData();
    int b = (*param).getData();
}

class Widget
{
public:
    // https://stackoverflow.com/questions/20319540/error-c2662-cannot-convert-from-const-to-reference
    int getData() const { return 7; }
};

// factory function
std::vector<Widget> createVec()
{
    return std::vector<Widget>( 1 );
}

int main()
{
    const int theAnswer = 42;

    auto x = theAnswer;         // int
    auto y = &theAnswer;        // const int*

    // error C2079: 'xType' uses undefined class 'TD<int>'
    //TD<decltype(x)> xType;      // elicit errors containing 
    //TD<decltype(x)> yType;      // x and y incomplete types

    std::cout << typeid(x).name() << std::endl;     // int
    std::cout << typeid(y).name() << std::endl;     // int const*

    // init vw with factory return
    const auto vw = createVec();
    if( !vw.empty() )
    {
        f( &vw[0] );
    }

    return 0;
}
