#include <cstdio>

using namespace std;

int a[1001];

int main(void)
{
	int i, j, k, T, n, ans;
	scanf("%d", &T);

	for (i = 0; i < T; i++) {
		ans = 0;
		scanf("%d", &n);
		for (j = 0; j < n; j++) scanf("%d", &a[j]);
		for (j = 1; j < n; j++) {
			for (k = j - 1; k >= 0; k--) if (a[j] >= a[k]) ans++;
		}
		printf("%d\n", ans);
	}
}