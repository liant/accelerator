#include "classobject.h"
#include "../modules/classobject.h"

ASTClassObject::ASTClassObject(ASTClassType *ptype,ASTToken *pName,ASTExpression *pExpression)
    :ASTNode(NT_ClassObject),ptype(ptype),pName(pName),pExpression(pExpression)
{
    //ctor
}

ASTClassObject::~ASTClassObject()
{
    //dtor
        if(ptype)
            delete ptype;
        if(pName)
            delete pName;
        if(pExpression)
            delete pExpression;
}

ClassObject *ASTClassObject::createModule()
{
    ClassObject *pObject;
    pObject=new ClassObject(nullptr,pName->toString(),nullptr,Protocol_Protected);
    pObject->setClass(ptype->createModule());
    return pObject;

}
