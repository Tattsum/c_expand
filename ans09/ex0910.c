/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>
#include <math.h>

#define	N		100

void getAveVarStddev(int data[], int size,
					 double *ave, double *var, double *stddev)
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

	*stddev = sqrt(*var);
}

double devVal(int score, double ave, double stddev)
{
	return (score - ave) * 10.0 / stddev + 50;
}

int main(void)
{
	int		A[N];
	int		i, n;
	double	ave, var, stddev;

	printf("入力データの個数:");
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		printf("Input A[%d]:", i);
		scanf("%d", &A[i]);
	}

	getAveVarStddev(A, n, &ave, &var, &stddev);
	printf("平均: %f\n", ave);
	printf("分散: %f\n", var);
	printf("標準偏差: %f\n", stddev);

	for (i = 0; i < n; i++) {
		printf("A[%d]: 得点 %d: 偏差値 %f\n",
			   i, A[i], devVal(A[i], ave, stddev));
	}
	
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
標準偏差: 16.420719
A[0]: 得点 65: 偏差値 46.711472
A[1]: 得点 45: 偏差値 34.531737
A[2]: 得点 74: 偏差値 52.192352
A[3]: 得点 95: 偏差値 64.981074
A[4]: 得点 81: 偏差値 56.455260
A[5]: 得点 64: 偏差値 46.102485
A[6]: 得点 55: 偏差値 40.621604
A[7]: 得点 90: 偏差値 61.936140
A[8]: 得点 85: 偏差値 58.891206
A[9]: 得点 50: 偏差値 37.576670
$ ./a.out
入力データの個数:5
Input A[0]:31
Input A[1]:27
Input A[2]:50
Input A[3]:36
Input A[4]:34
平均: 35.600000
分散: 61.040000
標準偏差: 7.812810
A[0]: 得点 31: 偏差値 44.112234
A[1]: 得点 27: 偏差値 38.992437
A[2]: 得点 50: 偏差値 68.431269
A[3]: 得点 36: 偏差値 50.511980
A[4]: 得点 34: 偏差値 47.952081
$ 

*/
