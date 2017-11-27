/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

int main(void)
{
    int principal, amount;
    double rate;
    int term;
    int i;
    
    printf("元金(円): "); scanf("%d", &principal);
    printf("年利率(%%): "); scanf("%lf", &rate);
    printf("預入期間(年): "); scanf("%d", &term);

    amount = principal;
    for (i = 1; i <= term; i = i + 1) {
	amount = amount * (1+rate/100);
	printf("%2d年目: %6d 円\n", i, amount);
    }

    return 0;
}
