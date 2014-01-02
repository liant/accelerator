#ifndef TOKEN_H
#define TOKEN_H

#include "node.h"
#include "../parser/tokentype.h"

#include <string>

class Token:public Node
{
    public:
        Token(TokenType type);
        Token(TokenType type,const char *str);
        virtual ~Token();
    protected:
    private:
        TokenType type;
        std::string text;
};

#endif // TOKEN_H
