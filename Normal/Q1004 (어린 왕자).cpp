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
	int i, j, cases, answer, planet, rad;
	Point start, end, mid;
	scanf("%d", &cases);
	for (i = 0; i < cases; i++) {
		answer = 0;
		scanf("%d %d %d %d", &start.x, &start.y, &end.x, &end.y);
		scanf("%d", &planet);
		for (j = 0; j < planet; j++) {
			scanf("%d %d %d", &mid.x, &mid.y, &rad);

			if ((rad * rad) >(start.x - mid.x) * (start.x - mid.x) + (start.y - mid.y) * (start.y - mid.y) || (rad * rad) > (end.x - mid.x) * (end.x - mid.x) + (end.y - mid.y) * (end.y - mid.y)) ++answer;
			if ((rad * rad) > (start.x - mid.x) * (start.x - mid.x) + (start.y - mid.y) * (start.y - mid.y) && (rad * rad) > (end.x - mid.x) * (end.x - mid.x) + (end.y - mid.y) * (end.y - mid.y)) --answer;
		} // 한 원안에 시작점, 도착점 둘다 있는 경우
		printf("%d\n", answer);
	}
	return 0;
}

// 문제 : https://www.acmicpc.net/problem/1004
