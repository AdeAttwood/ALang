
grammar ALang;

root
 : innerStatementList EOF
 ;

functionDeclaration
 : DocumentationComment* Function_ ID OpenRoundBracket parameters? CloseRoundBracket ':' type blockStatement
 ;

parameters
 : parameter ( ',' parameter)*
 ;

parameter: type ID;

functionCall
 : ID OpenRoundBracket arguments? CloseRoundBracket SemiColon
 ;

functionCallExpression
 : ID OpenRoundBracket arguments? CloseRoundBracket
 ;

arguments
 : expression ( ',' expression )*
 ;

blockStatement
 : OpenCurlyBracket innerStatementList CloseCurlyBracket
 ;

innerStatementList
 : innerStatement*
 ;

innerStatement
 : functionDeclaration
 | functionCall
 | ifElseIfElseStatement
 | forStatement
 | returnStatement
 | variableDeclaration
 | variableAssignment
 ;

variableDeclaration:         type ID Equals expression SemiColon;
variableDeclarationFragment: type ID Equals expression;

variableAssignment:        ID assignmentOperator expression SemiColon;
variableAssignmentFragment:ID assignmentOperator expression;

returnStatement
 : Return expression SemiColon
 ;

ifElseIfElseStatement
 : ifStatement elseIfStatement* elseStatement?
 ;

ifStatement
 : If OpenRoundBracket expression CloseRoundBracket blockStatement
 ;

elseIfStatement
 : ElseIf OpenRoundBracket expression CloseRoundBracket blockStatement
 ;

elseStatement
 : Else blockStatement
 ;

forStatement
 : For OpenRoundBracket (variableDeclarationFragment | variableAssignmentFragment) SemiColon test=expression SemiColon increment=expression CloseRoundBracket blockStatement
 ;


expression
 : '(' expression ')'
 | expression operation='*' expression
 | expression operation='/' expression
 | expression operation='+' expression
 | expression operation='-' expression
 | expression test=('==' | '!=' | '<' | '<=' | '>' | '>=') expression
 | expression test=('&&' | '||') expression
 | functionCallExpression
 | variableAssignmentFragment
 | BooleanConstant
 | DoubleQuoteString
 | NUMBER
 | ID
 ;

type
 : Int
 | Boolean
 | String
 | Void
 | ID
 ;

assignmentOperator
 : Equals
 ;

DocumentationComment:  '///' ~[\r\n]*;
Comment:  '//' ~[\r\n]* -> skip;

Return: 'return';
Function_: 'function';
For: 'for';
If: 'if';
Else: 'else';
ElseIf: 'else if';
Int: 'int';
Void: 'void';
String: 'string';
Boolean: 'bool';

BooleanConstant:    'true' | 'false';
ID:                 [a-z][a-z0-9_]*;
NUMBER:             ( [0-9]* '.' )? [0-9]+;
OpenCurlyBracket:   '{';
CloseCurlyBracket:  '}';
OpenRoundBracket:   '(';
CloseRoundBracket:  ')';
OpenSquareBracket:  '[';
CloseSquareBracket: ']';
Colon:              ':';
SemiColon:          ';';
Equals:             '=';
DoubleQuote:        '"';
DoubleQuoteString:  '"' (~('"' | '\\') | '\\' . )* '"';
SPACE: [ \t\r\n]+ -> skip;
