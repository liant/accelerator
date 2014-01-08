#include "expression.h"

Expression::Expression(MInstruction instruction,ClassObject *pResult,ClassObject *pObjectA,ClassObject *pObjectB)
    :instruction(instruction),pResult(pResult),pObjectA(pObjectA),pObjectB(pObjectB)
{
    //ctor
}

Expression::~Expression()
{
    //dtor
}
