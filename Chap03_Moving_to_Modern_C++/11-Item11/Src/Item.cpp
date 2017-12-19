#pragma once

#include "Data01.h"
#include "Data02.h"

int main()
{
    Calc c;

    bool b0 = c.isLucky( 7 );
    //bool b1 = c.isLucky( 'a' );       // error! call to deleted function
    //bool b2 = c.isLucky( true );      // error! call to deleted function
    //bool b3 = c.isLucky( 3.5          // error! call to deleted function

    return 0;
}