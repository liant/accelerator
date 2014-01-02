#include "returnstatment.h"

ReturnStatment::ReturnStatment(Expression *pReturn):Statment(ST_Return),pReturn(pReturn)
{
    //ctor
}

ReturnStatment::~ReturnStatment()
{
    //dtor
}
