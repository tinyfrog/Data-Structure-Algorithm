#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

char a[101], b[101], c[101];
int dp[101][101][101];
int l1, l2, l3;

int LCS(int idx1, int idx2, int idx3)
{
	if (idx1 == l1 || idx2 == l2 || idx3 == l3) return 0;

	int& ret = dp[idx1][idx2][idx3];
	if (ret != -1) return ret; // 이미 저장되어 있음

	ret = max(LCS(idx1 + 1, idx2, idx3), max(LCS(idx1, idx2 + 1, idx3), LCS(idx1, idx2, idx3 + 1)));
	ret = max(max(ret, LCS(idx1 + 1, idx2 + 1, idx3)), max(LCS(idx1 + 1, idx2, idx3 + 1), LCS(idx1, idx2 + 1, idx3 + 1)));
	ret = max(ret, (a[idx1] == b[idx2] && a[idx1] == c[idx3] && b[idx2] == c[idx3]) + LCS(idx1 + 1, idx2 + 1, idx3 + 1));
	return ret;
}
 
int main(void)
{
	int i;
	scanf("%s %s %s", &a, &b, &c);

	for (i = 0; a[i]; i++) l1++;
	for (i = 0; b[i]; i++) l2++;
	for (i = 0; c[i]; i++) l3++;

	memset(dp, -1, sizeof(dp));

	printf("%d\n", LCS(0, 0, 0));
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1958
// 1958 LCS 3
// DP