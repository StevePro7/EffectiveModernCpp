#pragma once

#include <string>

class Password
{
public:
    // pass by value    // construct text
    explicit Password( std::string pwd ) : text( std::move( pwd ) )
    {
    }

    // pass by value    // assign text
    void changeTo( std::string newPwd )
    {
        text = std::move( newPwd );
    }

private:
    // text of password
    std::string text;
};


class Password2
{
public:
    // the overload for l-values
    void changeTo( const std::string& newPwd )
    {
        text = newPwd;
    }

private:
    // text of password
    std::string text;
};