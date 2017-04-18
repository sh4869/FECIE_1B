#include <stdio.h>

int main(void){
  int i,j;
  printf("一つ目の数字を入力してください:");
  scanf("%d",&i);
  printf("二つ目の数字を入力してください:");
  scanf("%d",&j);
  if(j != 0){
    printf("%dわる%dは%f\n",i,j,(double)i/(double)j);
  } else {
    printf("われませんよ\n");
  }
}
