/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

int fact(int n)
{
    int f, i;
    f = 1;
    for (i = 1; i <= n; i++) {
	f = f*i;
    }
    return f;
}

int perm(int n, int k)
{
    return fact(n)/fact(n-k);
}

int comb(int n, int k)
{
    return fact(n)/(fact(n-k)*fact(k));
}


int main(void)
{
    int n, k;
    
    printf("n? "); scanf("%d", &n);
    printf("k? "); scanf("%d", &k);

    printf("%dP%d = %d, %dC%d = %d\n", n, k, perm(n, k), n, k, comb(n, k));

    return 0;
}

/*
  実行結果

$ ./a.out
n? 10
k? 4
10P4 = 5040, 10C4 = 210
$ ./a.out
n? 10
k? 1
10P1 = 10, 10C1 = 10
$ ./a.out
n? 10 
k? 10
10P10 = 3628800, 10C10 = 1
$

*/
