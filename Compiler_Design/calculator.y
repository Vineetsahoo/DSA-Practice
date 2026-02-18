%{
#include <stdio.h>
#include <math.h>

void yyerror(const char *s);
int yylex();
%}

%union {
    double dval;
}

%token <dval> NUMBER
%token PLUS MINUS MUL DIV POW
%token SINH COSH ASIN ACOS

%type <dval> expr

/* Precedence & Associativity */
%left PLUS MINUS
%left MUL DIV
%right POW

%%

input:
      | input line
      ;

line:
      expr '\n' { printf("Result = %lf\n", $1); }
      ;

expr:
      NUMBER                { $$ = $1; }

    | expr PLUS expr        { $$ = $1 + $3; }
    | expr MINUS expr       { $$ = $1 - $3; }
    | expr MUL expr         { $$ = $1 * $3; }

    | expr DIV expr
        {
            if ($3 == 0)
                yyerror("Division by zero");
            else
                $$ = $1 / $3;
        }

    | expr POW expr         { $$ = pow($1, $3); }

    | '(' expr ')'          { $$ = $2; }

    | SINH '(' expr ')'     { $$ = sinh($3); }
    | COSH '(' expr ')'     { $$ = cosh($3); }
    | ASIN '(' expr ')'     { $$ = asin($3); }
    | ACOS '(' expr ')'     { $$ = acos($3); }
    ;

%%

void yyerror(const char *s) {
    printf("Error: %s\n", s);
}

int main() {
    printf("Enter Expression:\n");
    yyparse();
    return 0;
}
