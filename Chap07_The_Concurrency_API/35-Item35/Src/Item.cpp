#pragma once

#include <thread>
#include <future>

//int doAsyncWork()
//{
//    return 0;
//}

// see Item14 for noexcept
int doAsyncWork() noexcept
{
    return 0;
}

int main()
{
    // throws if no more threads are available
    std::thread t( doAsyncWork );
    t.join();


    // onus of thread management is on implementer of the Standard Library
    auto future = std::async( doAsyncWork );

    return 0;
}
