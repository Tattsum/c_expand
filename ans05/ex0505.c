#include <stdio.h>

void put_stars(int no)
{
   int i;
   for (i = 1; i <= no; i++)
      printf("*");
}

void put_spaces(int no)
{
   int i;
   for (i = 1; i <= no; i++)
      printf(" ");
}

/* n段の直角三角形(右下が直角)を出力 */
void put_triangle3(int n)
{
   int i;
   for (i = 1; i <= n; i++) {
       put_spaces(n-i);
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

   put_triangle3(ln);

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
