#ifndef BLOCK_H
#define BLOCK_H

#include <list>
#include <cstdint>

class BlockBase;
class Value;
class Instruction;

class Block
{
    public:
        Block();
        virtual ~Block();
        //创建一个新块
        Block *newBlock();
        //在当前块中插入新值
        Value *createValue();
        void addValue(Value *pValue);
        //在当前快中插入新指令
        bool addInstruction(uintptr_t instruction,Value *v1,Value *v2,Value *v3);
        void addInstruction(Instruction *pInstruction);
        //在当前语句位置,插入新块
        Block createBlock();
    protected:
        //值列表,用于存放各种值
        std::list<Value*> mValues;
        std::list<Instruction*> mInstructions; //语句列表
    private:
};

#endif // BLOCK_H
