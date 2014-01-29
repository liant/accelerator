#include "ObjectFile.h"
#include "FileHeader.h"
#include "FilePrinter.h"
#include <iostream>
#include <cassert>
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
    return true;
}
bool ObjectFile::create(string name)
{
    file.open(name);
    return true;
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
    /*
    private module-name enum-name supertype extendtype
    //上面全是索引信息
    函数信息
    private module-class supertype extendtype................
        template-param
        private 3 4 5 6;
        private moudle-name function-name type param-type param-type
    //写入块信息
    instructionBlock
    {
        instruction //////////////////////
        instruction ////////////////////
        add 3 4 5   //////////////////////
        add 6 5 4   ////////////////////
    }
    //写入变量堆栈
    id type-name value-name offset size
    1   Int         x        0      0
    //常量表,常理有 string int float bool 等几种
    0 0 1;
    ///////////////////////////////
    //写入元数据
    字符串id  行数 列数 //其他未知信息,按照元数据的顺序进行罗列
    block 122
    line 1 32 2 3 2 2 ////////////////////////////////////
    ////////////////////////////
    //写入符号表信息
    字符串信息
    4this5imwhy6thengh
    */
}
//核心函数
Package *ObjectFile::read()
{
    return nullptr;
}

void ObjectFile::print(Package *pPackage)
{
    assert(pPackage);
     //模块总数量
     FilePrinter print(file);
     print.printHeader(&header);
     print.printPackage(pPackage);
     print.printBlocks(pContext);
     print.printValues(pContext);
     print.printData(pContext);
     print.printMeta(pContext);
     print.printTable(pContext);
    ///////////////////////////////////////////////////////////
    //写入块信息
    file<<"section block:"<<endl;
    file<<"     block0:"<<header.magic<<endl;
    file<<"         add 0 3 4;"<<endl;
    file<<"     block1:"<<header.magic<<endl;
    file<<"         add 0 3 4;"<<endl;
    //写入变量信息
    file<<"section values:"<<endl;
    file<<"     valueID     type     name    data"<<endl;
    file<<"         type = name"<<endl;
    file<<"         name = name"<<endl;
    file<<"         data = null"<<endl; //实际数据信息
    //数据表
    file<<"section data:"<<endl;
    file<<"     data0:"<<header.magic<<endl;
    file<<"         value = 0"<<endl;
    ///////////////////////////////
    //写入元数据
    file<<"section meta:"<<endl;
    file<<"     line1:"<<endl;
    file<<"         type    string column"<<endl;
    file<<"         identify  0     0"<<endl; //表示未能识别的,通常由外部导入
    file<<"         class     4     0"<<endl;
    file<<"         package     4     0"<<endl;
    file<<"         value     4     0"<<endl;
    file<<"         enum     4     0"<<endl;
    file<<"         delegate     4     0"<<endl;
    file<<"         function     4     0"<<endl;
    file<<"         function-param   4     0"<<endl;
    file<<"         template-param     4     0"<<endl;
    ///////////////////////////////
    //写入字符串标识
    file<<"section string:"<<endl;
    file<<"     string0 this"<<endl;
    file<<"     string1 this"<<endl;
    file<<"     string2 this"<<endl;
    file<<"     string3 this"<<endl;
    file<<"     string4 this"<<endl;


}
