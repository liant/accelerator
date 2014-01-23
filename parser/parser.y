%{
  extern int yylineno;
  #include "../modules/common.h"
  #include "tokentype.h"
  #include <list>
  using namespace std;
  int yyerror(const char *);
  extern int yylex();
%}

%token TokenKey_Switch TokenKey_Break TokenKey_Case TokenKey_Continue TokenKey_Default TokenKey_If TokenKey_Else TokenKey_Enum TokenKey_For
%token TokenKey_Return TokenKey_Static TokenKey_Class TokenKey_Void TokenKey_While TokenKey_Get TokenKey_Set TokenKey_Package TokenKey_Import
%token TokenKey_Interface TokenKey_Operator TokenKey_True TokenKey_False TokenKey_Null TokenKey_This TokenKey_New
%token TokenKey_Const TokenKey_Public TokenKey_Private TokenKey_Protected TokenKey_Super TokenKey_Template TokenKey_Delegate

%token Token_Integer Token_Float Token_Character Token_String Token_Identify
/*** 自增自减操作符号 ***/
%token TokenOpt_Inc TokenOpt_Dec
/*** 常规运算符好 ***/
%token TokenOpt_Add TokenOpt_Sub TokenOpt_Mul TokenOpt_Div TokenOpt_Mod TokenOpt_SetAdd TokenOpt_SetSub TokenOpt_SetMul TokenOpt_SetDiv TokenOpt_SetMod
/*** 位运算符号 ***/
%token TokenOpt_BitAnd TokenOpt_BitOr TokenOpt_BitNot TokenOpt_BitXor TokenOpt_ShiftLeft TokenOpt_ShiftRight TokenOpt_SetBitAnd TokenOpt_SetBitOr TokenOpt_SetBitXor TokenOpt_SetShiftLeft TokenOpt_SetShiftRight
/*** 比较运算符号 ***/
%token TokenOpt_Equal TokenOpt_NotEqual TokenOpt_LessEqual TokenOpt_MoreEqual TokenOpt_Less TokenOpt_More
/*** 逻辑运算符号 ***/
%token TokenOpt_And TokenOpt_Or TokenOpt_Not
/*** 特殊操作符号 ***/
%token TokenOpt_Comma TokenOpt_End TokenOpt_As TokenOpt_SetValue TokenOpt_Dot TokenOpt_To
 /*** 作用域操作符号 ***/
%token TokenOpt_LeftBracket TokenOpt_RightBracket TokenOpt_LeftBlock TokenOpt_RightBlock TokenOpt_LeftIndex TokenOpt_RightIndex

%union {
    Package *package;
    Enum *pEnum;
    Template *pTemplate;
    Class *pClass;
    Interface *interface;
    Delegate *delegate;
    Token *token;
    Function *function;

    Type *type;
   std::list<Type*> *typeList;
    Value *value;
   std::list<Value*> *valueList;
    Module *module;
    std::list<Module*> *moduleList;
    Block *block;
   Instruction *instruction;
   std::list<Instruction*> *instructionList;

     Protocol protocol;
     TokenType tokentype;
     Attribute attribute;
    AstInstructions ast_operator;
}
%type <ast_operator> operator_override assignment_operator

%type <protocol> protocol_opt protocol
%type <attribute> attribute attributes_opt attributes
%type <type> qualified_identifier

%type <token> Token_String Token_Character  Token_Float Token_Integer Token_Identify

%type <package> package_declaration
%type <type> package_name import_directive
%type <typeList> import_directives_opt import_directives
%type <moduleList> package_member_declarations_opt package_member_declarations
%type <module> package_member_declaration package_type_declaration

%type <pEnum> enum_declaration
%type <type> enum_super_opt enum_extend_opt
%type <block> enum_body enum_member_declarations_opt enum_member_declarations
%type <value> enum_member_declaration

%type <pTemplate> template_declaration template_extend_opt
%type <valueList> template_body_opt template_body template_params template_argument_list template_argument_list_opt template_arguments_opt
%type <value> template_param template_param_argument_opt template_argument
%type <typeList> extend_opt extend interface_type_list

%type <delegate> delegate_declaration

%type <interface> interface_declaration
%type <moduleList> interface_body interface_member_declarations_opt interface_member_declarations
%type <module> interface_member_declaration

%type <pClass> class_declaration
%type <type> class_super_opt
%type <moduleList> class_body class_member_declarations_opt class_member_declarations
%type <module> class_member_declaration class_protocol_member class_modifiers_declaration

%type <function> function_declaration function_header
%type <attribute> function_attribute_opt function_attribute
%type <block> function_body
%type <valueList> function_parameter_list
%type <value> function_parameter function_parameter_argument_opt

%type <instruction> statement declaration_statement embedded_statement block_statment expression_statement statement_expression
%type <instructionList> statement_list_opt statement_list 
%type <value> local_variable_declaration variable_declarator variable_initializer
%type <valueList> variable_declarators array_initializer variable_initializer_list_opt variable_initializer_list

%type <instruction> selection_statement if_statement switch_statement switch_block switch_sections_opt switch_section switch_label
%type <instruction> iteration_statement while_statement for_statement for_expression
%type <instruction> jump_statement break_statement continue_statement return_statement
%type <instructionList> switch_sections switch_labels
%type <value> for_initializer for_iterator

%type <instruction> expression  expression_opt
%type <instruction> parenthesized_expression primary_expression_no_parenthesis primary_expression

%type <instruction> assignment unary_expression unary_expression_not_plusminus
%type <instruction> boolean_expression constant_expression
%type <instruction> conditional_expression conditional_or_expression conditional_and_expression
%type <instruction> inclusive_or_expression exclusive_or_expression and_expression equality_expression
%type <instruction> relational_expression shift_expression additive_expression multiplicative_expression
%type <instruction> postfix_expression post_decrement_expression post_increment_expression

%type <instruction> cast_expression new_expression
%type <instruction> invocation_expression object_creation_expression
%type <instruction> member_access element_access
%type <value> this_access super_access

%type <type> type simple_type class_type
%type <value> variable_reference argument literal boolean_literal
%type <valueList> argument_list argument_list_opt

%start package_declaration

%nonassoc lower_than_else
%nonassoc TokenKey_Else

%nonassoc lower_than_more
%nonassoc TokenOpt_More

%nonassoc lower_than_rightbracket
%nonassoc TokenOpt_RightBracket

%nonassoc lower_than_dot
%nonassoc TokenOpt_Dot

%nonassoc lower_than_identify
%nonassoc Token_Identify

%nonassoc lower_level
%nonassoc high_level

%%
/*对象的开放协议*/
protocol_opt
  : {$$=Protocol_Protected;}
  | protocol {$$=$1;}
   ;
protocol
  :TokenKey_Public {$$=Protocol_Public;}
  |TokenKey_Protected {$$=Protocol_Protected;}
  |TokenKey_Private {$$=Protocol_Private;}
   ;
   /*对象的生成控制*/
attributes_opt
   : %prec lower_than_identify {$$=Attribute_None;}
   | attributes {$$=$1;}
   ;
attributes
   : attribute {$$=$1;}
   | attributes attribute {$1=(Attribute)($1|$2);}
    ;
attribute
    : TokenKey_Static {$$=Attribute_Static;}
    | TokenKey_Const {$$=Attribute_Const;}
     ;

/******************************* 递归标识符 a.b.c.d这种 ******************************************/
qualified_identifier
  : Token_Identify {$$=new Type($1->toString()); $$->addSubType($1->toString());}
  | qualified_identifier TokenOpt_Dot Token_Identify {$1->addSubType($3->toString());}
  ;

/*结尾*/
comma_opt
  :
  | TokenOpt_End
  ;

/*****************************************************************包定义*****************************************************************************/
package_declaration
  : protocol_opt TokenKey_Package package_name TokenOpt_LeftBlock import_directives_opt package_member_declarations_opt TokenOpt_RightBlock comma_opt
	 {$$=new Package($1,$3); $$->addModules($6); $$->addImports($5); }
  ;
package_name
  : qualified_identifier { $$=$1;}
  ;

import_directives_opt
  : /* 空 */{$$=nullptr;}
  | import_directives {$$=$1;}
  ;
import_directives
  : import_directive {$$=new list<Type*>(); $$->push_back($1);}
  | import_directives import_directive {$1->push_back($2);}
  ;
import_directive
  : TokenKey_Import package_name TokenOpt_End  {$$=$2;}
  ;

package_member_declarations_opt
  : /* 空 */ {$$=nullptr;}
  | package_member_declarations  {$$=$1;}
  ;

package_member_declarations
  : package_member_declaration   {$$=new list<Module*>(); $$->push_back($1);}
  | package_member_declarations package_member_declaration {$1->push_back($2);}
  ;
package_member_declaration
  : protocol_opt package_type_declaration {$$->setProtocol($1);}
  ;
package_type_declaration
  : enum_declaration {$$=$1;}
  | class_declaration   {$$=$1;}
  | interface_declaration {$$=$1;}
  | delegate_declaration {$$=$1;}
  ;

/********************************************************************** 枚举定义语法 ********************************************************/

enum_declaration
  : TokenKey_Enum enum_super_opt Token_Identify enum_extend_opt enum_body comma_opt
  {$$=new Enum($2,$3->toString(),$4);$$->setBlock($5);}
  ;
enum_super_opt
  : {$$=nullptr;}
  | TokenOpt_Less class_type TokenOpt_More {$$=$2;}
  ;

enum_extend_opt
  :{$$=nullptr;}
  | TokenOpt_As class_type {$$=$2;}
  ;

enum_body
  : TokenOpt_LeftBlock enum_member_declarations_opt TokenOpt_RightBlock {$$=$2;}
  | TokenOpt_LeftBlock enum_member_declarations TokenOpt_Comma TokenOpt_RightBlock {$$=$2;}
  ;
enum_member_declarations_opt
  : {$$=nullptr;}
  | enum_member_declarations {$$=$1;}
  ;
enum_member_declarations
  : enum_member_declaration {$$=new Block(); $$->addValue($1);}
  | enum_member_declarations TokenOpt_Comma enum_member_declaration {$1->addValue($3);}
  ;
enum_member_declaration
  : Token_Identify {$$=new Value(nullptr,$1->toString());}
  | Token_Identify TokenOpt_SetValue constant_expression {$$=new Value(nullptr,$1->toString()); $$->data=$3;}
  ;

/********************************************************************模板************************************************/

template_declaration
  : TokenOpt_Less template_body_opt TokenOpt_More
  { $$=new Template(); $$->setParams($2);}
  ;

template_body_opt
  :  { $$=nullptr;}
  | template_body {$$=$1;}
  ;
template_body
  : template_params {$$=$1;}
  ;
template_params
  : template_param  {$$=new list<Value*>(); $$->push_back($1); }
  |  template_params TokenOpt_Comma template_param {$1->push_back($3);}
  ;
template_param
  : class_type Token_Identify template_param_argument_opt{ if($3){$3->type=$1; $3->name=$2->toString();} else $$=new Value($1,$2->toString());}
  ;
template_param_argument_opt
   : {$$=nullptr;}
   | TokenOpt_SetValue constant_expression { $$=new Value(); $$->data=$2;}
   ;
////////////////////////////////////模板参数部分
template_arguments_opt
  : %prec lower_than_dot {$$=nullptr;}
  | TokenOpt_Less template_argument_list_opt TokenOpt_More {$$=$2;}
  ;
template_argument_list_opt
  : {$$=nullptr;}
  | template_argument_list {$$=$1;}
  ;
template_argument_list
  : template_argument {$$=new list<Value*>(); $$->push_back($1);}
  | template_argument_list TokenOpt_Comma template_argument {$1->push_back($3);}
  ;
template_argument
  : constant_expression { if($1) $$=$1->pret; else $$=nullptr;}
  ;

/********************************************************************** 委托定义语法 ********************************************************/
delegate_declaration
   : TokenKey_Delegate function_header function_empty_body {$$=new Delegate($2);}
   ;

/***********************************************************************************************************************************/
template_extend_opt
   : {$$=nullptr;}
   | template_declaration extend_opt { $$=$1; $$->setExtend($2);}
   | extend {$$=new Template(); $$->setExtend($1);}
   ;
extend_opt
 : {$$=nullptr;}
 | extend {$$=$1;}
 ;
extend
  :  TokenOpt_As interface_type_list {$$=$2;}
  ;
interface_type_list
  : class_type {$$=new list<Type*>(); $$->push_back($1);}
  | interface_type_list TokenOpt_Comma class_type {$1->push_back($3);}
  ;


/**************************************************************** 接口定义语法 *****************************************************/
interface_declaration
  : TokenKey_Interface Token_Identify template_extend_opt interface_body comma_opt
  { $$=new Interface($2->toString(),$3); $$->addModules($4); }
  ;

interface_body
  : TokenOpt_LeftBlock interface_member_declarations_opt TokenOpt_RightBlock {$$=$2;}
  ;
interface_member_declarations_opt
  : {$$=nullptr;}
  | interface_member_declarations {$$=$1;}
  ;
interface_member_declarations
  : interface_member_declaration {$$=new list<Module*>(); $$->push_back($1);}
  | interface_member_declarations interface_member_declaration {$1->push_back($2);}
  ;
interface_member_declaration
  : function_header function_empty_body {$$=$1;}
  ;

/*************************************************** 类定义表达式 ********************************************8*****/
class_declaration
  : TokenKey_Class class_super_opt Token_Identify template_extend_opt class_body comma_opt
    {$$=new Class($2,$3->toString(),$4); $$->addModules($5);}
  ;
class_super_opt
  : {$$=nullptr;}
  | TokenOpt_LeftBracket class_type TokenOpt_RightBracket {$$=$2;}
  ;

class_body
  : TokenOpt_LeftBlock class_member_declarations_opt TokenOpt_RightBlock {$$=$2;}
  ;
class_member_declarations_opt
  : {$$=nullptr;}
  | class_member_declarations {$$=$1;}
  ;
class_member_declarations
  : class_member_declaration {$$=new list<Module*>(); $$->push_back($1);}
  | class_member_declarations class_member_declaration {$1->push_back($2);}
  ;
/*类型定义 函数定义 和块定义*/
  class_member_declaration
  : protocol_opt class_protocol_member { $2->setProtocol($1);$$=$2;}
  ;
  class_protocol_member
  : attributes_opt class_modifiers_declaration {$2->setAttribute($1);$$=$2;}
  | class_body {$$=new Module(); $$->addModules($1);}
  ;
class_modifiers_declaration
  : function_declaration { $$=$1;}
  | local_variable_declaration TokenOpt_End { $$=new Module(); Block *pb; pb=new Block(); pb->addValue($1);$$->setBlock(pb);}
  ;

/***********************************************************函数定义******************************************************/
function_declaration
  : function_header function_body {$$=$1; $$->setBlock($2);}
  ;
function_header
  : type function_attribute_opt Token_Identify TokenOpt_LeftBracket function_parameter_list TokenOpt_RightBracket
    {$$=new Function($1,$3->toString()); $$->setFunctionAttribute($2); $$->setParams($5);}
  | type TokenKey_Operator operator_override TokenOpt_LeftBracket function_parameter_list TokenOpt_RightBracket
    {$$=new Function($1,$3); $$->setParams($5);}
  ;
function_attribute_opt
  : {$$=Attribute_None;}
  | function_attribute {$$=$1;}
  ;
function_attribute
  : TokenKey_Set {$$=Attribute_Set;}
  | TokenKey_Get {$$=Attribute_Get;}
  ;
function_empty_body
  : TokenOpt_End
  ;
function_body
  : block_statment {$$=new Block(); $$->addInstruction($1);}
  | TokenOpt_End {$$=nullptr;}
  ;

function_parameter_list
  :  {$$=nullptr;}
  | function_parameter {$$=new list<Value*>();$$->push_back($1);}
  | function_parameter_list TokenOpt_Comma function_parameter {$1->push_back($3);}
  ;

function_parameter
  : class_type Token_Identify function_parameter_argument_opt
  { if($3) {$$=$3;$$->type=$1; $$->name=$2->toString();} else $$=new Value($1,$2->toString());}
  ;
function_parameter_argument_opt
  : {$$=nullptr;}
  | TokenOpt_SetValue expression { $$=new Value(); $$->data=$2;}
  ;

operator_override
  : TokenOpt_Add {$$=AI_Add;}
  ;

/***********************************************************************语句语法*************************************************/
/*语句分为定义语句和集成语句*/
statement
  : declaration_statement {$$=$1;}
  | embedded_statement {$$=$1;}
  ;
/*定义语句********************************************************/
declaration_statement
  : attributes_opt local_variable_declaration TokenOpt_End
  { Value *pv; pv=new Value(); pv->data=(void*)$1; $$=new Instruction(AI_Declare,$2,pv,nullptr);}
  ;
local_variable_declaration
  :  class_type variable_declarators { Type *vType=new Type("@array"); Value *pv; pv=new Value(vType,$2,0); $$=pv; for(auto item:*$2) item->setType($1);}
  ;
variable_declarators
  : variable_declarator {$$=new list<Value*>(); $$->push_back($1);}
  | variable_declarators TokenOpt_Comma variable_declarator {$1->push_back($3);}
  ;
variable_declarator
  : Token_Identify {$$=new Value(nullptr,$1->toString());}
  | Token_Identify TokenOpt_SetValue variable_initializer {Type *vType=new Type("@value"); $$=new Value(vType,$1->toString()); $$->data=$3;}
  ;
variable_initializer
  : expression %prec lower_than_rightbracket {if($1) $$=$1->pret; else $$=nullptr;}
  | array_initializer  { Type *vType=new Type("@array"); $$=new Value(vType,$1,0);$$->setReadOnly();}
  ;
array_initializer
  : TokenOpt_LeftBracket variable_initializer_list_opt TokenOpt_RightBracket {$$=$2;}
  | TokenOpt_LeftBracket variable_initializer_list TokenOpt_Comma TokenOpt_RightBracket {$$=$2;}
  ;
variable_initializer_list_opt
  : {$$=nullptr;}
  | variable_initializer_list {$$=$1;}
  ;
variable_initializer_list
  : variable_initializer {$$=new list<Value*>();$$->push_back($1);}
  | variable_initializer_list TokenOpt_Comma variable_initializer {$1->push_back($3);}
  ;
/*集合语句****************************************************************/
embedded_statement
  : block_statment {$$=$1;}
  | empty_statement {$$=nullptr;}
  | iteration_statement {$$=$1;}
  | expression_statement {$$=$1;}
  | selection_statement {$$=$1;}
  | jump_statement {$$=$1;}
  ;
/*块语句*/
block_statment
  : TokenOpt_LeftBlock statement_list_opt TokenOpt_RightBlock { Value *ret; ret=new Value(); ret->data=$2; $$=new Instruction(AI_Block,ret,nullptr,nullptr);}
  ;
statement_list_opt
  : {$$=nullptr;}
  | statement_list {$$=$1;}
  ;
statement_list
  : statement {$$=new list<Instruction*>(); $$->push_back($1);}
  | statement_list statement {$1->push_back($2);}
  ;
/*空语句*/
empty_statement
  : TokenOpt_End
  ;

/*表达式语句,详见表达式部分 */
expression_statement
  : statement_expression TokenOpt_End {$$=$1;}
  ;

statement_expression
  : invocation_expression {$$=$1;}
  | object_creation_expression {$$=$1;}
  | assignment {$$=$1;}
  | post_increment_expression {$$=$1;}
  | post_decrement_expression {$$=$1;}
  ;
/*选择语句*/
selection_statement
  : if_statement {$$=$1;}
  | switch_statement {$$=$1;}
  ;
if_statement
  : TokenKey_If TokenOpt_LeftBracket boolean_expression TokenOpt_RightBracket embedded_statement  %prec lower_than_else
    { Value *pv=new Value(); pv->data=$5; $$=new Instruction(AI_If,$3->pret,pv,nullptr); }
  | TokenKey_If TokenOpt_LeftBracket boolean_expression TokenOpt_RightBracket embedded_statement TokenKey_Else embedded_statement
    { Value *pv=new Value(); pv->data=$5;  Value *pv2=new Value(); pv->data=$7; $$=new Instruction(AI_Switch,$3->pret,pv,pv2);}
  ;
switch_statement
  : TokenKey_Switch TokenOpt_LeftBracket expression TokenOpt_RightBracket switch_block
  {{ Value *pv=nullptr; if($5) pv=$5->pret; $$=new Instruction(AI_Switch,$3->pret,pv,nullptr);}}
  ;
switch_block
  : TokenOpt_LeftBlock switch_sections_opt TokenOpt_RightBlock {$$=$2;}
  ;
switch_sections_opt
  : {$$=nullptr;}
  | switch_sections { Value *ret; ret=new Value(); ret->data=$1; $$=new Instruction(AI_Block,ret,nullptr,nullptr);}
  ;
switch_sections
  : switch_section {$$=new list<Instruction*>(); $$->push_back($1);}
  | switch_sections switch_section {$1->push_back($2);}
  ;
switch_section
  : switch_labels statement_list { Value *ret; ret=new Value(); ret->data=$1; Value *pv; pv=new Value(); pv->data=$2; $$=new Instruction(AI_Block,ret,pv,nullptr);}
  ;
switch_labels
  : switch_label {$$=new list<Instruction*>(); $$->push_back($1);}
  | switch_labels switch_label {$1->push_back($2);}
  ;
switch_label
  : TokenKey_Case constant_expression TokenOpt_As { $$=new Instruction(AI_Case,$2->pret,nullptr,nullptr);}
  | TokenKey_Default TokenOpt_As { $$=new Instruction(AI_Default,nullptr,nullptr,nullptr);}
  ;

/*循环语句*/
iteration_statement
  : while_statement {$$=$1;}
  | for_statement {$$=$1;}
  ;

while_statement
  : TokenKey_While TokenOpt_LeftBracket boolean_expression TokenOpt_RightBracket embedded_statement
  {  Value *pv=new Value(); pv->data=$5; $$=new Instruction(AI_While,$3->pret,pv,nullptr);}
  ;

for_statement
  : TokenKey_For TokenOpt_LeftBracket for_expression TokenOpt_RightBracket embedded_statement
     {  Value *pv=new Value(); pv->data=$5; $$=new Instruction(AI_For,$3->pret,pv,nullptr);}
  ;

for_expression
  : for_initializer TokenOpt_As for_iterator  { Value *ret; ret=new Value();$$=new Instruction(AI_As,ret,$1,$3);}
  | for_initializer TokenOpt_To for_iterator  {Value *ret; ret=new Value();$$=new Instruction(AI_To,ret,$1,$3);}
  ;

for_initializer
  : local_variable_declaration {$$=$1;}
  | variable_reference {$$=$1;}
  ;

for_iterator
  : variable_reference {$$=$1;}
  ;

/*跳转语句*/
jump_statement
  : break_statement {$$=$1;}
  | continue_statement {$$=$1;}
  | return_statement {$$=$1;}
  ;
break_statement
  : TokenKey_Break TokenOpt_End {$$=new Instruction(AI_Break,nullptr,nullptr,nullptr);}
  ;
continue_statement
  : TokenKey_Continue expression_opt TokenOpt_End {Value *ret=nullptr; if($2) ret=$2->pret; $$=new Instruction(AI_Continue,ret,nullptr,nullptr);}
  ;

return_statement
  : TokenKey_Return expression_opt TokenOpt_End {Value *ret=nullptr; if($2) ret=$2->pret; $$=new Instruction(AI_Return,ret,nullptr,nullptr);}
  ;

/******************************************表达式语法***********************************************************/
/*表达式列表*/

expression
  : conditional_expression {$$=$1;}
  | assignment {$$=$1;}
  ;

/* 主表达式 包含 有括号,和没有括号两种*/
primary_expression
  : parenthesized_expression {$$=$1;}
  | primary_expression_no_parenthesis {$$=$1;}
  ;
/* 无括号的主表达式 包括 常量 数组创建表达式 成员访问 函数调用表达式 数组元素访问 this指针 super访问,和new表达式*/
primary_expression_no_parenthesis
  : literal {$$=new Instruction(AI_Access,$1,nullptr,nullptr);}
  | member_access {$$=$1;}
  | invocation_expression {$$=$1;}
  | element_access {$$=$1;}
  | this_access {$$=new Instruction(AI_Access,$1,nullptr,nullptr);}
  | super_access {$$=new Instruction(AI_Access,$1,nullptr,nullptr);}
  | new_expression {$$=$1;}
  ;
/*括号匹配表达式*/
parenthesized_expression
  : TokenOpt_LeftBracket expression TokenOpt_RightBracket {$$=$2;}
  ;
/*成员访问*/
member_access
  : primary_expression TokenOpt_Dot Token_Identify { Value *pv; pv=new Value();pv->name=$3->toString();$$=new Instruction(AI_Access,pv,$1->pret,nullptr);}
  | class_type TokenOpt_Dot Token_Identify  { $$=new Instruction(AI_Access,new Value($1,$3->toString()),nullptr,nullptr);}
  ;
/*函数调用表达式*/
invocation_expression
  : primary_expression_no_parenthesis TokenOpt_LeftBracket argument_list_opt TokenOpt_RightBracket
  {Value *ret; ret=new Value(); Value *pv=nullptr; if($3) {pv=new Value(); pv->data=$3;} $$=new Instruction(AI_Call,ret,$1->pret,pv);}
  ;
/*参数列表*/
argument_list_opt
  : /* 空 */ {$$=nullptr;}
  | argument_list {$$=$1;}
  ;
/* 数组元素的访问 */
element_access
  : primary_expression TokenOpt_LeftIndex expression TokenOpt_RightIndex
  { Value *pv; pv=new Value();$$=new Instruction(AI_Access,pv,$1->pret,$3->pret);}
  ;


/*this指针访问*/
this_access
  : TokenKey_This { Type *vType=new Type("@this");$$=new Value(vType,nullptr,0);$$->setReadOnly();}
  ;
/*super指针访问*/
super_access
  : TokenKey_Super { Type *vType=new Type("@super");$$=new Value(vType,nullptr,0);$$->setReadOnly();}
  ;

/*new表达式*/
new_expression
  : object_creation_expression {$$=$1;}
  ;
object_creation_expression
  : TokenKey_New class_type TokenOpt_LeftBracket argument_list_opt TokenOpt_RightBracket
  {Value *ret; ret=new Value($2,nullptr,0);$$=new Instruction(AI_New,ret,nullptr,nullptr); ret->data=$4;}
  ;



/*后缀表达式*/
postfix_expression
  : primary_expression {$$=$1;}
  | post_increment_expression {$$=$1;}
  | post_decrement_expression {$$=$1;}
  ;

/*后缀++ --*/
post_increment_expression
  : postfix_expression TokenOpt_Inc {Value *ret; ret=new Value();$$=new Instruction(AI_Inc,ret,$1->pret,nullptr);}
  ;
post_decrement_expression
  : postfix_expression TokenOpt_Dec {Value *ret; ret=new Value();$$=new Instruction(AI_Dec,ret,$1->pret,nullptr);}
  ;

unary_expression_not_plusminus
  : postfix_expression {$$=$1;}
  | TokenOpt_Not unary_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Not,ret,$2->pret,nullptr);}
  | TokenOpt_BitNot unary_expression {Value *ret; ret=new Value();$$=new Instruction(AI_BitNot,ret,$2->pret,nullptr);}
  | cast_expression {$$=$1;}
  ;
unary_expression
  : unary_expression_not_plusminus {$$=$1;}
  | TokenOpt_Add unary_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Plus,ret,$2->pret,nullptr);}
  | TokenOpt_Sub unary_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Minus,ret,$2->pret,nullptr);}
  ;
/* 类型转换 */
cast_expression
  : TokenOpt_LeftBracket class_type TokenOpt_RightBracket unary_expression
  {Value *ret; ret=new Value($2,nullptr,0);$$=new Instruction(AI_Call,ret,$4->pret,nullptr);}
  ;

/*多项表达式*/
multiplicative_expression
  : unary_expression {$$=$1;}
  | multiplicative_expression TokenOpt_Mul unary_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Mul,ret,$1->pret,$3->pret);}
  | multiplicative_expression TokenOpt_Div unary_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Div,ret,$1->pret,$3->pret);}
  | multiplicative_expression TokenOpt_Mod unary_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Mod,ret,$1->pret,$3->pret);}
  ;

additive_expression
  : multiplicative_expression {$$=$1;}
  | additive_expression TokenOpt_Add multiplicative_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Add,ret,$1->pret,$3->pret);}
  | additive_expression TokenOpt_Sub multiplicative_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Sub,ret,$1->pret,$3->pret);}
  ;
shift_expression
  : additive_expression {$$=$1;}
  | shift_expression TokenOpt_ShiftLeft additive_expression {Value *ret; ret=new Value();$$=new Instruction(AI_ShiftLeft,ret,$1->pret,$3->pret);}
  | shift_expression TokenOpt_ShiftRight additive_expression {Value *ret; ret=new Value();$$=new Instruction(AI_ShiftRight,ret,$1->pret,$3->pret);}
  ;

relational_expression
  : shift_expression {$$=$1;}
  | relational_expression TokenOpt_Less shift_expression {Value *ret; ret=new Value();$$=new Instruction(AI_Less,ret,$1->pret,$3->pret);}
  | relational_expression TokenOpt_More shift_expression {Value *ret; ret=new Value();$$=new Instruction(AI_More,ret,$1->pret,$3->pret);}
  | relational_expression TokenOpt_LessEqual shift_expression {Value *ret; ret=new Value();$$=new Instruction(AI_LessEqual,ret,$1->pret,$3->pret);}
  | relational_expression TokenOpt_MoreEqual shift_expression {Value *ret; ret=new Value();$$=new Instruction(AI_MoreEqual,ret,$1->pret,$3->pret);}
  ;
equality_expression
  : relational_expression    %prec lower_than_more {$$=$1;}
  | equality_expression TokenOpt_Equal relational_expression %prec lower_than_more
  {Value *ret; ret=new Value();$$=new Instruction(AI_Equal,ret,$1->pret,$3->pret);}
  | equality_expression TokenOpt_NotEqual relational_expression %prec lower_than_more
  {{Value *ret; ret=new Value();$$=new Instruction(AI_NotEqual,ret,$1->pret,$3->pret);}}
  ;
and_expression
  : equality_expression {$$=$1;}
  | and_expression TokenOpt_BitAnd equality_expression
  {Value *ret; ret=new Value();$$=new Instruction(AI_BitAnd,ret,$1->pret,$3->pret);}
  ;
exclusive_or_expression
  : and_expression {$$=$1;}
  | exclusive_or_expression TokenOpt_BitXor and_expression
	{Value *ret; ret=new Value();$$=new Instruction(AI_BitXor,ret,$1->pret,$3->pret);}
  ;
inclusive_or_expression
  : exclusive_or_expression {$$=$1;}
  | inclusive_or_expression TokenOpt_BitOr exclusive_or_expression
  {Value *ret; ret=new Value();$$=new Instruction(AI_BitOr,ret,$1->pret,$3->pret);}
  ;
conditional_and_expression
  : inclusive_or_expression {$$=$1;}
  | conditional_and_expression TokenOpt_And inclusive_or_expression
   {Value *ret; ret=new Value();$$=new Instruction(AI_And,ret,$1->pret,$3->pret);}
  ;
conditional_or_expression
  : conditional_and_expression {$$=$1;}
  | conditional_or_expression TokenOpt_Or conditional_and_expression
	{Value *ret; ret=new Value();$$=new Instruction(AI_Or,ret,$1->pret,$3->pret);}
  ;
conditional_expression
  : conditional_or_expression {$$=$1;}
  ;
/*等式*/
assignment
  : unary_expression assignment_operator expression
	{
		if($1->pret->readOnly){
			//表示左值为只读,是个错误的表达式
			Log::error("错误的表达式,该表达式左值只读.");
			$$=nullptr;
		}else{
			Value *ret; ret=new Value();$$=new Instruction($2,ret,$1->pret,$3->pret);
			//$$=new ASTAssignmentExpression($2,$1,$3);
		}

	}
  ;
assignment_operator
  : TokenOpt_SetValue {$$=AI_Assign;}| TokenOpt_SetAdd{$$=AI_AddAssign;} | TokenOpt_SetSub {$$=AI_SubAssign;}
  | TokenOpt_SetMul{$$=AI_MulAssign;} | TokenOpt_SetDiv {$$=AI_DivAssign;}| TokenOpt_SetMod {$$=AI_ModAssign;}
  | TokenOpt_SetBitXor {$$=AI_BitXorAssign;}| TokenOpt_SetBitAnd {$$=AI_BitAndAssign;}| TokenOpt_SetBitOr{$$=AI_BitOrAssign;}
  | TokenOpt_SetShiftRight{$$=AI_ShiftRightAssign;} | TokenOpt_SetShiftLeft {$$=AI_ShiftLeftAssign;}
  ;


/*常量表达式*/
constant_expression
  : expression { $$=$1;}
  ;
/*布尔表达式*/
boolean_expression
  : expression { $$=$1;}
  ;

expression_opt
  :  {$$=nullptr;}
  | expression {$$=$1;}
  ;

/***************************************类型定义**************************************************************/

/***** 类型定义 *****/
type
  : simple_type  {$$=$1;}
  | class_type  %prec lower_than_identify {$$=$1;}
  ;
simple_type
  : TokenKey_Void {$$=new Type("light");$$->addSubType("lang");$$->addSubType("Void");}
  ;
class_type
  : qualified_identifier template_arguments_opt
  {$$=$1; $$->addArgumentList($2); delete $2;}
  ;

/***** 值的定义 *****/
variable_reference
  : expression {$$=$1->pret;}
  ;
/***** 表达式定义 *****/
argument_list
  : argument {$$=new list<Value*>(); $$->push_back($1);}
  | argument_list TokenOpt_Comma argument {$1->push_back($3);}
  ;
argument
  : expression {$$=$1->pret;}
  ;

/***** 常量 *****/
literal
  : boolean_literal {$$=$1;}
  | Token_Integer
    { Type *vType=new Type("light");vType->addSubType("lang");vType->addSubType("Int");$$=new Value(vType,$1->toString(),0);$$->setReadOnly();}
  | Token_Float
    {Type *vType=new Type("light");vType->addSubType("lang");vType->addSubType("Float");$$=new Value(vType,$1->toString(),0);$$->setReadOnly();}
  | Token_Character
    { Type *vType=new Type("light");vType->addSubType("lang");vType->addSubType("Character");$$=new Value(vType,$1->toString(),0);$$->setReadOnly();}
  | Token_String
    { Type *vType=new Type("light");vType->addSubType("lang");vType->addSubType("String");$$=new Value(vType,$1->toString(),0);$$->setReadOnly();}
  | TokenKey_Null
    { Type *vType=new Type("light");vType->addSubType("lang");vType->addSubType("Object");$$=new Value(vType,nullptr,0);$$->setReadOnly();}
  ;

boolean_literal
  : TokenKey_True
    { Type *vType=new Type("light");vType->addSubType("lang");vType->addSubType("Bool");$$=new Value(vType,"true",0);$$->setReadOnly();}
  | TokenKey_False
    { Type *vType=new Type("light");vType->addSubType("lang");vType->addSubType("Bool");$$=new Value(vType,"false",0);$$->setReadOnly();}
  ;

%%

int yyerror(const char *s)
{
  fprintf(stderr,"%d:%s",yylineno,s);
  return 1;
}
