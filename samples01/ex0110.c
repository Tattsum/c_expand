/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int na, nb;

    printf("二つの整数を入力してください。\n");
    printf("整数A: "); scanf("%d", &na);
    printf("整数B: "); scanf("%d", &nb);

    printf("Aの値はBの%f％です。\n", 100 * (double)na / nb);

    return 0;
}
