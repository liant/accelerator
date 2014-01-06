#ifndef BLOCKSTATMENT_H
#define BLOCKSTATMENT_H

#include "../statment.h"

#include <list>

class BlockStatment:public Statment
{
    public:
        BlockStatment(std::list<Statment*> *pStatmentList);
        virtual ~BlockStatment();
    protected:
        std::list<Statment*> *pStatmentList;
    private:
};

#endif // BLOCKSTATMENT_H
