#include "word.h"
#include "imgutil.h"
#include "export.h"

int saveImage(FILE *fp, IMAGE *img){
  WORD bfType=0x4d42; /* BM */
  DWORD bfSize=40;
  WORD bfReserved1=0;
  WORD bfReserved2=0;
  DWORD bfOffset=54;
  DWORD biSize=40;
  DWORD biWidth=img->width;
  DWORD biHeight=img->height;
  WORD biPlanes=1;
  WORD biBitCount=img->depth;
  DWORD biCompression=0;
  DWORD biSizeImage=0;
  DWORD biXPelsPerMeter=300;
  DWORD biYPelsPerMeter=300;
  DWORD biClrUsed=0;
  DWORD biClrImportant=0;
  int x,y,i=0;
  PIXEL p;
  printf("Start.\n");
  /* This program supports only 24bit depth for simplicity.*/
  if(img->depth!=24){
    printf("Sorry, this supports only 24bit depth.\n");
    return 0;
  }
  printf("Writing header...\n");
  fwriteWORD(bfType, fp);
  fwriteDWORD(bfSize, fp);
  fwriteWORD(bfReserved1, fp);
  fwriteWORD(bfReserved2, fp);
  fwriteDWORD(bfOffset, fp);
  fwriteDWORD(biSize, fp);
  fwriteDWORD(biWidth, fp);
  fwriteDWORD(biHeight, fp);
  fwriteWORD(biPlanes, fp);
  fwriteWORD(biBitCount, fp);
  fwriteDWORD(biCompression, fp);
  fwriteDWORD(biSizeImage, fp);
  fwriteDWORD(biXPelsPerMeter, fp);
  fwriteDWORD(biYPelsPerMeter, fp);
  fwriteDWORD(biClrUsed, fp);
  fwriteDWORD(biClrImportant, fp);
  printf("Writing data...\n");
  for(y = 0;y < img->height;y++){
    for(x = 0;x < img->width;x++){
      i = getLabel(x,y,img->width);
      fputc(img->pixels[i].b,fp);
      fputc(img->pixels[i].g,fp);
      fputc(img->pixels[i].r,fp);
    }
  }
  /*
     imgのpixelsメンバが各ピクセルの色データを
     持っている配列であることを思い出し、各ピクセルのデータを順
     に
     青(b)、緑(g)、赤(r)の順番にファイルに書出せ。
     青(b)、緑(g)、赤(r)ともに0から255までの値をとるので
     char型の変数で取り扱えるデータである。そのため、
     ファイルへの書き出しにはfputc関数を使うと良い。
     */
  printf("done!\n");
  return 1;
}
