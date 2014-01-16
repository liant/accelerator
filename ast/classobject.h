#ifndef CLASSOBJECT_H
#define CLASSOBJECT_H

#include "node.h"
#include "classtype.h"
#include "expression.h"

class ClassObject;

class ASTClassObject:public ASTNode
{
    public:
        ASTClassObject(ASTClassType *ptype,ASTToken *pName,ASTExpression *pExpression);
        virtual ~ASTClassObject();
        ClassObject *createModule();
        ASTClassType *ptype;
        ASTToken *pName;
        ASTExpression *pExpression;
    protected:

    private:
};

#endif // CLASSOBJECT_H
