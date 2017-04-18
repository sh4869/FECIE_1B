#include <stdio.h>
#include <stdlib.h>

int main(int argc,char  **argv){
  int num = atoi(argv[1]);
  int i,sum = 0;
  int a[num];
  for(i=0;i<num;i++){
    printf("%d番目の数字:",i+1);
    scanf("%d",&a[i]);
  }
  for(i=0;i<num;i++){
    sum +=a[i];
  }
  printf("総和は%dです\n",sum);
  return 0;
}
