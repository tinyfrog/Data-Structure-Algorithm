#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	int i, T, N;
	scanf("%d", &T);

	while (T--) {
		scanf("%d", &N);
		printf("Pairs for %d:", N);

		if (N == 1 || N == 2) {
			printf("\n");
			continue;
		}

		if (N % 2) { // È¦¼ö
			for (i = 1; i < N / 2; i++) {
				printf(" %d %d,", i, N - i);
			}
			printf(" %d %d\n", N / 2, N - (N / 2));
		}
		else { // Â¦¼ö
			for (i = 1; i < (N / 2) - 1; i++) {
				printf(" %d %d,", i, N - i);
			}
			printf(" %d %d\n", (N / 2) - 1, N - (N / 2 - 1));
		}
	}
	return 0;
}

// ÃâÃ³ : https://www.acmicpc.net/problem/5217
// 5217 ½ÖÀÇ ÇÕ
// ¼öÇÐ