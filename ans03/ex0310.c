/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

int main(void)
{
    int no, i, j;
  
    printf("1辺：");
    scanf("%d", &no);

    for(i = 1; i <= no; i++) {
	for (j = 1; j <= no - i; j++) {
	    printf(" ");
	}
	for (j = 1; j <= i; j++) {
	    printf("*");
	}
	printf("\n");
    }
  
    return 0;
}
