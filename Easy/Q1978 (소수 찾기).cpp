#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#define MAX_N 1000

using namespace std;

int n;
unsigned char prime[(MAX_N + 7) / 8]; 

inline bool isPrime(int x) { // x�� �Ҽ����� üũ
	return prime[x >> 3] & (1 << (x & 7));
}

inline void notset(int x) { // x�� �Ҽ��� �ƴ�
	prime[x >> 3] &= ~(1 << (x & 7));
}

void erathsthenes() {
	int i, j;
	for (i = 0; i < (MAX_N + 7) / 8; i++) prime[i] = 255;
	notset(0), notset(1);

	for (i = 2; i * i <= MAX_N; i++) {
		if (isPrime(i)) { // �Ҽ���, ��� ����
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

// ��ó : https://www.acmicpc.net/problem/1978
// 1978 �Ҽ� ã��
// �����佺�׳׽��� ü + ��Ʈ����ũ