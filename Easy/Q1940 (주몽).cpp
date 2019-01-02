#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int ar[15001];

int main(void)
{
	int i, j, N, M, t, cnt = 0;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	sort(&ar[0], &ar[N]);

	i = 0, j = N - 1;
	while (i < j) {
		t = ar[i] + ar[j];
		if (t == M) cnt++, i++, j--;
		else if (t < M) i++;
		else j--;
	}

	printf("%d\n", cnt);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1940
// 1940 주몽
// 슬라이딩 윈도우