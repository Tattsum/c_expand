/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

#define SIZE 20

void readDoubleArray(double a[], int n)
{
   int i;

   for (i = 0; i < n; i++) {
       printf("%d番目? ", i+1);
       scanf("%lf", &a[i]);
   }
}

double sumSquareDoubleArray(double a[], int n)
{
    int i;
    double sum = 0;
    for (i = 0; i < n; i++) {
	sum += a[i] * a[i];
    }
    return sum;
}

int main(void)
{
    int i;
    double a[SIZE];
    int n;

    printf("データの数(20以下)を入力してください: ");
    scanf("%d", &n);
    readDoubleArray(a, n);
    
    printf("2乗の和は %lf です\n", sumSquareDoubleArray(a, n));

    return 0;
}

/*
  実行結果

$ ./a.out
私の名前は南山太郎です。
私の趣味は貯金です。
$ 

*/
