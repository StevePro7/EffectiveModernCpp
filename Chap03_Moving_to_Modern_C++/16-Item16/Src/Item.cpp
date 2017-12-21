#pragma once

#include "Data00.h"

int main()
{
    Polynomial p;

    /*----- Thread 1 -----*/
    auto rootsOfP = p.roots();

    /*----- Thread 1 -----*/
    auto valsGivingZero = p.roots();

    return 0;
}
