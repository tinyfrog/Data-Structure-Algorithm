#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

typedef vector<vector<long long>> matrix;
const long long mod = 1000000007LL;

matrix operator * (const matrix &a, const matrix &b) {
	int i, j, k;
	int n = a.size();
	matrix c(n, vector<long long>(n));
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (k = 0; k < n; k++) {
				c[i][j] += a[i][k] * b[k][j];
			}
			c[i][j] %= mod;
		}
	}
	return c;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	else return gcd(b, a%b);
}

int main(void)  // 피사노 주기는 나누는 수가 10의 거듭제곱 꼴일때만 가능
{
	long long n, m, num;
	scanf("%lld %lld", &n, &m);

	if (n >= m) num = gcd(n, m);
	else num = gcd(m, n);

	matrix ans = { { 1, 0 },{ 0, 1 } };
	matrix a = { { 1, 1 },{ 1, 0 } };

	while (num > 0) {
		if (num % 2 == 1) {
			ans = ans * a;
		}
		a = a * a;
		num /= 2;
	}

	printf("%lld\n", ans[0][1]);
	return 0;
}