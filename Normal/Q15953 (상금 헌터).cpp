#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int T;
	int a, b, sum;
	scanf("%d", &T);

	while (T--)
	{
		scanf("%d %d", &a, &b);
		sum = 0;
		if (a >= 1 && a < 2) sum += 5000000;
		else if (a >= 2 && a < 4) sum += 3000000;
		else if (a >= 4 && a < 7) sum += 2000000;
		else if (a >= 7 && a < 11) sum += 500000;
		else if (a >= 11 && a < 16) sum += 300000;
		else if (a >= 16 && a < 22) sum += 100000;

		if (b >= 1 && b < 2) sum += 5120000;
		else if (b >= 2 && b < 4) sum += 2560000;
		else if (b >= 4 && b < 8) sum += 1280000;
		else if (b >= 8 && b < 16) sum += 640000;
		else if (b >= 16 && b < 32) sum += 320000;
		
		printf("%d\n", sum);
	} 
	
	return 0;
}

// ¹®Á¦ : https://www.acmicpc.net/problem/15953