#include "ObjectFile.h"

using namespace std;

ObjectFile::ObjectFile()
{
    //ctor
}

ObjectFile::~ObjectFile()
{
    //dtor
}

bool ObjectFile::open(string name)
{
    file.open(name);
}
bool ObjectFile::create(string name)
{
    file.open(name);
}
void ObjectFile::close()
{
    file.close();
}
bool ObjectFile::flush()
{
    file.flush();
    return true;
}
//核心函数
bool ObjectFile::write(Package *pPackage)
{
    //写入文件头
  //  file.write(&header,sizeof(header));
    //写入包信息

    //逐个写入包的每一项

    //写入函数模块信息

    //写入块信息

    //写入变量信息
    //写入符号表信息
}
//核心函数
Package *ObjectFile::read()
{

}
