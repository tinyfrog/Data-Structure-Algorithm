#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

long long sum2, sum5;

long long num2(long long a) { // 총 2의 개수 (2, 2 * 2, 2 * 2 * 2 ...)
	long long i, cnt = 0;
	for (i = 2; a / i >= 1; i *= 2) cnt += a / i;
	return cnt;
}

long long num5(long long a) { // 총 5의 개수 (5, 5 * 5, 5 * 5 * 5 ...)
	long long i, cnt = 0;
	for (i = 5; a / i >= 1; i *= 5) cnt += a / i;
	return cnt;
}

int main() {
	long long n, m;
	scanf("%lld %lld", &n, &m);
	sum5 = num5(n) - num5(m) - num5(n - m); 
	sum2 = num2(n) - num2(m) - num2(n - m);
	printf("%lld\n", min(sum5, sum2));
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2004
// 2004 조합 0의 개수
// 수학