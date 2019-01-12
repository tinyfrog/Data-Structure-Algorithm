#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int ar[10];

int main(void)
{
	int N;
	scanf("%d", &N);

	while (N != 0) {
		ar[N % 10]++;
		N /= 10;
	}

	if (ar[3] != 0 || ar[4] != 0 || ar[5] != 0 || ar[6] != 0 || ar[7] != 0 || ar[9] != 0) printf("0\n");
	else if (ar[0] == 0 || ar[1] == 0 || ar[2] == 0 || ar[8] == 0) printf("1\n");
	else if (ar[0] == ar[1] && ar[1] == ar[2] && ar[2] == ar[8]) printf("8\n");
	else printf("2\n");
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/16674
// 16674 2018년을 되돌아보며
// 구현