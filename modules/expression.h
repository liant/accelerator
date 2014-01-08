#ifndef MEXPRESSION_H
#define MEXPRESSION_H

//表达式
#include "instruction.h"
#include "classobject.h"

class Expression
{
    public:
        Expression(MInstruction instruction,ClassObject *pResult,ClassObject *pObjectA,ClassObject *pObjectB);
        virtual ~Expression();
        MInstruction instruction;
        ClassObject *pResult;
        ClassObject *pObjectA;
        ClassObject *pObjectB;

    protected:
    private:
};

#endif // MEXPRESSION_H
