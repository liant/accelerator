#ifndef LITERAL_H
#define LITERAL_H

#include "token.h"
#include "literaltype.h"

class ASTLiteral:public ASTNode
{
    public:
        ASTLiteral(LiteralType type,ASTToken *ptoken);
        virtual ~ASTLiteral();
    protected:
    private:
        LiteralType type;
        ASTToken *ptoken;
};

#endif // LITERAL_H
