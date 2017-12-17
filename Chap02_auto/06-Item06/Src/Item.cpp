#pragma once

#include <array>
#include <vector>

class Widget
{
};

class Matrix
{
public:
    Matrix operator+( const Matrix &other )
    {
        x += other.x;
        return *this;
    }

private:
    float x = 1;
};

std::vector<bool> features( const Widget& w )
{
    return std::vector<bool>{ false, false, false, true, true, true };
}

void processWidget( const Widget& w, bool priority )
{
    int x = 7;
}

// return tolerance value
double calcEpsilon()
{
    return 0.01f;
}

int main()
{
    Widget w;

    //bool highPriority = features( w )[5];       // is w high priority?
    //processWidget( w, highPriority );           // process w in accord with its priority

    //auto highPriority = features( w )[5];       // is w high priority?
    //processWidget( w, highPriority );           // undefined behavior!

    // auto returns std::vector<bool>::reference here 
    // which results in dangling pointer in features
    auto highPriority = static_cast<bool>(features( w )[5]);
    processWidget( w, highPriority );

    Matrix m1, m2, m3, m4;
    auto sum = static_cast<Matrix>(m1 + m2 + m3 + m4);

    //float ep = calcEpsilon();                 // implicitly convert double => float
    auto ep = static_cast<float>(calcEpsilon());

    std::array<float, 3> c;
    int d = 10;
    //int index = d * c.size();
    auto index = static_cast<int>(d*c.size());

    return 0;
}