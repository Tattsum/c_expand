/*
[氏名]
[学生番号]
*/

/*
 * ツェラーの公式を用いて西暦(グレゴリオ暦)から曜日計算
 * h = (q + [((m+1)*26)/10] + K + [K/4] + [J/4] + 5*J ) mod 7
 * 但し、J: 西暦の上2桁
 *       K: 西暦の下2桁
 *       m: 月 (1,2月は前年の13,14月とする)
 *       q: 日
 *       h: 曜日 (0:土, 1:日, 2:月, 3:火, 4:水, 5:木, 6:金)
 *       []: floor (小数点以下切り捨て)
 *
 * ※ユリウス暦は1582年10月4日まで、グレゴリオ暦は1582年10月15日からなので、
 *   1582年10月5日〜14日は存在しない
 * 
 *   ユリウス暦の公式は
 *   h = (q + [((m+1)*26)/10] + K + [K/4] + 5 + 6*J ) mod 7
 */
#include <stdio.h>

int zeller( int y, int m, int q )
{
    int J, K, h;

    /* 1582年10月15日より前は -1 を返す */
    if ((y<1582) || (y==1582 && m<10) || (y==1582 && m==10 && q<15)) {
        return -1;
    }
    else {
        if (m == 1 || m == 2) { /* 1,2月を前年の13,14月に */
            m += 12;
            y -= 1;
        }

        J = y / 100; /* 年の上2桁と下2桁を分離 */
        K = y % 100;

        h = (q + ((m+1)*26)/10 + K + (K/4) + (J/4) + 5*J) % 7;

        return h;
    }
}

int main(void)
{
    int year, month, date, week;

    printf("年: ");
    scanf("%d", &year);
    printf("月: ");
    scanf("%d", &month); /* 月、日の範囲チェックはしない */
    printf("日: ");
    scanf("%d", &date);

    week = zeller(year, month, date);

    if (week == -1) {
        printf("1582年10月14日以前には対応していません\n");
    }
    else {
        printf("%4d年%2d月%2d日は ", year, month, date);
        switch(week) {
        case 0: printf("土曜日 です\n"); break;
        case 1: printf("日曜日 です\n"); break;
        case 2: printf("月曜日 です\n"); break;
        case 3: printf("火曜日 です\n"); break;
        case 4: printf("水曜日 です\n"); break;
        case 5: printf("木曜日 です\n"); break;
        case 6: printf("金曜日 です\n"); break;
        }
    }

    return 0;
}

/*
15se999@localhost:~/prog/01$ cc -o ad0102 ad0102.c
15se999@localhost:~/prog/01$ ./ad0102
年: 2016
月: 4
日: 8
2016年 4月 8日は 金曜日 です
15se999@localhost:~/prog/01$ ./ad0102
年: 2000
月: 1
日: 1
2000年 1月 1日は 土曜日 です
15se999@localhost:~/prog/01$ ./ad0102
年: 20000
月: 4
日: 5
20000年 4月 5日は 水曜日 です
15se999@localhost:~/prog/01$ ./ad0102
年: 1582
月: 10
日: 15
1582年10月15日は 金曜日 です
15se999@localhost:~/prog/01$ ./ad0102
年: 1582
月: 10
日: 14
1582年10月14日以前には対応していません
15se999@localhost:~/prog/01$ 
 */
