#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int rec[7][4];
bool ans[4];
bool can;
int p1[] = { 0,0,0,0,0,1,1,1,1,2,2,2,3,3,4 };
int p2[] = { 1,2,3,4,5,2,3,4,5,3,4,5,4,5,5 };

void solve(int game) {
	if (can) return; // ����

	// ������ ���ӱ��� �Դٸ�, ����
	if (game == 15) {
		can = true;
		return;
	}

	int t1 = p1[game];    // team 1
	int t2 = p2[game];    // team 2

	if (rec[t1][0] > 0 && rec[t2][2] >0) { // team 1�� �¸��� �����ϴٸ�
		rec[t1][0]--;
		rec[t2][2]--;
		solve(game + 1);
		rec[t2][2]++;
		rec[t1][0]++;
	}
	if (rec[t1][2] > 0 && rec[t2][0] >0) { // team 2�� �¸��� �����ϴٸ�
		rec[t1][2]--;
		rec[t2][0]--;
		solve(game + 1);
		rec[t2][0]++;
		rec[t1][2]++;
	}
	// team 1,2 �� ���ºΰ� �����ϴٸ�
	if (rec[t1][1] > 0 && rec[t2][1] >0) {
		rec[t1][1]--;
		rec[t2][1]--;
		solve(game + 1);
		rec[t2][1]++;
		rec[t1][1]++;
	}
}

int main(void)
{
	int i, j, k;
	for (k = 0; k < 4; k++) {
		can = false;
		int go = 1, tot = 0, win = 0, lose = 0, draw = 0;
		for (i = 0; i < 6; i++) {
			for (j = 0; j < 3; j++) {
				scanf("%d", &rec[i][j]);
				tot += rec[i][j];
				if (j == 0) { // �¸�
					win += rec[i][j];
					if (rec[i][j] == 6) can = 0;
				}
				else if (j == 1) { // ���º�
					draw += rec[i][j];
					if (rec[i][j] == 6) can = 0;
				}
				else { // �й�
					lose += rec[i][j];
					if (rec[i][j] == 6) can = 0;
				}
			}
		}
		if (win != lose) go = 0; // �Ұ����Ѱ� ���� ������
		if (tot != 30) go = 0;
		if (draw % 2) go = 0;
		
		if (go) solve(0);
		ans[k] = can;
	}

	for (i = 0; i < 4; i++) printf("%d ", (ans[i]) ? 1 : 0);
	printf("\n");
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/6987
// 08 KOI �ߵ�� 1�� 
// BackTracking