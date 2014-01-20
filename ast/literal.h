#ifndef LITERAL_H
#define LITERAL_H

#include "token.h"
#include "literaltype.h"

class Module;

class ASTLiteral:public ASTNode
{
    public:
        ASTLiteral(LiteralType type,ASTToken *ptoken);
        virtual ~ASTLiteral();
        bool codegen(Module *pModule);
    protected:
    private:
        LiteralType type;
        ASTToken *ptoken;
};

#endif // LITERAL_H
