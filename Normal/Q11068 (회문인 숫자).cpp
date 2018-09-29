#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool check(int num, int n)
{
	int i, l = 0, ar[21];
	bool flag = true;
	while (num > 0) {
		ar[l++] = num % n;
		num /= n;
	}
	--l;
	for (i = 0; i <= l / 2; i++) {
		if (ar[i] != ar[l - i]) {
			flag = false;
			break;
		}
	}

	if (flag) return true;
	else return false;
}

int main(void)
{
	int z, i, T, N;
	bool flag;
	scanf("%d", &T);

	for (z = 0; z < T; z++) {
		scanf("%d", &N);
		flag = false;
		for (i = 2; i <= 64; i++) {
			if (check(N, i)) {
				flag = true;
				break;
			}
		}
		if (flag) printf("1\n");
		else printf("0\n");
	}
	return 0;
}

// ¹®Á¦ : https://www.acmicpc.net/problem/11068