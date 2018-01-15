#pragma once

#include <cstddef>

class Widget
{
public:
    // MiVals declaration
    static const std::size_t MinVals = 28;

};


struct IPv4Header
{
    std::uint32_t version : 4,
        IHL : 4,
        DSCP : 6,
        ECN : 2,
        totalLength : 16;
};