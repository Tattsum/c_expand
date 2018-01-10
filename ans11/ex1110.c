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

double heron(struct point p1, struct point p2, struct point p3)
{
	double a = dist(p1, p2);
	double b = dist(p2, p3);
	double c = dist(p3, p1);
	double s = (a + b + c) / 2.0;

	return sqrt(s * (s - a) * (s - b) * (s - c));
}

int main(void)
{
	struct point a, b, c;

	printf("Aの座標を入力:\n");
	a = input_point();
	printf("Bの座標を入力:\n");
	b = input_point();
	printf("Cの座標を入力:\n");
	c = input_point();
	printf("三角形ABCの面積: %.2f\n", heron(a, b, c));

	return 0;
}
