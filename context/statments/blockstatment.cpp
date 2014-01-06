#include "blockstatment.h"

using namespace std;

BlockStatment::BlockStatment(list<Statment*> *pStatmentList):Statment(ST_Block),pStatmentList(pStatmentList)
{
    //ctor
}

BlockStatment::~BlockStatment()
{
    //dtor
}
