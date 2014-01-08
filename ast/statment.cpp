#include "statment.h"

ASTStatment::ASTStatment(StatmentType type):ASTNode(NT_Statment),type(type)
{

}

ASTStatment::~ASTStatment()
{
    //dtor
}

bool ASTStatment::checkType(StatmentType type)
{
    return this->type==type;
}

