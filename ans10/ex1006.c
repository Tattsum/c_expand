/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char str[128];
	
	printf("文字列を入力してください：");
	scanf("%s", str);

	printf("整数に変換すると%dです。\n", atoi(str));

	return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：123
整数に変換すると123です。
$ 

*/
