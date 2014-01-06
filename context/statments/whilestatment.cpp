#include "whilestatment.h"

WhileStatment::WhileStatment(Expression *pBooleanExpression  ,
                      Statment *pDoStatment):Statment(ST_While),pBooleanExpression(pBooleanExpression),pDoStatment(pDoStatment)
{
    //ctor
}

WhileStatment::~WhileStatment()
{
    //dtor
}
