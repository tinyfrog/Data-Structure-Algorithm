#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

void Hanoi(int n, int a, int b, int c) { // 1 ~ n 높이를 a에서 b로 옮김
	if (n == 1) {
		printf("%d %d\n", a, b);
		return;
	}
	Hanoi(n - 1, a, c, b);
	Hanoi(1, a, b, c); // 가장 아래에 있는 것을 a -> b로 옮김
	Hanoi(n - 1, c, b, a);
}

int main(void)
{
	int N;
	scanf("%d", &N);
	printf("%d\n", (int)pow(2, N) - 1);

	Hanoi(N, 1, 3, 2);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11729
// 11729 하노이 탑 이동 순서
// 분할정복(재귀)