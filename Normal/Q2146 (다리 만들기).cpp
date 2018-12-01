#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 500000

struct maze {
	int x, y, num;
} heap[MAX_SIZE];

bool island[101][101];
bool check[101][101];
int map[101][101];
int ans, N, nland = 0, heapSize = 0;
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int min(int x, int y)
{
	return (x <= y) ? x : y;
}

void heapInit(void)
{
	heapSize = 0;
}

int heapPush(maze value)
{
	if (heapSize + 1 > MAX_SIZE)
	{
		printf("queue is full!");
		return 0;
	}

	heap[heapSize] = value;

	int current = heapSize;
	while (current > 0 && heap[current].num < heap[(current - 1) / 2].num)
	{
		maze temp = heap[(current - 1) / 2];
		heap[(current - 1) / 2] = heap[current];
		heap[current] = temp;
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;

	return 1;
}

maze heapPop()
{
	maze value = heap[0];
	heapSize = heapSize - 1;
	heap[0] = heap[heapSize];

	int current = 0;
	while (current * 2 + 1 < heapSize)
	{
		int child;
		if (current * 2 + 2 == heapSize)
		{
			child = current * 2 + 1;
		}
		else
		{
			child = heap[current * 2 + 1].num < heap[current * 2 + 2].num ? current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current].num < heap[child].num)
		{
			break;
		}

		maze temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		current = child;
	}
	return value;
}

void bfs(int x, int y, int num) // 탐색
{
	int i;
	check[x][y] = true;
	heapPush({ x, y, 0 });
	bool flag = false;

	while (true)
	{
		maze t = heapPop();
		int tx = t.x, ty = t.y, tn = t.num;

		if (tn >= ans) break; // 의미 X
		for (i = 0; i < 4; i++) { // 탈출조건
			if (tx + dx[i] < 0 || tx + dx[i] >= N || ty + dy[i] < 0 || ty + dy[i] >= N) continue;
			else {
				if (map[tx + dx[i]][ty + dy[i]] != 0 && map[tx + dx[i]][ty + dy[i]] != num){
					ans = min(ans, tn);
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) break;

		for (i = 0; i < 4; i++) {
			if (tx + dx[i] < 0 || tx + dx[i] >= N || ty + dy[i] < 0 || ty + dy[i] >= N || check[tx + dx[i]][ty + dy[i]]) continue;
			else {
				check[tx + dx[i]][ty + dy[i]] = true; // 바다일때는 체크 X
				if (map[tx + dx[i]][ty + dy[i]] == 0) heapPush({ tx + dx[i], ty + dy[i], tn + 1 });
				else heapPush({ tx + dx[i], ty + dy[i], tn });
			}
		}
	}
}

void dfs(int tx, int ty, int num) // 섬 번호 붙이기
{
	int i;
	for (i = 0; i < 4; i++) {
		if (tx + dx[i] < 0 || tx + dx[i] >= N || ty + dy[i] < 0 || ty + dy[i] >= N || island[tx + dx[i]][ty + dy[i]] || map[tx + dx[i]][ty + dy[i]] == 0) continue;
		else {
			island[tx + dx[i]][ty + dy[i]] = true;
			map[tx + dx[i]][ty + dy[i]] = nland;
			dfs(tx + dx[i], ty + dy[i], nland);
		}
	}
}

int main(int argc, char* argv[])
{
	int i, j;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) scanf("%d", &map[i][j]);
	}

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (map[i][j] == 1 && !island[i][j]) {
				heapInit();
				++nland;
				island[i][j] = true;
				map[i][j] = nland;
				dfs(i, j, nland);
			}
		}
	}

	ans = 987654321;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++) {
			if (!check[i][j] && map[i][j] != 0) bfs(i, j, map[i][j]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2146
// DFS (섬 번호매기기) + BFS (최단경로)