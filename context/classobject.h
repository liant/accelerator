#ifndef CLASSOBJECT_H
#define CLASSOBJECT_H

#include "node.h"
#include "classtype.h"
#include "expression.h"

class ClassObject:public Node
{
    public:
        ClassObject(ClassType *ptype,Token *pName,Expression *pExpression);
        virtual ~ClassObject();
    protected:
        ClassType *ptype;
        Token *pName;
        Expression *pExpression;
    private:
};

#endif // CLASSOBJECT_H
