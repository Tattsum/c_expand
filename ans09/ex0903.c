/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	N	10

void set_idx(int v[], int n)
{
	int	i;

	for (i = 0; i < n; i++)
		v[i] = i;
}

int main(void)
{
	int		A[N];
	int		i;

	set_idx(A, N);

	for (i = 0; i < N; i ++)
		printf("A[%d]: %d\n", i, A[i]);

    return 0;
}

/*
  実行結果

$ ./a.out
A[0]: 0
A[1]: 1
A[2]: 2
A[3]: 3
A[4]: 4
A[5]: 5
A[6]: 6
A[7]: 7
A[8]: 8
A[9]: 9
$ 

*/
