#include <stdio.h>

int main(void){
  int i,n;

  printf("1/1の曜日を1から7の数字で指定してください：");
  scanf("%d",&n);

  for(i = 1; i < n; i++)
      printf("   ");

  for(i = 1; i <= 31; i++){
    printf("%3d",i);
    if( (i + n)%7 == 1 || i == 31 )
      printf("\n");
  }

  return 0;

}
