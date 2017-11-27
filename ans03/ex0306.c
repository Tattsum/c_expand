/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

int main(void)
{
    int i, no;
  
    printf("横幅：");
    scanf("%d", &no);
    
    for(i = 1; i <= no; i++) {
	printf("*");
    }
    printf("\n");
  
    return 0;
}
