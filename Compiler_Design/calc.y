/* calc.y - Calculator supporting +, *, -, SQRT, CQRT (cbrt) */

%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <math.h>

    void yyerror(const char *s);
    int yylex(void);
%}

/* Semantic value type */
%union {
    double d;
}

%token <d> NUMBER
%token SQRT CQRT

%type <d> expression

/* Precedence / associativity */
%left '+' '-'
%left '*' 
%right UMINUS   /* unary minus */

%%

/* Start rule */
equation:
    expression '\n'    { printf("Result: %g\n", $1); }
    | '\n'             { /* blank line - ignore */ }
    ;

expression:
      expression '+' expression    { $$ = $1 + $3; }
    | expression '*' expression    { $$ = $1 * $3; }
    | expression '-' expression    { $$ = $1 - $3; }   /* binary minus */
    | '-' expression  %prec UMINUS { $$ = -$2; }       /* unary minus */
    | '(' expression ')'           { $$ = $2; }
    | SQRT '(' expression ')'      { $$ = sqrt($3); }
    | CQRT '(' expression ')'      { $$ = cbrt($3); }  /* handle cube root */
    | NUMBER                       { $$ = $1; }
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Parse error: %s\n", s);
}

int main(void) {
    printf("Simple calculator (set 5): +  *  -  sqrt(...)  cbrt(...)  \n");
    printf("Enter one expression per line. Press Ctrl+D (Unix) or Ctrl+Z (Windows) to exit.\n");
    yyparse();
    return 0;
}