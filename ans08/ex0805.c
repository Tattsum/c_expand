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

void sort3(double *num1, double *num2, double *num3)
{
	if (*num1 > *num2)
		swapd(num1, num2);

	if (*num2 > *num3)
		swapd(num2, num3);

	if (*num1 > *num2)
		swapd(num1, num2);
}

int main(void)
{
	double n1, n2, n3;

	printf("Input n1: "); scanf("%lf", &n1);
	printf("Input n2: "); scanf("%lf", &n2);
	printf("Input n3: "); scanf("%lf", &n3);

	puts("Before Sorting");
	printf("n1: %f,  :  n2: %f  : n3: %f\n", n1, n2, n3);
	
	sort3(&n1, &n2, &n3);

	puts("After Sorting");
	printf("n1: %f,  :  n2: %f  : n3: %f\n", n1, n2, n3);	
	
    return 0;
}

/*
  実行結果

$ ./a.out
Input n1: 15.9
Input n2: 11.1
Input n3: 12.2
Before Sorting
n1: 15.900000,  :  n2: 11.100000  : n3: 12.200000
After Sorting
n1: 11.100000,  :  n2: 12.200000  : n3: 15.900000
$ ./a.out
Input n1: 0.5
Input n2: -1.1
Input n3: 2.2
Before Sorting
n1: 0.500000,  :  n2: -1.100000  : n3: 2.200000
After Sorting
n1: -1.100000,  :  n2: 0.500000  : n3: 2.200000
$ 

*/
