#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[])
{
      
       if(argc!=2)
       {
           printf("please enter maximum 2 parameters\n");
           return 1;
       }
       int k = atoi(argv[argc-1]);
       

       printf("plaintext: ");
       string str=get_string();
       
       int n=strlen(str);
       
              printf("ciphertext: ");
       for(int i=0;i<n;i++)
       {
           if(str[i]>='a' && str[i]<='z'){
           int p=((int)str[i]+k-97)%26;
           printf("%c",p+97);
           }
           else if(str[i]>='A' && str[i]<='Z'){
           int p=((int)str[i]+k-65)%26;
           printf("%c",p+65);
           }
           else
           printf("%c",str[i]);
       }

       printf("\n");
       return 0;
}