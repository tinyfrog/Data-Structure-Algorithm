#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int main(void)
{
	int i, N, len, com;
	scanf("%d", &N);
	while (N--)
	{
		com = 0;
		char st[101];
		for (i = 0; i < 101; i++) st[i] = 0; // 초기화
		scanf(" %[^\n]", st); // 숫자 다음 띄어주기

		for (i = 0; st[i]; i++) {
			if (st[i] == ' ') com++;
			if (com == 2) {
				len = i; 
				break;
			}
		}
		for (i = len + 1; st[i]; i++) printf("%c", st[i]);
		printf(" ");
		for (i = 0; i < len; i++) printf("%c", st[i]);
		printf("\n");
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/5363
// 5363 요다
// 문자열