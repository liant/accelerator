#ifndef METABLOCK_H
#define METABLOCK_H

#include "MetaLine.h"
#include <list>
#include <cstdint>

class MetaBlock
{
    public:
        MetaBlock();
        virtual ~MetaBlock();
        void addMetaLine(MetaLine *pMetaLine);
        MetaLine *addMetaLine(uintptr_t line);
        std::list<MetaLine*> mMetaLines;
    protected:

    private:
};

#endif // METABLOCK_H
