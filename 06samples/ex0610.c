/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int main(void)
{
	int i, ch;
	int dcnt[10] = { 0 };
	int Acnt[26] = { 0 };
	int acnt[26] = { 0 };
	int ns = 0;
	int nl = 0;
	int no = 0;
	
	while ((ch = getchar()) != EOF) {
		if ('0' <= ch && ch <= '9') {
			dcnt[ch - '0']++;
		} else if ('A' <= ch && ch <= 'Z') {
			Acnt[ch - 'A']++;
		} else if ('a' <= ch && ch <= 'z') {
			acnt[ch - 'a']++;
		} else if (ch == ' ' || ch == '\t') {
			ns++;
		} else if (ch == '\n') {
			nl++;
		} else {
			no++;
		}
	}

	for (i = 0; i < 10; i++) {
		putchar('\'');
		putchar('0' + i);
		putchar('\'');
		printf(": %d\n", dcnt[i]);
	}
	for (i = 0; i < 26; i++) {
		putchar('\'');
		putchar('A' + i);
		putchar('\'');
		printf(": %d\n", Acnt[i]);
	}
	for (i = 0; i < 26; i++) {
		putchar('\'');
		putchar('a' + i);
		putchar('\'');
		printf(": %d\n", acnt[i]);
	}
	printf("spaces: %d, lines: %d, others: %d\n", ns, nl, no);

    return 0;
}

/*
  実行結果

$ ./a.out < sample.txt
'0': 13
'1': 5
'2': 2
'3': 0
'4': 3
'5': 0
'6': 1
'7': 1
'8': 0
'9': 3
'A': 7
'B': 0
'C': 9
'D': 4
'E': 3
'F': 8
'G': 4
'H': 2
'I': 5
'J': 5
'K': 0
'L': 2
'M': 4
'N': 20
'O': 0
'P': 3
'Q': 0
'R': 0
'S': 9
'T': 13
'U': 6
'V': 0
'W': 6
'X': 0
'Y': 0
'Z': 0
'a': 260
'b': 17
'c': 77
'd': 92
'e': 317
'f': 60
'g': 68
'h': 119
'i': 255
'j': 2
'k': 9
'l': 116
'm': 51
'n': 287
'o': 224
'p': 41
'q': 3
'r': 162
's': 193
't': 252
'u': 91
'v': 32
'w': 37
'x': 6
'y': 44
'z': 16
spaces: 498, lines: 65, others: 77
$ 

*/
