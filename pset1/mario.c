#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x;

    do
    {

        printf("Height: ");
        x = GetInt();

    }while (x > 23 || x < 0 );

    int spaces = x - 1;
    int blocks = 2;
    
    for (int i = 0; i < x; i++)
    {
    
        for (int i = 0; i < spaces; i++)
        {
            printf(" ");
        }
        
        for (int i = 0; i < blocks; i++)
        {
            printf("#");
        }
        
        printf("\n");
        
        spaces--;
        blocks++;
    }
    
}
