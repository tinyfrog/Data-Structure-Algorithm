#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

char ar[1001][51];
char ans[51];
int check[4];

int main(void)
{
	int i, j, N, M, hd = 0;
	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++) scanf("%s", &ar[i]);
	
	for (j = 0; j < M; j++) {
		for (i = 0; i < 4; i++) check[i] = 0;
		for (i = 0; i < N; i++) {
			if (ar[i][j] == 'A') check[0]++;
			else if (ar[i][j] == 'C') check[1]++;
			else if (ar[i][j] == 'G') check[2]++;
			else check[3]++;
		}
		int order = 3, num = check[3];
		for (i = 2; i >= 0; i--) {
			if (check[i] >= num) {
				order = i;
				num = check[i];
			}
		}
		if (order == 3) ans[j] = 'T';
		else if (order == 2) ans[j] = 'G';
		else if (order == 1) ans[j] = 'C';
		else ans[j] = 'A';

		for (i = 0; i < N; i++) {
			if (ans[j] != ar[i][j]) hd++;
		}
	} 

	printf("%s\n%d\n", ans, hd);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/1969
// 1969 DNA
// 그리디