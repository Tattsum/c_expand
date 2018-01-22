#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

struct student{
    int id;
    char name[20];
};
typedef struct student Student;

/* 配列 a[] のメンバ id に探索鍵(ID) x があるかどうかを逐次探索で判定する */
int ssearch_id(Student a[], int x, int size)
{
    int i = 0;
    while (1) {
        if (i == size)
            return -1; /* 探索失敗 */
        if (a[i].id == x)
            return  i; /* 探索成功 */
        i++;
    }
}

/* 配列 a[] のメンバ name に探索鍵(名前) x があるかどうかを逐次探索で判定する */
int ssearch_name(Student a[], char x[], int size)
{
    int i = 0;
    while (1) {
        if (i == size)
            return -1; /* 探索失敗 */
        if (!strcmp(a[i].name, x))
            return  i; /* 探索成功 */
        i++;
    }
}

/* 長さ size の配列 a[] の各要素にユーザからの入力値を格納する */
void get_students(Student a[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("a[%d]\n", i);
        printf("  ID  : ");  scanf("%d", &a[i].id);
        printf("  名前: ");  scanf("%s", a[i].name);
    }
}

/* 長さ size の配列 a[] を表示する */
void put_students(Student a[], int size)
{
    int i;

    printf("\n要素  ID  名前\n");
    for (i = 0; i < size; i++) {
        printf("a[%d]: %2d  %-15s\n", i, a[i].id, a[i].name);
    }
}

int main(void)
{
    int size, pos, key, horw;
    char keystr[20];
    Student a[MAX_SIZE];

    printf("データ数: ");  scanf("%d", &size);
    get_students(a, size);
    put_students(a, size);

    printf("1) ID, 2) 名前: ");
    scanf("%d", &horw);

    switch (horw) {
    case 1:
        printf("探索鍵(ID): ");  scanf("%d", &key);
        pos = ssearch_id(a, key, size);
        if (pos >= 0) {
            printf("探索鍵(ID) %d, 名前 %s が a[%d] に見つかりました\n", key, a[pos].name, pos);
        } else {
            printf("探索鍵(ID) %d は見つかりませんでした\n", key);
        }
        break;
    case 2:
        printf("探索鍵(名前): ");  scanf("%s", keystr);
        pos = ssearch_name(a, keystr, size);
        if (pos >= 0) {
            printf("探索鍵(名前) %s, ID %d が a[%d] に見つかりました\n", keystr, a[pos].id, pos);
        } else {
            printf("探索鍵(名前) %s は見つかりませんでした\n", keystr);
        }
        break;
    }

    return 0;
}
