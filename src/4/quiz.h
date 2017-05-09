#ifndef QUIZ_H_
#define QUIZ_H_

#include <stdio.h>

struct _quiz {
 char question[50];
 char ans1[50];
 char ans2[50];
 int correct_ans;
};

typedef struct _quiz QUIZ;

int quizReader(QUIZ *quiz, int *n);
void input();

#endif
