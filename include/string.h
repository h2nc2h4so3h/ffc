#include "stddef.h"
#include "stdlib.h"

/*TO RELOCATE*/
#include <stdint.h>
#define memcpy(x,y,z) __memcpy(x,y,z);
void __memcpy(void* dest,const void* src,unsigned int n);
/*--*/

#define STRING_OUT_RANGE_ERROR printf("out range err");fflush(stdout);abort();
#define STRING_NOT_FOUND_END printf("not found end err");fflush(stdout);abort();

#define STRING_LENGTH_PIECE 32
#define MAX_PIECE_LENGTH 256

#//struct string* ns;
#define EXTEND_STRING ns=(struct string*)malloc(sizeof(struct string)); \
		makeString(ns); \
		str->next=ns; \
		str=ns;

#//unsigned int piece_i;
#define FOR_PIECE(x,y)						\
	for(piece_i = 0;piece_i<x;++piece_i)	\
	{										\
		y									\
	}	

#define NEXT_STR_(x) 		\
	if(x->next)	x=x->next;				

#define NEXT_STR 										\
	NEXT_STR_(str_it)

#//struct string str_it;
#//unsigned int str_i;
#define FOR_STR(x)  							\
	for(str_i=0;str_i<MAX_PIECE_LENGTH;str_i++)	\
	{											\
		x										\
		NEXT_STR                                \
	}											\

#define MALLOC_STR_IT_(x)									\
	x->next=(struct string*)malloc(sizeof(struct string));	\
	initString(x->next);									

#define MALLOC_STR_IT		\
	MALLOC_STR_IT_(str_it)									

#define NEXT_STR_F_(x)										\
	if(! x->next)											\
	{														\
		MALLOC_STR_IT_(x)									\
	}														\
	x=x->next;

#define NEXT_STR_F			\
	NEXT_STR_F_(str_it)

#//struct string str_it;
#//unsigned int str_i;
#define FOR_STR_F(x)													\
	for(str_i=0;str_i<MAX_PIECE_LENGTH;str_i++)							\
	{																	\
		x																\
		NEXT_STR_F														\
	}




#//unsigned int char_i
#define FOR_CHARS(x) 									\
	for(char_i=0;char_i<STRING_LENGTH_PIECE;++char_i)	\
	{													\
		x												\
	}													

#//struct string str_it;
#//unsigned int char_i;
#define FOR_CHARS_CHAIN(x)					\
	FOR_STR									\
	(										\
		FOR_CHARS							\
		(									\
			x								\
		)									\
	)										

#//struct string str_it;
#//unsigned int char_i,str_i;
#define FOR_CHARS_CHAIN_F(x)				\
	FOR_STR_F								\
	(										\
		FOR_CHARS							\
		(									\
			x								\
		)									\
	)										


#define CHAR_I_CHAIN str_it->chars[char_i]


struct string{
	char chars[STRING_LENGTH_PIECE];
	struct string* next;
};

void makeString(struct string*,const char*);
void initString(struct string*);

size_t lengthString(struct string*);

void putString(struct string*,char);

void printString_(struct string*);
void printString(struct string*);

void concateString(struct string*,struct string*);
void copyString(struct string*,struct string*);

char eraseString(struct string*,int,int);