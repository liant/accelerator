#ifndef BREAKSTATMENT_H
#define BREAKSTATMENT_H

#include "../statment.h"

class Module;

class ASTBreakStatment:public ASTStatment
{
    public:
        ASTBreakStatment();
        virtual ~ASTBreakStatment();
        bool codegen(Module *pModule);
    protected:
    private:
};

#endif // BREAKSTATMENT_H
