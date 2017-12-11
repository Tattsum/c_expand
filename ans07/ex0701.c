/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	LENGTH	128

int str_length(const char str[])
{
	int len = 0;

	while (str[len])
		len++;

	return len;
}

int main(void)
{
	char str[LENGTH];
	
    printf("文字列? ");
    scanf("%s", str);

	printf("\"%s\"の長さは %d.\n", str, str_length(str));
	
    return 0;
}

/*
  実行結果

$ ./a.out
文字列? Nanzan-University
"Nanzan-University"の長さは 17.
$ ./a.out
文字列? UltraSuperBigMaximumGreatStrong
"UltraSuperBigMaximumGreatStrong"の長さは 31.
$

*/
