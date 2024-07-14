#include "string.h"
#include <stdlib.h>
#include <stdio.h>

void makeString(struct string* str)
{
	str->chars[0]='\0';
	str->next=NULL;
}

size_t lengthString(struct string* str)
{
	unsigned int char_i, piece_i;
	STRING_FOR
	(
		if(str->chars[char_i]=='\0')
		{
			return char_i+piece_i*STRING_LENGTH_PIECE;
		}
		,
		;
	)
}

void putString(struct string* str,char ch)
{
	unsigned int char_i, piece_i;
	struct string* ns;
	char flag = 0;
	STRING_FOR
	(
		if(flag)
		{
			str->chars[char_i]='\0';
			return;
		}
		if(str->chars[char_i]=='\0')
		{
			str->chars[char_i]=ch;
			flag=1;
		}
		,
		EXTEND_STRING
	)
}

void printString_(struct string* str)
{
	unsigned int piece_i,char_i;
	STRING_FOR
	(
		if(str->chars[char_i]=='\0')
		{
			return;
		}
		putchar(str->chars[char_i]);
		,
		return;
	)
}

void printString(struct string* str)
{
	unsigned int piece_i,char_i;
	STRING_FOR
	(
		if(str->chars[char_i]=='\0')
		{
			putchar('\n');
			return;
		}
		putchar(str->chars[char_i]);
		,
		return;
	)
}

void copyString(struct string* str,struct string* str_)
{
	unsigned int piece_i,char_i;
	struct string* ns;

	for(piece_i=0;piece_i<MAX_PIECE_LENGTH;piece_i++) 
	{ 
		for(char_i=0;char_i<STRING_LENGTH_PIECE;char_i++) 
		{ 
			str->chars[char_i]=str_->chars[char_i];
			if(str->chars[char_i]=='\0')
			{
				return;	
			}
		} 
		if(str_->next!=NULL) 
		{ 
			str_=str_->next;
		}
		else 
		{ 
			STRING_NOT_FOUND_END
		}
		if(str->next!=NULL) 
		{ 
			str=str->next;
		}
		else 
		{ 
			EXTEND_STRING
		} 
	} 
}

void concateString(struct string* str,struct string* str_)
{
	unsigned int piece_i,char_i,from_pos=0;
	struct string* ns;
	int z;
	char flag=0;
	STRING_FOR
	(
		if(str->chars[char_i]=='\0')
		{
			flag=1;
		}
		if(flag)
		{
			str->chars[char_i]=str_->chars[from_pos];
			if(str_->chars[from_pos]=='\0')
			{
				return;	
			}
			from_pos++;
			if(from_pos==STRING_LENGTH_PIECE)
			{
				from_pos=0;
				if(str_->next!=NULL)
				{
					str_=str_->next;
				}
				else
				{
					STRING_NOT_FOUND_END
				}
			}
		}
		,
		EXTEND_STRING
	)
}

char eraseString(struct string* str,int start,int end)
{
	unsigned int piece_i,char_i;
	unsigned int piece_s = start/32;
	unsigned int piece_e = end/32;
	unsigned int char_s = start/32;
	unsigned int char_e = end/32;
	struct string* str_e = str;
	for(piece_i=piece_s;piece_i>piece_s;--piece_i)
	{
		str_e=str_e->next;
	}
	printString(str);


}