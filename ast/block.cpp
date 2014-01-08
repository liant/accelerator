#include "block.h"

using namespace std;

ASTBlock::ASTBlock(list<ASTNode*> *pContent)
:ASTNode(NT_Block),pContent(pContent)
{
    //ctor
}

ASTBlock::~ASTBlock()
{
    //dtor
}
