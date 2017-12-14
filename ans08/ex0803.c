/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int gcd(int n, int m)
{
	if ( m == 0 ){
        return n;
    } else {
        return gcd(m, n%m);
    }
}

void gcdlcm(int n1, int n2, int *gcdv, int *lcmv)
{
	*gcdv = gcd(n1, n2);
	*lcmv = n1 * n2 / *gcdv;
}

int main(void)
{
	int n1, n2;
	int gcd, lcm;

	printf("Input n1: "); scanf("%d", &n1);
	printf("Input n2: "); scanf("%d", &n2);

	gcdlcm(n1, n2, &gcd, &lcm);

	printf("最大公約数：%d\n", gcd);
	printf("最小公倍数：%d\n", lcm);
	
    return 0;
}

/*
  実行結果

$ ./a.out
Input n1: 10
Input n2: 15
最大公約数：5
最小公倍数：30
rhea:ans08 tachi$ ./a.out
Input n1: 48
Input n2: 36
最大公約数：12
最小公倍数：144
$ 

*/
