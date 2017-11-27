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

    for(i = no; i >= 1 ; i--) {
	for (j = 1; j <= i; j++) {
	    printf("*");
	}
	printf("\n");
    }
  
    return 0;
}
