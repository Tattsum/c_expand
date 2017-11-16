/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int sum(int n)
{
    int i;
    int total;

    total = 0;
    for (i = 0; i <= n; i = i + 1) {
    	total = total + i;
    }
    
    /* while 
    total = 0;
    i = 0;
    while (i <= n) {
	total = total + i;
	i = i + 1;
    }
    */
    
    return total;
}

int main(void)
{
    int i, n;

    printf("n: ");
    scanf("%d", &n);

    for (i = 0; i <= n; i = i + 1) {
        printf("sum(%2d) = %3d\n", i, sum(i));
    }

    /* while 
    i = 0;
    while (i <= n) {
        printf("sum(%2d) = %3d\n", i, sum(i));
        i = i + 1;
    }
    */
    
    return 0;
}
