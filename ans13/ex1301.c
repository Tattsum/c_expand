// ex1301.c

#include <stdio.h>

void dswap(double *x, double *y)
{
  double tmp;
  tmp = *x;
  *x = *y;
  *y = tmp;
}

int main(void)
{
  double x, y;

  printf("x: ");
  scanf("%lf", &x);
  printf("y: ");
  scanf("%lf", &y);
  
  if(x>y) dswap(&x, &y);

  printf("x = %.2f\n", x);
  printf("y = %.2f\n", y);
  
  return 0;
}
