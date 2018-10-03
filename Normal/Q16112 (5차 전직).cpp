#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k;
int ar[300001];

int main(void)
{
	int i, idx = 0;
	long long sum = 0, tsum = 0;

	scanf("%d %d", &n, &k);
	for(i = 0; i < n; i++) scanf("%d", &ar[i]);

	sort(ar, ar+n);

	for (i = n - 1; i >= 0; i--) {
		if (i < k) sum += tsum;
		tsum += (long long) ar[i]; 
	}
	printf("%lld\n", sum);
	return 0;
}

// ¹®Á¦ : https://www.acmicpc.net/problem/16112