/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int na, nb;

    printf("二つの整数を入力してください。\n");
    printf("整数a: "); scanf("%d", &na);
    printf("整数b: "); scanf("%d", &nb);

    printf("それらの和は%dで積は%dです。\n", na+nb, na*nb);

    return 0;
}
