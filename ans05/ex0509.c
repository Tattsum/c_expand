/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

int cube(int x)
{
    return x * x * x;
}

#define READ_VAR(x) do { printf(#x "=? "); scanf("%d", &x); } while(0)

int main(void)
{
    int x;

    READ_VAR(x);

    printf("%d^3 = %d\n", x, cube(x));

    return 0;
}

/*
  実行結果

$ ./a.out
私の名前は南山太郎です。
私の趣味は貯金です。
$

*/
