/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void put_stars(int no)
{
	int i;
	for (i = 1; i <= no; i++)
		printf("*");
}

int main(void)
{
	int i, ch;
	int cnt[10] = { 0 };

	while ((ch = getchar()) != EOF) {
		if ('0' <= ch && ch <= '9') {
			cnt[ch - '0']++;
		}
	}

	printf("数字文字の出現回数\n");
	for (i = 0; i < 10; i++) {
		putchar('\'');
		putchar('0' + i);
		putchar('\'');
		printf(": ");
		put_stars(cnt[i]);
		printf("\n");
	}

    return 0;
}

/*
  実行結果

$ ./a.out
3.14159265358979323846
数字文字の出現回数
'0':
'1': **
'2': **
'3': ****
'4': **
'5': ***
'6': **
'7': *
'8': **
'9': ***
$ 

*/
