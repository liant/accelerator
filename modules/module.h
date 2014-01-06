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

class Module
{
    public:
        Module(ModuleType type,ModuleProtocol openProtocol);
        virtual ~Module();
        //将代码写入后端
        virtual bool codegen();
        ModuleProtocol openProtocol;
        ModuleType type;
    protected:

    private:
};

#endif // MODULE_H
