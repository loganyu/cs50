#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float change;
    int coins = 0;

    do
    {
        printf("O hai!  How much change is owed? ");
        change = GetFloat();

    }while (change < 0 );
    
    int cents = (int) round(change * 100);

    coins += cents / 25;
    cents = cents % 25;
    
    coins += cents / 10;
    cents = cents % 10;
    
    coins += cents / 5;
    cents = cents % 5;
    
    coins += cents;
    
    printf("%d\n", coins);
    
    return 0;

}
