#pragma once

#include <string>

class Person
{
public:
    Person( std::string _name ) : name( _name ) {}

    // perfect forwarding ctor.
    // initializers data member
    //template<typename T>
    //explicit Person( T&& n ) : name( std::forward<T>( n ) )
    //{
    //}

    // int ctor
    explicit Person( int idx ) : name( nameFromIdx( idx ) )
    {
    }

    // copy ctor (compiler-generated)
    //Person( const Pewrson& rhs ) {}

    // move ctor (compiler-generated
    //Person( Person&& rhs ) {}


    // instantiated from perfect-forwarding template
    explicit Person( Person& n ) : name( std::forward<Person&>( n ).name )
    {
    }

    // instantiated from template
    explicit Person( const Person& n )
    {
    }


private:
    std::string nameFromIdx( int idx ) { return "name"; }
    std::string name;
};


class SpecialPerson : public Person
{
public:

    // ocpy ctor; calls base class forwarding ctor!
    SpecialPerson( const SpecialPerson& rhs ) : Person( rhs )
    {
    }

    // move ctor; calls base class forwarding ctor!
    SpecialPerson( SpecialPerson&& rhs ) : Person( std::move( rhs ) )
    {

    }
};