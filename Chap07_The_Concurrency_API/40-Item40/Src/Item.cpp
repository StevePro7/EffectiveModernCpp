#pragma once

#include <atomic>
#include <iostream>

// compute value
int computeImportantValue()
{
    return 0;
}

int main()
{
    std::atomic<int> ai( 0 );           // initialize ai to 0
    ai = 10;                            // atomically set ai 10 10
    std::cout << ai << std::endl;       // atomically read at value
    ++ai;                               // atomically increment at to 11
    --ai;                               // atomically decrement at to 10

    volatile int vi( 0 );               // initialize vi to 0
    vi = 10;                            // set vi to 10;
    std::cout << vi << std::endl;       // read vi value
    ++vi;                               // increment vi to 11
    --vi;                               // decrement vi to 10

    std::atomic<int> ac( 0 );           // "atomic" counter
    volatile int vc( 0 );                   // "volatile" counter

    std::atomic<bool> valAvailable( false );
    auto imptValue = computeImportantValue();
    valAvailable = true;                // tell other task it's available

    volatile bool valAvailable2( false );
    auto imptValue2 = computeImportantValue();
    valAvailable2 = true;               // other threads might see this assignment
                                        // before the one to imptValue!

    int x = 0;
    auto y = x;                         // read x
    y = x;                              // read x again
    x = 10;                             // write x
    x = 20;                             // write x again

    volatile int x2 = 0;
    auto y2 = x2;                       // read x
    y2 = x2;                            // read x again (can't be optimized away)
    x2 = 10;                            // write x (can't be optimized away)
    x2 = 20;                            // write x again

    //std::atomic<int> x3 = 0;
    //auto y3 = x3;                     // conceptually read x
    // NOT in book but this produces the following error in Visual Studio 2017
    // 'std::atomic<int>::atomic(const std::atomic<int> &)': function was explicitly deleted


    // Final code to load and store
    // std::atomic<int> y4( x.load() );    // read x
    // y.store( x.load() );                // read x again
    // register = x.load();                // read x into register
    // std::atomic > int > y( register );  // init y with register value
    // y.store( register );                // store register value into y

    return 0;
}
