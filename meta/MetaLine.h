#ifndef METALINE_H
#define METALINE_H

//行的元信息.
#include <cstdint>
#include <list>

#include "Meta.h"

class MetaLine
{
    public:
        MetaLine(uintptr_t line);
        virtual ~MetaLine();

        void addMeta(Meta *pMeta);
        void addMeta(std::string *pmeta,uintptr_t column);

        //行数
        uintptr_t line;
        std::list<Meta*> mMetaList;
    protected:
    private:
};

#endif // METALINE_H
