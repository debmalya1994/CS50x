#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
 
int main(int argc, string argv[])
{
    if(argc == 1){
         printf("Usage: ./vigenere k\n");
               return 1;
               }
      char *k=argv[1];
              for(int i=0;i<strlen(k);i++)
           {
               if(k[i]>=48 && k[i]<=57){
               printf("Usage: ./vigenere k\n");
               return 1;
               }
           }
      
      if(argc!=2 || !((k[0]>='a' && k[0]<='z') || (k[0]>='A' && k[0]<='Z')))
       {
           printf("Usage: ./vigenere k\n");
           return 1;
       }

       int key=0;
       printf("plaintext: ");
       string str = get_string();
       int n=strlen(str);
       printf("ciphertext: ");
       int j=0;
       for(int i=0;i<n;i++)
       
       {
           if(k[j]>='a' && k[j]<='z')
                key=k[j]-97;
                
            else if(k[j]>='A' && k[j]<='Z')
                key=k[j]-65;
           if(str[i]>='a' && str[i]<='z')
           {
               int p=((int)str[i]+key-97)%26;
               printf("%c",(p+97));
               j++;
              
           }
           else if(str[i]>='A' && str[i]<='Z')
           {
               
               int p=((int)str[i]+key-65)%26;
               printf("%c",p+65);
               j++;
              
           }
           else
                printf("%c",str[i]); 
           
           if(k[j]=='\0')
                j=0;
       
           
       }
       printf("\n");
        return 0;
}