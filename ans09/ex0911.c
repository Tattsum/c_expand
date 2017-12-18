/*
[氏名]     南山太郎
[学生番号] 17se999
*/

#include <stdio.h>
#include <math.h>

#define	N		10

void deleteIdx(int data[], int *size, int idx)
{
	int i;

	(*size)--;
	for (i = idx; i < *size; i++)
		data[i] = data[i + 1];
}

void getMaxIdx(int data[], int size, int *maxidx)
{
	int i;

	*maxidx = 0;
	for (i = 0; i < size; i++) {
		if (data[i] > data[*maxidx])
			*maxidx = i;
	}
}

void printarray(int data[], int size)
{
    int i;
    printf("{");
    for(i=0;i < size;i++){
        printf(" %3d", data[i]);
        if (i+1!=size) printf(","); 
    }
    printf("}\n");
}

int main(void)
{
	int		A[N];
	int		i, n = N;
	int		maxidx;
	
	for (i = 0; i < N; i++) {
		printf("Input A[%d]:", i);
		scanf("%d", &A[i]);
	}

	printf("Before:"); printarray(A, n);
	getMaxIdx(A, n, &maxidx);
	deleteIdx(A, &n, maxidx);
	printf("After :"); printarray(A, n);
	
    return 0;
}

/*
  実行結果

$ ./a.out
Input A[0]:23
Input A[1]:24
Input A[2]:42
Input A[3]:35
Input A[4]:42
Input A[5]:42
Input A[6]:57
Input A[7]:43
Input A[8]:42
Input A[9]:34
Before:{  23,  24,  42,  35,  42,  42,  57,  43,  42,  34}
After :{  23,  24,  42,  35,  42,  42,  43,  42,  34}
$ 

*/
