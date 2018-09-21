#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void)
{
	int ar[8], a, b, len, i = 0;
	scanf("%d %d", &a, &b);

	while (true)
	{
		if (a == 0 && b == 0) {
			--i;
			break;
		}
 		ar[i] = a % 10 + b % 10;
		a /= 10, b /= 10, ++i;
	}

	for (; i >= 0; i--)printf("%d", ar[i]);
	printf("\n");
	return 0;
}