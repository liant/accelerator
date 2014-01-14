#ifndef LLVMEXPRESSION_H
#define LLVMEXPRESSION_H

#include "../modules/expression.h"
#include "../modules/context.h"

class LLVMExpression
{
    public:
        LLVMExpression();
        virtual ~LLVMExpression();
        bool codegen(Context *pContext);
    protected:
    private:
};

#endif // LLVMEXPRESSION_H
