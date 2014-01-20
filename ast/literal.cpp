#include "literal.h"

#include "../modules/class.h"
#include "../modules/classobject.h"
#include "../modules/function.h"


#include <iostream>

using namespace std;

ASTLiteral::ASTLiteral(LiteralType type,ASTToken *ptoken):ASTNode(NT_Literal),type(type),ptoken(ptoken)
{
    //ctor
}

ASTLiteral::~ASTLiteral()
{
    //dtor
    if(ptoken)
        delete ptoken;
}

bool ASTLiteral::codegen(Module *pModule)
{
    ClassObject *pObject;
    if(pModule->type!=Module_ClassObject)
    {
        cout<<"literal的父模块不是对象."<<endl;
        return false;
    }
    pObject=(ClassObject*)pModule;
    switch(type)
    {
    case TrueLiteral:
    {
        pObject->setObjectType(Object_True);
        break;
    }
    case FalseLiteral:
    {
        pObject->setObjectType(Object_False);
        break;
    }
    case NullLiteral:
    {
        pObject->setObjectType(Object_Null);
        break;
    }
    case CharacterLiteral:
    {
        pObject->setObjectType(Object_Character);
        pObject->setText(ptoken->toString());
        break;
    }
    case StringLiteral:
    {
        pObject->setObjectType(Object_String);
        pObject->setText(ptoken->toString());
        break;
    }
    case IntegerLiteral:
    {
        pObject->setObjectType(Object_Integer);
        pObject->setText(ptoken->toString());
        break;
    }
    case FloatLiteral:
    {
        pObject->setObjectType(Object_Float);
        pObject->setText(ptoken->toString());
        break;
    }
    case ThisLiteral:
    {
        pObject->setObjectType(Object_This);
        break;
    }
    case SuperLiteral:
    {
        pObject->setObjectType(Object_Super);
        break;
    }
    default:
        cout<<"错误的literal."<<endl;
        return false;

    }
    return true;
}
