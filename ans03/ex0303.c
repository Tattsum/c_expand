/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

int main(void)
{
    int n, max;

    max = 0;
    
    while (1) {
	printf("整数 (0以下で終了): ");
	scanf("%d", &n);
	if (n <= 0) {
	    break;
	}
	if (n > max) {
	    max = n;
	}
    }

    printf("最大値は %d\n", max);

    return 0;
}
