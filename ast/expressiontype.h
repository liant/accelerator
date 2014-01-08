#ifndef EXPRESSIONTYPE_H_INCLUDED
#define EXPRESSIONTYPE_H_INCLUDED

enum ExpressionType {
    ET_None,
    ET_Boolean,
    ET_Constant,
    ET_Assignment,
    ET_Cast,
    ET_Postfix,
    ET_Prefix,
    ET_Nifix,
    ET_Access,
    ET_Invoke,
    ET_New,
    ET_Array,
    ET_Declare,

};


enum ExpressionPrefixOperator {
    EPreO_Not,
    EPreO_BitNot,
    EPreO_Inc,
    EPreO_Dec,
    EPreO_Plus,
    EPreO_Minus,
};

enum ExpressionPostfixOperator {
    EPostO_Inc,
    EPostO_Dec,
    EPostO_Bracket,
};

enum ExpressionNifixOperator {
    ENO_Add,
    ENO_Sub,
    ENO_Mul,
    ENO_Div,
    ENO_Mod,
    ENO_BitAnd,
    ENO_BitOr,
    ENO_BitXor,
    ENO_ShiftLeft,
    ENO_ShiftRight,
    ENO_And,
    ENO_Or,
    ENO_Equal,
    ENO_NotEqual,
    ENO_LessEqual,
    ENO_Less,
    ENO_MoreEqual,
    ENO_More,
    //////////////////////////
    ENO_As,
    ENO_To,
};

enum ExpressionAssignmentOperator {
    EAO_Assign,
    EAO_AddAssign,
    EAO_SubAssign,
    EAO_MulAssign,
    EAO_DivAssign,
    EAO_ModAssign,
    EAO_BitXorAssign,
    EAO_BitAndAssign,
    EAO_BitOrAssign,
    EAO_ShiftLeftAssign,
    EAO_ShiftRightAssign,
};

enum ExpressionOverrideOperator {
    EOO_Not,
    EOO_BitNot,
    EOO_Add,
    EOO_Sub,
    EOO_Mul,
    EOO_Div,
    EOO_Mod,
    EOO_BitAnd,
    EOO_BitOr,
    EOO_BitXor,
    EOO_ShiftLeft,
    EOO_ShiftRight,
    EOO_And,
    EOO_Or,
    EOO_Equal,
    EOO_NotEqual,
    EOO_LessEqual,
    EOO_Less,
    EOO_MoreEqual,
    EOO_More,
    EOO_Assign,
    EOO_AddAssign,
    EOO_SubAssign,
    EOO_MulAssign,
    EOO_DivAssign,
    EOO_ModAssign,
    EOO_BitXorAssign,
    EOO_BitAndAssign,
    EOO_BitOrAssign,
    EOO_ShiftLeftAssign,
    EOO_ShiftRightAssign,
};

#endif // EXPRESSIONTYPE_H_INCLUDED
