#ifndef BLOCK_H
#define BLOCK_H

#include <list>
#include <string>
#include <cstdint>

class BlockBase;
class Value;
class Instruction;
class Context;

class Block
{
    public:
        Block();
        virtual ~Block();
        //在当前块中插入新值
        void addValue(Value *pValue);
        //在当前快中插入新指令
        void addInstruction(Instruction *pInstruction);
        void build(Context *pContext);
        bool checkValue(std::string name);
    protected:
        //值列表,用于存放各种值
        std::list<Value*> mValues;
        std::list<Instruction*> mInstructions; //语句列表
    private:
};

#endif // BLOCK_H
