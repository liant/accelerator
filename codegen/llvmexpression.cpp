#include "llvmexpression.h"

#include <llvm/IR/Instruction.h>
#include <llvm/IR/Instructions.h>
#include <llvm/IR/LLVMContext.h>

LLVMExpression::LLVMExpression()
{
    //ctor
}

LLVMExpression::~LLVMExpression()
{
    //dtor
}

bool LLVMExpression::codegen(Context *pContext)
{
    return true;
}
