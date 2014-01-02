#include "classobject.h"

ClassObject::ClassObject(ClassType *ptype,Token *pName,Expression *pExpression)
    :Node(NT_ClassObject),ptype(ptype),pName(pName),pExpression(pExpression)
{
    //ctor
}

ClassObject::~ClassObject()
{
    //dtor
}
