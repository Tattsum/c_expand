#include <stdio.h>
#define MAX_SIZE 100

/* 配列 a[] に探索鍵 x があるかどうかを逐次探索で判定する */
int ssearch(int a[], int x, int size)
{
    int i = 0;
    while (1) {
        if (i  == size)
            return -1; /* 探索失敗 */
        if (a[i] == x)
            return  i; /* 探索成功 */
        i++;
    }
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
    put_array(a, size);

    printf("探索鍵: ");  scanf("%d", &key);
    pos = ssearch(a, key, size);
    if (pos >= 0) {
        printf("探索鍵 %d が a[%d] に見つかりました\n", key, pos);
    } else {
        printf("探索鍵 %d は見つかりませんでした\n", key);
    }

    return 0;
}
