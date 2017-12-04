/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

void put_spaces(int n)
{
    int i;
    for (i = 1; i <= n; i++) {
	printf(" ");
    }
}

void put_stars(int n)
{
    int i;
    for (i = 1; i <= n; i++) {
	printf("*");
    }
}

void draw_rectangle(int height, int width)
{
    int i;

    printf("\n");

    /* 1行目 */
    put_stars(width);
    printf("\n");

    /* 2〜height-1行目 */
    for (i = 1; i < height - 1; i++) {
	put_stars(1);
	put_spaces(width-2);
	if (width > 1) {
	    put_stars(1);
	}
	printf("\n");
    }

    /* height行目 */
    if (height > 1) {
	put_stars(width);
	printf("\n");
    }
    
    printf("\n");
}


int main(void)
{
    int h, w;

    printf("高さ: "); scanf("%d", &h);
    printf("幅: "); scanf("%d", &w);

    draw_rectangle(h, w);

    return 0;
}

/*
  実行結果

$ ./a.out
私の名前は南山太郎です。
私の趣味は貯金です。
$

*/
