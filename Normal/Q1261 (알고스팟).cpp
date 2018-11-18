#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_SIZE 1000001

struct path {
	int a, b, len;
};

path heap[MAX_SIZE];
int map[101][101];
bool check[101][101];
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1 ,1 };
int M, N, ans;
int heapSize = 0;

void heapPush(path value)
{
	heap[heapSize] = value;

	int current = heapSize;
	while (current > 0 && heap[current].len < heap[(current - 1) / 2].len)
	{
		path temp = heap[(current - 1) / 2];
		heap[(current - 1) / 2] = heap[current];
		heap[current] = temp;
		current = (current - 1) / 2;
	}

	heapSize = heapSize + 1;
}

path heapPop(void)
{
	path value = heap[0];
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
			child = heap[current * 2 + 1].len < heap[current * 2 + 2].len ? current * 2 + 1 : current * 2 + 2;
		}

		if (heap[current].len < heap[child].len)
		{
			break;
		}

		path temp = heap[current];
		heap[current] = heap[child];
		heap[child] = temp;

		current = child;
	}
	return value;
}

void go()
{
	int i, max;
	heapPush({ 0, 0, 0 });

	while (true)
	{
		path temp = heapPop();
		int ta = temp.a, tb = temp.b, len = temp.len;
		if (ta == N-1 && tb == M-1) { // 도착
			ans = len;
			break;
		}
		for (i = 0; i < 4; i++) {
			if (ta + dx[i] < 0 || ta + dx[i] >= N || tb + dy[i] < 0 || tb + dy[i] >= M || check[ta + dx[i]][tb + dy[i]]) continue;
			else {
				check[ta + dx[i]][tb + dy[i]] = true;
				if(map[ta + dx[i]][tb + dy[i]] == 1) heapPush({ ta + dx[i], tb + dy[i], len + 1 });
				else if(map[ta + dx[i]][tb + dy[i]] == 0) heapPush({ ta + dx[i], tb + dy[i], len });
			}
		}
	}
}

int main(void) // 최단경로는 bfs + PQ
{
	int i, j;
	scanf("%d %d", &M, &N);

	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) scanf("%1d", &map[i][j]);
	}
	check[0][0] = true;
	go();

	printf("%d\n", ans);
	return 0;
}