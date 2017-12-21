/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int is_alpha(char ch)
{
	if ('a' <= ch && ch <= 'z')
		return 1;
	else
		return 0;
}

int count_alpha_small(char *s)
{
	int ct = 0;

	while (*s) {
		if (is_alpha(*s))
			ct++;
		s++;
	}

	return ct;
}
	
int main(void)
{
	char str[128];

	printf("文字列を入力してください：");
	scanf("%s", str);

	printf("小文字のアルファベット：%d文字\n", count_alpha_small(str));
	
	return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：NanzanUniversity
小文字のアルファベット：14文字
$ 

*/
