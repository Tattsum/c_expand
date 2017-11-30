#include <stdio.h>

void readIntArray(int a[], int n)
{
   int i;

   for (i = 0; i < n; i++) {
       printf("%d番目? ", i+1);
       scanf("%d", &a[i]);
   }
}

void printIntArray(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++) {
	printf("%d ", a[i]);
    }
    printf("\n");
}

int sumIntArray(int a[], int n)
{  
    int sum, i;

    sum = 0;
    for (i = 0; i < n; i++) {
       sum = sum + a[i];
    }
    return sum;
}

double avgIntArray(int a[], int n)
{  
    return (double) sumIntArray(a, n) / n;
}

int main(void)
{
    int a[5];

    readIntArray(a, 5);

    printIntArray(a, 5);
    printf("合計%d, 平均: %f\n", sumIntArray(a, 5), avgIntArray(a, 5));

    return 0;
}

