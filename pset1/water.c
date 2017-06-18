#include<cs50.h>
#include<stdio.h>
int main(void)
{
    int a = 128; float b=1.5;
    printf("Minutes:");
    int minutes = get_int();
    
   if(minutes > 0)
    {
        int bottles = (a*(b*minutes))/16;
        printf("Bottles:%d\n",bottles);
    }
    else
    {
        printf("Enter Integer Value: ");
    }
}