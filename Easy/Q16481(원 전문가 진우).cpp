#define _CRT_SECURE_NO_WARNINGS

using namespace std;

#include <cstdio>

int main(void)
{
	int r1, r2, r3;
	scanf("%d %d %d", &r1, &r2, &r3);
	printf("%.6f\n", (float) (r1 * r2 * r3) / (r1*r2 + r2*r3 + r3*r1));
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/16481
// 16481 원 전문가 진우
// 수학