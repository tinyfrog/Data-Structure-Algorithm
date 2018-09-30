#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct _st {
	int s;
	char d;
} order;

typedef struct str {
	int x, y;
} Point;

int map[102][102];
order ar[101];
Point q[1000001];
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { -1, 1, 0, 0 }; // 좌우상하

int main(void)
{
	int i, N, K, L, a, b;
	int ans = 0, dir = 1, sx = 1, sy = 1, check = 0;
	int rear = 0, front = 0;
	scanf("%d %d", &N, &K);

	for (i = 0; i < K; i++) {
		scanf("%d %d", &a, &b);
		map[a][b] = 1;
	}

	scanf("%d", &L);
	for (i = 0; i < L; i++) {
		scanf(" %d %c", &ar[i].s, &ar[i].d);
	}

	map[sx][sy] = 2; // 뱀 위치
	q[rear].x = sx, q[rear++].y = sy;
	while (true)
	{
		++ans;
		sx += dx[dir], sy += dy[dir];
		if (map[sx][sy] == 0) { // 이 경우에는 성장하지 않으므로, 꼬리이동
			map[q[front].x][q[front].y] = 0;
			++front;
		}
		if (sx == 0 || sx == N+1 || sy == 0 || sy == N+1 || map[sx][sy] == 2) break; // 충돌
		
		map[sx][sy] = 2;
		q[rear].x = sx, q[rear++].y = sy;

		if (check < L && ans == ar[check].s) { // 방향 전환
			if (ar[check].d == 'D') {
				if (dir == 0) dir = 2;
				else if (dir == 1) dir = 3;
				else if (dir == 2) dir = 1;
				else dir = 0;
			}
			else if (ar[check].d == 'L') {
				if (dir == 0) dir = 3;
				else if (dir == 1) dir = 2;
				else if (dir == 2) dir = 0;
				else dir = 1;
			}
			++check;
		}
	}

	printf("%d\n", ans);
	return 0;
}  

// 문제 : https://www.acmicpc.net/problem/3190
