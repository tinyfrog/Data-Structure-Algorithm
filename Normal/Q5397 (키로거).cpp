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

Node *myalloc(void) // 리턴형 주목
{
	return &ar[arr_idx++];
}

Node *head; // 더블 링크드 리스트의 시작
Node *tail; // 더블 링크드 리스트의 끝

char ans[1000001];

void print_node()
{
	int i = 0;
	for (Node* iter = head->next; iter != tail; iter = iter->next, i++) ans[i] = iter->data;
	return;
}

void insert(Node * t, char w) // 제공 노드 포인터 다음에 문자 삽입
{
	Node *p = myalloc();
	p->data = w;

	p->next = t->next;
	p->prev = t;
	t->next->prev = p;
	t->next = p;
	return;
}

void del(Node * t) // 삭제 노드 포인터 문자를 제거
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
		arr_idx = 0, len = 0; // 초기화
		head = myalloc(); // head 노드 생성
		tail = myalloc(); // tail 노드 생성
		tail->prev = head;
		head->next = tail;
		Node *t = head; // 시간 단축을 위해 커서 포인터를 설정

		char set[1000001];

		scanf(" %s", set);
		for (i = 0; set[i]; i++) {
			if (set[i] == '<') {
				if (t == head) continue; // 첫 글자 앞이면 통과
				t = t->prev;
			}
			else if (set[i] == '>') {
				if (t->next == tail) continue; // 끝 글자 커서면 통과
				t = t->next;
			}
			else if (set[i] == '-') {
				if (t == head) continue; // 첫 글자 앞이면 통과
				t = t->prev; // t는 없어지는 노드이기 때문
				del(t->next);
				len--;
			}
			else {
				insert(t, set[i]);
				t = t->next; len++;
			}
		}

		print_node();
		ans[len] = 0; // 끝에 Null 삽입
		printf("%s\n", ans);
	}
	return 0;
}

// 출처 : https://www.acmicpc.net/problem/5397
// BAPC 10 I번 5397 키로거
// Linked List
