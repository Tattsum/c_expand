/* CPU負荷計測プログラム */
/*
[氏名]     南山太郎
[学生番号] 13se999
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/stat.h>

#define MAX_CPU 10 /* 最大CPUコア数+1(全体の平均も含む) */

/* CPU時間構造体 */
typedef struct cputime {
    char cpu[256]; /* CPU名（コア名） */
    unsigned int user; /* ユーザモード */
    unsigned int nice; /* 低い優先度(nice)でのユーザモード */
    unsigned int sys;  /* システム */
    unsigned int idle; /* アイドル */

    /*
    unsigned int iowait; // I/O 待ち時間
    unsigned int irq;    // 割り込み処理時間
    unsigned int softirq; // ソフト割り込み処理時間

    unsigned int steal; // 仮想化環境で他のOSが消費した時間
    unsigned int guest; // ゲストOSの仮想CPU消費時間
    unsigned int guest_nice; // 低い優先度でのゲストOS消費時間
    */
} Cputime;

/* /proc/stat から全体およびコア毎のCPU時間を取得し、CPUコア数+1を返す */
int sscan_cpustat(Cputime c[])
{
    FILE *fp;
    char cpustat[1024];
    int i = 0;

    if ((fp = fopen("/proc/stat", "r")) == NULL) {
        fprintf(stderr, "Can't open /proc/stat.");
        exit(1);
    }

    /* /proc/stat から1行ずつ読み込み、
       先頭が "cpu" なら sscanf() 関数でCPU名（コア名）と数値を取得 */
    while (fgets(cpustat, 1023, fp) != NULL) {
        if (!strncmp(cpustat, "cpu", 3)) {
            sscanf(cpustat, "%s %u %u %u %u",
              /* ここを穴埋め */
                   c[i].cpu, &c[i].user, &c[i].nice, &c[i].sys, &c[i].idle);
            i++;
        }
        else {
            break;
        }
    }

    fclose(fp);

    return i;
}

/* c0 から c1 までのCPU使用率を返す */
double cpuwork(Cputime c0, Cputime c1)
{
    /* 関数内部を穴埋め */

    Cputime cdiff;
    unsigned int work, total;

    cdiff.user = c1.user - c0.user;
    cdiff.nice = c1.nice - c0.nice;
    cdiff.sys  = c1.sys  - c0.sys;
    cdiff.idle = c1.idle - c0.idle;

    work = cdiff.user + cdiff.nice + cdiff.sys;
    total = work + cdiff.idle;

    return (double)work / (double)total;
}

/* 全体およびコア毎のCPU使用率を % で表示 */
void print_n_cpuwork(Cputime c0[], Cputime c1[], int n_cpu)
{
    int i;

    for (i=0; i<n_cpu-1; i++) {
        /* printf() の引数を穴埋め */
        printf("%s: %5.1f %%, ", c0[i].cpu, cpuwork(c0[i], c1[i]) * 100.0);
  }
  printf("%s: %5.1f %%\n", c0[i].cpu, cpuwork(c0[i], c1[i]) * 100.0);
}

int main(void)
{
    int i, n_cpu, t, worktime;

    Cputime c0[MAX_CPU], c1[MAX_CPU];
    char cpuload_cmd[100];
    struct stat st;

    printf("計測時間(秒): ");
    scanf("%d", &worktime);

    /* CPUコアに負荷を与えるプログラム cpuload があれば起動 */
    if (!stat("cpuload", &st)) {
        sprintf(cpuload_cmd, "./cpuload %d &", worktime);
        system(cpuload_cmd);
        printf("cpuload を起動しました．\n");
    }

    n_cpu = sscan_cpustat(c0); /* CPU時間を構造体配列 c0[] に格納し、n_cpu にコア数+1 を保存 */
    printf("n_cpu = %d\n", n_cpu);

    for (t=1; t<=worktime; t++) {
        /* 1秒休止 */
        sleep(1);

        sscan_cpustat(c1); /* CPU時間を構造体配列 c1[] に格納 */
        printf("%3d: ", t);
        print_n_cpuwork(c0, c1, n_cpu);

        /* 構造体配列 c1[] から c0[] へのコピー。穴埋めにする */
        for (i=0; i<n_cpu; i++) {
            c0[i] = c1[i];
        }
    }

  return 0;
}
