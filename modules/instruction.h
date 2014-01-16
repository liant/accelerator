#ifndef MINSTRUCTION_H_INCLUDED
#define MINSTRUCTION_H_INCLUDED

enum MInstruction
{
    ////////////////////
    MI_Push,
    MI_Pop,
    ////////////////////
    MI_Call,
    MI_Jmp,
    MI_JmpZ,
    MI_JmpNZ,
    MI_Return,
    ////////////////////
    MI_Inc,
    MI_Dec,
    ///////////////////
    MI_Add,
    MI_Sub,
    MI_Mul,
    MI_Div,
    MI_Mod,
    ///////////////////
    MI_And,
    MI_Or,
    MI_Not,
    ///////////////////
    MI_Equal,
    MI_NotEqual,
    MI_LessEqual,
    MI_Less,
    MI_MoreEqual,
    MI_More,
    //////////////////
    MI_BitAnd,
    MI_BitOr,
    MI_BitXor,
    MI_BitNot,
    MI_ShiftLeft,
    MI_ShiftRight,
    /////////////////////
    MI_As,
    MI_To,
    MI_New,
    MI_Cast,
    /////////////////////////
    MI_Assign,
    MI_AddAssign,
    MI_SubAssign,
    MI_MulAssign,
    MI_DivAssign,
    MI_ModAssign,
    MI_BitAndAssign,
    MI_BitOrAssign,
    MI_BitXorAssign,
    MI_ShiftLeftAssign,
    MI_ShiftRightAssign,
};

#endif // MINSTRUCTION_H_INCLUDED
