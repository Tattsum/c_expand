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

void sort4(double *num1, double *num2, double *num3, double *num4)
{
	sort3(num1, num2, num3);
	sort3(num2, num3, num4);	
	sort3(num1, num2, num3);
}

void sort5(double *num1, double *num2, double *num3, double *num4, double *num5)
{
	sort4(num1, num2, num3, num4);
	sort4(num2, num3, num4, num5);
	sort4(num1, num2, num3, num4);
}

int main(void)
{
	double n1, n2, n3, n4, n5;

	printf("Input n1: "); scanf("%lf", &n1);
	printf("Input n2: "); scanf("%lf", &n2);
	printf("Input n3: "); scanf("%lf", &n3);
	printf("Input n4: "); scanf("%lf", &n4);
	printf("Input n5: "); scanf("%lf", &n5);

	puts("Before Sorting");
	printf("n1: %f,  :  n2: %f  : n3: %f  : n4: %f  : n5: %f\n", n1, n2, n3, n4, n5);
	
	sort5(&n1, &n2, &n3, &n4, &n5);

	puts("After Sorting");
	printf("n1: %f,  :  n2: %f  : n3: %f  : n4: %f  : n5: %f\n", n1, n2, n3, n4, n5);
	
    return 0;
}

/*
  実行結果

$ ./a.out
Input n1: 15.9
Input n2: 11.1
Input n3: 12.2
Input n4: 10.3
Input n5: 13.6
Before Sorting
n1: 15.900000,  :  n2: 11.100000  : n3: 12.200000  : n4: 10.300000  : n5: 13.600000
After Sorting
n1: 10.300000,  :  n2: 11.100000  : n3: 12.200000  : n4: 13.600000  : n5: 15.900000
$ ./a.out
Input n1: 0.5
Input n2: -1.1
Input n3: 2.2
Input n4: -3.4
Input n5: 4.8
Before Sorting
n1: 0.500000,  :  n2: -1.100000  : n3: 2.200000  : n4: -3.400000  : n5: 4.800000
After Sorting
n1: -3.400000,  :  n2: -1.100000  : n3: 0.500000  : n4: 2.200000  : n5: 4.800000
$ 

*/
