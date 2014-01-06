#ifndef DECLAREEXPRESSION_H
#define DECLAREEXPRESSION_H

#include "../expression.h"
#include "../classobjectblock.h"

class DeclareExpression:public Expression
{
    public:
        DeclareExpression(ClassObjectBlock *pContent);
        virtual ~DeclareExpression();
    protected:
        ClassObjectBlock *pContent;
    private:
};

#endif // DECLAREEXPRESSION_H
