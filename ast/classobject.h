#ifndef CLASSOBJECT_H
#define CLASSOBJECT_H

#include "node.h"
#include "classtype.h"
#include "expression.h"

class ASTClassObject:public ASTNode
{
    public:
        ASTClassObject(ASTClassType *ptype,ASTToken *pName,ASTExpression *pExpression);
        virtual ~ASTClassObject();
    protected:
        ASTClassType *ptype;
        ASTToken *pName;
        ASTExpression *pExpression;
    private:
};

#endif // CLASSOBJECT_H
