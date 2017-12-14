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
	double da, db;

	puts("二つの実数を入力して下さい。");
	printf("実数Ａ："); scanf("%lf", &da);
	printf("実数Ｂ："); scanf("%lf", &db);

	swap(&da, &db);

	puts("これらの値を交換しました。");
	printf("実数Ａは%fです。\n", da);
	printf("実数Ｂは%fです。\n", db);
	
    return 0;
}

/*
  実行結果

$ ./a.out
二つの実数を入力して下さい。
実数Ａ：53.5
実数Ｂ：21.68
これらの値を交換しました。
実数Ａは53.500015です。
実数Ｂは21.679993です。
$ 

*/
