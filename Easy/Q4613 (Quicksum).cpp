#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	while (true)
	{
		int i, j = 1;
		long sum = 0;
		char set[256];

		scanf(" %[^\n]s", set);
		if (set[0] == '#') break;

		for (i = 0; set[i]; i++, j++) {
			if (set[i] == ' ') continue;
			sum += (set[i] - 'A' + 1) * j;
		}
		printf("%ld\n", sum);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/4613
// 4613 Quicksum
// 구현