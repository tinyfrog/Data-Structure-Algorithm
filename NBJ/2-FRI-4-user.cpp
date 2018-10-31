#ifndef NULL
#define NULL 0
#endif 

#define bit7(x) ((x>>8) & ((1<<7) - 1)) // 15bit 중 앞 7bit (; 없음)
int N, len[10005], Data[10005][200], *arr, cnt;
const int hn = (1 << 21); // hash size

struct Hash {
	int id, pos;
	Hash *next;
	Hash *myAlloc(int _id, int _pos, Hash *_next) {
		id = _id, pos = _pos, next = _next;
		return this;
	}
} table[hn], *hash[hn];

void push(int p, int id, int pos) {
	hash[p] = table[cnt++].myAlloc(id, pos, hash[p]);
}

void initUser(int soundNum) {
	int i;
	N = soundNum;
	cnt = 0;
	for (i = 0; i < hn; i++) hash[i] = 0;
}

int key(int a, int b, int c) {
	return (bit7(a) << 14) + (bit7(b) << 7) + bit7(c);
}

void registerSound(int soundID, int soundLen, int soundArr[200]) {
	len[soundID] = soundLen;
	int i, tmp;
	for (i = 0; i < soundLen; i++) Data[soundID][i] = soundArr[i];
	for (i = 0; i <= soundLen - 8; i++) {
		tmp = key(soundArr[i], soundArr[i + 1], soundArr[i + 2]);
		push(tmp, soundID, i);
	}
}

int chk(int id, int start)
{
	int i;
	for (i = 1; i < 8; i++) {
		if (Data[id][start + i] - 128 > arr[i] || Data[id][start + i] + 127 < arr[i]) return 0;
	}
	return 1;
}

int search(Hash *p) {
	if (!p) return 0;
	if (chk(p->id, p->pos)) return p->id;
	return search(p->next);
}

int p[3][8] = { {-127, -127, -127, -127, 128, 128, 128, 128},
{-127, -127, 128, 128, -127, -127, 128, 128},
{-127, 128, -127, 128, -127, 128, -127, 128} };

int plagiarismCheck(int newData[8])
{
	arr = newData;
	int tmp, i, id = 0;
	for (i = 0; i < 8 && id == 0; i++) {
		tmp = key(arr[0] + p[0][i], arr[1] + p[1][i], arr[2] + p[2][i]);
		id = search(hash[tmp]);
	}
	return id;
}
