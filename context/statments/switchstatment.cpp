#include "switchstatment.h"

using namespace std;

SwitchStatment::SwitchStatment(Expression *pExpression,list<Statment*> *pBody)
    :Statment(ST_Switch),pExpression(pExpression),pBody(pBody)
{
    //ctor
}

SwitchStatment::~SwitchStatment()
{
    //dtor
}
