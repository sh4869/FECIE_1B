#ifndef WORD_H_
#define WORD_H_
#include <stdio.h>
typedef unsigned short WORD; /* 符号なしshort intをWORDと呼ぶ*/
typedef unsigned long DWORD; /* 符号なしlong intをDWORDと呼ぶ*/
typedef unsigned char BYTE; /* 符号なしcharをBYTEと呼ぶ*/
void fwriteWORD(WORD w, FILE *fp);
void fwriteDWORD(DWORD dw, FILE *fp);
#endif /* WORD_H_ */