#pragma once

#include <thread>

class ThreadRAII
{
public:
    // use Item 10 for enum class info
    enum class DtorAction { join, detach };

    // in dtor take action a on t
    ThreadRAII( std::thread&& t, DtorAction a ) : action( a ), t( std::move( t ) )
    {
    }

    ~ThreadRAII()
    {
        if( t.joinable() )
        {
            if( action == DtorAction::join )
            {
                t.join();
            }
            else
            {
                t.detach();
            }
        }
    }

    ThreadRAII( ThreadRAII&& ) = default;                   // support moving
    ThreadRAII& operator=( ThreadRAII&& ) = default;        // support copying

    std::thread& get() { return t; }

private:
    DtorAction action;
    std::thread t;
};