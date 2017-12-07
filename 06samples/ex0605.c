/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int main(void)
{
	int ch;
	int nc, nl, nd, na;

	nc = 0;
	nl = 0;
	nd = 0;
	na = 0;
	
	while ((ch = getchar()) != EOF) {
		nc++;
		if (ch == '\n') {
			nl++;
		}
		if ('0' <= ch && ch <= '9') {
			nd++;
		}
		if (('A' <= ch && ch <= 'Z') || ('a' <= ch && ch <= 'z')) {
			na++;
		}
	}

	printf("総文字数=%d, 行数=%d, 数字=%d, アルファベット=%d\n", nc, nl, nd, na);

    return 0;
}

/*
  実行結果

$ ./a.out < sample.txt
総文字数=3609, 行数=65, 数字=28, アルファベット=2941
$ 

*/
