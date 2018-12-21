#define _CRT_SECURE_NO_WARNINGS

typedef long long ll;
#include <cstdio>

using namespace std;

int ar[500001];

int main(void)
{
	int i, N;
	ll ans = 0, sum = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &ar[i]);
		sum += ar[i];
	}

	for (i = 0; i < N; i++) {
		sum -= ar[i];
		ans += sum * ar[i];
	}

	printf("%lld\n", ans);
	return 0;
}

// ÃâÃ³ : https://www.acmicpc.net/problem/16208
// 16208 ±ÍÂúÀ½
// ¼öÇÐ(?)