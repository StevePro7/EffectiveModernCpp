#pragma once

//C++98
template<class charT, class traits = char_traits<charT>>
class basic_ios98 : public ios_base
{
public:

private:
    basic_ios98( const basic_ios98 );               // not defined
    basic_ios98& operator=( const basic_ios98& );    // not defined
};


//C++11
template<class charT, class traits = char_traits<charT>>
class basic_ios11 : public ios_base
{
public:

private:
    basic_ios11( const basic_ios11 ) = delete;
    basic_ios11& operator=( const basic_ios11& ) = delete;
};
