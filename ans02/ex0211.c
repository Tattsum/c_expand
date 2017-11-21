/*
[学生番号]
[氏名]
*/

#include <stdio.h>

int main(void)
{
    int area, ch;

    printf("地域を入力してください(1:東京, 2:名古屋, 3:大阪) ");
    scanf("%d", &area);

    printf("チャンネルを入力してください ");
    scanf("%d", &ch);

    if(area==1){
        switch(ch){
        case 1:
            printf("NHK総合\n");
            break;
        case 2:
            printf("NHKEテレ\n");
            break;
        case 4:
            printf("日本テレビ\n");
            break;
        case 5:
            printf("テレビ朝日\n");
            break;
        case 6:
            printf("TBS\n");
            break;
        case 7:
            printf("テレビ東京\n");
            break;
        case 8:
            printf("フジテレビ\n");
            break;
        case 9:
            printf("東京MX\n");
            break;
        default:
            printf("対応するテレビ局はありません\n");
            break;
        }
    }
    else if(area==2){
        switch(ch){
        case 1:
            printf("東海テレビ\n");
            break;
        case 2:
            printf("NHKEテレ\n");
            break;
        case 3:
            printf("NHK総合\n");
            break;
        case 4:
            printf("中京テレビ\n");
            break;
        case 5:
            printf("CBCテレビ\n");
            break;
        case 6:
            printf("メーテレ\n");
            break;
        case 10:
            printf("テレビ愛知\n");
            break;
        default:
            printf("対応するテレビ局はありません\n");
            break;
        }
    }
    else if(area==3){
        switch(ch){
        case 1:
            printf("NHK総合\n");
            break;
        case 2:
            printf("NHKEテレ\n");
            break;
        case 4:
            printf("毎日放送\n");
            break;
        case 6:
            printf("朝日放送\n");
            break;
        case 7:
            printf("テレビ大阪\n");
            break;
        case 8:
            printf("関西テレビ\n");
            break;
        case 10:
            printf("讀賣テレビ\n");
            break;
        default:
            printf("対応するテレビ局はありません\n");
            break;
        }
    }
    else{
        printf("その地域はありません\n");
    }
    return 0;
}
