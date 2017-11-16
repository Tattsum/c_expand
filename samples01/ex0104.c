/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int cube(int x)
{
    return x * x * x;
}

int power9(int x)
{
    return cube(cube(x));
}

int main(void)
{
    int x;

    printf("整数を入力してください：");
    scanf("%d", &x);

    printf("その数の9乗は%dです。\n", power9(x));

    return 0;
}
