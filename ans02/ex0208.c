/*
[氏名]
[学生番号]
*/
#include <stdio.h>

int main(void)
{
    int na, nb, diff;

    printf("二つの整数を入力してください\n");
    printf("整数A："); scanf("%d", &na);
    printf("整数B："); scanf("%d", &nb);

    diff = na - nb;

    if (-10 <= diff && diff <= 10) {
	printf("それらの差は10以下です\n");
    } else {
	printf("それらの差は11以上です\n");
    }
    
    return 0;
}
