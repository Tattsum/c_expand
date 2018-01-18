// ex1302.c

#include <stdio.h>
#define NUM 10

void dswap(double *x, double *y)
{
  double tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(void)
{
  double a[NUM];
  int i, j;

  for(i = 0; i < NUM; i++){
    printf("a[%d]: ", i);
    scanf("%lf", &a[i]);
  }
  
  for(j = NUM - 1; j >= 1; j--){
    for(i = 0; i < j; i++){
      if(a[i] < a[i+1]){
	dswap(&a[i], &a[i+1]);
      }
    }
  }

  for(i = 0; i < NUM; i++){
    printf("%.1f ", a[i]);
  }
  putchar('\n');
  
  return 0;
}
