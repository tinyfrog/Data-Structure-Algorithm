#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <deque>

struct score {
	int x, y;
};

using namespace std;

int main(void)
{
	int i, N, t, num;
	score rm;
	deque<score> dq;
	scanf("%d", &N);

	for (i = 1; i <= N; i++) {
		scanf("%d", &t);
		dq.push_back({ t, i });
	}

	num = 1;
	printf("%d ", dq.front().y);
	t = dq.front().x;
	dq.pop_front();
	while (num < N) {
		if (t > 0) {
			for (i = 1; i < t; i++) {
				rm = dq.front();
				dq.pop_front();
				dq.push_back(rm);
			}
			printf("%d ", dq.front().y);
			t = dq.front().x;
			dq.pop_front();
		}
		else if (t < 0) {
			for (i = 1; i < -t; i++) {
				rm = dq.back();
				dq.pop_back();
				dq.push_front(rm);
			}
			printf("%d ", dq.back().y);
			t = dq.back().x;
			dq.pop_back();
		}
		num++;
	}
	printf("\n");
	return 0;
}

// ÃâÃ³ : https://www.acmicpc.net/problem/2346
// 2346 Ç³¼± ÅÍ¶ß¸®±â
// µ¦