#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	int i, j, T;
	scanf("%d", &T);

	while (T--)
	{
		char t, set[1001];
		int st = 0, len = 0;
		scanf(" %[^\n]s", set);

		for (i = 0; set[i]; i++) {
			if (set[i] == ' ') {
				for (j = 0; j < len / 2; j++) {
					t = set[st + len - j - 1];
					set[st + len - j - 1] = set[st + j];
					set[st + j] = t;
				}
				st = i+1, len = 0;
				continue;
			}
			len++;
		}

		for (j = 0; j < len / 2; j++) {
			t = set[st + len - j - 1];
			set[st + len - j - 1] = set[st + j];
			set[st + j] = t;
		}
		printf("%s\n", set);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/9093
// 01 대전 지역 PA번
// 문자열, 구현