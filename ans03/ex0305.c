#include <stdio.h>

void print_mpl_tbl(int n)
{
    int i, j;
    for (i = 1; i <= n; i = i + 1) {
	for (j = 1; j <= n; j = j + 1) {
	    printf("%3d ", i * j);
	}
	printf("\n");
    }
}

int main(void)
{
  int n;

  printf("n: ");
  scanf("%d",&n);

  print_mpl_tbl(n);

  return 0;

}
