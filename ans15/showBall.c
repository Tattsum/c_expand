/* simple image display on X11 with Xlib
 * compile with -L/usr/X11R6/lib -lX11
 * by goto@it.nanzan-u.ac.jp
 * Sep 18, 2006
 *
 * 2011年5月プログラミング応用実習用に改訂
 * 2012年7月プログラミング応用実習用に改訂
 * 2014年7月プログラミング応用実習用に改訂
 * 2016年7月プログラミング応用実習用に改訂
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <X11/Xlib.h>

Display *display = NULL;
Window window;
XImage *ximage;
Visual *visual;
XSetWindowAttributes xswa;
Pixmap pixmap;
XEvent event;
int screen;
int depth;
GC gc;
XFontSet fs;

char drawstr[100];

unsigned int width, height;
unsigned long black, white; /* 黒と白のピクセル値 */
char *image; /* 画像バッファ */

int PutImage();

int InitWindow(unsigned int w, unsigned int h)
{
    char **mis_list;
    int    mis_count;
    char  *def_str;

    width = w;
    height = h;
    display = XOpenDisplay(NULL);
    visual = DefaultVisual(display, screen);
    screen = DefaultScreen(display);
    white  = WhitePixel(display, screen);
    black  = BlackPixel(display, screen);
    window = XCreateSimpleWindow(display, DefaultRootWindow(display),
                                 100, 50, width, height, 0, black, white);
    gc = XCreateGC(display, window, 0, NULL);
    XSetForeground(display, gc, black);
    XSetBackground(display, gc, white);
    depth = DefaultDepth(display, screen);

    pixmap = XCreatePixmap(display, window, width, height, depth);
    XSelectInput(display, window, KeyPressMask);
    XStoreName(display, window, "showBall");
    XMapWindow(display, window);

    /* 画像バッファ領域確保と初期化 */
    image = (char *)malloc(sizeof(char) * width * height * 4);
    memset(image, 255, width * height * 4);

    ximage = XCreateImage(display, visual, depth, ZPixmap, 0, image,
                          width, height, (depth<=16) ? depth : 32, 0);

    fs = XCreateFontSet(display, "-*-fixed-medium-r-normal--18-*0*0*",
                        &mis_list, &mis_count, &def_str);

    if (fs == NULL) {
        printf("Failed to create fontset\n");
        exit(-1);
    }

    PutImage();

    return depth;
}

/* スクリーン座標系の位置 x, y に色rgb で点描画 */ 
void DrawScrPixel(int x, int y, unsigned char r, unsigned char g, unsigned char b)
{
    image[(width * y + x) * 4 ]    = b; // B
    image[(width * y + x) * 4 + 1] = g; // G
    image[(width * y + x) * 4 + 2] = r; // R
    image[(width * y + x) * 4 + 3] = 0; // A
}

/* 文字列表示 */
void PutString( int x, int y, char str[] )
{
    XmbDrawString(display, pixmap, fs, gc, x, y, str, strlen(str));
}

/* int PutImage(unsigned char *image) */
int PutImage()
{
    // accept 24 bit RGB with width and height in InitWindow() only
    if (display == NULL) {
	fprintf(stderr, "InitWindow first!\n");
	return -1;
    }


    XPutImage(display, pixmap, gc, ximage, 0, 0, 0, 0, width, height);

    /* Draw velocity and accel */
    PutString(50, 20, drawstr);

    XCopyArea(display, pixmap, window, gc, 0, 0, width, height, 0, 0);

    XFlush(display);
    return 0;
}

void FreeWindow()
{
    XFreeFontSet(display, fs);
    XFreeGC(display, gc);
    XFreePixmap(display, pixmap);
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

#define WIDTH 800

int main(int argc, char *argv[])
{
    int i, j;
    int radius = 20;
    int width = WIDTH + radius * 4;
    int height = 4 * radius;
    int depth = 3;
    int cx = width + radius, cy = height - radius;	/* Initial position */
    char linebuf[80];
    double parms[5];
    double sim_time, position;
    double velocity, accel;
    double wall_position, playrate;
    struct timespec ts;
    struct timeval begin_tv, now_tv;
    double begin, now;

    char *infilename;
    FILE *infile;

    wall_position = 100;
    playrate = 1.0;
    infilename = "sim.txt";

    if (argc == 4) {
	wall_position = atof(argv[1]);
	playrate = atof(argv[2]);
	infilename = argv[3];
    }
    if (argc == 2) {
	playrate = atof(argv[2]);
    }

    infile = fopen(infilename, "r");
    if (infile == NULL) {
	printf("Can't open file: %s\n", infilename);
	exit(1);
    }


    /* fprintf(stderr, "Depth %d\n", InitWindow(width, height)); */
    InitWindow(width, height);

    gettimeofday(&begin_tv, NULL);
    begin = begin_tv.tv_sec + begin_tv.tv_usec / 1000000.0;

    while (fgets(linebuf, sizeof(linebuf), infile) != NULL) {
	static int display = 1;

        /* #から始まる行はコメントとして読み飛ばす */
	if (linebuf[0] == '#') {
	    continue;
	}
	sscanf(linebuf, "%lf %lf %lf %lf %lf",
	       &parms[0], &parms[1], &parms[2], &parms[3], &parms[4]);
	sim_time = parms[0];
	position = parms[1];
        velocity = parms[2];
        accel    = parms[3];
        /* cx = (int) (distance/max_distance*1000.0) - radius; *//* in pixel */
	cx = (int) ((double) position / wall_position * WIDTH) + radius;	/* in pixel */
        
	/* Paint window */
	if (display) {
            memset(image, 255, width * height * 4);

            /* Draw position 0 line*/ 
            for(i=0, j=radius*2; i<height; i++ ) {
                DrawScrPixel(j, i, 0, 0, 0);
            }

            /* Draw wall*/ 
            for(i=0; i<height; i++ ) {
              for(j=WIDTH+radius*2; j<WIDTH+radius*4; j++ ) {
                DrawScrPixel(j, i, 128, 128, 128);
              }
            }

            /* Draw a circle */
	    for (i = height - 2 * radius; i < height; i++) {
		for (j = cx - radius; j < cx + radius; j++) {
		    if ((j - cx) * (j - cx) + (i - cy) * (i - cy) <=
			radius * radius) {
                        DrawScrPixel(j, i, 255, 0, 0);
		    }
		}
            }

            /* Set velocity string */
            sprintf(drawstr, "t=%6.3f(s), pos=%7.3f(m), v=%5.1f(m/s), a=%5.1f(m/s)",
                    sim_time, position, velocity, accel);
            /*  puts(drawstr); */
            printf("t=%6.3f(s), pos=%7.3f(m), v=%5.1f(m/s), a=%5.1f(m/s)\r",
                    sim_time, position, velocity, accel);

	    PutImage();
	}

	gettimeofday(&now_tv, NULL);
	now = now_tv.tv_sec + now_tv.tv_usec / 1000000.0;
	if (now - begin < sim_time / playrate) {
	    display = 1;
	    ts.tv_sec = (int) (sim_time / playrate - (now - begin));
	    ts.tv_nsec = (int)
		(1000000000.0 *
		 (sim_time / playrate - (now - begin) - ts.tv_sec));
	    nanosleep(&ts, NULL);
	} else
	    display = 0;
    }

    ts.tv_sec = 100;
    ts.tv_nsec = 0;
    printf("\nEnd. Push any key>> \n");
    KeyPressWait(); /* ウィンドウ上でキー入力されるまで待機 */ 
    FreeWindow(); /* ウィンドウを解放 */

    return 0;
}
