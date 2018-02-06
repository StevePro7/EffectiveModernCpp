#pragma once

#include <functional>
#include <thread>
#include <vector>
#include "Data00.h"

constexpr auto tenMillion = 10000000;

// return whether computation was performed see Item2 for std::function
bool doWork( std::function<bool( int )> filter, int maxVal = tenMillion )
{
    // values that satisfy filter
    std::vector<int> goodVals;

    // populate goodVals
    std::thread t( [&filter, maxVal, &goodVals]
    {
        for( auto i = 0; i <= maxVal; ++i )
        {
            if( filter( i ) )
            {
                goodVals.push_back( i );
            }
        }
    } );

    // use t native handle to set t priority
    auto nh = t.native_handle();

    if( true /* conditionsAreSatisified */ )
    {
        t.join();
        // performComputation( goodVals );

        // computation was performed
        return true;
    }

    // computation was not performed
    return false;
}

bool doWork2( std::function<bool( int )> filter, int maxVal = tenMillion )
{
    // values that satisfy filter
    std::vector<int> goodVals;

    // populate goodVals    use RAII object
    ThreadRAII t(
        std::thread( [&filter, maxVal, &goodVals]
        {
        for( auto i = 0; i <= maxVal; ++i )
        {
            if( filter( i ) )
            {
                goodVals.push_back( i );
            }
        }

        } ),
        ThreadRAII::DtorAction::join );

    // use t native handle to set t priority
    auto nh = t.get().native_handle();

    if( true /* conditionsAreSatisified */ )
    {
        t.get().join();
        // performComputation( goodVals );

        // computation was performed
        return true;
    }

    // computation was not performed
    return false;
}

int main()
{
    return 0;
}
