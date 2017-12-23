#pragma once

#include <map>
#include <string.h>

class StringTable
{
public:
    StringTable() 
    {
        makeLogEntry( "Creating StringTable object" );
    }

    ~StringTable()
    {
        makeLogEntry( "Destroying StringTable object" );
    }

private:
    void makeLogEntry( const std::string& text) {}
    std::map<int, std::string> values;
};