#include "declareexpression.h"

DeclareExpression::DeclareExpression(ClassObjectBlock *pContent)
    :Expression(ET_Declare),pContent(pContent)
{
    //ctor
}

DeclareExpression::~DeclareExpression()
{
    //dtor
}
