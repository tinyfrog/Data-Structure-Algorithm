#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <stack>

using namespace std;

int N, ar[1002];

int main(void)
{
	int i, a, b, sum = 0, start = 1001, end = -1, high = 0, idx1 = 0, idx2 = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		ar[a] = b;
		if (b > high || b == high && a > idx1) {
			high = b;
			idx1 = a, idx2 = a+1;
		}
		if (a < start) start = a;
		if (a > end) end = a;
	}

	stack<int> st1, st2;
	
	for (i = start; i <= idx1; i++) {
		if (i == start) {
			sum += ar[start];
			st1.push(ar[start]);
			continue;
		}

		if (ar[i] <= st1.top()) sum += st1.top();
		else {
			sum += ar[i];
			st1.push(ar[i]);
		}
	}

	for (i = end; i >= idx2; i--) {
		if (i == end) {
			sum += ar[end];
			st2.push(ar[end]);
			continue;
		}

		if (ar[i] <= st2.top()) sum += st2.top();
		else {
			sum += ar[i];
			st2.push(ar[i]);
		}
	}
	printf("%d\n", sum);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2304
// KOI 05 초등부 2번
// 스택