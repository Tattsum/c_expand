/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

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

	printf("文字列\"%s\"の長さは%dです。\n", str, str_length(str));

    return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：nanzan
文字列nanzanの長さは6です。
$ 

*/
