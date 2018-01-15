#include <stdio.h>

int main(void)
{
    FILE *fp;
    char fname[100];

    printf("Filename: ");
    scanf("%s", fname);
    
    if ((fp = fopen(fname, "r")) == NULL) {
        printf("Not Found.\n");
    } else {
        printf("Found.\n");
        fclose(fp);
    }

    return 0;
}
