/*
[氏名]
[学生番号]
*/
#include <stdio.h>

void printSubject(int code)
{
    switch(code) {
    case 1006:
	printf("線形代数学Iおよび演習\n");
	break;
    case 1007 :
	printf("線形代数学IIおよび演習\n");
	break;
    case 1008:
	printf("プログラミング基礎\n");
	break;
    case 1009:
	printf("プログラミング応用\n");
	break;
    case 2012:
	printf("確率・統計\n");
	break;
    case 2013:
	printf("物理学基礎\n");
	break;
    case 2014:
	printf("通信ネットワーク基礎\n");
	break;
    default:
	printf("該当する科目はありません\n");
    }
}

int main(void)
{
    int code;

    printf("科目番号は? ");
    scanf("%d", &code);

    printSubject(code);

    return 0;
}
