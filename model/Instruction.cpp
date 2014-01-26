#include "Instruction.h"
#include "Value.h"

Instruction::Instruction(uintptr_t instruction,Value *pret,Value *popt1,Value *popt2)
    :instruction(instruction),pret(pret),popt1(popt1),popt2(popt2)
{
    //ctor
}

Instruction::~Instruction()
{
    //dtor
    if(pret)
        delete pret;
    if(popt1)
        delete popt1;
    if(popt2)
        delete popt2;
}

void Instruction::clear()
{
    pret=nullptr;
    popt1=nullptr;
    popt2=nullptr;
}

