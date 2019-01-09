#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

typedef long long ll;

using namespace std;

ll tree[4000001];

//ll init(int val, int node, int start, int end)
//{
//	if (start == end) return tree[node] = val;
//
//	int mid = (start + end) / 2;
//	return tree[node] = init(val, node * 2, start, mid) + init(val, node * 2 + 1, mid + 1, end);
//}

void update(int val, int node, int start, int end, int idx)
{
	if (!(start <= idx && idx <= end)) return; // 사이 index 아니면 무시
	tree[node] += val;

	if (start != end)
	{
		int mid = (start + end) / 2;
		update(val, node * 2, start, mid, idx);
		update(val, node * 2 + 1, mid + 1, end, idx);
	}
}

ll sum(int node, int start, int end, int left, int right)
{
	if (left > end || right < start) return 0;

	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return sum(node * 2, start, mid, left, right) + sum(node * 2 + 1, mid + 1, end, left, right);
}

int main(void)
{
	int i, N, Q, a, b, c;
	scanf("%d %d", &N, &Q);

	for (i = 1; i <= Q; i++) {
		scanf("%d %d %d", &a, &b, &c);
		if (a == 1) update(c, 1, 1, N, b);
		else if (a == 2) printf("%lld\n", sum(1, 1, N, b, c));
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/12837
// 12837 가계부 (Hard)
// 세그먼트 트리