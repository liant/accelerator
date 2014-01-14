#include "classtype.h"

using namespace std;

ASTClassType::ASTClassType():ASTNode(NT_ClassType),simple(true)
{
    //ctor
}

ASTClassType::ASTClassType(list<ASTToken*> *pList):ASTNode(NT_ClassType),pNameList(pList),simple(false)
{
    //ctor
}

ASTClassType::~ASTClassType()
{
    //dtor
}

void ASTClassType::setTemplateArgument(std::list<ASTExpression*> *pTemplateArgument)
{
    this->pTemplateArgument=pTemplateArgument;
}

Class *ASTClassType::createModule()
{
  //  Class *pClass;
//    pClass=new Class(null,nullptr,nullptr,Protocol_Protected);
    return nullptr;
}
