#include "declarestatment.h"

using namespace std;

ASTDeclareStatment::ASTDeclareStatment(ASTClassObjectBlock *pContent)
    :ASTStatment(ST_Declare),pContent(pContent)
{
    //ctor
}

ASTDeclareStatment::~ASTDeclareStatment()
{
    //dtor
}
