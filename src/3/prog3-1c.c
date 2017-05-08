#include <stdio.h>

int main(void){
  FILE *fp,*fp2;
  char line[1000];
  int i = 1;
  fp = fopen("./prog2-1a.c","r");
  fp2 = fopen("./prog2-1a-line.txt","a");
  if(fp == NULL || fp2 == NULL){
    printf("ファイルがひらけませんでした\n");
    return -1;
  }
  while(fgets(line,sizeof(line),fp)!=NULL){
    fprintf(fp2,"%d: %s",i,line);
    i++;
  }
  fclose(fp);
  fclose(fp2);
  return 0;
}
