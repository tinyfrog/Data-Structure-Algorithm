#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

struct ball {
	int n, c, s;
};

bool cmp(ball a, ball b) {
	return a.s < b.s;
}

ball ar[200010];
int N, sum, color[200001], ans[200001];

int main(void)
{
	int i, j, a, b;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d %d", &a, &b);
		ar[i] = { i, a, b };
	}

	sort(&ar[0], &ar[N], cmp); 

	for (i = 0, j = 0; i < N; i++) { // ���� ���Ǵ�� 
		for (; ar[j].s < ar[i].s; j++) {
			sum += ar[j].s;
			color[ar[j].c] += ar[j].s;
		}
		ans[ar[i].n] = sum - color[ar[i].c];
	}
	
	for (i = 0; i < N; i++) printf("%d\n", ans[i]);
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/10800
// 10800 �÷��� KOI �������� 2015 ���� 2��
// ����, ������