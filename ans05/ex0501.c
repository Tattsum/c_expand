/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

double areaTrapezoid(int ub, int lb, int height)
{
    return (ub + lb) * height / 2.0;
}

int main(void)
{
    int ub, lb, height;
    printf("上底の長さ: "); scanf("%d", &ub);
    printf("下底の長さ: "); scanf("%d", &lb);
    printf("高さ: "); scanf("%d", &height);

    printf("台形の面積: %f\n", areaTrapezoid(ub, lb, height));

    return 0;
}

/*
  実行結果

$ ./a.out
$

*/
