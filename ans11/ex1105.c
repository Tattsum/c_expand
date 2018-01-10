#include <stdio.h>

#define	NSTUDENTS	(12)
#define NAME_LEN 64

struct st {
  int id;
  char	name[NAME_LEN];
  double gpa;
};

int max_gpa_id(struct st st[], int size)
{
  int maxid, i;
  double maxgpa;

  maxid = 0;
  maxgpa = st[maxid].gpa;
	
  for (i = 1; i < size; i++)
    if (maxgpa < st[i].gpa) {
      maxid = i;
      maxgpa = st[maxid].gpa;
    }

  return maxid;
}

int main(void)
{
  int idx;
  struct st students[] = {
        { 1, "Aoki",      2.51},
        { 2, "Ban",       3.32},
        { 3, "Chikushi",  3.53},
        { 4, "Doi",       3.41},
        { 5, "Endo",      2.78},
        { 6, "Fukui",     2.82},
        { 7, "Goto",      3.50},
        { 8, "Hasegawa",  2.29},
        { 9, "Ishihara",  2.69},
        { 10, "Jinnai",   3.58},
        { 11, "Kato",     3.25},
        { 12, "Moriya",   2.91}
  };

  idx = max_gpa_id(students, NSTUDENTS);
  printf("最も GPA が高いのは番号 %d の %s で %.2f です。\n",
	 students[idx].id, students[idx].name, students[idx].gpa);

  return 0;
}
