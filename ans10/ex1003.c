/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void str_copy(char *dst, const char *src)
{
	while (*src != '\0') {
		*dst = *src;
		src++;
		dst++;
	}
	*dst = '\0';
}
	
int main(void)
{
	char s1[128], s2[128], temp[128];

	printf("文字列を入力してください：");
	scanf("%s", s1);
	printf("文字列を入力してください：");
	scanf("%s", s2);

	puts("Before");
	printf("str1:%-15sstr2:%-15s\n", s1, s2);

	str_copy(temp, s1);
	str_copy(s1, s2);
	str_copy(s2, temp);
	
	puts("After");
	printf("str1:%-15sstr2:%-15s\n", s1, s2);

    return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：NATO
文字列を入力してください：nattou
Before
str1:NATO           str2:nattou
After
str1:nattou         str2:NATO
$ 

*/
