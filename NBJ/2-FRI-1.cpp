#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int h, w, N;
char map[101][101];

int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int min(int a, int b)
{
	return (a <= b) ? a : b;
}

void create(int a, int b, int c, int d, char word)
{
	int i, j;
	for (i = max(a, 0); i < min(a + c, h); i++) {
		for (j = max(b, 0); j < min(b + d, w); j++)
		{
			if (i == a || i == a + c - 1)
			{
				if (j == b || j == b + d - 1) map[i][j] = '+';
				else map[i][j] = '-';
			}
			else if (j == b || j == b + d - 1) map[i][j] = '|';
			else map[i][j] = word;
		}
	}
}

int main(void)
{
	int i, j;
	int th, tw, thl, twl;
	char fill;

	scanf("%d %d %d", &h, &w, &N);

	while (N--) {
		scanf(" %d %d %d %d %c", &th, &tw, &thl, &twl, &fill);
		create(th, tw, thl, twl, fill);
	}

	for (i = 0; i < h; i++) {
		for (j = 0; j < w; j++) {
			if (map[i][j] == 0) printf(" ");
			else printf("%c", map[i][j]);
		}
		printf("\n");
	}
	return 0;
}

// char 배열의 경우 컴파일러에 따라 초기화 안될 수 있음
// 출력 때 null 일 경우 공백 출력하기