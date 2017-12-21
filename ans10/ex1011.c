/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int is_upper(int ch)
{
	if ('A' <= ch && ch <= 'Z')
		return 1;
	else
		return 0;
}

int is_lower(int ch)
{
	if ('a' <= ch && ch <= 'z')
		return 1;
	else
		return 0;
}

int to_upper(int ch)
{
	if (is_lower(ch))
		return ch - 'a' + 'A';
	else
		return ch;
}

int to_lower(int ch)
{
	if (is_upper(ch))
		return ch - 'A' + 'a';
	else
		return ch;
}

void str_change(char *s)
{
	while (*s) {
		if (is_upper(*s))
			*s = to_lower(*s);
		else if (is_lower(*s))
			*s = to_upper(*s);
		else
			*s = '*';
		s++;
	}
}
	
int main(void)
{
	char str[128];
	
	printf("文字列を入力してください：");
	scanf("%s", str);

	str_change(str);

	printf("変換後：%s\n", str);

	return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：Yahoo!JAPAN
変換後：yAHOO*japan
$ 

*/
