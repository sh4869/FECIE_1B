#include <stdio.h>

int main(void){
  int i,j;
  printf("一つめの数字を入力してください:");
  scanf("%d",&i);
  printf("二つめの数字ヲ入力してください:");
  scanf("%d",&j);
  printf("%dたす%dは%d\n",i,j,i+j);
  return 0;
}
