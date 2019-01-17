#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

struct st {
	int n, l;
} ar[500001];

st stack[500001];
int ans[500001];

int main(void)
{
	int i, N, idx;
	scanf("%d", &N);
	idx = 0;

	for (i = 1; i <= N; i++) {
		scanf("%d", &ar[i].n);
		ar[i].l = i;
	}
	
	stack[idx++] = ar[N];
	for (i = N-1; i >= 1; i--) {
		if (ar[i].n < stack[idx - 1].n) stack[idx++] = ar[i];
		else {
			while (idx > 0 && ar[i].n > stack[idx - 1].n) {
				ans[stack[idx - 1].l] = i;
				idx--;
			}
			stack[idx++] = ar[i];
		}
	}

	while (idx > 0) {
		ans[stack[idx - 1].l] = 0;
		idx--;
	}

	for (i = 1; i <= N; i++) printf("%d ", ans[i]);
	printf("\n");
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2493
// KOI 지역본선 09 고등부 2번
// 스택