%{
#include "calculator.tab.h"
#include <math.h>
%}

%%
[0-9]+(\.[0-9]+)?  { yylval.dval = atof(yytext); return NUMBER; }

"+"                { return PLUS; }
"-"                { return MINUS; }
"*"                { return MUL; }
"/"                { return DIV; }
"^"                { return POW; }

"("                { return '('; }
")"                { return ')'; }

"SINH"             { return SINH; }
"COSH"             { return COSH; }
"ASIN"             { return ASIN; }
"ACOS"             { return ACOS; }

[ \t]              ;
\n                 { return '\n'; }

.                  { printf("Invalid character: %s\n", yytext); }
%%

int yywrap() { return 1; }
