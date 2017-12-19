#pragma once

class Calc
{
public:
    bool isLucky( int number )
    {
        return true;
    }

    bool isLucky( char ) = delete;
    bool isLucky( bool ) = delete;
    bool isLucky( double ) = delete;
};
