/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int no;

    printf("整数を入力してください：");
    scanf("%d", &no);

    printf("その数の3乗は%dです。\n",  no * no * no);

    return 0;
}
