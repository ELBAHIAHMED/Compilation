

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
    void START();
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
    void CHOICE();
    void VARS();
    void INSTS();
    void INST();
    void AFFEC();
    void EXPR();
    void TERM();
    void FACT();
    void SI();
    void COND();
    void TANTQUE();
    void LIRE();
    void ECRIRE();
    void FUNCTION();
    
    void SWITCH();

#endif // SYNTAX_ANALYZER_H_INCLUDED
