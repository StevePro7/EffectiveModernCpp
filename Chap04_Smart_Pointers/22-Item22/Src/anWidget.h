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

private:
    // C++98 declare implementation struct and pointer to it
    //struct Impl;
    //Impl* pImpl;


    // C++11 use smart pointer instead of raw pointer
    struct Impl;
    std::unique_ptr<Impl> pImpl;
};