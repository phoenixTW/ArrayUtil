typedef struct arrUtil {
	void *base;
	int typeSize;
	int length;
} ArrayUtil;

int areEqual(ArrayUtil, ArrayUtil);
ArrayUtil create(int, int);
ArrayUtil resize(ArrayUtil, int);
int findIndex(ArrayUtil, void*);