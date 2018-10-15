#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, j, k, a, b, c, n;
	bool flag = false;
	scanf("%d %d %d %d", &a, &b, &c, &n);

	for (i = 0; i * a <= n; i++) {
		for (j = 0; j * b <= n; j++) {
			for (k = 0; k * c <= n; k++) {
				if (i * a + j * b + k * c == n) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}
		if (flag) break;
	}

	if (flag) printf("1\n");
	else printf("0\n");
	return 0;
}

// ¹®Á¦ : https://www.acmicpc.net/problem/14697
// ºê·çÆ® Æ÷½º
