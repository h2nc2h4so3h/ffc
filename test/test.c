#include "header.h"
#include <stdio.h>
#include "string.h"

int bar();

int main()
{
	int i,j;
	struct string s1,s2;
	initString(&s1);
	initString(&s2);
	for(i = 0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			putString(&s1,48+j);
		}

	}
	printString(&s1);
	printf("%d",lengthString(&s1));
	makeString(&s1,"hhiss");
	printString(&s1);
	makeString(&s2,"hi! it's me, mario !");
	printString(&s2);
	copyString(&s1,&s2);
	printString(&s1);
	copyString(&s2,&s1);
	printString(&s2);
	
	

	// printf("%d\n",lengthString(&s1));
}
