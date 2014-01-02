#include "statment.h"

Statment::Statment(StatmentType type):Node(NT_Statment),type(type)
{

}

Statment::~Statment()
{
    //dtor
}

bool Statment::checkType(StatmentType type)
{
    return this->type==type;
}

