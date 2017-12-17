#pragma once

#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include <type_traits>

typedef std::unique_ptr<std::unordered_map<std::string, std::string>> UPtrMapSS;
using UPtrMapSS = std::unique_ptr<std::unordered_map<std::string, std::string>>;

// FP is a synonym for a pointer to a function taking an int and
// a const std::string& and returning nothing
typedef void( *FP )(int, const std::string&);   // typedef
using FP = void( *)(int, const std::string&);   // alias declaration


template<typename T>
class MyAlloc
{
};

// MyAllocList<T> is synonym for std::list<T, MyAlloc<T>>
template<typename T>
using MyAllocList = std::list<T, MyAlloc<T>>;

// MyAllocList2<T> is synonym for std::list<T, MyAlloc<T>>
template<typename T>
struct MyAllocList2
{
    typedef std::list<T, MyAlloc<T>> type;
};

template<typename T>
class Widget2
{
private:
    typename MyAllocList2<T>::type list;
};

template<typename T>
class Widget
{
    // no "typename" no "::type"
private:
    MyAllocList<T> list;
};


class Wine
{
};

// MyAllocList2 specialization for when T is Wine
template<>
class MyAllocList2<Wine>
{
private:
    enum class WineType { White, Red, Rose };
    WineType type;              // in this class, type is a data member!
};


int main()
{
    //MyAllocList<Widget> lw;           // client code
    //MyAllocList<Widget>::type lw;     // client code


    //std::remove_const<T>::type;         // C++11 const T=>T
    //std::remove_const_t<T>;             // C++14 equivalent
    //std::remove_reference<T>::type;     // C++11 T&/T&&=>T
    //std::remove_reference_t<T>;         // C++14 equivalent
    //std::add_lvalue_reference<T>::type; // C++11 T=>T&
    //std::add_lvalue_reference_t<T>;     // C++14 equivalent


    //template<class T>
    //using remove_const_t = typename remove_const<T>::type;
    //template<class T>
    //using remove_reference_t = typename remove_reference<T>::type;
    //template<class T>
    //using add_lvalue_reference_t = typename add_lvalue_reference<T>::type;

    return 0;
}