#ifndef CASESTATMENT_H
#define CASESTATMENT_H

#include "../statment.h"
#include "../expression.h"

#include <list>

class ASTCaseStatment:public ASTStatment
{
    public:
        ASTCaseStatment(ASTExpression *pExpression);
        virtual ~ASTCaseStatment();
        void pushCases(ASTCaseStatment *pCase);
        void setContent(std::list<ASTStatment*> *pContent);
    protected:
        ASTExpression *pExpression;
        std::list<ASTCaseStatment*> *pCaseStatments;
        std::list<ASTStatment*> *pContent;
    private:
};

#endif // CASESTATMENT_H
