/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int gcd2(int n, int m)
{
	if ( m == 0 ){
        return n;
    } else {
        return gcd2(m, n%m);
    }
}

int lcm2(int n, int m)
{
	return n * m / gcd2(n, m);
}

void gcdlcm3(int n1, int n2, int n3, int *gcd, int *lcm)
{
	int gcd12 = gcd2(n1, n2);
	int lcm12 = lcm2(n1, n2);

	*gcd = gcd2(gcd12, n3);
	*lcm = lcm2(lcm12, n3);
}
	
int main(void)
{
	int n1, n2, n3;
	int gcd, lcm;

	printf("Input n1: "); scanf("%d", &n1);
	printf("Input n2: "); scanf("%d", &n2);
	printf("Input n3: "); scanf("%d", &n3);

	gcdlcm3(n1, n2, n3, &gcd, &lcm);

	printf("最大公約数：%d\n", gcd);
	printf("最小公倍数：%d\n", lcm);
	
    return 0;
}

/*
  実行結果

$ ./a.out
Input n1: 10
Input n2: 15
Input n3: 20
最大公約数：5
最小公倍数：60
$ ./a.out
Input n1: 48
Input n2: 36
Input n3: 12
最大公約数：12
最小公倍数：144
$

*/
