/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int eng, math, sci;
    double total;
	
    printf("英語："); scanf("%d", &eng);
    printf("数学："); scanf("%d", &math);
    printf("理科："); scanf("%d", &sci);
    total = eng + math + sci;

    if (eng < 0 || 100 < eng ||
	math < 0 || 100 < math ||
	sci < 0 ||  100 < sci) {
	printf("0から100以外の数値が入力されています\n");
    } else {
	printf("平均点は%.2fです\n", total / 3.0);

	if (90 <= eng && 90 <= math && 90 <= sci) {
	    printf("成績はA+です\n");
	} else if (80 <= eng && 80 <= math && 80 <= sci) {
	    printf("成績はAです\n");
	} else if (70 <= eng && 70 <= math && 70 <= sci) {
	    printf("成績はBです\n");
	} else if (180 <= total) {
	    printf("成績はCです\n");
	} else {
	    printf("成績はFです\n");
	}
    }
    
    return 0;
}
