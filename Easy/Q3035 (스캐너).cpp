#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

char m1[51][51], m2[251][251];
int w, h;

int main(void)
{
	int i, j, a, b, R, C, ZR, ZC;
	scanf("%d %d %d %d", &R, &C, &ZR, &ZC);

	w = R * ZR, h = C * ZC;

	for (i = 0; i < R; i++) scanf(" %s", m1[i]);

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			for (a = i * ZR; a < (i + 1) * ZR; a++) {
				for (b = j * ZC; b < (j + 1) * ZC; b++) m2[a][b] = m1[i][j];
			}
		}
	}

	for (i = 0; i < w; i++) printf("%s\n", m2[i]);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/3035
// 06 COCI #4 2번
// 반복문