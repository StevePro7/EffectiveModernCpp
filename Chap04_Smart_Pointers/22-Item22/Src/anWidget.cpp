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

Widget::Widget() : pImpl( std::make_unique<Impl>() )
{
}

// ~Widget definition
//Widget::~Widget()

// same effect as above
Widget::~Widget() = default;
