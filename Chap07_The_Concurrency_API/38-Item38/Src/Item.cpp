#pragma once

#include <future>
#include <thread>
#include <vector>

// Widget objects might block in their destructor
class Widget
{
public:
    
private:
    std::shared_future<double> fut;
};

// function to run
int calcValue()
{
    return 0;
}

int main()
{
    // set Item39 for info on std::future<void>
    std::vector<std::future<void>> futs;

    std::packaged_task<int()> pt( calcValue );

    // get future for pt
    auto fut = pt.get_future();


    // run pt on t
    std::thread t( std::move( pt ) );

    // easier if statements above are in block
    /*
    {
        std::packaged_task<int()> pt( calcValue );
        auto fut = pt.get_future();
        std::thread t( std::move( pt ) );
    }
    */

    return 0;
}
