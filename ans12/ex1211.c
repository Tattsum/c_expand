#include <stdio.h>

int main(void)
{
    FILE *fp;
    char fname[100];
    int  ch;
    int  ct = 0;

    printf("Filename: ");
    scanf("%s", fname);
    
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", fname);
    }
    else {
        while ((ch = fgetc(fp)) != EOF) {
            if (!(('0' <= ch && ch <= '9') ||
                  ('A' <= ch && ch <= 'Z') ||
                  ('a' <= ch && ch <= 'z')))
                ct++;
        }
        fclose(fp);

        printf("chars = %d\n", ct);
    }

    
    return 0;
}
