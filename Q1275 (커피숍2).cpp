#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef long long ll;

using namespace std;

int N, Q;
ll ar[100001];
ll tree[400001];

int min(int x, int y)
{
	return (x < y) ? x : y;
}

int max(int x, int y)
{
	return (x > y) ? x : y;
}

void init(int node, int start, int end)
{
	if (start == end) {
		tree[node] = ar[start];
		return;
	}

	int mid = (start + end) / 2;
	init(node * 2, start, mid);
	init(node * 2 + 1, mid + 1, end);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

ll query(int node, int start, int end, int left, int right)
{
	if (end < left || right < start) return 0; // ������ ���
	if (left <= start && end <= right) return tree[node]; // ���� ���ϴ� ���� �ȿ� ���� ������ ����

	int mid = (start + end) / 2;
	return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

void update(int node, int start, int end, int idx, ll val)
{
	if (idx < start || end < idx) return; // ������ ����

	if (start == end) { // idx�� ����
		tree[node] = val;
		return;
	}

	int mid = (start + end) / 2;
	update(node * 2, start, mid, idx, val);
	update(node * 2 + 1, mid + 1, end, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
	return;
}

int main(void)
{
	int i, a, x, y;
	ll b;
	scanf("%d %d", &N, &Q);

	for (i = 1; i <= N; i++) scanf("%lld", &ar[i]);
	init(1, 1, N);

	for (i = 1; i <= Q; i++) {
		scanf("%d %d %d %lld", &x, &y, &a, &b);
		printf("%lld\n", query(1, 1, N, min(x, y), max(x, y)));
		update(1, 1, N, a, b);
	}
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/1275
// 1275 Ŀ�Ǽ�2
// ���� �� Ʈ��