#include "randomWalk.h"
#include "imgutil.h"
#include "export.h"
#include <stdlib.h>

void init(POINT *pointArray,int totalPointNum,int initX,int initY){
  srand((unsigned)time(NULL));
  for(int i = 0;i < totalPointNum;i++){
    /*
    pointArray[i].x = initX;
    pointArray[i].y = initY;
    pointArray[i].r = (rand()%255 + rand()%255 + rand()%255 + rand()%255 + rand()%255) / 7;
    pointArray[i].b = (rand()%255 + rand()%255 + rand()%255 + rand()%255 + rand()%255) / 7;
    pointArray[i].g = (rand()%255 + rand()%255 + rand()%255 + rand()%255 + rand()%255) / 7;
    */
    
    switch(i%3){
      case 0:
        pointArray[i].r = 255;
        pointArray[i].g = 0;
        pointArray[i].b = 0;
        break;
      case 1:
        pointArray[i].r = 0;
        pointArray[i].g = 0;
        pointArray[i].b = 255;
        break;
      case 2:
        pointArray[i].r = 0;
        pointArray[i].g = 255;
        pointArray[i].b = 0;
        break;
      default:
        break;
    }
  }
}

void move(POINT *pointArray,int i,int w,int h){
  int r0,r1;
  r0 = rand()%3;
  r1 = rand()%3;
  switch(r0){
    case 0:
      if(pointArray[i].x + 1 < w) pointArray[i].x += 1;
      break;
    case 1:
      if(pointArray[i].x - 1 >= 0) pointArray[i].x -=1;
      break;
    default:
      break;
  }
  switch(r1){
    case 0:
      if(pointArray[i].y + 1 < h) pointArray[i].y += 1;
      break;
    case 1:
      if(pointArray[i].y - 1 >= 0) pointArray[i].y -= 1;
      break;
    default:
      break;
  }
  return;
}

void drawPoints(POINT *pointArray,int w,int h,int totalPointNum,int turns){
  int i,j,label,ret;
  FILE *fp;
  IMAGE *img = (IMAGE *)malloc(sizeof(IMAGE));
  img->width = w;
  img->height = h;
  img->depth = 24;
  img->pixels=(PIXEL *)malloc(img->width*img->height*sizeof(PIXEL));
  for(i=0;i<w*h;i++){
    img->pixels[i].r=255;
    img->pixels[i].g=255;
    img->pixels[i].b=255;
  }
  printf("Start Random Walk\n");
  for(i=0;i<turns;i++){
    printf("turn %d\r",i);
    for(j=0;j<totalPointNum;j++){
      move(pointArray,j,w,h);
      label = getLabel(pointArray[j].x,pointArray[j].y,w);
      img->pixels[label].r = pointArray[j].r;
      img->pixels[label].b = pointArray[j].b;
      img->pixels[label].g = pointArray[j].g;
    }
  }
  printf("Save Image\n");
  fp = fopen("randomWalk.bmp","w");
  ret=saveImage(fp,img);
  if(!ret){
    printf("error\n");
  }
  return;
}
