#include <stdio.h>

void put_stars(int no)
{
   int i;
   for (i = 1; i <= no; i++)
      printf("*");
}

/* n段の直角三角形(左上が直角)を出力 */
void put_triangle2(int n)
{
   int i;
   for (i = n; i >=1; i--) {
      put_stars(i);
      printf("\n");
   }
   /* ここではreturn文はなくても良い */
   return;
}

int main(void)
{
   int ln;
   
   printf("何段ですか? ");
   scanf("%d", &ln);

   put_triangle2(ln);

   return 0;
}

/*

実行結果

$ ./a.out 
何段ですか? 5
*****
****
***
**
*
$ ./a.out 
何段ですか? 3
***
**
*
$ ./a.out 
何段ですか? 1
*

*/
