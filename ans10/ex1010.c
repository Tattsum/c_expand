/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int ispalindrome(char *s)
{
	char *t = s;

	while (*t)
		t++;

	t--;
	while (s < t) {
		if (*s != *t)
			return 0;
		s++;
		t--;
	}

	return 1;
}

int main(void)
{
	char str[128];
	
	printf("Input word:");
	scanf("%s", str);

	if (ispalindrome(str))
		printf("%s は回文です。\n", str);
	else
		printf("%s は回文ではありません。\n", str);

	return 0;
}

/*
  実行結果

$ ./a.out
Input word:AKASAKA
AKASAKA は回文です。
$ ./a.out
Input word:ASAKUSA
ASAKUSA は回文ではありません。
$ ./a.out
Input word:redivider
redivider は回文です。
$ 

*/
