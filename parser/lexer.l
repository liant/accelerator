%option noyywrap
%option yylineno
%option stack

single_line_comment    "//".*
white_space            [ \t\n\r]

dec_digit              [0-9]
hex_digit              [0-9A-Fa-f]
int_suffix             [UuLl]|[Uu][Ll]|[Ll][Uu]
dec_literal            {dec_digit}+{int_suffix}?
hex_literal            0[xX]{hex_digit}+{int_suffix}?
integer_literal        {dec_literal}|{hex_literal}

real_suffix            [FfDdMm]
sign                   [+\-]
exponent_part          [eE]{sign}?{dec_digit}+
whole_real1            {dec_digit}+{exponent_part}{real_suffix}?
whole_real2            {dec_digit}+{real_suffix}
part_real              {dec_digit}*\.{dec_digit}+{exponent_part}?{real_suffix}?
real_literal           {whole_real1}|{whole_real2}|{part_real}

single_char            [^\\\']
simple_esc_seq         \\[\'\"\\0abfnrtv]
uni_esc_seq1           \\u{hex_digit}{4}
uni_esc_seq2           \\U{hex_digit}{8}
uni_esc_seq            {uni_esc_seq1}|{uni_esc_seq2}
hex_esc_seq            \\x{hex_digit}{1,4}
character              {single_char}|{simple_esc_seq}|{hex_esc_seq}|{uni_esc_seq}
character_literal      \'{character}\'

single_string_char     [^\\\"]
reg_string_char        {single_string_char}|{simple_esc_seq}|{hex_esc_seq}|{uni_esc_seq}
regular_string         \"{reg_string_char}*\"
single_verbatim_char   [^\"]
quote_esc_seq          \"\"
verb_string_char       {single_verbatim_char}|{quote_esc_seq}
verbatim_string        @\"{verb_string_char}*\"
string_literal         {regular_string}|{verbatim_string}


letter_char            [A-Za-z]
ident_char             {dec_digit}|{letter_char}|"_"
identifier             ({letter_char}|"_"){ident_char}*


%x IN_COMMENT

%s IN_ATTRIB IN_ACCESSOR IN_GETSET

%{
#include <stdio.h>
//记号类型

#include "../context/context.h"
#include "tokentype.h"
#include "parser.parser.hh"


#define NewTokenKey(x) { yylval.tokentype=x; return x;  }
#define NewTokenValue(x) {yylval.token=new Token(x,yytext); return x;}

%}

%%





                      /***** 多行注释 *****/
"/*"                  { yy_push_state(IN_COMMENT); }
<IN_COMMENT>.         { ; /* ignore */ }
<IN_COMMENT>\n        { ; /* ignore */ }
<IN_COMMENT>"*/"      { yy_pop_state(); }

{single_line_comment} { ; /* 当行注视 */ }

{white_space}         { ; /* 忽略不计 */ }
                      /***** Literals *****/
{integer_literal}     { NewTokenValue(Token_Integer); }
{real_literal}        { NewTokenValue(Token_Float);; }
{character_literal}   { NewTokenValue(Token_Character); }
{string_literal}      { NewTokenValue(Token_String); }


"++"  			{ NewTokenKey(TokenOpt_Inc);  }/*** 自增自减操作符号 ***/
"--" 			{ NewTokenKey(TokenOpt_Dec);  }
	/*** 常规运算符好 ***/
"+"			{ NewTokenKey(TokenOpt_Add); }
"-"			{ NewTokenKey(TokenOpt_Sub); }
"*"			{ NewTokenKey(TokenOpt_Mul); }
"/"			{ NewTokenKey(TokenOpt_Div); }
"%"			{ NewTokenKey(TokenOpt_Mod); }
"+="			{ NewTokenKey(TokenOpt_SetAdd); }
"-="			{ NewTokenKey(TokenOpt_SetSub); }
"*="			{ NewTokenKey(TokenOpt_SetMul); }
"/="			{ NewTokenKey(TokenOpt_SetDiv); }
"%="			{ NewTokenKey(TokenOpt_SetMod); }
	/*** 位运算符号 ***/
"&"			{ NewTokenKey(TokenOpt_BitAnd); }
"|"			{ NewTokenKey(TokenOpt_BitOr); }
"~"			{ NewTokenKey(TokenOpt_BitNot); }
"^"			{ NewTokenKey(TokenOpt_BitXor); }
"<<"  			{ NewTokenKey(TokenOpt_ShiftLeft); }
">>" 			{ NewTokenKey(TokenOpt_ShiftRight); }
"&="			{ NewTokenKey(TokenOpt_SetBitAnd); }
"|="			{ NewTokenKey(TokenOpt_SetBitOr); }
"^="			{ NewTokenKey(TokenOpt_SetBitXor); }
"<<="			{ NewTokenKey(TokenOpt_SetShiftLeft); }
">>=" 			{ NewTokenKey(TokenOpt_SetShiftRight); }
	/*** 比较运算符号 ***/
"=="  			{ NewTokenKey(TokenOpt_Equal); }
"!=" 			{ NewTokenKey(TokenOpt_NotEqual); }
"<="  			{ NewTokenKey(TokenOpt_LessEqual); }
">="  			{ NewTokenKey(TokenOpt_MoreEqual); }
"<"			{ NewTokenKey(TokenOpt_Less); }
">"			{ NewTokenKey(TokenOpt_More); }
	/*** 逻辑运算符号 ***/
"&&"  			{ NewTokenKey(TokenOpt_And); }
"||" 			{ NewTokenKey(TokenOpt_Or); }
"!"			{ NewTokenKey(TokenOpt_Not); }
	/*** 特殊操作符号 ***/
","   			{ NewTokenKey(TokenOpt_Comma); }
";"			{ NewTokenKey(TokenOpt_End); }
":"			{ NewTokenKey(TokenOpt_As); }
"="			{ NewTokenKey(TokenOpt_SetValue); }
"."			{ NewTokenKey(TokenOpt_Dot); }
"=>"  			{ NewTokenKey(TokenOpt_To); }
	/*** 作用域操作符号 ***/
"("			{ NewTokenKey(TokenOpt_LeftBracket);  }
")"			{ NewTokenKey(TokenOpt_RightBracket); }
"{"			{ NewTokenKey(TokenOpt_LeftBlock);  }
"}"			{ NewTokenKey(TokenOpt_RightBlock); }
"["   			{ NewTokenKey(TokenOpt_LeftIndex); }
"]"   			{ NewTokenKey(TokenOpt_RightIndex); }

	/*** 关键字 ***/
"switch"		{ NewTokenKey(TokenKey_Switch);}
"break"		{ NewTokenKey(TokenKey_Break);}
"case"			{ NewTokenKey(TokenKey_Case);}
"continue"		{ NewTokenKey(TokenKey_Continue);}
"default"		{ NewTokenKey(TokenKey_Default);}
"if"			{ NewTokenKey(TokenKey_If);}
"else"			{ NewTokenKey(TokenKey_Else);}
"enum"			{ NewTokenKey(TokenKey_Enum);}
"for"			{ NewTokenKey(TokenKey_For);}
"return"		{ NewTokenKey(TokenKey_Return);}
"static"		{ NewTokenKey(TokenKey_Static);}
"class"		{ NewTokenKey(TokenKey_Class);}
"void"			{ NewTokenKey(TokenKey_Void);}
"while"		{ NewTokenKey(TokenKey_While);}
"get"                { NewTokenKey(TokenKey_Get); }
"set"                { NewTokenKey(TokenKey_Set); }
"package"            { NewTokenKey(TokenKey_Package); }
"import"             { NewTokenKey(TokenKey_Import); }
"interface"          { NewTokenKey(TokenKey_Interface); }
"template"           { NewTokenKey(TokenKey_Template); }
"operator"           { NewTokenKey(TokenKey_Operator); }
"true"               { NewTokenKey(TokenKey_True); }
"false"              { NewTokenKey(TokenKey_False); }
"null"              { NewTokenKey(TokenKey_Null); }
"this"              { NewTokenKey(TokenKey_This); }
"new"              { NewTokenKey(TokenKey_New); }

{identifier}         { NewTokenValue(Token_Identify); }

.     			{ fprintf(stderr,"%d:lexical error (invalid token) [%s]\n",yylineno,yytext);}


%%
