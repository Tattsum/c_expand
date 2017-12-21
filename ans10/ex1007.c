/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int str_chnum(const char *s, int c)
{
	int ct = 0;
	
	while (*s) {
		if (*s == c)
			ct++;
		s++;
	}

	return ct;
}

int main(void)
{
	char str[128];
	int	 ch;
	
	printf("文字を入力してください：");
	ch = getchar();
	printf("文字列を入力してください：");
	scanf("%s", str);
	
	printf("文字列\"%s\"中に文字", str);
	putchar(ch);
	printf("は%d個含まれます。\n", str_chnum(str, ch));

	return 0;
}

/*
  実行結果

$ ./a.out
文字を入力してください：n
文字列を入力してください：NanzanUniversity
文字列"NanzanUniversity"中に文字nは3個含まれます。
$ 

*/
