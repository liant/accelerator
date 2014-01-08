#ifndef MTEMPLATE_H
#define MTEMPLATE_H

#include "classobject.h"

#include <list>
#include <string>

class Template
{
    public:
        Template();
        virtual ~Template();
        bool pushParams(ClassObject *pObject);
        ClassObject *selectParams(std::string name);
    protected:
        std::list<ClassObject*> mContent;
    private:
};

#endif // MTEMPLATE_H
