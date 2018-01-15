#pragma once

#include <assert.h>
#include <string>

class Person00
{
public:
    // Replaces T&& ctor
    explicit Person00( std::string n ) : name( std::move( n ) )
    {
    }

    explicit Person00( int idx ) : name( nameFromIdx( idx ) )
    {
    }

private:
    std::string nameFromIdx( int idx ) { return "name";  }
    std::string name;
};


class Person01
{
public:
    template<typename T, typename = typename std::enable_if<true>::type>
    explicit Person01( T&& n )
    {
    }

private:
    int age;
};


class Person02
{
public:
    template<typename T, typename = typename std::enable_if<!std::is_same<Person02, typename std::decay<T>::type>::value>::type>
    explicit Person02( T&& n )
    {
    }
};


class Person03
{
public:
    template<typename T, typename = typename std::enable_if<!std::is_base_of<Person03, typename std::decay<T>::type>::value>::type>
    explicit Person03( T&& n )
    {
    }
};


// C++14
class Person14
{
public:
    template<typename T, typename = std::enable_if_t<!std::is_base_of<Person14, std::decay_t<T>>::value>>
    explicit Person14( T&& n )
    {
    }
};


class Person05
{
public:
    template<typename T, typename = std::enable_if_t<
        !std::is_base_of<Person05, std::decay_t<T>>::value 
        &&
        !std::is_integral<std::remove_reference_t<T>>::value>>
        explicit Person05( T&& n ) : name( std::forward<T>( n ) )
    {
        // ctor for std::string and args convertible to std::string
        static_assert(std::is_constructible<std::string, T>::value, "Parameter n can't be used to construct a std::string");
    }

    // ctor for integral arguments
    explicit Person05( int idx ) : name( nameFromIdx( idx ) )
    {
    }

private:
    std::string nameFromIdx( int idx ) { return "name"; }
    std::string name;
};


class SpecialPerson : public Person02
{
public:
    // copy ctor; calls base class forwarding ctor!
    SpecialPerson( const SpecialPerson& rhs ) : Person02( rhs )
    {
    }

    // move ctor; calls base class forwarding ctor!
    SpecialPerson( const SpecialPerson&& rhs ) : Person02( std::move( rhs ) )
    {
    }

};
