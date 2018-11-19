#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int ar[101];

int main(void)
{
	int i, j, N, num, a, b, k, count;
	scanf("%d", &N);
	for (i = 0; i < N; i++) scanf("%d", &ar[i]);
	scanf("%d", &num);
	for (i = 0; i < num; i++) {
		scanf("%d %d", &a, &b);
		if (a == 1) {
			for (j = b-1; j < N; j += b) ar[j] = (ar[j] == 0) ? 1 : 0;
		}
		else if (a == 2) {
			k = 0;
			for (k = 1;; k++) {
				if (b - 1 - k < 0 || b - 1 + k >= N || ar[b - 1 - k] != ar[b - 1 + k]) {
					k--;
					break;
				}
			}
			ar[b - 1] = (ar[b - 1] == 0) ? 1 : 0;
			for (j = 1; j <= k; j++) {
				ar[b-1+j] = (ar[b-1+j] == 0) ? 1 : 0;
				ar[b-1-j] = (ar[b-1-j] == 0) ? 1 : 0;
			}
		}
	}

	count = 1;
	for (i = 0; i < N; i++) {
		printf("%d ", ar[i]);
		if(count % 20 == 0) printf("\n");
		count++;
	}
	return 0;
}

// ÃâÃ³ : https://www.acmicpc.net/problem/1244