#ifndef MINTERFACE_H
#define MINTERFACE_H

#include "../model/Module.h"
#include "template.h"

#include <string>
#include <list>

class Function;

class Interface:public Module
{
    public:
        Interface(std::string name,Template *pTemplate);
        virtual ~Interface();

        Template *pTemplate;
        void build(Context *pContext);
        /*
        std::string name;
        std::list<Class*> mExtendList;
        Function *createFunction(std::string name);
        Function *selectFunction(std::string name);

        std::list<Function*> mContent;
        */
    protected:
        std::list<Interface*> mExtendList;
    private:
};

#endif // MINTERFACE_H
