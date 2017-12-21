/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int str_length_new(const char *s)
{
	int len = 0;

	while (*s != '\0') {
		len++;
		s++;
	}

	return len;
}
	
int str_length(const char s[])
{
	int len = 0;

	while (s[len])
		len++;
	return len;
}
	
int main(void)
{
	char str[128];

	printf("文字列を入力してください：");
	scanf("%s", str);

	printf("str_length    ：%d\n", str_length(str));
	printf("str_length_new：%d\n", str_length_new(str));

    return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：NaruhodoRyuichi
str_length    ：15
str_length_new：15
$ 

*/
