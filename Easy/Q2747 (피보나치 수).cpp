#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

using namespace std;

int ar[46];

int fibb(int N)
{
	if (N <= 0) return 0;
	if (ar[N] != 0) return ar[N];

	ar[N] = fibb(N - 1) + fibb(N - 2);
	return ar[N];
}

int main(void)
{
	int N;
	scanf("%d", &N);
	ar[1] = 1;
	printf("%d\n", fibb(N));
	return 0;
}