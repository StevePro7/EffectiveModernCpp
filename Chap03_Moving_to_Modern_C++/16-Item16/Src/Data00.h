#pragma once

#include <mutex>
#include <vector>

class Polynomial
{
public:
    using RootsType = std::vector<double>;

    RootsType roots() const 
    {
        // lock mutex
        std::lock_guard<std::mutex> g(m);

        // if cache not valid then compute roots
        if( !rootsAreValid )
        {
            rootsAreValid = true;
        }

        // store them in rootVals
        return rootVals;
    }

private:
    mutable std::mutex m;
    mutable bool rootsAreValid{ false };
    mutable RootsType rootVals{};
};


/*
class Polynomial
{
public:
using RootsType = std::vector<double>;

RootsType roots() const
{
// if cache not valid then compute roots
if( !rootsAreValid )
{
rootsAreValid = true;
}

// store them in rootVals
return rootVals;
}

private:
mutable bool rootsAreValid{ false };
mutable RootsType rootVals{};
};
*/