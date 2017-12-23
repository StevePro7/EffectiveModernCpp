#pragma once

#include <memory>
#include <vector>

class Widget : public std::enable_shared_from_this<Widget>
{
public:

    // factory function that perfect-forwards args to a private ctor
    template<typename... Ts>
    static std::shared_ptr<Widget> create( Ts&&... params )
    {
    }

    void process()
    {
        // add it to list of processed Widgets; this is wrong!
        //processedWidgets.emplace_back( this );
        processedWidgets.emplace_back( shared_from_this() );
    }

private:
    std::vector<std::shared_ptr<Widget>> processedWidgets;
};

void makeLogEntry( Widget* pw )
{
}

// custom deleter
auto loggingDel = []( Widget* pw )
{
    makeLogEntry( pw );
    delete pw;
};

// custom deleter each with a different type
auto customDeleter1 = []( Widget* pw ) {};
auto customDeleter2 = []( Widget* pw ) {};


int main()
{
    // deleter type is part of ptr type
    std::unique_ptr<Widget, decltype(loggingDel)> upw( new Widget, loggingDel );

    // deleter type is not part of ptr type
    std::shared_ptr<Widget> spw( new Widget, loggingDel );
    spw->process();

    std::shared_ptr<Widget> pw1( new Widget, customDeleter1 );
    std::shared_ptr<Widget> pw2( new Widget, customDeleter2 );

    // std::initializer_list
    std::vector<std::shared_ptr<Widget>> vpw{ pw1, pw2 };


    auto pw = new Widget;                                       // pw is raw ptr
    std::shared_ptr<Widget> spw1( pw, loggingDel );             // create control block for *pw
    std::shared_ptr<Widget> spw2( pw, loggingDel );             // create second control block for *pw!


    std::shared_ptr<Widget> tpw1( new Widget, loggingDel );     // direct use of new
    std::shared_ptr<Widget> tpw2( tpw1 );                       // tpw2 uses same control block as tpw1
    std::vector<std::shared_ptr<Widget>> processedWidgets;

    return 0;
}
