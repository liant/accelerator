#include "literal.h"

ASTLiteral::ASTLiteral(LiteralType type,ASTToken *ptoken):ASTNode(NT_Literal),type(type),ptoken(ptoken)
{
    //ctor
}

ASTLiteral::~ASTLiteral()
{
    //dtor
    if(ptoken)
        delete ptoken;
}
