#ifndef TOKENTYPE_H_INCLUDED
#define TOKENTYPE_H_INCLUDED

#define YYTOKENTYPE


enum TokenType{

Token_Integer=258,
Token_Float,
Token_Character,
Token_String,

//////////////////////////////// 自增自减操作符号
TokenOpt_Inc,
TokenOpt_Dec,
///////////////////////////// 常规运算符好
TokenOpt_Add,
TokenOpt_Sub,
TokenOpt_Mul,
TokenOpt_Div,
TokenOpt_Mod,
TokenOpt_SetAdd,
TokenOpt_SetSub,
TokenOpt_SetMul,
TokenOpt_SetDiv,
TokenOpt_SetMod,
////////////////////// 位运算符号
TokenOpt_BitAnd,
TokenOpt_BitOr,
TokenOpt_BitNot,
TokenOpt_BitXor,
TokenOpt_ShiftLeft,
TokenOpt_ShiftRight,
TokenOpt_SetBitAnd,
TokenOpt_SetBitOr,
TokenOpt_SetBitXor,
TokenOpt_SetShiftLeft,
TokenOpt_SetShiftRight,
//////////////比较运算符号
TokenOpt_Equal,
TokenOpt_NotEqual,
TokenOpt_LessEqual,
TokenOpt_MoreEqual,
TokenOpt_Less,
TokenOpt_More,
//////////////////// 逻辑运算符号
TokenOpt_And,
TokenOpt_Or,
TokenOpt_Not,
//////////////////////特殊操作符号
TokenOpt_Comma,
TokenOpt_End,
TokenOpt_As,
TokenOpt_SetValue,
TokenOpt_Dot,
TokenOpt_To,
 ////////////////////////作用域操作符号
TokenOpt_LeftBracket,
TokenOpt_RightBracket,
TokenOpt_LeftBlock,
TokenOpt_RightBlock,
TokenOpt_LeftIndex,
TokenOpt_RightIndex,

////////////////////关键字
TokenKey_Switch,
TokenKey_Break,
TokenKey_Case,
TokenKey_Continue,
TokenKey_Default,
TokenKey_If,
TokenKey_Else,
TokenKey_Enum,
TokenKey_For,
TokenKey_Return,
TokenKey_Static,
TokenKey_Class,
TokenKey_Void,
TokenKey_While,
TokenKey_Get,
TokenKey_Set,
TokenKey_Package,
TokenKey_Import,
TokenKey_Interface,
TokenKey_Template,
TokenKey_Operator,
TokenKey_True,
TokenKey_False,
TokenKey_Null,
TokenKey_This,
TokenKey_New,
Token_Identify,
};


#endif // TOKENTYPE_H_INCLUDED
