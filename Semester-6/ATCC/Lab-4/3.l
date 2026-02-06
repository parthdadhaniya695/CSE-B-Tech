%{
#include <stdio.h>
%}

%%
[ \t]*\/\/.*        { printf("Single-line comment\n"); }
[ \t]*\/\*.*\*\/    { printf("Multi-line comment\n"); }
.*                  { printf("Not a comment\n"); }
%%

int main()
{
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
