/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

#define	LENGTH	128
#define	NUM		26

int islower(int ch)
{
	if ('a' <= ch && ch <= 'z')
		return 1;
	else
		return 0;
}

int isupper(int ch)
{
	if ('A' <= ch && ch <= 'Z')
		return 1;
	else
		return 0;
}

int encode(int ch, int key)
{
	int ord;

	if (islower(ch)) {
		ord = ch - 'a';
		ord = (ord + key) % NUM;
		ch = ord + 'a';
	} else if (isupper(ch)) {
		ord = ch - 'A';
		ord = (ord + key) % NUM;
		ch = ord + 'A';
	}

	return ch;
}

void str_encode(char str[], int key)
{
	int i;
	
	i = 0;
	while (str[i]) {
		str[i] = encode(str[i], key);
		i++;
	}
}

int main(void)
{
    char str[LENGTH];
	int n;
	
    printf("文字列? ");
    scanf("%s", str);
    printf("整数? ");
    scanf("%d", &n);

	str_encode(str, n);
	
	printf("%s\n", str);

    return 0;
}

/*
  実行結果

$ ./a.out
文字列? Nanzan
整数? 1
Oboabo
$ ./a.out
文字列? Nanzan
整数? 2
Pcpbcp
$ ./a.out
文字列? Nanzan
整数? 13
Anamna
$ ./a.out
文字列? Anamna
整数? 13
Nanzan
$

*/
