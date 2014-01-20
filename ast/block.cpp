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
    if(pContent)
        {
            for(auto item:*pContent)
            {
                delete item;
            }
            delete pContent;
        }
}

bool ASTBlock::codegen(Module *pModule)
{


        //添加子参数
        if(pContent)
        {
            for(auto item:*pContent)
            {
                item->codegen(pModule);
            }
        }
        return true;
}
