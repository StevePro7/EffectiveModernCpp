#pragma once

#include <memory>
#include "Data00.h"
#include "Data01.h"

// factory function (returns rvalue)
Widget makeWidget()
{
    return Widget();
}

int main()
{
    // create base class pointer to derived class object
    std::unique_ptr<Base> upd = std::make_unique<Derived>();

    // call doWork through base class ptr; derived class function is invoked
    upd->doWork();


    Widget w;                   // normal object (an lvalue)
    w.doWork();
    makeWidget().doWork();

    return 0;
}