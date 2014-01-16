#include "constantexpression.h"

ASTConstantExpression::ASTConstantExpression(ASTExpression *pExpression)
    :ASTExpression(ET_Constant),pExpression(pExpression),pLiteral(0),pType(0)
{
    //ctor
}

ASTConstantExpression::ASTConstantExpression(ASTLiteral *pLiteral)
    :ASTExpression(ET_Constant),pExpression(0),pLiteral(pLiteral),pType(0)
{

}
ASTConstantExpression::ASTConstantExpression(ASTClassType *pType)
    :ASTExpression(ET_Constant),pExpression(0),pLiteral(0),pType(pType)
{

}

ASTConstantExpression::~ASTConstantExpression()
{
    //dtor
}
