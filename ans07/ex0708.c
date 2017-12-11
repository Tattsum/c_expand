/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	LENGTH	128

int palindrome(const char str[])
{
	int head, tail;
	
	head = 0;
	tail = 0;
	while (str[tail])
		tail++;
	tail--;

	while (head < tail) {
		if (str[head] != str[tail])
			return 0;
		head++;
		tail--;
	}

	return 1;
}

int main(void)
{
    char str[LENGTH];
	
    printf("文字列? ");
    scanf("%s", str);

	if (palindrome(str))
		printf("\"%s\"は回文です。\n", str);
	else
		printf("\"%s\"は回文ではありません。\n", str);

    return 0;
}

/*
  実行結果

$ ./a.out
文字列? pop
"pop"は回文です。
$ ./a.out
文字列? madam
"madam"は回文です。
$ ./a.out
文字列? tomato
"tomato"は回文ではありません。
$

*/
