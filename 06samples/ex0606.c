/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int main(void)
{
	int i, ch;
	int cnt[26] = { 0 };

	while ((ch = getchar()) != EOF) {
		if ('A' <= ch && ch <= 'Z') {
			cnt[ch - 'A']++;
		}
		if ('a' <= ch && ch <= 'z') {
			cnt[ch - 'a']++;
		}
	}

	for (i = 0; i < 26; i++) {
		putchar('\'');
		putchar('A' + i);
		putchar('\'');
		printf(": %d\n", cnt[i]);
	}

    return 0;
}

/*
  実行結果

$ ./a.out < sample.txt
'A': 267
'B': 17
'C': 86
'D': 96
'E': 320
'F': 68
'G': 72
'H': 121
'I': 260
'J': 7
'K': 9
'L': 118
'M': 55
'N': 307
'O': 224
'P': 44
'Q': 3
'R': 162
'S': 202
'T': 265
'U': 97
'V': 32
'W': 43
'X': 6
'Y': 44
'Z': 16
$ 

*/
