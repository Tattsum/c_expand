/* 2D plot on X11 with Xlib
 * compile with -lX11
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>
#include <X11/Xlib.h>

Display *display = NULL;
Window window;
XImage *ximage;
Visual *visual;
Pixmap pixmap;
XEvent event;
int screen;
int depth;
GC gc;
XFontSet fs;

#define WIDTH  500
#define HEIGHT 500

#define MARGIN 50

#define X_MIN 0.0
#define X_MAX 1.0
#define Y_MIN 0.0
#define Y_MAX 1.0

int w_offset, h_offset;
unsigned int width, height; /* 画面全体 */
unsigned int draw_w, draw_h; /* 描画範囲 */
double x_min, x_max, y_min, y_max;

unsigned long black, white; /* 黒と白のピクセル値 */
char *image; /* 画像バッファ */

int PutImage();

int InitWindow(unsigned int w, unsigned int h)
{
    char **mis_list;
    int    mis_count;
    char  *def_str;

    w_offset = MARGIN;
    h_offset = MARGIN;
    draw_w = w - 2 * MARGIN;
    draw_h = h - 2 * MARGIN;
    width  = w;
    height = h;

    x_min = X_MIN;
    x_max = X_MAX;
    y_min = Y_MIN;
    y_max = Y_MAX;

    display = XOpenDisplay(NULL);
    screen = DefaultScreen(display);
    visual = DefaultVisual(display, screen);
    white  = WhitePixel(display, screen);
    black  = BlackPixel(display, screen);
    window = XCreateSimpleWindow(display, DefaultRootWindow(display),
                                 0, 0, width, height, 0, black, white);
    gc = XCreateGC(display, window, 0, NULL);
    XSetForeground(display, gc, black);
    XSetBackground(display, gc, white);
    depth = DefaultDepth(display, screen);
    pixmap = XCreatePixmap(display, window, width, height, depth);
    XSelectInput(display, window, KeyPressMask);
    XStoreName(display, window, "2dplot");
    XMapWindow(display, window);

    // 画像バッファ領域確保と初期化
    image = (char *)malloc(sizeof(char) * width * height * 4);
    memset(image, 255, width * height * 4);

    ximage = XCreateImage(display, visual, depth, ZPixmap, 0, image,
                          width, height, (depth<=16) ? depth : 32, 0);

    fs = XCreateFontSet(display, "-*-fixed-medium-r-normal--24-*0*0*",
                        &mis_list, &mis_count, &def_str);

    if (fs == NULL) {
        printf("Failed to create fontset\n");
        exit(-1);
    }

    PutImage();

    return depth;
}

/* 数学座標系からスクリーン座標系へ変換。範囲外のときは -1 を返す */
int math2scr_x( double x )
{
    int scr_x = w_offset + draw_w * (x - x_min) / (x_max - x_min);

    if ( 0 <= scr_x && scr_x < width )
        return scr_x;
    else
        return -1;
}

int math2scr_y( double y )
{
    int scr_y = h_offset + draw_h * (y_max - y) / (y_max - y_min);

    if ( 0 <= scr_y && scr_y < height )
        return scr_y;
    else
        return -1;
}

/* スクリーン座標系から数学座標系へ変換 */
double scr2math_x( int scr_x )
{
    return x_min + (scr_x - w_offset) * (x_max - x_min) / draw_w;
}

double scr2math_y( int scr_y )
{
    return y_max - (scr_y - h_offset) * (y_max - y_min) / draw_h;
}

// スクリーン座標系の位置 x, y に色rgb で点描画 */
void DrawScrPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    image[(width * y + x) * 4 ]    = b; // B
    image[(width * y + x) * 4 + 1] = g; // G
    image[(width * y + x) * 4 + 2] = r; // R
    image[(width * y + x) * 4 + 3] = 0; // A
}

/* 位置 x,y に色rgb で点描画 */
void DrawPixel(double x, double y, int r, int g, int b)
{
    int i = math2scr_y(y);
    int j = math2scr_x(x);

    DrawScrPixel(j, i, r, g, b);
}

/* 文字列表示 */
void PutString( int x, int y, char str[] )
{
    XmbDrawString(display, pixmap, fs, gc, x, y, str, strlen(str));
}

/* 座標軸描画 */
void DrawAxis()
{
    int i, j;

    /* y方向の描画範囲に y=0 があれば x軸描画 */
    if (y_min <= 0.0 && 0.0 <= y_max) {
        for (j=0, i=math2scr_y(0.0); j<width; j++) {
            DrawScrPixel(j, i, 0, 0, 0);
        }
        /* y方向の描画範囲に 1.0 が含まれる場合 */
        if (1.0 <= y_max) {
            for (j=math2scr_x(0.0), i=math2scr_y(1.0); j<math2scr_x(0.0)+draw_w/40; j++) {
                DrawScrPixel(j, i, 0, 0, 0);
            }
        }
    }

    /* 描画範囲に x=0 があれば y軸描画 */
    if (x_min <= 0.0 && 0.0 <= x_max) {
        for (i=0, j=math2scr_x(0.0); i<height; i++) {
            DrawScrPixel(j, i, 0, 0, 0);
        }
        /* x方向の描画範囲に 1.0 が含まれる場合 */
        if (1.0 <= x_max) {
            for (i=math2scr_y(0.0)-draw_h/40, j=math2scr_x(1.0); i<math2scr_y(0.0); i++) {
                DrawScrPixel(j, i, 0, 0, 0);
            }
        }
    }
}

/* int PutImage(unsigned char *image) */
int PutImage()
{
    /* accept 24 bit RGB with width and height in InitWindow() only */
    if (display == NULL) {
	fprintf(stderr, "InitWindow first!\n");
	return -1;
    }

    XPutImage(display, pixmap, gc, ximage, 0, 0, 0, 0, width, height);
    /*  XClearWindow(display, window); */
    DrawAxis(); /* 座標軸表示 */ 

    /*原点と座標軸に値表示 */
    PutString(w_offset - 15, height - h_offset + 25, "O"); /* 原点 */
    PutString(draw_w + w_offset - 5, height - h_offset + 25, "1"); /* x = 1 */
    PutString(w_offset - 15, h_offset + 10, "1"); /* y = 1 */

    XCopyArea(display, pixmap, window, gc, 0, 0, width, height, 0, 0);

    XFlush(display);
    return 0;
}

/* ウィンドウを解放 */
void FreeWindow()
{
    XFreeFontSet(display, fs);
    XFreePixmap(display, pixmap);
    XFreeGC(display, gc);
    XDestroyWindow(display, window);
    XCloseDisplay(display);

    free(image);

    return;
}

/* ウィンドウでキー入力されるまで待機 */
void KeyPressWait()
{
    while(1) {
        XNextEvent(display, &event);
        if (event.type == KeyPress) {
            break;
        }
    }
}
