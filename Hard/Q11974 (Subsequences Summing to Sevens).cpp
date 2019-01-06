#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int mmin[7], mmax[7];
int N;

int main(void)
{
	int i, li, psum = 0, ans = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++) {
		scanf("%d", &li);
		psum = (psum + li) % 7;
		if (psum > 0 && !mmin[psum]) mmin[psum] = i + 1; // 나머지 저장
		mmax[psum] = i + 1;
	}
	
	for (i = 0; i < 7; i++) if (mmax[i] - mmin[i] > ans) ans = mmax[i] - mmin[i];
	printf("%d\n", ans);
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/11974
// USACO 16/01 Silver 2번
// 수학