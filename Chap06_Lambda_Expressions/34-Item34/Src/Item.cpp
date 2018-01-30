#pragma once

#include <chrono>
#include <functional>
#include "Data00.h"

using namespace std::chrono;
using namespace std::literals;
using namespace std::placeholders;                      // needed for use of "_1"

// typedef for a point in time
using Time = std::chrono::steady_clock::time_point;
using Duration = std::chrono::steady_clock::duration;

enum class Sound { Beep, Siren, Whistle };
enum class Volume { Normal, Loud, LoadPlusPlus };
enum class CompLevel{ Low, Normal, High };              // compression level

// at time t, make sound s, for duration d
void setAlarm( Time t, Sound s, Duration d )
{
}

// make compressed copy of w
Widget compress( const Widget& w, CompLevel lev )
{
    Widget w2;
    return w2;
}

int main()
{
    // setSoundL ("L" for "lambda") is a function object allowing a sound
    // to be specified for a 30-sec alarm to go off an hour after it's set
    auto setSoundL = []( Sound s )
    {
        // make std::chrono components available w/o qualification
        using namespace std::chrono;
        setAlarm( steady_clock::now() + hours( 1 ), s, seconds( 30 ) );
    };

    auto setSoundL2 = []( Sound s )
    {
        using namespace std::chrono;
        using namespace std::literals;                  // for C++14 suffixes
        setAlarm( steady_clock::now() + 1h, s, 30s );   // C++14 but same meaning as above
    };

    // book says incorrect
    auto setSoundB = std::bind( setAlarm, steady_clock::now() + 1h, _1, 30s );
    auto setSoundB2 = std::bind( setAlarm, std::bind( std::plus<>(), steady_clock::now(), 1h ), _1, 30s );

    auto setSoundB3 = std::bind( setAlarm,
        std::bind( std::plus<steady_clock::time_point>(),
            steady_clock::now(),
            hours( 1 ) ),
        _1,
        seconds( 30 ) );

    // book says error! which alarm 
    auto setSoundB4 = std::bind( setAlarm,
        std::bind( std::plus<>(),
            steady_clock::now(),
            1h ),
        _1,
        30 );

    using SetAlarm3ParamType = void( *)(Time t, Sound s, Duration d);
    
    auto setSoundB5 = std::bind( static_cast<SetAlarm3ParamType>(setAlarm),
        std::bind( std::plus<>(),
            steady_clock::now(),
            1h ),
        _1,
        30s );

    // body of setAlarm may well be in-lined here
    setSoundL( Sound::Siren );

    // body of setAlarm less likely to be in-lined here
    setSoundB( Sound::Siren );


    int lowVal = { 0 };
    int highVal = { 0 };

    // C++14
    auto betweenL = [lowVal, highVal](const auto& val)
    {
        return lowVal <= val && val <= highVal;
    };

    // C++14
    auto betweenB = std::bind( std::logical_and<>(),
        std::bind( std::less_equal<>(), lowVal, _1 ),
        std::bind( std::less_equal<>(), _1, highVal ) );

    auto bewteenL2 = [lowVal, highVal]( int val )
    {
        return lowVal <= val && val <= highVal;
    };


    Widget w;

    // std::bind always copies arguments but callers can achive the 
    // effect of having an argument stored by reference std::ref()
    auto compressRateB = std::bind( compress, w, _1 );
    auto compressRateB2 = std::bind( compress, std::ref( w ), _1 );

    // w is capture by value; lev is passed by value
    auto compressRateL = [w]( CompLevel lev )
    {
        return compress( w, lev );
    };

    // argument is passed by value
    compressRateL( CompLevel::High );

    // how is argument passed?
    compressRateB( CompLevel::High );


    PolyWidget pw;
    auto boundPW = std::bind( pw, _1 );

    // pass int to PolyWidget::operator()
    boundPW( 1936 );

    // pass nullptr to PolyWidget::operator()
    boundPW( nullptr );

    //pass string literal to PolyWidget::operator()
    boundPW( "stevepro" );

    // C++14
    auto boundPW2 = [pw]( const auto& param )
    {
        pw( param );
    };

    return 0;
}
