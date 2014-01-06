#include "declarestatment.h"

using namespace std;

DeclareStatment::DeclareStatment(ClassObjectBlock *pContent)
    :Statment(ST_Declare),pContent(pContent)
{
    //ctor
}

DeclareStatment::~DeclareStatment()
{
    //dtor
}
