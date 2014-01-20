#ifndef STATMENT_H
#define STATMENT_H

#include "node.h"
#include "statmenttype.h"

class ClassObject;

class ASTStatment:public ASTNode
{
    public:
        ASTStatment(StatmentType type);
        virtual ~ASTStatment();
        bool checkType(StatmentType type);
        ClassObject *retObject;
    protected:
        StatmentType type;
    private:
};

#endif // STATMENT_H
