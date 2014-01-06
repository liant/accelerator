#include "ifstatment.h"

IfStatment::IfStatment(Expression *pBooleanExpression  ,Statment *pThenStatment,Statment *pElseStatment)
                       :Statment(ST_If),pBooleanExpression(pBooleanExpression),pThenStatment(pThenStatment),pElseStatment(pElseStatment)
{
    //ctor
}

IfStatment::~IfStatment()
{
    //dtor
}
