%{
#include <stdio.h>

int vowels = 0;
int consonants = 0;
%}

%%
[aeiouAEIOU]    { vowels++; }
[a-zA-Z]        { consonants++; }
\n              {
                    printf("Vowels = %d\n", vowels);
                    printf("Consonants = %d\n\n", consonants);
                    vowels = consonants = 0;
                }
.               ;
%%

int main()
{
    printf("Enter a string:\n");
    yylex();
    return 0;
}

int yywrap()
{
    return 1;
}
