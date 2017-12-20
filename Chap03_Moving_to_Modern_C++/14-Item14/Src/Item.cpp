#pragma once

#include <stddef.h>                      // size_t

void f1( int x ) throw() {}              // no exceptions from f: C++98 style
void f2( int x ) noexcept {}             // no exceptions from f: C++11 style

void func1( int params ) noexcept {}     // most optimizable
void func2( int params ) throw() {}      // less optimizable
void func3( int params ) {}              // less optimizable

template<class T, size_t N>
void swap( T( &a )[N], T( &b )[N] ) noexcept(noexcept(swap( *a, *b )))
{
}

template<class T1, class T2>
struct patr
{
    void swap( patr& p ) noexcept(noexcept(swap( first, p.first )) && noexcept(swap( second, p.second ) ) )
    {
    }

    int first;
    int second;
};

// functions defined elsewhere
void setup() {}
void cleanup() {}

void doWork() noexcept
{
    setup();    // set up work to be done
                // do the actual work
    cleanup();  // preform clean up actions
}

int main()
{
    return 0;
}
