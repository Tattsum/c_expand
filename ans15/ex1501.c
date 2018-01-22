#include <stdio.h>
#include <stdlib.h> /* rand() */

#define WIDTH  500
#define HEIGHT 500

/* 2dplot.c で定義した関数のプロトタイプ宣言 */
void InitWindow(int w, int h);  /* 指定の幅、高さでウィンドウを初期化 */
void DrawAxis(); /* 座標軸の描画 */
void DrawPixel(double x, double y, int r, int g, int b); /* 指定座標(x,y) に指定色 (0<=r,g,b<=255) で点描画 */
void PutImage(); /* ウィンドウを更新 */
void PutString( int x, int y, char str[] ); /* 指定座標(x,y) に文字列 str 表示 */
void FreeWindow(); /* ウィンドウを解放 */
void KeyPressWait(); /* ウィンドウでキー入力されるまで待機 */

/* [0,1)の乱数を生成 */
double myrand(void)
{
    return rand() / (RAND_MAX + 1.0);
}

/* 単位半径の四分円の内に点があるかの判定 */
int isarea(double x, double y)
{
    /*    return  y < sqrt(1.0 - x * x); */
    return  x * x + y * y < 1.0; /* sqrt() 使用禁止 */
}

int main(void)
{
    int i;

    int count, max, step;
    double x, y;

    printf("試行回数 > ");
    scanf("%d", &max);

    if (max >= 10000) {
        step = max / 10000; /* 試行回数全体の 1/10000 ごとに途中経過を描画 */
    }
    else {
        step = 1;
    }

    InitWindow(WIDTH, HEIGHT); /* ウィンドウの初期化 */

    for (i=1, count=0; i<=max; i++) {
        x = myrand();
        y = myrand();

        if (isarea(x,y)) {
            count++;
            DrawPixel(x, y, 0, 0, 255); /* 円内部を青の点で描画 */
        }
        else {
            DrawPixel(x, y, 255, 0, 0); /* 円外部を赤の点で描画 */
        }

        /* step間隔ごとにウィンドウを更新 */
        if (i % step == 0 ) {
            PutImage(); /* ウィンドウの更新 */
            printf("in / out: %8d / %8d\r", count, i);
        }
    }
    PutImage(); /* ウィンドウの更新 */
    printf("\n");

    printf("π: %f\n", (double) count * 4.0 / (double) max);
    printf("End. Push any key>> \n");

    KeyPressWait(); /* ウィンドウ上でキー入力されるまで待機 */ 
    FreeWindow(); /* ウィンドウを解放 */

    return 0;
}
