/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

int maxIntArray(int array[], int n)
{
	int max = array[0];
	int i;

	for (i = 1; i < n; i++)
		if (array[i] > max)
			max = array[i];

	return max;
}

int main(void)
{
	int i, j, ch;
	int cnt[10] = { 0 };
	int maxcnt;
	
	while ((ch = getchar()) != EOF) {
		if ('0' <= ch && ch <= '9') {
			cnt[ch - '0']++;
		}
	}

	maxcnt = maxIntArray(cnt, 10);
	
	printf("数字文字の出現回数\n\n");
	for (j = maxcnt; j > 0; j--) {
		for (i = 0; i < 10; i++) {
			if (cnt[i] >= j)
				printf("*  ");
			else
				printf("   ");
		}
		printf("\n");
	}
	for (i = 0; i < 10; i++) {
		printf("%d  ", i);
	}
	printf("\n");

    return 0;
}

/*
  実行結果

$ ./a.out
3.14159265358979323846
数字文字の出現回数

         *
         *     *           *
   *  *  *  *  *  *     *  *
   *  *  *  *  *  *  *  *  *
0  1  2  3  4  5  6  7  8  9
$ 

*/
