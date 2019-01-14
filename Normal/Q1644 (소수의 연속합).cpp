#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int ar[500001];
bool check[4000001];

int main(void)
{
	int i, j, N, ans = 0, idx = 0;
	scanf("%d", &N);

	for (i = 2; i * i <= 4000000; i++) {
		if (check[i]) continue;
		for (j = i * 2; j <= 4000000; j += i) check[j] = true;
	}

	for (i = 2; i <= 4000000; i++) {
		if (!check[i]) ar[idx++] = i;
	}
	
	int l = 0, r = 0, sum = ar[0];
	while (r < idx && r >= l)
	{
		if (sum == N) {
			ans++;
			sum += ar[++r];
			sum -= ar[l++];
		}
		else if (sum > N) sum -= ar[l++];
		else sum += ar[++r];
	}

	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1644
// 05 도쿄 지역 A번
// 슬라이딩 윈도우 + 소수(에라토스테네스의 체)

