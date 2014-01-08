#include "casestatment.h"

using namespace std;

ASTCaseStatment::ASTCaseStatment(ASTExpression *pExpression)
    :ASTStatment(ST_Case),pExpression(pExpression),pCaseStatments(nullptr),pContent(nullptr)
{
    //ctor
}

ASTCaseStatment::~ASTCaseStatment()
{
    //dtor
}

void ASTCaseStatment::pushCases(ASTCaseStatment *pCase)
{
    if(pCaseStatments==0){
        pCaseStatments=new list<ASTCaseStatment*>();
    }
    pCaseStatments->push_back(pCase);
}
        void ASTCaseStatment::setContent(std::list<ASTStatment*> *pContent)
        {
            this->pContent=pContent;
        }
