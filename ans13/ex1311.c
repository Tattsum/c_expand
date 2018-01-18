#include <stdio.h>
#include <string.h>
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

/* horw: 並べかえのキー，ad: 昇順、降順の切り替え */
void bsort_seiseki(struct seiseki a[], int size, int horw, int ad)
{
    int i, j;
    int hantei;

    for (j = size - 1; j >= 1; j--) {  
        for (i = 0; i < j; i++) {
            switch (horw) {
            case 0: hantei = (strcmp(a[i].name, a[i+1].name) > 0); break;
            case 1: hantei = (a[i].jpn  > a[i+1].jpn);  break;
            case 2: hantei = (a[i].math > a[i+1].math); break;
            case 3: hantei = (a[i].eng  > a[i+1].eng);  break;
            case 4: hantei = (a[i].sum  > a[i+1].sum);  break;
            }
            if (ad) {
                hantei = !hantei;
            }

            if (hantei) {
                swap_seiseki(&a[i], &a[i+1]);
            }
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

int fread_seiseki(FILE *fp, struct seiseki a[], int size)
{
    int i = 0;
    while (fscanf(fp, "%s%d%d%d", a[i].name, &a[i].jpn, &a[i].math, &a[i].eng) == 4) {
        i++;
    }

    return i;
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
    struct seiseki array[MAX_SIZE];
    int size;
    int horw, ad;

    char fname[64];
    FILE *fp;

    printf("成績データファイル: ");
    scanf("%s", fname);

    if ((fp = fopen(fname, "r")) == NULL) {
        printf("ファイルを開けません。\n");
    }
    else {
        size = fread_seiseki(fp, array, size);

        fclose(fp);

        sum_seiseki(array, size);
    
        printf("0) 名前, 1) 国語, 2) 数学, 3) 英語, 4) 合計: ");
        scanf("%d", &horw);
        printf("0) 昇順, 1) 降順: ");
        scanf("%d", &ad);
        
        bsort_seiseki(array, size, horw, ad);

        put_seiseki(array, size);
    }

    return 0;
}
