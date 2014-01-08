#include "whilestatment.h"

ASTWhileStatment::ASTWhileStatment(ASTExpression *pBooleanExpression  ,ASTStatment *pDoStatment)
        :ASTStatment(ST_While),pBooleanExpression(pBooleanExpression),pDoStatment(pDoStatment)
{
    //ctor
}

ASTWhileStatment::~ASTWhileStatment()
{
    //dtor
}
