#include "constantexpression.h"

ConstantExpression::ConstantExpression(Expression *pExpression)
        :Expression(ET_Constant),pExpression(pExpression),pLiteral(0),pType(0)
{
    //ctor
}

ConstantExpression::ConstantExpression(Literal *pLiteral)
:Expression(ET_Constant),pExpression(0),pLiteral(pLiteral),pType(0)
{

}
        ConstantExpression::ConstantExpression(ClassType *pType)
                :Expression(ET_Constant),pExpression(0),pLiteral(0),pType(pType)
        {

        }

ConstantExpression::~ConstantExpression()
{
    //dtor
}
