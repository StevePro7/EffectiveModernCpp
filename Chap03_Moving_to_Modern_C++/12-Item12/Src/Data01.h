#pragma once

class Widget
{
public:
    void doWork() & {}      // this version of doWork applies only when *this is an lvalue
    void doWork() && {}     // this version of doWork applies only when *this is an rvalue
};