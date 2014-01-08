#ifndef MODULE_H
#define MODULE_H

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
};

//模块开放性
enum ModuleProtocol
{
    ModuleProtocol_Public,
    ModuleProtocol_Protected,
    ModuleProtocol_Private,
};

enum ModuleAttribute
{
    ModuleAttribute_None=0,
    ModuleAttribute_Static=1,
    ModuleAttribute_Const=2,
    ModuleAttribute_Virtual=4,
    ModuleAttribute_Final=8,
    ModuleAttribute_Set=16,
    ModuleAttribute_Get=32,
};

class Module
{
    public:
        Module(ModuleType type,ModuleProtocol openProtocol);
        virtual ~Module();
        //将代码写入后端
        virtual bool codegen();
        bool checkAttribute(ModuleAttribute attribute);
        ModuleProtocol openProtocol;
        ModuleType type;
        ModuleAttribute attribute;
    protected:

    private:
};

#endif // MODULE_H
