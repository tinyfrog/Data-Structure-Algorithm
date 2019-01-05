#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string>
#include <queue>
#include <iostream>

using namespace std;

struct st {
	int a, num;
	string str;
};

int D(int n)
{
	return (2 * n) % 10000;
}

int S(int n)
{
	if (n == 0) return 9999;
	else return n - 1;
}

int L(int n)
{
	return (n % 1000) * 10 + n / 1000;
}

int R(int n)
{
	return (n % 10) * 1000 + (n / 10);
}

int B;
bool check[10000];

void cal(int a)
{
	int t1, t2, t3, t4;
	st t;
	check[a] = true;
	queue<st> pq;
	pq.push({ a, 0, "" });

	while (!pq.empty())
	{
		t = pq.front();
		pq.pop();

		if (t.a == B) {
			cout << t.str << "\n";
			return;
		}

		t1 = D(t.a), t2 = S(t.a), t3 = L(t.a), t4 = R(t.a);
		if (!check[t1]) {
			check[t1] = true;
			pq.push({ t1, t.num + 1, t.str + "D" });
		}
		if (!check[t2]) {
			check[t2] = true;
			pq.push({ t2, t.num + 1, t.str + "S" });
		}
		if (!check[t3]) {
			check[t3] = true;
			pq.push({ t3, t.num + 1, t.str + "L" });
		}
		if (!check[t4]) {
			check[t4] = true;
			pq.push({ t4, t.num + 1, t.str + "R" });
		}
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int i, T, a;

	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &a, &B);
		cal(a);
		for (i = 0; i < 10000; i++) check[i] = false;
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/9019
// 대전 지역 11 D번
// BFS, 문자열 처리