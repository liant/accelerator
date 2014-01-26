#ifndef LOWINSTRUCTION_H_INCLUDED
#define LOWINSTRUCTION_H_INCLUDED

enum LowInstruction
{
    LI_Push,
    LI_Pop,
    ///基本指令,取栈中地址数据操作,再放回到栈中
    LI_Inc,    //递增
    LI_Dec,   //递减
    LI_Add,
    LI_Sub,
    LI_Mul,
    LI_Div,
    LI_Mod,
    ///逻辑指令,取栈中地址数据操作,再放回到栈中
    LI_And,
    LI_Or,
    LI_Not,
    ///比较操作
    LI_Equal,
    LI_NotEqual,
    LI_LessEqual,
    LI_Less,
    LI_MoreEqual,
    LI_More,
    ///位操作
    LI_BitAnd,
    LI_BitOr,
    LI_BitXor,
    LI_BitNot,
    LI_ShiftLeft,
    LI_ShiftRight,
    ///类型转换操作,将栈中两个数进行复制.并进行类型转换.
    LI_New, //在数据区动态分配一个对象,并把地址,放入栈
    LI_Cast,
    ///赋值操作,将栈中两个数进行复制.并留下一个复制的值.
    LI_Assign,  //将堆栈中的两个值复制一次,弹出栈
    ///控制指令
    LI_Jmp, //跳转到某固定位置,位置由栈顶元素指定
    LI_JmpBool, //根据条件进行跳转,条件由栈顶元素指定,弹出后,第二个元素指定位置
    LI_Call, //模块转移指令,转移到某个指定模块.
    LI_Return, //返回指令,即从当前模块退出,返回模块栈栈顶元素位置.

}


#endif // LOWINSTRUCTION_H_INCLUDED
