/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void sumdiff(int n1, int n2, int sum, int diff)
{
	sum		= n1 + n2;
	diff	= (n1 > n2) ? n1 - n2 : n2 - n1;
}

int main(void)
{
	int		na, nb;
	int		wa = 0, sa = 0;

	puts("二つの整数を入力して下さい。");
	printf("整数Ａ："); scanf("%d", &na);
	printf("整数Ｂ："); scanf("%d", &nb);

	sumdiff(na, nb, wa, sa);

	printf("和は%dで差は%dです。\n", wa, sa);

    return 0;
}

/*
  実行結果

$ ./a.out
二つの整数を入力して下さい。
整数Ａ：4
整数Ｂ：10
和は0で差は0です。
$ ./a.out
二つの整数を入力して下さい。
整数Ａ：10
整数Ｂ：4
和は0で差は0です。
$ 

*/
