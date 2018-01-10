#include <stdio.h>
#include <string.h>

#define NAME_LEN 20

struct st {
	int  id;
    char name[NAME_LEN];
    double gpa;
};

int main(void)
{
	struct st x;
	double points;
	int credits;

	printf("番号? ");
	scanf("%d", &x.id);
	printf("名前? ");
	scanf("%s", x.name);
	
	printf("GP の合計? ");
	scanf("%lf", &points);
	printf("履修単位数? ");
	scanf("%d", &credits);
	
	x.gpa = points/credits;
	
    printf("No.%d %s の GPA は %.2f\n", x.id, x.name, x.gpa);

    return 0;
}
