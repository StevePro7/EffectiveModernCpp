#pragma once

class Widget {};

template<typename T>
class WidgetT
{
    typedef T&& RvalueRefToT;
};

template<typename T>
void func( T&& param )
{
}

// function returning r-value
Widget widgetFactory()
{
    Widget w;
    return w;
}

int main()
{
    Widget w;                       // a variable (an l-value)
    func( w );                      // call func with l-value; T deduced to be Widget&
    func( widgetFactory() );        // call func with r-value; T deduced to be Widget

    int x;
    //auto& & rx = x;               // error! can't declare reference to reference


    // Mimic Widget above
    auto&& w1 = w;                  // initialize w1 with an l-value
    //Widget& && w1 = w;

    Widget& w2 = w;                 // w2 is an l-value reference
    auto&& w3 = widgetFactory();    // initialize w3 with an r-value


    WidgetT<int&> wt;
    //typedef int& && RvalueRefToT;
    //typedef int& RvalueRefToT;

    return 0;
}