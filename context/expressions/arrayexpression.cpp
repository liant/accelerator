#include "arrayexpression.h"

using namespace std;

ArrayExpression::ArrayExpression(list<Expression*> *pContent)
    :Expression(ET_Array),pContent(pContent)
{
    //ctor
}

ArrayExpression::~ArrayExpression()
{
    //dtor
}
