/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

int min2(int a, int b)
{
    if (a < b) {
	return a;
    } else {
	return b;
    }
}

#define READ_VAR(x) do { printf(#x "=? "); scanf("%d", &x); } while(0)

int main(void)
{
    int a, b;

    READ_VAR(a);
    READ_VAR(b);

    printf("小さい値は: %d\n", min2(a, b));

    return 0;
}

/*
  実行結果

$ ./a.out
私の名前は南山太郎です。
私の趣味は貯金です。
$

*/
