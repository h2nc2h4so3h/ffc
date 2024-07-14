#include "header.h"
#include <stdio.h>
#include "string.h"

int bar();

int main()
{
	int i;
	printf("%d %d \n",foo(),bar());
	struct string s1,s2;
	makeString(&s1);
	makeString(&s2);
	for(i=0;i<17*3;i++)
	{
		putString(&s1,'1');
		putString(&s1,'2');
		putString(&s1,'3');
		putString(&s1,' ');
	}
	printString(&s1);
	printf("%d\n",lengthString(&s1));
	for(i=0;i<17*3;i++)
	{
	putString(&s2,'a');
	putString(&s2,'b');
	putString(&s2,'c');
	putString(&s2,' ');
	}
	printString(&s2);
	printf("%d\n",lengthString(&s2));
	concateString(&s1,&s2);
	printf("%d\n",lengthString(&s1));
	printString(&s1);
	printString(&s2);
	copyString(&s2,&s1);
	printf("%d\n",lengthString(&s2));
	printString(&s2);
	printf("erase");
	fflush(stdout);
	eraseString(&s2,13,19);
	printf("erase");
	fflush(stdout);
	// printf("%d\n",lengthString(&s1));
}