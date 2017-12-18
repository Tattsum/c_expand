/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	N		100

void getAveVar(int data[], int size, double *ave, double *var)
{
	int	i;
	int sum = 0;
	double sum2 = 0.0;

	for (i = 0; i < size; i++)
		sum += data[i];

	*ave = (double)sum / size;
	
	for (i = 0; i < size; i++)
		sum2 += (data[i] - *ave) * (data[i] - *ave);

	*var = sum2 / size;
}

int main(void)
{
	int		A[N];
	int		i, n;
	double	ave, var;

	printf("入力データの個数:");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Input A[%d]:", i);
		scanf("%d", &A[i]);
	}

	getAveVar(A, n, &ave, &var);
	printf("平均: %f\n", ave);
	printf("分散: %f\n", var);

    return 0;
}

/*
  実行結果

$ ./a.out
入力データの個数:10
Input A[0]:65
Input A[1]:45
Input A[2]:74
Input A[3]:95
Input A[4]:81
Input A[5]:64
Input A[6]:55
Input A[7]:90
Input A[8]:85
Input A[9]:50
平均: 70.400000
分散: 269.640000
$ ./a.out
入力データの個数:5
Input A[0]:31
Input A[1]:27
Input A[2]:50
Input A[3]:36
Input A[4]:34
平均: 35.600000
分散: 61.040000
$ 

*/
