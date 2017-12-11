/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define MAXSTRLEN 32

void str_copy(const char s[], char t[])
{
	int i;
	
	i = 0;
	while (s[i]) {
		t[i] = s[i];
		i++;
	}
	t[i] = s[i];
}

int main(void)
{
    char str1[MAXSTRLEN], str2[MAXSTRLEN];
    printf("文字列? ");
    scanf("%s", str1);

    str_copy(str1, str2);
    printf("str1: %s \n", str1);
    printf("str2: %s \n", str2);

    return 0;
}

/*
  実行結果

$ ./a.out
文字列? Nanzan-University
str1: Nanzan-University
str2: Nanzan-University
$

*/
