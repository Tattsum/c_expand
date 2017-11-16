/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int cube(int x)
{
    return x * x * x;
}

int main(void)
{
    int x;

    printf("x: ");
    scanf("%d", &x);

    printf("その数の3乗は%dです。\n", cube(x));

    return 0;
}
