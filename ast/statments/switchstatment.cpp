#include "switchstatment.h"

using namespace std;

ASTSwitchStatment::ASTSwitchStatment(ASTExpression *pExpression,list<ASTStatment*> *pBody)
    :ASTStatment(ST_Switch),pExpression(pExpression),pBody(pBody)
{
    //ctor
}

ASTSwitchStatment::~ASTSwitchStatment()
{
    //dtor
}
