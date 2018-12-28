#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int N, h[10], l[10];
bool check[10];
char ar[10];
bool fin;

void high(int idx)
{
	if (idx == N + 1) {
		fin = true;
		return;
	}

	int i;
	if (idx == 0) {
		for (i = 9; i >= 0; i--) {
			if (check[i]) continue;
			h[idx] = i, check[i] = true;
			high(idx + 1);
			if (fin) return;
			h[idx] = -1, check[i] = false;
		}
	}
	else {
		if (ar[idx - 1] == '<') {
			for (i = 9; i >= h[idx - 1] + 1; i--) {
				if (check[i]) continue;
				h[idx] = i, check[i] = true;
				high(idx + 1);
				if (fin) return;
				h[idx] = -1, check[i] = false;
			}
		}
		else if (ar[idx - 1] == '>') {
			for (i = h[idx - 1] - 1; i >= 0; i--) {
				if (check[i]) continue;
				h[idx] = i, check[i] = true;
				high(idx + 1);
				if (fin) return;
				h[idx] = -1, check[i] = false;
			}
		}
	}
}

void low(int idx)
{
	if (idx == N + 1) {
		fin = true;
		return;
	}

	int i;
	if (idx == 0) {
		for (i = 0; i <= 9; i++) {
			if (check[i]) continue;
			l[idx] = i, check[i] = true;
			low(idx + 1);
			if (fin) return;
			l[idx] = -1, check[i] = false;
		}
	}
	else {
		if (ar[idx - 1] == '<') {
			for (i = l[idx - 1] + 1; i <= 9; i++) {
				if (check[i]) continue;
				l[idx] = i, check[i] = true;
				low(idx + 1);
				if (fin) return;
				l[idx] = -1, check[i] = false;
			}
		}
		else if (ar[idx - 1] == '>') {
			for (i = 0; i <= l[idx - 1] - 1; i++) {
				if (check[i]) continue;
				l[idx] = i, check[i] = true;
				low(idx + 1);
				if (fin) return;
				l[idx] = -1, check[i] = false;
			}
		}
	}
}

int main(void)
{
	int i;
	scanf("%d\n", &N);
	for (i = 0; i < N; i++) scanf(" %c", &ar[i]);

	fin = false;
	high(0);
	for (i = 0; i < N + 1; i++) printf("%d", h[i]);
	printf("\n");

	fin = false;
	for (i = 0; i < 10; i++) check[i] = false;
	low(0);
	for (i = 0; i < N + 1; i++) printf("%d", l[i]);
	printf("\n");
	return 0;
}


// 출처 : https://www.acmicpc.net/problem/2529
// 12 지역 초등부 5번
// 그리디