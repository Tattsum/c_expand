#include <stdio.h>

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

void print_point(struct point p)
{
	printf("( %.2f, %.2f )\n", p.x, p.y);
}

int main(void)
{
	struct point a, b, m;
	
	printf("座標 A\n");
	a = input_point();
	printf("座標 B\n");
	b = input_point();
	
	m.x=(a.x+b.x)/2; m.y=(a.y+b.y)/2;
	
	printf("座標 A と B の中点: ");
	print_point(m);

    return 0;
}
