#pragma once

// from C++11 Standard
//template<class T, class... Args>
//shared_ptr<T> make_shared( Args&&... args );

// from C++14 Standard
//template<class T, class... Args>
//unique_ptr<T> make_unique( Args&&... args );


// text is universal reference
//template<typename T>
//void setSignText( T&& text )
//{
//    // use text but don't modify it
//    sign.setText( text );
//
//    // get current time
//    auto now = std::chrono::system_clock_clock::now();
//
//    // conditionally cast text to r-value
//    signHistory.add( now, std::forward<T>( text ) );
//}


class Matrix
{
public:
    // E0344 too many parameters for this operator function
    // https://stackoverflow.com/questions/16291623/operator-overloading-c-too-many-parameters-for-operation
    //friend Matrix operator+( Matrix&& lhs, const Matrix& rhs )
    //{
    //    lhs += rhs;

    //    // move lhs into return vale
    //    return std::move( lhs );
    //}

    //friend Matrix operator+( Matrix&& lhs, const Matrix& rhs )
    //{
    //    lhs += rhs;

    //    // copy lhs into return value
    //    return lhs;
    //}
};



// by-value return universal reference param
//template<typename T>
//Fraction reduceAndCopy( T&& frac )
//{
//    frac.reduce();
//
//    // move r-value into return value, copy l-value
//    return std::forward<T>( frac );
//}