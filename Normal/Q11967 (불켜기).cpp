#include <iostream>
#include <string.h> // for memset

using namespace std;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool light[102][102] = { false, };
int order[20002][4] = { 0, };
int N, M;
bool endbfs = false;

void qsort(int left, int right)
{
	int i = left, j = right;
	int pivot = order[(i + j) / 2][0];
	int t0, t1, t2, t3;
	while (i <= j) {
		while (order[i][0] < pivot) i++; // pivot보다 왼쪽 위치 값중 큰 것 찾기
		while (order[j][0] > pivot) j--; // pivot보다 오른쪽 위치 값중 작은 것 찾기
		if (i <= j) {
			t0 = order[i][0], t1 = order[i][1], t2 = order[i][2], t3 = order[i][3];
			order[i][0] = order[j][0], order[i][1] = order[j][1], order[i][2] = order[j][2], order[i][3] = order[j][3];
			order[j][0] = t0, order[j][1] = t1, order[j][2] = t2, order[j][3] = t3;
			i++;
			j--;
		}
	}
	if (left < j) qsort(left, j); // divide and conquer
	if (i < right) qsort(i, right);
}

void bfs(int a, int b)
{
	int num = 0;
	int **q = new int*[2];
	for (int i = 0; i < 2; i++) {
		q[i] = new int[250000];
		memset(q[i], 0, sizeof(int) * 250000);
	} // C++ 이차원배열 동적할당

	int front = 0, rear = 0;
	bool checked[102][102] = { false, };
	checked[a][b] = true;
	q[0][rear] = a;
	q[1][rear++] = b;

	while (front <= rear)
	{
		int x = q[0][front];
		int y = q[1][front++];

		for (int i = 0; i < M; i++) {
			if (order[i][0] < x) continue;
			else if (order[i][0] == x) {
				if (order[i][1] != y) continue;
				if (!light[order[i][2]][order[i][3]]) num++; // 새로 켜지는 방 개수 check
				light[order[i][2]][order[i][3]] = true;
			}
			else break; // 검색 좀더 빠르게
		}

		for (int i = 0; i < 4; i++) {
			if (x + dx[i] >= 1 && x + dx[i] <= N && y + dy[i] >= 1 && y + dy[i] <= N && !checked[x + dx[i]][y + dy[i]] && light[x + dx[i]][y + dy[i]]) {
				checked[x + dx[i]][y + dy[i]] = true;
				q[0][rear] = x + dx[i];
				q[1][rear++] = y + dy[i];
			}
		}
	}

	for (int i = 0; i < 2; i++) delete[] q[i];
	delete[] q; // C++ 메모리 해제
	if (num == 0) endbfs = true; // 새로 켜진 방 없으면 종료
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	// int T;
	// cin >> T;
	// while (T--)
	// {
	cin >> N >> M;
	for (int i = 0; i < M; i++) cin >> order[i][0] >> order[i][1] >> order[i][2] >> order[i][3];
	qsort(0, M - 1);

	light[1][1] = true;
	while (!endbfs) bfs(1, 1);

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) if (light[i][j]) answer++;
	}
	cout << answer << "\n";
	// }

	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11967
// USACO 15/12 Silver 1번
// BFS