/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void str_copy(char *dst, const char *src)
{
	while ((*dst++ = *src++))
		;
}

void revWord(char *s)
{
	char temp[128];
	char *t = temp;

	str_copy(temp, s);

	while (*t)
		t++;
	t--;

	while (t >= temp) {
		*s = *t;
		s++;
		t--;
	}
}

void swapc(char *a, char *b)
{
	char temp = *a;
	*a = *b;
	*b = temp;
}
	
void revWord2(char *s)
{
	char *t = s;

	while (*t)
		t++;
	t--;

	while (t > s) {
		swapc(s, t);
		s++;
		t--;
	}
}

int main(void)
{
	char str[128];
	
	printf("文字列を入力してください：");
	scanf("%s", str);

	revWord(str);

	printf("変換後：%s\n", str);

	return 0;
}

/*
  実行結果

$ ./a.out
文字列を入力してください：www.google.co.jp
変換後：pj.oc.elgoog.www
$ 

*/
