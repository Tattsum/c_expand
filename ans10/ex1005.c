/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void str_cat(char *s1, const char *s2)
{
	while (*s1)
		s1++;
	while (*s2) {
		*s1 = *s2;
		s1++;
		s2++;
	}
	*s1 = *s2;
}

int main(void)
{
	char st1[128], st2[128], st3[128], result[128];
	char *p = result;
	
	printf("文字列を入力してください：");
	scanf("%s", st1);
	printf("文字列を入力してください：");
	scanf("%s", st2);
	printf("文字列を入力してください：");
	scanf("%s", st3);

	*p = '\0';
	str_cat(result, st1);
	str_cat(result, st2);
	str_cat(result, st3);
	
	printf("連結した結果:%s\n", result);
	printf("文字列1     :%s\n", st1);
	printf("文字列2     :%s\n", st2);
	printf("文字列3     :%s\n", st3);
	
	return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：One
文字列を入力してください：Two
文字列を入力してください：Three
連結した結果:OneTwoThree
文字列1     :One
文字列2     :Two
文字列3     :Three
$ 

*/
