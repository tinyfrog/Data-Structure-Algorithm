#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct node {
	int a, b;
} parent[200001], temp[200001];

void sort(int s, int e)
{
	if (s >= e) return;
	int i, l, r, idx, mid = (s + e) / 2;

	sort(s, mid);
	sort(mid + 1, e);

	l = s, r = mid + 1, idx = s;
	while (l <= mid && r <= e) temp[idx++] = (parent[l].a <= parent[r].a) ? parent[l++] : parent[r++];
	while (l <= mid) temp[idx++] = parent[l++];
	while (r <= e) temp[idx++] = parent[r++];

	for (i = s; i <= e; i++) parent[i] = temp[i];
	return;
}

int loc[100002];
int ans[100002];

void dfs(int num) {
	int i;

	for(i = loc[num]; i < loc[num+1]; i++) {
		if (ans[parent[i].b] == 0) {
			ans[parent[i].b] = parent[i].a;
			dfs(parent[i].b);
		}
	}
}

int main(void)
{
	int i, N, num;
	scanf("%d", &N);

	for (i = 0; i < N-1; i++) {
		scanf("%d %d", &parent[2*i].a, &parent[2*i].b);
		parent[2 * i + 1].b = parent[2 * i].a;
		parent[2 * i + 1].a = parent[2 * i].b;
	}

	sort(0, 2*N - 3);
	loc[1] = 0, loc[N+1] = 2*N-2, num = 1;
	for (i = 1; i < 2*N - 2; i++) {
		if (parent[i].a != num) {
			loc[parent[i].a] = i;
			num = parent[i].a;
		}
	}

	dfs(1);

	for (i = 2; i <= N; i++) printf("%d\n", ans[i]);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11725
// 소트 + dfs