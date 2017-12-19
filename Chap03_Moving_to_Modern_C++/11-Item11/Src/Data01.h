#pragma once

class Calc
{
public:
    bool isLucky( int number )
    {
        return true;
    }

    bool isLucky( char ) = delete;
    bool isLucky( bool ) = delete;
    bool isLucky( double ) = delete;

    template<typename T>
    void processPointer( T* ptr )
    {
    }

    template<>
    void processPointer<void>( void* ) = delete;

    template<>
    void processPointer<char>( char* ) = delete;

    template<>
    void processPointer<const void>( const void* ) = delete;

    template<>
    void processPointer<const char>( const char* ) = delete;
};