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

void str_acount(const char str[], int cnt[])
{
	int i;
	
	i = 0;
	while (str[i]) {
		if (islower(str[i]))
			cnt[str[i] - 'a']++;
		if (isupper(str[i]))
			cnt[str[i] - 'A']++;
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

	str_acount(str, count);
	
	printf("アルファベットの出現回数\n");
	for (i = 0; i < NUM; i++) {
		putchar('\'');
		putchar('A' + i);
		putchar('\'');
		printf(": %d\n", count[i]);
	}
	
    return 0;
}

/*
  実行結果

$ ./a.out
文字列? UltraSuperBigMaximumGreatStrong
アルファベットの出現回数
'A': 3
'B': 1
'C': 0
'D': 0
'E': 2
'F': 0
'G': 3
'H': 0
'I': 2
'J': 0
'K': 0
'L': 1
'M': 3
'N': 1
'O': 1
'P': 1
'Q': 0
'R': 4
'S': 2
'T': 3
'U': 3
'V': 0
'W': 0
'X': 1
'Y': 0
'Z': 0
$

*/
