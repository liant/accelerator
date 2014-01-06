#ifndef STATMENTTYPE_H_INCLUDED
#define STATMENTTYPE_H_INCLUDED

//语句类型
enum StatmentType
{
    ST_None,
    ST_Expression,
    ST_Declare,
    ST_Block,
    //条件语句
    ST_If,
    ST_Switch,
    //循环语句
    ST_For,
    ST_While,
    //跳转语句
    ST_Break,
    ST_Continue,
    ST_Return,
    ST_Case,
};


#endif // STATMENTTYPE_H_INCLUDED
