#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int main(void)
{
	int L, P, V, num = 1;

	while (true)
	{
		scanf("%d %d %d", &L, &P, &V);
		if (L == 0) break;
		printf("Case %d: %d\n", num, (V / P) * L + min(V % P, L));
		num++;
	}

	return 0;
}

// 출처 : https://www.acmicpc.net/problem/4796
// 4796 캠핑
// 그리디