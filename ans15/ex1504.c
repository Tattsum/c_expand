#include <stdio.h>
#include <stdlib.h>		/* exit() */
#include <sys/stat.h>
#include <math.h> /* sqrt() */

#define DELTA  0.001          /* DELTA 秒ごとに計算を行う */
#define TIME_LIMIT 20         /* シミュレーションの最大時間 */
#define WALLPOS 100           /* 壁の位置 */

/* ボールの状態を表す構造体 */
struct ballType {
    double position;  /* ボールの位置 (m) */
    double velocity;  /* ボールの速度(右向きが正) (m/s) */
    double accel;     /* ボールの加速度(右向きが正、左向きが負) (m/s^2) */

    double brake_position; /* ブレーキを開始する位置 */
    double brake_accel;    /* ブレーキの加速度(負の値) */

    double max_velocity; /* 最高速度 (m/s) */
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

    /* ブレーキ位置に達したら加速度をブレーキ加速度にする */
    if (ball->position >= ball->brake_position) {
        ball->accel = ball->brake_accel;
    }
    /*    ball->accel = ball->accel; */       /* 加速度は変化なし */
    ball->velocity = ball->velocity + ball->accel * DELTA;

    /* 最高速度以上なら速度を最高速度にし、ブレーキ位置前なら加速度を 0 にする */
    if (ball->velocity >= ball->max_velocity) {
      ball->velocity = ball->max_velocity;
      if( ball->position < ball->brake_position)
        ball->accel = 0.0;
    }

    ball->position = ball->position + ball->velocity * DELTA;
}

/* ball についてのシミュレーションを開始する．結果はファイルfpに書き出す  */
void startSimulation(FILE *fp, struct ballType *ball)
{
    double simtime;  /* 時刻 */

    /* ボールの初期値を画面に表示 */
    printf("初期値: 位置 = %f, 速度 = %f, 加速度 = %f, ブレーキ位置 = %f, ブレーキ加速度 = %f, 最高速度 = %f\n",
           ball->position, ball->velocity, ball->accel,
           ball->brake_position, ball->brake_accel, ball->max_velocity);

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

    /* 最高速度となる位置、真の最高速度(加速が遅くて最高速度到達前にブレーキを掛ける場合) */
    double vmaxpos, vmax;

    /* 書き込み用ファイル sim.txt を開く */
    fp = fopen("sim.txt", "w");

    if (fp == NULL) {
	/* ファイルが開けないのでエラーメッセージを表示して終了 */
	printf("Can't open file: sim.txt\n");
	exit(1);
    }

    /* ボール位置の初期値を設定 */
    ball.position = 0;  /* 0m */

    /* 初速度を 0 に設定 */
    ball.velocity = 0.0;

    /* ボールの初期加速度の入力 */
    printf("初期加速度: ");
    scanf("%lf", &ball.accel);

    /* ボールの最高速度の入力 */
    printf("最高速度: ");
    scanf("%lf", &ball.max_velocity);

    /* ブレーキをかける位置の入力 */
    printf("ブレーキ開始位置: ");
    scanf("%lf", &ball.brake_position);

    /*
    do{
      printf("ブレーキの強さ(負の加速度): ");
      scanf("%lf", &ball.brake_accel);
    
      if (ball.brake_accel >= 0.0)
        puts("ブレーキの強さは負の値を入力してください。");
    
    } while (ball.brake_accel >= 0.0);
    */

    /* 初期加速度から最高速度になる位置を求め、ブレーキ位置より後なら 実際の最高速度 vmax を求める */
    vmaxpos = ball.max_velocity * ball.max_velocity / (2.0 * ball.accel);
    if( vmaxpos > ball.brake_position )
      vmax = sqrt(2.0*ball.accel*ball.brake_position); /* 設定上の最高速度にならない */
    else
      vmax = ball.max_velocity;

    /* 実際の最高速度とブレーキ位置から最適なブレーキ加速度を計算 */
    /* 1/2 * v^2 = -a * (WALLPOS - brake_pos) から a を求める  */
    ball.brake_accel = -0.5 * vmax * vmax / (WALLPOS - ball.brake_position);

    printf("最高速度となる位置: %.2lf\n", vmaxpos);
    printf("実際の最高速度: %.2lf\n", vmax);
    printf("ブレーキの強さ(負の加速度): %.2lf\n", ball.brake_accel);

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
