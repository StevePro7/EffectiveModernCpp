#pragma once

#include <functional>
#include <memory>
#include <vector>
#include "Data00.h"
#include "Data01.h"

int main()
{
    // create Widget and configure
    auto pw = std::make_unique<Widget>();

    // init data member in closure with std::move(pw);
    auto func1 = [pw = std::move(pw)]
    {
        return pw->isValidated() && pw->isArchived();
    };

    auto func2 = [pw = std::make_unique<Widget>()]
    {
        return pw->isValidated() && pw->isArchived();
    };


    auto func3 = IsValAndArch( std::make_unique<Widget>() );


    // object to be moved into closure
    std::vector<double> data;

    // C++14 init capture
    auto func4 = [data = std::move(data)]
    {
        /* uses of data */
    };

    // C++ 11 emulation of init capture
    auto func5 = std::bind( []( const std::vector<double>& data )
    {
    }, std::move(data) );

    // C++ 11 emulation of init capture for mutable lambda
    auto fun6 = std::bind( []( std::vector<double>& data ) mutable
    {
        /* uses of data */
    }, std::move( data ) );


    // as before, create pw in closure
    auto func7 = [pw = std::make_unique<Widget>()]
    {
        return pw->isValidated() && pw->isArchived();
    };

    // C++ emulation
    auto fun8 = std::bind( [] ( const std::unique_ptr<Widget>& pw )
    {
        return pw->isValidated() && pw->isValidated();
    }, std::make_unique<Widget>() );


    return 0;
}
