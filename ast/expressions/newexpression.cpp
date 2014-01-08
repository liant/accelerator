#include "newexpression.h"

using namespace std;

ASTNewExpression::ASTNewExpression(ASTClassType *pType,list<ASTExpression*> *pParam)
    :ASTExpression(ET_New),pType(pType),pParam(pParam)
{
    //ctor
}

ASTNewExpression::~ASTNewExpression()
{
    //dtor
}
