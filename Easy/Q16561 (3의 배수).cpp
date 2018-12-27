#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	int N;
	scanf("%d", &N);
	N /= 3;
	N -= 3;

	printf("%d\n", (N + 2) * (N + 1) / 2);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/16561
// 16561 3의 배수
// 수학
