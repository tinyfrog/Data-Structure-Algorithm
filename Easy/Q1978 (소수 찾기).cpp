#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX_N 1000

using namespace std;

int n;
unsigned char prime[(MAX_N + 7) / 8]; 

inline bool isPrime(int x) { // x가 소수인지 체크
	return prime[x >> 3] & (1 << (x & 7));
}

inline void notset(int x) { // x는 소수가 아님
	prime[x >> 3] &= ~(1 << (x & 7));
}

void erathsthenes() {
	int i, j;
	for (i = 0; i < (MAX_N + 7) / 8; i++) prime[i] = 255;
	notset(0), notset(1);

	for (i = 2; i * i <= MAX_N; i++) {
		if (isPrime(i)) { // 소수임, 배수 제거
			for (j = i * i; j <= MAX_N; j += i) notset(j);
		}
	}
}

int main(void)
{
	int i, a, ans = 0;
	scanf("%d", &n);
	erathsthenes();
	
	for (i = 0; i < n; i++) {
		scanf("%d", &a);
		if (isPrime(a)) ans++;
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1978
// 1978 소수 찾기
// 에라토스테네스의 체 + 비트마스크