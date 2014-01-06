#include "block.h"

using namespace std;

Block::Block(list<Node*> *pContent)
:Node(NT_Block),pContent(pContent)
{
    //ctor
}

Block::~Block()
{
    //dtor
}
