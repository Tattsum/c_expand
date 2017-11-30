/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

#define NUMBER 6

int main(void)
{
    double temperature[NUMBER];
    int i;
    int tmax_id, tmin_id;
    double total, ave;

    for (i = 0; i < NUMBER; i++) {
	printf("temperature[%d]: ", i);
	scanf("%lf", &temperature[i]);
    }

    tmax_id = tmin_id = 0;
    total = 0;
    for (i = 0; i < NUMBER; i++) {
	if (temperature[tmax_id] < temperature[i]) {
	    tmax_id = i;
	}
	if (temperature[tmin_id] > temperature[i]) {
	    tmin_id = i;
	}
	total += temperature[i];
    }
    ave = total / NUMBER;

    printf("最高気温: temperature[%d] = %.2f度\n", tmax_id,
	   temperature[tmax_id]);
    printf("最低気温: temperature[%d] = %.2f度\n", tmin_id,
	   temperature[tmin_id]);
    printf("平均気温: %.2f度\n", ave);

    return 0;
}


/*
  実行結果

*/
