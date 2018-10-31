#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int max(int x, int y) {
	return (x >= y) ? x : y;
}

int main(void)
{
	char S;
	int N, D, M, ans = 0, mario[2] = { 0 }, front = 0;
	scanf("%d %d", &N, &D);
	while (N--) {
		scanf(" %c-%d", &S, &M);
		ans = max(ans, M - mario[front]); // 앞서 나갈 마리오와 M 까지의 거리
		mario[front] = M; // 앞서 나갈 마리오를 M으로 이동
		front = 1 - front; // 앞 마리오로 바꿈
		if (S == 'W') mario[front] = M; // 나무토막이면 앞에 있던 마리오도 M으로 이동
	}
	ans = max(ans, D - mario[front]); // 마지막
	printf("%d\n", ans);
}

// 왔다 돌아오는 케이스는 이렇게 푸는 방법도 생각해보자