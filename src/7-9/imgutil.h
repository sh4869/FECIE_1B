#ifndef IMGUTIL_H_
#define IMGUTIL_H_

#include <stdio.h>

struct hsv {
  int h,s,v;
};
struct pixel {
  int r,g,b;
};

typedef struct pixel PIXEL;

struct image{
  int width,height,depth;
  PIXEL *pixels;
};

typedef struct image IMAGE;

long int getLabel(int x,int y,int width);

#endif
