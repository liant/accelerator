#include "declareexpression.h"

ASTDeclareExpression::ASTDeclareExpression(ASTClassObjectBlock *pContent)
    :ASTExpression(ET_Declare),pContent(pContent)
{
    //ctor
}

ASTDeclareExpression::~ASTDeclareExpression()
{
    //dtor
}
