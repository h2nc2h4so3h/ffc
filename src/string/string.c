#include "string.h"
#include <stdlib.h>
#include <stdio.h>

/*TO RELOCATE*/
#include <stdint.h>

union a_ptr{
	unsigned char* c;
	uintmax_t* i;
};

union c_a_ptr{
	const unsigned char* c;
	const uintmax_t* i;
};

void __memcpy(void* dest,const void* src,unsigned int n)
{
	union a_ptr cp_dest;
	union c_a_ptr cp_src;
	int i = 0;
	cp_dest.i=dest;
	cp_src.i=src;
	for(i=0;i<n/sizeof(uintmax_t);++i)
	{
		//todo move ++ to first line
		*(cp_dest.i)=*(cp_src.i);
		++cp_dest.i;
		++cp_src.i;
	}
	for(i=0;i<n%sizeof(uintmax_t);++i)
	{
		*(cp_dest.c)=*(cp_src.c);
		++cp_dest.c;
		++cp_src.c;
	}
}
/*--*/

void initString(struct string* str)
{
	str->chars[0]='\0';
	str->next=NULL;
}

void makeString(struct string* str_it, const char* chars)
{
	unsigned int i,len=0;
	const char * chars_i=chars;
	do
	{
		++len;
	}
	while(*++chars_i);
	printf(":%d\n",len);
	for(i=0;i<len/STRING_LENGTH_PIECE;i++)
	{
		__memcpy(str_it,chars,STRING_LENGTH_PIECE);
		NEXT_STR_F
	}
	__memcpy(str_it,chars,len%32);

}

size_t lengthString(struct string* str_it)
{
	unsigned int char_i,str_i;
	FOR_CHARS_CHAIN
	(
		if(CHAR_I_CHAIN=='\0')
		{
			return char_i+str_i*STRING_LENGTH_PIECE;
		}
	)
	STRING_NOT_FOUND_END
}

void putString(struct string* str_it,const char c)
{
	unsigned int char_i,str_i;
	char flag = 0;
	FOR_CHARS_CHAIN_F
	(
		if(flag)
		{
			CHAR_I_CHAIN='\0';
			return;
		}
		if(CHAR_I_CHAIN=='\0')
		{
			CHAR_I_CHAIN=c;
			flag=1;
		}
	)
	STRING_NOT_FOUND_END
}

void printString(struct string* str_it)
{
	unsigned int char_i,str_i;
	FOR_CHARS_CHAIN(
		if(CHAR_I_CHAIN=='\0')
		{
			printf("\n");
			return;
		}
		printf("%c",CHAR_I_CHAIN);
		)
	STRING_NOT_FOUND_END
}

void printString_(struct string* str_it)
{
	unsigned int char_i,str_i;
	FOR_CHARS_CHAIN(
		if(CHAR_I_CHAIN=='\0')
		{
			return;
		}
		printf("%c",CHAR_I_CHAIN);
		)
	STRING_NOT_FOUND_END
}

void copyString(struct string* str_to,struct string* str_it)
{
	unsigned int str_i,char_i;
	FOR_STR(
		FOR_CHARS(
			if(CHAR_I_CHAIN=='\0') return;
			str_to->chars[char_i]=CHAR_I_CHAIN;
		)
		NEXT_STR_F_(str_to)
	)
}

void concateString(struct string* str,struct string* str_)
{
	
}

char eraseString(struct string* str,int start,int end)
{

}