/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int wa(int n1, int n2)
{
    return (n1+n2);
}

int seki(int n1, int n2)
{
    return (n1*n2);
}

int main(void)
{
    int na, nb;

    printf("二つの整数を入力してください。\n");
    printf("整数a: "); scanf("%d", &na);
    printf("整数b: "); scanf("%d", &nb);

    printf("それらの和は%dで積は%dです。\n", wa(na, nb), seki(na, nb));

    return 0;
}
