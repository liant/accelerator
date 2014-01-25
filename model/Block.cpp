#include "Block.h"
#include "Value.h"
#include "Instruction.h"

using namespace std;

Block::Block()
{
    //ctor
}

Block::~Block()
{
    //dtor
    for(auto item:mValues)
        delete item;
    mValues.clear();
    for(auto item:mInstructions)
        delete item;
    mInstructions.clear();
}

//在当前块中插入新值
void Block::addValue(Value *pValue)
{
    if(pValue){
        mValues.push_back(pValue);
    }
}
//在当前快中插入新指令
void Block::addInstruction(Instruction *pInstruction)
{
    if(pInstruction){
        mInstructions.push_back(pInstruction);
    }
}
bool Block::checkValue(string name)
{
    for(auto item:mValues)
    {
        if(item->name==name){
            return true;
        }
    }
    return false;
}

