#include <stdio.h>
/* 別解のとき必要
   #include <string.h>
*/
#define BUFSIZE 1024

int main(void)
{
    FILE *fp;
    char fname[100];
    char ch, lbuf[BUFSIZE];
    char maxlbuf[BUFSIZE];
    int  i, len, maxlen = -1;

    printf("Filename: ");
    scanf("%s", fname);
    
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", fname);
    }
    else {
        len = 0;
        while ((ch = fgetc(fp)) != EOF) {
            if (ch != '\n') {            /* 行の途中 */
                lbuf[len++] = ch;
            }
            else {                       /* 行入力完了 */
                lbuf[len] = '\0';
                if (len > maxlen) {      /* 最長更新なら文字列保存 */
                    maxlen = len;

                    for (i=0; lbuf[i] != '\0'; i++) { /* lbuf を maxlbuf にコピー */
                        maxlbuf[i] = lbuf[i];
                    }
                    maxlbuf[i] = '\0';
                    /* 別解
                       strcpy(maxlbuf, lbuf);
                    */
                }
                len = 0;
            }
        }
        fclose(fp);

        printf("%d: %s\n", maxlen, maxlbuf);
    }

    return 0;
}
