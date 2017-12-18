/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	N	10

void ary_set_d(double v[], int n, double val)
{
	int i;

	for (i = 0; i < n; i++)
		v[i] = val;
}

int main(void)
{
	double	A[N];
	double	value;
	int		i;

	printf("数字を入力してください："); scanf("%lf", &value);
	
	ary_set_d(A, N, value);

	for (i = 0; i < N; i++) {
		printf("A[%d]: %f\n", i, A[i]);
	}

    return 0;
}

/*
  実行結果

$ ./a.out
数字を入力してください：3.14159
A[0]: 3.141590
A[1]: 3.141590
A[2]: 3.141590
A[3]: 3.141590
A[4]: 3.141590
A[5]: 3.141590
A[6]: 3.141590
A[7]: 3.141590
A[8]: 3.141590
A[9]: 3.141590
$ 

*/
