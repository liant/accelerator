#ifndef MINTERFACE_H
#define MINTERFACE_H

#include "module.h"
#include "template.h"
#include "function.h"

#include <string>
#include <list>

class Interface:public Module
{
    public:
        Interface(std::string name,Template *pTemplate=nullptr,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~Interface();
        std::string name;
        std::list<Interface*> mExtendList;
        bool addFunction(Function *pFunction);
        Function *selectFunction(std::string name);
        Template *mTemplate;
    protected:
        std::list<Function*> mContent;
    private:
};

#endif // MINTERFACE_H
