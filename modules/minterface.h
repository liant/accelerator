#ifndef MINTERFACE_H
#define MINTERFACE_H

#include "module.h"
#include "mtemplate.h"
#include "mfunction.h"

#include <string>
#include <list>

class MInterface:public Module
{
    public:
        MInterface(std::string name,MTemplate *pTemplate=nullptr,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~MInterface();
        std::string name;
        std::list<MInterface*> mExtendList;
        bool addFunction(MFunction *pFunction);
        MFunction *selectFunction(std::string name);
        MTemplate *mTemplate;
    protected:
        std::list<MFunction*> mContent;
    private:
};

#endif // MINTERFACE_H
