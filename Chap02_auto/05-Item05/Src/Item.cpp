#pragma once

#include <functional>
#include <iostream>
#include <memory>

using namespace std;

// algorithm to dwim (do what I mean)
template<typename IT>
void dwim( IT b, IT e )
{
    while( b != e )
    {
        //typename std::iterator_tratis<IT>::value_type currValue = *b;
        auto currValue = *b;
    }
}


class Widget
{
public:
    Widget operator<( Widget &other )
    {
        return data < other.data ? *this : other;
    }

private:
    int data;
};


int main()
{
    int x1;         // potentially uninitialized
    //auto x2;        // error! initializer required
    auto x3 = 0;    // fine x's value is well-defined

    //auto derefUPLess =
    //    []( const std::unique_ptr<Widget>& p1,
    //        const std::unique_ptr<Widget>& p2 )
    //{
    //    return *p1 < *p2;
    //};

    auto derefUPLess =
        []( const auto& p1,
            const auto& p2 )
    {
        return *p1 < *p2;
    };

    //std::function<bool( const std::unique_ptr<Widget>&, const std::unique_ptr<Widget>& )>
    //    derefUPLess = []( const std::unique_ptr<Widget>& p1, const std::unique_ptr<Widget>& p2 )
    //{
    //    return *p1 < *p2;
    //};

    int m[5] = { 1, 2, 3, 4, 5 };
    int sum = 0;
    for( const auto& p : m )
    {
        sum += p;
    }

    cout << "Sum = " << sum << endl;
    cin >> sum;

    return 0;
}
