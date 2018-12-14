#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <queue>

using namespace std;

struct pp {
	int x, y;
};

bool cmp(pp a, pp b) {
	if (a.x == b.x) return a.y <= b.y;
	else return a.x < b.x;
}

pp node[1000001];
int loc[1001];
bool visit[1001];
int answer = 0, N, M, idx;

void bfs(int start) {
	int i, t;
	queue<int> q;
	q.push(start);
	visit[start] = true;

	while (!q.empty()) {
		t = q.front();
		q.pop();
		for (i = loc[t]; node[i].x == t; i++) {
			if (!visit[node[i].y]) {
				visit[node[i].y] = true;
				q.push(node[i].y);
			}
		}
	}
}

int main(void)
{
	int i, s, d, tt;
	scanf("%d %d", &N, &M); 

	for (i = 0; i < M; i++) {
		scanf("%d %d", &s, &d);
		node[idx++] = { s, d };
	}

	sort(&node[0], &node[idx], cmp);

	tt = node[0].x;
	loc[tt] = 0;
	for (i = 1; i < idx; i++) {
		if (node[i].x != tt) {
			tt = node[i].x;
			loc[node[i].x] = i;
		}
	}

	for (i = 1; i <= N; i++) {
		if (visit[i] == false) {
			answer++;
			bfs(i);
		}
	}
	printf("%d\n", answer);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11724
// 11724 연결 요소의 개수
// dfs, bfs