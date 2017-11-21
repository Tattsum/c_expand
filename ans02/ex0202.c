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
	double b;
	
	printf("身長(cm): "); scanf("%lf", &height);
	printf("体重(kg): "); scanf("%lf", &weight);

	b = bmi(height, weight);
	if (b < 18.5)
		printf("あなたは低体重です\n");
	else if (b < 25.0)
		printf("あなたは普通です\n");
	else if (b < 35.0)
		printf("あなたは肥満です\n");
	else 
		printf("あなたは高度肥満です\n");

    return 0;
}
