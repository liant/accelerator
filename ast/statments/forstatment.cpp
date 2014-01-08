#include "forstatment.h"

ASTForStatment::ASTForStatment(ASTExpression *pExpression  ,ASTStatment *pBodyStatment)
    :ASTStatment(ST_For),pExpression(pExpression),pBodyStatment(pBodyStatment)
{
    //ctor
}

ASTForStatment::~ASTForStatment()
{
    //dtor
}
