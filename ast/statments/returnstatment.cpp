#include "returnstatment.h"

ASTReturnStatment::ASTReturnStatment(ASTExpression *pReturn):ASTStatment(ST_Return),pReturn(pReturn)
{
    //ctor
}

ASTReturnStatment::~ASTReturnStatment()
{
    //dtor
}
