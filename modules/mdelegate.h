#ifndef MDELEGATE_H
#define MDELEGATE_H

#include "module.h"
#include "mclassobject.h"
#include "mclass.h"

#include <string>
#include <list>

class MDelegate:public Module
{
    public:
        MDelegate(MClass *classType,std::string name,ModuleProtocol protocol=ModuleProtocol_Protected);
        virtual ~MDelegate();
        MClass *classType;
        std::string name;
        std::list<MClassObject*> mParamList;
    protected:
    private:
};

#endif // MDELEGATE_H
