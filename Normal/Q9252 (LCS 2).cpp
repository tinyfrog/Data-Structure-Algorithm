#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char a[1001], b[1001];
int dp[1001][1001];
char result[1001];

inline int max(int x, int y)
{
	return (x >= y) ? x : y;
}


int main(void)
{
	int i, j, len1 = 0, len2 = 0;
	scanf("%s %s", &a, &b);
	
	for (i = 0; a[i]; i++) ++len1;
	for (i = 0; b[i]; i++) ++len2;
	for (i = 1; i <= len1; i++) {
		for (j = 1; j <= len2; j++) {
			if (a[i - 1] == b[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
			else dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
		}
	}
	printf("%d\n", dp[len1][len2]);

	int c = dp[len1][len2] - 1;
	i = len1, j = len2; 
	while (i > 0 && j > 0) { 
		if (dp[i][j - 1] == dp[i - 1][j] && dp[i - 1][j] == dp[i - 1][j - 1] && dp[i - 1][j - 1] == dp[i][j] - 1) { 
			result[c--] = a[i - 1]; 
			i--; 
			j--; 
		} else { 
			if (dp[i - 1][j] == dp[i][j]) i--; 
			else if (dp[i][j - 1] == dp[i][j]) j--; 
		} 
	} 
	for (i = 0; i < dp[len1][len2]; i++) printf("%c", result[i]);
	printf("\n");
	return 0;
}

// 문제: https://www.acmicpc.net/problem/9252
