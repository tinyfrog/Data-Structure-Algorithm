#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	int a, b, c, d, sum;

	for (a = 6; a <= 100; a++) {
		sum = a * a * a;
		for (b = 2; b < a; b++) {
			for (c = b + 1; c < a; c++) {
				for (d = c + 1; d < a; d++) {
					int t = b*b*b + c*c*c + d*d*d;
					if (t > sum) break;
					else if (t == sum) {
						printf("Cube = %d, Triple = (%d,%d,%d)\n", a, b, c, d);
						continue;
					}
				}
			}
		}
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/4690
// 4690 완전 세제곱
// 브루트 포스