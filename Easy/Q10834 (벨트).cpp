#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int main(void)
{
	long i, M, a, b, c, mode = 0, ans = 1;
	scanf("%ld", &M);

	for (i = 0; i < M; i++) {
		scanf("%ld %ld %ld", &a, &b, &c);
		if (c == 1) {
			if (!mode) mode = 1;
			else mode = 0;
		}
		ans *= b, ans /= a;
	}

	printf("%ld %ld\n", mode, ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/10834
// 10834 15 초등부 2번 벨트
// 구현