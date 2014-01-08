#include "delegate.h"

ASTDelegate::ASTDelegate(ASTFunction *pFunction):ASTNode(NT_Delegate),pFunction(pFunction)
{
    //ctor
}

ASTDelegate::~ASTDelegate()
{
    //dtor
}
