#include <stdio.h>

typedef struct{
  char name[100];
  int population;
} PREF;

float calcDispersion(PREF *prefs,float ave,int length){
  int i;
  float sum;
  for(i=0;i<length;i++){
    sum += (prefs[i].population - ave) * (prefs[i].population - ave);
  }
  return (float)sum / length;
}

int main(void){
  FILE *fp;
  PREF prefs[50];
  int i = 0;
  int sum = 0;
  fp = fopen("population.csv","r");
  if(fp == NULL){
    printf("ファイルが開けませんでした");
    return -1;
  }
  while(fscanf(fp,"%s %d",prefs[i].name,&prefs[i].population) != EOF){
    sum += prefs[i].population;
    i++;
  }
  printf("平均値:%f 分散:%f",(float)(sum) / (i-1),calcDispersion(prefs,(float)(sum) / (i-1),(i-1)));
  return 0;
}
