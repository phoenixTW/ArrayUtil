typedef struct arrUtil {
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

typedef int (MatchFunc)(void*, void*);

int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil create(int, int);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil, void*);
void dispose(ArrayUtil);
void *findFirst(ArrayUtil, MatchFunc*, void*);