#include "literal.h"

Literal::Literal(LiteralType type,Token *ptoken):Node(NT_Literal),type(type),ptoken(ptoken)
{
    //ctor
}

Literal::~Literal()
{
    //dtor
    if(ptoken)
        delete ptoken;
}
