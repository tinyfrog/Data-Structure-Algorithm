#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int N, ar[101], ans[100005];

int gcd(int a, int b)
{
	if (b == 0) return a;
	else return gcd(b, a % b);
}

int main(void)
{
	int i, take, idx = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	sort(&ar[0], &ar[N]);
	
	take = ar[1] - ar[0];
	for (i = 2; i < N; i++) take = gcd(take, ar[i] - ar[i - 1]);

	for (i = 2; i * i <= take; i++) {
		if (!(take % i)) {
			ans[idx++] = i;
			if (i * i != take) ans[idx++] = take / i;
		}
	}
	sort(&ans[0], &ans[idx]);
	
	for (i = 0; i < idx; i++) printf("%d ", ans[i]);
	printf("%d\n", take);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2981
// 2981 COCI #6 3번 검문
// 수학(최대공약수)