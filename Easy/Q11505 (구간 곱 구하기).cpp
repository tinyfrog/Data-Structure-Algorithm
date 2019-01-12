#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef long long ll;

using namespace std;

long long ar[1000001], tree[4000001];
int N, M, K;

void init(int node, int start, int end)
{
	if (start == end) {
		tree[node] = ar[start];
		return;
	}

	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
	return;
}

void update(int node, int start, int end, int idx, ll val)
{
	if (idx < start || idx > end) return;
	if (start == end) {
		tree[node] = val;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = (tree[node * 2] * tree[node * 2 + 1]) % 1000000007;
	return;
}

ll query(int node, int start, int end, int left, int right)
{
	if (left > end || start > right) return 1;
	if (left <= start && end <= right) return tree[node];

	int mid = (start + end) / 2;
	return (query(node * 2, start, mid, left, right) * query(node * 2 + 1, mid + 1, end, left, right)) % 1000000007;
}

int main(void)
{
	int i, a, b;
	ll c;
	scanf("%d %d %d", &N, &M, &K);

	for (i = 1; i <= N; i++) scanf("%lld", &ar[i]);
	init(1, 1, N);

	for (i = 1; i <= M + K; i++) {
		scanf("%d %d %lld", &a, &b, &c);
		if (a == 1) update(1, 1, N, b, c);
		else if (a = 2) printf("%lld\n", query(1, 1, N, b, c));
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11505
// 11505 구간 곱 구하기
// 구간 곱 트리