#ifndef DECLAREEXPRESSION_H
#define DECLAREEXPRESSION_H

#include "../expression.h"
#include "../classobjectblock.h"

class ASTDeclareExpression:public ASTExpression
{
    public:
        ASTDeclareExpression(ASTClassObjectBlock *pContent);
        virtual ~ASTDeclareExpression();
    protected:
        ASTClassObjectBlock *pContent;
    private:
};

#endif // DECLAREEXPRESSION_H
