#pragma once

#include <memory>

class Investment 
{
public:
    virtual ~Investment() {}            // essential design component!

    void reset( void* args ) {}
};
class Stock : public Investment {};
class Bond : public Investment {};
class RealEstate: public Investment {};

// return std::unique_ptr to an object created from teh given args
template<typename... Ts>
std::unique_ptr<Investment>
makeInvestmentORG( Ts&&... params )
{
    return nullptr;
}

void makeLogEntry( Investment* pInvestment )
{
}

// custom deleter (a lambda expression)
auto delInvmt = []( Investment* pInvestment )
{
    makeLogEntry( pInvestment );
    delete pInvestment;
};

// revised return type
// C++11
template<typename... Ts>
std::unique_ptr<Investment, decltype(delInvmt)>
makeInvestment11( Ts&&... params)
{
    // ptr to be returned
    std::unique_ptr<Investment, decltype(delInvmt)> pInv( nullptr, delInvmt );
    bool test = true;

    if( /* a Stock object should be created */ test )
    {
        pInv->reset( new Stock( std::forward<Ts>( params )... ) );
    }
    else if( /* a Bond object should be created */ test )
    {
        pInv->reset( new Bond( std::forward<Ts>( params )... ) );
    }
    else if(/* a RealEstate object should be created*/ test )
    {
        pInv->reset( new RealEstate( std::forward<Ts>( params )... ) );
    }

    return pInv;
}

// C++14
template<typename... Ts>
auto makeInvestment14( Ts&&... params )
{
    auto delInvmt = []( Investment* pInvestment )
    {
        makeLogEntry( pInvestment );
        delete pInvestment;
    };

    // ptr to be returned
    std::unique_ptr<Investment, decltype(delInvmt)> pInv( nullptr, delInvmt );
    bool test = true;

    if( /* a Stock object should be created */ test )
    {
        pInv->reset( new Stock( std::forward<Ts>( params )... ) );
    }
    else if( /* a Bond object should be created */ test )
    {
        pInv->reset( new Bond( std::forward<Ts>( params )... ) );
    }
    else if(/* a RealEstate object should be created*/ test )
    {
        pInv->reset( new RealEstate( std::forward<Ts>( params )... ) );
    }

    return pInv;
}


/*
// custom deleter as stateless lambda
auto delInvmt1 = []( Investment* pInvestment )
{
    makeLogEntry( pInvestment );
    delete pInvestment;
};

// return type has size of Investment*
template<typename... Ts>
std::unique_ptr<Investment, decltype(delInvmt1)>
makeInvestment1( Ts&&... args )
{
    return nullptr;
}

// custom deleter as function
auto delInvmt2 = []( Investment* pInvestment )
{
    makeLogEntry( pInvestment );
    delete pInvestment;
};

// return type has size of Investment*
// plus at least size of function pointer!
template<typename... Ts>
std::unique_ptr<Investment, void( *)(Investment*)>
makeInvestment2( Ts&&... params )
{
    return nullptr;
}
*/

int main()
{
    // pInvestment is of type std::unique_ptr<Investment>
    auto arguments = 10;
    auto pInvestmentORG = makeInvestmentORG( arguments );

    auto pInvestment11 = makeInvestment11();
    auto pInvestment14 = makeInvestment14();

    return 0;
}
