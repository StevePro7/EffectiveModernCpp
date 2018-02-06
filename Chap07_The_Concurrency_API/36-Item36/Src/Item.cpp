#pragma once

#include <future>

using namespace std::literals;          // for C++14 duration suffixes

void f1()
{
}

void f2()
{
    // f2 sleeps for 1s
    std::this_thread::sleep_for( 1s );
}


template<typename F, typename... Ts>
inline
std::future<typename std::result_of<F(Ts...)>::type>
reallyAsync11( F&& f, Ts&&... params )
{
    // return future for asynchronous call to f(params...)
    return std::async( std::launch::async, std::forward<F>( f ), std::forward<Ts>( params )... );
}


template<typename F, typename... Ts>
inline
auto
reallyAsync14( F&& f, Ts&&... params )
{
    // C++14
    return std::async( std::launch::async, std::forward<F>( f ), std::forward<Ts>( params )... );
}


int main()
{
    // run f using default launch policy
    auto fut1 = std::async( f1 );

    // run f either async or deferred
    auto fut2 = std::async( std::launch::async | std::launch::deferred, f1 );


    // run f asynchronously (conceptually)
    auto fut3 = std::async( f2 );

    while( fut3.wait_for( 100ms ) != std::future_status::ready )
    {
        // loop until f3 has finished running...
        // which may never happen!
    }


    // if task is deferred...
    if( fut3.wait_for( 0s ) == std::future_status::deferred )
    {
        // use wait or get on fut3 to call f synchronously
    }
    else
    {
        // task is not deferred
        while( fut3.wait_for( 100ms ) != std::future_status::ready )
        {
            // infinite loop not possible (assuming f3 finished)

            // task is neither deferred not ready,
            // so do concurrent work until it's ready
        }

        // fut3 is ready
    }


    // launch f4 asynchronously
    auto fut4 = std::async( std::launch::async, f1 );


    // run f5 asynchronously throw if std::async would throw
    auto fut5 = reallyAsync11( f1 );
    auto fut6 = reallyAsync14( f1 );

    return 0;
}
