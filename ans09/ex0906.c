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

	ary_set(a, 5, 99);

	for (i = 0; i < 5; i++)
		printf("a[%d] = %d\n", i, a[i]);

    return 0;
}

/*
  実行結果

$ ./a.out
a[0] = 99
a[1] = 99
a[2] = 99
a[3] = 99
a[4] = 99
$ 

*/
