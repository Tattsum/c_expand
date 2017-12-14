/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void fouroperation(int n1, int n2, int *wa, int *sa, int *seki, double *shou)
{
	*wa		= n1 + n2;
	*sa		= n1 - n2;
	*seki	= n1 * n2;
	*shou	= (double)n1 / n2;
}

int main(void)
{
	int		na, nb;
	int		wa = 0, sa = 0, seki = 0;
	double 	shou = 0.0;

	printf("Input n1: "); scanf("%d", &na);
	printf("Input n2: "); scanf("%d", &nb);

	fouroperation(na, nb, &wa, &sa, &seki, &shou);

	printf("%d + %d = %d\n", na, nb, wa);
	printf("%d - %d = %d\n", na, nb, sa);
	printf("%d * %d = %d\n", na, nb, seki);
	printf("%d / %d = %f\n", na, nb, shou);

    return 0;
}

/*
  実行結果

$ ./a.out
Input n1: 4
Input n2: 10
4 + 10 = 14
4 - 10 = -6
4 * 10 = 40
4 / 10 = 0.400000
$ ./a.out
Input n1: 10
Input n2: 4
10 + 4 = 14
10 - 4 = 6
10 * 4 = 40
10 / 4 = 2.500000
$ 

*/
