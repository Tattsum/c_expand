/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

char *str_chr(const char *s, int c)
{
	while (*s) {
		if (*s == c)
			return (char*)s;
		s++;
	}

	return NULL;
}

int main(void) {
	
    char st1[100];
    char *point;

    printf("文字列1を入力してください：");
    scanf("%s",st1);   

    point = str_chr( st1, 'a');

    if (point != NULL) {
        printf("先頭の'a'以降の文字列：%s\n", point);
    }else{
        printf("'a'は出現しません。\n");
    }
    return 0;

}

/*
  実行結果

$ ./a.out
文字列1を入力してください：NanzanUniversity
先頭の'a'以降の文字列：anzanUniversity
$ ./a.out
文字列1を入力してください：MeijoUniversity
'a'は出現しません。
$ 

*/
