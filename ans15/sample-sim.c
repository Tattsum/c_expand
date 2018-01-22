#include <stdio.h>
#include <stdlib.h>		/* exit() */
#include <sys/stat.h>

#define DELTA  0.001          /* DELTA 秒ごとに計算を行う */
#define TIME_LIMIT 20         /* シミュレーションの最大時間 */
#define WALLPOS 100           /* 壁の位置 */

/* ボールの状態を表す構造体 */
struct ballType {
    double position;  /* ボールの位置 (m) */
    double velocity;  /* ボールの速度(右向きが正) (m/s) */
    double accel;     /* ボールの加速度(右向きが正、左向きが負) (m/s^2) */
};

/* 時刻(simtime)とballの状態(位置，速度，加速度)を
   ファイル fp に出力する */
void printBall(FILE *fp, double simtime, struct ballType *ball)
{
    fprintf(fp, "%10.3f %10.3f %10.3f %10.3f\n",
	    simtime,  ball->position, ball->velocity,  ball->accel);
}

/* ball の DELTA秒後の状態を計算する関数 */
void calcBall(struct ballType *ball)
{
    /* 引数の現在のボールの状態．DELTA 秒後のボールの状態に更新する */
    /* 加速度は0として，等速度運動の距離を計算する */
    ball->accel = ball->accel;        /* 加速度は変化なし */
    ball->velocity = ball->velocity;  /* 速度は変化なし */
    ball->position = ball->position + ball->velocity*DELTA; /* 位置 */
}

/* ball についてのシミュレーションを開始する．結果はファイルfpに書き出す  */
void startSimulation(FILE *fp, struct ballType *ball)
{
    double simtime;  /* 時刻 */

    /* ボールの初期値を画面に表示 */
    printf("初期値: 位置 = %f, 速度 = %f, 加速度 = %f\n",
	    ball->position, ball->velocity, ball->accel);

    /* 時刻0からシミュレーションを開始．
       ボールの速度が0以上，位置が壁+5未満，かつ時刻が TIME_LIMIT になるまで
       シミュレーションを行う．
       時刻は DELTA秒ずつ増やしていく */
    simtime = 0.0;
    printBall(fp, simtime, ball); /* 最初の状態 */
    while (ball->velocity >= 0.0 && ball->position < WALLPOS+5.0 && simtime <= TIME_LIMIT) {
	/* 時刻を DELTA秒進める */
	simtime += DELTA;

	/* ボールの状態を計算する */
	calcBall(ball);

	/* ボールの状態を表示する */
	printBall(fp, simtime, ball); /* 最初の状態 */
    }
}

int main(void)
{
    struct ballType ball; /* ボール */
    FILE   *fp; /* 書き込み用ファイル */
    struct stat st;

    /* 書き込み用ファイル sim.txt を開く */
    fp = fopen("sim.txt", "w");

    if (fp == NULL) {
	/* ファイルが開けないのでエラーメッセージを表示して終了 */
	printf("Can't open file: sim.txt\n");
	exit(1);
    }

    /* ボール位置の初期値を設定 */
    ball.position = 0;  /* 0m */

    /* ボールの初速度の入力 */
    printf("初速度: ");
    scanf("%lf", &ball.velocity);

    /* サンプルでは加速度は0とする */
    ball.accel = 0.0;

    /* シミュレーション開始 */
    startSimulation(fp, &ball);

    /* ファイルを閉じる */
    fclose(fp);

    /* シミュレーション結果の画面表示プログラム showBall があれば起動 */
    if (!stat("showBall", &st)) {
        printf("showBall を起動しました．\n");
        system("./showBall");
    }
    else {
      printf("showBall がありません．\n");
    }
    
    return 0;
}
