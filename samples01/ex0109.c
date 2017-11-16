/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int		n1, n2, n3, n4, n5, n6;
    double	d1, d2, d3, d4, d5, d6;

    n1 = 5   / 2;
    n2 = 5.0 / 2.0;
    n3 = 5.0 / 2;
    n4 = 5   / 2.0;

    d1 = 5   / 2;
    d2 = 5.0 / 2.0;
    d3 = 5.0 / 2;
    d4 = 5   / 2.0;

    printf("定数\n");
    printf("n1 = 5   / 2   = %d\n", n1);
    printf("n2 = 5.0 / 2.0 = %d\n", n2);
    printf("n3 = 5.0 / 2   = %d\n", n3);
    printf("n4 = 5   / 2.0 = %d\n", n4);

    printf("d1 = 5   / 2   = %f\n", d1);
    printf("d2 = 5.0 / 2.0 = %f\n", d2);
    printf("d3 = 5.0 / 2   = %f\n", d3);
    printf("d4 = 5   / 2.0 = %f\n", d4);

    n5 = 5;   n6 = 2;
    d5 = 5.0; d6 = 2.0;

    n1 = n5 / n6;
    n2 = d5 / d6;
    n3 = d5 / n6;
    n4 = n5 / d6;

    d1 = n5 / n6;
    d2 = d5 / d6;
    d3 = d5 / n6;
    d4 = n5 / d6;

    printf("\n変数\n");	
    printf("n5 = 5;   n6 = 2;\n");
    printf("d5 = 5.0; d6 = 2.0;\n");

    printf("n1 = n5 / n6 = %d\n", n1);
    printf("n2 = d5 / d6 = %d\n", n2);
    printf("n3 = d5 / n6 = %d\n", n3);
    printf("n4 = n5 / d6 = %d\n", n4);

    printf("d1 = n5 / n6 = %f\n", d1);
    printf("d2 = d5 / d6 = %f\n", d2);
    printf("d3 = d5 / n6 = %f\n", d3);
    printf("d4 = n5 / d6 = %f\n", d4);

    return 0;
}
