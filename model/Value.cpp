#include "Value.h"

#include <sstream>

using namespace std;

uintptr_t Value::maxid=1;

Value::Value(Type *pType,void *data,intptr_t size)
    :type(pType),name("@object_"),data(data),size(size),readOnly(false),datagen(false)
{
    //ctor
    stringstream snum;
    snum<<maxid++;
    name+=snum.str();
}

Value::Value(Type *pType,string data,intptr_t size)
    :type(pType),name("@object_"),data(nullptr),size(size),readOnly(false),virtualData(data),datagen(false)
{
    //ctor
    stringstream snum;
    snum<<maxid++;
    name+=snum.str();
}

Value::~Value()
{
    //dtor
}

void Value::setReadOnly()
{
    readOnly=true;
}

void Value::clearReadOnly()
{
    readOnly=false;
}
