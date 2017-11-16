/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int height;
    double weight;

    printf("身長を入力してください：");
    scanf("%d", &height);

    weight = (height - 100) * 0.9;

    printf("標準体重は%.1fです。\n", weight);

    return 0;
}
