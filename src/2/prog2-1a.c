
#include <stdio.h>
#include <stdlib.h>

int main(void){
  int *array1 = (int *)malloc(sizeof(int)*10000);
  int *array2 = (int *)malloc(sizeof(int)*10000);
  int i,j,k;
  for(i=0;i<10000;i++){
    array1[i] = 2 * i - 1;
    array2[i] = 2 * i;
  }
  for(j=0;j<2000;j++){
    for(i=0;i<10000;i++){
      k = array1[i];
      array1[i] = array2[i];
      array2[i] = k;
    }
  }
  printf("終了\n");
  return 0;
}
