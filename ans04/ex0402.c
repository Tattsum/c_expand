#include <stdio.h>

int main(void)
{
    int a[2][3], b[2][3], c[2][3], d[2][3];
    int i, j;

    printf("A?\n");
    for (i = 0; i < 2; i++) {
	for (j = 0; j < 3; j++) {
	    printf("(%d, %d)成分? ", i+1, j+1);
	    scanf("%d", &a[i][j]);
	}
    }

    printf("B?\n");
    for (i = 0; i < 2; i++) {
	for (j = 0; j < 3; j++) {
	    printf("(%d, %d)成分? ", i+1, j+1);
	    scanf("%d", &b[i][j]);
	}
    }

    for (i = 0; i < 2; i++) {
	for (j = 0; j < 3; j++) {
	    c[i][j] = a[i][j] + b[i][j];
	    d[i][j] = a[i][j] - b[i][j];
	}
    }

    printf("A=\n");
    for (i = 0; i < 2; i++) {
	for (j = 0; j < 3; j++) {
	    printf("%3d ", a[i][j]);
	}
	printf("\n");
    }

    printf("B=\n");
    for (i = 0; i < 2; i++) {
	for (j = 0; j < 3; j++) {
	    printf("%3d ", b[i][j]);
	}
	printf("\n");
    }

    printf("A+B=\n");
    for (i = 0; i < 2; i++) {
	for (j = 0; j < 3; j++) {
	    printf("%3d ", c[i][j]);
	}
	printf("\n");
    }


    printf("A-B=\n");
    for (i = 0; i < 2; i++) {
	for (j = 0; j < 3; j++) {
	    printf("%3d ", d[i][j]);
	}
	printf("\n");
    }

    return 0;
}
    
	    
