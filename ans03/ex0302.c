/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

int main(void)
{
    int n;
    int i, sumeven, sumodd;
	
    printf("整数 n: "); scanf("%d", &n);

    sumeven = 0;
    sumodd = 0;
    for (i = 1; i <= n; i = i + 1) {
	if (i % 2 == 0) {
	    sumeven = sumeven + i;
	} else {
	    sumodd = sumodd + i;
	}
    }

    printf("1から%dまでの偶数の和は%d, 奇数の和は%dです\n", n, sumeven, sumodd);
	
    return 0;
}
