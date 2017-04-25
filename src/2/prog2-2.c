#include <stdio.h>

int solve(double a,double b,double c,double d,double p,double q,double *x,double *y){
  double xi,yi;
  if((a * d) - (c * b) == 0){
    return 0;
  } 
  else {
    *x  = (p - (a * q)/c) / ((-d/c) + b);
    *y = (q - d * (yi))/c;
    return 1;
  }
}

int main(void){
  double x,y;
  int i;
  i = solve(1.0,-1.0,2.0,3.0,1.0,7.0,&x,&y);
  if(i == 1){
    printf("x = %f y = %f \n",x,y);
  } else {
    printf("det=0\n");
  }
  return 0;
}
