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
    
    // start in middle
    int first = 0;
    int last = n-1;
    int middle = (first + last) / 2;
    
    while( first <= last)
    {
    
        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] > value)
        {
            last = middle - 1;
        }
        else if (values[middle] < value)
        {
            first = middle + 1;
        }
        middle = (first + last) / 2;
    
    }
    
    return false;

}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // implement an O(n^2) sorting algorithm
    
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
                values[i] = values[i+1];
                values[i+1] = placeholder;
            }
        }
    }while(!sorted);
    
    return;
}
