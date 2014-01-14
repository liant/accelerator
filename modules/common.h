#ifndef COMMON_H_INCLUDED
#define COMMON_H_INCLUDED

enum ModuleType
{
    Module_Package,
    Module_Class,
    Module_ClassObject,
    Module_Interface,
    Module_Delegate,
    Module_Enum,
    Module_Function,
    Module_Statment,
    Module_Expression,
    Module_Block,
};

//模块开放性
enum Protocol
{
    Protocol_Public,
    Protocol_Protected,
    Protocol_Private,
};

enum Attribute
{
    Attribute_None=0,
    Attribute_Static=1,
    Attribute_Const=2,
    Attribute_Virtual=4,
    Attribute_Final=8,
    Attribute_Set=16,
    Attribute_Get=32,
    Attribute_Operator=64,
};

#endif // COMMON_H_INCLUDED
