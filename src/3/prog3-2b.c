#include <stdio.h>

typedef struct{
  char name[100];
  int population;
} PREF;

int main(void){
  FILE *fp;
  PREF prefs[50],p;
  int i = 0,j,k;
  fp = fopen("population.csv","r");
  if(fp == NULL){
    printf("ファイルが開けませんでした");
    return -1;
  }
  while(fscanf(fp,"%s %d",prefs[i].name,&prefs[i].population) != EOF){
    i++;
  }
  for(j=0;j<i;j++){
    for(k=j+1;k<i;k++){
      if(prefs[j].population > prefs[k].population){
        p = prefs[j];
        prefs[j] = prefs[k];
        prefs[k] = p;
      }
    }
  }
  for(i=0;i<20;i++){
    printf("%s %d\n",prefs[i].name,prefs[i].population);
  }
  fclose(fp);
  return 0;
}
