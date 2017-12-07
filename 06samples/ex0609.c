/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int encode(int ch, int key)
{
	int n;
	
	if ('A' <= ch && ch <= 'Z') {
		n = ch - 'A';
		n = (n + key) % 26;
		ch = n + 'A';
	} else if ('a' <= ch && ch <= 'z') {
		n = ch - 'a';
		n = (n + key) % 26;
		ch = n + 'a';
	}

	return ch;
}

int main(void)
{
	int ch, key;

	printf("キー(0以上26未満)を入力してください: ");
	scanf("%d", &key);
	
	while ((ch = getchar()) != EOF) {
		putchar(encode(ch, key));
	}

    return 0;
}

/*
  実行結果

$ ./a.out
キー(0以上26未満)を入力してください: 1

abcdefghijklmnopqrstuvwxyz
bcdefghijklmnopqrstuvwxyza
ABCDEFGHIJKLMNOPQRSTUVWXYZ
BCDEFGHIJKLMNOPQRSTUVWXYZA
$ ./a.out
キー(0以上26未満)を入力してください: 8

Nagoya City
Viowgi Kqbg
$ ./a.out
キー(0以上26未満)を入力してください: 18

Viowgi Kqbg
Nagoya City
$ 

*/
