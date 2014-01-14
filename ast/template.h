#ifndef TEMPLATE_H
#define TEMPLATE_H

#include "node.h"
#include "classobject.h"
#include <list>

#include "../modules/template.h"

class ASTTemplate:public ASTNode
{
    public:
        ASTTemplate();
        virtual ~ASTTemplate();
        void setContent(std::list<ASTClassObject*> *pContent);
        Template *create();
    protected:
        std::list<ASTClassObject*> *pContent;
    private:
};

#endif // TEMPLATE_H
