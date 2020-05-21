#pragma once

#include <cstddef>

namespace Widget
{
    // MiVals declaration
    static const int MinVals = 28;
};


struct IPv4Header
{
    std::uint32_t version : 4,
        IHL : 4,
        DSCP : 6,
        ECN : 2,
        totalLength : 16;
};
