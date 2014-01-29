#include "MetaBlock.h"

MetaBlock::MetaBlock()
{
    //ctor
}

MetaBlock::~MetaBlock()
{
    //dtor
    for(auto item:mMetaLines)
    {
        delete item;
    }
    mMetaLines.clear();
}

void MetaBlock::addMetaLine(MetaLine *pMetaLine)
{
    mMetaLines.push_back(pMetaLine);
}

MetaLine *MetaBlock::addMetaLine(uintptr_t line)
{
    MetaLine *pLine;
    pLine=new MetaLine(line);
    addMetaLine(pLine);
    return pLine;
}
