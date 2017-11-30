#include <stdio.h>

#define M 2
#define N 2

int main(void)
{
    int a[M][N], b[M][N], c[M][N], d[M][N];
    int i, j;

    printf("A?\n");
    for (i = 0; i < M; i++) {
	for (j = 0; j < N; j++) {
	    printf("(%d, %d)成分? ", i+1, j+1);
	    scanf("%d", &a[i][j]);
	}
    }

    printf("B?\n");
    for (i = 0; i < M; i++) {
	for (j = 0; j < N; j++) {
	    printf("(%d, %d)成分? ", i+1, j+1);
	    scanf("%d", &b[i][j]);
	}
    }

    for (i = 0; i < M; i++) {
	for (j = 0; j < N; j++) {
	    c[i][j] = a[i][j] + b[i][j];
	    d[i][j] = a[i][j] - b[i][j];
	}
    }

    printf("A=\n");
    for (i = 0; i < M; i++) {
	for (j = 0; j < N; j++) {
	    printf("%3d ", a[i][j]);
	}
	printf("\n");
    }

    printf("B=\n");
    for (i = 0; i < M; i++) {
	for (j = 0; j < N; j++) {
	    printf("%3d ", b[i][j]);
	}
	printf("\n");
    }

    printf("A+B=\n");
    for (i = 0; i < M; i++) {
	for (j = 0; j < N; j++) {
	    printf("%3d ", c[i][j]);
	}
	printf("\n");
    }


    printf("A-B=\n");
    for (i = 0; i < M; i++) {
	for (j = 0; j < N; j++) {
	    printf("%3d ", d[i][j]);
	}
	printf("\n");
    }

    return 0;
}
    
	    
