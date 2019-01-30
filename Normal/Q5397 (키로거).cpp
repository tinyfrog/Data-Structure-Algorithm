#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>

using namespace std;

int arr_idx;

struct Node
{
	char data;
	Node* prev;
	Node* next;
} ar[1000001];

Node *myalloc(void) // ������ �ָ�
{
	return &ar[arr_idx++];
}

Node *head; // ���� ��ũ�� ����Ʈ�� ����
Node *tail; // ���� ��ũ�� ����Ʈ�� ��

char ans[1000001];

void print_node()
{
	int i = 0;
	for (Node* iter = head->next; iter != tail; iter = iter->next, i++) ans[i] = iter->data;
	return;
}

void insert(Node * t, char w) // ���� ��� ������ ������ ���� ����
{
	Node *p = myalloc();
	p->data = w;

	p->next = t->next;
	p->prev = t;
	t->next->prev = p;
	t->next = p;
	return;
}

void del(Node * t) // ���� ��� ������ ���ڸ� ����
{
	t->next->prev = t->prev;
	t->prev->next = t->next;
	return;
}

int main(void)
{
	int i, len;

	int T;
	scanf("%d", &T);

	while (T--) {
		arr_idx = 0, len = 0; // �ʱ�ȭ
		head = myalloc(); // head ��� ����
		tail = myalloc(); // tail ��� ����
		tail->prev = head;
		head->next = tail;
		Node *t = head; // �ð� ������ ���� Ŀ�� �����͸� ����

		char set[1000001];

		scanf(" %s", set);
		for (i = 0; set[i]; i++) {
			if (set[i] == '<') {
				if (t == head) continue; // ù ���� ���̸� ���
				t = t->prev;
			}
			else if (set[i] == '>') {
				if (t->next == tail) continue; // �� ���� Ŀ���� ���
				t = t->next;
			}
			else if (set[i] == '-') {
				if (t == head) continue; // ù ���� ���̸� ���
				t = t->prev; // t�� �������� ����̱� ����
				del(t->next);
				len--;
			}
			else {
				insert(t, set[i]);
				t = t->next; len++;
			}
		}

		print_node();
		ans[len] = 0; // ���� Null ����
		printf("%s\n", ans);
	}
	return 0;
}

// ��ó : https://www.acmicpc.net/problem/5397
// BAPC 10 I�� 5397 Ű�ΰ�
// Linked List
