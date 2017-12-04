/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

#define MAX_SIZE 20

void intary_rcpy(int v1[], const int v2[], int n)
{
    int i;
    for (i = 0; i < n; i++) {
	v1[n-1-i] = v2[i];
    }
}

int main(void)
{
    int i, n;
    int v1[MAX_SIZE], v2[MAX_SIZE];
	
    printf("データ数(最大 %d まで)? ", MAX_SIZE); scanf("%d", &n);
    if (n > MAX_SIZE) {
	fprintf(stderr, "最大値を越えています。\n");
	return 1;
    }
    for (i = 0; i < n; i++) {
	printf("v2[%d]=? ", i); scanf("%d", &v2[i]);
    }

    intary_rcpy(v1, v2, n);

    for (i = 0; i < n; i++) {
	printf("v1[%d] = %d\n", i, v1[i]);
    }

    return 0;
}

/*
  実行結果

$ ./a.out
私の名前は南山太郎です。
私の趣味は貯金です。
$

*/
