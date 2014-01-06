#include "forstatment.h"

ForStatment::ForStatment(Expression *pExpression  ,Statment *pBodyStatment)
    :Statment(ST_For),pExpression(pExpression),pBodyStatment(pBodyStatment)
{
    //ctor
}

ForStatment::~ForStatment()
{
    //dtor
}
