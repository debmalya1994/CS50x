#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main (void)
{
	string name = "";
	int n = 0;
	
	name = GetString();
	n = strlen(name);
	
	printf("%c",toupper(name[0]));
	
	for(int i = 0; i < n; ++i)
	{
		if(name[i-1] == 32) 
		{
			printf("%c",toupper(name[i]));
		}
	}
	printf("\n");
}