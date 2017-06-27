#include <stdio.h>
#include <stdlib.h>

#include "imgutil.h"
#include "thicken.h"
#include "import.h"
#include "export.h"

void thicken(){
  FILE *fpIn,*fpOut;
  IMAGE *imgIn = (IMAGE *)malloc(sizeof(IMAGE));
  IMAGE *imgOut = (IMAGE *)malloc(sizeof(IMAGE));
  PIXEL *tmp_pixel = (PIXEL *) malloc (5 * sizeof(PIXEL));
  int r,g,b;
  fpIn = fopen("venice-edge.bmp","r");
  readImage(fpIn,imgIn);

  imgOut->width = imgIn->width;
  imgOut->height = imgIn->height;
  imgOut->depth = imgIn->depth;
  imgOut->pixels = (PIXEL *)malloc(imgOut->width*imgOut->height*sizeof(PIXEL));
  for(int x = 1;x < (imgOut->width - 1);x++){
    for(int y = 1;y < (imgOut->height - 1);y++){
      tmp_pixel[0] = imgIn->pixels[getLabel(x,y,imgIn->width)];
      tmp_pixel[1] = imgIn->pixels[getLabel(x+1,y,imgIn->width)];
      tmp_pixel[2] = imgIn->pixels[getLabel(x-1,y,imgIn->width)];
      tmp_pixel[3] = imgIn->pixels[getLabel(x,y+1,imgIn->width)];
      tmp_pixel[4] = imgIn->pixels[getLabel(x,y-1,imgIn->width)];
      r = tmp_pixel[0].r;
      g = tmp_pixel[0].g;
      b = tmp_pixel[0].b;
      for(int i = 1;i < 5;i++){
        if(r >  tmp_pixel[i].r) r = tmp_pixel[i].r;
        if(g >  tmp_pixel[i].g) g = tmp_pixel[i].g;
        if(b >  tmp_pixel[i].b) b = tmp_pixel[i].b;
      }
      imgOut->pixels[getLabel(x,y,imgIn->width)].r = r;
      imgOut->pixels[getLabel(x,y,imgIn->width)].g = g;
      imgOut->pixels[getLabel(x,y,imgIn->width)].b = b;
      printf("%d %d\r",x,y);
    }
  }
  fpOut = fopen("venice-t.bmp","w");
  saveImage(fpOut,imgOut);
  return;
}
