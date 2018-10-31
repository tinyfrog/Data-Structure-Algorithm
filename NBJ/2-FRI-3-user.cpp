#ifndef NULL
#define NULL 0
#endif 

const int mod = (1 << 8) - 1;
int N, cnt, save[10001][101];

struct data {
	int id, pos;
	data *next;
	data *myAlloc(int _id, int _pos, data *_next) {
		id = _id, pos = _pos, next = _next;
		return this;
	}
} arr[1000000], *index[1<<16];

void push(int p, int id, int pos) {
	index[p] = arr[cnt++].myAlloc(id, pos, index[p]);
}

int key(int a, int b) {
	return ((a & mod) << 8) + (b & mod);
}

void initUser(int dataN) {
	cnt = 0;
	N = dataN;
}

void registerData(int dataID, int dataLen, int dataArr[100]) {
	int i;
	for (i = 0; i < dataLen; i++) {
		save[dataID][i] = dataArr[i];
		if (i <= dataLen - 8) push(key(dataArr[i], dataArr[i + 1]), dataID, i);
	}
}

int chk(int * a, int * b) {
	int i;
	for (i = 0; i < 8; i++) if (a[i] != b[i]) return 0;
	return 1;
}

int findID(int args[8]) {
	for (data *p = index[key(args[0], args[1])]; p; p = p->next) {
		if (chk(save[p->id] + p->pos, args)) return p->id;
	}
	return 0;
}