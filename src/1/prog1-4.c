#include <stdio.h>

int main(void){
  int i,j,c;
  printf("縦の長さを入力してください:");
  scanf("%d",&i);
  printf("横の長さを入力してください:");
  scanf("%d",&j);
  if(i > 0 && j > 0){
    c = j;
    for(;i>0;i--){
      for(;j>0;j--){
        printf("#");
      }
      printf("\n");
      j = c;
    }
  } else {
    printf("正の整数を入力してね\n");
  }
  return 0;
}
