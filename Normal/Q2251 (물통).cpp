#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>

using namespace std;

struct st {
	int x, y, z;
};

bool ans[201], check[201][201][201];

void bucket(int a, int b, int c)
{
	queue<st> q;
	q.push({ 0, 0, c });

	while (!q.empty()) {
		st t = q.front(); q.pop();
		if (t.x == 0 && !ans[t.z]) ans[t.z] = true;

		if (!check[min(a, t.x + t.z)][t.y][max(0, t.z - (a - t.x))]) {
			check[min(a, t.x + t.z)][t.y][max(0, t.z - (a - t.x))] = true;
			q.push({ min(a, t.x + t.z) , t.y, max(0, t.z - (a - t.x)) });
		} // C -> A
		if (!check[t.x][min(b, t.y + t.z)][max(0, t.z - (b - t.y))]) {
			check[t.x][min(b, t.y + t.z)][max(0, t.z - (b - t.y))] = true;
			q.push({t.x, min(b, t.y + t.z), max(0, t.z - (b - t.y))});
		} // C -> B
		if (!check[t.x][max(0, t.y - (c - t.z))][min(c, t.z + t.y)]) {
			check[t.x][max(0, t.y - (c - t.z))][min(c, t.z + t.y)] = true;
			q.push({ t.x , max(0, t.y - (c - t.z)), min(c, t.z + t.y) });
		} // B -> C
		if (!check[min(a, t.x + t.y)][max(0, t.y - (a - t.x))][t.z]) {
			check[min(a, t.x + t.y)][max(0, t.y - (a - t.x))][t.z] = true;
			q.push({ min(a, t.x + t.y) , max(0, t.y - (a - t.x)) , t.z });
		} // B -> A
		if (!check[max(0, t.x - (b - t.y))][min(b, t.y + t.x)][t.z]) {
			check[max(0, t.x - (b - t.y))][min(b, t.y + t.x)][t.z] = true;
			q.push({ max(0, t.x - (b - t.y)) , min(b, t.y + t.x) , t.z});
		} // A -> B
		if (!check[max(0, t.x - (c - t.z))][t.y][min(c, t.z + t.x)]) {
			check[max(0, t.x - (c - t.z))][t.y][min(c, t.z + t.x)] = true;
			q.push({ max(0, t.x - (c - t.z)) , t.y, min(c, t.z + t.x) });
		} // A -> C
	}
}

int main(void)
{
	int i, a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	check[0][0][c] = true;
	ans[c] = true;
	bucket(a, b, c);

	for (i = 0; i <= c; i++) if (ans[i]) printf("%d ", i);
	printf("\n");
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2251
// 2251 물통
// DP, BFS