#ifndef DECLAREEXPRESSION_H
#define DECLAREEXPRESSION_H

#include "../expression.h"
#include "../classobjectblock.h"

class Module;

class ASTDeclareExpression:public ASTExpression
{
    public:
        ASTDeclareExpression(ASTClassObjectBlock *pContent);
        virtual ~ASTDeclareExpression();
        virtual bool codegen(Module *pModule);
    protected:
        ASTClassObjectBlock *pContent;
    private:
};

#endif // DECLAREEXPRESSION_H
