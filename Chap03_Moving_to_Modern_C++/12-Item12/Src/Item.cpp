#pragma once

#include <memory>
#include "Data00.h"
#include "Data01.h"
#include "Data03.h"

// factory function (returns rvalue)
Widget makeWidget()
{
    return Widget();
}
Widget2 makeWidget2()
{
    return Widget2();
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


    Widget2 w2;
    auto vals1 = w2.data();                  // calls lvalue overload for Widget::data   copy construct
    auto vals2 = makeWidget2().data();       // calls rvalue overload for Widget::data   move construct

    return 0;
}