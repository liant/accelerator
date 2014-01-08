#include "accessexpression.h"

using namespace std;

ASTAccessExpression::ASTAccessExpression(ASTLiteral *pLiteral)
    :ASTExpression(ET_Access),pType(nullptr),pLiteral(pLiteral),accessType(AET_Literal)
{
    //ctor
}

ASTAccessExpression::ASTAccessExpression(ASTExpression *pExpression,ASTToken *pToken)
    :ASTExpression(ET_Access),pExpression(pExpression),pToken(pToken),accessType(AET_Expression)
{
    //ctor
}

ASTAccessExpression::ASTAccessExpression(ASTClassType *pType,ASTToken *pToken)
    :ASTExpression(ET_Access),pType(pType),pToken(pToken),accessType(AET_ClassType)
{
    //ctor
}

ASTAccessExpression::ASTAccessExpression(ASTExpression *pExpression,list<ASTExpression*> *pContent)
    :ASTExpression(ET_Access),pExpression(pExpression),pContent(pContent),accessType(AET_Element)
{
    //ctor
}

ASTAccessExpression::~ASTAccessExpression()
{
    //dtor
}
