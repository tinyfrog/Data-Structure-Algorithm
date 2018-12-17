#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;

struct room {
	int x, y;
} ar[200001];

bool cmp(room a, room b)
{
	if (a.x == b.x) return a.y < b.y; // 같다(=)는 넣으면 안됨
	else return a.x < b.x;
}

priority_queue<int, vector<int>, greater<int>> pq;

int main(void)
{
	int i, N, ans = 1;
	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d %d", &ar[i].x, &ar[i].y);
	
	sort(&ar[0], &ar[N], cmp);

	pq.push(ar[0].y);
	for (i = 1; i < N; i++) {
		if (ar[i].x < pq.top()) {
			ans++;
			pq.push(ar[i].y);
		}
		else {
			pq.pop();
			pq.push(ar[i].y);
		}
	}
	
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11000
// 11000 강의실 배정
// 그리디(+정렬, 자료구조)