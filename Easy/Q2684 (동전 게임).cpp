#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int ar[8];

int main(void)
{
	int i, T;
	scanf("%d", &T);
	while (T--)
	{
		for (i = 0; i < 8; i++) ar[i] = 0;
		char set[41];
		scanf(" %s", set);

		for (i = 0; i <= 37; i++) {
			if (set[i] == 'T') {
				if(set[i+1] == 'T') {
					if (set[i + 2] == 'T') ar[0]++;
					else ar[1]++;
				}
				else {
					if (set[i + 2] == 'T') ar[2]++;
					else ar[3]++;
				}
			}
			else {
				if (set[i + 1] == 'T') {
					if (set[i + 2] == 'T') ar[4]++;
					else ar[5]++;
				}
				else {
					if (set[i + 2] == 'T') ar[6]++;
					else ar[7]++;
				}
			}
		}
		for (i = 0; i < 8; i++) printf("%d ", ar[i]);
		printf("\n");
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/2684
// Q2684 동전 게임
// 쉬운 문제