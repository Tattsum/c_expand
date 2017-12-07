/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

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
		printf(": %d\n", cnt[i]);
	}

    return 0;
}

/*
  実行結果

$ ./a.out
466-8673
(052)832-3111
数字文字の出現回数
'0': 1
'1': 3
'2': 2
'3': 3
'4': 1
'5': 1
'6': 3
'7': 1
'8': 2
'9': 0
$ 

*/
