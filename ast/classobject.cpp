#include "classobject.h"

ASTClassObject::ASTClassObject(ASTClassType *ptype,ASTToken *pName,ASTExpression *pExpression)
    :ASTNode(NT_ClassObject),ptype(ptype),pName(pName),pExpression(pExpression)
{
    //ctor
}

ASTClassObject::~ASTClassObject()
{
    //dtor
}
