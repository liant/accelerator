#include "FilePrinter.h"
#include "../modules/package.h"
#include "../model/Type.h"
#include "../model/Protocol.h"

using namespace std;

FilePrinter::FilePrinter(fstream &file):file(file)
{
    //ctor
}

FilePrinter::~FilePrinter()
{
    //dtor
}

void FilePrinter::printHeader(const FileHeader *pheader)
{
    //写入文件头
    file<<"section header:"<<endl;
    file<<"     magic = "<<pheader->magic<<endl;
    file<<"     version = "<<pheader->major<<"."<<pheader->minor<<endl;
}

void FilePrinter::printPackage(const Package *pPackage)
{
    //写入包节信息
    file<<"section package:"<<endl;
    file<<"     protocol = ";
    printProtocol(pPackage->protocol);
    file<<endl;
    file<<"     fullname = ";
    printType(pPackage->packagename);
    file<<endl;
    file<<"     name = "<<pPackage->name<<endl;
    for(auto item:pPackage->mImports) {
        file<<"     import module: ";
        printType(item);
        file<<endl;
    }
    for(auto item:pPackage->mChildren) {
        file<<"     submodule = "<<item->name<<endl;
    }
    file<<"section modules:"<<endl;
    for(auto item:pPackage->mChildren) {
        switch(item->moduleType) {
        case Module_Class: {
            printClass((Class*)item);
            break;
        }
        case Module_Delegate: {
            printDelegate((Delegate*)item);
            break;
        }
        case Module_Enum: {
            printEnum((Enum*)item);
            break;
        }
        case Module_Interface: {
            printInterface((Interface*)item);
            break;
        }
        default: {
            file<<"     unknow module;"<<endl;
            break;
        }
        }
    }
    file<<"     protected delegate send:"<<header.magic<<endl;
    file<<"         type = sss"<<header.magic<<endl;
    file<<"         param = sss"<<header.magic<<endl;
}

void FilePrinter::printProtocol(Protocol protocol)
{
    switch(protocol) {
    case Protocol_Private: {
        file<<"private";
        break;
    }
    case Protocol_Public: {
        file<<"public";
        break;
    }
    case Protocol_Protected: {
        file<<"protected";
        break;
    }
    default:
        file<<"unknow";
        break;
    }
}

void FilePrinter::printType(Type *type)
{
    unsigned int i=1;
    for(auto item:type->mName) {
        file<<item;
        if(i<type->mName.size()) {
            file<<".";
            i++;
        }
    }
}

void printClass(Class *pClass)
{
    //输出定义  protocol class name
    file<<"     ";
    printProtocol(pClass->protocol);
    file<<" class ";
    file<<pClass->name<<endl;
    //输出模板接口
    file<<"         template-param = int x"<<endl;
    //输出父类
    file<<"         super = int x"<<endl;
    //输出扩展接口列表
    file<<"         extend = send"<<header.magic<<endl;
    //输出子模块函数
    file<<"         submodule = name function feng s def ss"<<endl;
    -++++++++++++++++++++++++++++++++++++++-+++++++++++++++++++++++++++++++++++++++++-


    file<<"     module object:"<<header.magic<<endl; //值模块,用于记录类对象
    file<<"         name = send "<<header.magic<<endl;
    file<<"         type = send "<<header.magic<<endl;
    file<<"         attribute = send "<<header.magic<<endl;
    file<<"         block = null"<<header.magic<<endl;

    file<<"     module function:"<<header.magic<<endl; //值模块,用于记录类对象
    file<<"         name = send "<<header.magic<<endl;
    file<<"         type = send "<<header.magic<<endl;
    file<<"         param = send feng send "<<header.magic<<endl;
    file<<"         attribute = send "<<header.magic<<endl;
    file<<"         block = null"<<header.magic<<endl;
}
void FilePrinter::printEnum(Enum *pEnum)
{
    //输出定义  protocol enum name
    file<<"     ";
    printProtocol(pEnum->protocol);
    file<<" enum ";
    file<<pEnum->name<<endl;
    //输出父枚举  super = name
    file<<"         super = ";
    if(pEnum->pSuper) printType(pEnum->pSuper);
    else file<<"null"<<endl;
    //输出扩展枚举 extend = name
    file<<"         extend = ";
    if(pEnum->pExtend) printType(pEnum->Extend);
    else file<<"null"<<endl;
    //输出枚举子向量
    for(auto item:pEnum->pBlock->mValues){
        file<<"         value "<<item->name<<endl;
    }

}
void FilePrinter::printDelegate(Delegate *pDelegate)
{
    //输出定义  protocol delegate name
    file<<"     ";
    printProtocol(pDelegate->protocol);
    file<<" delegate ";
    file<<pDelegate->name<<endl;
    //输出类型 type = int
    file<<"         type = ";
    printType(pDelegate->pfun->pType);
    file<<endl;
    for(auto item:pDelegate->pfun->mParams) {
        file<<"         params:"<<endl;
        file<<"             ";printType(item->type);file<<" ";file<<item->name;file<<endl;
    }

}
void FilePrinter::printInterface(Interface *pInterface)
{
    //输出定义  protocol interface name
    file<<"     ";
    printProtocol(pDelegate->protocol);
    file<<" interface ";
    file<<pDelegate->name<<endl;
    //输出模板接口
    file<<"         template-param = int x"<<endl;
    //输出扩展接口列表
    file<<"         extend = send"<<header.magic<<endl;
    //输出子模块函数
    file<<"         submodule = name function feng s def ss"<<endl;
}
