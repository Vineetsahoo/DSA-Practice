%{
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void yyerror(const char *s);
int yylex();
%}

%left '+' '-'
%left '*' '/'
%right '^'
%right UMINUS

%token NUMBER SIN COS TAN COT SEC COSEC
%token LOG LOG2 LOG10 EXP
%token SQRT ABS FLOOR CEIL

%%

equation:
      expression '\n' { printf("Result: %lf\n", $1); }
    ;

expression:

      expression '+' expression { $$ = $1 + $3; }
    | expression '-' expression { $$ = $1 - $3; }
    | expression '*' expression { $$ = $1 * $3; }
    | expression '/' expression { $$ = $1 / $3; }

    | expression '^' expression { $$ = pow($1,$3); }

    | '-' expression %prec UMINUS { $$ = -$2; }

    | '(' expression ')' { $$ = $2; }

    | NUMBER { $$ = $1; }

    /* Trigonometric */

    | SIN '(' expression ')' { $$ = sin($3); }
    | COS '(' expression ')' { $$ = cos($3); }
    | TAN '(' expression ')' { $$ = tan($3); }

    | COT '(' expression ')' { $$ = 1/tan($3); }
    | SEC '(' expression ')' { $$ = 1/cos($3); }
    | COSEC '(' expression ')' { $$ = 1/sin($3); }

    /* Logarithmic */

    | LOG '(' expression ')' { $$ = log($3); }
    | LOG2 '(' expression ')' { $$ = log2($3); }
    | LOG10 '(' expression ')' { $$ = log10($3); }

    | EXP '(' expression ')' { $$ = exp($3); }

    /* Math utilities */

    | SQRT '(' expression ')' { $$ = sqrt($3); }

    | ABS '(' expression ')' { $$ = fabs($3); }

    | FLOOR '(' expression ')' { $$ = floor($3); }

    | CEIL '(' expression ')' { $$ = ceil($3); }

    ;

%%

void yyerror(const char *s){
    printf("Error: %s\n",s);
}

int main(){
    printf("Enter Expression:\n");
    yyparse();
    return 0;
}