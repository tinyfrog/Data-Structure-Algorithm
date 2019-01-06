#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int ar[50001], bessie[50001];
bool check[100001];

int main(void)
{
	int i, N, idx = 0, ans = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &ar[i]);
		check[ar[i]] = true;
	}
	sort(&ar[0], &ar[N]);

	for (i = 1; i <= 2 * N; i++) {
		if (!check[i]) bessie[idx++] = i;
	}

	int bessieidx = 0, eliseidx = 0;
	while (bessieidx < N && eliseidx < N) {
		if (bessie[bessieidx] > ar[eliseidx]) {
			ans++;
			bessieidx++;
			eliseidx++;
		}
		else bessieidx++;
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11968
// USACO 15/12 Silver 2번
// 수학, 게임