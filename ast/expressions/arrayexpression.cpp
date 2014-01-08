#include "arrayexpression.h"

using namespace std;

ASTArrayExpression::ASTArrayExpression(list<ASTExpression*> *pContent)
    :ASTExpression(ET_Array),pContent(pContent)
{
    //ctor
}

ASTArrayExpression::~ASTArrayExpression()
{
    //dtor
}
