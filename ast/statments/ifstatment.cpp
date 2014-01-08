#include "ifstatment.h"

ASTIfStatment::ASTIfStatment(ASTExpression *pBooleanExpression  ,ASTStatment *pThenStatment,ASTStatment *pElseStatment)
                       :ASTStatment(ST_If),pBooleanExpression(pBooleanExpression),pThenStatment(pThenStatment),pElseStatment(pElseStatment)
{
    //ctor
}

ASTIfStatment::~ASTIfStatment()
{
    //dtor
}
