#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int i, len = 0;
	long long ans = 0, t = 1;
	char word[11];
	scanf("%s", &word);

	for (i = 0; word[i]; i++) ++len;
	for (i = len - 1; i >= 0; i--) {
		ans += (word[i] - 'A' + 1) * t;
		t *= 26;
	}
	printf("%lld\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/16495
// 구현