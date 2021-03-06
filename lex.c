#include "dependencies.h"
#include "lex.h"

// Lexical Analysis

void lexicalAnalysis(){
    curr_line = 1;
    curr_column = 1;
    nbr_tokens = 1;
    nbr_strs = 1;
    MALLOC(tokens, 1, Token);
    MALLOC(Strings, 1, char*);

    next_char();
    do{
        getToken();
    }while (curr_token.code != EndOfFile);
}

void WriteCurrTknToFile(){
    fprintf(out_file,"CODE: %d     %s_TOKEN     VALUE: %s      n° line: %d \n",
            curr_token.code, curr_token.name, curr_token.value, curr_token.line);
}

char next_char(){
    curr_column++;
    prev_char = curr_char;
    curr_char = fgetc(prog_file);
    if( curr_char == '\n'){
        curr_column = 1;
        curr_line++;
    }
    return curr_char;
}

void LexError(char *message){
    printf("Lexical Error: Line %d, Column %d:\n%s\n",
           curr_line, curr_column, message);
}

void getToken(){
    // Clear Token
    memset(curr_token.name, '\0', lenName);
    memset(curr_token.value, '\0', lenValue);

    // Ignore white-spaces and Newlines and Comments
    ignoreWhiteSpacesComments();

    if(curr_char == EOF){
        curr_token.code = EndOfFile;
        strcpy(curr_token.name, "EOF");
        strcpy(curr_token.value, "EndOfFile");
        curr_token.line = curr_line;
        WriteCurrTknToFile();

        tokens[nbr_tokens-1] = curr_token;
        REALLOC(tokens, ++nbr_tokens, Token);
    }

    else if( isNumber() )
        WriteCurrTknToFile();
    else if( isWord() )
        WriteCurrTknToFile();
    else if( isChar() )
        WriteCurrTknToFile();
    else if( isString() )
        WriteCurrTknToFile();
    else if( isSpecial() )
        WriteCurrTknToFile();
    else{
        LexError("Invalid Token");
        next_char();
    }
}

void ignoreWhiteSpacesComments(){
    // Ignore blank space, tabulation, newline, catch single & multi-line comments
    while( curr_char == ' ' || curr_char == '\t' || curr_char == '\n' || curr_char == '#'){
        if( curr_char == '#'){
            // Ignore multi-line comments
            if((curr_char = next_char()) == '/'){
                do{
                    next_char();
                }while(curr_char != '/' && curr_char != EOF);

                if (curr_char == EOF)
                    LexError("Error in a multi-line comment, not closed");
                else if (curr_char == '#' && prev_char != '/')
                    LexError("Error in a multi-line comment, closing * is missing");
            }
            // Ignore single line comments
            else {
                do{
                   next_char();
                }while( (curr_char != '#') && (curr_char != '\n') && (curr_char != EOF) );
                if ( (curr_char == EOF) || (curr_char == '\n') )
                    LexError("Error in a single line comment, not closed");
            }
        }
        next_char();
    }
}

bool isNumber(){
    if(!isdigit(curr_char))
        return false;

    char num[MAXDIGIT+1];
    int i = 0;
    num[0] = curr_char;

    while( (++i <= MAXDIGIT) && isdigit(num[i] = curr_char = next_char()) );

    if(i > MAXDIGIT){
        LexError("Number exceeded MAXDIGIT limit ");
        next_char();
    }

    num[i] = '\0';

    curr_token.code = NUM;
    strcpy(curr_token.name, "NUM");
    strcpy(curr_token.value, num);
    curr_token.line = curr_line;

    tokens[nbr_tokens-1] = curr_token;
    REALLOC(tokens, ++nbr_tokens, Token);
    return true;
}

bool isWord(){
    if( !isalpha(curr_char) )
        return false;

    char word[MAXCHAR];
    memset(word,'\0', sizeof(word));
    int i = 0, j = 0, cmp = 0;
    word[0] = toupper(curr_char);

    while( isalnum( word[++i] = curr_char = toupper(next_char()) ) );

    if(i > MAXCHAR){
        LexError("Word exceeded MAXCHAR limit");
        return true;
    }

    word[i] = '\0';

    // Verify this word match a keyword in the list of keywords
    while( (cmp = strcmp(word , keywords_list[j++])) != 0 && j < NBRKEYWORDS );

    if(cmp == 0){
        // is keyword
        int a=strcmp(word,"INTEGER");
        int b=strcmp(word,"BOOL" );
        int c=strcmp(word,"FLOAT");
        int d=strcmp(word,"STRING");
        int e=strcmp(word,"LONG");
        int f=strcmp(word,"CHARACTER");
        int g=strcmp(word,"DATE");
        int h=strcmp(word,"TIME");
        int p=strcmp(word,"VOID");
        int k=strcmp(word,"FOR");
        int x=strcmp(word,"CLOSEFOR");
        if ( a==0|| b==0|| c == 0|| d==0 || e==0 || f==0 || g==0 || h==0 || p==0)
        {
        curr_token.code = TYPE;
        strcpy(curr_token.name, "TYPE");
        strcpy(curr_token.value, word);
        }
        else if (k==0)
        {
            curr_token.code = FOR;
        strcpy(curr_token.name, "FOR");
        strcpy(curr_token.value, word);
        }
        else if (x==0)
        {
            curr_token.code = CLOSEFOR;
        strcpy(curr_token.name, "CLOSEFOR");
        strcpy(curr_token.value, word);
        }
        
        
        else{
        curr_token.code = j-1;
        strcpy(curr_token.name, keywords_list[j-1]);
        strcpy(curr_token.value, word);}
    }


    /*else if (cmt==0) { // If not keyword, so it's an TYPE
        curr_token.code = TYPE;
        strcpy(curr_token.name, "TYPE");
        strcpy(curr_token.value, word);
    }*/

    else{ // If not keyword, so it's an ID
        curr_token.code = ID;
        strcpy(curr_token.name, "ID");
        strcpy(curr_token.value, word);
    }
    if (curr_char=='\n')
        curr_token.line = curr_line-1;
    else
        curr_token.line = curr_line;
    tokens[nbr_tokens-1] = curr_token;
    REALLOC(tokens, ++nbr_tokens, Token);
    return true;
}

bool isChar(){
    if( !(curr_char == '\'') ){
        return false;
    }
    char ch[2];
    memset(ch,'\0', sizeof(ch));
    ch[0] = next_char();

    curr_token.code = CHARACTER;
    strcpy(curr_token.name, "CHARACTER");
    strcpy(curr_token.value, ch);
    curr_token.line = curr_line;

    tokens[nbr_tokens-1] = curr_token;
    REALLOC(tokens, ++nbr_tokens, Token);

    if ( (curr_char=next_char()) != '\'' )
        LexError("CHAR expression not closed");
    else
        next_char();
    return true;
}

bool isString(){
    if(!(curr_char == '"') ){
        return false;
    }
    char *Str;
    MALLOC(Str, 2, char);
    Str[0] = next_char();
    int nbr_caracts = 1;
    while( (curr_char = next_char()) != '"' && curr_char != '\n' && curr_char != EOF){
        Str[nbr_caracts] = curr_char;
        REALLOC(Str, ++nbr_caracts, char);
    }
    if (curr_char == '\n' && curr_char == EOF){
        LexError("String Error, the whole line is ignored");
        return false;
    }
    Str[nbr_caracts] = '\0';

    curr_token.code = STRVAL;
    strcpy(curr_token.name, "STRVAL");
    sprintf(curr_token.value, "%d", nbr_strs-1);
    curr_token.line = curr_line;

    tokens[nbr_tokens-1] = curr_token;
    REALLOC(tokens, ++nbr_tokens, Token);

    REALLOC(Strings, nbr_strs, char*);
    Strings[nbr_strs-1] = Str;
    nbr_strs++;

    next_char();
    return true;
}

bool isSpecial(){
    if( !ispunct(curr_char) )
        return false;
    int i = 0, cmp = 0;
    char op[3];
    memset(op,'\0', sizeof(op));

    op[0] = curr_char;
    if( ( (op[1] = curr_char = next_char()) != '=') && ( (op[1] != '-') ))
        op[1] =  '\0';

    else
        next_char();

    while( (cmp = strcmp(op, specialTokens_symb[i++]) != 0) && i < NBRSPECIALTOKENS);

    if(cmp != 0)
        return false;
    curr_token.code = keywords_list_size + i - 1;
    strcpy(curr_token.name, specialTokens_list[i-1]);
    strcpy(curr_token.value, op);
    if (curr_char=='\n')
        curr_token.line = curr_line-1;
    else
        curr_token.line = curr_line;
    tokens[nbr_tokens-1] = curr_token;
    REALLOC(tokens, ++nbr_tokens, Token);
    return true;
}

