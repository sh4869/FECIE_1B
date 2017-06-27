#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "import.h"
#include "imgutil.h"
#include "edge.h"
#include "export.h"

void edge(){
  FILE *fpIn,*fpOut;
  IMAGE *imgIn = (IMAGE *)malloc(sizeof(IMAGE));
  IMAGE *imgOut = (IMAGE *)malloc(sizeof(IMAGE));
  int color[3];
  int label;
  PIXEL * tmp_pixels = (PIXEL *)malloc(4 * sizeof(PIXEL));
  fpIn = fopen("venice.bmp","r");
  fpOut = fopen("venice-edge.bmp","w");
  readImage(fpIn,imgIn);

  imgOut->width = imgIn->width;
  imgOut->height = imgIn->height;
  imgOut->depth = imgIn->depth;
  imgOut->pixels = (PIXEL *)malloc(imgOut->width*imgOut->height*sizeof(PIXEL));
  for(int y = 1;y < (imgOut->height - 1);y++){
    for(int x = 1;x < (imgOut->width - 1);x++){
      tmp_pixels[0] = imgIn->pixels[getLabel(x+1,y,imgIn->width)];
      tmp_pixels[1] = imgIn->pixels[getLabel(x-1,y,imgIn->width)];
      tmp_pixels[2] = imgIn->pixels[getLabel(x,y+1,imgIn->width)];
      tmp_pixels[3] = imgIn->pixels[getLabel(x,y-1,imgIn->width)];
      color[0] = sqrt(pow((tmp_pixels[0].r - tmp_pixels[1].r)/2,2) + pow((tmp_pixels[2].r - tmp_pixels[3].r)/2,2));
      color[1] = sqrt(pow((tmp_pixels[0].g - tmp_pixels[1].g)/2,2) + pow((tmp_pixels[2].g - tmp_pixels[3].g)/2,2));
      color[2] = sqrt(pow((tmp_pixels[0].b - tmp_pixels[1].b)/2,2) + pow((tmp_pixels[2].b - tmp_pixels[3].b)/2,2));
      label = getLabel(x,y,imgIn->width);
      imgOut->pixels[label].r = 255 - color[0];
      imgOut->pixels[label].g = 255 - color[1];
      imgOut->pixels[label].b = 255 - color[2];
    }
  }
  saveImage(fpOut,imgOut);

  free(fpIn);
  free(fpOut);
  free(imgIn);
  free(imgOut);
}
