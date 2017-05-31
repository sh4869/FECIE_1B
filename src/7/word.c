#include "word.h"
#define EIGHT_BIT 256

void fwriteWORD(WORD w,FILE *fp){
  char mod,i;
  for(i=0;i<2;i++){
    mod = w % EIGHT_BIT;
    fputc(mod,fp);
    w = (WORD)(w / EIGHT_BIT);
  }
}

void fwriteDWORD(DWORD dw,FILE *fp){
  char mod,i;
  for(i=0;i<4;i++){
    mod = dw % EIGHT_BIT;
    fputc(mod,fp);
    dw = (DWORD)(dw / EIGHT_BIT);
  }
}
