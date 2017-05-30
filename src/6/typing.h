#ifndef TYPING_H_
#define TYPING_H_

#define MAXLEN 100

struct _data{
  char string[50];
  int score;
};

typedef struct _data DATA;

int DataReader(DATA *dataArray, int *n);
int typing(DATA *dataArray, int n);

#endif  /* TYPING_H_ */
