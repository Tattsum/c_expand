// ex1303.c

#include <stdio.h>
#define NUM 10

void dswap(double *x, double *y)
{
  double tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

void ssort(double a[], int size)
{
  int i, j, max;

  for(j = 0; j < NUM-1; j++){
    max = j;
    for(i = j + 1; i < NUM; i++){
      if(a[i] > a[max]) max = i;
    }
    dswap(&a[j], &a[max]);
  }
}


void inputDArray(double a[], int size)
{
  int i;
  for(i = 0; i < size; i++){
    printf("a[%d]: ", i);
    scanf("%lf", &a[i]);
  }
}

void printDArray(double a[], int size)
{
  int i;
  for(i = 0; i < size; i++){
    printf("%.1lf ", a[i]);
  }
  putchar('\n');
}



int main(void)
{
  double a[NUM];
  int i, j;
  inputDArray(a, NUM);
  printf("Before sort \n");
  printDArray(a, NUM);

  printf("After sort \n");
  ssort(a, NUM);
  printDArray(a, NUM);

  return 0;
}
