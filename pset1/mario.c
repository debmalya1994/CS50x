#include<cs50.h>
#include<stdio.h>

int main(void)
{
int n,i,j,k;
do
{
    printf("Height: ");
n = get_int();
}
while((n<0) || (n>23));
for (i=1;i<=n;i++)
{
    for(j=n-i;j>0;j--)
    {
    printf(" ");
    }
    for(k=1;k<=i+1;k++)
    {
    printf("#");
    }
    printf("\n");
}
return 0;
}
