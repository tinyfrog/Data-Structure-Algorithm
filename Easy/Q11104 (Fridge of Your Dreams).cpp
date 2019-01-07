#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

char ar[25];
int cal[25];

int main(void)
{
	int i, j, n, sum, t = 1;

	for (i = 23; i >= 0; i--) {
		cal[i] = t;
		t *= 2;
	}
	scanf("%d", &n);

	for (i = 0; i < n; i++) {
		scanf(" %s", &ar);
		sum = 0;
		for (j = 0; j < 24; j++) {
			if (ar[j] == '1') sum += cal[j];
		}
		printf("%d\n", sum);
	}

	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11104
// 11104 Fridge of Your Dreams
// 구현