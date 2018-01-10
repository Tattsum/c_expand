#include <stdio.h>
#include <math.h>

struct point {
	double x;
	double y;
};

struct point input_point(void)
{
	struct point p;

	printf("X座標: ");
	scanf("%lf", &p.x);
	printf("Y座標: ");
	scanf("%lf", &p.y);

	return p;
}

double dist(struct point p1, struct point p2)
{
	return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y - p1.y)*(p2.y - p1.y));
}


int main(void)
{
	struct point a, b;

	printf("Aの座標を入力:\n");
	a = input_point();
	printf("Bの座標を入力:\n");
	b = input_point();
	printf("線分ABの長さ: %.2f\n", dist(a, b));

	return 0;
}
