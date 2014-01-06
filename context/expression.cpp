#include "expression.h"

Expression::Expression(ExpressionType type):Node(NT_Expression),type(type)
{
    //ctor
}

Expression::~Expression()
{
    //dtor
}
