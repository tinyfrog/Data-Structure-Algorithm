#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _st {
	int x, y;
	_st() {
		x = 0, y = 0;
	}
} Point;

int main(void)
{
	int i, cases, d1, d2, d3;
	scanf("%d", &cases);
	Point j, b;
	int jr, br;

	for (i = 0; i < cases; i++) {
		scanf("%d %d %d %d %d %d", &j.x, &j.y, &jr, &b.x, &b.y, &br);

		d1 = (j.x - b.x) * (j.x - b.x) + (j.y - b.y) * (j.y - b.y);
		d2 = (jr + br) * (jr + br);
		d3 = (jr - br) * (jr - br);

		if (d1 > d2) printf("0\n");
		else if ((d1 == d2 || d1 == d3) && d1 != 0) printf("1\n"); // 함정 주의
		else if (d1 > d3) printf("2\n");
		else if (d1 == 0 && d3 == 0) printf("-1\n"); // 중심도 같고, 반지름도 같고
		else printf("0\n");
	}
	return 0;
}