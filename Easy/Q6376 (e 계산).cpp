#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	int i;
	printf("n e\n");
	printf("- -----------\n");
	printf("0 1\n");
	printf("1 2\n");
	printf("2 2.5\n");

	double mul = 2, ans = 2.5;
	for (i = 3; i <= 9; i++) {
		mul *= (double)i;
		ans += (double)1 / mul;
		printf("%.0f %.9f\n", (double)i, ans);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/6376
// 6376 e 계산
// 구현, 출력
