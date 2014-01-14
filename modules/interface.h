#ifndef MINTERFACE_H
#define MINTERFACE_H

#include "module.h"
#include "template.h"

#include <string>
#include <list>

class Function;

class Interface:public Module
{
    public:
        Interface(std::string name,Template *pTemplate,Module *pParent,Protocol protocol);
        virtual ~Interface();
        std::string name;
        std::list<Class*> mExtendList;
        bool addFunction(Function *pFunction);
        Function *selectFunction(std::string name);
        Template *mTemplate;
    protected:
        std::list<Function*> mContent;
    private:
};

#endif // MINTERFACE_H
