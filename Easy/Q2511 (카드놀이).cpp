#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[2][11];

int main(void)
{
	int i, a = 0, b = 0, draw = 0;

	for (i = 0; i < 10; i++) scanf("%d", &ar[0][i]);
	for (i = 0; i < 10; i++) scanf("%d", &ar[1][i]);

	for (i = 0; i < 10; i++) {
		if (ar[0][i] > ar[1][i]) a += 3;
		else if (ar[0][i] < ar[1][i]) b += 3;
		else {
			++a, ++b, ++draw;
		}
	}

	if (a > b) printf("%d %d\nA\n", a, b);
	else if (a < b) printf("%d %d\nB\n", a, b);
	else {
		if (draw == 10) printf("%d %d\nD\n", a, b);
		else {
			for (i = 9; i >= 0; i--) {
				if (ar[0][i] > ar[1][i]) {
					printf("%d %d\nA\n", a, b);
					break;
				}
				else if (ar[0][i] < ar[1][i]) {
					printf("%d %d\nB\n", a, b);
					break;
				}
			}
		}
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2511
// 2012 초등부 1번
// 구현