#pragma once

#include <string>
#include "Data00.h"
#include "Data01.h"
#include "Data02.h"
#include "Data03.h"

void processWidget( Widget3 w )
{
}

int main()
{
    Widget0 w0;
    std::string name( "Bart" );

    // call addName with l-value
    w0.addName1( name );

    // call addName with r-value
    w0.addName1( name + "man" );


     Widget1 w1;
     w1.setPtr( std::make_unique<std::string>( "Modern C++" ) );


     std::string initPwd( "Supercalifragilisticexpialidocious" );
     Password p( initPwd );

     std::string newPassword = "Beware the Jabberwock";
     p.changeTo( newPassword );


     // processWidget sees a Widget NOT a SpecialWidget!
     SpecialWidget sw;
     processWidget( sw );

    return 0;
}
