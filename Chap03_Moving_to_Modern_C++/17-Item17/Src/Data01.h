#pragma once

class Base
{
public:
    // make dtor virtual
    virtual ~Base() = default;

    // support copying
    Base( Base& ) = default;
    Base& operator=( Base& ) = default;

    // support moving
    Base( Base&& ) = default;
    Base& operator=( Base&& ) = default;
};