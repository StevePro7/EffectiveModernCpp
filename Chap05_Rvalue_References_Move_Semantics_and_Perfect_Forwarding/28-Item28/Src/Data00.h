#pragma once

// not intended to be invoked
template<typename T>
void func( T&& fParam )
{
    someFunc( std::forward<T>( fParam ) );
}


// in namespace std
template<typename T>
T&& forward( typename remove_reference<T>::type& param )
{
    return static_cast<T&&>(param);
}


Widget&& forward( typename remove_reference<Widget&>::type& param )
{
    return static_cast<Widget& &&>(param);
}

Widget& && forward( Widget& param )
{
    return static_cast<Widget& &&>(param);
}

Widget& forward( Widget& param )
{
    return static_cast<Widget&>(param);
}

Widget&& forward( typename remove_reference<Widget>::type& param )
{
    return static_cast<Widget&&>(param);
}

Widget&& forward( Widget& param )
{
    return static_cast<Widget&&>(param);
}


// C++14    still in namespace std
template<typename T>
T&& forward( remove_reference_T<T>& param )
{
    return static_cast<T&&>(param);
}