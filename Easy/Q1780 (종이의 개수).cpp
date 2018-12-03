#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int map[2188][2188];
int answer[3];

void solve(int aStart, int bStart, int aEnd, int bEnd) {
	int t = aEnd - aStart;
	if (t == 1) {
		answer[map[aStart][bStart] + 1]++;
		return;
	}
	int temp = map[aStart][bStart];
	bool flag = true;
	for (int i = aStart; i < aEnd; i++) {
		for (int j = bStart; j < bEnd; j++) {
			if (map[i][j] != temp) {
				flag = false;
				break;
			}
		}
		if (!flag) break;
	}
	if (flag) {
		answer[temp + 1]++;
		return;
	}
	else {
		int length = t / 3;
		solve(aStart, bStart, aStart + length, bStart + length);
		solve(aStart, bStart + length, aStart + length, bStart + 2 * length);
		solve(aStart, bStart + 2 * length, aStart + length, bStart + 3 * length);
		solve(aStart + length, bStart, aStart + 2 * length, bStart + length);
		solve(aStart + length, bStart + length, aStart + 2 * length, bStart + 2 * length);
		solve(aStart + length, bStart + 2 * length, aStart + 2 * length, bStart + 3 * length);
		solve(aStart + 2 * length, bStart, aStart + 3 * length, bStart + length);
		solve(aStart + 2 * length, bStart + length, aStart + 3 * length, bStart + 2 * length);
		solve(aStart + 2 * length, bStart + 2 * length, aStart + 3 * length, bStart + 3 * length);
	}
}

int main(void) {
	int i, j, N;
	scanf("%d", &N); 
	
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) scanf("%d", &map[i][j]); 
	}
	solve(0, 0, N, N);
	for (i = 0; i < 3; i++) printf("%d\n", answer[i]);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1780
// 종이의 개수
// 분할정복