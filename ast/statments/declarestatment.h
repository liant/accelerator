#ifndef DECLARESTATMENT_H
#define DECLARESTATMENT_H

#include "../statment.h"
#include "../classobjectblock.h"

class ASTDeclareStatment:public ASTStatment
{
    public:
        ASTDeclareStatment(ASTClassObjectBlock *pContent);
        virtual ~ASTDeclareStatment();
    protected:
        ASTClassObjectBlock *pContent;
    private:
};

#endif // DECLARESTATMENT_H
