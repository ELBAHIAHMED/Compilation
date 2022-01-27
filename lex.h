
#ifndef LEX_H_INCLUDED
#define LEX_H_INCLUDED


    #define MAXDIGIT    11
    #define MAXCHAR     20

    char curr_char, prev_char;
    int curr_line, curr_column;

    const char* keywords_list[] =
        {"BEGINPROG" , "CLOSEPROG", "VAR", "BEGINFUN","CLOSEFUNC","RETURN","PRINCIPALFUNC",
        "IF","CLOSEIF","ELIF","ELSE",
        "WHILE", "READ", "SHOW", "AND", "OR", "NOT", "SHOWLN", "READLN","DO","CLOSEWHILE",
        "INTEGER" , "BOOL" , "FLOAT", "STRING", "LONG" , "CHARACTER", "DATE", "TIME",
        "FOR","CLOSEFOR", "TRUE", "FALSE", "STOP", "SKIP", "ATTACH", "VOID", "NULL"};

    const char* specialTokens_list[] =
        {"SC", "PT",  "PLUS", "MINUS", "MULT", "DIV", "COMMA", // SC: Semicolon
        "EQ", "ASSIGN", "INF",  "INFEQ", "SUP", "SUPEQ", "DIFF",
        "OP",  "CP", "OSB", "CSB", "CL", "OCB", "CCB"}; // SB : Square Bracket, CB: Curly Bracket , QT" Quotation Mark

    const char* specialTokens_symb[] =
        {";", ".", "+", "-", "*", "/", "," ,
        "==", "<-", "<", "<=", ">", ">=", "!=",
        "(", ")", "[", "]", ":", "{", "}"};

    int keywords_list_size = sizeof(keywords_list) / sizeof(keywords_list[0]);
    int specialTokens_list_size = sizeof(specialTokens_list) / sizeof(specialTokens_list[0]);

    #define NBRKEYWORDS         keywords_list_size
    #define NBRSPECIALTOKENS    specialTokens_list_size

    void lexicalAnalysis();
    void WriteCurrTknToFile();
    char next_char();
    void getToken();
    void LexError(char*);
    void ignoreWhiteSpacesComments();
    bool isNumber();
    bool isWord();
    bool isChar();
    bool isString();
    bool isSpecial();

#endif // TOKENIZER_H_INCLUDED
