
#ifndef DEPENDENCIES_H_INCLUDED
#define DEPENDENCIES_H_INCLUDED

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>
    #include <stdbool.h>


    #define lenName     12
    #define lenValue    20
    #define lenIDValue    20 // MAXDIGIT=11     MAXCHAR=20

    #define MALLOC(ad, nb, type)\
        ad =(type*)malloc(nb*sizeof(type));\
        if (ad == NULL){\
            printf("Memory allocation is impossible");\
            exit(1);\
        }

    #define CALLOC(ad, nb, type)\
        ad =(type*)calloc(nb,sizeof(type));\
        if (ad == NULL){\
            printf("Memory Callocation is impossible");\
            exit(1);\
        }

    #define REALLOC(ad, NewSize, type)\
        ad = realloc(ad, NewSize * sizeof(type));\
        if (ad == NULL){\
            printf("Memory reallocation is impossible");\
            exit(1);\
        }

    FILE *prog_file, *out_file , *xml_file;
    char **Strings;
    int nbr_tokens, nbr_strs, nbr_IDs;

    typedef enum {
        // keywords tokens
        BEGINPROG , CLOSEPROG , VAR, TYPE ,BEGINFUNC ,CLOSEFUNC,RETURN,PRINCIPAL,
        IF,CLOSEIF,ELIF,ELSE, WHILE, READ, SHOW, AND, OR, NOT, SHOWLN, READLN,DO,CLOSEWHILE,
        FOR , CLOSEFOR , TRUE, FALSE, STOP, SKIP, ATTACH, VOID, _NULL,
        INTEGER , BOOL , FLOAT, STRING, LONG , CHARACTER, DATE , TIME,
        SC,  PT,  PLUS,  MINUS,  MULT,  DIV,  COMMA,  EQ,  ASSIGN,  INF,  INFEQ,  SUP,
        SUPEQ, DIFF, OP, CP, OSB, CSB, CL, OCB, CCB,
        // Other tokens
        ID, NUM, STRVAL, CHARVAL , EndOfFile,
        
    } token_code;
/*typedef enum {
        // keywords tokens
        CONST,  IF,  ELSE, DEF, TYPE, RUN, RETURN, WHILE,
        READ,  WRITE, AND, OR, NOT, WRITELN, READLN,
        INTEGER , BOOL , FLOAT, STRING, LONG , CHAR, DATE, TIME,
        FOR, TRUE, FALSE, STOP, SKIP, ATTACH, VOID, _NULL,
        // Symbols tokens
        SC,  PT,  PLUS,  MINUS,  MULT,  DIV,  COMMA,  EQ,  ASSIGN,  INF,  INFEQ,  SUP,
        SUPEQ, DIFF, OP, CP, OSB, CSB, CL, OCB, CCB,
        // Other tokens
        ID, NUM, STRVAL, CHARVAL, EndOfFile
    } token_code;
 
*/
    typedef struct {
        token_code code;
        char name[lenName];
        char value[lenValue];
        int line;
    } Token;

    Token curr_token, prev_token, *tokens;

    typedef enum {TCONST, TTYPE, TTAB, TVAR, TFCT} ID_type;

    typedef struct {
        char name[lenValue];
        ID_type type;
        char value[lenIDValue];
        int line;
        char block[lenValue];
    } ID_struct;

    ID_struct *IDs;// ,**IDs_blocks;

#endif // DEPENDENCIES_H_INCLUDED
