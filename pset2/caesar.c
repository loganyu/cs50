#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cs50.h>

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("enter one argument");
        return 1;
    }
    
    int k = atoi(argv[1]);
    string p = GetString();
    char orig_letter;
    char caesar_letter;
    
    for (int i = 0, n = strlen(p); i < n; i++)
    {
        if ( p[i] >= 'a' && p[i] <= 'z' )
        {
            orig_letter = p[i] - 'a';
            caesar_letter = ((orig_letter + k) % 26) + 'a';
        } else if ( p[i] >= 'A' && p[i] <= 'Z') {
            orig_letter = p[i] - 'A';
            caesar_letter = ((orig_letter + k) % 26) + 'A';
        } else {
            caesar_letter = p[i];
        }
         
        printf("%c", caesar_letter);
    }
    printf("\n");
}
