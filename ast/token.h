#ifndef TOKEN_H
#define TOKEN_H

#include "node.h"
#include "../parser/tokentype.h"

#include <string>

class ASTToken:public ASTNode
{
    public:
        ASTToken(TokenType type);
        ASTToken(TokenType type,const char *str);
        virtual ~ASTToken();
        std::string toString();
    protected:
    private:
        TokenType type;
        std::string text;
};

#endif // TOKEN_H
