/**
GRAMMAR for SAMZO Language

GRAMMAR     =	PROGRAM  ;
PROGRAM     =	[ { "attach" , STRVAL } ] , [{ DCLR , ";" }] , [{CONST }] , [{ FUNCT }] ,
                    RUN , "{" , { INST , ";" } ,  [ RETURN ,  �;� ] , "}" ;
RETURN      = 	�return� ,  [ EXPR | { EXPR , "," } ]  ;
RUN         =	"void" | [ TYPE | { TYPE , "," } ] , �run� , �(� ,  [ DCLR | { DCLR , ";" } ]  , �)�  ;
DCLR		=	TYPE ,   ID  , [ { �,� , ID }  ]  , [INIT] ;
INIT		=	�=� , ( NUM | STRVAL | CHARVAL | BOOLVAL | "NULL" );
ID          =	LETTER ,  [ { CHARACTER } ]  ;
CONST		=	�const� ,  ID  ,  �=� ,   ( NUM | STRVAL | CHARVAL | BOOLVAL ) , �;� ;
TYPES		=	�def� , �type� ,  ID  , �{� ,  { TYPE ,  ID , �;� } , �}�   ;
FUNCT		=	"def" , [ TYPE | { TYPE , "," } ]  ,  ID  ,  �(� ,  [ DCLR | { DCLR , ";" } ] , �)� ,
                     "{" , [{ CONST }] , [ { DCLR , ";" } ] , [ {TYPES} ] ,  { INST , ";" } , "}" ;
TYPE        =	�integer� | �bool� | �float� | �string� | �long� | �char� | �date� | �time�  ;
NUM         =	{ DIGIT }  ;
STRVAL      =	��� , { ALL_CHARACTERS } , ���  ;
CHARVAL     =	��� , ALL_CHARACTERS , ���  ;
BOOLVAL     =	�true� | �false�  ;
TABLE		=	TYPE ,  ID  ,  �[�  , [EXPR] ,  �]� ,  �=� , �[� , { ( NUM | STRVAL | CHARVAL ) , [�,�] } ,  �]� , �;�  ;
VAR         =	ID  , [ �[� , EXPR , �]� ]  ;
(* �[� , EXPR , �]� pour inclure les variables qui designent des cases dans un tableau de dim 1 *)
EXPR		=	(  �(� , TERM ,  [ { ADDOP , TERM } ]  , �)�  )  |  BOOLVAL  |  STRVAL | CHARVAL ;
TERM		=	FACTOR  ,  [ { MULOP , FACTOR } ]  ;
FACTOR		=	VAR   |   NUM   |  ( �(� , EXPR , �)� )  |  EXECUTE  ;
ADDOP		=	�+�   |  �-�  ;
MULOP		=	�*�   |   �/�  ;
WRITE		=	(�write� | �writeln�) ,  �(� , ( EXPR | { EXPR , "," } ) , �)� ;
READ		=	(�read� | �readln�) , �(� , ( VAR | { VAR , "," } ) , �)�  ;
INSTS	    =	( INST , �;� ) | ( "{" , { INST , �;� } , "}" ) ;
INST		=	ASSIGN | EXECUTE |  IF | WHILE |  FOR | WRITE | WRITELN | READ | READLN | RETURN ;
ASSIGN		=	VAR   ,  �=�   ,  (EXPR | NULL) ;
EXECUTE     =	ID  ,   �(� ,  ( EXPR | {EXPR, ","} ) , �)� ;
COND        =   [{ �(� }] , [EXPR] , [CONDOP] , (EXPR | "null") , [ �)� ] , [ { (�and� | �or�) , COND , [{ "}" }] } ] ;
CONDOP      =	�!=� | �<� |� >� | �<=� | �>=� | �not� ;
IF          =	�if� , "(" , COND , ")" , {IF_INST} , [ { �else if� , "(" , COND , ")" , {IF_INST} ] , [ �else� , {IF_INST} ] ;
IF_INST		=   INSTS | ( �skip� , �;� )  | ( �stop� , �;� ) ;
WHILE		=	�while� , �(� , COND , �)� , INSTS ;
FOR         =	�for� , �(� ID , �=� , EXPR , �;� , COND , �;� , INST , �)� , INSTS ;
WHITE_SPACE     =	? white_space characters ? ;
ALL_CHARACTERS  =	? all visible characters ? ;
CHARACTER   =	LETTER | digit | symbol | "_" ;
SYMBOL      =	"[" | "]" | "{" | "}" | "(" | ")" | "<" | ">" | "'" | '"' | "=" | "|" | "." | "," | ";" | "%" ;
DIGIT       =	"0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"  ;
LETTER      =	"A" | "B" | "C" | "D" | "E" | "F" | "G" | "H" | "I" | "J" | "K" | "L" | "M" | "N" | "O" |
                "P" | "Q" | "R" | "S" | "T" | "U " | "V" | "W" | "X" | "Y" | "Z" | "a" | "b" | "c" | "d" |
                "e" | "f" | "g" | "h" | "i" | "j" | "k" | "l" | "m" | "n" | "o" | "p" | "q" | "r" | "s" |
                "t" | "u" | "v" | "w" | "x" | "y" | "z"  ;

*/

#ifndef SYNTAX_H_INCLUDED
#define SYNTAC_H_INCLUDED

    int currTokenNbr;
    char curr_block[lenValue];
    void WriteCurrTokenToFile();
    Token next_token();
    Token previous_token();
    bool verifyToken(token_code);
    void SyntaxError(token_code, char*);
    void Program();
    void VARS() ;
    bool Consts();
    void NewTypes(); // definition of new types
    bool isType(); // primitive types
    bool isNewType(); //new defined types
    bool Dclr();
    void Init();
    void Table();
    void Functs();
    void Run();
    void Insts();
    bool Inst();
    void Assign_Execute();
    void If();
    void While();
    void For();
    void Write();
    void Read();
    void Return();
    void Cond();
    bool CondOp();
    bool Expr();
    bool AddOp();
    bool Term();
    bool MulOp();
    bool Factor();
    bool isBool();

#endif // SYNTAX_ANALYZER_H_INCLUDED
