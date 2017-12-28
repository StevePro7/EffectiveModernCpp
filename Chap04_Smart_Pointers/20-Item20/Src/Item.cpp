#pragma once

#include <memory>
#include <unordered_map>

class Widget {};
enum WidgetID {};

auto loadWidget( WidgetID id )
{
    return nullptr;
}

std::shared_ptr<const Widget> fastLoadWidget( WidgetID id )
{
    static std::unordered_map<WidgetID, std::weak_ptr<Widget>> cache;

    // objPtr is std::shared_ptr to cached object (or null if object not in cache)
    auto objPtr = cache[id].lock();

    // if not in cache
    if( !objPtr )
    {
        objPtr = loadWidget( id );
        cache[id] = objPtr;
    }

    return objPtr;
}

int main()
{
    // after spw is constructed, the pointed to Widget's ref count (RC) is 1
    auto spw = std::make_shared<Widget>();

    // wpw points to same Widget as spw. RC remains 1
    std::weak_ptr<Widget> wpw( spw );

    // RC goes to 0, and the Widget is destroyed. wpw now dangles
    spw = nullptr;

    // if wpw doesn't point to an object
    if( wpw.expired() )
    {
        // if wpw is expired then spw1 is null
        std::shared_ptr<Widget> spw1 = wpw.lock();

        // same as above but uses auto
        auto spw2 = wpw.lock();

        // if wpw is expired then throw std::bad_weak_ptr
        //std::shared_ptr<Widget> spw3( wpw );
    }


    // define above generically
    //std::unique_ptr<const Widget> loadWidget( WidgetID id );

    return 0;
}
