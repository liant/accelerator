#ifndef DECLARESTATMENT_H
#define DECLARESTATMENT_H

#include "../statment.h"
#include "../classobjectblock.h"

class DeclareStatment:public Statment
{
    public:
        DeclareStatment(ClassObjectBlock *pContent);
        virtual ~DeclareStatment();
    protected:
        ClassObjectBlock *pContent;
    private:
};

#endif // DECLARESTATMENT_H
