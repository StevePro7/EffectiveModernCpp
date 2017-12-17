#pragma once

#include <memory>
#include <mutex>

// three overloads of f
void f( int ) {}
void f( bool ) {}
void f( void* ) {}

bool findRecord()
{
    return true;
}

class Widget
{
};

// call these only when the appropriate mutex is locked
int f1( std::shared_ptr<Widget> spw ) { return 0; }
double f2( std::unique_ptr<Widget> upw ) { return 0.0; }
bool f3( Widget* pw ) { return false; }

using MuxGuard = std::lock_guard<std::mutex>;

//template<typename FuncType, typename MuxType, typename PtrType>
//auto lockAndCall( FuncType func, MuxType& mutex, PtrType ptr ) -> decltype(func( ptr ))
//{
//    MuxGuard g( mutex );
//    return func( ptr );
//}

// C++14
template<typename FuncType, typename MuxType, typename PtrType>
decltype(auto) lockAndCall( FuncType func, MuxType& mutex, PtrType ptr )
{
    MuxGuard g( mutex );
    return func( ptr );
}


int main()
{
    f( 0 );         //calls f(int), not f(void*)
    //f( NULL );    // might not compile, but typically calls f(int).
                    // Never calls F(void*)
    f( nullptr );   // calls f(void*) overload

    auto result = findRecord();
    if( result == 0 )
    {
    }

    // No ambiguity: result must be a pointer type
    //if( result == nullptr )
    //{
    //}

    std::mutex f1m, f2m, f3m;
    {
        // pass 0 as null ptr to f1
        MuxGuard g( f1m );
        auto result = f1( 0 );
    }
    {
        // pass NULL as null ptr to f2
        MuxGuard g( f2m );
        auto result = f2( NULL );
    }
    {
        // pass nullptr as null ptr to f3
        MuxGuard g( f3m );
        auto result = f3( nullptr );
    }


    //auto result1 = lockAndCall( f1, f1m, 0 );             // error!
    //auto result2 = lockAndCall( f1, f1m, NULL );          // error!
    auto result1 = lockAndCall( f1, f1m, nullptr );       // fine

    return 0;
}