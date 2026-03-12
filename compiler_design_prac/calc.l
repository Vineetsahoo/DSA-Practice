%{
    #include "calc.tab.h"
    #include <stdio.h>
%}

%%
[0-9]+ { yylval = atoi(yytext); return NUMBER; }
[+-*/()] {return yytext[0]; }
[ \t] {/* Ignore Whitespace*/}
\n {return '\n'; }
. { printf(" Invalid Character: %s\n",yytext); }
%%

int yywrap(){
    return 1;
}