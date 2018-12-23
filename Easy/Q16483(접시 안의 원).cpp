#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <cstdio>
#include <cmath>

int main(void)
{
	int T;
	scanf("%d", &T);

	if (T % 2) printf("%d\n", (int)floor(((float)T/2) * ((float)T/2) + 0.5));
	else printf("%d\n", (T / 2) * (T / 2));
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/16483
// 16483 접시 안의 원
// 수학, C++(반올림)