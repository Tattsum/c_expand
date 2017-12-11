/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	LENGTH	128

int str_equal(const char s[], const char t[])
{
	int i;
	
	i = 0;
	while (s[i] && (s[i] == t[i]))
		i++;

	if (s[i] == t[i])
		return 1;
	else
		return 0;
}

int main(void)
{
    char str1[LENGTH], str2[LENGTH];
	
    printf("文字列1? ");
    scanf("%s", str1);
    printf("文字列2? ");
    scanf("%s", str2);

	if (str_equal(str1, str2))
		printf("等しい\n");
	else
		printf("等しくない\n");

    return 0;
}

/*
  実行結果

$ ./a.out
文字列1? Nanzan
文字列2? Nanzan
等しい
$ ./a.out
文字列1? Nanzan
文字列2? Nan
等しくない
$ ./a.out
文字列1? Nanz
文字列2? Nanzan
等しくない
$ ./a.out
文字列1? Nanzan
文字列2? nanzan
等しくない
$

*/
