/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int is_digit(int ch)
{
	if ('0' <= ch && ch <= '9')
		return 1;
	else
		return 0;
}

void del_digit(char *str)
{
	char *p = str;
	
	while (*str) {
		if (!is_digit(*str)) {
			*p = *str;
			p++;
		}
		str++;
	}
	*p = *str;
}

int main(void)
{
	char str[128];
	
	printf("文字列を入力してください：");
	scanf("%s", str);

	puts("数字文字を削除");
	del_digit(str);

	printf("%s\n", str);

	return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：2017/12/21,16:45
数字文字を削除
//,:
$ 

*/
