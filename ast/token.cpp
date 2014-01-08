#include "token.h"

using namespace std;

ASTToken::ASTToken(TokenType type):ASTNode(NT_Token),type(type)
{
    //ctor
}

ASTToken::ASTToken(TokenType type,const char *str):ASTNode(NT_Token),type(type)
{
    this->text=str;
}

ASTToken::~ASTToken()
{
    //dtor
}

string ASTToken::toString()
{
    return this->text;
}
