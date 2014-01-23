#include "Instruction.h"

Instruction::Instruction(uintptr_t instruction,Value *pret,Value *popt1,Value *popt2)
    :instruction(instruction),pret(pret),popt1(popt1),popt2(popt2)
{
    //ctor
}

Instruction::~Instruction()
{
    //dtor
}
