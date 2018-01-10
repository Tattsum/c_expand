#include <stdio.h>

// struct time definition
struct time {
	int	hour;
	int min;
	int sec;
};

struct time input_time(void)
{
    struct time t;

    printf("時間: ");
    scanf("%d", &t.hour);
    printf("分: ");
    scanf("%d", &t.min);
    printf("秒: ");
    scanf("%d", &t.sec);

    return t;
}

void print_time(struct time t)
{
    printf("%d時間%d分%d秒\n", t.hour, t.min, t.sec);
}

// add_time definition
struct time add_time(struct time t1, struct time t2)
{
	struct time t = { 0, 0, 0 };

	t.sec = t1.sec + t2.sec;
	if (t.sec > 60) {
		t.min += (t.sec / 60);
		t.sec %= 60;
	}
	t.min += t1.min + t2.min;
	if (t.min > 60) {
		t.hour += (t.min / 60);
		t.min %= 60;
	}
	t.hour += t1.hour + t2.hour;

	return t;
}

int main(void)
{
  struct time t1, t2, t3;

  printf("時間1を入力\n");
  t1 = input_time();
  printf("時間2を入力\n");
  t2 = input_time();

  t3 = add_time(t1, t2);

  print_time(t3);

  return 0;
}
