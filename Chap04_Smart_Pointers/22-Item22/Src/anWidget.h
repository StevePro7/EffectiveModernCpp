#pragma once

#include "anGadget.h"
#include <memory>

// Original
//class Widget
//{
//public:
//    Widget();
//    ~Widget();
//
//private:
//    std::string name;
//    std::vector<double> data;
//    Gadget g1, g2, g3;
//};

class Widget
{
public:
    Widget();
    ~Widget();

    // right idea, wrong code
    //Widget( Widget&& rhs ) = default;
    //Widget& operator=( Widget&& rhs ) = default;

    // declarations only
    Widget( const Widget& rhs );            // copy constructor
    Widget& operator=( const Widget& rhs );       // copy assignment operator

    Widget( Widget&& rhs );                 // move constructor
    Widget& operator=( Widget&& rhs );      // move assignment operator

private:
    // C++98 declare implementation struct and pointer to it
    //struct Impl;
    //Impl* pImpl;

    // C++11 use smart pointer instead of raw pointer
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};