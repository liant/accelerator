#ifndef TEMPLATE_H
#define TEMPLATE_H

#include "node.h"
#include "classobject.h"
#include <list>

class Template:public Node
{
    public:
        Template();
        virtual ~Template();
        void setContent(std::list<ClassObject*> *pContent);
    protected:
        std::list<ClassObject*> *pContent;
    private:
};

#endif // TEMPLATE_H
