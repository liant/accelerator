#include "MetaLine.h"

using namespace std;

MetaLine::MetaLine(uintptr_t line):line(line)
{
    //ctor
}

MetaLine::~MetaLine()
{
    //dtor
    for(auto item:mMetaList)
        delete item;
    mMetaList.clear();
}

void MetaLine::addMeta(Meta *pMeta)
{
    mMetaList.push_back(pMeta);
}
void MetaLine::addMeta(string *pmeta,uintptr_t column)
{
    Meta *pMeta;
    pMeta=new Meta(pmeta,column);
    addMeta(pMeta);
}
