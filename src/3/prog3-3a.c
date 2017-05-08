#include <stdio.h>

int main(int argc,char **argv){
  FILE *fp,*fp2;
  char line[1000];
  int i = 1;
  fp = fopen(argv[1],"r");
  fp2 = fopen(argv[2],"a");
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
