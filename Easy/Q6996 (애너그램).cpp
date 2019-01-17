#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int an[26], bn[26];

int main(void)
{
	int i, N;
	scanf("%d", &N);

	while (N--)
	{
		char a[101], b[101];
		scanf(" %s %s", a, b);
		int len1 = 0, len2 = 0;

		for (i = 0; a[i]; i++) len1++;
		for (i = 0; b[i]; i++) len2++;

		if (len1 != len2) {
			printf("%s & %s are NOT anagrams.\n", a, b);
			continue;
		}

		for (i = 0; i < 26; i++) {
			an[i] = 0, bn[i] = 0;
		}

		bool flag = true;
		for (i = 0; i < len1; i++) {
			an[a[i] - 'a']++, bn[b[i] - 'a']++;
		}

		for (i = 0; i < 26; i++) {
			if (an[i] != bn[i]) {
				flag = false;
				break;
			}
		}
		if (flag) printf("%s & %s are anagrams.\n", a, b);
		else printf("%s & %s are NOT anagrams.\n", a, b);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/6996
// 6996 애너그램
// 구현