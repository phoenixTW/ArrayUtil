#include "arrayUtil.h"
#include <stdio.h>

int areEqual (ArrayUtil array1, ArrayUtil array2) {
	int count;
	char *a1 = ((char*)(array1.base));
	char *a2 = ((char*)(array2.base));
	if(array1.length != array2.length || array1.typeSize != array2.typeSize)
		return 0;

	for (count = 0; count < (array1.length * array1.typeSize); ++count) {
		if(a1[count] != a2[count])
			return 0;	
	}

	return 1;
}

ArrayUtil create(int typeSize, int length) {
	ArrayUtil array;
	int *newArray;
	newArray = calloc(typeSize, length);
	array.length = length;
	array.typeSize = typeSize;
	array.base = newArray;

	return array;
}

ArrayUtil resize(ArrayUtil array, int length) {
	int newSize = array.typeSize * length;
	array.length = newSize;
	array.base = realloc(array.base, newSize);
	return array;
}

int findIndex(ArrayUtil array, void *element) {
	int count;

	float *convArray = array.base,
		  *ele = element;

	for(count = 0; count < array.length; count++) {
		if(convArray[count] == *ele)
			return count;
	}

	return -1;
}

void dispose (ArrayUtil array) {
	free(array.base);
	array.base = NULL;
}