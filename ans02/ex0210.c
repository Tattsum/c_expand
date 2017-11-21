/*
[氏名]
[学生番号]
*/
#include <stdio.h>

int main(void)
{
    int na, nb, nc;

    printf("三つの整数を入力してください\n");
    printf("整数A："); scanf("%d", &na);
    printf("整数B："); scanf("%d", &nb);
    printf("整数C："); scanf("%d", &nc);

    if (na == nb && nb == nc) {
	printf("三つの値は等しいです\n");
    } else if (na == nb || nb == nc || nc == na) {
	printf("二つの値が等しいです\n");
    } else {
	printf("三つの値は異なります\n");
    }

    return 0;
}
