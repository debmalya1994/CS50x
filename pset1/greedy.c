#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) 
{
    float n = 0;
    int a = 0;
    int b = 0;
    int c = 0;
    int e = 0;
    int leftover = 0;
    int f = 0;
    int Q = 25;
    int D=10;
    int N = 5;
    do 
    {
        printf("O hai! How much change is owed?\n");
        n = GetFloat();
        if(n == 0||n <= 0)
        printf("How much change is owed?\n:");
    }
    while(n <= 0);
    a = (int)round(n*100);

    b = a / Q;
    leftover = a % Q;
    
    c = leftover / D;
    leftover = leftover % D;
    
    e = leftover / N;
    leftover = leftover % N;
    
    f = b + c + e + leftover;

    printf("%d\n", f);
    
    return 0;
}