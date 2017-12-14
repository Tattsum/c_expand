/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void swapd(double *num1, double *num2)
{
	double tmp;

	tmp   = *num1;
	*num1 = *num2;
	*num2 = tmp;
}

int main(void)
{
	double n1, n2;

	printf("Input n1: "); scanf("%lf", &n1);
	printf("Input n2: "); scanf("%lf", &n2);

	if (n1 < n2)
		swapd(&n1, &n2);

	printf("%f / %f = %f\n", n1, n2, n1/n2);
	
    return 0;
}

/*
  実行結果

$ ./a.out
Input n1: 10.5
Input n2: 12.3
12.300000 / 10.500000 = 1.171429
$ ./a.out
Input n1: 15.6
Input n2: 11.1
15.600000 / 11.100000 = 1.405405
$ ./a.out
Input n1: -15.6
Input n2: 11.1
11.100000 / -15.600000 = -0.711538
$ 

*/
