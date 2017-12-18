/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>

void ary_set(int v[], int n, int val)
{
	int i;

	for (i = 0; i < n; i++) {
		v[i] = val;
	}
}

int main(void)
{
	int		i;
	int		a[] = {1, 2, 3, 4, 5};

	ary_set(&a[2], 2, 99);

	for (i = 0; i < 5; i++)
		printf("a[%d] = %d\n", i, a[i]);

    return 0;
}

/*
  実行結果

$ ./a.out
a[0] = 1
a[1] = 2
a[2] = 99
a[3] = 99
a[4] = 5
$ 

*/

/*
  実行結果の理由

  &a[2] は配列aの添字2となる要素をさすポインタだから、
  ary_set( &a[2], 2, 99); という呼び出し文は、
  配列aの添字2となる要素を先頭として 2個分の要素に指定された値99を代入する操作を意味する。
  以上の理由より、上記のような実行結果となる。

*/
