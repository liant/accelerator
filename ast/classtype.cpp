#include "classtype.h"

#include "../modules/expression.h"
#include "../modules/block.h"
#include "../modules/classobject.h"
#include "../modules/class.h"

#include <iostream>
#include <string>
#include <list>

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
    Class *pClass;
    list<string> *pnamelist;
    pnamelist=nullptr;
    pnamelist=new list<string>();
    if(simple==true){
            pnamelist->push_back("Void");
    }else if(pNameList){
        for(auto item:*pNameList)
        {
            pnamelist->push_back(item->toString());
        }
    }
    list<ClassObject*> *pvaluelist;
    Block *pBlock;
    pvaluelist=nullptr;
    pBlock=nullptr;
    if(pTemplateArgument){
        pvaluelist=new list<ClassObject*>();

        pBlock=new Block();
        for(auto item:*pTemplateArgument)
        {
            item->codegen(pBlock);
            pvaluelist->push_back(item->retObject);
        }
    }
    pClass=new Class(pnamelist);
    pClass->setTemplateParam(pvaluelist,pBlock);

    return pClass;
}
