/* -*- coding: utf-8 -*- */
/*
[氏名]
[学生番号]
*/

#include <stdio.h>

int main(void)
{
    int height;
    int i, j;

    printf("段数を入力してください ");
    scanf("%d", &height);

    for(i = 1; i <= height; i++){
	for(j = 1; j <= i - 1; j++){
	    printf(" ");
	}
	for(j = 1; j <= (height - i) * 2 + 1; j++){
	    printf("%d",i % 10);
	}
	printf("\n");
    }

    return 0;
}

/*
15se999@localhost:~/prog/01$ cc -o ad0101 ad0101.c
15se999@localhost:~/prog/01$ ./ad0101
段数を入力してください 5
111111111
 2222222
  33333
   444
    5
15se999@localhost:~/prog/01$ ./ad0101
段数を入力してください 12
11111111111111111111111
 222222222222222222222
  3333333333333333333
   44444444444444444
    555555555555555
     6666666666666
      77777777777
       888888888
        9999999
         00000
          111
           2
15se999@localhost:~/prog/01$ 
*/
