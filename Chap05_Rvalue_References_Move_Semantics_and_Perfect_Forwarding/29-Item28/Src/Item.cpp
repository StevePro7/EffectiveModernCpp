#pragma once

#include <array>
#include <vector>

class Widget {};

int main()
{
    std::vector<Widget> vw1;

    // move vw1 into vw2.
    // Runs in constant time
    // Only ptr in vw1 and vw2 are modified
    auto vw2 = std::move( vw1 );


    std::array<Widget, 10000> aw1;

    // move aw1 into aw2.
    // Runs in constant time
    // aw1 are moved into aw2
    auto aw2 = std::move( aw1 );

    return 0;
}
