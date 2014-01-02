#ifndef LITERAL_H
#define LITERAL_H

#include "token.h"
#include "literaltype.h"

class Literal:public Node
{
    public:
        Literal(LiteralType type,Token *ptoken);
        virtual ~Literal();
    protected:
    private:
        LiteralType type;
        Token *ptoken;
};

#endif // LITERAL_H
