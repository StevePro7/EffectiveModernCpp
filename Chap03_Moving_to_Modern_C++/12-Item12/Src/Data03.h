#pragma once

#include <vector>
using DataType = std::vector<double>;

class Widget2
{
public:
    DataType& data() & { return values; }               // for lvalue Widgets return lvalue
    DataType data() && { return std::move( values ); }    // for rvalue Widgets return lvalue

private:
    DataType values;
};