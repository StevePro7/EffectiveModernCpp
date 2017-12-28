#include "anWidget.h"
#include "anGadget.h"
#include <string>
#include <vector>

struct  Widget::Impl
{
    std::string name;
    std::vector<double> data;
    Gadget g1, g2, g3;
};

// C++98
//Widget::Widget() : pImpl( new Impl )
//{
//}

// C++11
Widget::Widget() : pImpl( std::make_unique<Impl>() )
{
}


// C++98
// destroy data members for this object
//Widget::~Widget()
//{
//    delete pImpl;
//}

// C++11
// ~Widget definition
//Widget::~Widget()

// same effect as above
Widget::~Widget() = default;


// definitions
// copy constructor
Widget::Widget( const Widget& rhs ) : pImpl( std::make_unique<Impl>( *rhs.pImpl ) )
{
}

// copy assignment operator
Widget& Widget::operator=( const Widget& rhs )
{
    *pImpl = *rhs.pImpl;
    return *this;
}

Widget::Widget( Widget&& rhs ) = default;                   // move constructor
Widget& Widget::operator=( Widget&& rhs ) = default;        // move assignment operator