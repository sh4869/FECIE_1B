#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *array1 = (int *)malloc(sizeof(int)*10000);
  int *array2 = (int *)malloc(sizeof(int)*10000);
  int i,j;
  int *k;
  for(i=0;i<10000;i++){
    array1[i] = 2 * i - 1;
    array2[i] = 2 * i;
  }
  for(j=0;j<2000;j++){
      k = array1;
      array1 = array2;
      array2 = k;
  }
  printf("終了\n");
  return 0;
}
