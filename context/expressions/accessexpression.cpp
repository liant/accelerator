#include "accessexpression.h"

using namespace std;

AccessExpression::AccessExpression(Literal *pLiteral)
    :Expression(ET_Access),pType(nullptr),pLiteral(pLiteral),accessType(AET_Literal)
{
    //ctor
}

AccessExpression::AccessExpression(Expression *pExpression,Token *pToken)
    :Expression(ET_Access),pExpression(pExpression),pToken(pToken),accessType(AET_Expression)
{
    //ctor
}

AccessExpression::AccessExpression(ClassType *pType,Token *pToken)
    :Expression(ET_Access),pType(pType),pToken(pToken),accessType(AET_ClassType)
{
    //ctor
}

AccessExpression::AccessExpression(Expression *pExpression,list<Expression*> *pContent)
    :Expression(ET_Access),pExpression(pExpression),pContent(pContent),accessType(AET_Element)
{
    //ctor
}

AccessExpression::~AccessExpression()
{
    //dtor
}
