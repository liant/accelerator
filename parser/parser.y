%{
  extern int yylineno;
  #include "../context/context.h"
  #include "tokentype.h"
  #include <list>
  #include <array>
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
    Literal *literal;
    std::list<Expression*> *expressionList;
    std::list<ClassObject*> *objectList;
    std::list<Token*> *tokenList;
    std::list<Package*> *packageList;
    std::list<Node*> *nodeList;
    std::list<Function*> *functionList;
    std::list<ClassType*> *typeList;
    std::list<Statment*> *statmentList;
    Expression *expression;
    Statment *statment;
    Token *token;
    ClassType *type;
    ClassObject *object;
    ClassObjectBlock *objectBlock;
     Class *pClass;
     Interface *interface;
     Delegate *delegate;
    Node *node;
    Function *function;
    Node* *pArray;
     Protocol protocol;
     TokenType tokentype;
     Modifier modifiertype;
     ExpressionOverrideOperator override_operator;
     ExpressionAssignmentOperator assign_operator;
     CaseStatment *casestatment;
}
%type <override_operator> operator_override
%type <assign_operator> assignment_operator

%type <protocol> protocol_opt protocol

%type <modifiertype> modifier modifiers_opt modifiers

%type <token> Token_String Token_Character  Token_Float Token_Integer Token_Identify
%type <tokenList>qualified_identifier

%type <package> package_declaration import_directive
%type <tokenList> package_name
%type <nodeList> package_body package_member_declarations_opt package_member_declarations import_directives_opt import_directives
%type <node> package_member_declaration package_type_declaration package_templatetype_declaration

%type <pEnum> enum_declaration
%type <type> enum_super_opt enum_extend_opt
%type <objectList> enum_body enum_member_declarations_opt enum_member_declarations
%type <object> enum_member_declaration

%type <pTemplate> template_declaration template_opt
%type <objectList> template_body_opt template_body template_params
%type <object> template_param
%type <expressionList> template_arguments_opt template_argument_list_opt template_argument_list
%type <expression> template_param_argument_opt template_argument

%type <delegate> delegate_declaration

%type <interface> interface_declaration
%type <typeList> interface_extend_opt interface_extend interface_type_list
%type <functionList> interface_body interface_member_declarations_opt interface_member_declarations
%type <function> interface_member_declaration

%type <pClass> class_declaration
%type <type> class_super_opt
%type <typeList> class_extend_opt
%type <nodeList> class_body class_member_declarations_opt class_member_declarations
%type <node> class_member_declaration class_protocol_member class_modifiers_declaration

%type <function> function_declaration function_header
%type <modifiertype> function_modifier_opt function_modifier
%type <statment> function_body
%type <objectList> function_parameter_list
%type <object> function_parameter
%type <expression> function_parameter_argument_opt

%type <statment> statement declaration_statement
%type <objectList> variable_declarators
%type <object> variable_declarator
%type <expression> variable_initializer
%type <expressionList> array_initializer variable_initializer_list_opt variable_initializer_list

%type <statment> embedded_statement block_statment expression_statement selection_statement if_statement switch_statement iteration_statement for_statement while_statement jump_statement break_statement continue_statement return_statement
%type <statmentList> statement_list_opt statement_list switch_block switch_sections_opt switch_sections
%type <casestatment> switch_label switch_labels switch_section
%type <expression> statement_expression for_expression for_iterator for_initializer

%type <expression> expression  expression_opt
%type <expression> parenthesized_expression primary_expression_no_parenthesis primary_expression

%type <expression> assignment unary_expression unary_expression_not_plusminus
%type <expression> boolean_expression constant_expression
%type <expression> conditional_expression conditional_or_expression conditional_and_expression
%type <expression> inclusive_or_expression exclusive_or_expression and_expression equality_expression
%type <expression> relational_expression shift_expression additive_expression multiplicative_expression
%type <expression> postfix_expression post_decrement_expression post_increment_expression

%type <expression> cast_expression new_expression
%type <expression> invocation_expression object_creation_expression
%type <expression> this_access super_access member_access element_access

%type <type> class_type simple_type type
%type <objectBlock> local_variable_declaration

%type <expressionList> expression_list argument_list argument_list_opt
%type <expression> argument variable_reference

%type <literal> literal boolean_literal

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
modifiers_opt
   : %prec lower_than_identify {$$=Modifier_None;}
   | modifiers {$$=$1;}
   ;
modifiers
   : modifier {$$=$1;}
   | modifiers modifier {$1=(Modifier)($1|$2);}
    ;
modifier
    : TokenKey_Static {$$=Modifier_Static;}
    | TokenKey_Const {$$=Modifier_Const;}
     ;

/******************************* 递归标识符 a.b.c.d这种 ******************************************/
qualified_identifier
  : Token_Identify {$$=new list<Token*>(); $$->push_back($1);}
  | qualified_identifier TokenOpt_Dot Token_Identify {$1->push_back($3);}
  ;

/*结尾*/
comma_opt
  :
  | TokenOpt_End
  ;

/*****************************************************************包定义*****************************************************************************/
package_declaration
  : protocol_opt TokenKey_Package package_name package_body comma_opt
	 {$$=new Package($1,$3); $$->setContent($4);}
  ;
package_name
  : qualified_identifier { $$=$1;}
  ;

/*包的主体,包括import 成员定义 */
package_body
  : TokenOpt_LeftBlock import_directives_opt package_member_declarations_opt TokenOpt_RightBlock
         { $$=new list<Node*>(); $$->merge(*$2);$$->merge(*$3); delete $2; delete $3;}
  ;
import_directives_opt
  : /* 空 */{$$=nullptr;}
  | import_directives {$$=$1;}
  ;
import_directives
  : import_directive {$$=new list<Node*>(); $$->push_back($1);}
  | import_directives import_directive {$1->push_back($2);}
  ;
import_directive
  : TokenKey_Import package_name TokenOpt_End  {$$=new Package(Protocol_Protected,$2);}
  ;

package_member_declarations_opt
  : /* 空 */ {$$=nullptr;}
  | package_member_declarations  {$$=$1;}
  ;

package_member_declarations
  : package_member_declaration   {$$=new list<Node*>(); $$->push_back($1);}
  | package_member_declarations package_member_declaration {$1->push_back($2);}
  ;
package_member_declaration
   : protocol_opt package_type_declaration {$$->setProtocol($1);}
    ;
package_type_declaration
    : enum_declaration {$$=$1;}
    | template_opt package_templatetype_declaration {$$=$2;$$->setTemplate($1);}
     ;
package_templatetype_declaration
  : class_declaration   {$$=$1;}
  | interface_declaration {$$=$1;}
  | delegate_declaration {$$=$1;}
  ;

/********************************************************************** 枚举定义语法 ********************************************************/

enum_declaration
  : TokenKey_Enum enum_super_opt Token_Identify enum_extend_opt enum_body comma_opt
  {$$=new Enum($2,$3,$4);$$->setContent($5);}
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
  : enum_member_declaration {$$=new list<ClassObject*>(); $$->push_back($1);}
  | enum_member_declarations TokenOpt_Comma enum_member_declaration {$1->push_back($3);}
  ;
enum_member_declaration
  : Token_Identify {$$=new ClassObject(nullptr,$1,nullptr);}
  | Token_Identify TokenOpt_SetValue constant_expression {$$=new ClassObject(nullptr,$1,$3);}
  ;

/********************************************************************模板************************************************/

template_opt
   : {$$=nullptr;}
   |template_declaration {$$=$1;}
   ;

template_declaration
  : TokenKey_Template TokenOpt_Less template_body_opt TokenOpt_More
  { $$=new Template(); $$->setContent($3);}
  ;

template_body_opt
  :  { $$=nullptr;}
  | template_body {$$=$1;}
  ;
template_body
  : template_params {$$=$1;}
  ;
template_params
  : template_param  {$$=new list<ClassObject*>(); $$->push_back($1); }
  |  template_params TokenOpt_Comma template_param {$1->push_back($3);}
  ;
template_param
  : class_type Token_Identify template_param_argument_opt{ $$=new ClassObject($1,$2,$3);}
  ;
template_param_argument_opt
   : {$$=nullptr;}
   | TokenOpt_SetValue constant_expression {$$=$2;}
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
  : template_argument {$$=new list<Expression*>(); $$->push_back($1);}
  | template_argument_list TokenOpt_Comma template_argument {$1->push_back($3);}
  ;
template_argument
  : constant_expression {$$=$1;}
  ;

/********************************************************************** 委托定义语法 ********************************************************/
delegate_declaration
   : TokenKey_Delegate function_header function_empty_body {$$=new Delegate($2);}
   ;

/**************************************************************** 接口定义语法 *****************************************************/
interface_declaration
  : TokenKey_Interface Token_Identify interface_extend_opt interface_body comma_opt
  { $$=new Interface($2,$3); $$->setContent($4);}
  ;
interface_extend_opt
  :  {$$=nullptr;}
  | interface_extend {$$=$1;}
  ;
interface_extend
  :  TokenOpt_As interface_type_list {$$=$2;}
  ;
interface_type_list
  : class_type {$$=new list<ClassType*>(); $$->push_back($1);}
  | interface_type_list TokenOpt_Comma class_type {$1->push_back($3);}
  ;
interface_body
  : TokenOpt_LeftBlock interface_member_declarations_opt TokenOpt_RightBlock {$$=$2;}
  ;
interface_member_declarations_opt
  : {$$=nullptr;}
  | interface_member_declarations {$$=$1;}
  ;
interface_member_declarations
  : interface_member_declaration {$$=new list<Function*>(); $$->push_back($1);}
  | interface_member_declarations interface_member_declaration {$1->push_back($2);}
  ;
interface_member_declaration
  : function_header function_empty_body {$$=$1;}
  ;

/*************************************************** 类定义表达式 ********************************************8*****/
class_declaration
  : TokenKey_Class class_super_opt Token_Identify class_extend_opt class_body comma_opt
    {$$=new Class($2,$3,$4); $$->setContent($5);}
  ;
class_super_opt
  : {$$=nullptr;}
  | TokenOpt_LeftBracket class_type TokenOpt_RightBracket {$$=$2;}
  ;

class_extend_opt
 : {$$=nullptr;}
 | TokenOpt_As interface_type_list {$$=$2;}
  ;

class_body
  : TokenOpt_LeftBlock class_member_declarations_opt TokenOpt_RightBlock {$$=$2;}
  ;
class_member_declarations_opt
  : {$$=nullptr;}
  | class_member_declarations {$$=$1;}
  ;
class_member_declarations
  : class_member_declaration {$$=new list<Node*>(); $$->push_back($1);}
  | class_member_declarations class_member_declaration {$1->push_back($2);}
  ;
/*类型定义 函数定义 和块定义*/
  class_member_declaration
  : protocol_opt class_protocol_member {$2->setProtocol($1);$$=$2;}
  ;
  class_protocol_member
  : modifiers_opt class_modifiers_declaration {$2->setModifiers($1);$$=$2;}
  | class_body {$$=new Block($1);}
  ;
class_modifiers_declaration
  : function_declaration { $$=$1;}
  | class_type variable_declarators TokenOpt_End {$$=new ClassObjectBlock($1,$2);}
  ;

/***********************************************************函数定义******************************************************/
function_declaration
  : function_header function_body {$$=$1; $$->setContent($2);}
  ;
function_header
  : type function_modifier_opt Token_Identify TokenOpt_LeftBracket function_parameter_list TokenOpt_RightBracket
    {$$=new Function($1,$3); $$->setFunctionModifier($2); $$->setParams($5);}
  | type TokenKey_Operator operator_override TokenOpt_LeftBracket function_parameter_list TokenOpt_RightBracket
    {$$=new Function($1,$3); $$->setParams($5);}
  ;
function_modifier_opt
  : {$$=Modifier_None;}
  | function_modifier {$$=$1;}
  ;
function_modifier
  : TokenKey_Set {$$=Modifier_Set;}
  | TokenKey_Get {$$=Modifier_Get;}
  ;
function_empty_body
  : TokenOpt_End
  ;
function_body
  : block_statment {$$=$1;}
  | TokenOpt_End {$$=nullptr;}
  ;

function_parameter_list
  :  {$$=nullptr;}
  | function_parameter {$$=new list<ClassObject*>();$$->push_back($1);}
  | function_parameter_list TokenOpt_Comma function_parameter {$1->push_back($3);}
  ;

function_parameter
  : class_type Token_Identify function_parameter_argument_opt {$$=new ClassObject($1,$2,$3);}
  ;
function_parameter_argument_opt
  : {$$=nullptr;}
  | TokenOpt_SetValue expression {$$=$2;}
  ;

operator_override
  : TokenOpt_Add {$$=EOO_Add;}
  ;

/***********************************************************************语句语法*************************************************/
/*语句分为定义语句和集成语句*/
statement
  : declaration_statement {$$=$1;}
  | embedded_statement {$$=$1;}
  ;
/*定义语句********************************************************/
declaration_statement
  : modifiers_opt local_variable_declaration TokenOpt_End
  { $2->setModifiers($1); $$=new DeclareStatment($2);}
  ;
local_variable_declaration
  :  class_type variable_declarators {$$=new ClassObjectBlock($1,$2);}
  ;
variable_declarators
  : variable_declarator {$$=new list<ClassObject*>(); $$->push_back($1);}
  | variable_declarators TokenOpt_Comma variable_declarator {$1->push_back($3);}
  ;
variable_declarator
  : Token_Identify {$$=new ClassObject(nullptr,$1,nullptr);}
  | Token_Identify TokenOpt_SetValue variable_initializer {$$=new ClassObject(nullptr,$1,$3);}
  ;
variable_initializer
  : expression %prec lower_than_rightbracket {$$=$1;}
  | array_initializer {$$=new ArrayExpression($1);}
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
  : variable_initializer {$$=new list<Expression*>();$$->push_back($1);}
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
  : TokenOpt_LeftBlock statement_list_opt TokenOpt_RightBlock {$$=new BlockStatment($2);}
  ;
statement_list_opt
  : {$$=nullptr;}
  | statement_list {$$=$1;}
  ;
statement_list
  : statement {$$=new list<Statment*>(); $$->push_back($1);}
  | statement_list statement {$1->push_back($2);}
  ;
/*空语句*/
empty_statement
  : TokenOpt_End
  ;

/*表达式语句,详见表达式部分 */
expression_statement
  : statement_expression TokenOpt_End {$$=new ExpressionStatment($1);}
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
    {$$=new IfStatment($3,$5);}
  | TokenKey_If TokenOpt_LeftBracket boolean_expression TokenOpt_RightBracket embedded_statement TokenKey_Else embedded_statement
    {$$=new IfStatment($3,$5,$7);}
  ;
switch_statement
  : TokenKey_Switch TokenOpt_LeftBracket expression TokenOpt_RightBracket switch_block
  {$$=new SwitchStatment($3,$5);}
  ;
switch_block
  : TokenOpt_LeftBlock switch_sections_opt TokenOpt_RightBlock {$$=$2;}
  ;
switch_sections_opt
  : {$$=nullptr;}
  | switch_sections {$$=$1;}
  ;
switch_sections
  : switch_section {$$=new list<Statment*>(); $$->push_back($1);}
  | switch_sections switch_section {$1->push_back($2);}
  ;
switch_section
  : switch_labels statement_list {$1->setContent($2); $$=$1;}
  ;
switch_labels
  : switch_label {$$=$1;}
  | switch_labels switch_label {$1->pushCases($2);}
  ;
switch_label
  : TokenKey_Case constant_expression TokenOpt_As {$$=new CaseStatment($2);}
  | TokenKey_Default TokenOpt_As {$$=new CaseStatment(nullptr);}
  ;

/*循环语句*/
iteration_statement
  : while_statement {$$=$1;}
  | for_statement {$$=$1;}
  ;

while_statement
  : TokenKey_While TokenOpt_LeftBracket boolean_expression TokenOpt_RightBracket embedded_statement
  {$$=new WhileStatment($3,$5);}
  ;

for_statement
  : TokenKey_For TokenOpt_LeftBracket for_expression TokenOpt_RightBracket embedded_statement
     {$$=new ForStatment($3,$5);}
  ;

for_expression
  : for_initializer TokenOpt_As for_iterator  {$$=new NifixExpression(ENO_As,$1,$3);}
  | for_initializer TokenOpt_To for_iterator  {$$=new NifixExpression(ENO_To,$1,$3);}
  ;

for_initializer
  : local_variable_declaration {$$=new DeclareExpression($1);}
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
  : TokenKey_Break TokenOpt_End {$$=new BreakStatment();}
  ;
continue_statement
  : TokenKey_Continue TokenOpt_End {$$=new ContinueStatment();}
  ;

return_statement
  : TokenKey_Return expression_opt TokenOpt_End {$$=new ReturnStatment($2);}
  ;

/******************************************表达式语法***********************************************************/
/*表达式列表*/
expression_list
  : expression {$$=new list<Expression*>();$$->push_back($1);}
  | expression_list TokenOpt_Comma expression {$1->push_back($3);}
  ;

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
  : literal {$$=new AccessExpression($1);}
  | member_access {$$=$1;}
  | invocation_expression {$$=$1;}
  | element_access {$$=$1;}
  | this_access {$$=$1;}
  | super_access {$$=$1;}
  | new_expression {$$=$1;}
  ;
/*括号匹配表达式*/
parenthesized_expression
  : TokenOpt_LeftBracket expression TokenOpt_RightBracket {$$=new PostfixExpression(EPostO_Bracket,$2);}
  ;
/*成员访问*/
member_access
  : primary_expression TokenOpt_Dot Token_Identify {$$=new AccessExpression($1,$3);}
  | class_type TokenOpt_Dot Token_Identify  {$$=new AccessExpression($1,$3);}
  ;
/*函数调用表达式*/
invocation_expression
  : primary_expression_no_parenthesis TokenOpt_LeftBracket argument_list_opt TokenOpt_RightBracket {$$=new InvokeExpression($1,$3);}
  ;
/*参数列表*/
argument_list_opt
  : /* 空 */ {$$=nullptr;}
  | argument_list {$$=$1;}
  ;
/* 数组元素的访问 */
element_access
  : primary_expression TokenOpt_LeftIndex expression_list TokenOpt_RightIndex {$$=new AccessExpression($1,$3);}
  ;


/*this指针访问*/
this_access
  : TokenKey_This {$$=new AccessExpression(new Literal(ThisLiteral,nullptr));}
  ;
/*super指针访问*/
super_access
  : TokenKey_Super {$$=new AccessExpression(new Literal(SuperLiteral,nullptr));}
  ;

/*new表达式*/
new_expression
  : object_creation_expression {$$=$1;}
  ;
object_creation_expression
  : TokenKey_New class_type TokenOpt_LeftBracket argument_list_opt TokenOpt_RightBracket {$$=new NewExpression($2,$4);}
  ;



/*后缀表达式*/
postfix_expression
  : primary_expression {$$=$1;}
  | post_increment_expression {$$=$1;}
  | post_decrement_expression {$$=$1;}
  ;

/*后缀++ --*/
post_increment_expression
  : postfix_expression TokenOpt_Inc {$$=new PostfixExpression(EPostO_Inc,$1);}
  ;
post_decrement_expression
  : postfix_expression TokenOpt_Dec {$$=new PostfixExpression(EPostO_Dec,$1);}
  ;

unary_expression_not_plusminus
  : postfix_expression {$$=$1;}
  | TokenOpt_Not unary_expression {$$=new PrefixExpression(EPreO_Not,$2);}
  | TokenOpt_BitNot unary_expression {$$=new PrefixExpression(EPreO_BitNot,$2);}
  | cast_expression {$$=$1;}
  ;
unary_expression
  : unary_expression_not_plusminus {$$=$1;}
  | TokenOpt_Add unary_expression {$$=new PrefixExpression(EPreO_Plus,$2);}
  | TokenOpt_Sub unary_expression {$$=new PrefixExpression(EPreO_Minus,$2);}
  ;
/* 类型转换 */
cast_expression
  : TokenOpt_LeftBracket class_type TokenOpt_RightBracket unary_expression {$$=new CastExpression($2,$4);}
  ;

/*多项表达式*/
multiplicative_expression
  : unary_expression {$$=$1;}
  | multiplicative_expression TokenOpt_Mul unary_expression {$$=new NifixExpression(ENO_Mul,$1,$3);}
  | multiplicative_expression TokenOpt_Div unary_expression {$$=new NifixExpression(ENO_Div,$1,$3);}
  | multiplicative_expression TokenOpt_Mod unary_expression {$$=new NifixExpression(ENO_Mod,$1,$3);}
  ;

additive_expression
  : multiplicative_expression {$$=$1;}
  | additive_expression TokenOpt_Add multiplicative_expression {$$=new NifixExpression(ENO_Add,$1,$3);}
  | additive_expression TokenOpt_Sub multiplicative_expression {$$=new NifixExpression(ENO_Sub,$1,$3);}
  ;
shift_expression
  : additive_expression {$$=$1;}
  | shift_expression TokenOpt_ShiftLeft additive_expression {$$=new NifixExpression(ENO_ShiftLeft,$1,$3);}
  | shift_expression TokenOpt_ShiftRight additive_expression {$$=new NifixExpression(ENO_ShiftRight,$1,$3);}
  ;

relational_expression
  : shift_expression {$$=$1;}
  | relational_expression TokenOpt_Less shift_expression {$$=new NifixExpression(ENO_Less,$1,$3);}
  | relational_expression TokenOpt_More shift_expression {$$=new NifixExpression(ENO_More,$1,$3);}
  | relational_expression TokenOpt_LessEqual shift_expression {$$=new NifixExpression(ENO_LessEqual,$1,$3);}
  | relational_expression TokenOpt_MoreEqual shift_expression {$$=new NifixExpression(ENO_MoreEqual,$1,$3);}
  ;
equality_expression
  : relational_expression    %prec lower_than_more {$$=$1;}
  | equality_expression TokenOpt_Equal relational_expression %prec lower_than_more {$$=new NifixExpression(ENO_Equal,$1,$3);}
  | equality_expression TokenOpt_NotEqual relational_expression %prec lower_than_more {$$=new NifixExpression(ENO_NotEqual,$1,$3);}
  ;
and_expression
  : equality_expression {$$=$1;}
  | and_expression TokenOpt_BitAnd equality_expression {$$=new NifixExpression(ENO_BitAnd,$1,$3);}
  ;
exclusive_or_expression
  : and_expression {$$=$1;}
  | exclusive_or_expression TokenOpt_BitXor and_expression {$$=new NifixExpression(ENO_BitXor,$1,$3);}
  ;
inclusive_or_expression
  : exclusive_or_expression {$$=$1;}
  | inclusive_or_expression TokenOpt_BitOr exclusive_or_expression {$$=new NifixExpression(ENO_BitOr,$1,$3);}
  ;
conditional_and_expression
  : inclusive_or_expression {$$=$1;}
  | conditional_and_expression TokenOpt_And inclusive_or_expression {$$=new NifixExpression(ENO_And,$1,$3);}
  ;
conditional_or_expression
  : conditional_and_expression {$$=$1;}
  | conditional_or_expression TokenOpt_Or conditional_and_expression {$$=new NifixExpression(ENO_Or,$1,$3);}
  ;
conditional_expression
  : conditional_or_expression {$$=$1;}
  ;
/*等式*/
assignment
  : unary_expression assignment_operator expression {$$=new AssignmentExpression($2,$1,$3);}
  ;
assignment_operator
  : TokenOpt_SetValue {$$=EAO_Assign;}| TokenOpt_SetAdd{$$=EAO_AddAssign;} | TokenOpt_SetSub {$$=EAO_SubAssign;}
  | TokenOpt_SetMul{$$=EAO_MulAssign;} | TokenOpt_SetDiv {$$=EAO_DivAssign;}| TokenOpt_SetMod {$$=EAO_ModAssign;}
  | TokenOpt_SetBitXor {$$=EAO_BitXorAssign;}| TokenOpt_SetBitAnd {$$=EAO_BitAndAssign;}| TokenOpt_SetBitOr{$$=EAO_BitOrAssign;}
  | TokenOpt_SetShiftRight{$$=EAO_ShiftRightAssign;} | TokenOpt_SetShiftLeft {$$=EAO_ShiftLeftAssign;}
  ;


/*常量表达式*/
constant_expression
  : expression { $$=new ConstantExpression($1); if(!$$->checkNode()) yyerror("this is not constant expression");}
  ;
/*布尔表达式*/
boolean_expression
  : expression {$$=new BooleanExpression($1); if(!$$->checkNode()) yyerror("this is not boolean expression");}
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
  : TokenKey_Void {$$=new ClassType();}
  ;
class_type
  : qualified_identifier template_arguments_opt {$$=new ClassType($1); $$->setTemplateArgument($2);}
  ;

/***** 值的定义 *****/
variable_reference
  : expression {$$=$1;}
  ;
/***** 表达式定义 *****/
argument_list
  : argument {$$=new list<Expression*>(); $$->push_back($1);}
  | argument_list TokenOpt_Comma argument {$1->push_back($3);}
  ;
argument
  : expression {$$=$1;}
  ;

/***** 常量 *****/
literal
  : boolean_literal {$$=$1;}
  | Token_Integer {$$=new Literal(IntegerLiteral,$1);}
  | Token_Float {$$=new Literal(FloatLiteral,$1);}
  | Token_Character {$$=new Literal(CharacterLiteral,$1);}
  | Token_String {$$=new Literal(StringLiteral,$1);}
  | TokenKey_Null {$$=new Literal(NullLiteral,nullptr);}
  ;

boolean_literal
  : TokenKey_True { $$=new Literal(TrueLiteral,nullptr);}
  | TokenKey_False { $$=new Literal(FalseLiteral,nullptr);}
  ;

%%

int yyerror(const char *s)
{
  fprintf(stderr,"%d:%s",yylineno,s);
  return 1;
}
