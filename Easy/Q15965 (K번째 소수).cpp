#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool check[7368788];

int main(void)
{
	int i, j, K, num = 2, ans;
	scanf("%d", &K);
	if (K == 1) {
		printf("2\n");
		return 0;
	}

	for (i = 2; i < 7368788; i += 2) {
		check[i] = true;
	}

	for (i = 3; i * i < 7368788; i += 2) {
		if (!check[i]) {
			for (j = i * i; j < 7368788; j += i) check[j] = true;
		}
	}

	for (i = 3; i < 7368788; i += 2) {
		if (!check[i]) {
			if (num == K) {
				printf("%d\n", i);
				break;
			}
			++num;
		}
	}
	return 0;
}

// 문제 : https://www.acmicpc.net/problem/15965
// 에라토스테네스의 체