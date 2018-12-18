#define _CRT_SECURE_NO_WARNINGS
typedef long long ll;
#include <cstdio>
#include <algorithm>

using namespace std;

int N;
ll ar[100001], sum[100001];

ll dc(int s, int e)
{
	if (s == e) return ar[s] * ar[s]; // base 

	int mid = (s + e) / 2;
	ll ret = max(dc(s, mid), dc(mid + 1, e));

	int left = mid, right = mid + 1;
	ll rets = min(ar[left], ar[right]);
	ret = max(ret, (ar[left] + ar[right]) * rets);

	while (s < left || right < e) {
		if (s == left || (right < e && ar[right + 1] > ar[left - 1])) right++, rets = min(rets, ar[right]);
		else left--, rets = min(rets, ar[left]);

		if (left == -1) left = 0;
		ret = max(ret, (sum[right] - sum[left - 1]) * rets);
	}
	return ret;
}

int main(void)
{
	int i;
	ll ans = 0;

	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%lld", &ar[i]);
	sum[0] = ar[0];
	for (i = 1; i < N; i++) sum[i] = ar[i] + sum[i - 1];
	
	printf("%lld\n", dc(0, N - 1));
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2104
// NEERC 2005 F번 2104 부분배열 고르기
// 분할정복