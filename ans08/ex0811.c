/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

#define	FALSE		0
#define	TRUE		!FALSE

#define MAX_MONTH	12
#define MIN_MONTH	1
#define MIN_DATE	1

#ifdef ENABLE_GC
#define GC_START_YEAR	1582
#define GC_START_MONTH	10
#define GC_START_DATE	15
#endif /*ENABLE_GC*/

int isleapyear(int y)
{
    if ((y % 400 == 0) || (y % 100 != 0 && y % 4 == 0))
        return TRUE;
    else
        return FALSE;
}

int daysof(int y, int m)
{
    int days = 31;

    switch (m) {
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    case 2:
        if (isleapyear(y))
            days = 29;
        else
            days = 28;
        break;
    }

    return days;
}

int isvalid(int y, int m, int d)
{
    int ret = 0;

#ifdef ENABLE_GC
    if (y == GC_START_YEAR) {
        if (m == GC_START_MONTH) {
            if (GC_START_DATE <= d && d <= daysof(y, m)) {
                ret = 1;
			}
		} else if (GC_START_MONTH < m && m <= MAX_MONTH) {
            ret = 1;
		}
	} else if (GC_START_YEAR < y)
#endif /*ENABLE_GC*/
        if ((MIN_MONTH <= m && m <= MAX_MONTH) &&
            (MIN_DATE  <= d && d <= daysof(y, m)))
            ret = 1;

    return ret;
}

void decrement_date(int *y, int *m, int *d)
{
    if (--(*d) == 0) {
        if (--(*m) == 0) {
            --(*y);
            *m = 12;
        }
        *d = daysof(*y, *m);
    }
#ifdef ENABLE_GC
	if (!isvalid(*y, *m, *d)) {
		fprintf(stderr, "decreent_date: coundn't decrement the first date of Gregorian calendar\n");
		*d = GC_START_DATE;
	}
#endif /*ENABLE_GC*/
}

void increment_date(int *y, int *m, int *d)
{
    if (++(*d) > daysof(*y, *m)) {
        if (++(*m) > MAX_MONTH) {
            ++(*y);
            *m = MIN_MONTH;
        }
        *d = MIN_DATE;
    }
}

void get_ymd(int *y, int *m, int *d)
{
	while (1) {
		printf("Input YEAR MONTH DATE? ");
		scanf("%d%d%d", y, m, d);
		if (isvalid(*y, *m, *d))
			break;
		fprintf(stderr, "Input a CORRECT date, PLEASE\n");
	}
}

void put_ymd(int y, int m, int d)
{
	printf("%d/%d/%d\n", y, m, d);
}

int main(void)
{
	int year, month, date;

	get_ymd(&year, &month, &date);

	printf("Date entered:     "); put_ymd(year, month, date);

	decrement_date(&year, &month, &date);
	printf("Date decremented: "); put_ymd(year, month, date);

	increment_date(&year, &month, &date);
	printf("Date incremented: "); put_ymd(year, month, date);

    return 0;
}

/*
  実行結果

$ cc -Wall ex0811.c
$ ./a.out
Input YEAR MONTH DATE? 2017 12 11
Date entered:     2017/12/11
Date decremented: 2017/12/10
Date incremented: 2017/12/11
$ ./a.out
Input YEAR MONTH DATE? 2000 1 1
Date entered:     2000/1/1
Date decremented: 1999/12/31
Date incremented: 2000/1/1
$ ./a.out
Input YEAR MONTH DATE? 1900 3 1
Date entered:     1900/3/1
Date decremented: 1900/2/28
Date incremented: 1900/3/1
$ ./a.out
Input YEAR MONTH DATE? 2000 3 1
Date entered:     2000/3/1
Date decremented: 2000/2/29
Date incremented: 2000/3/1
$ ./a.out
Input YEAR MONTH DATE? 2016 3 1
Date entered:     2016/3/1
Date decremented: 2016/2/29
Date incremented: 2016/3/1
$ ./a.out
Input YEAR MONTH DATE? 1582 10 15
Date entered:     1582/10/15
Date decremented: 1582/10/14
Date incremented: 1582/10/15
$ cc -Wall -DENABLE_GC ex0811.c
$ ./a.out
Input YEAR MONTH DATE? 2017 12 11
Date entered:     2017/12/11
Date decremented: 2017/12/10
Date incremented: 2017/12/11
$ ./a.out
Input YEAR MONTH DATE? 2000 1 1
Date entered:     2000/1/1
Date decremented: 1999/12/31
Date incremented: 2000/1/1
$ ./a.out
Input YEAR MONTH DATE? 1900 3 1
Date entered:     1900/3/1
Date decremented: 1900/2/28
Date incremented: 1900/3/1
$ ./a.out
Input YEAR MONTH DATE? 2000 3 1
Date entered:     2000/3/1
Date decremented: 2000/2/29
Date incremented: 2000/3/1
$ ./a.out
Input YEAR MONTH DATE? 2016 3 1
Date entered:     2016/3/1
Date decremented: 2016/2/29
Date incremented: 2016/3/1
$ ./a.out
Input YEAR MONTH DATE? 1582 10 15
Date entered:     1582/10/15
decreent_date: coundn't decrement the first date of Gregorian calendar
Date decremented: 1582/10/15
Date incremented: 1582/10/16
$ 

*/
