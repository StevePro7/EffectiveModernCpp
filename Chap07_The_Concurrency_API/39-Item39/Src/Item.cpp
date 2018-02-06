#pragma once

#include <atomic>
#include <condition_variable>
#include <future>
#include <vector>
#include "Data00.h"

void react()
{
}

void detect()
{
    std::promise<void> p;

    // Insert [&] otherwise receiving error:
    // 'p' cannot be implicitly captured because no default capture mode has been specified
    std::thread t( [&]
    {
        p.get_future().wait();
        react();
    } );

    p.set_value();
    t.join();
}

// leverage ThreadRAII from previous Item
void detect2()
{
    std::promise<void> p;

    // Insert [&] otherwise receiving error:
    // 'p' cannot be implicitly captured because no default capture mode has been specified
    ThreadRAII tr(
        std::thread( [&]
        {
            p.get_future().wait();
            react();
        } ),
        ThreadRAII::DtorAction::join
    );

    p.set_value();
}

// now for multiple reacting tasks
void detect3()
{
    std::promise<void> p;

    // sf type is std::shared_future<void>
    auto sf = p.get_future().share();

    // container for reacting threads
    std::vector<std::thread> vt;

    const int threadsToRun = 3;
    for( int i = 0; i < threadsToRun; ++i )
    {
        // wait on local copy of sf
        // see Item 42 for info on emplace_back
        vt.emplace_back( [sf] { sf.wait(); react(); } );
    }

    // detect hangs if this "..." then code throws!

    // un-suspend all threads
    p.set_value();

    // make all threads un-joinable;
    // see item 2 for info on "auto&"
    for( auto& t : vt )
    {
        t.join();
    }
}


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
    std::condition_variable cv2;
    std::mutex m2;
    bool flag3( false );
    {
        // lock mutex
        std::unique_lock<std::mutex> lk( m2 );

        // 'flag3' cannot be implicitly captured because no default capture mode has been specified
        cv2.wait( lk, [flag3] { return flag3; } );

        // react to event       // (m is locked)
    }
    // continue reacting        // (m now unlocked)
 

    // promise for communications channel
    std::promise<void> p;
    p.set_value();              // tell reacting task
    p.get_future().wait();      // wait on future corresponding to p
    // react to event

    
    return 0;
}
