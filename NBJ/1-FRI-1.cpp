#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

char word[251][51];
char str[51];
char temp[51]; 
int ar[51]; // �ܾ� ���� ����

inline int max(int a, int b)
{
	return (a >= b) ? a : b;
}

int main(void)
{
	int i, j, k, point, l1, l2, l3, num = 0;
	bool flag, f;
	while (true)
	{
		point = 0;
		scanf(" %[^\n]s", str);
		
		if (str[0] == 'E' && str[1] == 'N' && str[2] == 'D') break;

		l1 = 0;
		for (i = 0; str[i]; i++) ++l1;

		for (i = 0; i <= l1; i++) { // ���� �м�
			if(str[i] == ' ' || i == l1) {
				l2 = 0;
				for (j = point; j < i; j++) temp[l2++] = str[j]; // �ܾ�����
				point = i + 1;

				flag = true;
				for (j = 0; j < num; j++) { // �ߺ� ã��
					f = true;
					l3 = max(ar[j], l2);
					for (k = 0; k < l3; k++) {
						if (temp[k] != word[j][k]) {
							f = false;
							break;
						}
					}
					if (f) { // �ߺ� ����
						flag = false;
						break;
					}
				}

				if (flag) {
					for (j = 0; j < l2; j++) word[num][j] = temp[j]; // �ܾ� ���
					ar[num++] = l2;
				}
				for (j = 0; j < l2; j++) temp[j] = 0; // ����
			}
		}

		for (i = 0; i < num; i++) {
			for (j = 0; word[i][j]; j++) printf("%c", word[i][j]);
			printf(" ");
		}
		printf("\n");
	}
	return 0;
}