#ifndef STATMENT_H
#define STATMENT_H

#include "node.h"
#include "statmenttype.h"

class Statment:public Node
{
    public:
        Statment(StatmentType type);
        virtual ~Statment();
        bool checkType(StatmentType type);
    protected:
        StatmentType type;
    private:
};

#endif // STATMENT_H
