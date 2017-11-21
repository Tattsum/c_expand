#include <stdio.h>

int kiriage(double v)
{
    int vint;

    vint = v;
    if (v > vint) {
	return (vint + 1);
    } else {
	return vint;
    }
}

int main(void)
{
    int		plan;
    int		price;
    int		tax;
    double  talk;
    double	data;

    price = 0;
    printf("通話料金プランを選んでください: ");
    scanf("%d", &plan);
    switch (plan) {
    case 1:
	price += 934;
	printf("通話時間(分)を入力してください: ");
	scanf("%lf", &talk);
	price += 42 * kiriage(talk);
	break;
    case 2:
	price += 2700;
	break;
    default:
	puts("そのようなプランはありません");
	return 1;
    }
    printf("データ量(GB)を入力してください: ");
    scanf("%lf", &data);
    if (data <= 2.0) {
	price += 3500;
    } else if (data <= 5.0) {
	price += 5000;
    } else if (data <= 10.0) {
	price += 8000;
    } else if (data <= 15.0) {
	price += 12500;
    } else if (data <= 20.0) {
	price += 16000;
    } else if (data <= 30.0) {
	price += 22500;
    } else {
	puts("データ量が多すぎます");
	return 1;
    }
    tax = price * 0.08;
	
    printf("料金は%d円です\n", price);
    printf("消費税は%d円です\n", tax);
    printf("税込料金は%d円です\n", price + tax);
	
    return 0;
}
