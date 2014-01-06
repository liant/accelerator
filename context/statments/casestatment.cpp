#include "casestatment.h"

using namespace std;

CaseStatment::CaseStatment(Expression *pExpression)
    :Statment(ST_Case),pExpression(pExpression),pCaseStatments(nullptr),pContent(nullptr);
{
    //ctor
}

CaseStatment::~CaseStatment()
{
    //dtor
}

void CaseStatment::pushCases(CaseStatment *pCase)
{
    if(pCaseStatments==0){
        pCaseStatments=new list<CaseStatment*>();
    }
    pCaseStatments->push_back(pCase);
}
        void CaseStatment::setContent(std::list<Statment*> *pContent)
        {
            this->pContent=pContent;
        }
