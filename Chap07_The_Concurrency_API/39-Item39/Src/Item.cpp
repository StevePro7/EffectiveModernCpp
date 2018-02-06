#pragma once

#include <atomic>
#include <condition_variable>

int main()
{
    std::condition_variable cv;
    std::mutex m;

    // tell reacting task
    cv.notify_one();

    // open critical section
    {
        // lock mutex
        std::unique_lock<std::mutex> lk( m );

        // wait for notify      // this isn't correct!
        cv.wait( lk );
        //cv.wait( lk, [] { /* return whether the event has occurred */} );

        // react to event       // (m is locked)
    }
    // close critical section
    // continue reacting        // (m now unlocked)


    // shared flag;             // see Item 40 for std::atomic
    std::atomic<bool> flag( false );

    // detect event
    flag = true;                // tell reacting task

    // prepare to react
    while( !flag )
    {
        // wait for event
    }
    // react to event


    // now not atomic
    bool flag2( false );
    {
        // lock m via g constructor
        std::lock_guard<std::mutex> g( m );

        // tell reacting task   (part 1)
        flag2 = true;

        // unlock m via g destructor
    }

    // tell reacting task       (part 2)
    cv.notify_one();

    // Another example however using lambdas which didn't seem to compile...
    std::condition_variable cv;
    std::mutex m;
    bool flag( false );
    {
        // lock mutex
        std::unique_lock<std::mutex> lk( m );

        cv.wait( lk, [] { return flag; } );

        // react to event       // (m is locked)
    }
    // continue reacting        // (m now unlocked)
 
    return 0;
}
