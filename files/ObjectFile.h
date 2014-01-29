#ifndef OBJECTFILE_H
#define OBJECTFILE_H

#include "FileHeader.h"

#include <string>
#include <fstream>

class Package;
//对象文件,编译完成后的单个文件保存成这种格式
/*
    文件格式:
            文件类型标识:
            文件格式版本号:
            ///////////////////////////////////////////////
            //文件包信息
            //protect package name
            //objects n send
            //关联的包或文件
            //////////////////////////////////////////////////
            //object 信息
            public class name template
            classitem s1,s2,s3;
            //////////////////////////////////
            public enum name
            public interface name
            public delegate name
            ////////////////////////////////////////////
            //函数模块区域
            type 名字 导入参数 block信息//其他信息
            //////////////////////////////////////
            block信息
                instruct list;////////////////////////
            block信息
                instruction list;////////////////////////
            ////////////////////////////////////////////
            变量区域
            变量类型 变量名 变量种类常量还是其他/////////////////////////////
            /////////////////////////////////////////////
            常量区域,记录了一些常量 null true false int float 等等
            //////////////////////////////////////////////
            符号表区域//用来存放符号表
            1 2 342 name等等
            ///////////////////////////////////////////////


*/

class ObjectFile
{
    public:
        ObjectFile();
        virtual ~ObjectFile();
        bool open(std::string name);
        bool create(std::string name);
        void close();
        bool flush();
        bool write(Package *pPackage);
        Package *read();
    protected:
        FileHeader header=FileHeader(0x12032142,0,1);
        //将整个包,以文本方式输出
        void print(Package *pPackage);
    private:
        std::fstream file;
};

#endif // OBJECTFILE_H
