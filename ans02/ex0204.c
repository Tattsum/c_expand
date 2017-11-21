/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int tshirt, ftowel, mtowel, total;

    printf("Tシャツの枚数：");
    scanf("%d", &tshirt);

    printf("フェイスタオルの枚数：");
    scanf("%d", &ftowel);

    printf("マフラータオルの枚数：");
    scanf("%d", &mtowel);

    total = tshirt * 3000 +  ftowel * 1500 + mtowel * 1000;

    printf("商品の合計金額(税抜)は %d 円\n", total);

    if (total >= 10000) {
	total = total*1.08;
	printf("送料は無料\n送料込の合計金額(税込)は %d 円\n", total);
    } else {
	total = total*1.08+756;
	printf("送料(税込)は756円\n送料込の合計金額(税込)は %d 円\n", total); 
    }

    return 0;
}
