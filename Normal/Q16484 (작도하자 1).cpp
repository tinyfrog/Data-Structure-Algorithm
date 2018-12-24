#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <cstdio>
#include <cmath>

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);

	printf("%.1f\n", (floor(((double(a)/2 - b) * 10 + 0.5)) / 10));
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/16484
// 16484 작도하자1
// 나비 정리(Butterfly theorem)