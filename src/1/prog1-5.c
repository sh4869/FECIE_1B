#include <stdio.h>

int main(void){
  int i,j,n;
  printf("正の整数を入力してください:");
  scanf("%d",&i);
  if(i > 0){
    for(j=1;j<i+1;j++){
      for(n=0;n<j;n++){
        printf("#");
      }
      printf("\n");
    }
    for(j=i;j>0;j--){
      for(n=0;n<j;n++){
        printf("#");
      }
      printf("\n");
    }
  } else {
    printf("正の値を入力してね\n");
  }
  return 0;
}
