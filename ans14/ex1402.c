#include <stdio.h>
#define MAX_SIZE 100

/* ポインタ変数 x と y の指す整数を入れ替える */
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

/* 長さ size の配列 a[] をバブルソートで昇順に整列させる */
void bsort(int a[], int size)
{
    int i, j;

    for (j = size - 1; j >= 1; j--) {  
	for (i = 0; i < j; i++) {
	    if (a[i] > a[i+1]) {
		swap(&a[i], &a[i+1]);
	    }
	}
    }
}

/* 配列 a[] に探索鍵 x があるかどうかを二分探索で判定する */
int bsearch(int a[], int p, int q, int x)
{
    int t = (p + q) / 2;

    if (p > q) {     /* 見つからなかった */
        return -1;
    }
    if (a[t] == x) { /* 見つけた */
        return  t;
    }
    if (a[t] > x) {
        q = t - 1;
    } else {
        p = t + 1;
    }
    return bsearch(a, p, q, x);
}

/* 長さ size の配列 a[] の各要素にユーザからの入力値を格納する */
void get_array(int a[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("a[%d]: ", i);  scanf("%d", &a[i]);
    }
}

/* 長さ size の配列 a[] を表示する */
void put_array(int a[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    putchar('\n');
}

int main(void)
{
    int a[MAX_SIZE], size, key, pos;

    printf("データ数: ");  scanf("%d", &size);
    get_array(a, size);
    bsort(a, size);
    put_array(a, size);

    printf("探索鍵: ");  scanf("%d", &key);
    pos = bsearch(a, 0, size-1, key);
    if (pos >= 0){
        printf("探索鍵 %d が a[%d] に見つかりました\n", key, pos);
    } else {
        printf("探索鍵 %d は見つかりませんでした\n", key);
    }

    return 0;
}
