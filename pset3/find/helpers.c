/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>

#include "helpers.h"

#include <stdio.h>

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // implement a searching algorithm
    for (int i = 0; i < n; i++)
    {
        if (values[i] == value) {
            return true;
        }
    }
    
    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    bool sorted = false;
    int placeholder;
    
    do
    {
        sorted = true;
        for (int i = 0; i < n-1; i++)
        {

            if (values[i] > values[i+1])
            {
                sorted = false;
                placeholder = values[i];
                values[i] = values[j];
                values[j] = values[i];
            }
        }
    }while(!sorted);
    
    for (int i = 0; i < n; i++)
    {
        printf("%i\n", values[i]);
    }
    
    return;
}
