/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	LENGTH	128

void put_rev_string(const char str[])
{
	int i;

	i = 0;
	while (str[i])
		i++;

	i--;
	while (i >= 0) {
		putchar(str[i]);
		i--;
	}
}

int main(void)
{
	char str[LENGTH];
	
    printf("文字列? ");
    scanf("%s", str);

	put_rev_string(str);
	putchar('\n');
	
    return 0;
}

/*
  実行結果

$ ./a.out
文字列? Nanzan
naznaN
$ ./a.out
文字列? Hello,World
dlroW,olleH
$

*/
