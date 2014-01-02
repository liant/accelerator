#include "token.h"

Token::Token(TokenType type):Node(NT_Token),type(type)
{
    //ctor
}

Token::Token(TokenType type,const char *str):Node(NT_Token),type(type)
{
    this->text=str;
}

Token::~Token()
{
    //dtor
}
