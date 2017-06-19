/**
 * helpers.c
 *
 * Helper functions for Problem Set 3.
 */
 
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    // TODO: implement a searching algorithm
    if(n<0)
    {
        return false;
    }
    for(int i=0;i<n;i++)
    {
        if(value==values[i])
        {
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
    // TODO: implement a sorting algorithm
    int a=0;
    for(int i=n-3;i>=0;i--)
    {
        for(int j=0;j<=i;j++)
        {
            if(values[j]>values[j+1])
            {
                a=values[j];
                values[j]=values[j+1];
                values[j+1]=a;
           }
        }
    }
    
    return;
}
