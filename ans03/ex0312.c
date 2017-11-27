/* -*- coding: utf-8 -*- */
/*
 [氏名]
 [学生番号]
*/

#include <stdio.h>

#define TRUE	(1)

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int input_total(void)
{
	int coins;
	
	do {
		printf("コインの総数(奇数枚)を入力: ");
		scanf("%d", &coins);
	} while (coins % 2 == 0 || coins <= 0);

	return coins;
}

int input_coins(int player, int max)
{
	int n;
	
	do {
		printf("プレイヤー%d: 何枚? (1-%d)> ", player + 1, max);
		scanf("%d", &n);
	} while (n < 1 || max < n);

	return n;
}

int next(int turn)
{
	return (turn + 1) % 2;
}

int main(void)
{
	int coins;
	int turn;
	int n;
	int p1, p2;

	p1 = 0; p2 = 0;
	
	coins = input_total();
	turn = 0;
	do {
		n = input_coins(turn, min(4, coins));
		coins = coins - n;
		if (turn == 0) {
			p1 = p1 + n;
		} else {
			p2 = p2 + n;
		}
		turn = next(turn);
	} while (coins > 0);

	printf("プレイヤー1: %d枚\n", p1);
	printf("プレイヤー2: %d枚\n", p2);
	
	if (p1 % 2 == 0) {
		printf("プレイヤー1の勝ち\n");
	} else {
		printf("プレイヤー2の勝ち\n");
	}

	return 0;
}
