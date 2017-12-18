/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	N		10
#define	STLEN	1000

void ary_set(int a[], int n, int val)
{
	int i;

	for (i = 0; i < n; i++) {
		a[i] = val;
	}
}

void ary_init(int a[], int n)
{
	ary_set(a, n, 0);
}

int is_digit(char ch)
{
	if ('0' <= ch && ch <= '9')
		return 1;
	else
		return 0;
}

void str_dcount(const char str[], int cnt[])
{
	int i;

	i = 0;
	while (str[i]) {
		if (is_digit(str[i]))
			cnt[str[i] - '0']++;
		i++;
	}
}

int main(void)
{
	int		ct[N];
	char	str[STLEN];
	int		i;
	
	printf("文字列を入力してください：");
	scanf("%s", str);

	ary_init(ct, N);
	str_dcount(str, ct);

	puts("数字文字の出現回数");
	for (i = 0; i < N; i++) {
		putchar('\'');
		putchar(i + '0');
		putchar('\'');
		printf(": %d\n", ct[i]);
	}

    return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：2017/12/18(16:45)
数字文字の出現回数
'0': 1
'1': 4
'2': 2
'3': 0
'4': 1
'5': 1
'6': 1
'7': 1
'8': 1
'9': 0
$ ./a.out
文字列を入力してください：0123456789abcdefghijklmnopqrstuvwxyz0123456789
数字文字の出現回数
'0': 2
'1': 2
'2': 2
'3': 2
'4': 2
'5': 2
'6': 2
'7': 2
'8': 2
'9': 2
$ 

*/
