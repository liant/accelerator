#ifndef MCLASSOBJECT_H
#define MCLASSOBJECT_H

#include "module.h"

#include <string>

class MClass;
class MFunction;
class MClassObject:public Module
{
    public:
        MClassObject(MClass *pType,std::string name);
        virtual ~MClassObject();
        MClass *pType; //类型
        std::string name;
        MFunction *pSet;
        MFunction *pGet;
    protected:
        unsigned char *data;
        int len;

    private:
};

#endif // MCLASSOBJECT_H
