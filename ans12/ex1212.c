#include <stdio.h>

int isspace(int ch)
{
    if (ch == ' ' || ch == '\t' || ch == '\n')
        return 1;
    else
        return 0;
}

int main(void)
{
    FILE *fp;
    char fname[100];
    int  ch;
    int  cct = 0, wct = 0, lct = 0;
    int  spflag = 1;

    printf("Filename: ");
    scanf("%s", fname);
    
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", fname);
    }
    else {
        while ((ch = fgetc(fp)) != EOF) {
            cct++;
            if (spflag && !isspace(ch))
                wct++;
            if (ch == '\n')
                lct++;
            spflag = isspace(ch);
        }

        fclose(fp);

        printf("行数:   %4d\n", lct);
        printf("単語数: %4d\n", wct);
        printf("文字数: %4d\n", cct);
    }
    
    return 0;
}
