#ifndef CLASSTYPE_H
#define CLASSTYPE_H

#include "token.h"
#include "expression.h"

#include <list>

class ClassType:public Node
{
    public:
        ClassType();
        ClassType(std::list<Token*> *pList);
        virtual ~ClassType();
        void setTemplateArgument(std::list<Expression*> *pTemplateArgument);
    protected:
        std::list<Token*> *pNameList;
        std::list<Expression*> *pTemplateArgument;

    private:
        bool simple;

};

#endif // CLASSTYPE_H
