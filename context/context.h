#ifndef CONTEXT_H
#define CONTEXT_H

#include "node.h"
#include "token.h"
#include "literal.h"
#include "expression.h"
#include "statment.h"
#include "classtype.h"
#include "classobject.h"
#include "function.h"
#include "class.h"
#include "enum.h"
#include "interface.h"
#include "template.h"
#include "package.h"

class Context
{
    public:
        Context();
        virtual ~Context();
    protected:
    private:
};

#endif // CONTEXT_H
