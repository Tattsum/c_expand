/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define MAXSTRLEN 32

int isupper(int ch)
{
	if ('A' <= ch && ch <= 'Z')
		return 1;
	else
		return 0;
}

void str_tolower(char str[])
{
	int i;
	
	i = 0;
	while (str[i]) {
		if (isupper(str[i]))
			str[i] += 'a' - 'A';
		i++;
	}
}

int main(void)
{
    char str[MAXSTRLEN];

    printf("文字列? ");
    scanf("%s", str);

    str_tolower(str);
    printf("小文字: %s\n", str);

    return 0;
}

/*
  実行結果

$ ./a.out
文字列? Nanzan-University
小文字: nanzan-university
$ ./a.out
文字列? UltraSuperBigMaximumGreatStrong
小文字: ultrasuperbigmaximumgreatstrong
$

*/
