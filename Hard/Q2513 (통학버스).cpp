#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

struct bus{
	int x, y;
};

bool cmp(bus a, bus b) {
	return a.x < b.x;
}

using namespace std;

int N, K, S;
bus ar[100001];

int main(void)
{
	int i, a, b, t, tn, idx = 0, ans;
	scanf("%d %d %d", &N, &K, &S);
	
	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		ar[i] = { a, b };
		if (a < S) ++idx;
	}

	sort(&ar[0], &ar[N], cmp); // [begin, end)

	ans = 0, t = 0, tn = 0;
	for (i = 0; i < idx; ++i) { // 먼 곳에 있는 학생부터 태운다
		if (K - tn >= ar[i].y) {
			tn += ar[i].y;
			ar[i].y = 0;
		} else {
			ar[i].y = ar[i].y - (K - tn);
			ans += abs(S - ar[t].x) * 2;
			t = i, tn = 0;
			--i;
		}
		if (i == idx - 1) ans += abs(S - ar[t].x) * 2; // 문제없이 도착
	}

	t = N - 1, tn = 0;
	for (i = N - 1; i >= idx; --i) {
		if (K - tn >= ar[i].y) {
			tn += ar[i].y;
			ar[i].y = 0;
		} else {
			ar[i].y = ar[i].y - (K - tn);
			ans += abs(ar[t].x - S) * 2;
			t = i, tn = 0;
			++i;
		}
		if (i == idx) ans += abs(ar[t].x - S) * 2; // 문제없이 도착
	}
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2513
// 12 초등부 3번 2513
// 정렬 + 그리디(수학)