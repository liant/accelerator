#include "Value.h"
#include "../log/Log.h"

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

Value::Value(Type *pType,std::string name)
:type(pType),name(name),data(nullptr),size(0),readOnly(false),datagen(false)
{
    stringstream snum;
    snum<<maxid++;
    name+=snum.str();
}

Value::Value()
:type(nullptr),name("@object_"),data(nullptr),size(0),readOnly(false),datagen(false)
{

}


Value::~Value()
{
    //dtor
    if(type){
        delete type;
    }
}

void Value::setReadOnly()
{
    readOnly=true;
}

void Value::clearReadOnly()
{
    readOnly=false;
}

void Value::build(Context *pContext)
{
    //载入一个对象,可能是类 枚举 委托 或者接口
//    pObject=pContext->loadObject(type);
    if(pObject==nullptr){
        //没有该类型的对象
        Log::error("错误的值类型.");
    }
    //根据pObject的初始化函数,来构造类的对象.
}
