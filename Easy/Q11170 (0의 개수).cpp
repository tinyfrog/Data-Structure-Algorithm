#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int ar[1000001];

int cal(int n)
{
	int ans = 0;
	while (n != 0) {
		if (n % 10 == 0) ans++;
		n /= 10;
	}
	return ans;
}

int main(void)
{
	int i, T;
	scanf("%d", &T);
	
	ar[0] = 1;
	for (i = 1; i <= 1000001; i++) ar[i] += ar[i - 1] + cal(i);

	while (T--)
	{
		int N, M;
		scanf("%d %d", &N, &M);
		if (N == 0) printf("%d\n", ar[M]);
		else printf("%d\n", ar[M] - ar[N - 1]);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11170
// 11170 0의 개수
// 쉬운 문제