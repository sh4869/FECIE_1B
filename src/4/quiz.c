#include <stdlib.h>
#include "quiz.h"
#define N 100

int quizReader(QUIZ *quiz,int *n){
  int i = 0;
  FILE *fp;
  fp = fopen("quiz.txt","r");
  if(fp == NULL){
    printf("ファイルの読み込みに失敗しました\n");
    return -1;
  }
  while(fscanf(fp,"%[^,],%[^,],%[^,],%d",quiz[i].question,quiz[i].ans1,quiz[i].ans2,&quiz[i].correct_ans) != EOF && i < N){
    i++;
  }
  *n = i-1;
  return 0;
}

void input(){
  QUIZ *quizzes = (QUIZ *)malloc(sizeof(QUIZ)*100);
  int num,i,ans,score  = 0;
  if(quizReader(quizzes,&num)){
    printf("エラーが発生したようです\n");
    return;
  }
  for(i=0;i<num;i++){
    printf(quizzes[i].question);
    printf("\n1: %s,2: %s\n",quizzes[i].ans1,quizzes[i].ans2);
    scanf("%d",&ans);
    if(ans == quizzes[i].correct_ans){
      printf("CORRECT!\n");
      score += 5;
    } else {
      printf("WRONG!\n");
    }
    printf("score: %d\n",score);
  }
}
