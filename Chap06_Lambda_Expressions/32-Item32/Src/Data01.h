#pragma once

#include <memory>
#include "Data00.h"

// is validated and archived
class IsValAndArch
{
public:
    using DataType = std::unique_ptr<Widget>;

    // Item 25 explains use of std::move
    explicit IsValAndArch( DataType&& ptr ) : pw(std::move(ptr))
    {
    }

    bool operator()() const 
    {
        return pw->isValidated() && pw->isArchived();
    }

private:
    DataType pw;
};