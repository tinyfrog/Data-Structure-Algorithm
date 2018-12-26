#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

struct st {
	int d, w;
} ar[1001];

bool cmp(st a, st b)
{
	if (a.w < b.w) return false;
	else return true;
}

bool plan[1001];

int main(void)
{
	int i, j, N, sum = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) scanf("%d %d", &ar[i].d, &ar[i].w);
	sort(&ar[0], &ar[N], cmp);

	plan[ar[0].d] = true;
	sum += ar[0].w;

	for (i = 1; i < N; i++) {
		if (plan[ar[i].d]) { // �̹� ��ȹ ����
			for (j = ar[i].d - 1; j >= 1; j--) {
				if (!plan[j]) {
					plan[j] = true;
					sum += ar[i].w;
					break;
				}
			}
		}
		else {
			sum += ar[i].w;
			plan[ar[i].d] = true;
		}
	}

	printf("%d\n", sum);
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/13904
// 13904 ����
// �׸���