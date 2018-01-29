#pragma once

class SomeCompilerGeneratedClassName
{
public:
    template<typename T>
    auto operator()( T x ) const
    {
        return func( normalize( x ) );
    }
};

// in namespace std
//template<typename T>
//T&& forward( remove_reference_t<T>& param )
//{
//    return static_cast<T&&>(param);
//}

// instantiation of std::forward when T is Widget
class Widget;
Widget&& forward( Widget& param )
{
    return static_cast<Widget&&>(param);
}

// instantiation of std::forward when T is Widget&&
// (before reference collapsing)
//Widget&& && forward( Widget& param )
//{
//    return static_cast<Widget&& &&>(param);
//}

// instantiation of std::forward when T is Widget&&
// (after reference collapsing)
Widget&& forward2( Widget& param )
{
    return static_cast<Widget&&>(param);
}

int main()
{
    //auto f = []( auto x ) { return func( normalize( x ) ); }

    //auto f = []( auto&& x ) { return func( normalize( std::forward<int>( x ) ) ); }

    auto f = []( auto&& param )
    {
        //return func( normalize( std::forward<decltype(param)>( param ) ) );
    };

    auto f2 = []( auto&&... params )
    {
        //return func( normalize( std::forward<decltype(params)>( params )... ) );
    };

    return 0;
}
