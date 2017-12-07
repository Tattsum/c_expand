/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int main(void)
{
	int ch;

	for (ch = 'a'; ch <= 'z'; ch++)
		putchar(ch);
	putchar('\n');

    return 0;
}

/*
  実行結果

$ ./a.out
abcdefghijklmnopqrstuvwxyz
$ 

*/
