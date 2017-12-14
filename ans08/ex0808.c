/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void swap(int *px, int *py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

int main(void)
{
	int na, nb;

	puts("二つの整数を入力して下さい。");
	printf("整数Ａ："); scanf("%d", &na);
	printf("整数Ｂ："); scanf("%d", &nb);

	swap(&na, &nb);

	puts("これらの値を交換しました。");
	printf("整数Ａは%dです。\n", na);
	printf("整数Ｂは%dです。\n", nb);
	
    return 0;
}

/*
  実行結果

$ ./a.out
二つの整数を入力して下さい。
整数Ａ：57
整数Ｂ：21
これらの値を交換しました。
整数Ａは21です。
整数Ｂは57です。
$ 

*/
