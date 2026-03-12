%{
#include "calc.tab.h"
#include <stdlib.h>
%}

%%

[0-9]+(\.[0-9]+)?  { yylval = atof(yytext); return NUMBER; }

sin     { return SIN; }
cos     { return COS; }
tan     { return TAN; }
cot     { return COT; }
sec     { return SEC; }
cosec   { return COSEC; }

log     { return LOG; }
log2    { return LOG2; }
log10   { return LOG10; }

exp     { return EXP; }

sqrt    { return SQRT; }

abs     { return ABS; }

floor   { return FLOOR; }
ceil    { return CEIL; }

[-+*/^()] { return yytext[0]; }

[ \t] ;

\n { return '\n'; }

. { printf("Invalid character: %s\n",yytext); }

%%

int yywrap(){
return 1;
}