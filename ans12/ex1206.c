#include <stdio.h>
#define NALPH 26

int main(void)
{
    FILE *fp;
    char fname[100];
    int  ch;
    int  ct[NALPH] = {0};
    int  i;
    
    printf("Filename: ");
    scanf("%s", fname);
    
    if ((fp = fopen(fname, "r")) == NULL) {
        fprintf(stderr, "Can't open %s.\n", fname);
    }
    else {
        while ((ch = fgetc(fp)) != EOF)
            if ('a' <= ch && ch <= 'z')
                ct[ch-'a']++;
        
        fclose(fp);

        for (ch = 'a'; ch <= 'z'; ch++) {
            printf("%c: ", ch);
            for (i = 0; i < ct[ch - 'a']; i++)
                printf("*");
            printf("\n");
        }
    }

    return 0;
}
