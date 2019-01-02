#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int prime[10000];
int idx;

bool is(int n)
{
	int i;
	for (i = 3; i * i <= n; i += 2) if (!(n % i)) return false;
	return true;
}

void cal(int n)
{
	int cnt, t = 0;

	while (n != 1)
	{
		cnt = 0;
		while (!(n % prime[t]))
		{
			++cnt;
			n /= prime[t];
		}
		if (cnt != 0) printf("%d %d\n", prime[t], cnt);
		t++;
	}
}

int main(void)
{
	int i, N, a;
	scanf("%d", &N);

	prime[0] = 2, prime[1] = 3, idx = 2;
	for (i = 5; i <= 99997; i += 2) if (is(i)) prime[idx++] = i;

	while (N--)
	{
		scanf("%d", &a);
		cal(a);
	}

	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2312
// 2312 수 복원하기
// 수학