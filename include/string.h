#include "stddef.h"
#include "stdlib.h"

#define STRING_OUT_RANGE_ERROR printf("out range err");fflush(stdout);abort();
#define STRING_NOT_FOUND_END printf("not found end err");fflush(stdout);abort();

#define STRING_LENGTH_PIECE 32
#define MAX_PIECE_LENGTH 256

#//struct string* ns;
#define EXTEND_STRING ns=(struct string*)malloc(sizeof(struct string)); \
		makeString(ns); \
		str->next=ns; \
		str=ns;

#//piece_i char_i str
#//unsigned int piece_i,char_i;
#// x - statement foreach chars
#// n - statement when there is no new piece
#define STRING_FOR(x,n) for(piece_i=0;piece_i<MAX_PIECE_LENGTH;piece_i++) \
	{ \
		for(char_i=0;char_i<STRING_LENGTH_PIECE;char_i++) \
		{ \
			x \
		} \
		\
		if(str->next!=NULL) \
		{ \
			str=str->next; \
		} \
		else \
		{ \
			n \
		} \
	} \
	STRING_OUT_RANGE_ERROR;

struct string{
	char chars[STRING_LENGTH_PIECE];
	struct string* next;
};

void makeString(struct string*);

size_t lengthString(struct string*);

void putString(struct string*,char);

void printString_(struct string*);
void printString(struct string*);

void concateString(struct string*,struct string*);
void copyString(struct string*,struct string*);

char eraseString(struct string*,int,int);