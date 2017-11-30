#include <stdio.h>

#define N 3

int main(void)
{
    int a[N][N], b[N][N], c[N][N];
    int i, j, k;

    printf("A?\n");
    for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++) {
	    printf("(%d, %d)成分? ", i+1, j+1);
	    scanf("%d", &a[i][j]);
	}
    }

    printf("B?\n");
    for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++) {
	    printf("(%d, %d)成分? ", i+1, j+1);
	    scanf("%d", &b[i][j]);
	}
    }

    for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++) {
	    c[i][j] = 0;
	    for (k = 0; k < N; k++) {
		c[i][j] += a[i][k]*b[k][j];
	    }
	}
    }

    printf("A=\n");
    for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++) {
	    printf("%3d ", a[i][j]);
	}
	printf("\n");
    }

    printf("B=\n");
    for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++) {
	    printf("%3d ", b[i][j]);
	}
	printf("\n");
    }

    printf("AB=\n");
    for (i = 0; i < N; i++) {
	for (j = 0; j < N; j++) {
	    printf("%3d ", c[i][j]);
	}
	printf("\n");
    }

    return 0;
}
    
