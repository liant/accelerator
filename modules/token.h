#ifndef TOKEN_H
#define TOKEN_H

#include "../parser/tokentype.h"

#include <string>

class Token
{
    public:
        Token();
        Token(TokenType type);
        Token(TokenType type,const char *str);
        virtual ~Token();
        void set(TokenType type,const char *str);
        std::string toString();
    protected:
        TokenType type;
        std::string text;
    private:
};

extern Token globalToken;

#endif // TOKEN_H
