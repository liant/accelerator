#include "block.h"

Block::Block():Module(Module_Block,nullptr,"ss",Protocol_Protected)
{
    //ctor
}

Block::~Block()
{
    //dtor
}

ClassObject *Block::createObject()
{
    ClassObject *pObject;
    pObject=new ClassObject(this);
    mData.push_back(pObject);
    return pObject;
}
