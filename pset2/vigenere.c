#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("enter one argument");
        return 1;
    }
    
    string k = argv[1];
    
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if ( isalpha(k[i]) == 0 )
        {
            printf("don't do that");
            return 1;
        }
    }
    string p = GetString();
    char orig_letter;
    char caesar_letter;
    int klen = strlen(k);
    char ki;
    int kshift;
    int kcount = 0;
    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        ki = k[kcount % klen];
        
        if ( ki >= 'a' && ki <= 'z' )
        {
            kshift = ki - 'a';

        } else if ( ki >= 'A' && ki <= 'Z') {
            kshift = ki - 'A';
        } else {
            kshift = 0;
        }

    
    
        if ( p[i] >= 'a' && p[i] <= 'z' )
        {
            orig_letter = p[i] - 'a';
            caesar_letter = ((orig_letter + kshift) % 26) + 'a';
            kcount += 1;
        } else if ( p[i] >= 'A' && p[i] <= 'Z') {
            orig_letter = p[i] - 'A';
            caesar_letter = ((orig_letter + kshift) % 26) + 'A';
            kcount += 1;
        } else {
            caesar_letter = p[i];
        }
         
        printf("%c", caesar_letter);
    }
    printf("\n");
}
