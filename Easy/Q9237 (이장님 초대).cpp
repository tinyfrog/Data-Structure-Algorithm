#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <functional>

using namespace std;

int ans, ar[100001];

int main(void)
{
	int i, N;
	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	sort(&ar[0], &ar[N], greater<int>());

	for (i = 0; i < N; i++) ans = max(ans, ar[i] + i + 2);
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/9237
// 9237 이장님 초대
// 정렬