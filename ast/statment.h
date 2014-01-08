#ifndef STATMENT_H
#define STATMENT_H

#include "node.h"
#include "statmenttype.h"

class ASTStatment:public ASTNode
{
    public:
        ASTStatment(StatmentType type);
        virtual ~ASTStatment();
        bool checkType(StatmentType type);
    protected:
        StatmentType type;
    private:
};

#endif // STATMENT_H
