/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	LENGTH	128
#define	NUM		10

int isdigit(int ch)
{
	if ('0' <= ch && ch <= '9')
		return 1;
	else
		return 0;
}

void str_dcount(const char str[], int cnt[])
{
	int i;
	
	i = 0;
	while (str[i]) {
		if (isdigit(str[i]))
			cnt[str[i] - '0']++;
		i++;
	}
}

int main(void)
{
	char str[LENGTH];
	int	count[NUM] = { 0 };
	int i;
	
    printf("文字列? ");
    scanf("%s", str);

	str_dcount(str, count);
	
	printf("数字文字の出現回数\n");
	for (i = 0; i < NUM; i++) {
		putchar('\'');
		putchar('0' + i);
		putchar('\'');
		printf(": %d\n", count[i]);
	}
	
    return 0;
}

/*
  実行結果

$ ./a.out
文字列? 2017/04/06-2017/05/31:2017/06/07-2017/07/28:2017/09/16-2017/11/10:2017/11/17-2018/01/27
数字文字の出現回数
'0': 17
'1': 17
'2': 10
'3': 1
'4': 1
'5': 1
'6': 3
'7': 11
'8': 2
'9': 1
$

*/
