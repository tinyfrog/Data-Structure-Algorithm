#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int prime[1001];
int idx = 0;

void check()
{
	prime[idx++] = 2;
	int i, t;
	bool flag;

	for (i = 3; i <= 997; i += 2)
	{
		t = 3;
		flag = true;
		while (t * t <= i) {
			if (i % t == 0) {
				flag = false;
				break;
			}
			t += 2;
		}
		if (flag) prime[idx++] = i;
	}
	return;
}

int main(void)
{
	int i, j, k, z, T, K, sum;
	bool flag;
	scanf("%d", &T);

	check();

	for (z = 0; z < T; z++)
	{
		flag = false;
		int answer[3];
		scanf("%d", &K);

		for (i = 0; i < idx; i++) {
			sum = prime[i];
			if (sum > K) break;
			for (j = i; j < idx; j++) {
				sum += prime[j];
				if (sum > K) {
					sum -= prime[j];
					break;
				}
				for (k = j; k < idx; k++) {
					sum += prime[k];
					if (sum == K) {
						flag = true;
						answer[0] = prime[i];
						answer[1] = prime[j];
						answer[2] = prime[k];
						break;
					}
					sum -= prime[k];
				}
				if (flag) break;
				sum -= prime[j];
			}
			if (flag) break;
			sum -= prime[i];
		}
		if (flag) {
			for (i = 0; i < 3; i++) printf("%d ", answer[i]);
			printf("\n");
		}
		else printf("0\n");
	}
	return 0;
}