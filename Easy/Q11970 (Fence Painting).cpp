#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

int main(void)
{
	int a, b, c, d;
	scanf("%d %d %d %d", &a, &b, &c, &d);
	if(d >= a && b >= c|| b >= c && d >= a) printf("%d\n", max(b, d) - min(a, c));
	else printf("%d\n", (b + d) - (a + c));
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11970
// USACO 15/12 Bronze 1번
// 수학