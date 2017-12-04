/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

int min3(int a, int b, int c)
{
    int min = a;
    if (min > b) {
	min = b;
    }
    if (min > c) {
	min = c;
    }
    return min;
}

#define READ_VAR(x) do { printf(#x "=? "); scanf("%d", &x); } while(0)

int main(void)
{
    int a, b, c;

    READ_VAR(a);
    READ_VAR(b);
    READ_VAR(c);

    printf("小さい値は: %d\n", min3(a, b, c));

    return 0;
}

/*
  実行結果

$ ./a.out
私の名前は南山太郎です。
私の趣味は貯金です。
$

*/
