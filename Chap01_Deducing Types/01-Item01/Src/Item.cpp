// Pg.17
// Function Arguments

#pragma once

// someFunc is a function;
// type is void(int, double)
void someFunc( int, double )
{
}

// f1 param passed by value
template<typename T>
void f1( T param )
{
}

// f2 param passed by reference
template<typename T>
void f2( T& param )
{
}

int main()
{
    // param deduced as ptr-to-func
    // type is void(*)(int, double)
    f1( someFunc );

    // param deduced as ref-to-func
    // type is void(&)(int, double)
    f2( someFunc );
    return 0;
}