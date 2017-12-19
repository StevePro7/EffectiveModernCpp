#pragma once

class Widget
{
public:
    template<typename T>
    void processPointer( T* ptr )
    {
    }
};


template<>
void Widget::processPointer<void>( void* )
{
}

template<>
void Widget::processPointer<char>( char* )
{
}

template<>
void Widget::processPointer<const void>( const void* )
{
}

template<>
void Widget::processPointer<const char>( const char* )
{
}
