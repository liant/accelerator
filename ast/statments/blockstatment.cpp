#include "blockstatment.h"

using namespace std;

ASTBlockStatment::ASTBlockStatment(list<ASTStatment*> *pStatmentList):ASTStatment(ST_Block),pStatmentList(pStatmentList)
{
    //ctor
}

ASTBlockStatment::~ASTBlockStatment()
{
    //dtor
}
