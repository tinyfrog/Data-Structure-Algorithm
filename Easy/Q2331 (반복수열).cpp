#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <cmath>

int A, P;
int ar[10000];
bool check[300000];

int main(void)
{
	scanf("%d %d", &A, &P);
	int i, N, sum, ans, idx = 0;
	
	check[A] = true;
	ar[idx++] = A;
	while (true)
	{
		N = A;
		sum = 0;
		while (N != 0) {
			sum += (int) pow(N % 10, P);
			N /= 10;
		}
		if (check[sum]) break;
		check[sum] = true;
		ar[idx++] = sum, A = sum;
	}

	for (i = idx - 1; i >= 0; i--) {
		if (ar[i] == sum) {
			ans = i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2331
// 2331 반복수열
// 구현

