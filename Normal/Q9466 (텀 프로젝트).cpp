#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define MAX_NUM 100001

int ar[MAX_NUM];
bool check[MAX_NUM], visit[MAX_NUM];
int n, ans;

void dfs(int idx)
{
	int i, next = ar[idx];
	check[idx] = true;

	if (!check[next]) dfs(next); // 사이클 탐색

	if (!visit[next]) { // 팀원수 구하기
		for (i = next; i != idx; i = ar[i]) ++ans;
		++ans;
	}

	visit[idx] = true;
}

int main(void)
{
	int i, T;
	scanf("%d", &T);

	while (T--)
	{
		ans = 0;
		scanf("%d", &n);
		for (i = 1; i <= n; i++) {
			check[i] = false;
			visit[i] = false;
			scanf("%d", &ar[i]);
		}
		
		for (i = 1; i <= n; i++) {
			if (!check[i]) dfs(i);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/9466
// DFS(사이클 찾기)