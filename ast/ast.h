#ifndef CONTEXTAST_H
#define CONTEXTAST_H

#include "node.h"
#include "token.h"
#include "literal.h"
#include "expression.h"
#include "statment.h"
#include "classtype.h"
#include "classobject.h"
#include "function.h"
#include "delegate.h"
#include "class.h"
#include "enum.h"
#include "interface.h"
#include "template.h"
#include "package.h"
#include "block.h"
#include "classobjectblock.h"

//语句类型
#include "statments/blockstatment.h"
#include "statments/breakstatment.h"
#include "statments/continuestatment.h"
#include "statments/expressionstatment.h"
#include "statments/forstatment.h"
#include "statments/ifstatment.h"
#include "statments/returnstatment.h"
#include "statments/switchstatment.h"
#include "statments/whilestatment.h"
#include "statments/casestatment.h"

//expresion 表达式类型
#include "expressions/accessexpression.h"
#include "expressions/assignmentexpression.h"
#include "expressions/booleanexpression.h"
#include "expressions/castexpression.h"
#include "expressions/constantexpression.h"
#include "expressions/invokeexpression.h"
#include "expressions/newexpression.h"
#include "expressions/nifixexpression.h"
#include "expressions/postfixexpression.h"
#include "expressions/prefixexpression.h"
#include "expressions/arrayexpression.h"
#include "expressions/declareexpression.h"

#endif // CONTEXT_H
