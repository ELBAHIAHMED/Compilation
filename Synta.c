#include "dependencies.h"
#include "Synta.h"

// Syntax Analysis: Parsing
void Erreur(token_code COD_ERR,int i){int ligne=5;
    switch(COD_ERR){
        
  case 0: printf("%d-ligne %d ERREUR-->STARTP_ERREUR\n",i,curr_token.line);break;
  case 1: printf("%d-ligne %d ERREUR-->ID_ERREUR\n",i,curr_token.line);break;
  case 2: printf("%d-ligne %d ERREUR-->VAR_ERREUR\n",i,curr_token.line);break;
  case 3: printf("%d-ligne %d ERREUR-->START_ERREUR\n",i,curr_token.line);break;
  case 4: printf("%d-ligne %d ERREUR-->END_ERREUR\n",i,curr_token.line);break;
  case 5: printf("%d-ligne %d ERREUR-->IF_ERREUR\n",i,curr_token.line);break;
  case 6: printf("%d-ligne %d ERREUR-->THEN_ERREUR\n",i,ligne);break;
  case 7: printf("%d-ligne %d ERREUR-->WHILE_ERREUR\n",i,ligne);break;
  case 8: printf("%d-ligne %d ERREUR-->FUNCTION_ERREUR\n",i,ligne);break;
  case 9: printf("%d-ligne %d ERREUR-->PUT_ERREUR\n",i,ligne);break;
  case 10: printf("%d-ligne %d ERREUR-->PRINT_ERREUR\n",i,ligne);break;
  case 11: printf("%d-ligne %d ERREUR-->PV_ERREUR\n",i,ligne);break;
  case 12: printf("%d-ligne %d ERREUR-->PLUS_ERREUR\n",i,ligne);break;
  case 13: printf("%d-ligne %d ERREUR-->MOINS_ERREUR\n",i,ligne);break;
  case 14: printf("%d-ligne %d ERREUR-->MULT_ERREUR\n",i,ligne);break;
  case 15: printf("%d-ligne %d ERREUR-->DIV_ERREUR\n",i,ligne);break;
  case 16: printf("%d-ligne %d ERREUR-->VIR_ERREUR\n",i,ligne);break;
  case 17: printf("%d-ligne %d ERREUR-->AFF_ERREUR\n",i,ligne);break;
  case 18: printf("%d-ligne %d ERREUR-->INF_ERREUR\n",i,ligne);break;
  case 19: printf("%d-ligne %d ERREUR-->INFEG_ERREUR\n",i,ligne);break;
  case 20: printf("%d-ligne %d ERREUR-->SUP_ERREUR\n",i,ligne);break;
  case 21: printf("%d-ligne %d ERREUR-->SUPEG_ERREUR\n",i,ligne);break;
  case 22: printf("%d-ligne %d ERREUR-->DIFF_ERREUR\n",i,ligne);break;
  case 23: printf("%d-ligne %d ERREUR-->PO_ERREUR\n",i,ligne);break;
  case 24: printf("%d-ligne %d ERREUR-->PF_ERREUR\n",i,ligne);break;
  case 25: printf("%d-ligne %d ERREUR-->ENDPROG_ERREUR\n",i,ligne);break;
  case 26: printf("%d-ligne %d ERREUR-->NUM_ERREUR\n",i,ligne);break;
  case 27: printf("%d-ligne %d ERREUR-->EG_ERREUR\n",i,ligne);break;
  case 28: printf("%d-ligne %d ERREUR-->EOF_ERREUR\n",i,ligne);break;
  case 29: printf("%d-ligne %d ERREUR-->SWITCH_ERREUR\n",i,ligne);break;
  case 30: printf("%d-ligne %d ERREUR-->CASE_ERREUR\n",i,ligne);break;
  case 31: printf("%d-ligne %d ERREUR-->BREAK_ERREUR\n",i,ligne);break;
  case 32: printf("%d-ligne %d ERREUR-->DEFFAULT_ERREUR\n",i,ligne);break;
  case 33: printf("%d-ligne %d ERREUR-->FOR_ERREUR\n",i,ligne);break;
  case 34: printf("%d-ligne %d ERREUR-->MAIN_ERREUR\n",i,ligne);break;
  case 35: printf("%d-ligne %d ERREUR-->RETURN_ERREUR\n",i,ligne);break;
  case 36: printf("%d-ligne %d ERREUR-->ELSE_ERREUR\n",i,ligne);break;
  case 37: printf("%d-ligne %d ERREUR-->ELSIF_ERREUR\n",i,ligne);break;
  case 38: printf("%d-ligne %d ERREUR-->AND_ERREUR\n",i,ligne);break;
  case 39: printf("%d-ligne %d ERREUR-->TYPE_ERREUR\n",i,ligne);break;
  case 40: printf("%d-ligne %d ERREUR-->DOUBLEPOINT_ERREUR\n",i,ligne);break;
  case 41: printf("%d-ligne %d ERREUR-->CHAINE_ERREUR\n",i,ligne);break;
  case 42: printf("%d-ligne %d ERREUR-->CONDITION_ERREUR\n",i,ligne);break;
  case 43 : printf("%d-ligne %d ERREUR-->OPERATION_ERREUR\n",i,ligne);break;
    default : printf("probleme %d \n , %s \n", curr_token.code, curr_token.value);
  }
  }
 bool verifyTokenbeging(token_code code_to_test){
    if ( (curr_token = next_token()).code != code_to_test ){
       previous_token();
       Erreur(code_to_test,curr_token.line);
        return false;
    }
    next_token();
    //WriteCurrTokenToFile();
    return true;

}
bool verifyToken(token_code code_to_test){
    if ( curr_token.code != code_to_test ){
       previous_token();
       Erreur(code_to_test,curr_token.line);
        return false;
    }
    next_token();
    //WriteCurrTokenToFile();
    return true;

}

Token previous_token(){
    return curr_token = tokens[--currTokenNbr];
}

Token next_token(){
    prev_token = curr_token;
    return curr_token = tokens[currTokenNbr++];
}

// Parse tree
void WriteCurrTokenToFile(){
    fprintf(xml_file,"{ %s, %s }\n", curr_token.name, curr_token.value);
}

void SyntaxError(token_code code, char *message){
    printf("Syntax Error: Code %d\nLine %d: %s\n",
           code, curr_token.line, message);
}

// PROGRAM  =   [ { "attach" , STRVAL } ] , [{ DCLR , ";" }] , [{CONST }] , [{ FUNCT }] ,
//                    RUN , "{" , { INST , ";" } ,  [ RETURN ,  �;� ] , "}" ;

void Program(){
    currTokenNbr = 0;
    MALLOC(IDs, 1, ID_struct);
    nbr_IDs = 1;
    //fprintf(xml_file,"<PROGRAM>\n");
      verifyTokenbeging(BEGINPROG);
        VARS();
      //START();
      //verifyToken(CLOSEPROG);
  }



/*void Program(){
    currTokenNbr = 0;
    MALLOC(IDs, 1, ID_struct);
    nbr_IDs = 1;
    fprintf(xml_file,"<PROGRAM>\n");
    if (verifyToken(ATTACH)){
        if(!verifyToken(STRVAL))
            SyntaxError(ID, "The name of the file to import is missing");
    }
    strcpy(curr_block, "PROGRAM");
    bool r = false;
    while( Consts() || (r = Dclr()) || verifyToken(DEF) ){
        if (curr_token.code == DEF){
            if(verifyToken(TYPE)){
                fprintf(xml_file,"<NEWTYPE>\n");
                NewTypes();
            }
            else{
                fprintf(xml_file,"<FUNCT>\n");
                Functs();
            }
        }
        else if (r){
            if(!verifyToken(SC))
                SyntaxError(SC, "SemiColon is missing");
            r = false;
        }
    }
    Run();
    Insts();
    fprintf(xml_file,"</PROGRAM>\n");
}*/

/* verification des VAR_TOKEN */
  void VARS() {
      
     
    switch (curr_token.code) {
      case VAR :     {  
                        verifyToken(VAR);
                       
                        verifyToken(OP);
                       
                       if(curr_token.code == CP)
                       verifyToken(CP);
                       else if(curr_token.code == TYPE){
                         while(curr_token.code == TYPE){
                               verifyToken(TYPE);
                                verifyToken(ID);
                                if(curr_token.code ==ASSIGN){
                                          next_token();
                                          verifyToken(NUM);
                                          while (curr_token.code== COMMA) {
                                                          next_token();
                                                          verifyToken(ID);
                                                          if(curr_token.code ==ASSIGN){
                                                              verifyToken(ASSIGN);
                                                              verifyToken(NUM);

                                                            }
                                                        }
                                                    }
                                  else {
                                    while (curr_token.code== COMMA) {
                                                         next_token();
                                                        
                                                          verifyToken(ID);
                                                          if(curr_token.code ==ASSIGN){
                                                            verifyToken(ASSIGN);
                                                            verifyToken(NUM);
                                                          }
                                                        }
                                                      }
                           verifyToken(SC);
                           
                           
                       }verifyToken(CP);
                       verifyToken(SC);break;
                       }
      case BEGINFUNC : break;
      //default          : Erreur(BEGINFUN,curr_token.line);break;
    }
    next_token();
  }

  }

  /*void START(){
    while (curr_token.code==BEGINFUNC){
     switch (curr_token.code) {
       case BEGINFUNC: verifyToken(BEGINFUNC);
                         verifyToken(TYPE);
                         switch(curr_token.code){
                           case FUNCTION_TOKEN : Test_Symbole(FUNCTION_TOKEN,FUNCTION_ERR);
                                                 Test_Symbole(ID_TOKEN,ID_ERR);
                                                 Test_Symbole(PO_TOKEN,PO_ERR);
                                                 if(temp->cls==TYPE_TOKEN){
                                                            Test_Symbole(TYPE_TOKEN,TYPE_ERR);
                                                            Test_Symbole(ID_TOKEN,ID_ERR);
                                                            while(temp->cls==VIR_TOKEN){
                                                                    Sym_Suiv();
                                                                    Test_Symbole(TYPE_TOKEN,TYPE_ERR);
                                                                    Test_Symbole(ID_TOKEN,ID_ERR);
                                                                  }
                                                            }
                                                 Test_Symbole(PF_TOKEN,PF_ERR);
                                                 while(temp->cls==SAUT_TOKEN)
                                                 {ligne+=1;
                                                 Sym_Suiv();}
                                                 INSTS();
                                                 Test_Symbole(END_TOKEN,END_ERR);
                                                 Test_Symbole(FUNCTION_TOKEN,FUNCTION_ERR);
                                                 Test_Symbole(ID_TOKEN,ID_ERR);break;
                           case MAIN_TOKEN     : Test_Symbole(MAIN_TOKEN,MAIN_ERR);
                                                 Test_Symbole(PO_TOKEN,PO_ERR);
                                                 Test_Symbole(PF_TOKEN,PF_ERR);
                                                 while(temp->cls==SAUT_TOKEN)
                                                 {ligne+=1;
                                                 Sym_Suiv();}
                                                 INSTS();
                                                 Test_Symbole(END_TOKEN,END_ERR);
                                                 Test_Symbole(MAIN_TOKEN,MAIN_ERR);break;
                           default             : Erreur(FUNCTION_ERR,i);break;
                         }break;
       default : Erreur(START_ERR,i);break;
     }
     while(temp->cls==SAUT_TOKEN)
     {ligne+=1;
     Sym_Suiv();}
  }
}
/*
// CONST	=	�const� ,  ID  ,  �=� ,  ( NUM | STRVAL | CHARVAL | BOOLVAL ) , �;� ;
bool Consts(){
    if (!verifyToken(CONST))
        return false;
    fprintf(xml_file,"<CONST>\n");
    while(verifyToken(ID)){
        strcpy(IDs[nbr_IDs-1].name, curr_token.value);
        IDs[nbr_IDs-1].type = TCONST;
        IDs[nbr_IDs-1].line = curr_token.line;
        strcpy(IDs[nbr_IDs-1].block, curr_block);

        if(!verifyToken(ASSIGN))
            SyntaxError(EQ, "Assign sign is missing");
        if(verifyToken(NUM) || isBool() || verifyToken(CHARVAL)){
            strcpy(IDs[nbr_IDs-1].value, curr_token.value);
        }
        else if (verifyToken(STRVAL)){
            strcpy(IDs[nbr_IDs-1].value, curr_token.value);
        }
        else
            SyntaxError(SC, "Constant's value is missing");
        REALLOC(IDs, ++nbr_IDs, ID_struct);
        if(!verifyToken(SC))
            SyntaxError(SC, "SemiColon is missing");
    }
    fprintf(xml_file,"</CONST>\n");
    return true;
}

// TYPES	=	�def� , �type� ,  ID  , �{� ,  { TYPE ,  ID , �;� } , �}�   ;
void NewTypes(){
    //fprintf(xml_file,"<NEWTYPE>\n");
    if(verifyToken(ID)){
        strcpy(IDs[nbr_IDs-1].name, curr_token.value);
        IDs[nbr_IDs-1].type = TTYPE;
        IDs[nbr_IDs-1].line = curr_token.line;
        strcpy(IDs[nbr_IDs-1].block, curr_block);
        REALLOC(IDs, ++nbr_IDs, ID_struct);
    }
    else
        SyntaxError(ID, "Type's ID is missing");
    if(!verifyToken(OCB))
        SyntaxError(OCB, "Opening Bracket is missing");
    while( (isType()||isNewType()) && verifyToken(ID) ){
        if(!verifyToken(SC))
            SyntaxError(SC, "SemiColon is missing");
    }
    if(!verifyToken(CCB))
        SyntaxError(CCB, "Closing Bracket is missing");
    fprintf(xml_file,"</NEWTYPE>\n");
}

// TYPE    =    �integer� | �bool� | �float� | �string� | �long� | �char� | �date� | �time�  ;
bool isType(){
    switch((curr_token = next_token()).code){
        case INTEGER : case BOOL : case STRING :
        case LONG : case CHAR : case FLOAT :
        case DATE : case TIME : break;
        default: previous_token(); return false;
    }
    WriteCurrTokenToFile();
    return true;
}

bool isNewType(){
    if(!verifyToken(ID))
        return false;
    for(int i = 0; i<=nbr_IDs-1;i++){
        if( (IDs[i].type==TTYPE) && (strcmp(IDs[i].name, curr_token.value)==0) )
            return true;
    }
    return false;
}

// DCLR		=	TYPE ,   ID  , [ { �,� , ID }  ]  , [INIT] ;
bool Dclr(){
    if(!isType() && !isNewType())
        return false;
    fprintf(xml_file,"<DCLR>\n");
    do{
        if (verifyToken(ID)){
            strcpy(IDs[nbr_IDs-1].name, curr_token.value);
            IDs[nbr_IDs-1].type = TVAR;
            IDs[nbr_IDs-1].line = curr_token.line;
            strcpy(IDs[nbr_IDs-1].block, curr_block);
            REALLOC(IDs, ++nbr_IDs, ID_struct);
        }
        else{
            fprintf(xml_file,"</DCLR>\n");
            return true;
        }
    } while(verifyToken(COMMA));
    if (verifyToken(COMMA))
        SyntaxError(COMMA, "COMMA not needed");
    if (verifyToken(ASSIGN))
        Init();
    fprintf(xml_file,"</DCLR>\n");
    return true;
}

// INIT		=	�=� , ( NUM | STRVAL | CHARVAL | BOOLVAL );
// initializing more than one var at the same time with the same value is allowed
void Init(){
    if(verifyToken(NUM) || isBool() || verifyToken(CHARVAL) || verifyToken(STRVAL)){
        strcpy(IDs[nbr_IDs-2].value, curr_token.value);
    }
    else
        SyntaxError(curr_token.code, "Initialization value is missing");
}

// TABLE    =	TYPE ,  ID  ,  �[�  , [EXPR] ,  �]� ,  �=� ,
//              �[� , { ( NUM | STRVAL | CHARVAL ) , [�,�] } ,  �]� , �;�  ;
void Table(){
    if(!isType()&&!isNewType())
        return;
    fprintf(xml_file,"<TABLE>\n");
    if (verifyToken(ID)){
        strcpy(IDs[nbr_IDs-1].name, curr_token.value);
        IDs[nbr_IDs-1].type = TTAB;
        IDs[nbr_IDs-1].line = curr_token.line;
        strcpy(IDs[nbr_IDs-1].block, curr_block);
        REALLOC(IDs, ++nbr_IDs, ID_struct);
    }
    verifyToken(OSB);
    verifyToken(CSB);
    if (verifyToken(ASSIGN))
        Init();
    fprintf(xml_file,"</TABLE>\n");
}

// FUNCT	=	"def" , [ TYPE | { TYPE , "," } ]  ,  ID  ,  �(� ,  [ DCLR | { DCLR , ";" } ] , �)� ,
//                     "{" , [{ CONST }] , [ { DCLR , ";" } ] , [ {TYPES} ] ,  { INST , ";" } , "}" ;
void Functs(){
    do{
        if(!isType())
            if(!isNewType())
                break;
    }while(verifyToken(COMMA));
    if(!verifyToken(ID))
        SyntaxError(ID, "ID is missing");
    else{
        strcpy(IDs[nbr_IDs-1].name, curr_token.value);
        strcpy(curr_block, curr_token.value);
        IDs[nbr_IDs-1].type = TFCT;
        strcpy(IDs[nbr_IDs-1].block, curr_block);
        REALLOC(IDs, ++nbr_IDs, ID_struct);
    }
    if(!verifyToken(OP))
        SyntaxError(OP, "Opening parenthesis is missing");
    do{;}while( Dclr() && verifyToken(SC) );
    if(!verifyToken(CP))
        SyntaxError(CP, "Closing parenthesis is missing");

    if(!verifyToken(OCB))
        SyntaxError(OCB, "Opening Bracket is missing");
    bool r = false;
    while( Consts() || (r = Dclr()) || verifyToken(DEF) ){
        if (curr_token.code == DEF){
            if(verifyToken(TYPE)){
                fprintf(xml_file,"<NEWTYPE>\n");
                NewTypes();
            }
            else
                SyntaxError(curr_token.code, "Functions defintion is not allowed inside another function");
        }
        else if (r){
            if(!verifyToken(SC))
                SyntaxError(SC, "SemiColon is missing");
            r = false;
        }
    }
    while(Inst()){
        if(!verifyToken(SC))
            SyntaxError(SC, "SemiColon is missing");
    }
    if(!verifyToken(CCB))
        SyntaxError(CCB, "Closing Bracket is missing");
    fprintf(xml_file,"</FUNCT>\n");
}

// RUN    =	  "void" | [ TYPE | { TYPE , "," } ] , �run� , �(� ,  [ DCLR | { DCLR , ";" } ]  , �)�  ;
void Run(){
    fprintf(xml_file,"<RUN>\n");
    if(!verifyToken(VOID) && !isType() && !isNewType())
        SyntaxError(curr_token.code, "RUN's type is missing");
    while (isType() || isNewType()){
        if(verifyToken(COMMA))
            SyntaxError(COMMA, "COMMA is missing");
    }
    verifyToken(RUN);
    if(!verifyToken(OP))
        SyntaxError(OP, "Opening parenthesis is missing");
    do{
        Dclr();
    }while(verifyToken(SC));
    if(!verifyToken(CP))
        SyntaxError(CP, "Closing parenthesis is missing");
    fprintf(xml_file,"</RUN>\n");
}

// INSTS	=	( INST , �;� ) | ( "{" , { INST , �;� } , "}" ) ;
void Insts(){
    if (verifyToken(OCB)){
        fprintf(xml_file,"<INSTS>\n");
        while (Inst()){
            if( (curr_token.code != CCB) && !verifyToken(SC))
                SyntaxError(SC, "SemiColon is missing");
        }
        fprintf(xml_file,"</INSTS>\n");
        if (!verifyToken(CCB))
            SyntaxError(CCB, "Closing Bracket is missing");
    }
    else if (Inst()){
        if(!verifyToken(SC))
            SyntaxError(SC, "SemiColon is missing");
    }
}

// ASSIGN	=	VAR   ,  �=�   ,  EXPR ;
// INST =   ASSIGN | EXECUTE |  IF | WHILE |  FOR | WRITE | WRITELN | READ | READLN | RETURN ;
bool Inst(){
    switch((curr_token = next_token()).code){
        case ID         :Assign_Execute();break;
        case IF         :If();break;
        case WHILE      :While();break;
        case FOR        :For();break;
        case WRITE      :Write();break;
        case WRITELN    :Write();break;
        case READ       :Read();break;
        case READLN     :Read();break;
        case RETURN     :Return();break;
        case SKIP       :
            WriteCurrTokenToFile();
            break;
        case STOP       :
            WriteCurrTokenToFile();
            break;
        default:
            previous_token();
            return false;
    }
    fprintf(xml_file,"</INST>\n");
    return true;
}

// EXECUTE  =	ID  , �(� , ( EXPR | {EXPR, ","} ) , �)� ;
// ASSIGN   =   VAR   ,  �=�  ,  (EXPR | NULL) ;
// VAR      =	ID  , [ �[� , EXPR , �]� ]  ;
void Assign_Execute(){
    fprintf(xml_file,"<INST>\n");
    WriteCurrTokenToFile();
    //Execute
    if(verifyToken(OP)){
        bool r, r2;
        do{
            r = Expr();
        }while((r2 = verifyToken(COMMA)));
        if(r2 && !r)
            SyntaxError(COMMA, "Comma not needed");
        if(!verifyToken(CP))
            SyntaxError(CP, "Closing parenthesis is missing");
        return;
    }
    // Assign
    if(verifyToken(OSB)){
        Expr();
        if(!verifyToken(CSB))
            SyntaxError(CSB, "Closing bracket is missing");
    }
    if(!verifyToken(ASSIGN))
        SyntaxError(ASSIGN, "Assign sign is missing");

    if( !verifyToken(_NULL) && !Expr())
        SyntaxError(curr_token.code, "The expression to be assigned is missing");
}

// IF       =	�if� , "(" , COND , ")" , {IF_INST} , [ { �else if� , "(" , COND , ")" , {IF_INST } ] , [ �else� , {IF_INST} ] ;
// IF_INST	=   INSTS | ( �skip� , �;� )  | ( �stop� , �;� ) ;
void If(){
    fprintf(xml_file,"<INST>\n");
    WriteCurrTokenToFile();
    if(!verifyToken(OP))
        SyntaxError(OP, "Opening parenthesis is missing");
    Cond();
    if(!verifyToken(CP))
        SyntaxError(CP, "Closing parenthesis is missing");
    Insts();
    if(verifyToken(ELSE)){
        if(verifyToken(IF)){
            if(!verifyToken(OP))
            SyntaxError(OP, "Opening parenthesis is missing");
            Cond();
            if(!verifyToken(CP))
                SyntaxError(CP, "Closing parenthesis is missing");
            Insts();
        }
        else
            Insts();
    }
}

// WHILE  =	�while� , �(� , COND , �)� , INSTS ;
void While(){
    fprintf(xml_file,"<INST>\n");
    WriteCurrTokenToFile();
    if(!verifyToken(OP))
        SyntaxError(OP, "Opening parenthesis is missing");
    Cond();
    if(!verifyToken(CP))
        SyntaxError(CP, "Closing parenthesis is missing");
    Insts();
}

// FOR   =	�for� , �(� ID , �=� , EXPR , �;� , COND , �;� , INST , �)� , INSTS ;
void For(){
    fprintf(xml_file,"<INST>\n");
    WriteCurrTokenToFile();
    if(!verifyToken(OP))
        SyntaxError(OP, "Opening parenthesis is missing");
    if(!verifyToken(ID))
        SyntaxError(ID, "ID is missing");
    if(!verifyToken(ASSIGN))
        SyntaxError(ASSIGN, "Assign sign is missing");
    if(!Expr())
        SyntaxError(curr_token.code, "Initial value is missing");
    if(!verifyToken(SC))
        SyntaxError(SC, "SemiColon is missing");
    Cond();
    if(!verifyToken(SC))
        SyntaxError(SC, "SemiColon is missing");
    Inst();
    if(!verifyToken(CP))
        SyntaxError(CP, "Closing parenthesis is missing");
    Insts();
}

// COND   =   [{ �(� }] , [EXPR] , [CONDOP] , (EXPR | "null") , [ �)� ] , [ { (�and� | �or�) , COND , [{ "}" }] } ] ;
void Cond(){
    bool r = false;
    r = verifyToken(OP);
    Expr();
    if (CondOp()){
        if(!Expr() && !verifyToken(_NULL))
            SyntaxError(curr_token.code, "The right expression in the condition is missing");
    }
    if(r){
        if(!verifyToken(CP))
            SyntaxError(CP, "Closing parenthesis is missing");
    }
    if(verifyToken(AND) || verifyToken(OR))
        Cond();
}

// CONDOP   =	�!=� | �<� |� >� | �<=� | �>=� | �not� ;
bool CondOp(){
     switch((curr_token = next_token()).code){
        case EQ: case PLUS: case MINUS: case MULT:
        case DIV: case INF: case INFEQ: case SUP:
        case SUPEQ: case DIFF: case NOT : break;
        default: return false;
    }
    if (curr_token.code==INFEQ)
        fprintf(xml_file,"{ %s, &#60;= }\n", curr_token.name);
    else if (curr_token.code==INF)
        fprintf(xml_file,"{ %s, &#60; }\n", curr_token.name);
    else
        WriteCurrTokenToFile();
    return true;
}

void Write(){
    bool r = true;
    fprintf(xml_file,"<INST>\n");
    WriteCurrTokenToFile();
    if(!verifyToken(OP))
        SyntaxError(OP, "Opening parenthesis is missing");
    do{
        r = Expr();
    }while(verifyToken(COMMA));
    if(!r)
        SyntaxError(COMMA, "Comma not needed");
    if(!verifyToken(CP))
        SyntaxError(CP, "Closing parenthesis is missing");
}

void Read(){
    bool r = true;
    fprintf(xml_file,"<INST>\n");
    WriteCurrTokenToFile();
    if(!verifyToken(OP))
        SyntaxError(OP, "Opening parenthesis is missing");
    verifyToken(ID);
    if(verifyToken(OSB)){
        Expr();
        if(!verifyToken(CSB))
            SyntaxError(CSB, "Closing bracket is missing");
    }
    while(verifyToken(COMMA)){
        r = verifyToken(ID);
        if(verifyToken(OSB)){
            Expr();
            if(!verifyToken(CSB))
                SyntaxError(CSB, "Closing bracket is missing");
        }
    }
    if(!r)
        SyntaxError(COMMA, "Comma not needed");
    if(!verifyToken(CP))
        SyntaxError(CP, "Closing parenthesis is missing");
}

// RETURN    = 	�return� ,  [ EXPR | { EXPR , "," } ]  ;
void Return(){
    fprintf(xml_file,"<INST>\n");
    WriteCurrTokenToFile();
    bool r, r2;
    do{
        r = Expr();
    }while((r2 = verifyToken(COMMA)));
    if(r2 && !r)
        SyntaxError(COMMA, "Comma not needed");
}

// EXPR  =	(  �(� , TERM ,  [ { ADDOP , TERM } ]  , �)�  )  |  BOOLVAL  |  STRVAL | CHARVAL | "null";
bool Expr(){
    bool r = true;
    if ( isBool() || verifyToken(CHARVAL) || verifyToken(STRVAL) )
        return true;
    if (!Term())
        return false;
    while( AddOp() ){
        if(!r)
            SyntaxError(PLUS, "Two successive terms without AddOp sign in between");
        r = Term();
    }
    if (!r)
        SyntaxError(PLUS, "+ or - sign not needed");
    return true;
}

bool isBool(){
    if(verifyToken(TRUE) || verifyToken(FALSE))
        return true;
    return false;
}

bool AddOp(){
    if ( (verifyToken(PLUS)) || (verifyToken(MINUS)) )
        return true;
    return false;
}

// TERM    =	FACTOR  ,  [ { MULOP , FACTOR } ]  ;
bool Term(){
    if (!Factor())
        return false;
    bool r = true;
    while( MulOp() ){
        if(!r)
            SyntaxError(MULT, "Two successive factors without MultOp sign in between");
        r = Factor();
    }
    if(!r)
        SyntaxError(MULT, "* or / sign not needed");
    return true;
}

bool Factor(){
    if ( !verifyToken(ID) && !verifyToken(NUM) && !verifyToken(OP) ){
        return false;
    }
    // expression between parentheses
    if (curr_token.code==OP){
        Expr();
        if(!verifyToken(CP))
            SyntaxError(CP, "Closing parenthesis is missing");
    }
    // array value
    else if (curr_token.code==ID && verifyToken(OSB)){
        Expr();
        if(!verifyToken(CSB))
            SyntaxError(CSB, "Closing bracket is missing");
    }
    // function execution
    else if (curr_token.code==ID && verifyToken(OP)){
        bool r = true, r2 = false;
        do{
            r = Expr();
        }while((r2 = verifyToken(COMMA)));
        if(r2 && !r)
            SyntaxError(COMMA, "Comma not needed");
        if(!verifyToken(CP))
            SyntaxError(CP, "Closing parenthesis is missing");
    }
    return true;
}

bool MulOp(){
    if ( verifyToken(MULT) || verifyToken(DIV) )
        return true;
    return false;
}
*/
