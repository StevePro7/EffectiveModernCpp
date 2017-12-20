#pragma once

#include <vector>

typedef std::vector<int>::iterator IterT;
typedef std::vector<int>::const_iterator ConstIterT;

// In container, find first occurrence of targetVal, then insert insertVal there
template<typename C, typename V>
void findAndInsert( C& container, const V& targetVal, const V& insertVal )
{
    using std::cbegin;
    using std::cend;

    // non-member cbegin and cend
    auto it = std::find( cbegin( container ), cend( container ), targetVal );
    container.insert( it, insertVal );
}

// C++11 equivalent
//template<class C>
//auto cbegin( const C& container )->decltype(std::begin( container ))
//{
//    return std::begin( container );
//}

int main()
{
    std::vector<int> values;

    std::vector<int>::iterator it = std::find( values.begin(), values.end(), 1983 );
    values.insert( it, 1998);

    // Not compile  no suitable user-defined conversion from ConstIterT to IterT exists
    //ConstIterT ci = std::find( static_cast<ConstIterT>(values.begin()), static_cast<ConstIterT>(values.end()), 1983 );
    //values.insert( static_cast<IterT>(ci), 1998 );

    // Code that uses const_iterator that is practical
    auto ci = std::find( values.cbegin(), values.cend(), 1983 );
    values.insert( ci, 1998 );

    return 0;
}
