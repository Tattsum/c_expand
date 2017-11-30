/*
[氏名]     南山太郎
[学生番号] 15se999
*/

#include <stdio.h>

#define ST_NUM 10
#define C_NUM 3

int main(void)
{
    int exam[ST_NUM][C_NUM];
    int member;
    int i, j;
    int total[ST_NUM];
    double avg[C_NUM + 1];

    /* 人数の入力 */
    printf("人数を入力してください ");
    scanf("%d", &member);
    if (member <= 0 || ST_NUM <= member) {
        /* 1 未満あるいは 10 より多い人数が入力されたときの出力 */
	puts("1 以上 10 以下の人数を入力してください");
	return 0;
    }

    for (i = 0; i < member; i++) {
        /* i 人目の国語，数学，英語の点数の入力 */
	printf("%2d人目の国語，数学，英語の点数: ", i+1);
	scanf("%d%d%d", &exam[i][0], &exam[i][1], &exam[i][2]);
    }

    for (i = 0; i < member; i++) {
	total[i] = 0;
	for (j = 0; j < C_NUM; j++) {
	    total[i] += exam[i][j];
	    avg[j] += exam[i][j];
	}
	avg[C_NUM] += total[i];
    }

    for (i = 0; i <= C_NUM; i++) {
	avg[i] /= member;
    }

    /* 表見出しの出力 */
    puts("");
    puts("  国語  数学  英語  合計");
    puts("----------------------------");
    for (i = 0; i < member; i++) {
	for (j = 0; j < C_NUM; j++) {
	    /* i 人目の国語，数学，英語の出力 */
	    printf("   %3d", exam[i][j]);
	}
	/* i 人目の3科目合計点数の出力 */
	printf("  %4d\n", total[i]);
    }
    puts("----------------------------");
    printf("  ");
    for (j = 0; j <= C_NUM; j++) {
	/* 3 科目と合計点数の平均の出力 */
	printf(" %5.1f", avg[j] );
    }
    printf("\n");

    return 0;
}


/*
  実行結果

*/
