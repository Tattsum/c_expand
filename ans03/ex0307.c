/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

int main(void)
{
    int width, height, i, j;
  
    printf("横幅：");
    scanf("%d", &width);
    printf("高さ：");
    scanf("%d", &height);

    for(i = 1; i <= height; i++) {
	for (j = 1; j <= width; j++) {
	    printf("*");
	}
	printf("\n");
    }
  
    return 0;
}
