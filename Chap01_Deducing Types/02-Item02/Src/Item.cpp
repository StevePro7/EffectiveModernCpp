#pragma once

// conceptual template for deducing x type
template<typename T>
void func_for_x( T param )                  // int
{
}

// conceptual template for deducing cx type
template<typename T>
void func_for_cx( const T param )           // const int
{
}

// conceptual template for deducing rx type
template<typename T>
void func_for_rx( const T& param )          // const int &
{
}

int main()
{
    auto x = 27;            // case 3   x neither ptr nor ref
    const auto cx = x;      // case 3   cx isn't either
    const auto& rx = x;     // case 1   rx is non-universal ref

    func_for_x( 27 );       // conceptual call      param deduced type is x type
    func_for_cx( x );       // conceptual call      param deduced type is cx type
    func_for_rx( x );       // conceptual call      param deduced type is rx type

    // Case 2   Type is universal reference         works as expected
    auto&& uref1 = x;       // x int        lvalue  uref1 type is int&
    auto&& uref2 = cx;      // cx const int lvalue  uref2 type is const int&
    auto&& uref3 = 27;      // 27           rvalue  uref3 type is int&&

    return 0;
}