#pragma once

class Widget1
{
public:

    template< typename T >
    void processPointer( T* ptr )
    {
    }

private:

    template<>
    void processPointer< void >( void* );       
};



class Widget2
{
public:

    template< typename T >
    void processPointer( T* ptr )
    {
    }
};

//template<>
//void Widget2::processPointer< void >( void ) = delete;