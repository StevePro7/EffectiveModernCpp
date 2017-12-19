#pragma once

class Base
{
public:
    virtual void doWork() {}        // base class virtual function
};

class Derived : public Base
{
public:
    virtual void doWork() {}        // overrides Base::doWork   (virtual is optional here)
};