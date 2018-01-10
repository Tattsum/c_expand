/*
 * 教科書 p.322 List12-8
 * （旧教科書 p.286 List12-10）
 */
/*
  2点間の距離を求める
*/

#include <math.h>
#include <stdio.h>

#define sqr(n)	((n) * (n))		/* 二乗値を求める */

typedef struct {		/*=== 点 === */
	double	x;		/* X座標 */
	double	y;		/* Y座標 */
} Point;

/*--- 点paと点pbの距離を返す ---*/
double distance_of(Point pa, Point pb)
{
	return sqrt(sqr(pa.x - pb.x) + sqr(pa.y - pb.y));
}

int main(void)
{
	Point crnt, dest;

	printf("現在地のX座標: ");		scanf("%lf", &crnt.x);
	printf("        Y座標: ");		scanf("%lf", &crnt.y);
	printf("目的地のX座標: ");		scanf("%lf", &dest.x);
	printf("        Y座標: ");		scanf("%lf", &dest.y);

	printf("目的地までの距離は%.2fです。\n", distance_of(crnt, dest));
	
	return 0;
}
