#ifndef CASESTATMENT_H
#define CASESTATMENT_H

#include "../statment.h"
#include "../expression.h"

#include <list>

class CaseStatment:public Statment
{
    public:
        CaseStatment(Expression *pExpression);
        virtual ~CaseStatment();
        void pushCases(CaseStatment *pCase);
        void setContent(std::list<Statment*> *pContent);
    protected:
        Expression *pExpression;
        std::list<CaseStatment*> *pCaseStatments;
        std::list<Statment*> *pContent;
    private:
};

#endif // CASESTATMENT_H
