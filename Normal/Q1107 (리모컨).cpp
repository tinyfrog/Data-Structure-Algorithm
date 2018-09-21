#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool check[10];
int ans;

int ab(int a) {
	return (a < 0) ? -a : a;
}

int main(void)
{
	int i, t, N, M;
	int num, temp, digit;
	bool flag;
	scanf("%d %d", &N, &M);
	
	for (i = 0; i < M; i++) {
		scanf("%d", &t);
		check[t] = true;
	}

	ans = ab(N - 100);
	if (N < 100) {
		num = 99;
		while (num > -1)
		{
			flag = true;
			temp = num;
			digit = 0;

			if (num % 10 == 0) { // 끝자리가 0이면 생기는 반례
				if (check[0]) {
					--num;
					continue;
				}
				++digit;
				temp /= 10;
			}
			while (temp != 0) {
				if (check[temp % 10]) {
					flag = false;
					break;
				}
				temp /= 10;
				++digit;
			}
			
			if (flag) {
				if (ab(N - num) + digit < ans) ans = ab(N - num) + digit;
			}
			--num;
		}
	}
	else if (N == 100) {}
	else {
		num = 101;
		while (num < 1000001)
		{
			flag = true;
			temp = num;
			digit = 0;

			if (num % 10 == 0) { // 끝자리가 0이면 생기는 반례
				if (check[0]) {
					++num;
					continue;
				}
				++digit;
				temp /= 10;
			}
			while (temp != 0) {
				if (check[temp % 10]) {
					flag = false;
					break;
				}
				temp /= 10;
				++digit;
			}

			if (flag) {
				if (ab(N - num) + digit < ans) ans = ab(N - num) + digit;
			}
			++num;
		}
	}
	printf("%d\n", ans);
}