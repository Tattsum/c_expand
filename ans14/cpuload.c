/* CPUコアに順番に負荷を与えるプログラム
 * コンパイル方法: cc -o cpuload cpuload.c -lpthread
 * usage: cpuload <秒数>
 */

#define _GNU_SOURCE /* GNU拡張機能を使用 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/sched.h>
#include <pthread.h> /* POSIXスレッドライブラリを使用 */

#define MAX_CPU 10 /* 最大CPUコア数 */

int worktime; /* 負荷計測時間 */

/* スレッドを動作させるCPUを指定 */
int bind_cpu(int id)
{
    cpu_set_t mask;
    CPU_ZERO(&mask);
    CPU_SET(id, &mask);

    if (sched_setaffinity(0, sizeof(mask), &mask) == -1) {
        fprintf(stderr, "Failed to set CPU affinity\n");
        return -1;
    }
    /* fprintf(stderr, "Bind thread to CPU %d\n", id); */

    return 0;
}

/* 指定されたIDのCPUに(worktime/2)秒間負荷をかけて待つ(別スレッドで動作させる関数) */
void *usecpu(void *pid)
{
    int id = *(int *)pid;
    time_t t0, t1;

    bind_cpu(id);
    t0 = time(NULL);

    while (1) {
        t1 = time(NULL);
        if (difftime(t1, t0) >= worktime/2)
            break;
    }
    return NULL;
}

int main(int argc, char *argv[])
{
    int n_cpu, id, t;
    int n_thread=0;
    double dth_sec, next_th;

    int cpuID[MAX_CPU+1];
    pthread_t thread[MAX_CPU+1];

    /*
      fprintf(stderr, "CPU負荷計測時間(秒): ");
      scanf("%d", &worktime);
    */
    if (argc == 2)
        worktime = atoi(argv[1]);
    else
        worktime = 60;

    n_cpu = sysconf(_SC_NPROCESSORS_CONF); /* n_cpu にコア数を保存 */
    /* fprintf(stderr, "n_cpu = %d\n", n_cpu); */

    for (id=0; id<n_cpu; id++ ) /* CPUコア番号を配列cpuID[] に格納 (n_cpu個) */
        cpuID[id] = id;

    id = 0;
    next_th = dth_sec = (double)worktime/(double)((n_cpu+1) * 2);
    for (t=1; t<=worktime; t++) {
        /* 適当なタイミングで usecpu() を別スレッドで実行させる。改変禁止 */
        if (t > next_th && id < n_cpu) {
            /* fprintf(stderr, "create_thread %d\n", n_thread); */
            pthread_create(&thread[n_thread++], NULL, usecpu, &cpuID[id]);
            next_th += dth_sec;
            id++;
        }

        /* 1秒休止 */
        sleep(1);
    }

    return 0;
}
