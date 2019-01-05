#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

int R, C;
int s, w; // 양, 늑대
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
char map[251][251];
bool ch[251][251];

struct pt {
	int x, y;
} temp[100001];

void battle(pt p)
{
	int i, idx = 0, sn = 0, wn = 0;
	pt n;
	temp[idx++] = p;

	while (idx != 0) {
		n = temp[--idx];
		if (map[n.x][n.y] == 'v') wn++;
		else if (map[n.x][n.y] == 'o') sn++;

		for (i = 0; i < 4; i++) {
			if (n.x + dx[i] < 0 || n.x + dx[i] >= R || n.y + dy[i] < 0 || n.y + dy[i] >= C || map[n.x + dx[i]][n.y + dy[i]] == '#' || ch[n.x + dx[i]][n.y + dy[i]]) continue;
			ch[n.x + dx[i]][n.y + dy[i]] = true;
			temp[idx++] = { n.x + dx[i], n.y + dy[i] };
		}
	}

	if (wn >= sn) w += wn;
	else s += sn;
	return;
}

int main(void)
{
	int i, j;
	scanf("%d %d", &R, &C);

	for (i = 0; i < R; i++) scanf("%s", map[i]);

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			if (!ch[i][j] && map[i][j] != '#') {
				ch[i][j] = true;
				battle({ i, j });
			}
		}
	}

	printf("%d %d\n", s, w);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/3184
// 3184 양
// BFS 