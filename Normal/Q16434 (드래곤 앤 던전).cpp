#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

long long N, A;

struct room {
	long long t, a, h;
} ar[123457];

bool game (long long sth) // 시작 체력, 시작 공격
{
	int i;
	long long a = A, h = sth;
	for (i = 0; i < N; i++) {
		if (ar[i].t == 1) { // 몬스터방
			if (a < ar[i].h) {
				if (ar[i].h % a) h -= (ar[i].h / a) * ar[i].a;
				else h -= ((ar[i].h / a) - 1) * ar[i].a;
			}

			if (h <= 0) return false;
		}
		else if (ar[i].t == 2) { // 포션 방
			a += ar[i].a;
			if (h + ar[i].h > sth) h = sth;
			else h += ar[i].h;
		}
	}
	return true;
}

int main(void)
{
	int i;
	long long ans = 0;
	scanf("%lld %lld", &N, &A);

	for (i = 0; i < N; i++) scanf("%lld %lld %lld", &ar[i].t, &ar[i].a, &ar[i].h);

	long long l = 1, r = 999999000001 * 123456, mid;

	while (l <= r) {
		mid = (l + r) / 2;
		if (game(mid)) {
			ans = mid;
			r = mid - 1;
		}
		else l = mid + 1;
	}

	printf("%lld\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/16434
// 16434 드래곤 앤 던전 
// 이진 탐색 (범위가 핵심)