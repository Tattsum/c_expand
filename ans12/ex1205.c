#include <stdio.h>

int main(void)
{
    FILE *sfp, *dfp;
    char sname[100], dname[100];
    int  ch;

    printf("Input Filename: ");
    scanf("%s", sname);
    
    printf("Output Filename: ");
    scanf("%s", dname);
    
    if ((sfp = fopen(sname, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", sname);
    }
    else {
        if ((dfp = fopen(dname, "w")) == NULL) {
            fprintf(stderr, "Can't open %s.\n", dname);
        }
        else {
            while ((ch = fgetc(sfp)) != EOF) {
                if ('A' <= ch && ch <= 'Z')
                    ch = ch - 'A' + 'a';
                else if ('a' <= ch && ch <= 'z')
                    ch = ch - 'a' + 'A';
            
                fputc(ch, dfp);
            }
            fclose(dfp);
        }
        fclose(sfp);
    }
    
    return 0;
}
