#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>

using namespace std;

struct st {
	int x, y, dit, did;
};

struct cmp { // STL 사용법
	bool operator()(st a, st b) {
		return a.dit > b.dit; // dit 작은 값이 앞으로 오게 한다
	}
};

int N, M;
char map[1001][1001];
bool check[1001][1001][2]; // 벽 부시지 않음, 벽 부심
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int bfs()
{
	int i, ans = -1;
	priority_queue<st, vector<st>, cmp> pq; // STL 사용법 알아두기
	check[0][0][0] = true;
	pq.push({ 0, 0, 1, 0 });

	while (!pq.empty()) {
		st temp = pq.top();
		pq.pop();

		int tx = temp.x, ty = temp.y, td = temp.dit, tb = temp.did;

		if (tx == N - 1 && ty == M - 1) {
			ans = td;
			break;
		}
		for (i = 0; i < 4; i++) {
			if (tx + dx[i] >= N || tx + dx[i] < 0 || ty + dy[i] >= M || ty + dy[i] < 0) continue;
			if (map[tx + dx[i]][ty + dy[i]] == '1') {
				if (tb == 1) continue; // 이미 벽 뚫음
				if (check[tx + dx[i]][ty + dy[i]][1]) continue;
				check[tx + dx[i]][ty + dy[i]][1] = true;
				pq.push({ tx + dx[i], ty + dy[i], td + 1, 1});
				continue;
			}
			if (tb == 0) {
				if (check[tx + dx[i]][ty + dy[i]][0]) continue;
				check[tx + dx[i]][ty + dy[i]][0] = true;
				pq.push({ tx + dx[i], ty + dy[i], td + 1, tb });
			}
			if (tb == 1) {
				if (check[tx + dx[i]][ty + dy[i]][1]) continue;
				check[tx + dx[i]][ty + dy[i]][1] = true;
				pq.push({ tx + dx[i], ty + dy[i], td + 1, tb });
			}
		}
	}
	return ans;
}

int main(void)
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++) scanf("%s", map[i]);

	printf("%d\n", bfs());
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2206
// 2206 벽 부수고 이동하기
// BFS, 기록