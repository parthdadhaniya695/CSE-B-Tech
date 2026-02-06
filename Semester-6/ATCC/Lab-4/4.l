%{
#include <stdio.h>
int lines = 1;
%}

%%
int|float|if|else|while|return   { printf("Keyword: %s\n", yytext); }

[a-zA-Z_][a-zA-Z0-9_]*            { printf("Identifier: %s\n", yytext); }

[0-9]+                            { printf("Number: %s\n", yytext); }

"="|"+"|"-"|"*"|"/"               { printf("Operator: %s\n", yytext); }

"//".*                            { printf("Single-line Comment\n"); }

"/*"                              { printf("Multi-line Comment Start\n"); }
"*/"                              { printf("Multi-line Comment End\n"); }

[ \t]+                            { /* ignore spaces */ }

\n                                { lines++; }

.                                 { /* ignore others */ }
%%

int main()
{
    printf("Enter input (Ctrl+Z then Enter):\n");
    yylex();
    printf("Total lines: %d\n", lines);
    return 0;
}

int yywrap()
{
    return 1;
}
