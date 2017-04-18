#include <stdio.h>
#define N  10

int main(void){
  int i,sum = 0;
  int a[N];
  for(i=0;i<N;i++){
    printf("%d番目の数字:",i+1);
    scanf("%d",&a[i]);
  }
  for(i=0;i<N;i++){
    sum +=a[i];
  }
  printf("総和は%dです\n",sum);
  return 0;
}
