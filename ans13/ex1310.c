#include <stdio.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct point {
    int x;
    int y;
    int z;
} Point;

/* 個数 size の頂点座標 (x, y, z) にユーザからの入力値を格納する */
void get_points(Point points[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("頂点%d/%d：", i + 1, size);
        scanf("%d%d%d", &points[i].x, &points[i].y,  &points[i].z);
    }
}

/* Point型ポインタ変数 p と q の指す変数を入れ替える */
void swap_points(Point *p, Point *q)
{
    Point tmp = *p;
    *p = *q;
    *q = tmp;
}

/* p の原点からの距離の2乗を計算する */
int len_sq(Point p){
    return p.x*p.x + p.y*p.y + p.z*p.z;
}

/* 頂点 p1 が p2 よりも原点から遠い場合 1 を返す */
int greater_than(Point p1, Point p2)
{
    if (len_sq(p1) > len_sq(p2))
        return (1);
    else
        return (0);
}

/* 個数 size の頂点配列 points をバブルソートで原点からの距離の昇順に整列させる */
void bsort_points(Point points[], int size)
{
    int i, j;

    for (j = size - 1; j >= 1; j--)
        for (i = 0; i < j; i++)
            if (greater_than(points[i], points[i+1]))
                swap_points(&points[i], &points[i+1]);
}

/* 個数 size の頂点座標 p=(x, y, z) を表示する */
void put_points(Point points[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("(%3d, %3d, %3d), 原点からの距離: %5.1f\n",
               points[i].x, points[i].y, points[i].z, sqrt(len_sq(points[i])));
    }
}

int main(void)
{
    Point points[MAX_SIZE];
    int size;

    printf("頂点の個数を入力して下さい：");
    scanf("%d", &size);

    get_points(points, size);
    bsort_points(points, size);
    put_points(points, size);

    return (0);
}
