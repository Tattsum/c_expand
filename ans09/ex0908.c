/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	N	100

void getMaxIdx(int data[], int size, int *maxidx)
{
	int i;

	*maxidx = 0;
	for (i = 0; i < size; i++) {
		if (data[i] > data[*maxidx])
			*maxidx = i;
	}
}

int main(void)
{
	int		A[N];
	int		i, n;
	int		maxidx;

	printf("入力データの個数:");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Input A[%d]:", i);
		scanf("%d", &A[i]);
	}

	getMaxIdx(A, n, &maxidx);
	printf("最大値: A[%d]: %d\n", maxidx, A[maxidx]);

    return 0;
}

/*
  実行結果

$ ./a.out
入力データの個数:10
Input A[0]:23
Input A[1]:24
Input A[2]:42
Input A[3]:35
Input A[4]:42
Input A[5]:42
Input A[6]:57
Input A[7]:43
Input A[8]:42
Input A[9]:34
最大値: A[6]: 57
$ 

*/
