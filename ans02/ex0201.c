/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

double bmi(double height, double weight)
{
	return (weight / (height/100 * height/100));
}

double stdweight(double height)
{
	return (22 * (height/100 * height/100));
}

int main(void)
{
	double height, weight;
	
	printf("身長(cm): "); scanf("%lf", &height);
	printf("体重(kg): "); scanf("%lf", &weight);

	printf("あなたの BMI は%.1fです\n", bmi(height, weight));
	printf("あなたの標準体重は%.1f(kg)です\n", stdweight(height));

    return 0;
}
