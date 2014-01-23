#include "token.h"

using namespace std;

Token globalToken;

Token::Token()
{
}

Token::Token(TokenType type):type(type)
{
    //ctor
}

Token::Token(TokenType type,const char *str):type(type),text(str)
{
    //ctor
}

Token::~Token()
{
    //dtor
}

void Token::set(TokenType type,const char *str)
{
    this->type=type;
    this->text=str;
}

string Token::toString()
{
    return this->text;
}
