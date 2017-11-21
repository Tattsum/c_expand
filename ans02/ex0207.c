/*
[氏名]
[学生番号]
*/
#include <stdio.h>

int main(void)
{
    int na, nb;

    printf("二つの整数を入力してください\n");
    printf("整数A："); scanf("%d", &na);
    printf("整数B："); scanf("%d", &nb);

    if (na % nb) {
	printf("BはAの約数ではありません\n");
    } else {
	printf("BはAの約数です\n");
    }

    return 0;
}
