#include "classobject.h"
#include "sstream"

using namespace std;

ClassObject::ClassObject(Class *pType,string name,Module *pParent,Protocol protocol)
    :Module(Module_ClassObject,pParent,name,protocol),pclassType(pType)
{
    //ctor
}
ClassObject::ClassObject(Module *pParent)
    :Module(Module_ClassObject,pParent,"@object_",protocol),pclassType(nullptr)
{
    stringstream snum;
    snum<<maxid++;
    name+=snum.str();
}
ClassObject::~ClassObject()
{
    //dtor
}

int ClassObject::maxid=1;
