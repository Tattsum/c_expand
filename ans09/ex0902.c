/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	N	100

void getMinMax(int data[], int size, int *min, int *max)
{
	int i;

	*min = data[0];
	*max = data[0];

	for (i = 0; i < size; i++) {
		if (data[i] < *min)
			*min = data[i];
		if (data[i] > *max)
			*max = data[i];
	}
}

int main(void)
{
	int		A[N];
	int		i, n;
	int		min, max;

	printf("入力データの個数:"); scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Input A[%d]:", i);
		scanf("%d", &A[i]);
	}

	getMinMax(A, n, &min, &max);
	printf("最大値: %d\n", max);
	printf("最小値: %d\n", min);

    return 0;
}

/*
  実行結果

$ ./a.out
入力データの個数:10
Input A[0]:183
Input A[1]:232
Input A[2]:541
Input A[3]:140
Input A[4]:329
Input A[5]:348
Input A[6]:257
Input A[7]:346
Input A[8]:605
Input A[9]:454
最大値: 605
最小値: 140
$ ./a.out
入力データの個数:5
Input A[0]:83
Input A[1]:23
Input A[2]:54
Input A[3]:39
Input A[4]:45
最大値: 83
最小値: 23
$ 

*/
