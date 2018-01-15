#include <stdio.h>
#include <stdlib.h>

int main(void)
{
  FILE *fp;
  int ninzu = 0;
  char name[100];
  double height, weight;

  if((fp = fopen("hw.dat", "a"))==NULL){
    fprintf(stderr, "オープンできません．\n");
    exit(1);
  }
  while(1){
    printf("名前 身長 体重: ");
    if(scanf("%s%lf%lf", name, &height, &weight) != 3)
      break;
    fprintf(fp, "%s %.1f %.1f\n", name, height, weight);
  }
  fclose(fp);
  return 0;
}
