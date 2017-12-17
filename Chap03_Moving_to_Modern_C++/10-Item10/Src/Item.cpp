#pragma once

#include <cstdint>
#include <tuple>
#include <vector>

std::vector<std::size_t> primeFactors( std::size_t x )
{
    return std::vector<std::size_t>();
}

//enum ColorX;                                    // error! Note compiles on VS2017
enum class ColorY;

//enum Status
//{
//    good = 0,
//    failed = 1,
//    incomplete = 100,
//    corrupt = 200,
//    indeterminant = 0xFFFFFFFF
//};

// Prefer scoped enum forward declaration
enum class Status : std::uint32_t;


// C++11
template<typename E>
constexpr typename std::underlying_type<E>::type
toUType( E enumerator ) noexcept
{
    return static_cast<typename std::underlying_type<E>::type>(enumerator);
}

// C++14
template<typename E>
constexpr std::underlying_type_t<E>
toUType2( E enumerator ) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

// C++14 sleeker
template<typename E>
constexpr auto
toUType3( E enumerator ) noexcept
{
    return static_cast<std::underlying_type_t<E>>(enumerator);
}

int main()
{
    //enum Color { black, white, red }; // black, white, red are in same scope as Color
    //auto white = false;               // error! white already declared in this scope

    enum class Color { black, white, red };     // black, white, red are scoped to Color
    auto white = false;                         // fine, no other white in scope

    //Color c = white;                          // error! no enumerator named "white" is in this scope
    Color c = Color::white;                     // fine
    auto d = Color::white;                      // fine


    // unscoped enum
    enum Color2 { black2, white2, red2 };
    Color2 c2 = red2;
    auto factors2 = primeFactors( c2 );

    // scoped enum
    enum class Color3 { black3, white3, red3 };
    Color3 c3 = Color3::red3;
    //auto factors3 = primeFactors( c3 );       // errror! can't pass Color to function expecting size_t

    if( static_cast<double>(c3) < 14.5 )
    {
        auto factor3 = primeFactors( static_cast<double>(c3) );     // suspect, but it compiles
    }


    // Example where unscoped enum may be better than scoped : tuple
    using UserInfo = std::tuple<std::string, std::string, std::size_t>;

    // Could not get this code working in Xcode
    //UserInfo uInfo;
    //auto val = std::get<1>( uInfo );

    // Unscoped enum
    //enum UserInfoFields1 { uiName, uiEmail, uiReputation };
    //UserInfo uInfo1;
    //auto val1 = std::get<uiEmail>( uInfo1 );

    // Scoped enum
    //enum class UserInfoFields2 { uiName, uiEmail, uiReputation };
    //UserInfo uInfo2;
    //auto val2 = std::get<uiEmail>( uInfo2 );
    //auto val2 = std::get<static_cast<std::size_t>(UserInfoFields2::uiEmail)>( uInfo2 );

    return 0;
}
