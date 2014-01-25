#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <cstdint>

class Value;

class Instruction
{
    public:
        Instruction(uintptr_t instruction,Value *pret,Value *popt1,Value *popt2);
        virtual ~Instruction();
        void clear();
        uintptr_t instruction;
        Value *pret;
        Value *popt1;
        Value *popt2;
    protected:
    private:
};

#endif // INSTRUCTION_H
