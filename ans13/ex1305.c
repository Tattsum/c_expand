#include <stdio.h>
#define MAX_SIZE 100

struct seiseki {
    char name[20]; /* 名前 */
    int  jpn;      /* 国語 */
    int  math;     /* 数学 */
    int  eng;      /* 英語 */
    int  sum;      /* 合計 */
};

void swap_seiseki(struct seiseki *a, struct seiseki *b)
{
    struct seiseki tmp = *a;
    *a = *b;
    *b = tmp;
}

void bsort_jpn(struct seiseki a[], int size)
{
    int i, j;
    for (j = size - 1; j >= 1; j--) {  
        for (i = 0; i < j; i++) {
            if (a[i].jpn < a[i+1].jpn)
                swap_seiseki(&a[i], &a[i+1]);
        }
    }
}

void ssort_math(struct seiseki a[], int size)
{
    int i, j, max;
    for (j = 0; j < size-1; j++) {
        max = j;
        for (i = j+1; i < size; i++) {
            if (a[i].math > a[max].math)
                max = i;
        }
        swap_seiseki(&a[j], &a[max]);
    }
}

void ssort_eng(struct seiseki a[], int size)
{
    int i, j, max;
    for (j = 0; j < size-1; j++) {
        max = j;
        for (i = j+1; i < size; i++) {
            if (a[i].eng > a[max].eng)
                max = i;
        }
        swap_seiseki(&a[j], &a[max]);
    }
}

void bsort_sum(struct seiseki a[], int size)
{
    int i, j;
    for (j = size - 1; j >= 1; j--) {  
        for (i = 0; i < j; i++) {
            if (a[i].sum < a[i+1].sum)
                swap_seiseki(&a[i], &a[i+1]);
        }
    }
}

void get_seiseki(struct seiseki a[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("成績%d/%d\n", i + 1, size);
        printf("  名前: "); scanf("%s", a[i].name);
        printf("  国語: "); scanf("%d", &a[i].jpn);
        printf("  数学: "); scanf("%d", &a[i].math);
        printf("  英語: "); scanf("%d", &a[i].eng);
    }
}

void put_seiseki(struct seiseki a[], int size)
{
    int i;

    printf("名前                  国  数  英   計\n");
    for (i = 0; i < size; i++) {
        printf("%-20s %3d %3d %3d  %3d\n", a[i].name, a[i].jpn, a[i].math, a[i].eng, a[i].sum);
    }
}

void sum_seiseki(struct seiseki a[], int size)
{
    int i;

    for (i = 0; i < size; i++) {
        a[i].sum = a[i].jpn + a[i].math + a[i].eng;
    }
}

int main(void)
{
    struct seiseki array[] =
        {{"Sato",   81, 34, 67, 0},
         {"Sanaka", 72, 94, 88, 0},
         {"Takao",  60, 78, 62, 0},
         {"Mike",   96, 89, 93, 0},
         {"Masaki", 58, 46, 81, 0}};

    int size = 5;
    int horw;

    /*
    printf("データ数: ");
    scanf("%d", &size);

    get_seiseki(array, size);
    */

    sum_seiseki(array, size);
    
    printf("1) 国語, 2) 数学, 3) 英語, 4) 合計: ");
    scanf("%d", &horw);

    switch (horw) {
    case 1:
        bsort_jpn(array, size);
        break;
    case 2:
        ssort_math(array, size);
        break;
    case 3:
        ssort_eng(array, size);
        break;
    case 4:
        bsort_sum(array, size);
    }
    put_seiseki(array, size);

    return 0;
}
