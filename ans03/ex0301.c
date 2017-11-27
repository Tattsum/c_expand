/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

int quotient(int m, int n)
{
    int q;

    q = 0;
    while (m >= n) {
	m = m - n;
	q = q + 1;
    }

    return q;
}

int main(void)
{
    int m, n;
	
    printf("整数 m: "); scanf("%d", &m);
    printf("整数 n: "); scanf("%d", &n);

    printf("%dを%dで割った商は%dです\n", m, n, quotient(m, n));

    return 0;
}
