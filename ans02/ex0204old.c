/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int tshirt, towel, tote, total;

    printf("Tシャツの個数：");
    scanf("%d", &tshirt);

    printf("フェイスタオルの個数：");
    scanf("%d", &towel);

    printf("トートバッグの個数：");
    scanf("%d", &tote);

    total = tshirt * 3240 +  towel * 1620 + tote * 2160;

    printf("商品の合計金額は %d 円\n", total);

    if (total >= 10000) {
	printf("送料は無料です\n送料込みの合計金額は %d 円\n", total);
    } else {
	printf("送料は756円です\n送料込みの合計金額は %d 円\n", total+756); 
    }

    return 0;
}
