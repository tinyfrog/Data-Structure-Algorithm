#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define INF 987654321;

typedef struct _point {
	int x, y;
	_point() {
		x = 0, y = 0;
	}
	_point(int _x, int _y) {
		x = _x, y = _y;
	}
} point;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int map[126][126];
int dp[126][126];
point queue[700000];

int bfs(int len)
{
	int i, rear = 0, front = 0, ans = INF;
	queue[rear++] = { 0, 0 };
	
	while (rear > front)
	{
		point temp = queue[front++];
		if (temp.x == len - 1 && temp.y == len - 1) {
			if (dp[temp.x][temp.y] < ans) ans = dp[temp.x][temp.y];
			continue;
		}

		for (i = 0; i < 4; i++) {
			int tx = temp.x + dx[i];
			int ty = temp.y + dy[i];
			if (tx >= 0 && tx < len && ty >= 0 && ty < len && dp[tx][ty] > dp[temp.x][temp.y] + map[tx][ty]) {
				dp[tx][ty] = dp[temp.x][temp.y] + map[tx][ty];
				queue[rear++] = { tx, ty };
			}
		}
	}

	return ans;
}

int main(void)
{
	int num = 1;
	while (true)
	{
		int i, j, N;
		scanf("%d", &N);

		if (N == 0) break;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &map[i][j]);
				dp[i][j] = INF;
			}
		}

		dp[0][0] = map[0][0];
		printf("Problem %d: %d\n", num, bfs(N));
		++num;
	}
	return 0;
}