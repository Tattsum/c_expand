/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int main(void)
{
	int		n;
	double	x;
	int		a[3];

	printf("n   のアドレス：%p\n", &n);
	printf("x   のアドレス：%p\n", &x);
	printf("a[0]のアドレス：%p\n", &a[0]);
	printf("a[1]のアドレス：%p\n", &a[1]);
	printf("a[2]のアドレス：%p\n", &a[2]);
	
    return 0;
}

/*
  実行結果

$ ./a.out
n   のアドレス：0x7ffeed513644
x   のアドレス：0x7ffeed513638
a[0]のアドレス：0x7ffeed51364c
a[1]のアドレス：0x7ffeed513650
a[2]のアドレス：0x7ffeed513654
$ ./a.out
n   のアドレス：0x7ffee162a644
x   のアドレス：0x7ffee162a638
a[0]のアドレス：0x7ffee162a64c
a[1]のアドレス：0x7ffee162a650
a[2]のアドレス：0x7ffee162a654
$ ./a.out
n   のアドレス：0x7ffeee733644
x   のアドレス：0x7ffeee733638
a[0]のアドレス：0x7ffeee73364c
a[1]のアドレス：0x7ffeee733650
a[2]のアドレス：0x7ffeee733654
$ 

*/
