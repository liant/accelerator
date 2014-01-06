#include "classtype.h"

using namespace std;

ClassType::ClassType():Node(NT_ClassType),simple(true)
{
    //ctor
}

ClassType::ClassType(list<Token*> *pList):Node(NT_ClassType),pNameList(pList),simple(false)
{
    //ctor
}

ClassType::~ClassType()
{
    //dtor
}

void ClassType::setTemplateArgument(std::list<Expression*> *pTemplateArgument)
{
    this->pTemplateArgument=pTemplateArgument;
}
