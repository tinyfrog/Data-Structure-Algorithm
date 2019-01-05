#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int idx, queue[26];

int main(void)
{
	int i, a, N, bef;
	while (true)
	{
		scanf("%d", &N);
		if (N == 0) break;

		idx = 0;
		scanf("%d", &a);
		queue[idx++] = a, bef = a;

		for (i = 1; i < N; i++) {
			scanf("%d", &a);
			if (a != bef) {
				queue[idx++] = a;
				bef = a;
			}
		}

		for (i = 0; i < idx; i++) {
			printf("%d ", queue[i]);
		}
		printf("$\n");
	}

	return 0;
}

// 출처 : https://www.acmicpc.net/problem/4592
// 4592 중복을 없애자
// 구현
