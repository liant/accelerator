#ifndef BLOCKSTATMENT_H
#define BLOCKSTATMENT_H

#include "../statment.h"

#include <list>

class ASTBlockStatment:public ASTStatment
{
    public:
        ASTBlockStatment(std::list<ASTStatment*> *pStatmentList);
        virtual ~ASTBlockStatment();
        virtual bool codegen(Module *pModule);
    protected:
        std::list<ASTStatment*> *pStatmentList;
    private:
};

#endif // BLOCKSTATMENT_H
