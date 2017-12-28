#pragma once

#include <memory>
#include <vector>

class Widget {};
class ReallyBigType {};

template<typename T, typename... Ts>
std::unique_ptr<T> make_unique( Ts&&... params )
{
    return std::unique_ptr<T>( new T( std::forward<Ts>( params )... ) );
}

void processWidget( std::shared_ptr<Widget> spw, int priority )
{
}
int computePriority()
{
    return 1;
}

auto widgetDeleter = []( Widget* pw )
{
};

// custom deleter
void cusDel( Widget* ptr )
{
}

int main()
{
    // with make function
    auto upw1( std::make_unique<Widget>() );

    // without make function
    std::unique_ptr<Widget> upw2( new Widget );

    // with make function
    auto spw1( std::make_shared<Widget>() );

    // without make function
    std::shared_ptr<Widget> spw2( new Widget );


    // potential resource leak!
    processWidget( std::shared_ptr<Widget>( new Widget), computePriority() );

    // no potential resource leak
    processWidget( std::make_shared<Widget>(), computePriority() );


    std::unique_ptr<Widget, decltype(widgetDeleter)> upw( new Widget, widgetDeleter );
    std::shared_ptr<Widget> spw( new Widget, widgetDeleter );

    auto upv = std::make_unique<std::vector<int>> (10, 20);
    auto spv = std::make_shared<std::vector<int>>( 10, 20 );

    // create std::initializer_list
    auto initList = { 10, 20 };

    //create std::vecotr using std::initializer_list ctor
    auto spv3 = std::make_shared<std::vector<int>>( initList );


    // create very large object via std::make_shared
    auto pBigObj = std::make_shared<ReallyBigType>();

    // create std::shared_ptr and std::wak_ptr to large object, use them to work with it
    // final std::shared_ptr to object destroyed here, but std::weak_ptr to it remain
    // during this period, memory formerly occupied by large object remains allocated
    // final std::weak_ptr to object destroyed here; memory for control block and object is released


    // create very large object via new
    std::shared_ptr<ReallyBigType> pBigObj2( new ReallyBigType );

    // as before, create std::shared_ptr and std::weak_ptr to object, use them with it
    // final std::shared_ptr to object destroyed here, but std::weak_ptr to it reamin; memory for object is deallocated
    // during this period, only memory for the control block remains allocated
    // final std::weak_ptr to object destroyed here; memory for control block is released


    // as before, potential resource leak!
    processWidget( std::shared_ptr<Widget>( new Widget, cusDel ), computePriority() );

    
    // Split out argument...
    std::shared_ptr<Widget> spw4( new Widget, cusDel );

    // correct, but not optimal
    processWidget( spw4, computePriority() );

    // both efficient and exception safe
    processWidget( std::move( spw4 ), computePriority() );

    return 0;
}
